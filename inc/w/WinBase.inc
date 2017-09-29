' ########################################################################################
' Microsoft Windows
' File: WinBase.inc
' Contents: This module defines the 32-Bit Windows Base APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Note: windows.inc must be included before this file, but can't be done here.
' You must do it in your application.

#INCLUDE THIS ONCE
%WINBASE_INC = 1

'/*
' * Compatibility macros
' */

'#define DefineHandleTable(w)            ((w),TRUE)
'#define LimitEmsPages(dw)
'#define SetSwapAreaSize(w)              (w)
'#define LockSegment(w)                  GlobalFix((HANDLE)(w))
'#define UnlockSegment(w)                GlobalUnfix((HANDLE)(w))
'#define GetCurrentTime()                GetTickCount()

'#define Yield()

'#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
'#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
'#define INVALID_SET_FILE_POINTER ((DWORD)-1)
'#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)

%INVALID_HANDLE_VALUE     = &HFFFFFFFF???
%INVALID_FILE_SIZE        = &HFFFFFFFF???
%INVALID_SET_FILE_POINTER = &HFFFFFFFF???
%INVALID_FILE_ATTRIBUTES  = &HFFFFFFFF???

%FILE_BEGIN   = 0
%FILE_CURRENT = 1
%FILE_END     = 2

'#define TIME_ZONE_ID_INVALID ((DWORD)0xFFFFFFFF)
%TIME_ZONE_ID_INVALID  = &HFFFFFFFF???

'#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
'#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )
%WAIT_FAILED      = &HFFFFFFFF???
%WAIT_OBJECT_0    = %STATUS_WAIT_0 + 0

'#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
'#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

%WAIT_ABANDONED   = %STATUS_ABANDONED_WAIT_0 + 0
%WAIT_ABANDONED_0 = %STATUS_ABANDONED_WAIT_0 + 0

%WAIT_IO_COMPLETION                 = %STATUS_USER_APC
%STILL_ACTIVE                       = %STATUS_PENDING
%STATUS_POSSIBLE_DEADLOCK           = &HC0000194&
%EXCEPTION_ACCESS_VIOLATION         = %STATUS_ACCESS_VIOLATION
%EXCEPTION_DATATYPE_MISALIGNMENT    = %STATUS_DATATYPE_MISALIGNMENT
%EXCEPTION_BREAKPOINT               = %STATUS_BREAKPOINT
%EXCEPTION_SINGLE_STEP              = %STATUS_SINGLE_STEP
%EXCEPTION_ARRAY_BOUNDS_EXCEEDED    = %STATUS_ARRAY_BOUNDS_EXCEEDED
%EXCEPTION_FLT_DENORMAL_OPERAND     = %STATUS_FLOAT_DENORMAL_OPERAND
%EXCEPTION_FLT_DIVIDE_BY_ZERO       = %STATUS_FLOAT_DIVIDE_BY_ZERO
%EXCEPTION_FLT_INEXACT_RESULT       = %STATUS_FLOAT_INEXACT_RESULT
%EXCEPTION_FLT_INVALID_OPERATION    = %STATUS_FLOAT_INVALID_OPERATION
%EXCEPTION_FLT_OVERFLOW             = %STATUS_FLOAT_OVERFLOW
%EXCEPTION_FLT_STACK_CHECK          = %STATUS_FLOAT_STACK_CHECK
%EXCEPTION_FLT_UNDERFLOW            = %STATUS_FLOAT_UNDERFLOW
%EXCEPTION_INT_DIVIDE_BY_ZERO       = %STATUS_INTEGER_DIVIDE_BY_ZERO
%EXCEPTION_INT_OVERFLOW             = %STATUS_INTEGER_OVERFLOW
%EXCEPTION_PRIV_INSTRUCTION         = %STATUS_PRIVILEGED_INSTRUCTION
%EXCEPTION_IN_PAGE_ERROR            = %STATUS_IN_PAGE_ERROR
%EXCEPTION_ILLEGAL_INSTRUCTION      = %STATUS_ILLEGAL_INSTRUCTION
%EXCEPTION_NONCONTINUABLE_EXCEPTION = %STATUS_NONCONTINUABLE_EXCEPTION
%EXCEPTION_STACK_OVERFLOW           = %STATUS_STACK_OVERFLOW
%EXCEPTION_INVALID_DISPOSITION      = %STATUS_INVALID_DISPOSITION
%EXCEPTION_GUARD_PAGE               = %STATUS_GUARD_PAGE_VIOLATION
%EXCEPTION_INVALID_HANDLE           = %STATUS_INVALID_HANDLE
%EXCEPTION_POSSIBLE_DEADLOCK        = %STATUS_POSSIBLE_DEADLOCK
%CONTROL_C_EXIT                     = %STATUS_CONTROL_C_EXIT

'//
'// File creation flags must start at the high end since they
'// are combined with the attributes
'//

%FILE_FLAG_WRITE_THROUGH       = &H80000000???
%FILE_FLAG_OVERLAPPED          = &H40000000???
%FILE_FLAG_NO_BUFFERING        = &H20000000???
%FILE_FLAG_RANDOM_ACCESS       = &H10000000???
%FILE_FLAG_SEQUENTIAL_SCAN     = &H08000000???
%FILE_FLAG_DELETE_ON_CLOSE     = &H04000000???
%FILE_FLAG_BACKUP_SEMANTICS    = &H02000000???
%FILE_FLAG_POSIX_SEMANTICS     = &H01000000???
%FILE_FLAG_OPEN_REPARSE_POINT  = &H00200000???
%FILE_FLAG_OPEN_NO_RECALL      = &H00100000???
%FILE_FLAG_FIRST_PIPE_INSTANCE = &H00080000???

%CREATE_NEW        = 1
%CREATE_ALWAYS     = 2
%OPEN_EXISTING     = 3
%OPEN_ALWAYS       = 4
%TRUNCATE_EXISTING = 5

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Define possible return codes from the CopyFileEx callback routine
'//

%PROGRESS_CONTINUE = 0
%PROGRESS_CANCEL   = 1
%PROGRESS_STOP     = 2
%PROGRESS_QUIET    = 3

'//
'// Define CopyFileEx callback routine state change values
'//

%CALLBACK_CHUNK_FINISHED  = &H00000000???
%CALLBACK_STREAM_SWITCHED = &H00000001???

'//
'// Define CopyFileEx option flags
'//

%COPY_FILE_FAIL_IF_EXISTS              = &H00000001???
%COPY_FILE_RESTARTABLE                 = &H00000002???
%COPY_FILE_OPEN_SOURCE_FOR_WRITE       = &H00000004???
%COPY_FILE_ALLOW_DECRYPTED_DESTINATION = &H00000008???

'//
'//  Gap for private copyfile flags
'//

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%COPY_FILE_COPY_SYMLINK                = &H00000800???
%COPY_FILE_NO_BUFFERING                = &H00001000???
#ENDIF

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0500)
'//
'// Define ReplaceFile option flags
'//

%REPLACEFILE_WRITE_THROUGH       = &H00000001???
%REPLACEFILE_IGNORE_MERGE_ERRORS = &H00000002???

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%REPLACEFILE_IGNORE_ACL_ERRORS   = &H00000004???
#ENDIF
'#endif

'#endif // #if (_WIN32_WINNT >= 0x0500)

'//
'// Define the NamedPipe definitions
'//


'//
'// Define the dwOpenMode values for CreateNamedPipe
'//

%PIPE_ACCESS_INBOUND   = &H00000001???
%PIPE_ACCESS_OUTBOUND  = &H00000002???
%PIPE_ACCESS_DUPLEX    = &H00000003???

'//
'// Define the Named Pipe End flags for GetNamedPipeInfo
'//

%PIPE_CLIENT_END       = &H00000000???
%PIPE_SERVER_END       = &H00000001???

'//
'// Define the dwPipeMode values for CreateNamedPipe
'//

%PIPE_WAIT                  = &H00000000???
%PIPE_NOWAIT                = &H00000001???
%PIPE_READMODE_BYTE         = &H00000000???
%PIPE_READMODE_MESSAGE      = &H00000002???
%PIPE_TYPE_BYTE             = &H00000000???
%PIPE_TYPE_MESSAGE          = &H00000004???
%PIPE_ACCEPT_REMOTE_CLIENTS = &H00000000???
%PIPE_REJECT_REMOTE_CLIENTS = &H00000008???

'//
'// Define the well known values for CreateNamedPipe nMaxInstances
'//

%PIPE_UNLIMITED_INSTANCES = 255

'//
'// Define the Security Quality of Service bits to be passed
'// into CreateFile
'//

'#define SECURITY_ANONYMOUS          ( SecurityAnonymous      << 16 )
'#define SECURITY_IDENTIFICATION     ( SecurityIdentification << 16 )
'#define SECURITY_IMPERSONATION      ( SecurityImpersonation  << 16 )
'#define SECURITY_DELEGATION         ( SecurityDelegation     << 16 )

%SECURITY_ANONYMOUS        = 0???
%SECURITY_IDENTIFICATION   = &H00010000???
%SECURITY_IMPERSONATION    = &H00020000???
%SECURITY_DELEGATION       = &H00030000???

%SECURITY_CONTEXT_TRACKING = &H00040000???
%SECURITY_EFFECTIVE_ONLY   = &H00080000???

%SECURITY_SQOS_PRESENT     = &H00100000???
%SECURITY_VALID_SQOS_FLAGS = &H001F0000???

'//
'//  File structures
'//

' // Size = 8 bytes
TYPE OVERLAPPED_UNION_STRUCT DWORD
   Offset       AS DWORD   ' DWORD Offset
   OffsetHigh   AS DWORD   ' DWORD OffsetHigh
END TYPE

' // Size = 8 bytes
UNION OVERLAPPED_UNION DWORD
   OVERLAPPED_UNION_STRUCT
   Pointer AS DWORD        ' PVOID Pointer
END UNION

' // Size = 20 bytes
TYPE OVERLAPPED DWORD
   Internal          AS DWORD   ' ULONG_PTR Internal
   InternalHigh      AS DWORD   ' ULONG_PTR InternalHigh
   OVERLAPPED_UNION
   hEvent            AS DWORD   ' HANDLE  hEvent
END TYPE

' // Size = 16 bytes
TYPE OVERLAPPED_ENTRY DWORD
   lpCompletionKey            AS DWORD            ' ULONG_PTR
   lpOverlapped               AS OVERLAPPED PTR   ' LPOVERLAPPED
   Internal                   AS DWORD            ' ULONG_PTR
   dwNumberOfBytesTransferred AS DWORD            ' DWORD
END TYPE

#IF NOT %DEF(%SECURITY_ATTRIBUTES_DEFINED)
%SECURITY_ATTRIBUTES_DEFINED = 1
' // Size = 12 bytes
TYPE SECURITY_ATTRIBUTES DWORD
   nLength              AS DWORD   ' DWORD nLength
   lpSecurityDescriptor AS DWORD   ' LPVOID lpSecurityDescriptor
   bInheritHandle       AS LONG    ' BOOL bInheritHandle
END TYPE
#ENDIF

' // Size = 16 bytes
TYPE PROCESS_INFORMATION DWORD
   hProcess    AS DWORD   ' HANDLE hProcess
   hThread     AS DWORD   ' HANDLE hThread
   dwProcessId AS DWORD   ' DWORD dwProcessId
   dwThreadId  AS DWORD   ' DWORD dwThreadId
END TYPE

'//
'//  File System time stamps are represented with the following structure:
'//

#IF NOT %DEF(%FILETIME_DEFINED)
%FILETIME_DEFINED = 1
' // Size = 8 bytes
TYPE FILETIME_STRUCT DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

' // To allow to use both DWORD's and a QUAD
' // Size = 8 bytes
UNION FILETIME DWORD
   FILETIME_STRUCT
   qDateTime AS QUAD
END UNION
#ENDIF

'//
'// System time is represented with the following structure:
'//

#IF NOT %DEF(%SYSTEMTIME_DEFINED)
%SYSTEMTIME_DEFINED = 1
' // Size = 16 bytes
TYPE SYSTEMTIME WORD
   wYear         AS WORD   ' WORD wYear
   wMonth        AS WORD   ' WORD wMonth
   wDayOfWeek    AS WORD   ' WORD wDayOfWeek
   wDay          AS WORD   ' WORD wDay
   wHour         AS WORD   ' WORD wHour
   wMinute       AS WORD   ' WORD wMinute
   wSecond       AS WORD   ' WORD wSecond
   wMilliseconds AS WORD   ' WORD wMilliseconds
END TYPE
#ENDIF

'typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(
'    LPVOID lpThreadParameter
'    );
'typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

'#if(_WIN32_WINNT >= 0x0400)
'typedef VOID (WINAPI *PFIBER_START_ROUTINE)(
'    LPVOID lpFiberParameter
'    );
'typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
'#endif /* _WIN32_WINNT >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
'//
'// Define one-time initialization primitive
'//

'typedef RTL_RUN_ONCE INIT_ONCE;
'typedef PRTL_RUN_ONCE PINIT_ONCE;
'typedef PRTL_RUN_ONCE LPINIT_ONCE;

MACRO INIT_ONCE = RTL_RUN_ONCE

%INIT_ONCE_STATIC_INIT   = %RTL_RUN_ONCE_INIT

'//
'// Run once flags
'//

%INIT_ONCE_CHECK_ONLY        = %RTL_RUN_ONCE_CHECK_ONLY
%INIT_ONCE_ASYNC             = %RTL_RUN_ONCE_ASYNC
%INIT_ONCE_INIT_FAILED       = %RTL_RUN_ONCE_INIT_FAILED

'//
'// The context stored in the run once structure must leave the following number
'// of low order bits unused.
'//

%INIT_ONCE_CTX_RESERVED_BITS = %RTL_RUN_ONCE_CTX_RESERVED_BITS

'//
'// FailFast Exception Flags
'//

%FAIL_FAST_GENERATE_EXCEPTION_ADDRESS    = &H1???
%FAIL_FAST_NO_HARD_ERROR_DLG             = &H2???

'typedef
'BOOL
'(WINAPI *PINIT_ONCE_FN) (
'    __inout PINIT_ONCE InitOnce,
'    __inout PVOID Parameter,
'    __out PVOID *Context
'    );

'FUNCTION INIT_ONCE_FN ( _
'   BYREF InitOnce AS INIT_ONCE _                        ' __inout PINIT_ONCE InitOnce
' , BYREF Parameter AS DWORD _                           ' __inout PVOID Parameter
' , BYREF Context AS DWORD _                             ' __out PVOID *Context
' ) AS LONG                                              ' BOOL

DECLARE SUB InitOnceInitialize IMPORT "KERNEL32.DLL" ALIAS "InitOnceInitialize" ( _
   BYREF InitOnce AS INIT_ONCE _                        ' __out PINIT_ONCE InitOnce
 )                                                      ' void

DECLARE FUNCTION InitOnceExecuteOnce IMPORT "KERNEL32.DLL" ALIAS "InitOnceExecuteOnce" ( _
   BYREF InitOnce AS INIT_ONCE _                        ' __inout     PINIT_ONCE InitOnce
 , BYVAL InitFn AS DWORD _                              ' __in        PINIT_ONCE_FN InitFn
 , OPTIONAL BYREF Parameter AS ANY _                    ' __inout_opt PVOID Parameter
 , OPTIONAL BYREF Context AS ANY _                      ' __out_opt   LPVOID *Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitOnceBeginInitialize IMPORT "KERNEL32.DLL" ALIAS "InitOnceBeginInitialize" ( _
   BYREF lpInitOnce AS INIT_ONCE _                      ' __inout   LPINIT_ONCE lpInitOnce
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD dwFlags
 , BYREF fPending AS LONG _                             ' __out     PBOOL fPending
 , OPTIONAL BYREF lpContext AS ANY _                    ' __out_opt LPVOID *lpContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitOnceComplete IMPORT "KERNEL32.DLL" ALIAS "InitOnceComplete" ( _
   BYREF lpInitOnce AS INIT_ONCE _                      ' __inout  LPINIT_ONCE lpInitOnce
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 , OPTIONAL BYREF lpContext AS ANY _                    ' __in_opt LPVOID lpContext
 ) AS LONG                                              ' BOOL

#ENDIF   ' #if (_WIN32_WINNT >= 0x0600)

'//
'// Define the slim r/w lock
'//

'typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;
MACRO SRWLOCK = RTL_SRWLOCK

%SRWLOCK_INIT = %RTL_SRWLOCK_INIT

DECLARE SUB InitializeSRWLock IMPORT "KERNEL32.DLL" ALIAS "InitializeSRWLock" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __out PSRWLOCK SRWLock
 )                                                      ' void

DECLARE SUB ReleaseSRWLockExclusive IMPORT "KERNEL32.DLL" ALIAS "ReleaseSRWLockExclusive" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __out PSRWLOCK SRWLock
 )                                                      ' void

DECLARE SUB ReleaseSRWLockShared IMPORT "KERNEL32.DLL" ALIAS "ReleaseSRWLockShared" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __inout PSRWLOCK SRWLock
 )                                                      ' void

DECLARE SUB AcquireSRWLockExclusive IMPORT "KERNEL32.DLL" ALIAS "AcquireSRWLockExclusive" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __inout PSRWLOCK SRWLock
 )                                                      ' void

DECLARE SUB AcquireSRWLockShared IMPORT "KERNEL32.DLL" ALIAS "AcquireSRWLockShared" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __inout PSRWLOCK SRWLock
 )                                                      ' void

DECLARE FUNCTION TryAcquireSRWLockExclusive IMPORT "KERNEL32.DLL" ALIAS "TryAcquireSRWLockExclusive" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __inout PSRWLOCK SRWLock
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION TryAcquireSRWLockShared IMPORT "KERNEL32.DLL" ALIAS "TryAcquireSRWLockShared" ( _
   BYREF SRWLock AS SRWLOCK _                           ' __inout PSRWLOCK SRWLock
 ) AS BYTE                                              ' BOOLEAN

'//
'// Define condition variable
'//

'typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;
MACRO CONDITION_VARIABLE = RTL_CONDITION_VARIABLE

DECLARE SUB InitializeConditionVariable IMPORT "KERNEL32.DLL" ALIAS "InitializeConditionVariable" ( _
   BYREF ConditionVariable AS CONDITION_VARIABLE _      ' __out PCONDITION_VARIABLE ConditionVariable
 )                                                      ' void

DECLARE SUB WakeConditionVariable IMPORT "KERNEL32.DLL" ALIAS "WakeConditionVariable" ( _
   BYREF ConditionVariable AS CONDITION_VARIABLE _      ' __inout PCONDITION_VARIABLE ConditionVariable
 )                                                      ' void

DECLARE SUB WakeAllConditionVariable IMPORT "KERNEL32.DLL" ALIAS "WakeAllConditionVariable" ( _
   BYREF ConditionVariable AS CONDITION_VARIABLE _      ' __inout PCONDITION_VARIABLE ConditionVariable
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SleepConditionVariableCS LIB "Kernel32.dll" _
    ALIAS "SleepConditionVariableCS" (ConditionVariable AS CONDITION_VARIABLE, _
    CriticalSection AS DWORD, BYVAL dwMilliseconds AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SleepConditionVariableCS IMPORT "KERNEL32.DLL" ALIAS "SleepConditionVariableCS" ( _
   BYREF ConditionVariable AS CONDITION_VARIABLE _     ' __inout PCONDITION_VARIABLE ConditionVariable
 , BYREF CriticalSection AS CRITICAL_SECTION _         ' __inout PCRITICAL_SECTION CriticalSection
 , BYVAL dwMilliseconds AS DWORD _                     ' __in    DWORD dwMilliseconds
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SleepConditionVariableSRW IMPORT "KERNEL32.DLL" ALIAS "SleepConditionVariableSRW" ( _
   BYREF ConditionVariable AS CONDITION_VARIABLE _     ' __inout PCONDITION_VARIABLE ConditionVariable
 , BYREF SRWLock AS SRWLOCK _                          ' __inout PSRWLOCK SRWLock
 , BYVAL dwMilliseconds AS DWORD _                     ' __in    DWORD dwMilliseconds
 , BYVAL Flags AS DWORD _                              ' __in    ULONG Flags
 ) AS LONG                                              ' BOOL

'//
'// Static initializer for the condition variable
'//

%CONDITION_VARIABLE_INIT = %RTL_CONDITION_VARIABLE_INIT

'//
'// Flags for condition variables
'//
%CONDITION_VARIABLE_LOCKMODE_SHARED = %RTL_CONDITION_VARIABLE_LOCKMODE_SHARED

DECLARE FUNCTION EncodePointer IMPORT "KERNEL32.DLL" ALIAS "EncodePointer" ( _
   BYVAL Ptr AS DWORD _                                 ' __in PVOID Ptr
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION DecodePointer IMPORT "KERNEL32.DLL" ALIAS "DecodePointer" ( _
   BYVAL Ptr AS DWORD _                                 ' __in PVOID Ptr
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION EncodeSystemPointer IMPORT "KERNEL32.DLL" ALIAS "EncodeSystemPointer" ( _
   BYVAL Ptr AS DWORD _                                 ' __in PVOID Ptr
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION DecodeSystemPointer IMPORT "KERNEL32.DLL" ALIAS "DecodeSystemPointer" ( _
   BYVAL Ptr AS DWORD _                                 ' __in PVOID Ptr
 ) AS DWORD                                             ' PVOID

'#if defined(_X86_)
'typedef PLDT_ENTRY LPLDT_ENTRY;
'#else
'typedef LPVOID LPLDT_ENTRY;
'#endif

%MUTEX_MODIFY_STATE = %MUTANT_QUERY_STATE
%MUTEX_ALL_ACCESS   = %MUTANT_ALL_ACCESS

'//
'// Serial provider type.
'//

%SP_SERIALCOMM      = &H00000001???

'//
'// Provider SubTypes
'//

%PST_UNSPECIFIED    = &H00000000???
%PST_RS232          = &H00000001???
%PST_PARALLELPORT   = &H00000002???
%PST_RS422          = &H00000003???
%PST_RS423          = &H00000004???
%PST_RS449          = &H00000005???
%PST_FAX            = &H00000021???
%PST_SCANNER        = &H00000022???
%PST_NETWORK_BRIDGE = &H00000100???
%PST_LAT            = &H00000101???
%PST_TCPIP_TELNET   = &H00000102???
%PST_X25            = &H00000103???

'//
'// Provider capabilities flags.
'//

%PCF_DTRDSR        = &H0001???
%PCF_RTSCTS        = &H0002???
%PCF_RLSD          = &H0004???
%PCF_PARITY_CHECK  = &H0008???
%PCF_XONXOFF       = &H0010???
%PCF_SETXCHAR      = &H0020???
%PCF_TOTALTIMEOUTS = &H0040???
%PCF_INTTIMEOUTS   = &H0080???
%PCF_SPECIALCHARS  = &H0100???
%PCF_16BITMODE     = &H0200???

'//
'// Comm provider settable parameters.
'//

%SP_PARITY         = &H0001???
%SP_BAUD           = &H0002???
%SP_DATABITS       = &H0004???
%SP_STOPBITS       = &H0008???
%SP_HANDSHAKING    = &H0010???
%SP_PARITY_CHECK   = &H0020???
%SP_RLSD           = &H0040???

'//
'// Settable baud rates in the provider.
'//

%BAUD_075          = &H00000001???
%BAUD_110          = &H00000002???
%BAUD_134_5        = &H00000004???
%BAUD_150          = &H00000008???
%BAUD_300          = &H00000010???
%BAUD_600          = &H00000020???
%BAUD_1200         = &H00000040???
%BAUD_1800         = &H00000080???
%BAUD_2400         = &H00000100???
%BAUD_4800         = &H00000200???
%BAUD_7200         = &H00000400???
%BAUD_9600         = &H00000800???
%BAUD_14400        = &H00001000???
%BAUD_19200        = &H00002000???
%BAUD_38400        = &H00004000???
%BAUD_56K          = &H00008000???
%BAUD_128K         = &H00010000???
%BAUD_115200       = &H00020000???
%BAUD_57600        = &H00040000???
%BAUD_USER         = &H10000000???

'//
'// Settable Data Bits
'//

%DATABITS_5        = &H0001??
%DATABITS_6        = &H0002??
%DATABITS_7        = &H0004??
%DATABITS_8        = &H0008??
%DATABITS_16       = &H0010??
%DATABITS_16X      = &H0020??

'//
'// Settable Stop and Parity bits.
'//

%STOPBITS_10       = &H0001??
%STOPBITS_15       = &H0002??
%STOPBITS_20       = &H0004??
%PARITY_NONE       = &H0100??
%PARITY_ODD        = &H0200??
%PARITY_EVEN       = &H0400??
%PARITY_MARK       = &H0800??
%PARITY_SPACE      = &H1000??

' // Size = 64 bytes
TYPE COMMPROP DWORD FILL
   wPacketLength       AS WORD       ' WORD  wPacketLength
   wPacketVersion      AS WORD       ' WORD  wPacketVersion
   dwServiceMask       AS DWORD      ' DWORD dwServiceMask
   dwReserved1         AS DWORD      ' DWORD dwReserved1
   dwMaxTxQueue        AS DWORD      ' DWORD dwMaxTxQueue
   dwMaxRxQueue        AS DWORD      ' DWORD dwMaxRxQueue
   dwMaxBaud           AS DWORD      ' DWORD dwMaxBaud
   dwProvSubType       AS DWORD      ' DWORD dwProvSubType
   dwProvCapabilities  AS DWORD      ' DWORD dwProvCapabilities
   dwSettableParams    AS DWORD      ' DWORD dwSettableParams
   dwSettableBaud      AS DWORD      ' DWORD dwSettableBaud
   wSettableData       AS WORD       ' WORD  wSettableData
   wSettableStopParity AS WORD       ' WORD  wSettableStopParity
   dwCurrentTxQueue    AS DWORD      ' DWORD dwCurrentTxQueue
   dwCurrentRxQueue    AS DWORD      ' DWORD dwCurrentRxQueue
   dwProvSpec1         AS DWORD      ' DWORD dwProvSpec1
   dwProvSpec2         AS DWORD      ' DWORD dwProvSpec2
   wcProvChar(1)       AS WORD       ' WCHAR wcProvChar[1] ' any size
   ' Note: We are using wcProvChar(1) instead of wcProvChar(0) to keep DWORD alignment
END TYPE

'//
'// Set dwProvSpec1 to COMMPROP_INITIALIZED to indicate that wPacketLength
'// is valid before a call to GetCommProperties().
'//
%COMMPROP_INITIALIZED = &HE73CF52E???

' // Size = 12 bytes
TYPE COMSTAT DWORD
   fCtsHold  AS BIT * 1 IN DWORD   ' DWORD fCtsHold : 1
   fDsrHold  AS BIT * 1            ' DWORD fDsrHold : 1
   fRlsdHold AS BIT * 1            ' DWORD fRlsdHold : 1
   fXoffHold AS BIT * 1            ' DWORD fXoffHold : 1
   fXoffSent AS BIT * 1            ' DWORD fXoffSent : 1
   fEof      AS BIT * 1            ' DWORD fEof : 1
   fTxim     AS BIT * 1            ' DWORD fTxim : 1
   fReserved AS BIT * 25           ' DWORD fReserved : 25
   cbInQue   AS DWORD              ' DWORD cbInQue
   cbOutQue  AS DWORD              ' DWORD cbOutQue
END TYPE

'//
'// DTR Control Flow Values.
'//
%DTR_CONTROL_DISABLE   = &H00???
%DTR_CONTROL_ENABLE    = &H01???
%DTR_CONTROL_HANDSHAKE = &H02???

'//
'// RTS Control Flow Values
'//
%RTS_CONTROL_DISABLE   = &H00???
%RTS_CONTROL_ENABLE    = &H01???
%RTS_CONTROL_HANDSHAKE = &H02???
%RTS_CONTROL_TOGGLE    = &H03???

' // Size = 28 bytes
TYPE DCB DWORD FILL
   DCBlength         AS DWORD               ' DWORD DCBlength;      /* sizeof(DCB)                     */
   BaudRate          AS DWORD               ' DWORD BaudRate;       /* Baudrate at which running       */
   fBinary           AS BIT * 1  IN DWORD   ' DWORD fBinary: 1;     /* Binary Mode (skip EOF check)    */
   fParity           AS BIT * 1             ' DWORD fParity: 1;     /* Enable parity checking          */
   fOutxCtsFlow      AS BIT * 1             ' DWORD fOutxCtsFlow:1; /* CTS handshaking on output       */
   fOutxDsrFlow      AS BIT * 1             ' DWORD fOutxDsrFlow:1; /* DSR handshaking on output       */
   fDtrControl       AS BIT * 2             ' DWORD fDtrControl:2;  /* DTR Flow control                */
   fDsrSensitivity   AS BIT * 1             ' DWORD fDsrSensitivity:1; /* DSR Sensitivity              */
   fTXContinueOnXoff AS BIT * 1             ' DWORD fTXContinueOnXoff: 1; /* Continue TX when Xoff sent */
   fOutX             AS BIT * 1             ' DWORD fOutX: 1;       /* Enable output X-ON/X-OFF        */
   fInX              AS BIT * 1             ' DWORD fInX: 1;        /* Enable input X-ON/X-OFF         */
   fErrorChar        AS BIT * 1             ' DWORD fErrorChar: 1;  /* Enable Err Replacement          */
   fNull             AS BIT * 1             ' DWORD fNull: 1;       /* Enable Null stripping           */
   fRtsControl       AS BIT * 2             ' DWORD fRtsControl:2;  /* Rts Flow control                */
   fAbortOnError     AS BIT * 1             ' DWORD fAbortOnError:1; /* Abort all reads and writes on Error */
   fDummy2           AS BIT * 17            ' DWORD fDummy2:17;     /* Reserved                        */
   wReserved         AS WORD                ' WORD  wReserved;       /* Not currently used              */
   XonLim            AS WORD                ' WORD  XonLim;          /* Transmit X-ON threshold         */
   XoffLim           AS WORD                ' WORD  XoffLim;         /* Transmit X-OFF threshold        */
   ByteSize          AS BYTE                ' BYTE  ByteSize;        /* Number of bits/byte, 4-8        */
   Parity            AS BYTE                ' BYTE  Parity;          /* 0-4=None,Odd,Even,Mark,Space    */
   StopBits          AS BYTE                ' BYTE  StopBits;        /* 0,1,2 = 1, 1.5, 2               */
   XonChar           AS BYTE                ' char  XonChar;         /* Tx and Rx X-ON character        */
   XoffChar          AS BYTE                ' char  XoffChar;        /* Tx and Rx X-OFF character       */
   ErrorChar         AS BYTE                ' char  ErrorChar;       /* Error replacement char          */
   EofChar           AS BYTE                ' char  EofChar;         /* End of Input character          */
   EvtChar           AS BYTE                ' char  EvtChar;         /* Received Event character        */
   wReserved2        AS WORD                ' WORD  wReserved1;      /* Fill for now.                   */
END TYPE

' // Size = 20 bytes
TYPE COMMTIMEOUTS DWORD
   ReadIntervalTimeout         AS DWORD   ' DWORD ReadIntervalTimeout;          /* Maximum time between read chars. */
   ReadTotalTimeoutMultiplier  AS DWORD   ' DWORD ReadTotalTimeoutMultiplier;   /* Multiplier of characters.        */
   ReadTotalTimeoutConstant    AS DWORD   ' DWORD ReadTotalTimeoutConstant;     /* Constant in milliseconds.        */
   WriteTotalTimeoutMultiplier AS DWORD   ' DWORD WriteTotalTimeoutMultiplier;  /* Multiplier of characters.        */
   WriteTotalTimeoutConstant   AS DWORD   ' DWORD WriteTotalTimeoutConstant;    /* Constant in milliseconds.        */
END TYPE

' // Size = 52 bytes
TYPE COMMCONFIG DWORD FILL
   dwSize            AS DWORD      ' DWORD dwSize               /* Size of the entire struct */
   wVersion          AS WORD       ' WORD  wVersion             /* version of the structure */
   wReserved         AS WORD       ' WORD  wReserved            /* alignment */
   dcbx              AS DCB        ' DCB   dcb                  /* device control block */
   dwProviderSubType AS DWORD      ' DWORD dwProviderSubType    /* ordinal value for identifying
                                   '                               provider-defined data structure format*/
   dwProviderOffset  AS DWORD      ' DWORD dwProviderOffset     /* Specifies the offset of provider specific
                                   '                               data field in bytes from the start */
   dwProviderSize    AS DWORD      ' DWORD dwProviderSize       /* size of the provider-specific data field */
   wcProviderData(1) AS WORD       ' WCHAR wcProviderData[1]    /* provider-specific data */ any size
   ' // Note: We are using wcProviderData(1) instead of wcProviderData(0) to keep DWORD alignment.
END TYPE

' // Size = 4 bytes
TYPE SYSTEM_INFO_UNION_STRUCT WORD
   wProcessorArchitecture AS WORD   ' WORD wProcessorArchitecture
   wReserved              AS WORD   ' WORD wReserved
END TYPE

' // Size = 4 bytes
UNION SYSTEM_INFO_UNION DWORD
   dwOemId AS DWORD   ' DWORD dwOemId;          // Obsolete field...do not use
   SYSTEM_INFO_UNION_STRUCT
END UNION

' // Size = 36 bytes
TYPE SYSTEM_INFO DWORD FILL
   SYSTEM_INFO_UNION
   dwPageSize                  AS DWORD   ' DWORD     dwPageSize
   lpMinimumApplicationAddress AS DWORD   ' LPVOID    lpMinimumApplicationAddress
   lpMaximumApplicationAddress AS DWORD   ' LPVOID    lpMaximumApplicationAddress
   dwActiveProcessorMask       AS DWORD   ' DWORD_PTR dwActiveProcessorMask
   dwNumberOfProcessors        AS DWORD   ' DWORD     dwNumberOfProcessors;
   dwProcessorType             AS DWORD   ' DWORD     dwProcessorType
   dwAllocationGranularity     AS DWORD   ' DWORD     dwAllocationGranularity
   wProcessorLevel             AS WORD    ' WORD      wProcessorLevel
   wProcessorRevision          AS WORD    ' WORD      wProcessorRevision
END TYPE


'//
'//

'#define FreeModule(hLibModule) FreeLibrary((hLibModule))
'#define MakeProcInstance(lpProc,hInstance) (lpProc)
'#define FreeProcInstance(lpProc) (lpProc)

'/* Global Memory Flags */
%GMEM_FIXED          = &H0000???
%GMEM_MOVEABLE       = &H0002???
%GMEM_NOCOMPACT      = &H0010???
%GMEM_NODISCARD      = &H0020???
%GMEM_ZEROINIT       = &H0040???
%GMEM_MODIFY         = &H0080???
%GMEM_DISCARDABLE    = &H0100???
%GMEM_NOT_BANKED     = &H1000???
%GMEM_SHARE          = &H2000???
%GMEM_DDESHARE       = &H2000???
%GMEM_NOTIFY         = &H4000???
%GMEM_LOWER          = %GMEM_NOT_BANKED
%GMEM_VALID_FLAGS    = &H7F72???
%GMEM_INVALID_HANDLE = &H00008000???

%GHND = %GMEM_MOVEABLE OR %GMEM_ZEROINIT
%GPTR = %GMEM_FIXED OR %GMEM_ZEROINIT

'#define GlobalLRUNewest( h )    ((HANDLE)(h))
'#define GlobalLRUOldest( h )    ((HANDLE)(h))
'#define GlobalDiscard( h )      GlobalReAlloc( (h), 0, GMEM_MOVEABLE )

'/* Flags returned by GlobalFlags (in addition to GMEM_DISCARDABLE) */
%GMEM_DISCARDED = &H4000???
%GMEM_LOCKCOUNT = &H00FF???

' // Size = 32 bytes
TYPE MEMORYSTATUS DWORD
   dwLength        AS DWORD   ' DWORD  dwLength
   dwMemoryLoad    AS DWORD   ' DWORD  dwMemoryLoad
   dwTotalPhys     AS DWORD   ' SIZE_T dwTotalPhys
   dwAvailPhys     AS DWORD   ' SIZE_T dwAvailPhys
   dwTotalPageFile AS DWORD   ' SIZE_T dwTotalPageFile
   dwAvailPageFile AS DWORD   ' SIZE_T dwAvailPageFile
   dwTotalVirtual  AS DWORD   ' SIZE_T dwTotalVirtual
   dwAvailVirtual  AS DWORD   ' SIZE_T dwAvailVirtual
END TYPE

'/* Local Memory Flags */
%LMEM_FIXED          = &H0000???
%LMEM_MOVEABLE       = &H0002???
%LMEM_NOCOMPACT      = &H0010???
%LMEM_NODISCARD      = &H0020???
%LMEM_ZEROINIT       = &H0040???
%LMEM_MODIFY         = &H0080???
%LMEM_DISCARDABLE    = &H0F00???
%LMEM_VALID_FLAGS    = &H0F72???
%LMEM_INVALID_HANDLE = &H8000???

%LHND = %LMEM_MOVEABLE + %LMEM_ZEROINIT
%LPTR = %LMEM_FIXED + %LMEM_ZEROINIT

%NONZEROLHND  = %LMEM_MOVEABLE
%NONZEROLPTR  = %LMEM_FIXED

'#define LocalDiscard( h )   LocalReAlloc( (h), 0, LMEM_MOVEABLE )

'/* Flags returned by LocalFlags (in addition to LMEM_DISCARDABLE) */
%LMEM_DISCARDED      = &H4000???
%LMEM_LOCKCOUNT      = &H00FF???

'//
'// NUMA values
'//
%NUMA_NO_PREFERRED_NODE = &HFFFFFFFF???   ' ((DWORD) -1)

'//
'// dwCreationFlag values
'//

' // Note: The remed flags are predefined in the compiler.

%DEBUG_PROCESS                     = &H00000001???
%DEBUG_ONLY_THIS_PROCESS           = &H00000002???
%CREATE_SUSPENDED                  = &H00000004???
%DETACHED_PROCESS                  = &H00000008???

%CREATE_NEW_CONSOLE                = &H00000010???
'%NORMAL_PRIORITY_CLASS             = &H00000020???
'%IDLE_PRIORITY_CLASS               = &H00000040???
'%HIGH_PRIORITY_CLASS               = &H00000080???

'%REALTIME_PRIORITY_CLASS           = &H00000100???
%CREATE_NEW_PROCESS_GROUP          = &H00000200???
%CREATE_UNICODE_ENVIRONMENT        = &H00000400???
%CREATE_SEPARATE_WOW_VDM           = &H00000800???

%CREATE_SHARED_WOW_VDM             = &H00001000???
%CREATE_FORCEDOS                   = &H00002000???
%BELOW_NORMAL_PRIORITY_CLASS       = &H00004000???
%ABOVE_NORMAL_PRIORITY_CLASS       = &H00008000???

%INHERIT_PARENT_AFFINITY           = &H00010000???
%INHERIT_CALLER_PRIORITY           = &H00020000???   ' // Deprecated
%CREATE_PROTECTED_PROCESS          = &H00040000???
%EXTENDED_STARTUPINFO_PRESENT      = &H00080000???

%PROCESS_MODE_BACKGROUND_BEGIN     = &H00100000???
%PROCESS_MODE_BACKGROUND_END       = &H00200000???

%CREATE_BREAKAWAY_FROM_JOB         = &H01000000???
%CREATE_PRESERVE_CODE_AUTHZ_LEVEL  = &H02000000???
%CREATE_DEFAULT_ERROR_MODE         = &H04000000???
%CREATE_NO_WINDOW                  = &H08000000???

%PROFILE_USER                      = &H10000000???
%PROFILE_KERNEL                    = &H20000000???
%PROFILE_SERVER                    = &H40000000???
%CREATE_IGNORE_SYSTEM_DEFAULT      = &H80000000???

'//
'// Thread dwCreationFlag values
'//

'//#define CREATE_SUSPENDED                  0x00000004

%STACK_SIZE_PARAM_IS_A_RESERVATION = &H00010000???   ' // Threads only

'//
'// Priority flags
'//

' // The remed dlags are predefined in the compiler.
'%THREAD_PRIORITY_LOWEST        = %THREAD_BASE_PRIORITY_MIN
'%THREAD_PRIORITY_BELOW_NORMAL  = %THREAD_PRIORITY_LOWEST + 1
'%THREAD_PRIORITY_NORMAL        = 0
'%THREAD_PRIORITY_HIGHEST       = %THREAD_BASE_PRIORITY_MAX
'%THREAD_PRIORITY_ABOVE_NORMAL  = %THREAD_PRIORITY_HIGHEST - 1
%THREAD_PRIORITY_ERROR_RETURN  = %MAXLONG

'%THREAD_PRIORITY_TIME_CRITICAL = %THREAD_BASE_PRIORITY_LOWRT
'%THREAD_PRIORITY_IDLE          = %THREAD_BASE_PRIORITY_IDLE

%THREAD_MODE_BACKGROUND_BEGIN  = &H00010000???
%THREAD_MODE_BACKGROUND_END    = &H00020000???

'//
'// GetFinalPathNameByHandle
'//

%VOLUME_NAME_DOS  = &H0     ' //default
%VOLUME_NAME_GUID = &H1
%VOLUME_NAME_NT   = &H2
%VOLUME_NAME_NONE = &H4

%FILE_NAME_NORMALIZED = &H0   ' //default
%FILE_NAME_OPENED     = &H8

'//
'// Debug APIs
'//
%EXCEPTION_DEBUG_EVENT      = 1
%CREATE_THREAD_DEBUG_EVENT  = 2
%CREATE_PROCESS_DEBUG_EVENT = 3
%EXIT_THREAD_DEBUG_EVENT    = 4
%EXIT_PROCESS_DEBUG_EVENT   = 5
%LOAD_DLL_DEBUG_EVENT       = 6
%UNLOAD_DLL_DEBUG_EVENT     = 7
%OUTPUT_DEBUG_STRING_EVENT  = 8
%RIP_EVENT                  = 9

' // Size = 84 bytes
TYPE EXCEPTION_DEBUG_INFO DWORD
  ExceptionRecord AS EXCEPTION_RECORD   ' EXCEPTION_RECORD ExceptionRecord
  dwFirstChance   AS DWORD              ' DWORD dwFirstChance
END TYPE

' // Size = 12 bytes
TYPE CREATE_THREAD_DEBUG_INFO DWORD
   hThread           AS DWORD   ' HANDLE hThread
   lpThreadLocalBase AS DWORD   ' LPVOID lpThreadLocalBase
   lpStartAddress    AS DWORD   ' LPTHREAD_START_ROUTINE lpStartAddress
END TYPE

' // Size = 40 bytes
TYPE CREATE_PROCESS_DEBUG_INFO DWORD
   hFile                 AS DWORD       ' HANDLE hFile
   hProcess              AS DWORD       ' HANDLE hProcess
   hThread               AS DWORD       ' HANDLE hThread
   lpBaseOfImage         AS DWORD       ' LPVOID lpBaseOfImage
   dwDebugInfoFileOffset AS DWORD       ' DWORD  dwDebugInfoFileOffset
   nDebugInfoSize        AS DWORD       ' DWORD  nDebugInfoSize
   lpThreadLocalBase     AS DWORD       ' LPVOID lpThreadLocalBase
   lpStartAddress        AS DWORD       ' LPTHREAD_START_ROUTINE lpStartAddress
   lpImageName           AS DWORD PTR   ' LPVOID lpImageName
   fUnicode              AS WORD        ' WORD   fUnicode
END TYPE

' // Size = 4 bytes
TYPE EXIT_THREAD_DEBUG_INFO DWORD
   dwExitCode AS DWORD   ' DWORD dwExitCode
END TYPE

' // Size = 4 bytes
TYPE EXIT_PROCESS_DEBUG_INFO DWORD
   dwExitCode AS DWORD   ' DWORD dwExitCode
END TYPE

' // Size = 24 bytes
TYPE LOAD_DLL_DEBUG_INFO DWORD
   hFile                 AS DWORD        ' HANDLE hFile
   lpBaseOfDll           AS LONG         ' LPVOID lpBaseOfDll
   dwDebugInfoFileOffset AS DWORD        ' DWORD  dwDebugInfoFileOffset
   nDebugInfoSize        AS DWORD        ' DWORD  nDebugInfoSize;
   lpImageName           AS DWORD PTR    ' LPVOID lpImageName
   fUnicode              AS WORD         ' WORD   fUnicode
END TYPE

' // Size = 4 bytes
TYPE UNLOAD_DLL_DEBUG_INFO DWORD
   lpBaseOfDll AS LONG   ' LPVOID lpBaseOfDll
END TYPE

' // Size = 8 bytes
TYPE OUTPUT_DEBUG_STRING_INFO DWORD FILL
   lpDebugStringData  AS ASCIIZ PTR   ' LPSTR lpDebugStringData
   fUnicode           AS WORD         ' WORD  fUnicode
   nDebugStringLength AS WORD         ' WORD  nDebugStringLength
END TYPE

' // Size = 8 bytes
TYPE RIP_INFO DWORD
   dwError AS DWORD   ' DWORD dwError
   dwType  AS DWORD   ' DWORD dwType
END TYPE

' // Size = 84 bytes
UNION DEBUGEVENTUNION
   deuException         AS EXCEPTION_DEBUG_INFO        ' EXCEPTION_DEBUG_INFO Exception
   deuCreateThread      AS CREATE_THREAD_DEBUG_INFO    ' CREATE_THREAD_DEBUG_INFO CreateThread
   deuCreateProcessInfo AS CREATE_PROCESS_DEBUG_INFO   ' CREATE_PROCESS_DEBUG_INFO CreateProcessInfo
   deuExitThread        AS EXIT_THREAD_DEBUG_INFO      ' EXIT_THREAD_DEBUG_INFO ExitThread
   deuExitProcess       AS EXIT_PROCESS_DEBUG_INFO     ' EXIT_PROCESS_DEBUG_INFO ExitProcess
   deuLoadDll           AS LOAD_DLL_DEBUG_INFO         ' LOAD_DLL_DEBUG_INFO LoadDll
   deuUnloadDll         AS UNLOAD_DLL_DEBUG_INFO       ' UNLOAD_DLL_DEBUG_INFO UnloadDll
   deuDebugString       AS OUTPUT_DEBUG_STRING_INFO    ' OUTPUT_DEBUG_STRING_INFO DebugString
   deuRipInfo           AS RIP_INFO                    ' RIP_INFO RipInfo
END UNION

UNION DEBUG_EVENT_U_UNION
   DEBUGEVENTUNION
   u AS DEBUGEVENTUNION
END UNION

' // Size = 96 bytes
TYPE DEBUG_EVENT DWORD
   dwDebugEventCode AS DWORD   ' DWORD dwDebugEventCode
   dwProcessId      AS DWORD   ' DWORD dwProcessId
   dwThreadId       AS DWORD   ' DWORD dwThreadId
   DEBUG_EVENT_U_UNION
END TYPE

'//
'// JIT Debugging Info. This structure is defined to have constant size in
'// both the emulated and native environment.
'//

' // Size = 40 bytes
TYPE JIT_DEBUG_INFO QWORD FILL
   dwSize                  AS DWORD   ' DWORD
   dwProcessorArchitecture AS DWORD   ' DWORD
   dwThreadID              AS DWORD   ' DWORD
   dwReserved0             AS DWORD   ' DWORD
   lpExceptionAddress      AS QUAD    ' ULONG64
   lpExceptionRecord       AS QUAD    ' ULONG64
   lpContextRecord         AS QUAD    ' ULONG64
END TYPE

%DRIVE_UNKNOWN     = 0
%DRIVE_NO_ROOT_DIR = 1
%DRIVE_REMOVABLE   = 2
%DRIVE_FIXED       = 3
%DRIVE_REMOTE      = 4
%DRIVE_CDROM       = 5
%DRIVE_RAMDISK     = 6

'#ifndef _MAC
'#define GetFreeSpace(w)                 (0x100000L)
'#else
'WINBASEAPI DWORD WINAPI GetFreeSpace(__in UINT);
'#endif

%FILE_TYPE_UNKNOWN = &H0000???
%FILE_TYPE_DISK    = &H0001???
%FILE_TYPE_CHAR    = &H0002???
%FILE_TYPE_PIPE    = &H0003???
%FILE_TYPE_REMOTE  = &H8000???

%STD_INPUT_HANDLE  = &HFFFFFFF6???   ' ((DWORD)-10)
%STD_OUTPUT_HANDLE = &HFFFFFFF5???   ' ((DWORD)-11)
%STD_ERROR_HANDLE  = &HFFFFFFF4???   ' ((DWORD)-12)

%NOPARITY    = 0
%ODDPARITY   = 1
%EVENPARITY  = 2
%MARKPARITY  = 3
%SPACEPARITY = 4

%ONESTOPBIT   = 0
%ONE5STOPBITS = 1
%TWOSTOPBITS  = 2

%IGNORE   = 0               ' Ignore signal
%INFINITE = &HFFFFFFFF???   ' Infinite timeout

'//
'// Baud rates at which the communication device operates
'//

%CBR_110      = 110
%CBR_300      = 300
%CBR_600      = 600
%CBR_1200     = 1200
%CBR_2400     = 2400
%CBR_4800     = 4800
%CBR_9600     = 9600
%CBR_14400    = 14400
%CBR_19200    = 19200
%CBR_38400    = 38400
%CBR_56000    = 56000
%CBR_57600    = 57600
%CBR_115200   = 115200
%CBR_128000   = 128000
%CBR_256000   = 256000

'//
'// Error Flags
'//

%CE_RXOVER   = &H0001???    ' Receive Queue overflow
%CE_OVERRUN  = &H0002???    ' Receive Overrun Error
%CE_RXPARITY = &H0004???    ' Receive Parity Error
%CE_FRAME    = &H0008???    ' Receive Framing error
%CE_BREAK    = &H0010???    ' Break Detected
%CE_TXFULL   = &H0100???    ' TX Queue is full
%CE_PTO      = &H0200???    ' LPTx Timeout
%CE_IOE      = &H0400???    ' LPTx I/O Error
%CE_DNS      = &H0800???    ' LPTx Device not selected
%CE_OOP      = &H1000???    ' LPTx Out-Of-Paper
%CE_MODE     = &H8000???    ' Requested mode unsupported

%IE_BADID    = -1        ' Invalid or unsupported id
%IE_OPEN     = -2        ' Device Already Open
%IE_NOPEN    = -3        ' Device Not Open
%IE_MEMORY   = -4        ' Unable to allocate queues
%IE_DEFAULT  = -5        ' Error in default parameters
%IE_HARDWARE = -10       ' Hardware Not Present
%IE_BYTESIZE = -11       ' Illegal Byte Size
%IE_BAUDRATE = -12       ' Unsupported BaudRate

'//
'// Events
'//

%EV_RXCHAR   = &H0001???    ' Any Character received
%EV_RXFLAG   = &H0002???    ' Received certain character
%EV_TXEMPTY  = &H0004???    ' Transmitt Queue Empty
%EV_CTS      = &H0008???    ' CTS changed state
%EV_DSR      = &H0010???    ' DSR changed state
%EV_RLSD     = &H0020???    ' RLSD changed state
%EV_BREAK    = &H0040???    ' BREAK received
%EV_ERR      = &H0080???    ' Line status error occurred
%EV_RING     = &H0100???    ' Ring signal detected
%EV_PERR     = &H0200???    ' Printer error occured
%EV_RX80FULL = &H0400???    ' Receive buffer is 80 percent full
%EV_EVENT1   = &H0800???    ' Provider specific event 1
%EV_EVENT2   = &H1000???    ' Provider specific event 2

'//
'// Escape Functions
'//

%SETXOFF  = 1         ' Simulate XOFF received
%SETXON   = 2         ' Simulate XON received
%SETRTS   = 3         ' Set RTS high
%CLRRTS   = 4         ' Set RTS low
%SETDTR   = 5         ' Set DTR high
%CLRDTR   = 6         ' Set DTR low
%RESETDEV = 7         ' Reset device if possible
%SETBREAK = 8         ' Set the device break line
%CLRBREAK = 9         ' Clear the device break line

'//
'// PURGE function flags.
'//
%PURGE_TXABORT = &H0001???       ' Kill the pending/current writes to the comm port.
%PURGE_RXABORT = &H0002???       ' Kill the pending/current reads to the comm port.
%PURGE_TXCLEAR = &H0004???       ' Kill the transmit queue if there.
%PURGE_RXCLEAR = &H0008???       ' Kill the typeahead buffer if there.

'#define LPTx                0x80    // Set if ID is for LPT device

%LPTx = &H80      ' Set if ID is for LPT device

'//
'// Modem Status Flags
'//
%MS_CTS_ON  = &H0010???
%MS_DSR_ON  = &H0020???
%MS_RING_ON = &H0040???
%MS_RLSD_ON = &H0080???

'//
'// WaitSoundState() Constants
'//

%S_QUEUEEMPTY   = 0
%S_THRESHOLD    = 1
%S_ALLTHRESHOLD = 2

'//
'// Accent Modes
'//

%S_NORMAL       = 0
%S_LEGATO       = 1
%S_STACCATO     = 2

'//
'// SetSoundNoise() Sources
'//

%S_PERIOD512    = 0   ' Freq = N/512 high pitch, less coarse hiss
%S_PERIOD1024   = 1   ' Freq = N/1024
%S_PERIOD2048   = 2   ' Freq = N/2048 low pitch, more coarse hiss
%S_PERIODVOICE  = 3   ' Source is frequency from voice channel (3)
%S_WHITE512     = 4   ' Freq = N/512 high pitch, less coarse hiss
%S_WHITE1024    = 5   ' Freq = N/1024
%S_WHITE2048    = 6   ' Freq = N/2048 low pitch, more coarse hiss
%S_WHITEVOICE   = 7   ' Source is frequency from voice channel (3)

%S_SERDVNA      = -1  ' Device not available
%S_SEROFM       = -2  ' Out of memory
%S_SERMACT      = -3  ' Music active
%S_SERQFUL      = -4  ' Queue full
%S_SERBDNT      = -5  ' Invalid note
%S_SERDLN       = -6  ' Invalid note length
%S_SERDCC       = -7  ' Invalid note count
%S_SERDTP       = -8  ' Invalid tempo
%S_SERDVL       = -9  ' Invalid volume
%S_SERDMD       = -10 ' Invalid mode
%S_SERDSH       = -11 ' Invalid shape
%S_SERDPT       = -12 ' Invalid pitch
%S_SERDFQ       = -13 ' Invalid frequency
%S_SERDDR       = -14 ' Invalid duration
%S_SERDSR       = -15 ' Invalid source
%S_SERDST       = -16 ' Invalid state

%NMPWAIT_WAIT_FOREVER      = &HFFFFFFFF???
%NMPWAIT_NOWAIT            = &H00000001???
%NMPWAIT_USE_DEFAULT_WAIT  = &H00000000???

%FS_CASE_IS_PRESERVED      = %FILE_CASE_PRESERVED_NAMES
%FS_CASE_SENSITIVE         = %FILE_CASE_SENSITIVE_SEARCH
%FS_UNICODE_STORED_ON_DISK = %FILE_UNICODE_ON_DISK
%FS_PERSISTENT_ACLS        = %FILE_PERSISTENT_ACLS
%FS_VOL_IS_COMPRESSED      = %FILE_VOLUME_IS_COMPRESSED
%FS_FILE_COMPRESSION       = %FILE_FILE_COMPRESSION
%FS_FILE_ENCRYPTION        = %FILE_SUPPORTS_ENCRYPTION

%FILE_MAP_COPY       = %SECTION_QUERY
%FILE_MAP_WRITE      = %SECTION_MAP_WRITE
%FILE_MAP_READ       = %SECTION_MAP_READ
%FILE_MAP_ALL_ACCESS = %SECTION_ALL_ACCESS
%FILE_MAP_EXECUTE    = %SECTION_MAP_EXECUTE_EXPLICIT   ' // not included in FILE_MAP_ALL_ACCESS

%OF_READ             = &H00000000???
%OF_WRITE            = &H00000001???
%OF_READWRITE        = &H00000002???
%OF_SHARE_COMPAT     = &H00000000???
%OF_SHARE_EXCLUSIVE  = &H00000010???
%OF_SHARE_DENY_WRITE = &H00000020???
%OF_SHARE_DENY_READ  = &H00000030???
%OF_SHARE_DENY_NONE  = &H00000040???
%OF_PARSE            = &H00000100???
%OF_DELETE           = &H00000200???
%OF_VERIFY           = &H00000400???
%OF_CANCEL           = &H00000800???
%OF_CREATE           = &H00001000???
%OF_PROMPT           = &H00002000???
%OF_EXIST            = &H00004000???
%OF_REOPEN           = &H00008000???

%OFS_MAXPATHNAME = 128

' // Size = 136 bytes
TYPE OFSTRUCT BYTE
   cBytes     AS BYTE                        ' BYTE cBytes
   fFixedDisk AS BYTE                        ' BYTE fFixedDisk
   nErrCode   AS WORD                        ' WORD nErrCode
   Reserved1  AS WORD                        ' WORD Reserved1
   Reserved2  AS WORD                        ' WORD Reserved2
   szPathName AS ASCIIZ * %OFS_MAXPATHNAME   ' CHAR szPathName[OFS_MAXPATHNAME]
END TYPE

#IF NOT %DEF(%NOWINBASEINTERLOCK) ' -------------------------------------------

#IF NOT %DEF(%NTOS) ' ---------------------------------------------------------

DECLARE FUNCTION InterlockedIncrement IMPORT "KERNEL32.DLL" ALIAS "InterlockedIncrement" ( _
   BYREF Addend AS LONG _                               ' __inout LONG volatile *Addend
 ) AS LONG                                              ' LONG

DECLARE FUNCTION InterlockedDecrement IMPORT "KERNEL32.DLL" ALIAS "InterlockedDecrement" ( _
   BYREF Addend AS LONG _                               ' __inout LONG volatile *Addend
 ) AS LONG                                              ' LONG

DECLARE FUNCTION InterlockedExchange IMPORT "KERNEL32.DLL" ALIAS "InterlockedExchange" ( _
   BYREF Target AS LONG _                               ' __inout LONG volatile *Target
 , BYVAL Value AS LONG _                                ' __in    LONG Value
 ) AS LONG                                              ' LONG

'#define InterlockedExchangePointer(Target, Value) \
'    (PVOID)InterlockedExchange((PLONG)(Target), (LONG)(Value))

DECLARE FUNCTION InterlockedExchangePointer IMPORT "KERNEL32.DLL" ALIAS "InterlockedExchange" ( _
   BYREF Target AS LONG _                               ' __inout LONG volatile *Target
 , BYVAL Value AS LONG _                                ' __in    LONG Value
 ) AS LONG                                              ' LONG

DECLARE FUNCTION InterlockedExchangeAdd IMPORT "KERNEL32.DLL" ALIAS "InterlockedExchangeAdd" ( _
   BYREF Addend AS LONG _                               ' __inout LONG volatile *Addend
 , BYVAL Value AS LONG _                                ' __in    LONG Value
 ) AS LONG                                              ' LONG

DECLARE FUNCTION InterlockedCompareExchange IMPORT "KERNEL32.DLL" ALIAS "InterlockedCompareExchange" ( _
   BYREF Destination AS LONG _                          ' __inout LONG volatile *Destination
 , BYVAL ExChange AS LONG _                             ' __in    LONG ExChange
 , BYVAL Comperand AS LONG _                            ' __in    LONG Comperand
 ) AS LONG                                              ' LONG

'#if (_WIN32_WINNT >= 0x0502)

DECLARE FUNCTION InterlockedCompareExchange64 IMPORT "KERNEL32.DLL" ALIAS "InterlockedCompareExchange64" ( _
   BYREF Destination AS QUAD _                          ' __inout LONGLONG volatile *Destination
 , BYVAL ExChange AS QUAD _                             ' __in    LONGLONG ExChange
 , BYVAL Comperand AS QUAD _                            ' __in    LONGLONG Comperand
 ) AS QUAD                                              ' LONGLONG

'#endif

'#if (_WIN32_WINNT >= 0x0502)
#IF %WINVER >= &H0502

'FORCEINLINE
'LONGLONG
'InterlockedAnd64 (
'    __inout LONGLONG volatile *Destination,
'    __in    LONGLONG Value
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Destination;
'    } while (InterlockedCompareExchange64(Destination,
'                                          Old & Value,
'                                          Old) != Old);

'    return Old;
'}

FUNCTION InterlockedAnd64 (BYREF Destination AS QUAD, BYVAL Value AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Destination
   LOOP WHILE InterlockedCompareExchange64(Destination, Old AND Value, Old) <> Old
   FUNCTION = Old
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedOr64 (
'    __inout LONGLONG volatile *Destination,
'    __in    LONGLONG Value
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Destination;
'    } while (InterlockedCompareExchange64(Destination,
'                                          Old | Value,
'                                          Old) != Old);

'    return Old;
'}

FUNCTION InterlockedOr64 (BYREF Destination AS QUAD, BYVAL Value AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Destination
   LOOP WHILE InterlockedCompareExchange64(Destination, Old OR Value, Old) <> Old
   FUNCTION = Old
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedXor64 (
'    __inout LONGLONG volatile *Destination,
'    __in    LONGLONG Value
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Destination;
'    } while (InterlockedCompareExchange64(Destination,
'                                          Old ^ Value,
'                                          Old) != Old);

'    return Old;
'}

FUNCTION InterlockedXor64 (BYREF Destination AS QUAD, BYVAL Value AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Destination
   LOOP WHILE InterlockedCompareExchange64(Destination, Old XOR Value, Old) <> Old
   FUNCTION = Old
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedIncrement64 (
'    __inout LONGLONG volatile *Addend
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Addend;
'    } while (InterlockedCompareExchange64(Addend,
'                                          Old + 1,
'                                          Old) != Old);

'    return Old + 1;
'}

FUNCTION InterlockedIncrement64 (BYREF Addend AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Addend
   LOOP WHILE InterlockedCompareExchange64(Addend, Old + 1, Old) <> Old
   FUNCTION = Old + 1
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedDecrement64 (
'    __inout LONGLONG volatile *Addend
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Addend;
'    } while (InterlockedCompareExchange64(Addend,
'                                          Old - 1,
'                                          Old) != Old);

'    return Old - 1;
'}

FUNCTION InterlockedDecrement64 (BYREF Addend AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Addend
   LOOP WHILE InterlockedCompareExchange64(Addend, Old - 1, Old) <> Old
   FUNCTION = Old - 1
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedExchange64 (
'    __inout LONGLONG volatile *Target,
'    __in    LONGLONG Value
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Target;
'    } while (InterlockedCompareExchange64(Target,
'                                          Value,
'                                          Old) != Old);

'    return Old;
'}

FUNCTION InterlockedExchange64 (BYREF Target AS QUAD, BYVAL Value AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Target
   LOOP WHILE InterlockedCompareExchange64(Target, Value, Old) <> Old
   FUNCTION = Old
END FUNCTION

'FORCEINLINE
'LONGLONG
'InterlockedExchangeAdd64(
'    __inout LONGLONG volatile *Addend,
'    __in    LONGLONG Value
'    )
'{
'    LONGLONG Old;

'    do {
'        Old = *Addend;
'    } while (InterlockedCompareExchange64(Addend,
'                                          Old + Value,
'                                          Old) != Old);

'    return Old;
'}

FUNCTION InterlockedExchangeAdd64 (BYREF Addend AS QUAD, BYVAL Value AS QUAD) AS QUAD
   LOCAL Old AS QUAD
   DO
      Old = Addend
   LOOP WHILE InterlockedCompareExchange64(Addend, Old + Value, Old) <> Old
   FUNCTION = Old
END FUNCTION

'#endif
#ENDIF   ' #IF %WINVER >= &H0502

DECLARE SUB InitializeSListHead IMPORT "KERNEL32.DLL" ALIAS "InitializeSListHead" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __inout PSLIST_HEADER ListHead
 )                                                      ' void

DECLARE FUNCTION InterlockedPopEntrySList IMPORT "KERNEL32.DLL" ALIAS "InterlockedPopEntrySList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __inout PSLIST_HEADER ListHead
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION InterlockedPushEntrySList IMPORT "KERNEL32.DLL" ALIAS "InterlockedPushEntrySList" ( _
   BYREF ListHead AS SLIST_HEADER, _                    ' __inout PSLIST_HEADER ListHead
   BYREF ListEntry AS SLIST_ENTRY _                     ' __inout PSLIST_ENTRY ListEntry
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION InterlockedFlushSList IMPORT "KERNEL32.DLL" ALIAS "InterlockedFlushSList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __inout PSLIST_HEADER ListHead
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION QueryDepthSList IMPORT "KERNEL32.DLL" ALIAS "QueryDepthSList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __inout PSLIST_HEADER ListHead
 ) AS WORD                                              ' USHORT

#ENDIF   ' #IF NOT %DEF(%NTOS) ------------------------------------------------

#ENDIF   ' #IF NOT %DEF(%NOWINBASEINTERLOCK) ----------------------------------

DECLARE FUNCTION FreeResource IMPORT "KERNEL32.DLL" ALIAS "FreeResource" ( _
   BYVAL hResData AS DWORD _                            ' __in HGLOBAL hResData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LockResource IMPORT "KERNEL32.DLL" ALIAS "LockResource" ( _
   BYVAL hResData AS DWORD _                            ' __in HGLOBAL hResData
 ) AS DWORD                                             ' LPVOID

'#define UnlockResource(hResData) ((hResData), 0)
'#define MAXINTATOM 0xC000
'#define MAKEINTATOM(i)  (LPTSTR)((ULONG_PTR)((WORD)(i)))
'#define INVALID_ATOM ((ATOM)0)

%MAXINTATOM   = &HC000??
%INVALID_ATOM = 0??

DECLARE FUNCTION FreeLibrary IMPORT "KERNEL32.DLL" ALIAS "FreeLibrary" ( _
   BYVAL hLibModule AS DWORD _                          ' __in HMODULE hLibModule
 ) AS LONG                                              ' BOOL

DECLARE SUB FreeLibraryAndExitThread IMPORT "KERNEL32.DLL" ALIAS "FreeLibraryAndExitThread" ( _
   BYVAL hLibModule AS DWORD _                          ' __in HMODULE hLibModule
 , BYVAL dwExitCode AS DWORD _                          ' __in DWORD   dwExitCode
 )                                                      ' void

DECLARE FUNCTION DisableThreadLibraryCalls IMPORT "KERNEL32.DLL" ALIAS "DisableThreadLibraryCalls" ( _
   BYVAL hLibModule AS DWORD _                          ' __in HMODULE hLibModule
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcAddress IMPORT "KERNEL32.DLL" ALIAS "GetProcAddress" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpProcName AS ASCIIZ _                         ' __in LPCSTR  lpProcName
 ) AS LONG                                              ' FARPROC

DECLARE FUNCTION GetVersion IMPORT "KERNEL32.DLL" ALIAS "GetVersion" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GlobalAlloc IMPORT "KERNEL32.DLL" ALIAS "GlobalAlloc" ( _
   BYVAL uFlags AS DWORD _                              ' __in UINT   uFlags
 , BYVAL dwBytes AS DWORD _                             ' __in SIZE_T dwBytes
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION GlobalReAlloc IMPORT "KERNEL32.DLL" ALIAS "GlobalReAlloc" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 , BYVAL dwBytes AS DWORD _                             ' __in SIZE_T  dwBytes
 , BYVAL uFlags AS DWORD _                              ' __in UINT    uFlags
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION GlobalSize IMPORT "KERNEL32.DLL" ALIAS "GlobalSize" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION GlobalFlags IMPORT "KERNEL32.DLL" ALIAS "GlobalFlags" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GlobalLock IMPORT "KERNEL32.DLL" ALIAS "GlobalLock" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION GlobalHandle IMPORT "KERNEL32.DLL" ALIAS "GlobalHandle" ( _
   BYVAL pMem AS DWORD _                                ' __in LPCVOID pMem
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION GlobalUnlock IMPORT "KERNEL32.DLL" ALIAS "GlobalUnlock" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GlobalFree IMPORT "KERNEL32.DLL" ALIAS "GlobalFree" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION GlobalCompact IMPORT "KERNEL32.DLL" ALIAS "GlobalCompact" ( _
   BYVAL dwMinFree AS DWORD _                           ' __in DWORD dwMinFree
 ) AS DWORD                                             ' SIZE_T

DECLARE SUB GlobalFix IMPORT "KERNEL32.DLL" ALIAS "GlobalFix" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 )                                                      ' void

DECLARE SUB GlobalUnfix IMPORT "KERNEL32.DLL" ALIAS "GlobalUnfix" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 )                                                      ' void

DECLARE FUNCTION GlobalWire IMPORT "KERNEL32.DLL" ALIAS "GlobalWire" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
   ) AS DWORD                                           ' LPVOID

DECLARE FUNCTION GlobalUnWire IMPORT "KERNEL32.DLL" ALIAS "GlobalUnWire" ( _
   BYVAL hMem AS DWORD _                                ' __in HGLOBAL hMem
 ) AS LONG                                              ' BOOL

DECLARE SUB GlobalMemoryStatus IMPORT "KERNEL32.DLL" ALIAS "GlobalMemoryStatus" ( _
   BYREF lpBuffer AS MEMORYSTATUS _                     ' __out LPMEMORYSTATUS lpBuffer
 )                                                      ' void

' // Size = 64 bytes
TYPE MEMORYSTATUSEX QWORD FILL   ' Must be 8 byte aligned
   dwLength                AS DWORD   ' DWORD     dwLength
   dwMemoryLoad            AS DWORD   ' DWORD     dwMemoryLoad
   ullTotalPhys            AS QUAD    ' DWORDLONG ullTotalPhys
   ullAvailPhys            AS QUAD    ' DWORDLONG ullAvailPhys
   ullTotalPageFile        AS QUAD    ' DWORDLONG ullTotalPageFile
   ullAvailPageFile        AS QUAD    ' DWORDLONG ullAvailPageFile
   ullTotalVirtual         AS QUAD    ' DWORDLONG ullTotalVirtual
   ullAvailVirtual         AS QUAD    ' DWORDLONG ullAvailVirtual
   ullAvailExtendedVirtual AS QUAD    ' DWORDLONG ullAvailExtendedVirtual
END TYPE

DECLARE FUNCTION GlobalMemoryStatusEx IMPORT "KERNEL32.DLL" ALIAS "GlobalMemoryStatusEx" ( _
   BYREF lpBuffer AS MEMORYSTATUSEX _                   ' __out LPMEMORYSTATUSEX lpBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LocalAlloc IMPORT "KERNEL32.DLL" ALIAS "LocalAlloc" ( _
   BYVAL uFlags AS DWORD _                              ' __in UINT   uFlags
 , BYVAL uBytes AS DWORD _                              ' __in SIZE_T uBytes
 ) AS DWORD                                             ' HLOCAL

DECLARE FUNCTION LocalReAlloc IMPORT "KERNEL32.DLL" ALIAS "LocalReAlloc" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 , BYVAL uBytes AS DWORD _                              ' __in SIZE_T uBytes
 , BYVAL uFlags AS DWORD _                              ' __in UINT   uFlags
 ) AS DWORD                                             ' HLOCAL

DECLARE FUNCTION LocalLock IMPORT "KERNEL32.DLL" ALIAS "LocalLock" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION LocalHandle IMPORT "KERNEL32.DLL" ALIAS "LocalHandle" ( _
   BYVAL pMem AS DWORD _                                ' __in LPCVOID pMem
 ) AS DWORD                                             ' HLOCAL

DECLARE FUNCTION LocalUnlock IMPORT "KERNEL32.DLL" ALIAS "LocalUnlock" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LocalSize IMPORT "KERNEL32.DLL" ALIAS "LocalSize" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION LocalFlags IMPORT "KERNEL32.DLL" ALIAS "LocalFlags" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION LocalFree IMPORT "KERNEL32.DLL" ALIAS "LocalFree" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' HLOCAL

DECLARE FUNCTION LocalShrink IMPORT "KERNEL32.DLL" ALIAS "LocalShrink" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 , BYVAL cbNewSize AS DWORD _                           ' __in UINT   cbNewSize
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION LocalCompact IMPORT "KERNEL32.DLL" ALIAS "LocalCompact" ( _
   BYVAL uMinFree AS DWORD _                            ' __in UINT uMinFree
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION FlushInstructionCache IMPORT "KERNEL32.DLL" ALIAS "FlushInstructionCache" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE  hProcess
 , BYVAL lpBaseAddress AS DWORD _                       ' __in LPCVOID lpBaseAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T  dwSize
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE SUB FlushProcessWriteBuffers IMPORT "KERNEL32.DLL" ALIAS "FlushProcessWriteBuffers" ( _
 )                                                      ' void

DECLARE FUNCTION QueryThreadCycleTime IMPORT "KERNEL32.DLL" ALIAS "QueryThreadCycleTime" ( _
   BYVAL ThreadHandle AS DWORD _                        ' __in  HANDLE   ThreadHandle
 , BYREF CycleTime AS QUAD _                            ' __out PULONG64 CycleTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryProcessCycleTime IMPORT "KERNEL32.DLL" ALIAS "QueryProcessCycleTime" ( _
   BYVAL ProcessHandle AS DWORD _                       ' __in  HANDLE   ProcessHandle
 , BYREF CycleTime AS QUAD _                            ' __out PULONG64 CycleTime
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryIdleProcessorCycleTime LIB "Kernel32.dll" _
    ALIAS "QueryIdleProcessorCycleTime" (BufferLength AS DWORD, _
    BYVAL ProcessorIdleCycleTime AS QUAD PTR) AS LONG
#ELSE
DECLARE FUNCTION QueryIdleProcessorCycleTime IMPORT "KERNEL32.DLL" ALIAS "QueryIdleProcessorCycleTime" ( _
   BYREF BufferLength AS DWORD _                        ' __inout PULONG   BufferLength
 , BYREF ProcessorIdleCycleTime AS QUAD _               ' __out   PULONG64 ProcessorIdleCycleTime
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF   ' #if (_WIN32_WINNT >= 0x0600)

'#if (_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryIdleProcessorCycleTimeEx LIB "Kernel32.dll" _
    ALIAS "QueryIdleProcessorCycleTimeEx" (BYVAL Group AS WORD, _
    BufferLength AS DWORD, _
    BYVAL ProcessorIdleCycleTime AS QUAD PTR) AS LONG
#ELSE
DECLARE FUNCTION QueryIdleProcessorCycleTimeEx IMPORT "KERNEL32.DLL" ALIAS "QueryIdleProcessorCycleTimeEx" ( _
   BYVAL Group AS WORD _                                ' __in    USHORT Group
 , BYREF BufferLength AS DWORD _                        ' __inout PULONG   BufferLength
 , BYREF ProcessorIdleCycleTime AS QUAD _               ' __out   PULONG64 ProcessorIdleCycleTime
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION QueryUnbiasedInterruptTime IMPORT "KERNEL32.DLL" ALIAS "QueryUnbiasedInterruptTime" ( _
   BYREF UnbiasedTime AS QUAD _                         ' __out PULONG64 UnbiasedTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessorSystemCycleTime IMPORT "KERNEL32.DLL" ALIAS "GetProcessorSystemCycleTime" ( _
   BYVAL Group AS WORD _                                ' __in    USHORT Group
 , BYREF Buffer AS ANY _                                ' __out_bcount_part_opt(*ReturnedLength, *ReturnedLength) PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer
 , BYREF ReturnedLength AS DWORD _                      ' __inout PDWORD ReturnedLength
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >= 0x0601)

DECLARE FUNCTION VirtualAlloc IMPORT "KERNEL32.DLL" ALIAS "VirtualAlloc" ( _
   BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 , BYVAL flAllocationType AS DWORD _                    ' __in DWORD  flAllocationType
 , BYVAL flProtect AS DWORD _                           ' __in DWORD  flProtect
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION VirtualFree IMPORT "KERNEL32.DLL" ALIAS "VirtualFree" ( _
   BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 , BYVAL dwFreeType AS DWORD _                          ' __in DWORD  dwFreeType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualProtect IMPORT "KERNEL32.DLL" ALIAS "VirtualProtect" ( _
   BYVAL lpAddress AS DWORD _                           ' __in  LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in  SIZE_T dwSize
 , BYVAL flNewProtect AS DWORD _                        ' __in  DWORD  flNewProtect
 , BYREF lpflOldProtect AS DWORD _                      ' __out PDWORD lpflOldProtect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualQuery IMPORT "KERNEL32.DLL" ALIAS "VirtualQuery" ( _
   BYVAL lpAddress AS DWORD _                           ' __in  LPCVOID lpAddress
 , BYREF lpBuffer AS MEMORY_BASIC_INFORMATION _         ' __out PMEMORY_BASIC_INFORMATION lpBuffer
 , BYVAL dwLength AS DWORD _                            ' __in  SIZE_T dwLength
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION VirtualAllocEx IMPORT "KERNEL32.DLL" ALIAS "VirtualAllocEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 , BYVAL flAllocationType AS DWORD _                    ' __in DWORD  flAllocationType
 , BYVAL flProtect AS DWORD _                           ' __in DWORD  flProtect
 ) AS DWORD                                             ' LPVOID

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION VirtualAllocExNuma IMPORT "KERNEL32.DLL" ALIAS "VirtualAllocExNuma" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 , BYVAL flAllocationType AS DWORD _                    ' __in DWORD  flAllocationType
 , BYVAL flProtect AS DWORD _                           ' __in DWORD  flProtect
 , BYVAL nndPreferred AS DWORD _                        ' __in DWORD  nndPreferred
 ) AS DWORD                                             ' LPVOID

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION GetWriteWatch IMPORT "KERNEL32.DLL" ALIAS "GetWriteWatch" ( _
   BYVAL dwFlags AS DWORD _                             ' __in    DWORD      dwFlags
 , BYVAL lpBaseAddress AS DWORD _                       ' __in    PVOID      lpBaseAddress
 , BYVAL dwRegionSize AS DWORD _                        ' __in    SIZE_T     dwRegionSize
 , BYREF lpAddresses AS ANY _                           ' __out   PVOID     *lpAddresses
 , BYREF lpdwCount AS DWORD _                           ' __inout ULONG_PTR *lpdwCount
 , BYREF lpdwGranularity AS DWORD _                     ' __out   PULONG     lpdwGranularity
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ResetWriteWatch IMPORT "KERNEL32.DLL" ALIAS "ResetWriteWatch" ( _
   BYVAL lpBaseAddress AS DWORD _                       ' __in LPVOID lpBaseAddress
 , BYVAL dwRegionSize AS DWORD _                        ' __in SIZE_T dwRegionSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetLargePageMinimum IMPORT "KERNEL32.DLL" ALIAS "GetLargePageMinimum" ( _
 ) AS DWORD                                             ' SIZE_T

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumSystemFirmwareTables LIB "Kernel32.dll" _
    ALIAS "EnumSystemFirmwareTables" _
    (BYVAL FirmwareTableProviderSignature AS DWORD, _
    BYVAL pFirmwareTableEnumBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION EnumSystemFirmwareTables IMPORT "KERNEL32.DLL" ALIAS "EnumSystemFirmwareTables" ( _
   BYVAL FirmwareTableProviderSignature AS DWORD _      ' __in  DWORD FirmwareTableProviderSignature
 , BYREF pFirmwareTableEnumBuffer AS ANY _              ' __out PVOID pFirmwareTableEnumBuffer
 , BYVAL BufferSize AS DWORD _                          ' __in  DWORD BufferSize
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSystemFirmwareTable LIB "Kernel32.dll" _
    ALIAS "GetSystemFirmwareTable" _
    (BYVAL FirmwareTableProviderSignature AS DWORD, _
    BYVAL FirmwareTableID AS DWORD, BYVAL pFirmwareTableBuffer AS DWORD, _
    BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetSystemFirmwareTable IMPORT "KERNEL32.DLL" ALIAS "GetSystemFirmwareTable" ( _
   BYVAL FirmwareTableProviderSignature AS DWORD _      ' __in  DWORD FirmwareTableProviderSignature
 , BYVAL FirmwareTableID AS DWORD _                     ' __in  DWORD FirmwareTableID
 , BYREF pFirmwareTableBuffer AS ANY _                  ' __out PVOID pFirmwareTableBuffer
 , BYVAL BufferSize AS DWORD _                          ' __in  DWORD BufferSize
 ) AS DWORD                                             ' UINT
#ENDIF

DECLARE FUNCTION GetPhysicallyInstalledSystemMemory IMPORT "KERNEL32.DLL" ALIAS "GetPhysicallyInstalledSystemMemory" ( _
   BYREF TotalMemoryInKilobytes AS QUAD _               ' __out PULONGLONG TotalMemoryInKilobytes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualFreeEx IMPORT "KERNEL32.DLL" ALIAS "VirtualFreeEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 , BYVAL dwFreeType AS DWORD _                          ' __in DWORD  dwFreeType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualProtectEx IMPORT "KERNEL32.DLL" ALIAS "VirtualProtectEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL lpAddress AS DWORD _                           ' __in  LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in  SIZE_T dwSize
 , BYVAL flNewProtect AS DWORD _                        ' __in  DWORD  flNewProtect
 , BYREF lpflOldProtect AS DWORD _                      ' __out PDWORD lpflOldProtect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualQueryEx IMPORT "KERNEL32.DLL" ALIAS "VirtualQueryEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYVAL lpAddress AS DWORD _                           ' __in  LPCVOID lpAddress
 , BYREF lpBuffer AS MEMORY_BASIC_INFORMATION _         ' __out PMEMORY_BASIC_INFORMATION lpBuffer
 , BYVAL dwLength AS DWORD _                            ' __in  SIZE_T  dwLength
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION HeapCreate IMPORT "KERNEL32.DLL" ALIAS "HeapCreate" ( _
   BYVAL flOptions AS DWORD _                           ' __in DWORD  flOptions
 , BYVAL dwInitialSize AS DWORD _                       ' __in SIZE_T dwInitialSize
 , BYVAL dwMaximumSize AS DWORD _                       ' __in SIZE_T dwMaximumSize
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION HeapDestroy IMPORT "KERNEL32.DLL" ALIAS "HeapDestroy" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE hHeap
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapAlloc IMPORT "KERNEL32.DLL" ALIAS "HeapAlloc" ( _
   BYVAL hHeap AS  DWORD _                              ' __in HANDLE hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL dwBytes AS DWORD _                             ' __in SIZE_T dwBytes
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION HeapReAlloc IMPORT "KERNEL32.DLL" ALIAS "HeapReAlloc" ( _
   BYVAL hHeap AS DWORD _                               ' __inout HANDLE hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD  dwFlags
 , BYVAL lpMem AS DWORD _                               ' __in    LPVOID lpMem
 , BYVAL dwBytes AS DWORD _                             ' __in    SIZE_T dwBytes
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION HeapFree IMPORT "KERNEL32.DLL" ALIAS "HeapFree" ( _
   BYVAL hHeap AS DWORD _                               ' __inout     HANDLE hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL lpMem AS DWORD _                               ' __in LPVOID lpMem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapSize IMPORT "KERNEL32.DLL" ALIAS "HeapSize" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE  hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYVAL lpMem AS DWORD _                               ' __in LPCVOID lpMem
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION HeapValidate IMPORT "KERNEL32.DLL" ALIAS "HeapValidate" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE  hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYVAL lpMem AS DWORD _                               ' __in LPCVOID lpMem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapCompact IMPORT "KERNEL32.DLL" ALIAS "HeapCompact" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION GetProcessHeap IMPORT "KERNEL32.DLL" ALIAS "GetProcessHeap" ( _
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetProcessHeaps LIB "Kernel32.dll" ALIAS "GetProcessHeaps" _
    (BYVAL NumberOfHeaps AS DWORD, BYVAL ProcessHeaps AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetProcessHeaps IMPORT "KERNEL32.DLL" ALIAS "GetProcessHeaps" ( _
   BYVAL NumberOfHeaps AS DWORD _                       ' __in  DWORD   NumberOfHeaps
 , BYREF ProcessHeaps AS DWORD _                        ' __out PHANDLE ProcessHeaps
 ) AS DWORD                                             ' DWORD
#ENDIF

' // Size = 16 bytes
TYPE PROCESS_HEAP_ENTRY_Block DWORD
   hMem          AS DWORD
   dwReserved(2) AS DWORD
END TYPE

' // Size = 16 bytes
TYPE PROCESS_HEAP_ENTRY_Region DWORD
   dwCommittedSize   AS DWORD
   dwUnCommittedSize AS DWORD
   lpFirstBlock      AS DWORD
   lpLastBlock       AS DWORD
END TYPE

' // Size = 16 bytes
UNION PROCESS_HEAP_ENTRY_UNION DWORD
   PROCESS_HEAP_ENTRY_Block
   PROCESS_HEAP_ENTRY_Region
END UNION

' // Size = 28 bytes
TYPE PROCESS_HEAP_ENTRY DWORD FILL
   lpData       AS DWORD
   cbData       AS DWORD
   cbOverhead   AS BYTE
   iRegionIndex AS BYTE
   wFlags       AS WORD
   PROCESS_HEAP_ENTRY_UNION
END TYPE

%PROCESS_HEAP_REGION            = &H0001??
%PROCESS_HEAP_UNCOMMITTED_RANGE = &H0002??
%PROCESS_HEAP_ENTRY_BUSY        = &H0004??
%PROCESS_HEAP_ENTRY_MOVEABLE    = &H0010??
%PROCESS_HEAP_ENTRY_DDESHARE    = &H0020??

DECLARE FUNCTION HeapLock IMPORT "KERNEL32.DLL" ALIAS "HeapLock" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE hHeap
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapUnlock IMPORT "KERNEL32.DLL" ALIAS "HeapUnlock" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE hHeap
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapWalk IMPORT "KERNEL32.DLL" ALIAS "HeapWalk" ( _
   BYVAL hHeap AS DWORD _                               ' __in HANDLE hHeap
 , BYREF lpEntry AS PROCESS_HEAP_ENTRY _                ' __inout LPPROCESS_HEAP_ENTRY lpEntry
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapSetInformation IMPORT "KERNEL32.DLL" ALIAS "HeapSetInformation" ( _
   BYVAL HeapHandle AS DWORD _                          ' __in HANDLE HeapHandle
 , BYVAL HeapInformationClass AS LONG _                 ' __in HEAP_INFORMATION_CLASS HeapInformationClass
 , BYREF HeapInformation AS ANY _                       ' __in PVOID HeapInformation
 , BYVAL HeapInformationLength AS DWORD _               ' __in SIZE_T HeapInformationLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HeapQueryInformation IMPORT "KERNEL32.DLL" ALIAS "HeapQueryInformation" ( _
   BYVAL HeapHandle AS DWORD _                          ' __in HANDLE HeapHandle
 , BYVAL HeapInformationClass AS LONG _                 ' __in HEAP_INFORMATION_CLASS HeapInformationClass
 , BYREF HeapInformation AS ANY _                       ' __out PVOID HeapInformation
 , BYVAL HeapInformationLength AS DWORD _               ' __in SIZE_T HeapInformationLength
 , BYREF ReturnLength AS DWORD _                        ' __out PSIZE_T ReturnLength
 ) AS LONG                                              ' BOOL

'// GetBinaryType return values.

%SCS_32BIT_BINARY = 0
%SCS_DOS_BINARY   = 1
%SCS_WOW_BINARY   = 2
%SCS_PIF_BINARY   = 3
%SCS_POSIX_BINARY = 4
%SCS_OS216_BINARY = 5
%SCS_64BIT_BINARY = 6


'#if defined(_WIN64)
'# define SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
'#else
'# define SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
'#endif

DECLARE FUNCTION GetBinaryTypeA IMPORT "KERNEL32.DLL" ALIAS "GetBinaryTypeA" ( _
   BYREF lpApplicationName AS ASCIIZ _                  ' __in  LPCSTR  lpApplicationName
 , BYREF lpBinaryType AS DWORD _                        ' __out LPDWORD lpBinaryType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetBinaryTypeW IMPORT "KERNEL32.DLL" ALIAS "GetBinaryTypeW" ( _
   BYREF lpApplicationName AS WSTRINGZ _                ' __in  LPCWSTR lpApplicationName
 , BYREF lpBinaryType AS DWORD _                        ' __out LPDWORD lpBinaryType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetBinaryType = GetBinaryTypeW
#ELSE
   MACRO GetBinaryType = GetBinaryTypeA
#ENDIF

DECLARE FUNCTION GetShortPathNameA IMPORT "KERNEL32.DLL" ALIAS "GetShortPathNameA" ( _
   BYREF lpszLongPath AS ASCIIZ _                       ' __in  LPCSTR lpszLongPath
 , BYREF lpszShortPath AS ASCIIZ _                      ' __out LPSTR  lpszShortPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD  cchBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetShortPathNameW IMPORT "KERNEL32.DLL" ALIAS "GetShortPathNameW" ( _
   BYREF lpszLongPath AS WSTRINGZ _                     ' __in  LPCWSTR lpszLongPath
 , BYREF lpszShortPath AS WSTRINGZ _                    ' __out LPWSTR  lpszShortPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetShortPathName = GetShortPathNameW
#ELSE
   MACRO GetShortPathName = GetShortPathNameA
#ENDIF

DECLARE FUNCTION GetLongPathNameA IMPORT "KERNEL32.DLL" ALIAS "GetLongPathNameA" ( _
   BYREF lpszShortPath AS ASCIIZ _                      ' __in  LPCSTR lpszShortPath
 , BYREF lpszLongPath AS ASCIIZ _                       ' __out LPSTR  lpszLongPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD  cchBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLongPathNameW IMPORT "KERNEL32.DLL" ALIAS "GetLongPathNameW" ( _
   BYREF lpszShortPath AS WSTRINGZ _                    ' __in  LPCWSTR lpszShortPath
 , BYREF lpszLongPath AS WSTRINGZ _                     ' __out LPWSTR  lpszLongPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetLongPathName = GetLongPathNameW
#ELSE
   MACRO GetLongPathName = GetLongPathNameA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION GetLongPathNameTransactedA IMPORT "KERNEL32.DLL" ALIAS "GetLongPathNameTransactedA" ( _
   BYREF lpszShortPath AS ASCIIZ _                      ' __in  LPCSTR lpszShortPath
 , BYREF lpszLongPath AS ASCIIZ _                       ' __out LPSTR  lpszLongPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD  cchBuffer
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLongPathNameTransactedW IMPORT "KERNEL32.DLL" ALIAS "GetLongPathNameTransactedW" ( _
   BYREF lpszShortPath AS WSTRINGZ _                    ' __in  LPCWSTR lpszShortPath
 , BYREF lpszLongPath AS WSTRINGZ _                     ' __out LPWSTR  lpszLongPath
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE  hTransaction
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetLongPathNameTransacted = GetLongPathNameTransactedW
#ELSE
   MACRO GetLongPathNameTransacted = GetLongPathNameTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION GetProcessAffinityMask IMPORT "KERNEL32.DLL" ALIAS "GetProcessAffinityMask" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE     hProcess
 , BYREF lpProcessAffinityMask AS DWORD _               ' __out PDWORD_PTR lpProcessAffinityMask
 , BYREF lpSystemAffinityMask AS DWORD _                ' __out PDWORD_PTR lpSystemAffinityMask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessAffinityMask IMPORT "KERNEL32.DLL" ALIAS "SetProcessAffinityMask" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE    hProcess
 , BYVAL dwProcessAffinityMask AS DWORD _               ' __in DWORD_PTR dwProcessAffinityMask
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetProcessGroupAffinity LIB "Kernel32.dll" _
    ALIAS "GetProcessGroupAffinity" (BYVAL hProcess AS DWORD, _
    GroupCount AS WORD, BYVAL GroupArray AS WORD PTR) AS LONG
#ELSE
DECLARE FUNCTION GetProcessGroupAffinity IMPORT "KERNEL32.DLL" ALIAS "GetProcessGroupAffinity" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE    hProcess
 , BYREF GroupCount AS WORD _                           ' __inout PUSHORT GroupCount
 , BYREF GroupArray AS WORD _                           ' __out_ecount(*GroupCount) PUSHORT GroupArray
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF   ' // _WIN32_WINNT >= 0x0601

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION GetProcessHandleCount IMPORT "KERNEL32.DLL" ALIAS "GetProcessHandleCount" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF pdwHandleCount AS DWORD _                      ' __out PDWORD pdwHandleCount
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION GetProcessTimes IMPORT "KERNEL32.DLL" ALIAS "GetProcessTimes" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE     hProcess
 , BYREF lpCreationTime AS FILETIME _                   ' __out LPFILETIME lpCreationTime
 , BYREF lpExitTime AS FILETIME _                       ' __out LPFILETIME lpExitTime
 , BYREF lpKernelTime AS FILETIME _                     ' __out LPFILETIME lpKernelTime
 , BYREF lpUserTime AS FILETIME _                       ' __out LPFILETIME lpUserTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessIoCounters IMPORT "KERNEL32.DLL" ALIAS "GetProcessIoCounters" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE       hProcess
 , BYREF lpIoCounters AS IO_COUNTERS _                  ' __out PIO_COUNTERS lpIoCounters
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessWorkingSetSize IMPORT "KERNEL32.DLL" ALIAS "GetProcessWorkingSetSize" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYREF lpMinimumWorkingSetSize AS DWORD _             ' __out PSIZE_T lpMinimumWorkingSetSize
 , BYREF lpMaximumWorkingSetSize AS DWORD _             ' __out PSIZE_T lpMaximumWorkingSetSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessWorkingSetSizeEx IMPORT "KERNEL32.DLL" ALIAS "GetProcessWorkingSetSizeEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYREF lpMinimumWorkingSetSize AS DWORD _             ' __out PSIZE_T lpMinimumWorkingSetSize
 , BYREF lpMaximumWorkingSetSize AS DWORD _             ' __out PSIZE_T lpMaximumWorkingSetSize
 , BYREF Flags AS DWORD _                               ' __out PDWORD  Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessWorkingSetSize IMPORT "KERNEL32.DLL" ALIAS "SetProcessWorkingSetSize" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL dwMinimumWorkingSetSize AS DWORD _             ' __in SIZE_T dwMinimumWorkingSetSize
 , BYVAL dwMaximumWorkingSetSize AS DWORD _             ' __in SIZE_T dwMaximumWorkingSetSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessWorkingSetSizeEx IMPORT "KERNEL32.DLL" ALIAS "SGetProcessWorkingSetSizeEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL dwMinimumWorkingSetSize AS DWORD _             ' __in SIZE_T dwMinimumWorkingSetSize
 , BYVAL dwMaximumWorkingSetSize AS DWORD _             ' __in SIZE_T dwMaximumWorkingSetSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD  Flags
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

%PROCESS_AFFINITY_ENABLE_AUTO_UPDATE = &H00000001???

DECLARE FUNCTION SetProcessAffinityUpdateMode IMPORT "KERNEL32.DLL" ALIAS "SetProcessAffinityUpdateMode" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Flags AS DWORD _                               ' __in DWORD  Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryProcessAffinityUpdateMode IMPORT "KERNEL32.DLL" ALIAS "QueryProcessAffinityUpdateMode" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD lpdwFlags
 ) AS LONG                                              ' BOOL

'#endif // _WIN32_WINNT >= 0x0600
#ENDIF

DECLARE FUNCTION OpenProcess IMPORT "KERNEL32.DLL" ALIAS "OpenProcess" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL  bInheritHandle
 , BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetCurrentProcess IMPORT "KERNEL32.DLL" ALIAS "GetCurrentProcess" ( _
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetCurrentProcessId IMPORT "KERNEL32.DLL" ALIAS "GetCurrentProcessId" ( _
 ) AS DWORD                                             ' DWORD

DECLARE SUB ExitProcess IMPORT "KERNEL32.DLL" ALIAS "ExitProcess" ( _
   BYVAL uExitCode AS DWORD _                           ' __in UINT uExitCode
 )                                                      ' void

DECLARE FUNCTION TerminateProcess IMPORT "KERNEL32.DLL" ALIAS "TerminateProcess" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL uExitCode AS DWORD _                           ' __in UINT   uExitCode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetExitCodeProcess IMPORT "KERNEL32.DLL" ALIAS "GetExitCodeProcess" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYREF lpExitCode AS DWORD _                          ' __out LPDWORD lpExitCode
 ) AS LONG                                              ' BOOL

DECLARE SUB FatalExit IMPORT "KERNEL32.DLL" ALIAS "FatalExit" ( _
   BYVAL ExitCode AS LONG _                             ' __in int ExitCode
 )                                                      ' void

DECLARE FUNCTION GetEnvironmentStringsA IMPORT "KERNEL32.DLL" ALIAS "GetEnvironmentStringsA" ( _
 ) AS DWORD                                             ' LPCH

DECLARE FUNCTION GetEnvironmentStringsW IMPORT "KERNEL32.DLL" ALIAS "GetEnvironmentStringsW" ( _
 ) AS DWORD                                             ' LPWCH

#IF %DEF(%UNICODE)
   MACRO GetEnvironmentStrings = GetEnvironmentStringsW
#ELSE
   MACRO GetEnvironmentStrings = GetEnvironmentStringsA
#ENDIF

' Requires Windows Vista
DECLARE FUNCTION SetEnvironmentStringsA IMPORT "KERNEL32.DLL" ALIAS "SetEnvironmentStringsA" ( _
   BYVAL NewEnvironment AS DWORD _                      ' __in __nullnullterminated LPCH NewEnvironment
 ) AS LONG                                              ' BOOL

' Requires Windows Vista
DECLARE FUNCTION SetEnvironmentStringsW IMPORT "KERNEL32.DLL" ALIAS "SetEnvironmentStringsW" ( _
   BYVAL NewEnvironment AS DWORD _                      ' __in __nullnullterminated LPWCH NewEnvironment
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetEnvironmentStrings = SetEnvironmentStringsW
#ELSE
   MACRO SetEnvironmentStrings = SetEnvironmentStringsA
#ENDIF

DECLARE FUNCTION FreeEnvironmentStringsA IMPORT "KERNEL32.DLL" ALIAS "FreeEnvironmentStringsA" ( _
   BYVAL lpszEnvironmentBlock AS DWORD _                ' __in __nullnullterminated LPCH lpszEnvironmentBlock
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreeEnvironmentStringsW IMPORT "KERNEL32.DLL" ALIAS "FreeEnvironmentStringsW" ( _
   BYVAL lpszEnvironmentBlock AS DWORD _                ' __in __nullnullterminated LPWCH lpszEnvironmentBlock
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FreeEnvironmentStrings = FreeEnvironmentStringsW
#ELSE
   MACRO FreeEnvironmentStrings = FreeEnvironmentStringsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB RaiseException LIB "Kernel32.dll" ALIAS "RaiseException" _
    (BYVAL dwExceptionCode AS DWORD, BYVAL dwExceptionFlags AS DWORD, _
    BYVAL nNumberOfArguments AS DWORD, BYVAL lpArguments AS DWORD)
#ELSE
DECLARE SUB RaiseException IMPORT "KERNEL32.DLL" ALIAS "RaiseException" ( _
   BYVAL dwExceptionCode AS DWORD _                     ' __in DWORD dwExceptionCode
 , BYVAL dwExceptionFlags AS DWORD _                    ' __in DWORD dwExceptionFlags
 , BYVAL nNumberOfArguments AS DWORD _                  ' __in DWORD nNumberOfArguments
 , BYREF lpArguments AS DWORD _                         ' __in CONST ULONG_PTR *lpArguments
 )                                                      ' void
#ENDIF

DECLARE SUB RaiseFailFastException IMPORT "KERNEL32.DLL" ALIAS "RaiseFailFastException" ( _
   BYREF pExceptionRecord AS EXCEPTION_RECORD _         ' __in_opt PEXCEPTION_RECORD pExceptionRecord
 , BYREF pContextRecord AS CONTEXT _                    ' __in PCONTEXT pContextRecord
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 )                                                      ' void

'__callback
'WINBASEAPI
'LONG
'WINAPI
'UnhandledExceptionFilter(
'    __in struct _EXCEPTION_POINTERS *ExceptionInfo
'    );

'FUNCTION UnhandledExceptionFilter _
'   BYREF ExceptionInfo AS EXCEPTION_POINTERS _          ' __in struct _EXCEPTION_POINTERS *ExceptionInfo
' ) AS LONG                                              ' LONG

'typedef LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(
'    __in struct _EXCEPTION_POINTERS *ExceptionInfo
'    );
'typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

DECLARE FUNCTION SetUnhandledExceptionFilter IMPORT "KERNEL32.DLL" ALIAS "SetUnhandledExceptionFilter" ( _
   BYVAL lpTopLevelExceptionFilter AS DWORD _           ' __in_opt LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
 ) AS DWORD                                             ' LPTOP_LEVEL_EXCEPTION_FILTER

'#if(_WIN32_WINNT >= 0x0400)

'//
'// Fiber creation flags
'//

%FIBER_FLAG_FLOAT_SWITCH = &H1???    ' // context switch floating point

DECLARE FUNCTION CreateFiber IMPORT "KERNEL32.DLL" ALIAS "CreateFiber" ( _
   BYVAL dwStackSize AS DWORD _                         ' __in SIZE_T dwStackSize
 , BYVAL lpStartAddress AS DWORD _                      ' __in LPFIBER_START_ROUTINE lpStartAddress
 , BYVAL lpParameter AS DWORD _                         ' __in LPVOID lpParameter
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION CreateFiberEx IMPORT "KERNEL32.DLL" ALIAS "CreateFiberEx" ( _
   BYVAL dwStackCommitSize AS DWORD _                   ' __in SIZE_T dwStackCommitSize
 , BYVAL dwStackReserveSize AS DWORD _                  ' __in SIZE_T dwStackReserveSize
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lpStartAddress AS DWORD _                      ' __in LPFIBER_START_ROUTINE lpStartAddress
 , BYVAL lpParameter AS DWORD _                         ' __in LPVOID lpParameter
 ) AS DWORD                                             ' LPVOID

DECLARE SUB DeleteFiber IMPORT "KERNEL32.DLL" ALIAS "DeleteFiber" ( _
   BYVAL lpFiber AS DWORD _                             ' __in LPVOID lpFiber
 )                                                      ' void

DECLARE FUNCTION ConvertThreadToFiber IMPORT "KERNEL32.DLL" ALIAS "ConvertThreadToFiber" ( _
   BYVAL lpParameter AS DWORD _                         ' __in LPVOID lpParameter
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION ConvertThreadToFiberEx IMPORT "KERNEL32.DLL" ALIAS "ConvertThreadToFiberEx" ( _
   BYVAL lpParameter AS DWORD _                         ' __in LPVOID lpParameter
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPVOID

'#if (_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION ConvertFiberToThread IMPORT "KERNEL32.DLL" ALIAS "ConvertFiberToThread" ( _
 ) AS LONG                                              ' BOOL

'#endif

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION IsThreadAFiber IMPORT "KERNEL32.DLL" ALIAS "IsThreadAFiber" ( _
 ) AS LONG                                              ' BOOL

#ENDIF

DECLARE SUB SwitchToFiber IMPORT "KERNEL32.DLL" ALIAS "SwitchToFiber" ( _
   BYVAL lpFiber AS DWORD _                             ' __in LPVOID lpFiber
 )                                                      ' void

DECLARE FUNCTION SwitchToThread IMPORT "KERNEL32.DLL" ALIAS "SwitchToThread" ( _
 ) AS LONG                                              ' BOOL

'//
'// UMS begin
'//

'#if (_WIN32_WINNT >= 0x0601) && !defined(MIDL_PASS)
#IF %WINVER >= &H0601

%UMS_VERSION = %RTL_UMS_VERSION

'typedef void *PUMS_CONTEXT;
'typedef void *PUMS_COMPLETION_LIST;
'typedef enum _RTL_UMS_THREAD_INFO_CLASS UMS_THREAD_INFO_CLASS, *PUMS_THREAD_INFO_CLASS;
'typedef enum _RTL_UMS_SCHEDULER_REASON UMS_SCHEDULER_REASON;
'typedef PRTL_UMS_SCHEDULER_ENTRY_POINT PUMS_SCHEDULER_ENTRY_POINT;

' // Size = 16 bytes
TYPE UMS_SCHEDULER_STARTUP_INFO DWORD
   ' // UMS Version the application was built to. Should be set to UMS_VERSION
   UmsVersion     AS DWORD   ' ULONG
   ' // Completion List to associate the new User Scheduler to.
   CompletionList AS DWORD   ' PUMS_COMPLETION_LIST
   ' // A pointer to the application-defined function that represents the starting
   ' // address of the Sheduler.
   SchedulerProc  AS DWORD   ' PUMS_SCHEDULER_ENTRY_POINT
   ' // pointer to a variable to be passed to the scheduler uppon first activation.
   SchedulerParam AS DWORD   ' PVOID
END TYPE

DECLARE FUNCTION CreateUmsCompletionList IMPORT "KERNEL32.DLL" ALIAS "CreateUmsCompletionList" ( _
   BYREF UmsCompletionList AS ANY _                     ' __out PUMS_COMPLETION_LIST* UmsCompletionList
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DequeueUmsCompletionListItems IMPORT "KERNEL32.DLL" ALIAS "DequeueUmsCompletionListItems" ( _
   BYREF UmsCompletionList AS ANY _                     ' __out PUMS_COMPLETION_LIST* UmsCompletionList
 , BYVAL WaitTimeOut AS DWORD _                         ' __in DWORD WaitTimeOut
 , BYREF UmsThreadList AS ANY _                         ' __out PUMS_CONTEXT* UmsThreadList
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUmsCompletionListEvent IMPORT "KERNEL32.DLL" ALIAS "GetUmsCompletionListEvent" ( _
   BYREF UmsCompletionList AS ANY _                     ' __out PUMS_COMPLETION_LIST* UmsCompletionList
 , BYREF UmsCompletionEvent AS DWORD _                  ' __inout PHANDLE UmsCompletionEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExecuteUmsThread IMPORT "KERNEL32.DLL" ALIAS "ExecuteUmsThread" ( _
   BYREF UmsThread AS ANY _                             ' __inout PUMS_CONTEXT UmsThread
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UmsThreadYield IMPORT "KERNEL32.DLL" ALIAS "UmsThreadYield" ( _
   BYREF SchedulerParam AS ANY _                        ' __in PVOID SchedulerParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteUmsCompletionList IMPORT "KERNEL32.DLL" ALIAS "DeleteUmsCompletionList" ( _
   BYREF UmsCompletionList AS ANY _                     ' __in PUMS_COMPLETION_LIST UmsCompletionList
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCurrentUmsThread IMPORT "KERNEL32.DLL" ALIAS "GetCurrentUmsThread" ( _
 ) AS DWORD                                             ' PUMS_CONTEXT

DECLARE FUNCTION GetNextUmsListItem IMPORT "KERNEL32.DLL" ALIAS "GetNextUmsListItem" ( _
   BYREF UmsContext AS ANY _                            ' __inout PUMS_CONTEXT UmsContext
 ) AS DWORD                                             ' PUMS_CONTEXT

DECLARE FUNCTION QueryUmsThreadInformation IMPORT "KERNEL32.DLL" ALIAS "QueryUmsThreadInformation" ( _
   BYREF UmsThread AS ANY _                             ' __in PUMS_CONTEXT UmsThread
 , BYVAL UmsThreadInfoClass AS LONG _                   ' __in UMS_THREAD_INFO_CLASS UmsThreadInfoClass
 , BYREF UmsThreadInformation AS ANY _                  ' __out_bcount_part(UmsThreadInformationLength, *ReturnLength) PVOID UmsThreadInformation
 , BYVAL UmsThreadInformationLength AS DWORD _          ' __in ULONG UmsThreadInformationLength
 , BYREF ReturnLength AS DWORD _                        ' __out_opt PULONG ReturnLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUmsThreadInformation IMPORT "KERNEL32.DLL" ALIAS "SetUmsThreadInformation" ( _
   BYREF UmsThread AS ANY _                             ' __in PUMS_CONTEXT UmsThread
 , BYVAL UmsThreadInfoClass AS LONG _                   ' __in UMS_THREAD_INFO_CLASS UmsThreadInfoClass
 , BYREF UmsThreadInformation AS ANY _                  ' __out_bcount_part(UmsThreadInformationLength, *ReturnLength) PVOID UmsThreadInformation
 , BYVAL UmsThreadInformationLength AS DWORD _          ' __in ULONG UmsThreadInformationLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteUmsThreadContext IMPORT "KERNEL32.DLL" ALIAS "DeleteUmsThreadContext" ( _
   BYREF UmsThread AS ANY _                             ' __in PUMS_CONTEXT UmsThread
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateUmsThreadContext IMPORT "KERNEL32.DLL" ALIAS "CreateUmsThreadContext" ( _
   BYREF lpUmsThread AS ANY _                           ' __out PUMS_CONTEXT *lpUmsThread
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnterUmsSchedulingMode IMPORT "KERNEL32.DLL" ALIAS "EnterUmsSchedulingMode" ( _
   BYREF SchedulerStartupInfo AS UMS_SCHEDULER_STARTUP_INFO _ '__in PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >= 0x0601) && !defined(MIDL_PASS)

'typedef struct _PROC_THREAD_ATTRIBUTE_LIST *PPROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;

'//
'// UMS end
'//

'#endif /* _WIN32_WINNT >= 0x0400 */

DECLARE FUNCTION CreateThread IMPORT "KERNEL32.DLL" ALIAS "CreateThread" ( _
   BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in  LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL dwStackSize AS DWORD _                         ' __in  SIZE_T dwStackSize
 , BYVAL lpStartAddress AS DWORD _                      ' __in  LPTHREAD_START_ROUTINE lpStartAddress
 , BYVAL lpParameter AS DWORD _                         ' __in  LPVOID lpParameter
 , BYVAL dwCreationFlags AS DWORD _                     ' __in  DWORD dwCreationFlags
 , BYREF lpThreadId AS DWORD _                          ' __out LPDWORD lpThreadId
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateRemoteThread IMPORT "KERNEL32.DLL" ALIAS "CreateRemoteThread" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in  LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL dwStackSize AS DWORD _                         ' __in  SIZE_T dwStackSize
 , BYVAL lpStartAddress AS DWORD _                      ' __in  LPTHREAD_START_ROUTINE lpStartAddress
 , BYVAL lpParameter AS DWORD _                         ' __in  LPVOID lpParameter
 , BYVAL dwCreationFlags AS DWORD _                     ' __in  DWORD dwCreationFlags
 , BYREF lpThreadId AS DWORD _                          ' __out LPDWORD lpThreadId
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateRemoteThreadEx IMPORT "KERNEL32.DLL" ALIAS "CreateRemoteThreadEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in  LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL dwStackSize AS DWORD _                         ' __in  SIZE_T dwStackSize
 , BYVAL lpStartAddress AS DWORD _                      ' __in  LPTHREAD_START_ROUTINE lpStartAddress
 , BYVAL lpParameter AS DWORD _                         ' __in  LPVOID lpParameter
 , BYVAL dwCreationFlags AS DWORD _                     ' __in  DWORD dwCreationFlags
 , BYVAL lpAttributeList AS DWORD _                     ' __in_opt  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
 , BYREF lpThreadId AS DWORD _                          ' __out LPDWORD lpThreadId
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetCurrentThread IMPORT "KERNEL32.DLL" ALIAS "GetCurrentThread" ( _
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetCurrentThreadId IMPORT "KERNEL32.DLL" ALIAS "GetCurrentThreadId" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetThreadStackGuarantee IMPORT "KERNEL32.DLL" ALIAS "SetThreadStackGuarantee" ( _
   BYREF StackSizeInBytes AS DWORD _                    ' __inout PULONG StackSizeInBytes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessIdOfThread IMPORT "KERNEL32.DLL" ALIAS "GetProcessIdOfThread" ( _
   BYVAL Thread AS DWORD _                              ' __in HANDLE Thread
 ) AS DWORD                                             ' DWORD

'#if (_WIN32_WINNT >= 0x0502)

DECLARE FUNCTION GetThreadId IMPORT "KERNEL32.DLL" ALIAS "GetThreadId" ( _
   BYVAL Thread AS DWORD _                              ' __in HANDLE Thread
 ) AS DWORD                                             ' DWORD

'#endif // _WIN32_WINNT >= 0x0502

DECLARE FUNCTION GetProcessId IMPORT "KERNEL32.DLL" ALIAS "GetProcessId" ( _
   BYVAL Process AS DWORD _                             ' __in HANDLE Process
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCurrentProcessorNumber IMPORT "KERNEL32.DLL" ALIAS "GetCurrentProcessorNumber" ( _
 ) AS DWORD                                             ' DWORD

'#if (_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601
DECLARE SUB GetCurrentProcessorNumberEx IMPORT "KERNEL32.DLL" ALIAS "GetCurrentProcessorNumberEx" ( _
   BYREF ProcNumber AS PROCESSOR_NUMBER _               ' __out PPROCESSOR_NUMBER ProcNumber
 )                                                      ' VOID
#ENDIF

'#if (_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601
DECLARE FUNCTION GetThreadGroupAffinity IMPORT "KERNEL32.DLL" ALIAS "GetThreadGroupAffinity" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF GroupAffinity AS GROUP_AFFINITY _              ' __out PGROUP_AFFINITY GroupAffinity
 ) AS LONG                                              ' BOOL
#ENDIF   ' // _WIN32_WINNT >= 0x0601

DECLARE FUNCTION SetThreadAffinityMask IMPORT "KERNEL32.DLL" ALIAS "SetThreadAffinityMask" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL dwThreadAffinityMask AS DWORD _                ' __in DWORD_PTR dwThreadAffinityMask
 ) AS DWORD                                             ' DWORD_PTR

'#if (_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601
DECLARE FUNCTION SetThreadGroupAffinity IMPORT "KERNEL32.DLL" ALIAS "SetThreadGroupAffinity" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF GroupAffinity AS GROUP_AFFINITY _              ' __in CONST GROUP_AFFINITY *GroupAffinity
 , BYREF PreviousGroupAffinity AS GROUP_AFFINITY _      ' __out_opt PGROUP_AFFINITY PreviousGroupAffinity
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadIdealProcessorEx IMPORT "KERNEL32.DLL" ALIAS "SetThreadIdealProcessorEx" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpIdealProcessor AS PROCESSOR_NUMBER _         ' __in PPROCESSOR_NUMBER lpIdealProcessor
 , BYREF lpPreviousIdealProcessor AS PROCESSOR_NUMBER _ ' __out_opt PPROCESSOR_NUMBER lpPreviousIdealProcessor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadIdealProcessorEx IMPORT "KERNEL32.DLL" ALIAS "GetThreadIdealProcessorEx" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpIdealProcessor AS PROCESSOR_NUMBER _         ' __out PPROCESSOR_NUMBER lpIdealProcessor
 ) AS LONG                                              ' BOOL
#ENDIF   ' // _WIN32_WINNT >= 0x0601

'#if(_WIN32_WINNT >= 0x0400)
DECLARE FUNCTION SetThreadIdealProcessor IMPORT "KERNEL32.DLL" ALIAS "SetThreadIdealProcessor" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL dwIdealProcessor AS DWORD _                    ' __in DWORD  dwIdealProcessor
 ) AS DWORD                                             ' HANDLE
'#endif /* _WIN32_WINNT >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

%PROCESS_DEP_ENABLE                          = &H00000001???
%PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION     = &H00000002???

DECLARE FUNCTION SetProcessDEPPolicy IMPORT "KERNEL32.DLL" ALIAS "SetProcessDEPPolicy" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessDEPPolicy IMPORT "KERNEL32.DLL" ALIAS "GetProcessDEPPolicy" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF lpFlags AS DWORD _                             ' __out LPDWORD lpFlags
 , BYREF lpPermanent AS LONG _                          ' __out PBOOL lpPermanent
 ) AS LONG                                              ' BOOL

'#endif // _WIN32_WINNT >= 0x0600
#ENDIF

DECLARE FUNCTION SetProcessPriorityBoost IMPORT "KERNEL32.DLL" ALIAS "SetProcessPriorityBoost" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL bDisablePriorityBoost AS LONG _                ' __in BOOL   bDisablePriorityBoost
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessPriorityBoost IMPORT "KERNEL32.DLL" ALIAS "GetProcessPriorityBoost" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF pDisablePriorityBoost AS LONG _                ' __out PBOOL  pDisablePriorityBoost
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RequestWakeupLatency IMPORT "KERNEL32.DLL" ALIAS "RequestWakeupLatency" ( _
   BYVAL latency AS LONG _                              ' __in LATENCY_TIME latency
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsSystemResumeAutomatic IMPORT "KERNEL32.DLL" ALIAS "IsSystemResumeAutomatic" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenThread IMPORT "KERNEL32.DLL" ALIAS "OpenThread" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL  bInheritHandle
 , BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION SetThreadPriority IMPORT "KERNEL32.DLL" ALIAS "SetThreadPriority" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL nPriority AS LONG _                            ' __in int    nPriority
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadPriorityBoost IMPORT "KERNEL32.DLL" ALIAS "SetThreadPriorityBoost" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL bDisablePriorityBoost AS LONG _                ' __in BOOL   bDisablePriorityBoost
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadPriorityBoost IMPORT "KERNEL32.DLL" ALIAS "GetThreadPriorityBoost" ( _
   BYVAL hThread AS DWORD _                             ' __in  HANDLE hThread
 , BYREF pDisablePriorityBoost AS LONG _                ' __out PBOOL  pDisablePriorityBoost
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadPriority IMPORT "KERNEL32.DLL" ALIAS "GetThreadPriority" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 ) AS LONG                                              ' int

DECLARE FUNCTION GetThreadTimes IMPORT "KERNEL32.DLL" ALIAS "GetThreadTimes" ( _
   BYVAL hThread AS DWORD _                             ' __in  HANDLE     hThread
 , BYREF lpCreationTime AS FILETIME _                   ' __out LPFILETIME lpCreationTime
 , BYREF lpExitTime AS FILETIME _                       ' __out LPFILETIME lpExitTime
 , BYREF lpKernelTime AS FILETIME _                     ' __out LPFILETIME lpKernelTime
 , BYREF lpUserTime AS FILETIME _                       ' __out LPFILETIME lpUserTime
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION GetThreadIOPendingFlag IMPORT "KERNEL32.DLL" ALIAS "GetThreadIOPendingFlag" ( _
   BYVAL hThread AS DWORD _                             ' __in  HANDLE hThread
 , BYREF lpIOIsPending AS LONG _                        ' __out PBOOL  lpIOIsPending
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

DECLARE SUB ExitThread IMPORT "KERNEL32.DLL" ALIAS "ExitThread" ( _
   BYVAL dwExitCode AS DWORD _                          ' __in DWORD dwExitCode
 )                                                      ' void

DECLARE FUNCTION TerminateThread IMPORT "KERNEL32.DLL" ALIAS "TerminateThread" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL dwExitCode AS DWORD _                          ' __in DWORD  dwExitCode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetExitCodeThread IMPORT "KERNEL32.DLL" ALIAS "GetExitCodeThread" ( _
   BYVAL hThread AS DWORD _                             ' __in  HANDLE  hThread
 , BYREF lpExitCode AS DWORD _                          ' __out LPDWORD lpExitCode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadSelectorEntry IMPORT "KERNEL32.DLL" ALIAS "GetThreadSelectorEntry" ( _
   BYVAL hThread AS DWORD _                             ' __in  HANDLE hThread
 , BYVAL dwSelector AS DWORD _                          ' __in  DWORD dwSelector
 , BYREF lpSelectorEntry AS LDT_ENTRY _                 ' __out LPLDT_ENTRY lpSelectorEntry
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadExecutionState IMPORT "KERNEL32.DLL" ALIAS "SetThreadExecutionState" ( _
   BYVAL esFlags AS DWORD _                             ' __in EXECUTION_STATE esFlags
 ) AS DWORD                                             ' EXECUTION_STATE

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0601

' // Size = 16 bytes
TYPE REASON_CONTEXT_Detailed DWORD
   LocalizedReasonModule AS DWORD          ' HMODULE
   LocalizedReasonId     AS DWORD          ' ULONG
   ReasonStringCount     AS DWORD          ' ULONG
   ReasonStrings         AS WSTRINGZ PTR   ' LPWSTR*
END TYPE

' // Size = 16 bytes
UNION REASON_CONTEXT_UNION DWORD
   Detailed AS REASON_CONTEXT_Detailed
   SimpleReasonString AS WSTRINGZ PTR   ' LPWSTR
END UNION

' // Size = 24 bytes
TYPE REASON_CONTEXT DWORD
   Version AS DWORD   ' ULONG
   Flags   AS DWORD   ' DWORD
   Reason  AS REASON_CONTEXT_UNION
END TYPE

'//
'// Power Request APIs
'//

'typedef REASON_CONTEXT POWER_REQUEST_CONTEXT, *PPOWER_REQUEST_CONTEXT, *LPPOWER_REQUEST_CONTEXT;

DECLARE FUNCTION PowerCreateRequest IMPORT "KERNEL32.DLL" ALIAS "PowerCreateRequest" ( _
   BYREF Context AS REASON_CONTEXT _                    ' __in PREASON_CONTEXT Context
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION PowerSetRequest IMPORT "KERNEL32.DLL" ALIAS "PowerSetRequest" ( _
   BYVAL PowerRequest AS DWORD _                        ' __in HANDLE PowerRequest
 , BYVAL RequestType AS LONG _                          ' __in POWER_REQUEST_TYPE RequestType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PowerClearRequest IMPORT "KERNEL32.DLL" ALIAS "PowerClearRequest" ( _
   BYVAL PowerRequest AS DWORD _                        ' __in HANDLE PowerRequest
 , BYVAL RequestType AS LONG _                          ' __in POWER_REQUEST_TYPE RequestType
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

DECLARE FUNCTION GetLastError IMPORT "KERNEL32.DLL" ALIAS "GetLastError" ( _
   ) AS DWORD                                           ' DWORD

DECLARE SUB SetLastError IMPORT "KERNEL32.DLL" ALIAS "SetLastError" ( _
   BYVAL dwErrCode AS DWORD _                           ' __in DWORD dwErrCode
 )                                                      ' void

DECLARE SUB RestoreLastError IMPORT "KERNEL32.DLL" ALIAS "RestoreLastError" ( _
   BYVAL dwErrCode AS DWORD _                           ' __in DWORD dwErrCode
 )                                                      ' void

'typedef VOID (WINAPI* PRESTORE_LAST_ERROR)(DWORD);
'#define RESTORE_LAST_ERROR_NAME_A      "RestoreLastError"
'#define RESTORE_LAST_ERROR_NAME_W     L"RestoreLastError"
'#define RESTORE_LAST_ERROR_NAME   TEXT("RestoreLastError")

$RESTORE_LAST_ERROR_NAME_A      = "RestoreLastError"
$RESTORE_LAST_ERROR_NAME        = "RestoreLastError"

'#endif

'#define HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal) != STATUS_PENDING)

DECLARE FUNCTION GetOverlappedResult IMPORT "KERNEL32.DLL" ALIAS "GetOverlappedResult" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __in  LPOVERLAPPED lpOverlapped
 , BYREF lpNumberOfBytesTransferred AS DWORD _          ' __out LPDWORD lpNumberOfBytesTransferred
 , BYVAL bWait AS LONG _                                ' __in  BOOL bWait
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateIoCompletionPort IMPORT "KERNEL32.DLL" ALIAS "CreateIoCompletionPort" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL ExistingCompletionPort AS DWORD _              ' __in HANDLE ExistingCompletionPort
 , BYVAL CompletionKey AS DWORD _                       ' __in ULONG_PTR CompletionKey
 , BYVAL NumberOfConcurrentThreads AS DWORD _           ' __in DWORD NumberOfConcurrentThreads
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetQueuedCompletionStatus LIB "Kernel32.dll" _
    ALIAS "GetQueuedCompletionStatus" (BYVAL CompletionPort AS DWORD, _
    lpNumberOfBytesTransferred AS DWORD, lpCompletionKey AS DWORD, _
    lpOverlapped AS OVERLAPPED, BYVAL dwMilliseconds AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetQueuedCompletionStatus IMPORT "KERNEL32.DLL" ALIAS "GetQueuedCompletionStatus" ( _
   BYVAL CompletionPort AS DWORD _                      ' __in  HANDLE CompletionPort
 , BYREF lpNumberOfBytesTransferred AS DWORD _          ' __out LPDWORD lpNumberOfBytesTransferred
 , BYREF lpCompletionKey AS DWORD _                     ' __out PULONG_PTR lpCompletionKey
 , BYREF lpOverlapped AS DWORD _                        ' __out LPOVERLAPPED *lpOverlapped
 , BYVAL dwMilliseconds AS DWORD _                      ' __in  DWORD dwMilliseconds
 ) AS LONG                                              ' BOOL
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetQueuedCompletionStatusEx LIB "Kernel32.dll" _
    ALIAS "GetQueuedCompletionStatusEx" (BYVAL CompletionPort AS DWORD, _
    lpCompletionPortEntries AS DWORD, BYVAL ulCount AS DWORD, _
    ulNumEntriesRemoved AS DWORD, BYVAL dwMilliseconds AS DWORD, _
    BYVAL fAlertable AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetQueuedCompletionStatusEx IMPORT "KERNEL32.DLL" ALIAS "GetQueuedCompletionStatusEx" ( _
   BYVAL CompletionPort AS DWORD _                      ' __in  HANDLE CompletionPort
 , BYREF lpCompletionPortEntries AS OVERLAPPED_ENTRY _  ' __out LPOVERLAPPED_ENTRY lpCompletionPortEntries
 , BYVAL ulCount AS DWORD _                             ' __in  ULONG ulCount
 , BYREF ulNumEntriesRemoved AS DWORD _                 ' __out PULONG ulNumEntriesRemoved
 , BYVAL dwMilliseconds AS DWORD _                      ' __in  DWORD dwMilliseconds
 , BYVAL fAlertable AS LONG _                           ' __in  BOOL fAlertable
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PostQueuedCompletionStatus LIB "Kernel32.dll" _
    ALIAS "PostQueuedCompletionStatus" (BYVAL CompletionPort AS DWORD, _
    BYVAL dwNumberOfBytesTransferred AS DWORD, BYVAL dwCompletionKey AS DWORD, _
    lpOverlapped AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PostQueuedCompletionStatus IMPORT "KERNEL32.DLL" ALIAS "PostQueuedCompletionStatus" ( _
   BYVAL CompletionPort AS DWORD _                      ' __in HANDLE CompletionPort
 , BYVAL dwNumberOfBytesTransferred AS DWORD _          ' __in DWORD dwNumberOfBytesTransferred
 , BYVAL dwCompletionKey AS DWORD _                     ' __in ULONG_PTR dwCompletionKey
 , OPTIONAL BYREF lpOverlapped AS OVERLAPPED _          ' __in LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

'//
'// The following flags allows an application to change
'// the semantics of IO completion notification.
'//

'//
'// Don't queue an entry to an associated completion port if returning success
'// synchronously.
'//
%FILE_SKIP_COMPLETION_PORT_ON_SUCCESS    = &H1?

'//
'// Don't set the file handle event on IO completion.
'//
%FILE_SKIP_SET_EVENT_ON_HANDLE           = &H2?

DECLARE FUNCTION SetFileCompletionNotificationModes IMPORT "KERNEL32.DLL" ALIAS "SetFileCompletionNotificationModes" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL Flags AS BYTE _                                ' __in UCHAR  Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileIoOverlappedRange IMPORT "KERNEL32.DLL" ALIAS "SetFileIoOverlappedRange" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL OverlappedRangeStart AS BYTE PTR _             ' __in PUCHAR OverlappedRangeStart
 , BYVAL Length AS DWORD _                              ' __in ULONG  Length
 ) AS LONG                                              ' BOOL

#ENDIF ' // _WIN32_WINNT >= 0x0600

%SEM_FAILCRITICALERRORS     = &H0001???
%SEM_NOALIGNMENTFAULTEXCEPT = &H0004???
%SEM_NOGPFAULTERRORBOX      = &H0002???
%SEM_NOOPENFILEERRORBOX     = &H8000???

DECLARE FUNCTION GetErrorMode IMPORT "KERNEL32.DLL" ALIAS "GetErrorMode" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetErrorMode IMPORT "KERNEL32.DLL" ALIAS "SetErrorMode" ( _
   BYVAL uMode AS DWORD _                               ' __in UINT uMode
 ) AS DWORD                                             ' UINT

'//
'// Thread error mode support
'//

DECLARE FUNCTION GetThreadErrorMode IMPORT "KERNEL32.DLL" ALIAS "GetThreadErrorMode" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetThreadErrorMode IMPORT "KERNEL32.DLL" ALIAS "SetThreadErrorMode" ( _
   BYVAL dwNewMode AS DWORD _                           ' __in DWORD dwNewMode
 , BYREF lpOldMode AS DWORD _                           ' __out LPDWORD lpOldMode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReadProcessMemory IMPORT "KERNEL32.DLL" ALIAS "ReadProcessMemory" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYVAL lpBaseAddress AS DWORD _                       ' __in  LPCVOID lpBaseAddress
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID  lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  SIZE_T  nSize
 , BYREF lpNumberOfBytesRead AS DWORD _                 ' __out SIZE_T *lpNumberOfBytesRead
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WriteProcessMemory IMPORT "KERNEL32.DLL" ALIAS "WriteProcessMemory" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYVAL lpBaseAddress AS DWORD _                       ' __in  LPVOID  lpBaseAddress
 , BYREF lpBuffer AS ANY _                              ' __in  LPCVOID lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  SIZE_T  nSize
 , BYREF lpNumberOfBytesWritten AS DWORD _              ' __out SIZE_T *lpNumberOfBytesWritten
 ) AS LONG                                              ' BOOL

'#if !defined(MIDL_PASS)

DECLARE FUNCTION GetThreadContext IMPORT "KERNEL32.DLL" ALIAS "GetThreadContext" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpContext AS CONTEXT _                         ' __inout LPCONTEXT lpContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadContext IMPORT "KERNEL32.DLL" ALIAS "SetThreadContext" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpContext AS CONTEXT _                         ' __in CONST CONTEXT *lpContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Wow64GetThreadContext IMPORT "KERNEL32.DLL" ALIAS "Wow64GetThreadContext" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpContext AS WOW64_CONTEXT _                   ' __inout PWOW64_CONTEXT lpContext
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601

DECLARE FUNCTION Wow64GetThreadSelectorEntry IMPORT "KERNEL32.DLL" ALIAS "Wow64GetThreadSelectorEntry" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL dwSelector AS DWORD _                          ' __in DWORD dwSelector
 , BYREF lpSelectorEntry AS WOW64_LDT_ENTRY _           ' __out PWOW64_LDT_ENTRY lpSelectorEntry
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* _WIN32_WINNT >= 0x0601 */

DECLARE FUNCTION Wow64SetThreadContext IMPORT "KERNEL32.DLL" ALIAS "Wow64SetThreadContext" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF lpContext AS WOW64_CONTEXT _                   ' __in CONST WOW64_CONTEXT *lpContext
 ) AS LONG                                              ' BOOL

'#endif

DECLARE FUNCTION SuspendThread IMPORT "KERNEL32.DLL" ALIAS "SuspendThread" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION Wow64SuspendThread IMPORT "KERNEL32.DLL" ALIAS "Wow64SuspendThread" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ResumeThread IMPORT "KERNEL32.DLL" ALIAS "ResumeThread" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 ) AS DWORD                                             ' DWORD

'#if(_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)

DECLARE FUNCTION QueueUserAPC IMPORT "KERNEL32.DLL" ALIAS "QueueUserAPC" ( _
   BYVAL pfnAPC AS DWORD _                              ' __in PAPCFUNC pfnAPC
 , BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYVAL dwData AS DWORD _                              ' __in ULONG_PTR dwData
 ) AS DWORD                                             ' DWORD

'#endif /* _WIN32_WINNT >= 0x0400 || _WIN32_WINDOWS > 0x0400 */

'#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)

DECLARE FUNCTION IsDebuggerPresent IMPORT "KERNEL32.DLL" ALIAS "IsDebuggerPresent" ( _
 ) AS LONG                                              ' BOOL

'#endif

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION CheckRemoteDebuggerPresent IMPORT "KERNEL32.DLL" ALIAS "CheckRemoteDebuggerPresent" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF pbDebuggerPresent AS LONG _                    ' __out PBOOL  pbDebuggerPresent
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

DECLARE SUB DebugBreak IMPORT "KERNEL32.DLL" ALIAS "DebugBreak" ()   ' void

DECLARE FUNCTION WaitForDebugEvent IMPORT "KERNEL32.DLL" ALIAS "WaitForDebugEvent" ( _
   BYREF lpDebugEvent AS DEBUG_EVENT _                  ' __in LPDEBUG_EVENT lpDebugEvent
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ContinueDebugEvent IMPORT "KERNEL32.DLL" ALIAS "ContinueDebugEvent" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 , BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 , BYVAL dwContinueStatus AS DWORD _                    ' __in DWORD dwContinueStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DebugActiveProcess IMPORT "KERNEL32.DLL" ALIAS "DebugActiveProcess" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DebugActiveProcessStop IMPORT "KERNEL32.DLL" ALIAS "DebugActiveProcessStop" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DebugSetProcessKillOnExit IMPORT "KERNEL32.DLL" ALIAS "DebugSetProcessKillOnExit" ( _
   BYVAL KillOnExit AS LONG _                           ' __in BOOL KillOnExit
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DebugBreakProcess IMPORT "KERNEL32.DLL" ALIAS "DebugBreakProcess" ( _
   BYVAL Process AS DWORD _                             ' __in HANDLE Process
 ) AS LONG                                              ' BOOL

DECLARE SUB InitializeCriticalSection IMPORT "KERNEL32.DLL" ALIAS "InitializeCriticalSection" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __out LPCRITICAL_SECTION lpCriticalSection
 )                                                      ' void

DECLARE SUB EnterCriticalSection IMPORT "KERNEL32.DLL" ALIAS "EnterCriticalSection" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __inout LPCRITICAL_SECTION lpCriticalSection
 )                                                      ' void

DECLARE SUB LeaveCriticalSection IMPORT "KERNEL32.DLL" ALIAS "LeaveCriticalSection" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __inout LPCRITICAL_SECTION lpCriticalSection
 )                                                      ' void

'#if (_WIN32_WINNT >= 0x0403)

%CRITICAL_SECTION_NO_DEBUG_INFO  = %RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO

DECLARE FUNCTION InitializeCriticalSectionAndSpinCount IMPORT "KERNEL32.DLL" ALIAS "InitializeCriticalSectionAndSpinCount" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __out LPCRITICAL_SECTION lpCriticalSection
 , BYVAL dwSpinCount AS DWORD _                         ' __in  DWORD dwSpinCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCriticalSectionSpinCount IMPORT "KERNEL32.DLL" ALIAS "SetCriticalSectionSpinCount" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __inout LPCRITICAL_SECTION lpCriticalSection
 , BYVAL dwSpinCount AS DWORD _                         ' __in DWORD dwSpinCount
 ) AS DWORD                                             ' DWORD

'#endif

'#if(_WIN32_WINNT >= 0x0400)

DECLARE FUNCTION TryEnterCriticalSection IMPORT "KERNEL32.DLL" ALIAS "TryEnterCriticalSection" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __inout LPCRITICAL_SECTION lpCriticalSection
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0400 */

DECLARE SUB DeleteCriticalSection IMPORT "KERNEL32.DLL" ALIAS "DeleteCriticalSection" ( _
   BYREF lpCriticalSection AS CRITICAL_SECTION _        ' __inout LPCRITICAL_SECTION lpCriticalSection
 )                                                      ' void

DECLARE FUNCTION SetEvent IMPORT "KERNEL32.DLL" ALIAS "SetEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ResetEvent IMPORT "KERNEL32.DLL" ALIAS "ResetEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PulseEvent IMPORT "KERNEL32.DLL" ALIAS "PulseEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReleaseSemaphore IMPORT "KERNEL32.DLL" ALIAS "ReleaseSemaphore" ( _
   BYVAL hSemaphore AS DWORD _                          ' __in  HANDLE hSemaphore
 , BYVAL lReleaseCount AS LONG _                        ' __in  LONG lReleaseCount
 , BYREF lpPreviousCount AS LONG _                      ' __out LPLONG lpPreviousCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReleaseMutex IMPORT "KERNEL32.DLL" ALIAS "ReleaseMutex" ( _
   BYVAL hMutex AS DWORD _                              ' __in HANDLE hMutex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WaitForSingleObject IMPORT "KERNEL32.DLL" ALIAS "WaitForSingleObject" ( _
   BYVAL hHandle AS DWORD _                             ' __in HANDLE hHandle
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WaitForMultipleObjects IMPORT "KERNEL32.DLL" ALIAS "WaitForMultipleObjects" ( _
   BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF lpHandles AS DWORD _                           ' __in_ecount(nCount) CONST HANDLE *lpHandles
 , BYVAL bWaitAll AS LONG _                             ' __in BOOL bWaitAll
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS DWORD                                             ' DWORD

DECLARE SUB ApiSleep IMPORT "KERNEL32.DLL" ALIAS "Sleep" ( _
   BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 )                                                      ' void

DECLARE FUNCTION LoadResource IMPORT "KERNEL32.DLL" ALIAS "LoadResource" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL hResInfo AS DWORD _                            ' __in HRSRC hResInfo
 ) AS DWORD                                             ' HGLOBAL

DECLARE FUNCTION SizeofResource IMPORT "KERNEL32.DLL" ALIAS "SizeofResource" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL hResInfo AS DWORD _                            ' __in HRSRC hResInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GlobalDeleteAtom IMPORT "KERNEL32.DLL" ALIAS "GlobalDeleteAtom" ( _
   BYVAL nAtom AS WORD _                                ' __in ATOM nAtom
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION InitAtomTable IMPORT "KERNEL32.DLL" ALIAS "InitAtomTable" ( _
   BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteAtom IMPORT "KERNEL32.DLL" ALIAS "DeleteAtom" ( _
   BYVAL nAtom AS WORD _                                ' __in ATOM nAtom
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION SetHandleCount IMPORT "KERNEL32.DLL" ALIAS "SetHandleCount" ( _
   BYVAL uNumber AS DWORD _                             ' __in UINT uNumber
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetLogicalDrives IMPORT "KERNEL32.DLL" ALIAS "GetLogicalDrives" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION LockFile IMPORT "KERNEL32.DLL" ALIAS "LockFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFileOffsetLow AS DWORD _                     ' __in DWORD dwFileOffsetLow
 , BYVAL dwFileOffsetHigh AS DWORD _                    ' __in DWORD dwFileOffsetHigh
 , BYVAL nNumberOfBytesToLockLow AS DWORD _             ' __in DWORD nNumberOfBytesToLockLow
 , BYVAL nNumberOfBytesToLockHigh AS DWORD _            ' __in DWORD nNumberOfBytesToLockHigh
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnlockFile IMPORT "KERNEL32.DLL" ALIAS "UnlockFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFileOffsetLow AS DWORD _                     ' __in DWORD dwFileOffsetLow
 , BYVAL dwFileOffsetHigh AS DWORD _                    ' __in DWORD dwFileOffsetHigh
 , BYVAL nNumberOfBytesToLockLow AS DWORD _             ' __in DWORD nNumberOfBytesToUnlockLow
 , BYVAL nNumberOfBytesToLockHigh AS DWORD _            ' __in DWORD nNumberOfBytesToUnlockHigh
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LockFileEx IMPORT "KERNEL32.DLL" ALIAS "LockFileEx" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL nNumberOfBytesToLockLow AS DWORD _             ' __in DWORD nNumberOfBytesToLockLow
 , BYVAL nNumberOfBytesToLockHigh AS DWORD _            ' __in DWORD nNumberOfBytesToLockHigh
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

%LOCKFILE_FAIL_IMMEDIATELY = &H00000001???
%LOCKFILE_EXCLUSIVE_LOCK   = &H00000002???

DECLARE FUNCTION UnlockFileEx IMPORT "KERNEL32.DLL" ALIAS "UnlockFileEx" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL nNumberOfBytesToUnlockLow AS DWORD _           ' __in DWORD nNumberOfBytesToUnlockLow
 , BYVAL nNumberOfBytesToUnlockHigh AS DWORD _          ' __in DWORD nNumberOfBytesToUnlockHigh
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

' // Size = 52 bytes
TYPE BY_HANDLE_FILE_INFORMATION DWORD
   dwFileAttributes     AS DWORD      ' DWORD dwFileAttributes
   ftCreationTime       AS FILETIME   ' FILETIME ftCreationTime
   ftLastAccessTime     AS FILETIME   ' FILETIME ftLastAccessTime
   ftLastWriteTime      AS FILETIME   ' FILETIME ftLastWriteTime
   dwVolumeSerialNumber AS DWORD      ' DWORD dwVolumeSerialNumber
   nFileSizeHigh        AS DWORD      ' DWORD nFileSizeHigh
   nFileSizeLow         AS DWORD      ' DWORD nFileSizeLow
   nNumberOfLinks       AS DWORD      ' DWORD nNumberOfLinks
   nFileIndexHigh       AS DWORD      ' DWORD nFileIndexHigh
   nFileIndexLow        AS DWORD      ' DWORD nFileIndexLow
END TYPE

DECLARE FUNCTION GetFileInformationByHandle IMPORT "KERNEL32.DLL" ALIAS "GetFileInformationByHandle" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpFileInformation AS BY_HANDLE_FILE_INFORMATION _ ' __out LPBY_HANDLE_FILE_INFORMATION lpFileInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileType IMPORT "KERNEL32.DLL" ALIAS "GetFileType" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFileSize IMPORT "KERNEL32.DLL" ALIAS "GetFileSize" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpFileSizeHigh AS LONG _                       ' __out LPDWORD lpFileSizeHigh
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFileSizeEx IMPORT "KERNEL32.DLL" ALIAS "GetFileSizeEx" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpFileSize AS QUAD _                           ' __out PLARGE_INTEGER lpFileSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetStdHandle IMPORT "KERNEL32.DLL" ALIAS "GetStdHandle" ( _
   BYVAL nStdHandle AS DWORD _                          ' __in DWORD nStdHandle
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION SetStdHandle IMPORT "KERNEL32.DLL" ALIAS "SetStdHandle" ( _
   BYVAL nStdHandle AS DWORD _                          ' __in DWORD nStdHandle
 , BYVAL hHandle AS DWORD _                             ' __in HANDLE hHandle
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION SetStdHandleEx IMPORT "KERNEL32.DLL" ALIAS "SetStdHandleEx" ( _
   BYVAL nStdHandle AS DWORD _                          ' __in DWORD nStdHandle
 , BYVAL hHandle AS DWORD _                             ' __in HANDLE hHandle
 , BYREF phPrevValue AS DWORD _                         ' __out PHANDLE phPrevValue
 ) AS LONG                                              ' BOOL

#ENDIF ' // _WIN32_WINNT >= 0x0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteFile LIB "Kernel32.dll" ALIAS "WriteFile" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpNumberOfBytesWritten AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION WriteFile IMPORT "KERNEL32.DLL" ALIAS "WriteFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __in LPCVOID lpBuffer
 , BYVAL nNumberOfBytesToWrite AS DWORD _               ' __in DWORD nNumberOfBytesToWrite
 , OPTIONAL BYREF lpNumberOfBytesWritten AS DWORD _     ' __out_opt LPDWORD lpNumberOfBytesWritten
 , OPTIONAL BYREF lpOverlapped AS OVERLAPPED _          ' __inout_opt LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadFile LIB "Kernel32.dll" ALIAS "ReadFile" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpNumberOfBytesRead AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION ReadFile IMPORT "KERNEL32.DLL" ALIAS "ReadFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in DWORD nNumberOfBytesToRead
 , OPTIONAL BYREF lpNumberOfBytesRead AS DWORD _        ' __out_opt LPDWORD lpNumberOfBytesRead
 , OPTIONAL BYREF lpOverlapped AS OVERLAPPED _          ' __inout_opt LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION FlushFileBuffers IMPORT "KERNEL32.DLL" ALIAS "FlushFileBuffers" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DeviceIoControl LIB "Kernel32.dll" ALIAS "DeviceIoControl" _
    (BYVAL hDevice AS DWORD, BYVAL dwIoControlCode AS DWORD, _
    BYVAL lpInBuffer AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL lpOutBuffer AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    lpBytesReturned AS LONG, lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION DeviceIoControl IMPORT "KERNEL32.DLL" ALIAS "DeviceIoControl" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwIoControlCode AS DWORD _                     ' __in DWORD dwIoControlCode
 , BYREF lpInBuffer AS ANY _                            ' __in LPVOID lpInBuffer
 , BYVAL nInBufferSize AS DWORD _                       ' __in DWORD nInBufferSize
 , BYREF lpOutBuffer AS ANY _                           ' __out LPVOID lpOutBuffer
 , BYVAL nOutBufferSize AS DWORD _                      ' __in DWORD nOutBufferSize
 , BYREF lpBytesReturned AS DWORD _                     ' __out LPDWORD lpBytesReturned
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION RequestDeviceWakeup IMPORT "KERNEL32.DLL" ALIAS "RequestDeviceWakeup" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CancelDeviceWakeupRequest IMPORT "KERNEL32.DLL" ALIAS "CancelDeviceWakeupRequest" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDevicePowerState IMPORT "KERNEL32.DLL" ALIAS "GetDevicePowerState" ( _
   BYVAL hDevice AS DWORD _                             ' __in  HANDLE hDevice
 , BYREF pfOn AS DWORD _                                ' __out BOOL *pfOn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMessageWaitingIndicator IMPORT "KERNEL32.DLL" ALIAS "SetMessageWaitingIndicator" ( _
   BYVAL hMsgIndicator AS DWORD _                       ' __in HANDLE hMsgIndicator
 , BYVAL ulMsgCount AS DWORD _                          ' __in ULONG ulMsgCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetEndOfFile IMPORT "KERNEL32.DLL" ALIAS "SetEndOfFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFilePointer IMPORT "KERNEL32.DLL" ALIAS "SetFilePointer" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL lDistanceToMove AS LONG _                      ' __in LONG lDistanceToMove
 , BYREF lpDistanceToMoveHigh AS LONG _                 ' __in PLONG lpDistanceToMoveHigh
 , BYVAL dwMoveMethod AS DWORD _                        ' __in DWORD dwMoveMethod
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetFilePointerEx IMPORT "KERNEL32.DLL" ALIAS "SetFilePointerEx" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYVAL lDistanceToMove AS QUAD _                      ' __in  LARGE_INTEGER liDistanceToMove
 , BYREF lpNewFilePointer AS QUAD _                     ' __out PLARGE_INTEGER lpNewFilePointer
 , BYVAL dwMoveMethod AS DWORD _                        ' __in  DWORD dwMoveMethod
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindClose IMPORT "KERNEL32.DLL" ALIAS "FindClose" ( _
   BYVAL hFindFile AS DWORD _                           ' __inout HANDLE hFindFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileTime IMPORT "KERNEL32.DLL" ALIAS "GetFileTime" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpCreationTime AS FILETIME _                   ' __out LPFILETIME lpCreationTime
 , BYREF lpLastAccessTime AS FILETIME _                 ' __out LPFILETIME lpLastAccessTime
 , BYREF lpLastWriteTime AS FILETIME _                  ' __out LPFILETIME lpLastWriteTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileTime IMPORT "KERNEL32.DLL" ALIAS "SetFileTime" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpCreationTime AS FILETIME _                   ' __in CONST FILETIME *lpCreationTime
 , BYREF lpLastAccessTime AS FILETIME _                 ' __in CONST FILETIME *lpLastAccessTime
 , BYREF lpLastWriteTime AS FILETIME _                  ' __in CONST FILETIME *lpLastWriteTime
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION SetFileValidData IMPORT "KERNEL32.DLL" ALIAS "SetFileValidData" ( _
   BYVAL hFile AS DWORD  _                              ' __in HANDLE hFile
 , BYVAL ValidDataLength AS QUAD _                      ' __in LONGLONG ValidDataLength
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION SetFileShortNameA IMPORT "KERNEL32.DLL" ALIAS "SetFileShortNameA" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpShortName AS ASCIIZ _                        ' __in LPCSTR lpShortName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileShortNameW IMPORT "KERNEL32.DLL" ALIAS "SetFileShortNameW" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpShortName AS WSTRINGZ _                      ' __in LPCWSTR lpShortName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetFileShortName = SetFileShortNameW
#ELSE
   MACRO SetFileShortName = SetFileShortNameA
#ENDIF

DECLARE FUNCTION CloseHandle IMPORT "KERNEL32.DLL" ALIAS "CloseHandle" ( _
   BYVAL hObject AS DWORD _                             ' __in HANDLE hObject
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DuplicateHandle IMPORT "KERNEL32.DLL" ALIAS "DuplicateHandle" ( _
   BYVAL hSourceProcessHandle AS DWORD _                ' __in  HANDLE hSourceProcessHandle
 , BYVAL hSourceHandle AS DWORD _                       ' __in  HANDLE hSourceHandle
 , BYVAL hTargetProcessHandle AS DWORD _                ' __in  HANDLE hTargetProcessHandle
 , BYREF lpTargetHandle AS DWORD _                      ' __out LPHANDLE lpTargetHandle
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in  DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in  BOOL bInheritHandle
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetHandleInformation IMPORT "KERNEL32.DLL" ALIAS "GetHandleInformation" ( _
   BYVAL hObject AS DWORD  _                            ' __in  HANDLE hObject
 , BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetHandleInformation IMPORT "KERNEL32.DLL" ALIAS "SetHandleInformation" ( _
   BYVAL hObject AS DWORD _                             ' __in HANDLE hObject
 , BYVAL dwMask AS DWORD _                              ' __in DWORD dwMask
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

%HANDLE_FLAG_INHERIT             = &H00000001???
%HANDLE_FLAG_PROTECT_FROM_CLOSE  = &H00000002???

%HINSTANCE_ERROR = 32

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LoadModule LIB "Kernel32.dll" ALIAS "LoadModule" _
    (lpModuleName AS ASCIIZ, BYVAL lpParameterBlock AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION LoadModule IMPORT "KERNEL32.DLL" ALIAS "LoadModule" ( _
   BYREF lpModuleName AS ASCIIZ  _                      ' __in LPCSTR lpModuleName
 , BYREF lpParameterBlock AS ANY _                      ' __in LPVOID lpParameterBlock
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION WinExec IMPORT "KERNEL32.DLL" ALIAS "WinExec" ( _
   BYREF lpCmdLine AS ASCIIZ _                          ' __in LPCSTR lpCmdLine
 , BYVAL uCmdShow AS DWORD _                            ' __in UINT uCmdShow
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ClearCommBreak IMPORT "KERNEL32.DLL" ALIAS "ClearCommBreak" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ClearCommError IMPORT "KERNEL32.DLL" ALIAS "ClearCommError" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpErrors AS DWORD _                            ' __out LPDWORD lpErrors
 , BYREF lpStat AS COMSTAT _                            ' __out LPCOMSTAT lpStat
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupComm IMPORT "KERNEL32.DLL" ALIAS "SetupComm" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwInQueue AS DWORD _                           ' __in DWORD dwInQueue
 , BYVAL dwOutQueue AS DWORD _                          ' __in DWORD dwOutQueue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EscapeCommFunction IMPORT "KERNEL32.DLL" ALIAS "EscapeCommFunction" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFunc AS DWORD _                              ' __in DWORD dwFunc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCommConfig IMPORT "KERNEL32.DLL" ALIAS "GetCommConfig" ( _
   BYVAL hCommDev AS DWORD _                            ' __in HANDLE hCommDev
 , BYREF lpCC AS COMMCONFIG _                           ' __out LPCOMMCONFIG lpCC
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCommMask IMPORT "KERNEL32.DLL" ALIAS "GetCommMask" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpEvtMask AS DWORD _                           ' __out LPDWORD lpEvtMask
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetCommProperties LIB "Kernel32.dll" _
    ALIAS "GetCommProperties" (BYVAL hFile AS DWORD, _
    BYVAL lpCommProp AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetCommProperties IMPORT "KERNEL32.DLL" ALIAS "GetCommProperties" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpCommProp AS COMMPROP _                       ' __out LPCOMMPROP lpCommProp
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION GetCommModemStatus IMPORT "KERNEL32.DLL" ALIAS "GetCommModemStatus" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpModemStat AS DWORD _                         ' __out LPDWORD lpModemStat
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCommState IMPORT "KERNEL32.DLL" ALIAS "GetCommState" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpDCB AS DCB _                                 ' __out LPDCB lpDCB
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCommTimeouts IMPORT "KERNEL32.DLL" ALIAS "GetCommTimeouts" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpCommTimeouts AS COMMTIMEOUTS _               ' __out LPCOMMTIMEOUTS lpCommTimeouts
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PurgeComm IMPORT "KERNEL32.DLL" ALIAS "PurgeComm" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCommBreak IMPORT "KERNEL32.DLL" ALIAS "SetCommBreak" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCommConfig IMPORT "KERNEL32.DLL" ALIAS "SetCommConfig" ( _
   BYVAL hCommDev AS DWORD _                            ' __in HANDLE hCommDev
 , BYREF lpCC AS COMMCONFIG  _                          ' __in_bcount(dwSize) LPCOMMCONFIG lpCC
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCommMask IMPORT "KERNEL32.DLL" ALIAS "SetCommMask" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwEvtMask AS DWORD _                           ' __in DWORD dwEvtMask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCommState IMPORT "KERNEL32.DLL" ALIAS "SetCommState" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpDCB AS DCB _                                 ' __in LPDCB lpDCB
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCommTimeouts IMPORT "KERNEL32.DLL" ALIAS "SetCommTimeouts" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpCommTimeouts AS COMMTIMEOUTS _               ' __in LPCOMMTIMEOUTS lpCommTimeouts
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TransmitCommChar IMPORT "KERNEL32.DLL" ALIAS "TransmitCommChar" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL cChar AS BYTE _                                ' __in char cChar
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WaitCommEvent IMPORT "KERNEL32.DLL" ALIAS "WaitCommEvent" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpEvtMask AS DWORD _                           ' __inout LPDWORD lpEvtMask
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetTapePosition IMPORT "KERNEL32.DLL" ALIAS "SetTapePosition" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwPositionMethod AS DWORD _                    ' __in DWORD dwPositionMethod
 , BYVAL dwPartition AS DWORD _                         ' __in DWORD dwPartition
 , BYVAL dwOffsetLow AS DWORD _                         ' __in DWORD dwOffsetLow
 , BYVAL dwOffsetHigh AS DWORD _                        ' __in DWORD dwOffsetHigh
 , BYVAL bImmediate AS LONG _                           ' __in BOOL bImmediate
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetTapePosition IMPORT "KERNEL32.DLL" ALIAS "GetTapePosition" ( _
   BYVAL hDevice AS DWORD _                             ' __in  HANDLE hDevice
 , BYVAL dwPositionType AS DWORD _                      ' __in  DWORD dwPositionType
 , BYREF lpdwPartition AS DWORD _                       ' __out LPDWORD lpdwPartition
 , BYREF lpdwOffsetLow AS DWORD _                       ' __out LPDWORD lpdwOffsetLow
 , BYREF lpdwOffsetHigh AS DWORD _                      ' __out LPDWORD lpdwOffsetHigh
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PrepareTape IMPORT "KERNEL32.DLL" ALIAS "PrepareTape" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwOperation AS DWORD _                         ' __in DWORD dwOperation
 , BYVAL bImmediate AS LONG _                           ' __in BOOL bImmediate
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION EraseTape IMPORT "KERNEL32.DLL" ALIAS "EraseTape" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwEraseType AS DWORD _                         ' __in DWORD dwEraseType
 , BYVAL bImmediate AS LONG _                           ' __in BOOL bImmediate
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CreateTapePartition IMPORT "KERNEL32.DLL" ALIAS "CreateTapePartition" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwPartitionMethod AS DWORD _                   ' __in DWORD dwPartitionMethod
 , BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WriteTapemark IMPORT "KERNEL32.DLL" ALIAS "WriteTapemark" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwTapemarkType AS DWORD _                      ' __in DWORD dwTapemarkType
 , BYVAL dwTapemarkCount AS DWORD _                     ' __in DWORD dwTapemarkCount
 , BYVAL bImmediate AS LONG _                           ' __in BOOL bImmediate
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetTapeStatus IMPORT "KERNEL32.DLL" ALIAS "GetTapeStatus" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetTapeParameters LIB "Kernel32.dll" _
    ALIAS "GetTapeParameters" (BYVAL hDevice AS DWORD, _
    BYVAL dwOperation AS DWORD, lpdwSize AS DWORD, _
    BYVAL lpTapeInformation AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetTapeParameters IMPORT "KERNEL32.DLL" ALIAS "GetTapeParameters" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwOperation AS DWORD _                         ' __in DWORD dwOperation
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 , BYREF lpTapeInformation AS ANY _                     ' __out LPVOID lpTapeInformation
 ) AS DWORD                                             ' DWORD
#ENDIF

%GET_TAPE_MEDIA_INFORMATION = 0
%GET_TAPE_DRIVE_INFORMATION = 1

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetTapeParameters LIB "Kernel32.dll" _
    ALIAS "SetTapeParameters" (BYVAL hDevice AS DWORD, _
    BYVAL dwOperation AS DWORD, BYVAL lpTapeInformation AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION SetTapeParameters IMPORT "KERNEL32.DLL" ALIAS "SetTapeParameters" ( _
   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
 , BYVAL dwOperation AS DWORD _                         ' __in DWORD dwOperation
 , BYREF lpTapeInformation AS ANY _                     ' __in LPVOID lpTapeInformation
 ) AS DWORD                                             ' DWORD
#ENDIF

%SET_TAPE_MEDIA_INFORMATION = 0
%SET_TAPE_DRIVE_INFORMATION = 1

DECLARE FUNCTION WinBeep IMPORT "KERNEL32.DLL" ALIAS "Beep" ( _
   BYVAL dwFreq AS DWORD _                              ' __in DWORD dwFreq
 , BYVAL dwDuration AS DWORD _                          ' __in DWORD dwDuration
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MulDiv IMPORT "KERNEL32.DLL" ALIAS "MulDiv" ( _
   BYVAL nNumber AS LONG _                              ' __in int nNumber
 , BYVAL nNumerator AS LONG _                           ' __in int nNumerator
 , BYVAL nDenominator AS LONG _                         ' __in int nDenominator
 ) AS LONG                                              ' int

DECLARE SUB GetSystemTime IMPORT "KERNEL32.DLL" ALIAS "GetSystemTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __out LPSYSTEMTIME lpSystemTime
 )                                                      ' void

DECLARE SUB GetSystemTimeAsFileTime IMPORT "KERNEL32.DLL" ALIAS "GetSystemTimeAsFileTime" ( _
   BYREF lpSystemTimeAsFileTime AS FILETIME _           ' __out LPFILETIME lpSystemTimeAsFileTime
 )                                                      ' void

DECLARE FUNCTION SetSystemTime IMPORT "KERNEL32.DLL" ALIAS "SetSystemTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __in CONST SYSTEMTIME *lpSystemTime
 ) AS LONG                                              ' BOOL

DECLARE SUB GetLocalTime IMPORT "KERNEL32.DLL" ALIAS "GetLocalTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __out LPSYSTEMTIME lpSystemTime
 )                                                      ' void

DECLARE FUNCTION SetLocalTime IMPORT "KERNEL32.DLL" ALIAS "SetLocalTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __in CONST SYSTEMTIME *lpSystemTime
 ) AS LONG                                              ' BOOL

DECLARE SUB GetSystemInfo IMPORT "KERNEL32.DLL" ALIAS "GetSystemInfo" ( _
   BYREF lpSystemInfo AS SYSTEM_INFO _                  ' __out LPSYSTEM_INFO lpSystemInfo
 )                                                      ' void

' enum DEP_SYSTEM_POLICY_TYPE
%DEPPolicyAlwaysOff  = 0
%DEPPolicyAlwaysOn   = 1
%DEPPolicyOptIn      = 2
%DEPPolicyOptOut     = 3
%DEPTotalPolicyCount = 4

DECLARE FUNCTION GetSystemDEPPolicy IMPORT "KERNEL32.DLL" ALIAS "GetSystemDEPPolicy" ( _
 ) AS LONG                                              ' DEP_SYSTEM_POLICY_TYPE

'#if _WIN32_WINNT >= 0x0502

%FILE_CACHE_FLAGS_DEFINED = 1

%FILE_CACHE_MAX_HARD_ENABLE      = &H00000001???
%FILE_CACHE_MAX_HARD_DISABLE     = &H00000002???
%FILE_CACHE_MIN_HARD_ENABLE      = &H00000004???
%FILE_CACHE_MIN_HARD_DISABLE     = &H00000008???

DECLARE FUNCTION SetSystemFileCacheSize IMPORT "KERNEL32.DLL" ALIAS "SetSystemFileCacheSize" ( _
   BYVAL MinimumFileCacheSize AS DWORD _                ' __in SIZE_T MinimumFileCacheSize
 , BYVAL MaximumFileCacheSize AS DWORD _                ' __in SIZE_T MaximumFileCacheSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSystemFileCacheSize IMPORT "KERNEL32.DLL" ALIAS "GetSystemFileCacheSize" ( _
   BYREF lpMinimumFileCacheSize AS DWORD _              ' __out PSIZE_T lpMinimumFileCacheSize
 , BYREF lpMaximumFileCacheSize AS DWORD _              ' __out PSIZE_T lpMaximumFileCacheSize
 , BYREF lpFlags AS DWORD _                             ' __out PDWORD lpFlags
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0502)

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION GetSystemRegistryQuota IMPORT "KERNEL32.DLL" ALIAS "GetSystemRegistryQuota" ( _
   BYREF pdwQuotaAllowed AS DWORD _                     ' __out PDWORD pdwQuotaAllowed
 , BYREF pdwQuotaUsed AS DWORD _                        ' __out PDWORD pdwQuotaUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSystemTimes IMPORT "KERNEL32.DLL" ALIAS "GetSystemTimes" ( _
   BYREF lpIdleTime AS FILETIME _                       ' __out LPFILETIME lpIdleTime
 , BYREF lpKernelTime AS FILETIME _                     ' __out LPFILETIME lpKernelTime
 , BYREF lpUserTime AS FILETIME _                       ' __out LPFILETIME lpUserTime
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

'#if _WIN32_WINNT >= 0x0501

DECLARE SUB GetNativeSystemInfo IMPORT "KERNEL32.DLL" ALIAS "GetNativeSystemInfo" ( _
   BYREF lpSystemInfo AS SYSTEM_INFO _                  ' __out LPSYSTEM_INFO lpSystemInfo
 )                                                      ' void

'#endif

DECLARE FUNCTION IsProcessorFeaturePresent IMPORT "KERNEL32.DLL" ALIAS "IsProcessorFeaturePresent" ( _
   BYVAL ProcessorFeature AS DWORD _                    ' __in DWORD ProcessorFeature
 ) AS LONG                                              ' BOOL

' // Size = 172 bytes
TYPE TIME_ZONE_INFORMATION DWORD
   Bias         AS LONG            ' LONG
   StandardName AS WSTRINGZ * 32   ' WCHAR[32]
   StandardDate AS SYSTEMTIME      ' SYSTEMTIME
   StandardBias AS LONG            ' LONG
   DaylightName AS WSTRINGZ * 32   ' WCHAR[32]
   DaylightDate AS SYSTEMTIME      ' SYSTEMTIME
   DaylightBias AS LONG            ' LONG
END TYPE

' // Size = 432 bytes
TYPE DYNAMIC_TIME_ZONE_INFORMATION DWORD
   Bias         AS LONG                  ' LONG
   StandardName AS WSTRINGZ * 32         ' WCHAR[32]
   StandardDate AS SYSTEMTIME            ' SYSTEMTIME
   StandardBias AS LONG                  ' LONG
   DaylightName AS WSTRINGZ * 32         ' WCHAR[32]
   DaylightDate AS SYSTEMTIME            ' SYSTEMTIME
   DaylightBias AS LONG                  ' LONG
   TimeZoneKeyName AS WSTRINGZ * 128     ' WCHAR
   DynamicDaylightTimeDisabled AS BYTE   ' BOOLEAN
END TYPE

DECLARE FUNCTION SystemTimeToTzSpecificLocalTime IMPORT "KERNEL32.DLL" ALIAS "SystemTimeToTzSpecificLocalTime" ( _
   BYREF lpTimeZoneInformation AS TIME_ZONE_INFORMATION _ ' __in  LPTIME_ZONE_INFORMATION lpTimeZoneInformation
 , BYREF lpUniversalTime AS SYSTEMTIME _                ' __in  LPSYSTEMTIME lpUniversalTime
 , BYREF lpLocalTime AS SYSTEMTIME _                    ' __out LPSYSTEMTIME lpLocalTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TzSpecificLocalTimeToSystemTime IMPORT "KERNEL32.DLL" ALIAS "TzSpecificLocalTimeToSystemTime" ( _
   BYREF lpTimeZoneInformation AS TIME_ZONE_INFORMATION _ ' __in  LPTIME_ZONE_INFORMATION lpTimeZoneInformation
 , BYREF lpLocalTime AS SYSTEMTIME _                    ' __in  LPSYSTEMTIME lpLocalTime
 , BYREF lpUniversalTime AS SYSTEMTIME _                ' __out LPSYSTEMTIME lpUniversalTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTimeZoneInformationForYear IMPORT "KERNEL32.DLL" ALIAS "GetTimeZoneInformationForYear" ( _
   BYVAL wYear AS WORD _                                ' __in USHORT wYear
 , BYREF pdtzi AS DYNAMIC_TIME_ZONE_INFORMATION _       ' __in_opt PDYNAMIC_TIME_ZONE_INFORMATION pdtzi
 , BYREF ptzi AS TIME_ZONE_INFORMATION _                ' __out LPTIME_ZONE_INFORMATION ptzi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTimeZoneInformation IMPORT "KERNEL32.DLL" ALIAS "GetTimeZoneInformation" ( _
   BYREF lpTimeZoneInformation AS TIME_ZONE_INFORMATION _ ' __out LPTIME_ZONE_INFORMATION lpTimeZoneInformation
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetTimeZoneInformation IMPORT "KERNEL32.DLL" ALIAS "SetTimeZoneInformation" ( _
   BYREF lpTimeZoneInformation AS TIME_ZONE_INFORMATION _ ' __in CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDynamicTimeZoneInformation IMPORT "KERNEL32.DLL" ALIAS "GetDynamicTimeZoneInformation" ( _
   BYREF lpTimeZoneInformation AS DYNAMIC_TIME_ZONE_INFORMATION _ ' __out PDYNAMIC_TIME_ZONE_INFORMATION lpTimeZoneInformation
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetDynamicTimeZoneInformation IMPORT "KERNEL32.DLL" ALIAS "SetDynamicTimeZoneInformation" ( _
   BYREF lpTimeZoneInformation AS DYNAMIC_TIME_ZONE_INFORMATION _ ' __in CONST DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation
 ) AS LONG                                              ' BOOL

'//
'// Routines to convert back and forth between system time and file time
'//

DECLARE FUNCTION SystemTimeToFileTime IMPORT "KERNEL32.DLL" ALIAS "SystemTimeToFileTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __in  CONST SYSTEMTIME *lpSystemTime
 , BYREF lpFileTime AS FILETIME _                       ' __out LPFILETIME lpFileTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FileTimeToLocalFileTime IMPORT "KERNEL32.DLL" ALIAS "FileTimeToLocalFileTime" ( _
   BYREF lpFileTime AS FILETIME _                       ' __in  CONST FILETIME *lpFileTime
 , BYREF lpLocalFileTime AS FILETIME _                  ' __out LPFILETIME lpLocalFileTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LocalFileTimeToFileTime IMPORT "KERNEL32.DLL" ALIAS "LocalFileTimeToFileTime" ( _
   BYREF lpLocalFileTime AS FILETIME _                  ' __in  CONST FILETIME *lpLocalFileTime
 , BYREF lpFileTime AS FILETIME _                       ' __out LPFILETIME lpFileTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FileTimeToSystemTime IMPORT "KERNEL32.DLL" ALIAS "FileTimeToSystemTime" ( _
   BYREF lpFileTime AS FILETIME _                       ' __in  CONST FILETIME *lpFileTime
 , BYREF lpSystemTime AS SYSTEMTIME _                   ' __out LPSYSTEMTIME lpSystemTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CompareFileTime IMPORT "KERNEL32.DLL" ALIAS "CompareFileTime" ( _
   BYREF lpFileTime1 AS FILETIME _                      ' __in CONST FILETIME *lpFileTime1
 , BYREF lpFileTime2 AS FILETIME _                      ' __in CONST FILETIME *lpFileTime2
 ) AS LONG                                              ' LONG

DECLARE FUNCTION FileTimeToDosDateTime IMPORT "KERNEL32.DLL" ALIAS "FileTimeToDosDateTime" ( _
   BYREF lpFileTime2 AS FILETIME _                      ' __in  CONST FILETIME *lpFileTime
 , BYREF lpFatDate AS WORD _                            ' __out LPWORD lpFatDate
 , BYREF lpFatTime AS WORD _                            ' __out LPWORD lpFatTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DosDateTimeToFileTime IMPORT "KERNEL32.DLL" ALIAS "DosDateTimeToFileTime" ( _
   BYVAL wFatDate AS WORD _                             ' __in  WORD wFatDate
 , BYVAL wFatTime AS WORD _                             ' __in  WORD wFatTime
 , BYREF lpFileTime AS FILETIME _                       ' __out LPFILETIME lpFileTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTickCount IMPORT "KERNEL32.DLL" ALIAS "GetTickCount" ( _
 ) AS DWORD                                             ' DWORD

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
DECLARE FUNCTION GetTickCount64 IMPORT "KERNEL32.DLL" ALIAS "GetTickCount64" ( _
 ) AS QUAD                                              ' ULONGULONG
#ENDIF
'#endif

DECLARE FUNCTION SetSystemTimeAdjustment IMPORT "KERNEL32.DLL" ALIAS "SetSystemTimeAdjustment" ( _
   BYVAL dwTimeAdjustment AS DWORD  _                   ' __in DWORD dwTimeAdjustment
 , BYVAL bTimeAdjustmentDisabled AS LONG _              ' __in BOOL  bTimeAdjustmentDisabled
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSystemTimeAdjustment IMPORT "KERNEL32.DLL" ALIAS "GetSystemTimeAdjustment" ( _
   BYREF lpTimeAdjustment AS DWORD _                    ' __out PDWORD lpTimeAdjustment
 , BYREF lpTimeIncrement AS DWORD _                     ' __out PDWORD lpTimeIncrement
 , BYREF lpTimeAdjustmentDisabled AS LONG _             ' __out PBOOL  lpTimeAdjustmentDisabled
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FormatMessageA LIB "Kernel32.dll" ALIAS "FormatMessageA" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS ASCIIZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD
' // Note: The Arguments parameter should be BYREF ANY, but it has been declared as
' // BYVAL DWORD for compatibility with the PowerBASIC include files to no break
' // existing code.
#ELSE
DECLARE FUNCTION FormatMessageA IMPORT "KERNEL32.DLL" ALIAS "FormatMessageA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpSource AS ANY _                              ' __in LPCVOID lpSource
 , BYVAL dwMessageId AS DWORD _                         ' __in DWORD dwMessageId
 , BYVAL dwLanguageId AS DWORD _                        ' __in DWORD dwLanguageId
 , BYREF lpBuffer AS ASCIIZ _                           ' __inout LPSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYVAL Arguments AS DWORD _                           ' __in va_list *Arguments
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FormatMessageW LIB "Kernel32.dll" ALIAS "FormatMessageW" _
    (BYVAL dwFlags AS DWORD, BYVAL lpSource AS DWORD, _
    BYVAL dwMessageId AS DWORD, BYVAL dwLanguageId AS DWORD, _
    lpBuffer AS WSTRINGZ, BYVAL nSize AS DWORD, BYVAL Arguments AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION FormatMessageW IMPORT "KERNEL32.DLL" ALIAS "FormatMessageW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpSource AS ANY _                              ' __in LPCVOID lpSource
 , BYVAL dwMessageId AS DWORD _                         ' __in DWORD dwMessageId
 , BYVAL dwLanguageId AS DWORD _                        ' __in DWORD dwLanguageId
 , BYREF lpBuffer AS WSTRINGZ _                         ' __inout LPWSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYVAL Arguments AS DWORD _                           ' __in va_list *Arguments
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO FormatMessage = FormatMessageW
#ELSE
   MACRO FormatMessage = FormatMessageA
#ENDIF

%FORMAT_MESSAGE_ALLOCATE_BUFFER = &H00000100???
%FORMAT_MESSAGE_IGNORE_INSERTS  = &H00000200???
%FORMAT_MESSAGE_FROM_STRING     = &H00000400???
%FORMAT_MESSAGE_FROM_HMODULE    = &H00000800???
%FORMAT_MESSAGE_FROM_SYSTEM     = &H00001000???
%FORMAT_MESSAGE_ARGUMENT_ARRAY  = &H00002000???
%FORMAT_MESSAGE_MAX_WIDTH_MASK  = &H000000FF???

DECLARE FUNCTION CreatePipe IMPORT "KERNEL32.DLL" ALIAS "CreatePipe" ( _
   BYREF hReadPipe AS DWORD _                           ' __out PHANDLE hReadPipe
 , BYREF hWritePipe AS DWORD _                          ' __out PHANDLE hWritePipe
 , BYREF lpPipeAttributes AS SECURITY_ATTRIBUTES _      ' __in  LPSECURITY_ATTRIBUTES lpPipeAttributes
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConnectNamedPipe IMPORT "KERNEL32.DLL" ALIAS "ConnectNamedPipe" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in HANDLE hNamedPipe
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __in LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DisconnectNamedPipe IMPORT "KERNEL32.DLL" ALIAS "DisconnectNamedPipe" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in HANDLE hNamedPipe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetNamedPipeHandleState IMPORT "KERNEL32.DLL" ALIAS "SetNamedPipeHandleState" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in HANDLE hNamedPipe
 , BYREF lpMode AS DWORD _                              ' __in LPDWORD lpMode
 , BYREF lpMaxCollectionCount AS DWORD _                ' __in LPDWORD lpMaxCollectionCount
 , BYREF lpCollectDataTimeout AS DWORD _                ' __in LPDWORD lpCollectDataTimeout
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeInfo IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeInfo" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in HANDLE hNamedPipe
 , BYREF lpFlags AS DWORD _                             ' __out LPDWORD lpFlags
 , BYREF lpOutBufferSize AS DWORD _                     ' __out LPDWORD lpOutBufferSize
 , BYREF lpInBufferSize AS DWORD _                      ' __out LPDWORD lpInBufferSize
 , BYREF lpMaxInstances AS DWORD _                      ' __out LPDWORD lpMaxInstances
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PeekNamedPipe LIB "Kernel32.dll" ALIAS "PeekNamedPipe" _
    (BYVAL hNamedPipe AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nBufferSize AS DWORD, lpBytesRead AS DWORD, _
    lpTotalBytesAvail AS DWORD, lpBytesLeftThisMessage AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PeekNamedPipe IMPORT "KERNEL32.DLL" ALIAS "PeekNamedPipe" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in  HANDLE hNamedPipe
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nBufferSize AS DWORD _                         ' __in  DWORD nBufferSize
 , BYREF lpBytesRead AS DWORD _                         ' __out LPDWORD lpBytesRead
 , BYREF lpTotalBytesAvail AS DWORD _                   ' __out LPDWORD lpTotalBytesAvail
 , BYREF lpBytesLeftThisMessage AS DWORD _              ' __out LPDWORD lpBytesLeftThisMessage
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TransactNamedPipe LIB "Kernel32.dll" _
    ALIAS "TransactNamedPipe" (BYVAL hNamedPipe AS DWORD, _
    BYVAL lpInBuffer AS DWORD, BYVAL nInBufferSize AS DWORD, _
    BYVAL lpOutBuffer AS DWORD, BYVAL nOutBufferSize AS DWORD, _
    lpBytesRead AS DWORD, lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION TransactNamedPipe IMPORT "KERNEL32.DLL" ALIAS "TransactNamedPipe" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in  HANDLE hNamedPipe
 , BYREF lpInBuffer AS ANY _                            ' __in  LPVOID lpInBuffer
 , BYVAL nInBufferSize AS DWORD _                       ' __in  DWORD nInBufferSize
 , BYREF lpOutBuffer AS ANY _                           ' __out LPVOID lpOutBuffer
 , BYVAL nOutBufferSize AS DWORD _                      ' __in  DWORD nOutBufferSize
 , BYREF lpBytesRead AS DWORD _                         ' __out LPDWORD lpBytesRead
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CreateMailslotA IMPORT "KERNEL32.DLL" ALIAS "CreateMailslotA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL nMaxMessageSize AS DWORD _                     ' __in DWORD nMaxMessageSize
 , BYVAL lReadTimeout AS DWORD _                        ' __in DWORD lReadTimeout
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateMailslotW IMPORT "KERNEL32.DLL" ALIAS "CreateMailslotW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL nMaxMessageSize AS DWORD _                     ' __in DWORD nMaxMessageSize
 , BYVAL lReadTimeout AS DWORD _                        ' __in DWORD lReadTimeout
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateMailslot = CreateMailslotW
#ELSE
   MACRO CreateMailslot = CreateMailslotA
#ENDIF

DECLARE FUNCTION GetMailslotInfo IMPORT "KERNEL32.DLL" ALIAS "GetMailslotInfo" ( _
   BYVAL hMailslot AS DWORD _                           ' __in  HANDLE hMailslot
 , BYREF lpMaxMessageSize AS DWORD _                    ' __out LPDWORD lpMaxMessageSize
 , BYREF lpNextSize AS DWORD _                          ' __out LPDWORD lpNextSize
 , BYREF lpMessageCount AS DWORD _                      ' __out LPDWORD lpMessageCount
 , BYREF lpReadTimeout AS DWORD _                       ' __out LPDWORD lpReadTimeout
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMailslotInfo IMPORT "KERNEL32.DLL" ALIAS "SetMailslotInfo" ( _
   BYVAL hMailslot AS DWORD  _                          ' __in HANDLE hMailslot
 , BYVAL lReadTimeout AS DWORD _                        ' __in DWORD lReadTimeout
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MapViewOfFile IMPORT "KERNEL32.DLL" ALIAS "MapViewOfFile" ( _
   BYVAL hFileMappingObject AS DWORD _                  ' __in HANDLE hFileMappingObject
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwFileOffsetHigh AS DWORD _                    ' __in DWORD dwFileOffsetHigh
 , BYVAL dwFileOffsetLow AS DWORD _                     ' __in DWORD dwFileOffsetLow
 , BYVAL dwNumberOfBytesToMap AS DWORD _                ' __in SIZE_T dwNumberOfBytesToMap
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION FlushViewOfFile IMPORT "KERNEL32.DLL" ALIAS "FlushViewOfFile" ( _
   BYVAL lpBaseAddress AS DWORD _                       ' __in LPCVOID lpBaseAddress
 , BYVAL dwNumberOfBytesToFlush AS DWORD _              ' __in SIZE_T dwNumberOfBytesToFlush
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnmapViewOfFile IMPORT "KERNEL32.DLL" ALIAS "UnmapViewOfFile" ( _
   BYVAL lpBaseAddress AS DWORD _                       ' __in LPCVOID lpBaseAddress
 ) AS LONG                                              ' BOOL

'//
'// File Encryption API
'//

DECLARE FUNCTION EncryptFileA IMPORT "ADVAPI32.DLL" ALIAS "EncryptFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EncryptFileW IMPORT "ADVAPI32.DLL" ALIAS "EncryptFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EncryptFile = EncryptFileW
#ELSE
   MACRO EncryptFile = EncryptFileA
#ENDIF

DECLARE FUNCTION DecryptFileA IMPORT "ADVAPI32.DLL" ALIAS "DecryptFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DecryptFileW IMPORT "ADVAPI32.DLL" ALIAS "DecryptFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DecryptFile = DecryptFileW
#ELSE
   MACRO DecryptFile = DecryptFileA
#ENDIF

'//
'//  Encryption Status Value
'//

%FILE_ENCRYPTABLE               = 0
%FILE_IS_ENCRYPTED              = 1
%FILE_SYSTEM_ATTR               = 2
%FILE_ROOT_DIR                  = 3
%FILE_SYSTEM_DIR                = 4
%FILE_UNKNOWN                   = 5
%FILE_SYSTEM_NOT_SUPPORT        = 6
%FILE_USER_DISALLOWED           = 7
%FILE_READ_ONLY                 = 8
%FILE_DIR_DISALLOWED            = 9

DECLARE FUNCTION FileEncryptionStatusA IMPORT "ADVAPI32.DLL" ALIAS "FileEncryptionStatusA" ( _
   BYREF lpFileName AS ASCIIZ  _                        ' __in  LPCSTR lpFileName
 , BYREF lpStatus AS DWORD _                            ' __out LPDWORD  lpStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FileEncryptionStatusW IMPORT "ADVAPI32.DLL" ALIAS "FileEncryptionStatusW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF lpStatus AS DWORD _                            ' __out LPDWORD  lpStatus
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FileEncryptionStatus = FileEncryptionStatusW
#ELSE
   MACRO FileEncryptionStatus = FileEncryptionStatusA
#ENDIF

'//
'// Currently defined recovery flags
'//

%EFS_USE_RECOVERY_KEYS = &H1

'typedef
'DWORD
'(WINAPI *PFE_EXPORT_FUNC)(
'    __in_bcount(ulLength) PBYTE pbData,
'    __in PVOID pvCallbackContext,
'    __in     ULONG ulLength
'    );

'typedef
'DWORD
'(WINAPI *PFE_IMPORT_FUNC)(
'    __out_bcount_part(*ulLength, *ulLength) PBYTE pbData,
'    __in PVOID pvCallbackContext,
'    __inout  PULONG ulLength
'    );


'//
'//  OpenRaw flag values
'//

%CREATE_FOR_IMPORT  = 1
%CREATE_FOR_DIR     = 2
%OVERWRITE_HIDDEN   = 4
%EFSRPC_SECURE_ONLY = 8

DECLARE FUNCTION OpenEncryptedFileRawA IMPORT "ADVAPI32.DLL" ALIAS "OpenEncryptedFileRawA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG    ulFlags
 , BYREF pvContext AS ANY _                             ' __out PVOID   *pvContext
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION OpenEncryptedFileRawW IMPORT "ADVAPI32.DLL" ALIAS "OpenEncryptedFileRawW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG    ulFlags
 , BYREF pvContext AS ANY _                             ' __out PVOID   *pvContext
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO OpenEncryptedFileRaw = OpenEncryptedFileRawW
#ELSE
   MACRO OpenEncryptedFileRaw = OpenEncryptedFileRawA
#ENDIF

DECLARE FUNCTION ReadEncryptedFileRaw IMPORT "ADVAPI32.DLL" ALIAS "ReadEncryptedFileRaw" ( _
   BYVAL pfExportCallback AS DWORD _                    ' __in PFE_EXPORT_FUNC pfExportCallback
 , BYVAL pvCallbackContext AS DWORD _                   ' __in PVOID           pvCallbackContext
 , BYVAL pvContext AS DWORD _                           ' __in PVOID           pvContext
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WriteEncryptedFileRaw IMPORT "ADVAPI32.DLL" ALIAS "WriteEncryptedFileRaw" ( _
   BYVAL pfImportCallback AS DWORD _                    ' __in PFE_IMPORT_FUNC pfImportCallback
 , BYVAL pvCallbackContext AS DWORD _                   ' __in PVOID           pvCallbackContext
 , BYVAL pvContext AS DWORD _                           ' __in PVOID           pvContext
 ) AS DWORD                                             ' DWORD

DECLARE SUB CloseEncryptedFileRaw IMPORT "ADVAPI32.DLL" ALIAS "CloseEncryptedFileRaw" ( _
   BYVAL pvContext AS DWORD _                           ' __in PVOID           pvContext
 )                                                      ' void

'//
'// _l Compat Functions
'//

DECLARE FUNCTION lstrcmpA IMPORT "KERNEL32.DLL" ALIAS "lstrcmpA" ( _
   BYREF lpString1 AS ASCIIZ _                          ' __in LPCSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 ) AS LONG                                              ' int

DECLARE FUNCTION lstrcmpW IMPORT "KERNEL32.DLL" ALIAS "lstrcmpW" ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO lstrcmp = lstrcmpW
#ELSE
   MACRO lstrcmp = lstrcmpA
#ENDIF

DECLARE FUNCTION lstrcmpiA IMPORT "KERNEL32.DLL" ALIAS "lstrcmpiA" ( _
   BYREF lpString1 AS ASCIIZ _                          ' __in LPCSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 ) AS LONG                                              ' int

DECLARE FUNCTION lstrcmpiW IMPORT "KERNEL32.DLL" ALIAS "lstrcmpiW" ( _
   BYREF lpString1 AS WSTRINGZ _                         ' __in LPCWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                         ' __in LPCWSTR lpString2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO lstrcmpi = lstrcmpiW
#ELSE
   MACRO lstrcmpi = lstrcmpiA
#ENDIF

DECLARE FUNCTION lstrcpynA IMPORT "KERNEL32.DLL" ALIAS "lstrcpynA" ( _
   BYREF lpString1 AS ASCIIZ _                          ' __out LPSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 , BYVAL iMaxLength AS LONG _                           ' __in int iMaxLength
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION lstrcpynW IMPORT "KERNEL32.DLL" ALIAS "lstrcpynW" ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __out LPWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL iMaxLength AS LONG _                           ' __in int iMaxLength
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO lstrcpyn = lstrcpynW
#ELSE
   MACRO lstrcpyn = lstrcpynA
#ENDIF

DECLARE FUNCTION lstrcpyA IMPORT "KERNEL32.DLL" ALIAS "lstrcpyA" ( _
   BYREF lpString1 AS ASCIIZ _                          ' __out LPSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in  LPCSTR lpString2
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION lstrcpyW IMPORT "KERNEL32.DLL" ALIAS "lstrcpyW" ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __out LPWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in  LPCWSTR lpString2
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO lstrcpy = lstrcpyW
#ELSE
   MACRO lstrcpy = lstrcpyA
#ENDIF

DECLARE FUNCTION lstrcatA IMPORT "KERNEL32.DLL" ALIAS "lstrcatA" ( _
   BYREF lpString1 AS ASCIIZ _                          ' __inout LPSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION lstrcatW IMPORT "KERNEL32.DLL" ALIAS "lstrcatW" ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __inout LPWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO lstrcat = lstrcatW
#ELSE
   MACRO lstrcat = lstrcatA
#ENDIF

DECLARE FUNCTION lstrlenA IMPORT "KERNEL32.DLL" ALIAS "lstrlenA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS LONG                                              ' int

DECLARE FUNCTION lstrlenw IMPORT "KERNEL32.DLL" ALIAS "lstrlenW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO lstrlen = lstrlenw
#ELSE
   MACRO lstrlen = lstrlenA
#ENDIF

DECLARE FUNCTION OpenFile IMPORT "KERNEL32.DLL" ALIAS "OpenFile" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYREF lpReOpenBuff AS OFSTRUCT _                     ' __inout LPOFSTRUCT lpReOpenBuff
 , BYVAL uStyle AS DWORD _                              ' __in UINT uStyle
 ) AS DWORD                                             ' HFILE

DECLARE FUNCTION lopen IMPORT "KERNEL32.DLL" ALIAS "_lopen" ( _
   BYREF lpPathName0 AS ASCIIZ _                        ' __in LPCSTR lpPathName0
 , BYVAL iReadWrite AS LONG _                           ' __in int iReadWrite
 ) AS DWORD                                             ' HFILE

DECLARE FUNCTION lcreat IMPORT "KERNEL32.DLL" ALIAS "_lcreat" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 , BYVAL iAttribute AS LONG _                           ' __in int  iAttribute
 ) AS DWORD                                             ' HFILE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION lread LIB "Kernel32.dll" ALIAS "_lread" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL uBytes AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION lread IMPORT "KERNEL32.DLL" ALIAS "_lread" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL uBytes AS DWORD _                              ' __in UINT uBytes
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION lwrite LIB "Kernel32.dll" ALIAS "_lwrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL uBytes AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION lwrite IMPORT "KERNEL32.DLL" ALIAS "_lwrite" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 , BYREF lpBuffer AS ASCIIZ _                           ' __in LPCCH lpBuffer
 , BYVAL uBytes AS DWORD _                              ' __in UINT uBytes
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION hread LIB "Kernel32.dll" ALIAS "_hread" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL lBytes AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION hread IMPORT "KERNEL32.DLL" ALIAS "_hread" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL lBytes AS LONG _                               ' __in long lBytes
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION hwrite LIB "Kernel32.dll" ALIAS "_hwrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, BYVAL lBytes AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION hwrite IMPORT "KERNEL32.DLL" ALIAS "_hwrite" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 , BYREF lpBuffer AS ASCIIZ _                           ' __in LPCCH lpBuffer
 , BYVAL lBytes AS LONG _                               ' __in long lBytes
 ) AS LONG                                              ' LONG
#ENDIF

DECLARE FUNCTION lclose IMPORT "KERNEL32.DLL" ALIAS "_lclose" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 ) AS DWORD                                             ' HFILE

DECLARE FUNCTION llseek IMPORT "KERNEL32.DLL" ALIAS "_llseek" ( _
   BYVAL hFile AS DWORD _                               ' __in HFILE hFile
 , BYVAL lOffset AS LONG _                              ' __in LONG lOffset
 , BYVAL iOrigin AS LONG _                              ' __in int iOrigin
 ) AS LONG                                              ' LONG

DECLARE FUNCTION IsTextUnicode IMPORT "ADVAPI32.DLL" ALIAS "IsTextUnicode" ( _
   BYVAL lpv AS DWORD _                                 ' __in CONST VOID* lpv
 , BYVAL iSize AS LONG _                                ' __in int iSize
 , OPTIONAL BYREF lpiResult AS LONG _                   ' __inout LPINT lpiResult
 ) AS LONG                                              ' BOOL

%FLS_OUT_OF_INDEXES = &HFFFFFFFF???   ' ((DWORD)0xFFFFFFFF)

DECLARE FUNCTION FlsAlloc IMPORT "KERNEL32.DLL" ALIAS "FlsAlloc" ( _
   BYVAL lpCallback AS DWORD _                          ' __in PFLS_CALLBACK_FUNCTION lpCallback
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION FlsGetValue IMPORT "KERNEL32.DLL" ALIAS "FlsGetValue" ( _
   BYVAL dwFlsIndex AS DWORD _                          ' __in DWORD dwFlsIndex
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION FlsSetValue IMPORT "KERNEL32.DLL" ALIAS "FlsSetValue" ( _
   BYVAL dwFlsIndex AS DWORD _                          ' __in DWORD dwFlsIndex
 , OPTIONAL BYVAL lpFlsData AS DWORD _                  ' __in_opt PVOID lpFlsData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlsFree IMPORT "KERNEL32.DLL" ALIAS "FlsFree" ( _
   BYVAL dwFlsIndex AS DWORD _                          ' __in DWORD dwFlsIndex
 ) AS LONG                                              ' BOOL

%TLS_OUT_OF_INDEXES = &HFFFFFFFF???   ' ((DWORD)0xFFFFFFFF)

DECLARE FUNCTION TlsAlloc IMPORT "KERNEL32.DLL" ALIAS "TlsAlloc" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION TlsGetValue IMPORT "KERNEL32.DLL" ALIAS "TlsGetValue" ( _
   BYVAL dwTlsIndex AS DWORD _                          ' __in DWORD dwTlsIndex
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION TlsSetValue IMPORT "KERNEL32.DLL" ALIAS "TlsSetValue" ( _
   BYVAL dwTlsIndex AS DWORD _                          ' __in DWORD  dwTlsIndex
 , BYREF lpTlsValue AS ANY _                            ' __in LPVOID lpTlsValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TlsFree IMPORT "KERNEL32.DLL" ALIAS "TlsFree" ( _
   BYVAL dwTlsIndex AS DWORD _                          ' __in DWORD dwTlsIndex
 ) AS LONG                                              ' BOOL

'typedef
'VOID
'(WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(
'    __in    DWORD dwErrorCode,
'    __in    DWORD dwNumberOfBytesTransfered,
'    __inout LPOVERLAPPED lpOverlapped
'    );

DECLARE FUNCTION SleepEx IMPORT "KERNEL32.DLL" ALIAS "SleepEx" ( _
   BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 , BYVAL bAlertable AS LONG _                           ' __in BOOL  bAlertable
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WaitForSingleObjectEx IMPORT "KERNEL32.DLL" ALIAS "WaitForSingleObjectEx" ( _
   BYVAL hHandle AS DWORD _                             ' __in HANDLE hHandle
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD  dwMilliseconds
 , BYVAL bAlertable AS LONG _                           ' __in BOOL   bAlertable
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WaitForMultipleObjectsEx IMPORT "KERNEL32.DLL" ALIAS "WaitForMultipleObjectsEx" ( _
   BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF lpHandles AS DWORD _                           ' __in CONST HANDLE *lpHandles
 , BYVAL bWaitAll AS LONG _                             ' __in BOOL  bWaitAll
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 , BYVAL bAlertable AS LONG _                           ' __in BOOL  bAlertable
 ) AS DWORD                                             ' DWORD

'#if(_WIN32_WINNT >= 0x0400)

DECLARE FUNCTION SignalObjectAndWait IMPORT "KERNEL32.DLL" ALIAS "SignalObjectAndWait" ( _
   BYVAL hObjectToSignal AS DWORD _                     ' __in HANDLE hObjectToSignal
 , BYVAL hObjectToWaitOn AS DWORD _                     ' __in HANDLE hObjectToWaitOn
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD  dwMilliseconds
 , BYVAL bAlertable AS LONG _                           ' __in BOOL   bAlertable
 ) AS DWORD                                             ' DWORD

'#endif /* _WIN32_WINNT >= 0x0400 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadFileEx LIB "Kernel32.dll" ALIAS "ReadFileEx" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadFileEx IMPORT "KERNEL32.DLL" ALIAS "ReadFileEx" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in DWORD nNumberOfBytesToRead
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteFileEx LIB "Kernel32.dll" ALIAS "WriteFileEx" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteFileEx IMPORT "KERNEL32.DLL" ALIAS "WriteFileEx" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __in LPCVOID lpBuffer
 , BYVAL nNumberOfBytesToWrite AS DWORD _               ' __in DWORD nNumberOfBytesToWrite
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION BackupRead LIB "Kernel32.dll" ALIAS "BackupRead" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToRead AS DWORD, lpNumberOfBytesRead AS DWORD, _
    BYVAL bAbort AS LONG, BYVAL bProcessSecurity AS LONG, _
    lpContext AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION BackupRead IMPORT "KERNEL32.DLL" ALIAS "BackupRead" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __out LPBYTE lpBuffer
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in  DWORD nNumberOfBytesToRead
 , BYREF lpNumberOfBytesRead AS DWORD _                 ' __out LPDWORD lpNumberOfBytesRead
 , BYVAL bAbort AS LONG _                               ' __in  BOOL bAbort
 , BYVAL bProcessSecurity AS LONG  _                    ' __in  BOOL bProcessSecurity
 , BYREF lpContext AS DWORD _                           ' __out LPVOID *lpContext
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION BackupSeek LIB "Kernel32.dll" ALIAS "BackupSeek" _
    (BYVAL hFile AS DWORD, BYVAL dwLowBytesToSeek AS DWORD, _
    BYVAL dwHighBytesToSeek AS DWORD, lpdwLowByteSeeked AS DWORD, _
    lpdwHighByteSeeked AS LONG, lpContext AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION BackupSeek IMPORT "KERNEL32.DLL" ALIAS "BackupSeek" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYVAL dwLowBytesToSeek AS DWORD _                    ' __in  DWORD  dwLowBytesToSeek
 , BYVAL dwHighBytesToSeek AS DWORD _                   ' __in  DWORD  dwHighBytesToSeek
 , BYREF lpdwLowByteSeeked AS DWORD _                   ' __out LPDWORD lpdwLowByteSeeked
 , BYREF lpdwHighByteSeeked AS DWORD _                  ' __out LPDWORD lpdwHighByteSeeked
 , BYVAL lpContext AS DWORD _                           ' __in  LPVOID *lpContext
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION BackupWrite LIB "Kernel32.dll" ALIAS "BackupWrite" _
    (BYVAL hFile AS DWORD, BYVAL lpBuffer AS DWORD, _
    BYVAL nNumberOfBytesToWrite AS DWORD, lpNumberOfBytesWritten AS DWORD, _
    BYVAL bAbort AS LONG, BYVAL bProcessSecurity AS LONG, _
    lpContext AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION BackupWrite IMPORT "KERNEL32.DLL" ALIAS "BackupWrite" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpBuffer AS ANY _                              ' __in  LPBYTE lpBuffer
 , BYVAL nNumberOfBytesToWrite AS DWORD _               ' __in  DWORD nNumberOfBytesToWrite
 , BYREF lpNumberOfBytesWritten AS DWORD _              ' __out LPDWORD lpNumberOfBytesWritten
 , BYVAL bAbort AS LONG _                               ' __in  BOOL bAbort
 , BYVAL bProcessSecurity AS LONG _                     ' __in  BOOL bProcessSecurity
 , BYVAL lpContext AS DWORD _                           ' __in  LPVOID *lpContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//
'//  Stream id structure
'//
' // Size = 24 bytes
TYPE WIN32_STREAM_ID DWORD
   dwStreamID         AS DWORD      ' DWORD          dwStreamId
   dwStreamAttributes AS DWORD      ' DWORD          dwStreamAttributes
   qsize              AS QUAD       ' LARGE_INTEGER  Size
   dwStreamNameSize   AS DWORD      ' DWORD          dwStreamNameSize
   cStreamName(0)     AS WORD       ' WCHAR          cStreamName[ ANYSIZE_ARRAY ]
END TYPE

'//
'//  Stream Ids
'//

%BACKUP_INVALID          = &H00000000???
%BACKUP_DATA             = &H00000001???
%BACKUP_EA_DATA          = &H00000002???
%BACKUP_SECURITY_DATA    = &H00000003???
%BACKUP_ALTERNATE_DATA   = &H00000004???
%BACKUP_LINK             = &H00000005???
%BACKUP_PROPERTY_DATA    = &H00000006???
%BACKUP_OBJECT_ID        = &H00000007???
%BACKUP_REPARSE_DATA     = &H00000008???
%BACKUP_SPARSE_BLOCK     = &H00000009???
%BACKUP_TXFS_DATA        = &H0000000a???

'//
'//  Stream Attributes
'//

%STREAM_NORMAL_ATTRIBUTE         = &H00000000???
%STREAM_MODIFIED_WHEN_READ       = &H00000001???
%STREAM_CONTAINS_SECURITY        = &H00000002???
%STREAM_CONTAINS_PROPERTIES      = &H00000004???
%STREAM_SPARSE_ATTRIBUTE         = &H00000008???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadFileScatter LIB "Kernel32.dll" ALIAS "ReadFileScatter" _
    (BYVAL hFile AS DWORD, BYVAL aSegmentArray AS FILE_SEGMENT_ELEMENT PTR, _
    BYVAL nNumberOfBytesToRead AS DWORD, BYVAL lpReserved AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION ReadFileScatter IMPORT "KERNEL32.DLL" ALIAS "ReadFileScatter" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF aSegmentArray AS FILE_SEGMENT_ELEMENT _        ' __in FILE_SEGMENT_ELEMENT aSegmentArray[]
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in DWORD nNumberOfBytesToRead
 , BYVAL lpReserved AS DWORD _                          ' __in LPDWORD lpReserved
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteFileGather LIB "Kernel32.dll" ALIAS "WriteFileGather" _
    (BYVAL hFile AS DWORD, BYVAL aSegmentArray AS FILE_SEGMENT_ELEMENT PTR, _
    BYVAL nNumberOfBytesToWrite AS DWORD, BYVAL lpReserved AS DWORD, _
    lpOverlapped AS OVERLAPPED) AS LONG
#ELSE
DECLARE FUNCTION WriteFileGather IMPORT "KERNEL32.DLL" ALIAS "WriteFileGather" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF aSegmentArray AS FILE_SEGMENT_ELEMENT _        ' __in FILE_SEGMENT_ELEMENT aSegmentArray[]
 , BYVAL nNumberOfBytesToWrite AS DWORD _               ' __in DWORD nNumberOfBytesToWrite
 , BYVAL lpReserved AS DWORD _                          ' __in LPDWORD lpReserved
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL
#ENDIF

'//
'// Dual Mode API below this line. Dual Mode Structures also included.
'//

%STARTF_USESHOWWINDOW    = &H00000001???
%STARTF_USESIZE          = &H00000002???
%STARTF_USEPOSITION      = &H00000004???
%STARTF_USECOUNTCHARS    = &H00000008???
%STARTF_USEFILLATTRIBUTE = &H00000010???
%STARTF_RUNFULLSCREEN    = &H00000020???     ' ignored for non-x86 platforms
%STARTF_FORCEONFEEDBACK  = &H00000040???
%STARTF_FORCEOFFFEEDBACK = &H00000080???
%STARTF_USESTDHANDLES    = &H00000100???
'#if(WINVER >= 0x0400)
%STARTF_USEHOTKEY        = &H00000200???
%STARTF_TITLEISLINKNAME  = &H00000800???
%STARTF_TITLEISAPPID     = &H00001000???
%STARTF_PREVENTPINNING   = &H00002000???
'#endif /* WINVER >= 0x0400 */

' // Size = 68 bytes
TYPE STARTUPINFOA DWORD FILL
   cb              AS DWORD        ' DWORD   cb
   lpReserved      AS ASCIIZ PTR   ' LPSTR   lpReserved
   lpDesktop       AS ASCIIZ PTR   ' LPSTR   lpDesktop
   lpTitle         AS ASCIIZ PTR   ' LPSTR   lpTitle
   dwX             AS DWORD        ' DWORD   dwX
   dwY             AS DWORD        ' DWORD   dwY
   dwXSize         AS DWORD        ' DWORD   dwXSize
   dwYSize         AS DWORD        ' DWORD   dwYSize
   dwXCountChars   AS DWORD        ' DWORD   dwXCountChars
   dwYCountChars   AS DWORD        ' DWORD   dwYCountChars
   dwFillAttribute AS DWORD        ' DWORD   dwFillAttribute
   dwFlags         AS DWORD        ' DWORD   dwFlags
   wShowWindow     AS WORD         ' WORD    wShowWindow
   cbReserved2     AS WORD         ' WORD    cbReserved2
   lpReserved2     AS BYTE PTR     ' LPBYTE  lpReserved2
   hStdInput       AS DWORD        ' HANDLE  hStdInput
   hStdOutput      AS DWORD        ' HANDLE  hStdOutput
   hStdError       AS DWORD        ' HANDLE  hStdError
END TYPE

' // Size = 68 bytes
TYPE STARTUPINFOW DWORD FILL
   cb              AS DWORD          ' DWORD   cb
   lpReserved      AS WSTRINGZ PTR   ' LPWSTR  lpReserved
   lpDesktop       AS WSTRINGZ PTR   ' LPWSTR  lpDesktop
   lpTitle         AS WSTRINGZ PTR   ' LPWSTR  lpTitle
   dwX             AS DWORD          ' DWORD   dwX
   dwY             AS DWORD          ' DWORD   dwY
   dwXSize         AS DWORD          ' DWORD   dwXSize
   dwYSize         AS DWORD          ' DWORD   dwYSize
   dwXCountChars   AS DWORD          ' DWORD   dwXCountChars
   dwYCountChars   AS DWORD          ' DWORD   dwYCountChars
   dwFillAttribute AS DWORD          ' DWORD   dwFillAttribute
   dwFlags         AS DWORD          ' DWORD   dwFlags
   wShowWindow     AS WORD           ' WORD    wShowWindow
   cbReserved2     AS WORD           ' WORD    cbReserved2
   lpReserved2     AS BYTE PTR       ' LPBYTE  lpReserved2
   hStdInput       AS DWORD          ' HANDLE  hStdInput
   hStdOutput      AS DWORD          ' HANDLE  hStdOutput
   hStdError       AS DWORD          ' HANDLE  hStdError
END TYPE

#IF %DEF(%UNICODE)
   MACRO STARTUPINFO = STARTUPINFOW
#ELSE
   MACRO STARTUPINFO = STARTUPINFOA
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)

UNION STARTUPINFOEXA_UNION
   StartupInfo AS STARTUPINFOA
   ' // For compatibility with the PB declares
   StartupInfoValue AS STARTUPINFOA
END UNION

' // Size = 72 bytes
TYPE STARTUPINFOEXA DWORD FILL
   STARTUPINFOEXA_UNION
   lpAttributeList AS DWORD   ' LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
END TYPE

UNION STARTUPINFOEXW_UNION
   StartupInfo AS STARTUPINFOW
   ' // For compatibility with the PB declares
   StartupInfoValue AS STARTUPINFOW
END UNION

' // Size = 72 bytes
TYPE STARTUPINFOEXW DWORD FILL
   STARTUPINFOEXW_UNION
   lpAttributeList AS DWORD   ' LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
END TYPE

#IF %DEF(%UNICODE)
   MACRO STARTUPINFOEX = STARTUPINFOEXW
#ELSE
   MACRO STARTUPINFOEX = STARTUPINFOEXA
#ENDIF

'#endif // (_WIN32_WINNT >= 0x0600)

%SHUTDOWN_NORETRY = &H00000001???

' // Size = 320 bytes
TYPE WIN32_FIND_DATAA DWORD
   dwFileAttributes   AS DWORD                ' DWORD dwFileAttributes
   ftCreationTime     AS FILETIME             ' FILETIME ftCreationTime
   ftLastAccessTime   AS FILETIME             ' FILETIME ftLastAccessTime
   ftLastWriteTime    AS FILETIME             ' FILETIME ftLastWriteTime
   nFileSizeHigh      AS DWORD                ' DWORD nFileSizeHigh
   nFileSizeLow       AS DWORD                ' DWORD nFileSizeLow
   dwReserved0        AS DWORD                ' DWORD dwReserved0
   dwReserved1        AS DWORD                ' DWORD dwReserved1
   cFileName          AS ASCIIZ * %MAX_PATH   ' CHAR   cFileName[ MAX_PATH ]
   cAlternateFileName AS ASCIIZ * 14          ' CHAR   cAlternateFileName[ 14 ]
END TYPE

' // Size = 592 bytes
TYPE WIN32_FIND_DATAW DWORD
   dwFileAttributes   AS DWORD                  ' DWORD    dwFileAttributes
   ftCreationTime     AS FILETIME               ' FILETIME ftCreationTime
   ftLastAccessTime   AS FILETIME               ' FILETIME ftLastAccessTime
   ftLastWriteTime    AS FILETIME               ' FILETIME ftLastWriteTime
   nFileSizeHigh      AS DWORD                  ' DWORD    nFileSizeHigh
   nFileSizeLow       AS DWORD                  ' DWORD    nFileSizeLow
   dwReserved0        AS DWORD                  ' DWORD    dwReserved0
   dwReserved1        AS DWORD                  ' DWORD    dwReserved1
   cFileName          AS WSTRINGZ * %MAX_PATH   ' WCHAR    cFileName[ MAX_PATH ]
   cAlternateFileName AS WSTRINGZ * 14          ' WCHAR    cAlternateFileName[ 14 ]
END TYPE

#IF %DEF(%UNICODE)
   MACRO WIN32_FIND_DATA = WIN32_FIND_DATAW
#ELSE
   MACRO WIN32_FIND_DATA = WIN32_FIND_DATAA
#ENDIF

' // Size = 36 bytes
TYPE WIN32_FILE_ATTRIBUTE_DATA DWORD
   dwFileAttributes AS DWORD      ' DWORD    dwFileAttributes
   ftCreationTime   AS FILETIME   ' FILETIME ftCreationTime
   ftLastAccessTime AS FILETIME   ' FILETIME ftLastAccessTime
   ftLastWriteTime  AS FILETIME   ' FILETIME ftLastWriteTime
   nFileSizeHigh    AS DWORD      ' DWORD    nFileSizeHigh
   nFileSizeLow     AS DWORD      ' DWORD    nFileSizeLow
END TYPE

DECLARE FUNCTION CreateMutexA IMPORT "KERNEL32.DLL" ALIAS "CreateMutexA" ( _
   BYREF lpMutexAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpMutexAttributes
 , BYVAL bInitialOwner AS LONG _                        ' __in BOOL bInitialOwner
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateMutexW IMPORT "KERNEL32.DLL" ALIAS "CreateMutexW" ( _
   BYREF lpMutexAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpMutexAttributes
 , BYVAL bInitialOwner AS LONG _                        ' __in BOOL bInitialOwner
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateMutex = CreateMutexW
#ELSE
   MACRO CreateMutex = CreateMutexA
#ENDIF

DECLARE FUNCTION OpenMutexA IMPORT "KERNEL32.DLL" ALIAS "OpenMutexA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenMutexW IMPORT "KERNEL32.DLL" ALIAS "OpenMutexW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenMutex = OpenMutexW
#ELSE
   MACRO OpenMutex = OpenMutexA
#ENDIF

DECLARE FUNCTION CreateEventA IMPORT "KERNEL32.DLL" ALIAS "CreateEventA" ( _
   BYREF lpEventAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpEventAttributes
 , BYVAL bManualReset AS LONG _                         ' __in BOOL bManualReset
 , BYVAL bInitialState AS LONG _                        ' __in BOOL bInitialState
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateEventW IMPORT "KERNEL32.DLL" ALIAS "CreateEventW" ( _
   BYREF lpEventAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpEventAttributes
 , BYVAL bManualReset AS LONG _                         ' __in BOOL bManualReset
 , BYVAL bInitialState AS LONG _                        ' __in BOOL bInitialState
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateEvent = CreateEventW
#ELSE
   MACRO CreateEvent = CreateEventA
#ENDIF

DECLARE FUNCTION OpenEventA IMPORT "KERNEL32.DLL" ALIAS "OpenEventA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenEventW IMPORT "KERNEL32.DLL" ALIAS "OpenEventW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenEvent = OpenEventW
#ELSE
   MACRO OpenEvent = OpenEventA
#ENDIF

DECLARE FUNCTION CreateSemaphoreA IMPORT "KERNEL32.DLL" ALIAS "CreateSemaphoreA" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYVAL lInitialCount AS LONG _                        ' __in LONG lInitialCount
 , BYVAL lMaximumCount AS LONG _                        ' __in LONG lMaximumCount
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateSemaphoreW IMPORT "KERNEL32.DLL" ALIAS "CreateSemaphoreW" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYVAL lInitialCount AS LONG _                        ' __in LONG lInitialCount
 , BYVAL lMaximumCount AS LONG _                        ' __in LONG lMaximumCount
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateSemaphore = CreateSemaphoreW
#ELSE
   MACRO CreateSemaphore = CreateSemaphoreA
#ENDIF

DECLARE FUNCTION OpenSemaphoreA IMPORT "KERNEL32.DLL" ALIAS "OpenSemaphoreA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenSemaphoreW IMPORT "KERNEL32.DLL" ALIAS "OpenSemaphoreW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenSemaphore = OpenSemaphoreW
#ELSE
   MACRO OpenSemaphore = OpenSemaphoreA
#ENDIF

'#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
'typedef
'VOID
'(APIENTRY *PTIMERAPCROUTINE)(
'    __in LPVOID lpArgToCompletionRoutine,
'    __in     DWORD dwTimerLowValue,
'    __in     DWORD dwTimerHighValue
'    );

DECLARE FUNCTION CreateWaitableTimerA IMPORT "KERNEL32.DLL" ALIAS "CreateWaitableTimerA" ( _
   BYREF lpTimerAttributes AS SECURITY_ATTRIBUTES  _    ' __in LPSECURITY_ATTRIBUTES lpTimerAttributes
 , BYVAL bManualReset AS LONG _                         ' __in BOOL bManualReset
 , BYREF lpTimerName AS ASCIIZ _                        ' __in LPCSTR lpTimerName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateWaitableTimerW IMPORT "KERNEL32.DLL" ALIAS "CreateWaitableTimerW" ( _
   BYREF lpTimerAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpTimerAttributes
 , BYVAL bManualReset AS LONG _                         ' __in BOOL bManualReset
 , BYREF lpTimerName AS WSTRINGZ _                      ' __in LPCWSTR lpTimerName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateWaitableTimer = CreateWaitableTimerW
#ELSE
   MACRO CreateWaitableTimer = CreateWaitableTimerA
#ENDIF

DECLARE FUNCTION OpenWaitableTimerA IMPORT "KERNEL32.DLL" ALIAS "OpenWaitableTimerA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpTimerName AS ASCIIZ _                        ' __in LPCSTR lpTimerName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenWaitableTimerW IMPORT "KERNEL32.DLL" ALIAS "OpenWaitableTimerW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpTimerName AS WSTRINGZ _                      ' __in LPCWSTR lpTimerName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenWaitableTimer = OpenWaitableTimerW
#ELSE
   MACRO OpenWaitableTimer = OpenWaitableTimerA
#ENDIF

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0601
' Note: Although the lpDueTime parameter is a QUAD, it is more practical to use
' a FILETIME structure. Therefore, the parameter as been declared BYREF ANY to
' allow passing a QUAD or a FILETIME structure.
DECLARE FUNCTION SetWaitableTimerEx IMPORT "KERNEL32.DLL" ALIAS "SetWaitableTimerEx" ( _
   BYVAL hTimer AS DWORD _                              ' __in     HANDLE hTimer
 , BYREF lpDueTime AS ANY _                             ' __in const LARGE_INTEGER *lpDueTime
 , BYVAL lPeriod AS LONG _                              ' __in     LONG lPeriod
 , BYVAL pfnCompletionRoutine AS DWORD _                ' __in PTIMERAPCROUTINE pfnCompletionRoutine
 , BYREF lpArgToCompletionRoutine AS ANY _              ' __in LPVOID lpArgToCompletionRoutine
 , BYREF WakeContext AS REASON_CONTEXT _                ' __in_opt PREASON_CONTEXT WakeContext
 , BYVAL TolerableDelay AS DWORD _                      ' __in     ULONG TolerableDelay
 ) AS LONG                                              ' BOOL
#ENDIF   ' // (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetWaitableTimer LIB "Kernel32.dll" ALIAS "SetWaitableTimer" _
    (BYVAL hTimer AS DWORD, lpDueTime AS ANY, BYVAL lPeriod AS LONG, _
    BYVAL pfnCompletionRoutine AS DWORD, _
    BYVAL lpArgToCompletionRoutine AS DWORD, BYVAL fResume AS LONG) AS LONG
#ELSE
' Note: Although the lpDueTime parameter is a QUAD, it is more practical to use
' a FILETIME structure. Therefore, the parameter as been declared BYREF ANY to
' allow passing a QUAD or a FILETIME structure.
DECLARE FUNCTION SetWaitableTimer IMPORT "KERNEL32.DLL" ALIAS "SetWaitableTimer" ( _
   BYVAL hTimer AS DWORD _                              ' __in HANDLE hTimer
 , BYREF lpDueTime AS ANY _                             ' __in const LARGE_INTEGER *lpDueTime
 , BYVAL lPeriod AS LONG _                              ' __in LONG lPeriod
 , BYVAL pfnCompletionRoutine AS DWORD _                ' __in PTIMERAPCROUTINE pfnCompletionRoutine
 , BYVAL lpArgToCompletionRoutine AS DWORD _            ' __in LPVOID lpArgToCompletionRoutine
 , BYVAL fResume AS LONG _                              ' __in BOOL fResume
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CancelWaitableTimer IMPORT "KERNEL32.DLL" ALIAS "CancelWaitableTimer" ( _
   BYVAL hTimer AS DWORD _                              ' __in HANDLE hTimer
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

%CREATE_MUTEX_INITIAL_OWNER  = &H00000001???

DECLARE FUNCTION CreateMutexExA IMPORT "KERNEL32.DLL" ALIAS "CreateMutexExA" ( _
   BYREF lpMutexAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpMutexAttributes
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateMutexExW IMPORT "KERNEL32.DLL" ALIAS "CreateMutexExW" ( _
   BYREF lpMutexAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpMutexAttributes
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateMutexEx = CreateMutexExW
#ELSE
   MACRO CreateMutexEx = CreateMutexExA
#ENDIF

%CREATE_EVENT_MANUAL_RESET   = &H00000001???
%CREATE_EVENT_INITIAL_SET    = &H00000002???

DECLARE FUNCTION CreateEventExA IMPORT "KERNEL32.DLL" ALIAS "CreateEventExA" ( _
   BYREF lpEventAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpEventAttributes
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateEventExW IMPORT "KERNEL32.DLL" ALIAS "CreateEventExW" ( _
   BYREF lpEventAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpEventAttributes
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateEventEx = CreateEventExW
#ELSE
   MACRO CreateEventEx = CreateEventExA
#ENDIF

DECLARE FUNCTION CreateSemaphoreExA IMPORT "KERNEL32.DLL" ALIAS "CreateSemaphoreExA" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYVAL lInitialCount AS LONG _                        ' __in LONG lInitialCount
 , BYVAL lMaximumCount AS LONG _                        ' __in LONG lMaximumCount
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateSemaphoreExW IMPORT "KERNEL32.DLL" ALIAS "CreateSemaphoreExW" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYVAL lInitialCount AS LONG _                        ' __in LONG lInitialCount
 , BYVAL lMaximumCount AS LONG _                        ' __in LONG lMaximumCount
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateSemaphoreEx = CreateSemaphoreExW
#ELSE
   MACRO CreateSemaphoreEx = CreateSemaphoreExA
#ENDIF

%CREATE_WAITABLE_TIMER_MANUAL_RESET  = &H00000001???

DECLARE FUNCTION CreateWaitableTimerExA IMPORT "KERNEL32.DLL" ALIAS "CreateWaitableTimerExA" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYREF lpTimerName AS ASCIIZ _                        ' __in LPCSTR lpTimerName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateWaitableTimerExW IMPORT "KERNEL32.DLL" ALIAS "CreateWaitableTimerExW" ( _
   BYREF lpSemaphoreAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpSemaphoreAttributes
 , BYREF lpTimerName AS WSTRINGZ _                      ' __in LPCWSTR lpTimerName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateWaitableTimerEx = CreateWaitableTimerExW
#ELSE
   MACRO CreateWaitableTimerEx = CreateWaitableTimerExA
#ENDIF

#ENDIF ' /* (_WIN32_WINNT >= 0x0600) */


'#endif /* (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400) */

DECLARE FUNCTION CreateFileMappingA IMPORT "KERNEL32.DLL" ALIAS "CreateFileMappingA" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpFileMappingAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpFileMappingAttributes
 , BYVAL flProtect AS DWORD _                           ' __in DWORD flProtect
 , BYVAL dwMaximumSizeHigh AS DWORD _                   ' __in DWORD dwMaximumSizeHigh
 , BYVAL dwMaximumSizeLow AS DWORD _                    ' __in DWORD dwMaximumSizeLow
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateFileMappingW IMPORT "KERNEL32.DLL" ALIAS "CreateFileMappingW" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpFileMappingAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpFileMappingAttributes
 , BYVAL flProtect AS DWORD _                           ' __in DWORD flProtect
 , BYVAL dwMaximumSizeHigh AS DWORD _                   ' __in DWORD dwMaximumSizeHigh
 , BYVAL dwMaximumSizeLow AS DWORD _                    ' __in DWORD dwMaximumSizeLow
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateFileMapping = CreateFileMappingW
#ELSE
   MACRO CreateFileMapping = CreateFileMappingA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION CreateFileMappingNumaA IMPORT "KERNEL32.DLL" ALIAS "CreateFileMappingNumaA" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpFileMappingAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpFileMappingAttributes
 , BYVAL flProtect AS DWORD _                           ' __in DWORD flProtect
 , BYVAL dwMaximumSizeHigh AS DWORD _                   ' __in DWORD dwMaximumSizeHigh
 , BYVAL dwMaximumSizeLow AS DWORD _                    ' __in DWORD dwMaximumSizeLow
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL nndPreferred AS DWORD _                        ' __in DWORD nndPreferred
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateFileMappingNumaW IMPORT "KERNEL32.DLL" ALIAS "CreateFileMappingNumaW" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpFileMappingAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpFileMappingAttributes
 , BYVAL flProtect AS DWORD _                           ' __in DWORD flProtect
 , BYVAL dwMaximumSizeHigh AS DWORD _                   ' __in DWORD dwMaximumSizeHigh
 , BYVAL dwMaximumSizeLow AS DWORD _                    ' __in DWORD dwMaximumSizeLow
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL nndPreferred AS DWORD _                        ' __in DWORD nndPreferred
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateFileMappingNuma = CreateFileMappingNumaW
#ELSE
   MACRO CreateFileMappingNuma = CreateFileMappingNumaA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION OpenFileMappingA IMPORT "KERNEL32.DLL" ALIAS "OpenFileMappingA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenFileMappingW IMPORT "KERNEL32.DLL" ALIAS "OpenFileMappingW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenFileMapping = OpenFileMappingW
#ELSE
   MACRO OpenFileMapping = OpenFileMappingA
#ENDIF

' // Note: The lpBuffer parameter has been declared as BYVAL DWORD instead of BYREF ASCIIZ/WSTRINGZ
' // to allow to pass a pointer to another kind of buffer, since it returns a series of
' // null-terminated strings, one for each valid drive in the system, plus with an additional null character.

DECLARE FUNCTION GetLogicalDriveStringsA IMPORT "KERNEL32.DLL" ALIAS "GetLogicalDriveStringsA" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD nBufferLength
 , BYVAL lpBuffer AS DWORD _                            ' __out LPSTR lpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLogicalDriveStringsW IMPORT "KERNEL32.DLL" ALIAS "GetLogicalDriveStringsW" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD nBufferLength
 , BYVAL lpBuffer AS DWORD _                            ' __out LPWSTR lpBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetLogicalDriveStrings = GetLogicalDriveStringsW
#ELSE
   MACRO GetLogicalDriveStrings = GetLogicalDriveStringsA
#ENDIF

'#if _WIN32_WINNT >= 0x0501

' MEMORY_RESOURCE_NOTIFICATION_TYPE enum
%LowMemoryResourceNotification  = 0
%HighMemoryResourceNotification = 1

DECLARE FUNCTION CreateMemoryResourceNotification IMPORT "KERNEL32.DLL" ALIAS "CreateMemoryResourceNotification" ( _
   BYVAL NotificationType AS DWORD _                    ' __in MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION QueryMemoryResourceNotification IMPORT "KERNEL32.DLL" ALIAS "QueryMemoryResourceNotification" ( _
   BYVAL ResourceNotificationHandle AS DWORD _          ' __in  HANDLE ResourceNotificationHandle
 , BYREF ResourceState AS LONG _                        ' __out PBOOL  ResourceState
 ) AS LONG                                              ' BOOL

'#endif // _WIN32_WINNT >= 0x0501


DECLARE FUNCTION LoadLibraryA IMPORT "KERNEL32.DLL" ALIAS "LoadLibraryA" ( _
   BYREF lpLibFileName AS ASCIIZ _                      ' __in LPCSTR lpLibFileName
 ) AS DWORD                                             ' HMODULE

DECLARE FUNCTION LoadLibraryW IMPORT "KERNEL32.DLL" ALIAS "LoadLibraryW" ( _
   BYREF lpLibFileName AS WSTRINGZ _                    ' __in LPCWSTR lpLibFileName
 ) AS DWORD                                             ' HMODULE

#IF %DEF(%UNICODE)
   MACRO LoadLibrary = LoadLibraryW
#ELSE
   MACRO LoadLibrary = LoadLibraryA
#ENDIF

DECLARE FUNCTION LoadLibraryExA IMPORT "KERNEL32.DLL" ALIAS "LoadLibraryExA" ( _
   BYREF lpLibFileName AS ASCIIZ _                      ' __in LPCSTR lpLibFileName
 , BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS DWORD                                             ' HMODULE

DECLARE FUNCTION LoadLibraryExW IMPORT "KERNEL32.DLL" ALIAS "LoadLibraryExW" ( _
   BYREF lpLibFileName AS WSTRINGZ _                    ' __in LPCWSTR lpLibFileName
 , BYVAL hFile AS DWORD _                               ' __in HANDLE  hFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS DWORD                                             ' HMODULE

#IF %DEF(%UNICODE)
   MACRO LoadLibraryEx = LoadLibraryExW
#ELSE
   MACRO LoadLibraryEx = LoadLibraryExA
#ENDIF

%DONT_RESOLVE_DLL_REFERENCES        = &H00000001???
%LOAD_LIBRARY_AS_DATAFILE           = &H00000002???
%LOAD_WITH_ALTERED_SEARCH_PATH      = &H00000008???
%LOAD_IGNORE_CODE_AUTHZ_LEVEL       = &H00000010???
%LOAD_LIBRARY_AS_IMAGE_RESOURCE     = &H00000020???
%LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE = &H00000040???
%LOAD_LIBRARY_REQUIRE_SIGNED_TARGET = &H00000080???

DECLARE FUNCTION GetModuleFileNameA IMPORT "KERNEL32.DLL" ALIAS "GetModuleFileNameA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpFilename AS ASCIIZ _                         ' __out LPSTR  lpFilename
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetModuleFileNameW IMPORT "KERNEL32.DLL" ALIAS "GetModuleFileNameW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpFilename AS WSTRINGZ _                       ' __out LPWSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetModuleFileName = GetModuleFileNameW
#ELSE
   MACRO GetModuleFileName = GetModuleFileNameA
#ENDIF

DECLARE FUNCTION GetModuleHandleA IMPORT "KERNEL32.DLL" ALIAS "GetModuleHandleA" ( _
   BYREF lpModuleName AS ASCIIZ _                       ' __in LPCSTR lpModuleName
 ) AS DWORD                                             ' HMODULE

DECLARE FUNCTION GetModuleHandleW IMPORT "KERNEL32.DLL" ALIAS "GetModuleHandleW" ( _
   BYREF lpModuleName AS WSTRINGZ _                     ' __in LPCWSTR lpModuleName
 ) AS DWORD                                             ' HMODULE

#IF %DEF(%UNICODE)
   MACRO GetModuleHandle = GetModuleHandleW
#ELSE
   MACRO GetModuleHandle = GetModuleHandleA
#ENDIF

' // Wrapper function (not in the SDK)
FUNCTION GethInst() AS DWORD
   FUNCTION = GetModuleHandle(BYVAL %NULL)
END FUNCTION

'#if !defined(RC_INVOKED)
'#if _WIN32_WINNT > 0x0500 || defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX) || ISOLATION_AWARE_ENABLED

%GET_MODULE_HANDLE_EX_FLAG_PIN                 = &H00000001???
%GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT  = &H00000002???
%GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS        = &H00000004???

'typedef
'BOOL
'(WINAPI*
'PGET_MODULE_HANDLE_EXA)(
'    __in  DWORD    dwFlags,
'    __in  LPCSTR   lpModuleName,
'    __out HMODULE* phModule
'    );
'typedef

'BOOL
'(WINAPI*
'PGET_MODULE_HANDLE_EXW)(
'    __in  DWORD    dwFlags,
'    __in  LPCWSTR  lpModuleName,
'    __out HMODULE* phModule
'    );

DECLARE FUNCTION GetModuleHandleExA IMPORT "KERNEL32.DLL" ALIAS "GetModuleHandleExA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags
 , BYREF lpModuleName AS ASCIIZ _                       ' __in  LPCSTR   lpModuleName
 , BYREF phModule AS DWORD _                            ' __out HMODULE* phModule
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetModuleHandleExW IMPORT "KERNEL32.DLL" ALIAS "GetModuleHandleExW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags
 , BYREF lpModuleName AS WSTRINGZ _                     ' __in  LPCWSTR  lpModuleName
 , BYREF phModule AS DWORD _                            ' __out HMODULE* phModule
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetModuleHandleEx = GetModuleHandleExW
#ELSE
   MACRO GetModuleHandleEx = GetModuleHandleExA
#ENDIF

'#if _WIN32_WINNT >= 0x0502

DECLARE FUNCTION NeedCurrentDirectoryForExePathA IMPORT "KERNEL32.DLL" ALIAS "NeedCurrentDirectoryForExePathA" ( _
   BYREF ExeName AS ASCIIZ _                            ' __in LPCSTR ExeName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION NeedCurrentDirectoryForExePathW IMPORT "KERNEL32.DLL" ALIAS "NeedCurrentDirectoryForExePathW" ( _
   BYREF ExeName AS WSTRINGZ _                          ' __in LPCWSTR ExeName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO NeedCurrentDirectoryForExePath = NeedCurrentDirectoryForExePathW
#ELSE
   MACRO NeedCurrentDirectoryForExePath = NeedCurrentDirectoryForExePathA
#ENDIF

'#endif

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

%PROCESS_NAME_NATIVE     = &H00000001???

DECLARE FUNCTION QueryFullProcessImageNameA IMPORT "KERNEL32.DLL" ALIAS "QueryFullProcessImageNameA" ( _
   BYVAL hProcess AS DWORD _                            ' __in     HANDLE hProcess
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 , BYREF lpExeName AS ASCIIZ _                          ' __out    LPSTR  lpExeName
 , BYREF lpdwSize AS DWORD _                            ' __inout PDWORD lpdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryFullProcessImageNameW IMPORT "KERNEL32.DLL" ALIAS "QueryFullProcessImageNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in     HANDLE hProcess
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 , BYREF lpExeName AS WSTRINGZ _                        ' __out    LPWSTR lpExeName
 , BYREF lpdwSize AS DWORD _                            ' __inout PDWORD lpdwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO QueryFullProcessImageName = QueryFullProcessImageNameW
#ELSE
   MACRO QueryFullProcessImageName = QueryFullProcessImageNameA
#ENDIF

#ENDIF

'#if (_WIN32_WINNT >= 0x0600)

'//
'// Extended process and thread attribute support
'//

%PROC_THREAD_ATTRIBUTE_NUMBER    = &H0000FFFF???
%PROC_THREAD_ATTRIBUTE_THREAD    = &H00010000???  ' // Attribute may be used with thread creation
%PROC_THREAD_ATTRIBUTE_INPUT     = &H00020000???  ' // Attribute is input only
%PROC_THREAD_ATTRIBUTE_ADDITIVE  = &H00040000???  ' // Attribute may be "accumulated," e.g. bitmasks, counters, etc.

' enum PROC_THREAD_ATTRIBUTE_NUM
%ProcThreadAttributeParentProcess    = 0
%ProcThreadAttributeExtendedFlags    = 1
%ProcThreadAttributeHandleList       = 2
%ProcThreadAttributeGroupAffinity    = 3
%ProcThreadAttributePreferredNode    = 4
%ProcThreadAttributeIdealProcessor   = 5
%ProcThreadAttributeUmsThread        = 6
%ProcThreadAttributeMitigationPolicy = 7
%ProcThreadAttributeMax              = 8

'#define ProcThreadAttributeValue(Number, Thread, Input, Additive) \
'    (((Number) & PROC_THREAD_ATTRIBUTE_NUMBER) | \
'     ((Thread != FALSE) ? PROC_THREAD_ATTRIBUTE_THREAD : 0) | \
'     ((Input != FALSE) ? PROC_THREAD_ATTRIBUTE_INPUT : 0) | \
'     ((Additive != FALSE) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))

'#define PROC_THREAD_ATTRIBUTE_PARENT_PROCESS \
'    ProcThreadAttributeValue (ProcThreadAttributeParentProcess, FALSE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS \
'    ProcThreadAttributeValue (ProcThreadAttributeExtendedFlags, FALSE, TRUE, TRUE)
'#define PROC_THREAD_ATTRIBUTE_HANDLE_LIST \
'    ProcThreadAttributeValue (ProcThreadAttributeHandleList, FALSE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY \
'    ProcThreadAttributeValue (ProcThreadAttributeGroupAffinity, TRUE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_PREFERRED_NODE \
'    ProcThreadAttributeValue (ProcThreadAttributePreferredNode, FALSE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR \
'    ProcThreadAttributeValue (ProcThreadAttributeIdealProcessor, TRUE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_UMS_THREAD \
'    ProcThreadAttributeValue (ProcThreadAttributeUmsThread, TRUE, TRUE, FALSE)
'#define PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY \
'    ProcThreadAttributeValue (ProcThreadAttributeMitigationPolicy, FALSE, TRUE, FALSE)

%PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE            = &H01???
%PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE  = &H02???
%PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE          = &H04???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InitializeProcThreadAttributeList LIB "Kernel32.dll" _
    ALIAS "InitializeProcThreadAttributeList" _
    (BYVAL lpAttributeList AS DWORD, BYVAL dwAttributeCount AS DWORD, _
    BYVAL dwFlags AS DWORD, lpSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION InitializeProcThreadAttributeList IMPORT "KERNEL32.DLL" ALIAS "InitializeProcThreadAttributeList" ( _
   BYREF lpAttributeList AS DWORD _                     ' __out LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
 , BYVAL dwAttributeCount AS DWORD _                    ' __in DWORD dwAttributeCount
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpSize AS DWORD _                              ' __inout PSIZE_T lpSize
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE SUB DeleteProcThreadAttributeList IMPORT "KERNEL32.DLL" ALIAS "DeleteProcThreadAttributeList" ( _
   BYREF lpAttributeList AS DWORD _                       ' __inout LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
 )                                                      ' void

%PROC_THREAD_ATTRIBUTE_REPLACE_VALUE     = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION UpdateProcThreadAttribute LIB "Kernel32.dll" _
    ALIAS "UpdateProcThreadAttribute" (BYVAL lpAttributeList AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL dAttribute AS DWORD, _
    BYVAL lpValue AS DWORD, BYVAL cbSize AS DWORD, _
    BYVAL lpPreviousValue AS DWORD, BYVAL lpReturnSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION UpdateProcThreadAttribute IMPORT "KERNEL32.DLL" ALIAS "UpdateProcThreadAttribute" ( _
   BYREF lpAttributeList AS DWORD _                     ' __inout LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL Attribute AS DWORD _                           ' __in DWORD_PTR Attribute
 , BYVAL lpValue AS DWORD _                             ' __in PVOID lpValue
 , BYVAL cbSize AS DWORD _                              ' __in SIZE_T cbSize
 , OPTIONAL BYREF lpPreviousValue AS DWORD _            ' __out_opt PVOID lpPreviousValue
 , BYVAL lpReturnSize AS DWORD _                        ' __in_opt PSIZE_T lpReturnSize
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif // (_WIN32_WINNT >= 0x0600)

DECLARE FUNCTION CreateProcessA IMPORT "KERNEL32.DLL" ALIAS "CreateProcessA" ( _
   BYREF lpApplicationName AS ASCIIZ _                  ' __in LPCSTR lpApplicationName
 , BYREF lpCommandLine AS ASCIIZ _                      ' __inout LPSTR lpCommandLine
 , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _   ' __in LPSECURITY_ATTRIBUTES lpProcessAttributes
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL bInheritHandles AS LONG _                      ' __in BOOL bInheritHandles
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS ASCIIZ _                 ' __in LPCSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOA _                ' __in LPSTARTUPINFOA lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateProcessW IMPORT "KERNEL32.DLL" ALIAS "CreateProcessW" ( _
   BYREF lpApplicationName AS WSTRINGZ _                ' __in LPCWSTR lpApplicationName
 , BYREF lpCommandLine AS WSTRINGZ _                    ' __inout LPWSTR lpCommandLine
 , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _   ' __in LPSECURITY_ATTRIBUTES lpProcessAttributes
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL bInheritHandles AS LONG _                      ' __in BOOL bInheritHandles
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS WSTRINGZ _               ' __in LPCWSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOW _                ' __in LPSTARTUPINFOW lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateProcess = CreateProcessW
#ELSE
   MACRO CreateProcess = CreateProcessA
#ENDIF

DECLARE FUNCTION SetProcessShutdownParameters IMPORT "KERNEL32.DLL" ALIAS "SetProcessShutdownParameters" ( _
   BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessShutdownParameters IMPORT "KERNEL32.DLL" ALIAS "GetProcessShutdownParameters" ( _
   BYREF lpdwLevel AS DWORD _                           ' __out LPDWORD lpdwLevel
 , BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessVersion IMPORT "KERNEL32.DLL" ALIAS "GetProcessVersion" ( _
   BYVAL ProcessId AS DWORD _                           ' __in DWORD ProcessId
 ) AS DWORD                                             ' DWORD

DECLARE SUB FatalAppExitA IMPORT "KERNEL32.DLL" ALIAS "FatalAppExitA" ( _
   BYVAL uAction AS DWORD _                             ' __in UINT   uAction
 , BYREF lpMessageText AS ASCIIZ _                      ' __in LPCSTR lpMessageText
 )                                                      ' void

DECLARE SUB FatalAppExitW IMPORT "KERNEL32.DLL" ALIAS "FatalAppExitW" ( _
   BYVAL uAction AS DWORD _                             ' __in UINT    uAction
 , BYREF lpMessageText AS WSTRINGZ _                    ' __in LPCWSTR lpMessageText
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO FatalAppExit = FatalAppExitW
#ELSE
   MACRO FatalAppExit = FatalAppExitA
#ENDIF

DECLARE SUB GetStartupInfoA IMPORT "KERNEL32.DLL" ALIAS "GetStartupInfoA" ( _
   BYREF lpStartupInfo AS STARTUPINFOA _                ' __out LPSTARTUPINFOA lpStartupInfo
 )                                                      ' void

DECLARE SUB GetStartupInfoW IMPORT "KERNEL32.DLL" ALIAS "GetStartupInfoW" ( _
   BYREF lpStartupInfo AS STARTUPINFOW _                ' __out LPSTARTUPINFOW lpStartupInfo
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO GetStartupInfo = GetStartupInfoW
#ELSE
   MACRO GetStartupInfo = GetStartupInfoA
#ENDIF

DECLARE FUNCTION GetCommandLineA IMPORT "KERNEL32.DLL" ALIAS "GetCommandLineA" ( _
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION GetCommandLineW IMPORT "KERNEL32.DLL" ALIAS "GetCommandLineW" ( _
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO GetCommandLine = GetCommandLineW
#ELSE
   MACRO GetCommandLine = GetCommandLineA
#ENDIF

DECLARE FUNCTION GetEnvironmentVariableA IMPORT "KERNEL32.DLL" ALIAS "GetEnvironmentVariableA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetEnvironmentVariableW IMPORT "KERNEL32.DLL" ALIAS "GetEnvironmentVariableW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetEnvironmentVariable = GetEnvironmentVariableW
#ELSE
   MACRO GetEnvironmentVariable = GetEnvironmentVariableA
#ENDIF

'#if defined(_M_CEE)
'#undef GetEnvironmentVariable
'__inline
'DWORD
'GetEnvironmentVariable(
'    __in_opt LPCTSTR lpName,
'    __out_ecount_part_opt(nSize, return + 1) LPTSTR lpBuffer,
'    __in DWORD nSize
'    )
'{
'#ifdef UNICODE
'    return GetEnvironmentVariableW(
'#else
'    return GetEnvironmentVariableA(
'#endif
'        lpName,
'        lpBuffer,
'	nSize
'        );
'}
'#endif  /* _M_CEE */

DECLARE FUNCTION SetEnvironmentVariableA IMPORT "KERNEL32.DLL" ALIAS "SetEnvironmentVariableA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYREF lpValue AS ASCIIZ _                            ' __in LPCSTR lpValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetEnvironmentVariableW IMPORT "KERNEL32.DLL" ALIAS "SetEnvironmentVariableW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYREF lpValue AS WSTRINGZ _                          ' __in LPCWSTR lpValue
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetEnvironmentVariable = SetEnvironmentVariableW
#ELSE
   MACRO SetEnvironmentVariable = SetEnvironmentVariableA
#ENDIF

DECLARE FUNCTION ExpandEnvironmentStringsA IMPORT "KERNEL32.DLL" ALIAS "ExpandEnvironmentStringsA" ( _
   BYREF lpSrc AS ASCIIZ _                              ' __in LPCSTR lpSrc
 , BYREF lpDst AS ASCIIZ _                              ' __out LPSTR lpDst
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ExpandEnvironmentStringsW IMPORT "KERNEL32.DLL" ALIAS "ExpandEnvironmentStringsW" ( _
   BYREF lpSrc AS WSTRINGZ _                            ' __in LPCWSTR lpSrc
 , BYREF lpDst AS WSTRINGZ _                            ' __out LPWSTR lpDst
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ExpandEnvironmentStrings = ExpandEnvironmentStringsW
#ELSE
   MACRO ExpandEnvironmentStrings = ExpandEnvironmentStringsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFirmwareEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFirmwareEnvironmentVariableA IMPORT "KERNEL32.DLL" ALIAS "GetFirmwareEnvironmentVariableA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in  LPCSTR lpName
 , BYREF lpGuid AS ASCIIZ _                             ' __in  LPCSTR lpGuid
 , BYREF pBuffer AS ANY _                               ' __out PVOID  pBuffer
 , BYVAL nSize AS DWORD _                               ' __in  DWORD  nSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFirmwareEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "GetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetFirmwareEnvironmentVariableW IMPORT "KERNEL32.DLL" ALIAS "GetFirmwareEnvironmentVariableW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in  LPCWSTR lpName
 , BYREF lpGuid AS WSTRINGZ _                           ' __in  LPCWSTR lpGuid
 , BYREF pBuffer AS ANY _                               ' __out PVOID   pBuffer
 , BYVAL nSize AS DWORD _                               ' __in  DWORD   nSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetFirmwareEnvironmentVariable = GetFirmwareEnvironmentVariableW
#ELSE
   MACRO GetFirmwareEnvironmentVariable = GetFirmwareEnvironmentVariableA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetFirmwareEnvironmentVariableA LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableA" (lpName AS ASCIIZ, _
    lpGuid AS ASCIIZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFirmwareEnvironmentVariableA IMPORT "KERNEL32.DLL" ALIAS "SetFirmwareEnvironmentVariableA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYREF lpGuid AS ASCIIZ _                             ' __in LPCSTR lpGuid
 , BYREF pValue AS ANY _                                ' __in PVOID  pValue
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetFirmwareEnvironmentVariableW LIB "Kernel32.dll" _
    ALIAS "SetFirmwareEnvironmentVariableW" (lpName AS WSTRINGZ, _
    lpGuid AS WSTRINGZ, BYVAL pBuffer AS DWORD, BYVAL nSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFirmwareEnvironmentVariableW IMPORT "KERNEL32.DLL" ALIAS "SetFirmwareEnvironmentVariableW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYREF lpGuid AS WSTRINGZ _                           ' __in LPCWSTR lpGuid
 , BYREF pValue AS ANY _                                ' __in PVOID   pValue
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetFirmwareEnvironmentVariable = SetFirmwareEnvironmentVariableW
#ELSE
   MACRO SetFirmwareEnvironmentVariable = SetFirmwareEnvironmentVariableA
#ENDIF

DECLARE SUB OutputDebugStringA IMPORT "KERNEL32.DLL" ALIAS "OutputDebugStringA" ( _
   BYREF lpOutputString AS ASCIIZ _                     ' __in LPCSTR lpOutputString
 )                                                      ' void

DECLARE SUB OutputDebugStringW IMPORT "KERNEL32.DLL" ALIAS "OutputDebugStringW" ( _
   BYREF lpOutputString AS WSTRINGZ _                   ' __in LPCWSTR lpOutputString
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO OutputDebugString = OutputDebugStringW
#ELSE
   MACRO OutputDebugString = OutputDebugStringA
#ENDIF

DECLARE FUNCTION FindResourceA IMPORT "KERNEL32.DLL" ALIAS "FindResourceA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR  lpName
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR  lpType
 ) AS DWORD                                             ' HRSRC

DECLARE FUNCTION FindResourceW IMPORT "KERNEL32.DLL" ALIAS "FindResourceW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 ) AS DWORD                                             ' HRSRC

#IF %DEF(%UNICODE)
   MACRO FindResource = FindResourceW
#ELSE
   MACRO FindResource = FindResourceA
#ENDIF

DECLARE FUNCTION FindResourceExA IMPORT "KERNEL32.DLL" ALIAS "FindResourceExA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR  lpType
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR  lpName
 , BYVAL wLanguage AS WORD _                            ' __in WORD    wLanguage
 ) AS DWORD                                             ' HRSRC

DECLARE FUNCTION FindResourceExW IMPORT "KERNEL32.DLL" ALIAS "FindResourceExW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL wLanguage AS WORD _                            ' __in WORD    wLanguage
 ) AS DWORD                                             ' HRSRC

#IF %DEF(%UNICODE)
   MACRO FindResourceEx = FindResourceExW
#ELSE
   MACRO FindResourceEx = FindResourceExA
#ENDIF

'typedef BOOL (CALLBACK* ENUMRESNAMEPROCA)(__in HMODULE hModule, __in LPCSTR lpType,
'__in LPSTR lpName, __in LONG_PTR lParam);
'typedef BOOL (CALLBACK* ENUMRESNAMEPROCW)(__in HMODULE hModule, __in LPCWSTR lpType,
'__in LPWSTR lpName, __in LONG_PTR lParam);

'typedef BOOL (CALLBACK* ENUMRESLANGPROCA)(__in HMODULE hModule, __in LPCSTR lpType,
'__in LPCSTR lpName, __in WORD  wLanguage, __in LONG_PTR lParam);
'typedef BOOL (CALLBACK* ENUMRESLANGPROCW)(__in HMODULE hModule, __in LPCWSTR lpType,
'__in LPCWSTR lpName, __in WORD  wLanguage, __in LONG_PTR lParam);

DECLARE FUNCTION EnumResourceTypesA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceTypesA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESTYPEPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceTypesW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceTypesW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESTYPEPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceTypes = EnumResourceTypesW
#ELSE
   MACRO EnumResourceTypes = EnumResourceTypesA
#ENDIF

DECLARE FUNCTION EnumResourceNamesA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceNamesA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR lpType
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESNAMEPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceNamesW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceNamesW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESNAMEPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceNames = EnumResourceNamesW
#ELSE
   MACRO EnumResourceNames = EnumResourceNamesA
#ENDIF

DECLARE FUNCTION EnumResourceLanguagesA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceLanguagesA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR lpType
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESLANGPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceLanguagesW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceLanguagesW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESLANGPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceLanguages = EnumResourceLanguagesW
#ELSE
   MACRO EnumResourceLanguages = EnumResourceLanguagesA
#ENDIF

%RESOURCE_ENUM_LN               = &H0001
%RESOURCE_ENUM_MUI              = &H0002
%RESOURCE_ENUM_MUI_SYSTEM       = &H0004
%RESOURCE_ENUM_VALIDATE         = &H0008
'%RESOURCE_UPDATE_LN             = &H0010   ' // Renamed in Windows 7 SDL
%RESOURCE_ENUM_MODULE_EXACT     = &H0010
'%RESOURCE_UPDATE_MUI            = &H0020   ' // Removed in Windows 7 SDK

DECLARE FUNCTION EnumResourceTypesExA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceTypesExA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESTYPEPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceTypesExW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceTypesExW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESTYPEPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceTypesEx = EnumResourceTypesExW
#ELSE
   MACRO EnumResourceTypesEx = EnumResourceTypesExA
#ENDIF

DECLARE FUNCTION EnumResourceNamesExA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceNamesExA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR lpType
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESNAMEPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceNamesExW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceNamesExW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCSTR lpType
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESNAMEPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceNamesEx = EnumResourceNamesExW
#ELSE
   MACRO EnumResourceNamesEx = EnumResourceNamesExA
#ENDIF

DECLARE FUNCTION EnumResourceLanguagesExA IMPORT "KERNEL32.DLL" ALIAS "EnumResourceLanguagesExA" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR lpType
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESLANGPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumResourceLanguagesExW IMPORT "KERNEL32.DLL" ALIAS "EnumResourceLanguagesExW" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL lpEnumFunc AS DWORD _                          ' __in ENUMRESLANGPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LangId AS WORD _                               ' __in LANGID LangId
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumResourceLanguagesEx = EnumResourceLanguagesExW
#ELSE
   MACRO EnumResourceLanguagesEx = EnumResourceLanguagesExA
#ENDIF

DECLARE FUNCTION BeginUpdateResourceA IMPORT "KERNEL32.DLL" ALIAS "BeginUpdateResourceA" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in LPCSTR pFileName
 , BYVAL bDeleteExistingResources AS LONG _             ' __in BOOL bDeleteExistingResources
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION BeginUpdateResourceW IMPORT "KERNEL32.DLL" ALIAS "BeginUpdateResourceW" ( _
   BYREF pFileName AS WSTRINGZ _                        ' __in LPCWSTR pFileName
 , BYVAL bDeleteExistingResources AS LONG _             ' __in BOOL bDeleteExistingResources
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO BeginUpdateResource = BeginUpdateResourceW
#ELSE
   MACRO BeginUpdateResource = BeginUpdateResourceA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION UpdateResourceA LIB "Kernel32.dll" ALIAS "UpdateResourceA" _
    (BYVAL hUpdate AS DWORD, lpType AS ASCIIZ, lpName AS ASCIIZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION UpdateResourceA IMPORT "KERNEL32.DLL" ALIAS "UpdateResourceA" ( _
   BYVAL hUpdate AS DWORD _                             ' __in HANDLE hUpdate
 , BYREF lpType AS ASCIIZ _                             ' __in LPCSTR lpType
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL wLanguage AS WORD _                            ' __in WORD wLanguage
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 , BYVAL c AS DWORD _                                   ' __in DWORD c
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION UpdateResourceW LIB "Kernel32.dll" ALIAS "UpdateResourceW" _
    (BYVAL hUpdate AS DWORD, lpType AS WSTRINGZ, lpName AS WSTRINGZ, _
    BYVAL wLanguage AS WORD, BYVAL lpData AS DWORD, BYVAL cbData AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION UpdateResourceW IMPORT "KERNEL32.DLL" ALIAS "UpdateResourceW" ( _
   BYVAL hUpdate AS DWORD _                             ' __in HANDLE hUpdate
 , BYREF lpType AS WSTRINGZ _                           ' __in LPCWSTR lpType
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL wLanguage AS WORD _                            ' __in WORD wLanguage
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 , BYVAL c AS DWORD _                                   ' __in DWORD cb
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO UpdateResource = UpdateResourceW
#ELSE
   MACRO UpdateResource = UpdateResourceA
#ENDIF

DECLARE FUNCTION EndUpdateResourceA IMPORT "KERNEL32.DLL" ALIAS "EndUpdateResourceA" ( _
   BYVAL hUpdate AS DWORD _                             ' __in HANDLE hUpdate
 , BYVAL fDiscard AS LONG _                             ' __in BOOL   fDiscard
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EndUpdateResourceW IMPORT "KERNEL32.DLL" ALIAS "EndUpdateResourceW" ( _
   BYVAL hUpdate AS DWORD _                             ' __in HANDLE hUpdate
 , BYVAL fDiscard AS LONG _                             ' __in BOOL   fDiscard
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EndUpdateResource = EndUpdateResourceW
#ELSE
   MACRO EndUpdateResource = EndUpdateResourceA
#ENDIF

DECLARE FUNCTION GlobalAddAtomA IMPORT "KERNEL32.DLL" ALIAS "GlobalAddAtomA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION GlobalAddAtomW IMPORT "KERNEL32.DLL" ALIAS "GlobalAddAtomW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO GlobalAddAtom = GlobalAddAtomW
#ELSE
   MACRO GlobalAddAtom = GlobalAddAtomA
#ENDIF

DECLARE FUNCTION GlobalFindAtomA IMPORT "KERNEL32.DLL" ALIAS "GlobalFindAtomA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION GlobalFindAtomW IMPORT "KERNEL32.DLL" ALIAS "GlobalFindAtomW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO GlobalFindAtom = GlobalFindAtomW
#ELSE
   MACRO GlobalFindAtom = GlobalFindAtomA
#ENDIF

DECLARE FUNCTION GlobalGetAtomNameA IMPORT "KERNEL32.DLL" ALIAS "GlobalGetAtomNameA" ( _
   BYVAL nAtom AS  WORD _                               ' __in  ATOM nAtom
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  int nSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GlobalGetAtomNameW IMPORT "KERNEL32.DLL" ALIAS "GlobalGetAtomNameW" ( _
   BYVAL nAtom AS WORD _                                ' __in  ATOM nAtom
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  int nSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GlobalGetAtomName = GlobalGetAtomNameW
#ELSE
   MACRO GlobalGetAtomName = GlobalGetAtomNameA
#ENDIF

DECLARE FUNCTION AddAtomA IMPORT "KERNEL32.DLL" ALIAS "AddAtomA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION AddAtomW IMPORT "KERNEL32.DLL" ALIAS "AddAtomW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO AddAtom = AddAtomW
#ELSE
   MACRO AddAtom = AddAtomA
#ENDIF

DECLARE FUNCTION FindAtomA IMPORT "KERNEL32.DLL" ALIAS "FindAtomA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION FindAtomW IMPORT "KERNEL32.DLL" ALIAS "FindAtomW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO FindAtom = FindAtomW
#ELSE
   MACRO FindAtom = FindAtomA
#ENDIF

DECLARE FUNCTION GetAtomNameA IMPORT "KERNEL32.DLL" ALIAS "GetAtomNameA" ( _
   BYVAL nAtom AS WORD _                                ' __in  ATOM  nAtom
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  int   nSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetAtomNameW IMPORT "KERNEL32.DLL" ALIAS "GetAtomNameW" ( _
   BYVAL nAtom AS WORD _                                ' __in  ATOM   nAtom
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in  int    nSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetAtomName = GetAtomNameW
#ELSE
   MACRO GetAtomName = GetAtomNameA
#ENDIF

DECLARE FUNCTION GetProfileIntA IMPORT "KERNEL32.DLL" ALIAS "GetProfileIntA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in LPCSTR lpKeyName
 , BYVAL nDefault AS LONG _                             ' __in INT    nDefault
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetProfileIntW IMPORT "KERNEL32.DLL" ALIAS "GetProfileIntW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in LPCWSTR lpKeyName
 , BYVAL nDefault AS LONG _                             ' __in INT     nDefault
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetProfileInt = GetProfileIntW
#ELSE
   MACRO GetProfileInt = GetProfileIntA
#ENDIF

DECLARE FUNCTION GetProfileStringA IMPORT "KERNEL32.DLL" ALIAS "GetProfileStringA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR  lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in LPCSTR  lpKeyName
 , BYREF lpDefault AS ASCIIZ _                          ' __in LPCSTR  lpDefault
 , BYREF lpReturnedString AS ASCIIZ _                   ' __out LPSTR  lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetProfileStringW IMPORT "KERNEL32.DLL" ALIAS "GetProfileStringW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in LPCWSTR lpKeyName
 , BYREF lpDefault AS WSTRINGZ _                        ' __in LPCWSTR lpDefault
 , BYREF lpReturnedString AS WSTRINGZ _                 ' __out LPWSTR lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetProfileString = GetProfileStringW
#ELSE
   MACRO GetProfileString = GetProfileStringA
#ENDIF

DECLARE FUNCTION WriteProfileStringA IMPORT "KERNEL32.DLL" ALIAS "WriteProfileStringA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in LPCSTR lpKeyName
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WriteProfileStringW IMPORT "KERNEL32.DLL" ALIAS "WriteProfileStringW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in LPCWSTR lpKeyName
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WriteProfileString = WriteProfileStringW
#ELSE
   MACRO WriteProfileString = WriteProfileStringA
#ENDIF

DECLARE FUNCTION GetProfileSectionA IMPORT "KERNEL32.DLL" ALIAS "GetProfileSectionA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpReturnedString AS ASCIIZ _                   ' __out LPSTR lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetProfileSectionW IMPORT "KERNEL32.DLL" ALIAS "GetProfileSectionW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpReturnedString AS WSTRINGZ _                 ' __out LPWSTR lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetProfileSection = GetProfileSectionW
#ELSE
   MACRO GetProfileSection = GetProfileSectionA
#ENDIF

DECLARE FUNCTION WriteProfileSectionA IMPORT "KERNEL32.DLL" ALIAS "WriteProfileSectionA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS LONG                                              ' LONG

DECLARE FUNCTION WriteProfileSectionW IMPORT "KERNEL32.DLL" ALIAS "WriteProfileSectionW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WriteProfileSection = WriteProfileSectionW
#ELSE
   MACRO WriteProfileSection = WriteProfileSectionA
#ENDIF

DECLARE FUNCTION GetPrivateProfileIntA IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileIntA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in LPCSTR lpKeyName
 , BYVAL nDefault AS LONG _                             ' __in INT    nDefault
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetPrivateProfileIntW IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileIntW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in LPCWSTR lpKeyName
 , BYVAL nDefault AS LONG _                             ' __in INT     nDefault
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetPrivateProfileInt = GetPrivateProfileIntW
#ELSE
   MACRO GetPrivateProfileInt = GetPrivateProfileIntA
#ENDIF

DECLARE FUNCTION GetPrivateProfileStringA IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileStringA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in  LPCSTR lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in  LPCSTR lpKeyName
 , BYREF lpDefault AS ASCIIZ _                          ' __in  LPCSTR lpDefault
 , BYREF lpReturnedString AS ASCIIZ _                   ' __out LPSTR  lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in  DWORD  nSize
 , BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetPrivateProfileStringW IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileStringW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in  LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in  LPCWSTR lpKeyName
 , BYREF lpDefault AS WSTRINGZ _                        ' __in  LPCWSTR lpDefault
 , BYREF lpReturnedString AS WSTRINGZ _                 ' __out LPWSTR  lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in  DWORD   nSize
 , BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetPrivateProfileString = GetPrivateProfileStringW
#ELSE
   MACRO GetPrivateProfileString = GetPrivateProfileStringA
#ENDIF

DECLARE FUNCTION WritePrivateProfileStringA IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileStringA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpKeyName AS ASCIIZ _                          ' __in LPCSTR lpKeyName
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WritePrivateProfileStringW IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileStringW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in LPCWSTR lpAppName
 , BYREF lpKeyName AS WSTRINGZ _                        ' __in LPCWSTR lpKeyName
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WritePrivateProfileString = WritePrivateProfileStringW
#ELSE
   MACRO WritePrivateProfileString = WritePrivateProfileStringA
#ENDIF

DECLARE FUNCTION GetPrivateProfileSectionA IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileSectionA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in LPCSTR lpAppName
 , BYREF lpReturnedString AS ASCIIZ _                   ' __out LPSTR lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetPrivateProfileSectionW IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileSectionW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in  LPCWSTR lpAppName
 , BYREF lpReturnedString AS WSTRINGZ _                 ' __out LPWSTR  lpReturnedString
 , BYVAL nSize AS DWORD _                               ' __in DWORD    nSize
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR  lpFileName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetPrivateProfileSection = GetPrivateProfileSectionW
#ELSE
   MACRO GetPrivateProfileSection = GetPrivateProfileSectionA
#ENDIF

DECLARE FUNCTION WritePrivateProfileSectionA IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileSectionA" ( _
   BYREF lpAppName AS ASCIIZ _                          ' __in_opt LPCSTR lpAppName
 , BYREF lpString AS ASCIIZ _                           ' __in_opt LPCSTR lpString
 , BYREF lpFileName AS ASCIIZ _                         ' __in_opt LPCSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WritePrivateProfileSectionW IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileSectionW" ( _
   BYREF lpAppName AS WSTRINGZ _                        ' __in_opt LPCWSTR lpAppName
 , BYREF lpString AS WSTRINGZ _                         ' __in_opt LPCWSTR lpString
 , BYREF lpFileName AS WSTRINGZ _                       ' __in_opt LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WritePrivateProfileSection = WritePrivateProfileSectionW
#ELSE
   MACRO WritePrivateProfileSection = WritePrivateProfileSectionA
#ENDIF

DECLARE FUNCTION GetPrivateProfileSectionNamesA IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileSectionNamesA" ( _
   BYREF lpszReturnBuffer AS ASCIIZ _                   ' __out LPSTR lpszReturnBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD  nSize
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetPrivateProfileSectionNamesW IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileSectionNamesW" ( _
   BYREF lpszReturnBuffer AS WSTRINGZ _                 ' __out LPWSTR lpszReturnBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD   nSize
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetPrivateProfileSectionNames = GetPrivateProfileSectionNamesW
#ELSE
   MACRO GetPrivateProfileSectionNames = GetPrivateProfileSectionNamesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrivateProfileStructA LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS ASCIIZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileStructA IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileStructA" ( _
   BYREF lpszSection AS ASCIIZ _                        ' __in LPCSTR  lpszSection
 , BYREF lpszKey AS ASCIIZ _                            ' __in LPCSTR  lpszKey
 , BYREF lpStruct AS ANY _                              ' __out LPVOID lpStruct
 , BYVAL uSizeStruct AS DWORD _                         ' __in UINT    uSizeStruct
 , BYREF szFile AS ASCIIZ _                             ' __in LPCSTR  szFile
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrivateProfileStructW LIB "Kernel32.dll" _
    ALIAS "GetPrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, BYVAL nSize AS DWORD, _
    lpFileName AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrivateProfileStructW IMPORT "KERNEL32.DLL" ALIAS "GetPrivateProfileStructW" ( _
   BYREF lpszSection AS WSTRINGZ _                      ' __in LPCWSTR lpszSection
 , BYREF lpszKey AS WSTRINGZ _                          ' __in LPCWSTR lpszKey
 , BYREF lpStruct AS ANY _                              ' __out LPVOID lpStruct
 , BYVAL uSizeStruct AS DWORD _                         ' __in UINT    uSizeStruct
 , BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrivateProfileStruct = GetPrivateProfileStructW
#ELSE
   MACRO GetPrivateProfileStruct = GetPrivateProfileStructA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WritePrivateProfileStructA LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructA" (lpApplicationName AS ASCIIZ, _
    lpKeyName AS ASCIIZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS ASCIIZ) AS LONG
#ELSE
DECLARE FUNCTION WritePrivateProfileStructA IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileStructA" ( _
   BYREF lpszSection AS ASCIIZ _                        ' __in LPCSTR lpszSection
 , BYREF lpszKey AS ASCIIZ _                            ' __in LPCSTR lpszKey
 , BYREF lpStruct AS ANY _                              ' __in LPVOID lpStruct
 , BYVAL uSizeStruct AS DWORD _                         ' __in UINT   uSizeStruct
 , BYREF szFile AS ASCIIZ _                             ' __in LPCSTR szFile
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WritePrivateProfileStructW LIB "Kernel32.dll" _
    ALIAS "WritePrivateProfileStructW" (lpApplicationName AS WSTRINGZ, _
    lpKeyName AS WSTRINGZ, BYVAL lpStruct AS DWORD, _
    BYVAL uSizeStruct AS DWORD, lpFileName AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION WritePrivateProfileStructW IMPORT "KERNEL32.DLL" ALIAS "WritePrivateProfileStructW" ( _
   BYREF lpszSection AS WSTRINGZ _                      ' __in LPCWSTR lpszSection
 , BYREF lpszKey AS WSTRINGZ _                          ' __in LPCWSTR lpszKey
 , BYREF lpStruct AS ANY _                              ' __in LPVOID  lpStruct
 , BYVAL uSizeStruct AS DWORD _                         ' __in UINT    uSizeStruct
 , BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WritePrivateProfileStruct = WritePrivateProfileStructW
#ELSE
   MACRO WritePrivateProfileStruct = WritePrivateProfileStructA
#ENDIF

DECLARE FUNCTION GetDriveTypeA IMPORT "KERNEL32.DLL" ALIAS "GetDriveTypeA" ( _
   BYREF lpRootPathName AS ASCIIZ _                     ' __in LPCSTR lpRootPathName
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetDriveTypeW IMPORT "KERNEL32.DLL" ALIAS "GetDriveTypeW" ( _
   BYREF lpRootPathName AS WSTRINGZ _                   ' __in LPCWSTR lpRootPathName
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetDriveType = GetDriveTypeW
#ELSE
   MACRO GetDriveType = GetDriveTypeA
#ENDIF

DECLARE FUNCTION GetSystemDirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetSystemDirectoryA" ( _
   BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT  uSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetSystemDirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetSystemDirectoryW" ( _
   BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT   uSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetSystemDirectory = GetSystemDirectoryW
#ELSE
   MACRO GetSystemDirectory = GetSystemDirectoryA
#ENDIF

DECLARE FUNCTION GetTempPathA IMPORT "KERNEL32.DLL" ALIAS "GetTempPathA" ( _
   BYVAL nBufferLength AS LONG _                        ' __in  DWORD nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetTempPathW IMPORT "KERNEL32.DLL" ALIAS "GetTempPathW" ( _
   BYVAL nBufferLength AS LONG _                        ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetTempPath = GetTempPathW
#ELSE
   MACRO GetTempPath = GetTempPathA
#ENDIF

DECLARE FUNCTION GetTempFileNameA IMPORT "KERNEL32.DLL" ALIAS "GetTempFileNameA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in  LPCSTR lpPathName
 , BYREF lpPrefixString AS ASCIIZ _                     ' __in  LPCSTR lpPrefixString
 , BYVAL uUnique AS DWORD _                             ' __in  UINT   uUnique
 , BYREF lpTempFileName AS ASCIIZ _                     ' __out LPSTR  lpTempFileName
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetTempFileNameW IMPORT "KERNEL32.DLL" ALIAS "GetTempFileNameW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in  LPCWSTR lpPathName
 , BYREF lpPrefixString AS WSTRINGZ _                   ' __in  LPCWSTR lpPrefixString
 , BYVAL uUnique AS DWORD _                             ' __in  UINT    uUnique
 , BYREF lpTempFileName AS WSTRINGZ _                   ' __out LPWSTR  lpTempFileName
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetTempFileName = GetTempFileNameW
#ELSE
   MACRO GetTempFileName = GetTempFileNameA
#ENDIF

DECLARE FUNCTION GetWindowsDirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetWindowsDirectoryA" ( _
   BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT  uSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetWindowsDirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetWindowsDirectoryW" ( _
   BYREF lpBuffer AS WSTRINGZ  _                        ' __out LPWSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT   uSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetWindowsDirectory = GetWindowsDirectoryW
#ELSE
   MACRO GetWindowsDirectory = GetWindowsDirectoryA
#ENDIF

DECLARE FUNCTION GetSystemWindowsDirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetSystemWindowsDirectoryA" ( _
   BYREF lpBuffer AS ASCIIZ  _                          ' __out LPSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT  uSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetSystemWindowsDirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetSystemWindowsDirectoryW" ( _
   BYREF lpBuffer AS WSTRINGZ  _                        ' __out LPWSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT   uSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetSystemWindowsDirectory = GetSystemWindowsDirectoryW
#ELSE
   MACRO GetSystemWindowsDirectory = GetSystemWindowsDirectoryA
#ENDIF

'#if _WIN32_WINNT >= 0x0501 || defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)

DECLARE FUNCTION GetSystemWow64DirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetSystemWow64DirectoryA" ( _
   BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT  uSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetSystemWow64DirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetSystemWow64DirectoryW" ( _
   BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL uSize AS DWORD _                               ' __in  UINT  uSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetSystemWow64Directory = GetSystemWow64DirectoryW
#ELSE
   MACRO GetSystemWow64Directory = GetSystemWow64DirectoryA
#ENDIF

DECLARE FUNCTION Wow64EnableWow64FsRedirection IMPORT "KERNEL32.DLL" ALIAS "Wow64EnableWow64FsRedirection" ( _
   BYVAL Wow64FsEnableRedirection AS BYTE _             ' __in BOOLEAN Wow64FsEnableRedirection
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION Wow64DisableWow64FsRedirection IMPORT "KERNEL32.DLL" ALIAS "Wow64DisableWow64FsRedirection" ( _
   BYREF OldValue AS DWORD _                            ' __out PVOID *OldValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Wow64RevertWow64FsRedirection IMPORT "KERNEL32.DLL" ALIAS "Wow64RevertWow64FsRedirection" ( _
   BYVAL OldValue AS DWORD _                            ' __in PVOID OldValue
 ) AS LONG                                              ' BOOL

'//
'// for GetProcAddress
'//
'typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_A)(__out_ecount_part_opt(uSize, return + 1) LPSTR lpBuffer, __in UINT uSize);
'typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_W)(__out_ecount_part_opt(uSize, return + 1) LPWSTR lpBuffer, __in UINT uSize);

'//
'// GetProcAddress only accepts GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A,
'// GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A, GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A.
'// The others are if you want to use the strings in some other way.
'//
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A      "GetSystemWow64DirectoryA"
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W     L"GetSystemWow64DirectoryA"
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A      "GetSystemWow64DirectoryW"
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W     L"GetSystemWow64DirectoryW"
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

$GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A  = "GetSystemWow64DirectoryA"
$$GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W = "GetSystemWow64DirectoryA"$$
$GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A  = "GetSystemWow64DirectoryW"
$$GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W = "GetSystemWow64DirectoryW"$$

#IF %DEF(%UNICODE)
   MACRO GET_SYSTEM_WOW64_DIRECTORY_NAME = $GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#ELSE
   MACRO GET_SYSTEM_WOW64_DIRECTORY_NAME = $$GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#ENDIF

'#ifdef UNICODE
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
'#else
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
'#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
'#endif

'#endif // _WIN32_WINNT >= 0x0501
'#endif

DECLARE FUNCTION SetCurrentDirectoryA IMPORT "KERNEL32.DLL" ALIAS "SetCurrentDirectoryA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCurrentDirectoryW IMPORT "KERNEL32.DLL" ALIAS "SetCurrentDirectoryW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetCurrentDirectory = SetCurrentDirectoryW
#ELSE
   MACRO SetCurrentDirectory = SetCurrentDirectoryA
#ENDIF

DECLARE FUNCTION GetCurrentDirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetCurrentDirectoryA" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCurrentDirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetCurrentDirectoryW" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetCurrentDirectory = GetCurrentDirectoryW
#ELSE
   MACRO GetCurrentDirectory = GetCurrentDirectoryA
#ENDIF

'#if _WIN32_WINNT >= 0x0502

DECLARE FUNCTION SetDllDirectoryA IMPORT "KERNEL32.DLL" ALIAS "SetDllDirectoryA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetDllDirectoryW IMPORT "KERNEL32.DLL" ALIAS "SetDllDirectoryW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetDllDirectory = SetDllDirectoryW
#ELSE
   MACRO SetDllDirectory = SetDllDirectoryA
#ENDIF

DECLARE FUNCTION GetDllDirectoryA IMPORT "KERNEL32.DLL" ALIAS "GetDllDirectory" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetDllDirectoryW IMPORT "KERNEL32.DLL" ALIAS "GetDllDirectoryW" ( _
   BYVAL nBufferLength AS DWORD _                       ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetDllDirectory = GetDllDirectoryW
#ELSE
   MACRO GetDllDirectory = GetDllDirectoryA
#ENDIF

'#endif // _WIN32_WINNT >= 0x0502

%BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE = &H1???
%BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE = &H10000???
%BASE_SEARCH_PATH_PERMANENT = &H8000???
%BASE_SEARCH_PATH_INVALID_FLAGS = NOT &H18001???   ' ~0x18001

DECLARE FUNCTION SetSearchPathMode IMPORT "KERNEL32.DLL" ALIAS "SetSearchPathMode" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDiskFreeSpaceA IMPORT "KERNEL32.DLL" ALIAS "GetDiskFreeSpaceA" ( _
   BYREF lpRootPathName AS ASCIIZ _                     ' __in  LPCSTR  lpRootPathName
 , BYREF lpSectorsPerCluster AS DWORD _                 ' __out LPDWORD lpSectorsPerCluster
 , BYREF lpBytesPerSector AS DWORD _                    ' __out LPDWORD lpBytesPerSector
 , BYREF lpNumberOfFreeClusters AS DWORD _              ' __out LPDWORD lpNumberOfFreeClusters
 , BYREF lpTotalNumberOfClusters AS DWORD _             ' __out LPDWORD lpTotalNumberOfClusters
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDiskFreeSpaceW IMPORT "KERNEL32.DLL" ALIAS "GetDiskFreeSpaceW" ( _
   BYREF lpRootPathName AS WSTRINGZ _                   ' __in  LPCWSTR lpRootPathName
 , BYREF lpSectorsPerCluster AS DWORD _                 ' __out LPDWORD lpSectorsPerCluster
 , BYREF lpBytesPerSector AS DWORD _                    ' __out LPDWORD lpBytesPerSector
 , BYREF lpNumberOfFreeClusters AS DWORD _              ' __out LPDWORD lpNumberOfFreeClusters
 , BYREF lpTotalNumberOfClusters AS DWORD _             ' __out LPDWORD lpTotalNumberOfClusters
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetDiskFreeSpace = GetDiskFreeSpaceW
#ELSE
   MACRO GetDiskFreeSpace = GetDiskFreeSpaceA
#ENDIF

DECLARE FUNCTION GetDiskFreeSpaceExA IMPORT "KERNEL32.DLL" ALIAS "GetDiskFreeSpaceExA" ( _
   BYREF lpDirectoryName AS ASCIIZ _                    ' __in  LPCSTR  lpDirectoryName
 , BYREF lpFreeBytesAvailableToCaller AS QUAD _         ' __out PULARGE_INTEGER lpFreeBytesAvailableToCaller
 , BYREF lpTotalNumberOfBytes AS QUAD _                 ' __out PULARGE_INTEGER lpTotalNumberOfBytes
 , BYREF lpTotalNumberOfFreeBytes AS QUAD _             ' __out PULARGE_INTEGER lpTotalNumberOfFreeBytes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDiskFreeSpaceExW IMPORT "KERNEL32.DLL" ALIAS "GetDiskFreeSpaceExW" ( _
   BYREF lpDirectoryName AS WSTRINGZ _                  ' __in  LPCWSTR lpDirectoryName
 , BYREF lpFreeBytesAvailableToCaller AS QUAD _         ' __out PULARGE_INTEGER lpFreeBytesAvailableToCaller
 , BYREF lpTotalNumberOfBytes AS QUAD _                 ' __out PULARGE_INTEGER lpTotalNumberOfBytes
 , BYREF lpTotalNumberOfFreeBytes AS QUAD _             ' __out PULARGE_INTEGER lpTotalNumberOfFreeBytes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetDiskFreeSpaceEx = GetDiskFreeSpaceExW
#ELSE
   MACRO GetDiskFreeSpaceEx = GetDiskFreeSpaceExA
#ENDIF

DECLARE FUNCTION CreateDirectoryA IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateDirectoryW IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateDirectory = CreateDirectoryW
#ELSE
   MACRO CreateDirectory = CreateDirectoryA
#ENDIF

DECLARE FUNCTION CreateDirectoryExA IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryExA" ( _
   BYREF lpTemplateDirectory AS ASCIIZ _                ' __in LPCSTR lpTemplateDirectory
 , BYREF lpNewDirectory AS ASCIIZ _                     ' __in LPCSTR lpNewDirectory
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateDirectoryExW IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryExW" ( _
   BYREF lpTemplateDirectory AS WSTRINGZ _              ' __in LPCWSTR lpTemplateDirectory
 , BYREF lpNewDirectory AS WSTRINGZ _                   ' __in LPCWSTR lpNewDirectory
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateDirectoryEx = CreateDirectoryExW
#ELSE
   MACRO CreateDirectoryEx = CreateDirectoryExA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION CreateDirectoryTransactedA IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryTransactedA" ( _
   BYREF lpTemplateDirectory AS ASCIIZ _                ' __in_opt LPCSTR lpTemplateDirectory
 , BYREF lpNewDirectory AS ASCIIZ _                     ' __in LPCSTR lpNewDirectory
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateDirectoryTransactedW IMPORT "KERNEL32.DLL" ALIAS "CreateDirectoryTransactedW" ( _
   BYREF lpTemplateDirectory AS WSTRINGZ _              ' __in_opt LPCWSTR lpTemplateDirectory
 , BYREF lpNewDirectory AS WSTRINGZ _                   ' __in LPCWSTR lpNewDirectory
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateDirectoryTransacted = CreateDirectoryTransactedW
#ELSE
   MACRO CreateDirectoryTransacted = CreateDirectoryTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION RemoveDirectoryA IMPORT "KERNEL32.DLL" ALIAS "RemoveDirectoryA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveDirectoryW IMPORT "KERNEL32.DLL" ALIAS "RemoveDirectoryW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RemoveDirectory = RemoveDirectoryW
#ELSE
   MACRO RemoveDirectory = RemoveDirectoryA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION RemoveDirectoryTransactedA IMPORT "KERNEL32.DLL" ALIAS "RemoveDirectoryTransactedA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveDirectoryTransactedW IMPORT "KERNEL32.DLL" ALIAS "RemoveDirectoryTransactedW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RemoveDirectoryTransacted = RemoveDirectoryTransactedW
#ELSE
   MACRO RemoveDirectoryTransacted = RemoveDirectoryTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION GetFullPathNameA IMPORT "KERNEL32.DLL" ALIAS "GetFullPathNameA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR  lpBuffer
 , OPTIONAL BYREF lpFilePart AS DWORD _                 ' __out_opt LPSTR *lpFilePart
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFullPathNameW IMPORT "KERNEL32.DLL" ALIAS "GetFullPathNameW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD   nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR  lpBuffer
 , OPTIONAL BYREF lpFilePart AS DWORD _                 ' __out_opt LPWSTR *lpFilePart
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFullPathName = GetFullPathNameW
#ELSE
   MACRO GetFullPathName = GetFullPathNameA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION GetFullPathNameTransactedA IMPORT "KERNEL32.DLL" ALIAS "GetFullPathNameTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR  lpBuffer
 , BYREF lpFilePart AS DWORD _                            ' __out LPSTR *lpFilePart
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFullPathNameTransactedW IMPORT "KERNEL32.DLL" ALIAS "GetFullPathNameTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD   nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR  lpBuffer
 , BYREF lpFilePart AS DWORD _                          ' __out LPWSTR *lpFilePart
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE  hTransaction
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFullPathNameTransacted = GetFullPathNameTransactedW
#ELSE
   MACRO GetFullPathNameTransacted = GetFullPathNameTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600


%DDD_RAW_TARGET_PATH         = &H00000001???
%DDD_REMOVE_DEFINITION       = &H00000002???
%DDD_EXACT_MATCH_ON_REMOVE   = &H00000004???
%DDD_NO_BROADCAST_SYSTEM     = &H00000008???
%DDD_LUID_BROADCAST_DRIVE    = &H00000010???

DECLARE FUNCTION DefineDosDeviceA IMPORT "KERNEL32.DLL" ALIAS "DefineDosDeviceA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYREF lpDeviceName AS ASCIIZ _                       ' __in LPCSTR lpDeviceName
 , BYREF lpTargetPath AS ASCIIZ _                       ' __in LPCSTR lpTargetPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DefineDosDeviceW IMPORT "KERNEL32.DLL" ALIAS "DefineDosDeviceW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYREF lpDeviceName AS WSTRINGZ _                     ' __in LPCWSTR lpDeviceName
 , BYREF lpTargetPath AS WSTRINGZ _                     ' __in LPCWSTR lpTargetPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DefineDosDevice = DefineDosDeviceW
#ELSE
   MACRO DefineDosDevice = DefineDosDeviceA
#ENDIF

DECLARE FUNCTION QueryDosDeviceA IMPORT "KERNEL32.DLL" ALIAS "QueryDosDeviceA" ( _
   BYREF lpDeviceName AS ASCIIZ _                       ' __in LPCSTR lpDeviceName
 , BYREF lpTargetPath AS ASCIIZ _                       ' __out LPSTR lpTargetPath
 , BYVAL ucchMax AS DWORD _                             ' __in DWORD  ucchMax
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION QueryDosDeviceW IMPORT "KERNEL32.DLL" ALIAS "QueryDosDeviceW" ( _
   BYREF lpDeviceName AS WSTRINGZ _                     ' __in LPCWSTR lpDeviceName
 , BYREF lpTargetPath AS WSTRINGZ _                     ' __out LPWSTR lpTargetPath
 , BYVAL ucchMax AS DWORD _                             ' __in DWORD   ucchMax
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO QueryDosDevice = QueryDosDeviceW
#ELSE
   MACRO QueryDosDevice = QueryDosDeviceA
#ENDIF

'#define EXPAND_LOCAL_DRIVES

DECLARE FUNCTION CreateFileA IMPORT "KERNEL32.DLL" ALIAS "CreateFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL hTemplateFile AS DWORD _                       ' __in HANDLE hTemplateFile
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateFileW IMPORT "KERNEL32.DLL" ALIAS "CreateFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL hTemplateFile AS DWORD _                       ' __in HANDLE hTemplateFile
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateFile = CreateFileW
#ELSE
   MACRO CreateFile = CreateFileA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION CreateFileTransactedA IMPORT "KERNEL32.DLL" ALIAS "CreateFileTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL hTemplateFile AS DWORD _                       ' __in HANDLE hTemplateFile
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYREF pusMiniVersion AS WORD _                       ' __in PUSHORT pusMiniVersion
 , BYVAL lpExtendedParameter AS DWORD _                 ' __in PVOID lpExtendedParameter
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateFileTransactedW IMPORT "KERNEL32.DLL" ALIAS "CreateFileTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL hTemplateFile AS DWORD _                       ' __in HANDLE hTemplateFile
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYREF pusMiniVersion AS WORD _                       ' __in PUSHORT pusMiniVersion
 , BYVAL lpExtendedParameter AS DWORD _                 ' __in PVOID lpExtendedParameter
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateFileTransacted = CreateFileTransactedW
#ELSE
   MACRO CreateFileTransacted = CreateFileTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

'#if _WIN32_WINNT >= 0x0502

DECLARE FUNCTION ReOpenFile IMPORT "KERNEL32.DLL" ALIAS "ReOpenFile" ( _
   BYVAL hOriginalFile AS DWORD _                       ' __in HANDLE  hOriginalFile
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD   dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD   dwShareMode
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD   dwFlagsAndAttributes
 ) AS DWORD                                             ' HANDLE

'#endif // _WIN32_WINNT >= 0x0502

DECLARE FUNCTION SetFileAttributesA IMPORT "KERNEL32.DLL" ALIAS "SetFileAttributesA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD dwFileAttributes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileAttributesW IMPORT "KERNEL32.DLL" ALIAS "SetFileAttributesW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD dwFileAttributes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetFileAttributes = SetFileAttributesW
#ELSE
   MACRO SetFileAttributes = SetFileAttributesA
#ENDIF

DECLARE FUNCTION GetFileAttributesA IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFileAttributesW IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFileAttributes = GetFileAttributesW
#ELSE
   MACRO GetFileAttributes = GetFileAttributesA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION SetFileAttributesTransactedA IMPORT "KERNEL32.DLL" ALIAS "SetFileAttributesTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD  dwFileAttributes
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileAttributesTransactedW IMPORT "KERNEL32.DLL" ALIAS "SetFileAttributesTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                      ' __in LPCWSTR lpFileName
 , BYVAL dwFileAttributes AS DWORD _                   ' __in DWORD   dwFileAttributes
 , BYVAL hTransaction AS DWORD _                       ' __in HANDLE  hTransaction
 ) AS LONG                                             ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetFileAttributesTransacted = SetFileAttributesTransactedW
#ELSE
   MACRO SetFileAttributesTransacted = SetFileAttributesTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

' GET_FILEEX_INFO_LEVELS enum
%GetFileExInfoStandard = 0
%GetFileExMaxInfoLevel = 1

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFileAttributesTransactedA LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesTransactedA IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  GET_FILEEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFileInformation AS ANY _                     ' __out LPVOID lpFileInformation
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFileAttributesTransactedW LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesTransactedW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFileInformation AS DWORD, _
    BYVAL hTransaction AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesTransactedW IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  GET_FILEEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFileInformation AS ANY _                     ' __out LPVOID lpFileInformation
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetFileAttributesTransacted = GetFileAttributesTransactedW
#ELSE
   MACRO GetFileAttributesTransacted = GetFileAttributesTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFileAttributesExA LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExA" (lpFileName AS ASCIIZ, _
    BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFileInformation AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesExA IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesExA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  GET_FILEEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFileInformation AS ANY _                     ' __out LPVOID lpFileInformation
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFileAttributesExW LIB "Kernel32.dll" _
    ALIAS "GetFileAttributesExW" (lpFileName AS WSTRINGZ, _
    BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFileInformation AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileAttributesExW IMPORT "KERNEL32.DLL" ALIAS "GetFileAttributesExW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  GET_FILEEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFileInformation AS ANY _                     ' __out LPVOID lpFileInformation
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetFileAttributesEx = GetFileAttributesExW
#ELSE
   MACRO GetFileAttributesEx = GetFileAttributesExA
#ENDIF

DECLARE FUNCTION GetCompressedFileSizeA IMPORT "KERNEL32.DLL" ALIAS "GetCompressedFileSizeA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR  lpFileName
 , BYREF lpFileSizeHigh AS DWORD _                      ' __out LPDWORD lpFileSizeHigh
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCompressedFileSizeW IMPORT "KERNEL32.DLL" ALIAS "GetCompressedFileSizeW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF lpFileSizeHigh AS DWORD _                      ' __out LPDWORD lpFileSizeHigh
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetCompressedFileSize = GetCompressedFileSizeW
#ELSE
   MACRO GetCompressedFileSize = GetCompressedFileSizeA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION GetCompressedFileSizeTransactedA IMPORT "KERNEL32.DLL" ALIAS "GetCompressedFileSizeTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR  lpFileName
 , BYREF lpFileSizeHigh AS DWORD _                      ' __out LPDWORD lpFileSizeHigh
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE  hTransaction
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCompressedFileSizeTransactedW IMPORT "KERNEL32.DLL" ALIAS "GetCompressedFileSizeTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF lpFileSizeHigh AS DWORD _                      ' __out LPDWORD lpFileSizeHigh
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE  hTransaction
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetCompressedFileSizeTransacted = GetCompressedFileSizeTransactedW
#ELSE
   MACRO GetCompressedFileSizeTransacted = GetCompressedFileSizeTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION DeleteFileA IMPORT "KERNEL32.DLL" ALIAS "DeleteFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteFileW IMPORT "KERNEL32.DLL" ALIAS "DeleteFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteFile = DeleteFileW
#ELSE
   MACRO DeleteFile = DeleteFileA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION DeleteFileTransactedA IMPORT "KERNEL32.DLL" ALIAS "DeleteFileTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteFileTransactedW IMPORT "KERNEL32.DLL" ALIAS "DeleteFileTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE  hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteFileTransacted = DeleteFileTransactedW
#ELSE
   MACRO DeleteFileTransacted = DeleteFileTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION CheckNameLegalDOS8Dot3A IMPORT "KERNEL32.DLL" ALIAS "CheckNameLegalDOS8Dot3A" ( _
   BYREF lpName AS ASCIIZ _                             ' __in  LPCSTR lpName
 , BYREF lpOemName AS ASCIIZ _                          ' __out LPSTR  lpOemName
 , BYVAL OemNameSize AS DWORD _                         ' __in  DWORD  OemNameSize
 , BYREF pbNameContainsSpaces AS LONG _                 ' __out PBOOL  pbNameContainsSpaces OPTIONAL
 , BYREF pbNameLegal AS LONG _                          ' __out PBOOL  pbNameLegal
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CheckNameLegalDOS8Dot3W IMPORT "KERNEL32.DLL" ALIAS "CheckNameLegalDOS8Dot3W" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in  LPCWSTR lpName
 , BYREF lpOemName AS WSTRINGZ _                        ' __out LPWSTR  lpOemName
 , BYVAL OemNameSize AS DWORD _                         ' __in  DWORD   OemNameSize
 , BYREF pbNameContainsSpaces AS LONG _                 ' __out PBOOL   pbNameContainsSpaces OPTIONAL
 , BYREF pbNameLegal AS LONG _                          ' __out PBOOL   pbNameLegal
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CheckNameLegalDOS8Dot3 = CheckNameLegalDOS8Dot3W
#ELSE
   MACRO CheckNameLegalDOS8Dot3 = CheckNameLegalDOS8Dot3A
#ENDIF

'#endif // (_WIN32_WINNT >= 0x0501)

'#if(_WIN32_WINNT >= 0x0400)
' FINDEX_INFO_LEVELS enum
%FindExInfoStandard     = 0
%FindExInfoBasic        = 1
%FindExInfoMaxInfoLevel = 2

' FINDEX_SEARCH_OPS enum
%FindExSearchNameMatch          = 0
%FindExSearchLimitToDirectories = 1
%FindExSearchLimitToDevices     = 2
%FindExSearchMaxSearchOp        = 3

%FIND_FIRST_EX_CASE_SENSITIVE = &H00000001???
%FIND_FIRST_EX_LARGE_FETCH    = &H00000002???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FindFirstFileExA LIB "Kernel32.dll" ALIAS "FindFirstFileExA" _
    (lpFileName AS ASCIIZ, BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS LONG, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstFileExA IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileExA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  FINDEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFindFileData AS ANY _                        ' __out LPVOID lpFindFileData
 , BYVAL fSearchOp AS LONG _                            ' __in  FINDEX_SEARCH_OPS fSearchOp
 , BYVAL lpSearchFilter AS DWORD _                      ' __in  LPVOID lpSearchFilter
 , BYVAL dwAdditionalFlags AS DWORD _                   ' __in  DWORD dwAdditionalFlags
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FindFirstFileExW LIB "Kernel32.dll" ALIAS "FindFirstFileExW" _
    (lpFileName AS WSTRINGZ, BYVAL fInfoLevelId AS LONG, _
    BYVAL lpFindFileData AS DWORD, BYVAL fSearchOp AS LONG, _
    BYVAL lpSearchFilter AS DWORD, BYVAL dwAdditionalFlags AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION FindFirstFileExW IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileExW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  FINDEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFindFileData AS ANY _                        ' __out LPVOID lpFindFileData
 , BYVAL fSearchOp AS LONG _                            ' __in  FINDEX_SEARCH_OPS fSearchOp
 , BYVAL lpSearchFilter AS DWORD _                      ' __in  LPVOID lpSearchFilter
 , BYVAL dwAdditionalFlags AS DWORD _                   ' __in  DWORD dwAdditionalFlags
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%UNICODE)
   MACRO FindFirstFileEx = FindFirstFileExW
#ELSE
   MACRO FindFirstFileEx = FindFirstFileExA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION FindFirstFileTransactedA IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  FINDEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFindFileData AS ANY _                        ' __out LPVOID lpFindFileData
 , BYVAL fSearchOp AS LONG _                            ' __in  FINDEX_SEARCH_OPS fSearchOp
 , BYVAL lpSearchFilter AS DWORD _                      ' __in  LPVOID lpSearchFilter
 , BYVAL dwAdditionalFlags AS DWORD _                   ' __in  DWORD dwAdditionalFlags
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstFileTransactedW IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in  FINDEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFindFileData AS ANY _                        ' __out LPVOID lpFindFileData
 , BYVAL fSearchOp AS LONG _                            ' __in  FINDEX_SEARCH_OPS fSearchOp
 , BYVAL lpSearchFilter AS DWORD _                      ' __in  LPVOID lpSearchFilter
 , BYVAL dwAdditionalFlags AS DWORD _                   ' __in  DWORD dwAdditionalFlags
 , BYVAL hTransaction AS DWORD _                        ' __in  HANDLE hTransaction
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstFileTransacted = FindFirstFileTransactedW
#ELSE
   MACRO FindFirstFileTransacted = FindFirstFileTransactedA
#ENDIF

#ENDIF

DECLARE FUNCTION FindFirstFileA IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYREF lpFindFileData AS WIN32_FIND_DATAA _           ' __out LPWIN32_FIND_DATAA lpFindFileData
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstFileW IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF lpFindFileData AS WIN32_FIND_DATAW _           ' __out LPWIN32_FIND_DATAW lpFindFileData
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstFile = FindFirstFileW
#ELSE
   MACRO FindFirstFile = FindFirstFileA
#ENDIF

DECLARE FUNCTION FindNextFileA IMPORT "KERNEL32.DLL" ALIAS "FindNextFileA" ( _
   BYVAL hFindFile AS DWORD _                           ' __in  HANDLE hFindFile
 , BYREF lpFindFileData AS WIN32_FIND_DATAA _           ' __out LPWIN32_FIND_DATAA lpFindFileData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextFileW IMPORT "KERNEL32.DLL" ALIAS "FindNextFileW" ( _
   BYVAL hFindFile AS DWORD _                           ' __in  HANDLE hFindFile
 , BYREF lpFindFileData AS WIN32_FIND_DATAW _           ' __out LPWIN32_FIND_DATAW lpFindFileData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextFile = FindNextFileW
#ELSE
   MACRO FindNextFile = FindNextFileA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SearchPathA LIB "Kernel32.dll" ALIAS "SearchPathA" _
    (lpPath AS ASCIIZ, lpFileName AS ASCIIZ, lpExtension AS ASCIIZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS ASCIIZ, lpFilePart AS ASCIIZ) _
    AS DWORD
#ELSE
DECLARE FUNCTION SearchPathA IMPORT "KERNEL32.DLL" ALIAS "SearchPathA" ( _
   BYREF lpPath AS ASCIIZ _                             ' __in  LPCSTR lpPath
 , BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYREF lpExtension AS ASCIIZ _                        ' __in  LPCSTR lpExtension
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD  nBufferLength
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR  lpBuffer
 , OPTIONAL BYREF lpFilePart AS DWORD _                 ' __out_opt LPSTR *lpFilePart
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SearchPathW LIB "Kernel32.dll" ALIAS "SearchPathW" _
    (lpPath AS WSTRINGZ, lpFileName AS WSTRINGZ, lpExtension AS WSTRINGZ, _
    BYVAL nBufferLength AS LONG, lpBuffer AS WSTRINGZ, _
    lpFilePart AS WSTRINGZ) AS DWORD
#ELSE
DECLARE FUNCTION SearchPathW IMPORT "KERNEL32.DLL" ALIAS "SearchPathW" ( _
   BYREF lpPath AS WSTRINGZ _                           ' __in  LPCWSTR lpPath
 , BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF lpExtension AS WSTRINGZ _                      ' __in  LPCWSTR lpExtension
 , BYVAL nBufferLength AS DWORD _                       ' __in  DWORD   nBufferLength
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR  lpBuffer
 , OPTIONAL BYREF lpFilePart AS DWORD _                 ' __out_opt LPWSTR *lpFilePart
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SearchPath = SearchPathW
#ELSE
   MACRO SearchPath = SearchPathA
#ENDIF

DECLARE FUNCTION CopyFileA IMPORT "KERNEL32.DLL" ALIAS "CopyFileA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL bFailIfExists AS LONG _                        ' __in BOOL   bFailIfExists
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CopyFileW IMPORT "KERNEL32.DLL" ALIAS "CopyFileW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL bFailIfExists AS LONG _                        ' __in BOOL    bFailIfExists
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CopyFile = CopyFileW
#ELSE
   MACRO CopyFile = CopyFileA
#ENDIF

'#if(_WIN32_WINNT >= 0x0400)
'typedef
'DWORD
'(WINAPI *LPPROGRESS_ROUTINE)(
'    __in LARGE_INTEGER TotalFileSize,
'    __in LARGE_INTEGER TotalBytesTransferred,
'    __in LARGE_INTEGER StreamSize,
'    __in LARGE_INTEGER StreamBytesTransferred,
'    __in DWORD dwStreamNumber,
'    __in DWORD dwCallbackReason,
'    __in HANDLE hSourceFile,
'    __in HANDLE hDestinationFile,
'    __in LPVOID lpData
'    );

DECLARE FUNCTION CopyFileExA IMPORT "KERNEL32.DLL" ALIAS "CopyFileExA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData
 , BYREF pbCancel AS LONG _                             ' __in LPBOOL pbCancel
 , BYVAL dwCopyFlags AS DWORD _                         ' __in DWORD dwCopyFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CopyFileExW IMPORT "KERNEL32.DLL" ALIAS "CopyFileExW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD  _                             ' __in LPVOID lpData
 , BYREF pbCancel AS LONG  _                            ' __in LPBOOL pbCancel
 , BYVAL dwCopyFlags AS DWORD _                         ' __in DWORD dwCopyFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CopyFileEx = CopyFileExW
#ELSE
   MACRO CopyFileEx = CopyFileExA
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION CopyFileTransactedA IMPORT "KERNEL32.DLL" ALIAS "CopyFileTransactedA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData
 , BYREF pbCancel AS LONG _                             ' __in LPBOOL pbCancel
 , BYVAL dwCopyFlags AS DWORD _                         ' __in DWORD dwCopyFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CopyFileTransactedW IMPORT "KERNEL32.DLL" ALIAS "CopyFileTransactedW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD  _                             ' __in LPVOID lpData
 , BYREF pbCancel AS LONG  _                            ' __in LPBOOL pbCancel
 , BYVAL dwCopyFlags AS DWORD _                         ' __in DWORD dwCopyFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CopyFileTransacted = CopyFileTransactedW
#ELSE
   MACRO CopyFileTransacted = CopyFileTransactedA
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600
'#ENDIF ' /* _WIN32_WINNT >= 0x0400 */

DECLARE FUNCTION MoveFileA IMPORT "KERNEL32.DLL" ALIAS "MoveFileA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MoveFileW IMPORT "KERNEL32.DLL" ALIAS "MoveFileW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO MoveFile = MoveFileW
#ELSE
   MACRO MoveFile = MoveFileA
#ENDIF

DECLARE FUNCTION MoveFileExA IMPORT "KERNEL32.DLL" ALIAS "MoveFileExA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MoveFileExW IMPORT "KERNEL32.DLL" ALIAS "MoveFileExW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO MoveFileEx = MoveFileExW
#ELSE
   MACRO MoveFileEx = MoveFileExA
#ENDIF

'#if (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION MoveFileWithProgressA IMPORT "KERNEL32.DLL" ALIAS "MoveFileWithProgressA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MoveFileWithProgressW IMPORT "KERNEL32.DLL" ALIAS "MoveFileWithProgressW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD  _                             ' __in LPVOID lpData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO MoveFileWithProgress = MoveFileWithProgressW
#ELSE
   MACRO MoveFileWithProgress = MoveFileWithProgressA
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION MoveFileTransactedA IMPORT "KERNEL32.DLL" ALIAS "MoveFileTransactedA" ( _
   BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpNewFileName AS ASCIIZ _                      ' __in LPCSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MoveFileTransactedW IMPORT "KERNEL32.DLL" ALIAS "MoveFileTransactedW" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpData AS DWORD  _                             ' __in LPVOID lpData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO MoveFileTransacted = MoveFileTransactedW
#ELSE
   MACRO MoveFileTransacted = MoveFileTransactedA
#ENDIF

#ENDIF ' // (_WIN32_WINNT >= 0x0600)

%MOVEFILE_REPLACE_EXISTING      = &H00000001???
%MOVEFILE_COPY_ALLOWED          = &H00000002???
%MOVEFILE_DELAY_UNTIL_REBOOT    = &H00000004???
%MOVEFILE_WRITE_THROUGH         = &H00000008???
'#if (_WIN32_WINNT >= 0x0500)
%MOVEFILE_CREATE_HARDLINK       = &H00000010???
%MOVEFILE_FAIL_IF_NOT_TRACKABLE = &H00000020???
'#endif // (_WIN32_WINNT >= 0x0500)


'#if (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION ReplaceFileA IMPORT "KERNEL32.DLL" ALIAS "ReplaceFileA" ( _
   BYREF lpReplacedFileName AS ASCIIZ _                 ' __in LPCSTR  lpReplacedFileName
 , BYREF lpReplacementFileName AS ASCIIZ _              ' __in LPCSTR  lpReplacementFileName
 , BYREF lpBackupFileName AS ASCIIZ _                   ' __in LPCSTR  lpBackupFileName
 , BYVAL dwReplaceFlags AS DWORD _                      ' __in DWORD   dwReplaceFlags
 , BYVAL lpExclude AS DWORD _                           ' __in LPVOID  lpExclude
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID  lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReplaceFileW IMPORT "KERNEL32.DLL" ALIAS "ReplaceFileW" ( _
   BYREF lpReplacedFileName AS WSTRINGZ _               ' __in LPCWSTR  lpReplacedFileName
 , BYREF lpReplacementFileName AS WSTRINGZ _            ' __in LPCWSTR  lpReplacementFileName
 , BYREF lpBackupFileName AS WSTRINGZ _                 ' __in LPCWSTR  lpBackupFileName
 , BYVAL dwReplaceFlags AS DWORD _                      ' __in DWORD   dwReplaceFlags
 , BYVAL lpExclude AS DWORD _                           ' __in LPVOID  lpExclude
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID  lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ReplaceFile = ReplaceFileW
#ELSE
   MACRO ReplaceFile = ReplaceFileA
#ENDIF

'#if (_WIN32_WINNT >= 0x0500)
'//
'// API call to create hard links.
'//

DECLARE FUNCTION CreateHardLinkA IMPORT "KERNEL32.DLL" ALIAS "CreateHardLinkA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateHardLinkW IMPORT "KERNEL32.DLL" ALIAS "CreateHardLinkW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateHardLink = CreateHardLinkW
#ELSE
   MACRO CreateHardLink = CreateHardLinkA
#ENDIF

'#endif // (_WIN32_WINNT >= 0x0500)

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
'//
'// API call to create hard links.
'//

DECLARE FUNCTION CreateHardLinkTransactedA IMPORT "KERNEL32.DLL" ALIAS "CreateHardLinkTransactedA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYREF lpExistingFileName AS ASCIIZ _                 ' __in LPCSTR lpExistingFileName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateHardLinkTransactedW IMPORT "KERNEL32.DLL" ALIAS "CreateHardLinkTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateHardLinkTransacted = CreateHardLinkTransactedW
#ELSE
   MACRO CreateHardLinkTransacted = CreateHardLinkTransactedA
#ENDIF

#ENDIF ' // (_WIN32_WINNT >= 0x0600)


'#if (_WIN32_WINNT >= 0x0501)

'//
'// API call to enumerate for streams within a file
'//

' STREAM_INFO_LEVELS enum
%FindStreamInfoStandard     = 0
%FindStreamInfoMaxInfoLevel = 1

' // Size = 600 bytes
TYPE WIN32_FIND_STREAM_DATA   ' Must be 8 byte aligned
   StreamSize  AS QUAD                        ' LARGE_INTEGER StreamSize
   cStreamName AS WSTRINGZ * %MAX_PATH + 36   ' WCHAR cStreamName[ MAX_PATH + 36 ]
END TYPE

DECLARE FUNCTION FindFirstStreamW IMPORT "KERNEL32.DLL" ALIAS "FindFirstStreamW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL InfoLevel AS DWORD _                           ' __in  STREAM_INFO_LEVELS InfoLevel
 , BYREF lpFindStreamData AS ANY _                      ' __out LPVOID lpFindStreamData
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS DWORD                                             ' HANDLE

MACRO FindFirstStream = FindFirstStreamW

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600
DECLARE FUNCTION FindFirstStreamTransactedW IMPORT "KERNEL32.DLL" ALIAS "FindFirstStreamTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL InfoLevel AS DWORD _                           ' __in  STREAM_INFO_LEVELS InfoLevel
 , BYREF lpFindStreamData AS ANY _                      ' __out LPVOID lpFindStreamData
 , BYVAL dwFlags AS DWORD _                             ' __reserved DWORD dwFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS DWORD                                             ' HANDLE
#ENDIF

MACRO FindFirstStreamTransacted = FindFirstStreamTransactedW
'#endif // _WIN32_WINNT >= 0x600

DECLARE FUNCTION FindNextStreamW IMPORT "KERNEL32.DLL" ALIAS "FindNextStreamW" ( _
   BYVAL hFindStream AS DWORD _                         ' __in  HANDLE hFindStream
 , BYREF lpFindStreamData AS ANY _                      ' __out LPVOID lpFindStreamData
 ) AS LONG                                              ' BOOL

MACRO FindNextStream = FindNextStreamW
'#endif // (_WIN32_WINNT >= 0x0501)

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION FindFirstFileNameW IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileNameW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF StringLength AS DWORD _                        ' __inout LPDWORD StringLength
 , BYREF LinkName AS WSTRINGZ _                         ' __in PWCHAR LinkName
 ) AS DWORD                                             ' HANDLE

MACRO FindFirstFileName = FindFirstFileNameW

DECLARE FUNCTION FindNextFileNameW IMPORT "KERNEL32.DLL" ALIAS "FindNextFileNameW" ( _
   BYVAL hFindStream AS DWORD _                         ' __in HANDLE hFindStream
 , BYREF StringLength AS DWORD _                        ' __inout LPDWORD StringLength
 , BYREF LinkName AS WSTRINGZ _                         ' __in PWCHAR LinkName
 ) AS LONG                                              ' BOOL

MACRO FindNextFileName = FindNextFileNameW

DECLARE FUNCTION FindFirstFileNameTransactedW IMPORT "KERNEL32.DLL" ALIAS "FindFirstFileNameTransactedW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF StringLength AS DWORD _                        ' __inout LPDWORD StringLength
 , BYREF LinkName AS WSTRINGZ _                         ' __in PWCHAR LinkName
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS DWORD                                             ' HANDLE

MACRO FindFirstFileNameTransacted = FindFirstFileNameTransactedW

#ENDIF


DECLARE FUNCTION CreateNamedPipeA IMPORT "KERNEL32.DLL" ALIAS "CreateNamedPipeA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL dwOpenMode AS DWORD _                          ' __in DWORD dwOpenMode
 , BYVAL dwPipeMode AS DWORD _                          ' __in DWORD dwPipeMode
 , BYVAL nMaxInstances AS DWORD _                       ' __in DWORD nMaxInstances
 , BYVAL nOutBufferSize AS DWORD _                      ' __in DWORD nOutBufferSize
 , BYVAL nInBufferSize AS DWORD _                       ' __in DWORD nInBufferSize
 , BYVAL nDefaultTimeOut AS DWORD _                     ' __in DWORD nDefaultTimeOut
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateNamedPipeW IMPORT "KERNEL32.DLL" ALIAS "CreateNamedPipeW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwOpenMode AS DWORD _                          ' __in DWORD dwOpenMode
 , BYVAL dwPipeMode AS DWORD _                          ' __in DWORD dwPipeMode
 , BYVAL nMaxInstances AS DWORD _                       ' __in DWORD nMaxInstances
 , BYVAL nOutBufferSize AS DWORD _                      ' __in DWORD nOutBufferSize
 , BYVAL nInBufferSize AS DWORD _                       ' __in DWORD nInBufferSize
 , BYVAL nDefaultTimeOut AS DWORD _                     ' __in DWORD nDefaultTimeOut
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateNamedPipe = CreateNamedPipeW
#ELSE
   MACRO CreateNamedPipe = CreateNamedPipeA
#ENDIF

DECLARE FUNCTION GetNamedPipeHandleStateA IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeHandleStateA" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in  HANDLE hNamedPipe
 , BYREF lpState AS DWORD _                             ' __out LPDWORD lpState
 , BYREF lpCurInstances AS DWORD _                      ' __out LPDWORD lpCurInstances
 , BYREF lpMaxCollectionCount AS DWORD _                ' __out LPDWORD lpMaxCollectionCount
 , BYREF lpCollectDataTimeout AS DWORD _                ' __out LPDWORD lpCollectDataTimeout
 , BYREF lpUserName AS ASCIIZ _                         ' __out LPSTR lpUserName
 , BYVAL nMaxUserNameSize AS DWORD _                    ' __in  DWORD nMaxUserNameSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeHandleStateW IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeHandleStateW" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in  HANDLE hNamedPipe
 , BYREF lpState AS DWORD _                             ' __out LPDWORD lpState
 , BYREF lpCurInstances AS DWORD _                      ' __out LPDWORD lpCurInstances
 , BYREF lpMaxCollectionCount AS DWORD _                ' __out LPDWORD lpMaxCollectionCount
 , BYREF lpCollectDataTimeout AS DWORD _                ' __out LPDWORD lpCollectDataTimeout
 , BYREF lpUserName AS WSTRINGZ _                       ' __out LPWSTR lpUserName
 , BYVAL nMaxUserNameSize AS DWORD _                    ' __in  DWORD nMaxUserNameSize
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO GetNamedPipeHandleState = GetNamedPipeHandleStateW
#ELSE
   MACRO GetNamedPipeHandleState = GetNamedPipeHandleStateA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CallNamedPipeA LIB "Kernel32.dll" ALIAS "CallNamedPipeA" _
    (lpNamedPipeName AS ASCIIZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CallNamedPipeA IMPORT "KERNEL32.DLL" ALIAS "CallNamedPipeA" ( _
   BYREF lpNamedPipeName AS ASCIIZ _                    ' __in  LPCSTR lpNamedPipeName
 , BYREF lpInBuffer AS ANY _                            ' __in  LPVOID lpInBuffer
 , BYVAL nInBufferSize AS DWORD _                       ' __in  DWORD nInBufferSize
 , BYREF lpOutBuffer AS ANY _                           ' __out LPVOID lpOutBuffer
 , BYVAL nOutBufferSize AS DWORD _                      ' __in  DWORD nOutBufferSize
 , BYREF lpBytesRead AS DWORD _                         ' __out LPDWORD lpBytesRead
 , BYVAL nTimeOut AS DWORD _                            ' __in  DWORD nTimeOut
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CallNamedPipeW LIB "Kernel32.dll" ALIAS "CallNamedPipeW" _
    (lpNamedPipeName AS WSTRINGZ, BYVAL lpInBuffer AS DWORD, _
    BYVAL nInBufferSize AS DWORD, BYVAL lpOutBuffer AS DWORD, _
    BYVAL nOutBufferSize AS DWORD, lpBytesRead AS DWORD, _
    BYVAL nTimeOut AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CallNamedPipeW IMPORT "KERNEL32.DLL" ALIAS "CallNamedPipeW" ( _
   BYREF lpNamedPipeName AS WSTRINGZ _                  ' __in  LPCWSTR lpNamedPipeName
 , BYREF lpInBuffer AS ANY _                            ' __in  LPVOID lpInBuffer
 , BYVAL nInBufferSize AS DWORD _                       ' __in  DWORD nInBufferSize
 , BYREF lpOutBuffer AS ANY _                           ' __out LPVOID lpOutBuffer
 , BYVAL nOutBufferSize AS DWORD _                      ' __in  DWORD nOutBufferSize
 , BYREF lpBytesRead AS DWORD _                         ' __out LPDWORD lpBytesRead
 , BYVAL nTimeOut AS DWORD _                            ' __in  DWORD nTimeOut
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO CallNamedPipe = CallNamedPipeW
#ELSE
   MACRO CallNamedPipe = CallNamedPipeA
#ENDIF

DECLARE FUNCTION WaitNamedPipeA IMPORT "KERNEL32.DLL" ALIAS "WaitNamedPipeA" ( _
   BYREF lpNamedPipeName AS ASCIIZ _                    ' __in LPCSTR lpNamedPipeName
 , BYVAL nTimeOut AS DWORD _                            ' __in DWORD nTimeOut
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WaitNamedPipeW IMPORT "KERNEL32.DLL" ALIAS "WaitNamedPipeW" ( _
   BYREF lpNamedPipeName AS WSTRINGZ _                  ' __in LPCWSTR lpNamedPipeName
 , BYVAL nTimeOut AS DWORD _                            ' __in DWORD nTimeOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WaitNamedPipe = WaitNamedPipeW
#ELSE
   MACRO WaitNamedPipe = WaitNamedPipeA
#ENDIF

' enum PIPE_ATTRIBUTE_TYPE
%PipeAttribute           = 0
%PipeConnectionAttribute = 1
%PipeHandleAttribute     = 2

' // Undocumented
DECLARE FUNCTION GetNamedPipeAttribute IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeAttribute" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYVAL AttributeType AS DWORD _                       ' __in PIPE_ATTRIBUTE_TYPE AttributeType
 , BYREF AttributeName AS ASCIIZ _                      ' __in PSTR AttributeName
 , BYREF AttributeValue AS ANY _                        ' __out PVOID AttributeValue
 , BYREF AttributeValueLength AS DWORD _                ' __inout PSIZE_T AttributeValueLength
 ) AS LONG                                              ' BOOL

' // Undocumented
DECLARE FUNCTION SetNamedPipeAttribute IMPORT "KERNEL32.DLL" ALIAS "SetNamedPipeAttribute" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYVAL AttributeType AS DWORD _                       ' __in PIPE_ATTRIBUTE_TYPE AttributeType
 , BYREF AttributeName AS ASCIIZ _                      ' __in PSTR AttributeName
 , BYREF AttributeValue AS ANY _                        ' __in PVOID AttributeValue
 , BYVAL AttributeValueLength AS DWORD _                ' __in SIZE_T AttributeValueLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeClientComputerNameA IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeClientComputerNameA" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ClientComputerName AS ASCIIZ _                 ' __out LPSTR ClientComputerName
 , BYVAL ClientComputerNameLength AS DWORD _            ' __in ULONG ClientComputerNameLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeClientComputerNameW IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeClientComputerNameW" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ClientComputerName AS WSTRINGZ _               ' __out LPWSTR ClientComputerName
 , BYVAL ClientComputerNameLength AS DWORD _            ' __in ULONG ClientComputerNameLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetNamedPipeClientComputerName = GetNamedPipeClientComputerNameW
#ELSE
   MACRO GetNamedPipeClientComputerName = GetNamedPipeClientComputerNameA
#ENDIF

DECLARE FUNCTION GetNamedPipeClientProcessId IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeClientProcessId" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ClientProcessId AS DWORD _                     ' __out PULONG ClientProcessId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeClientSessionId IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeClientSessionId" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ClientSessionId AS DWORD _                     ' __out PULONG ClientSessionId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeServerProcessId IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeServerProcessId" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ServerProcessId AS DWORD _                     ' __out PULONG ServerProcessId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedPipeServerSessionId IMPORT "KERNEL32.DLL" ALIAS "GetNamedPipeServerSessionId" ( _
   BYVAL Pipe AS DWORD _                                ' __in HANDLE Pipe
 , BYREF ServerSessionId AS DWORD _                     ' __out PULONG ServerSessionId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetVolumeLabelA IMPORT "KERNEL32.DLL" ALIAS "SetVolumeLabelA" ( _
   BYREF lpRootPathName AS ASCIIZ _                     ' __in LPCSTR lpRootPathName
 , BYREF lpVolumeName AS ASCIIZ _                       ' __in LPCSTR lpVolumeName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetVolumeLabelW IMPORT "KERNEL32.DLL" ALIAS "SetVolumeLabelW" ( _
   BYREF lpRootPathName AS WSTRINGZ _                   ' __in LPCWSTR lpRootPathName
 , BYREF lpVolumeName AS WSTRINGZ _                     ' __in LPCWSTR lpVolumeName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetVolumeLabel = SetVolumeLabelW
#ELSE
   MACRO SetVolumeLabel = SetVolumeLabelA
#ENDIF

DECLARE SUB SetFileApisToOEM IMPORT "KERNEL32.DLL" ALIAS "SetFileApisToOEM" ()   ' void

DECLARE SUB SetFileApisToANSI IMPORT "KERNEL32.DLL" ALIAS "SetFileApisToANSI" ()   ' void

DECLARE FUNCTION AreFileApisANSI IMPORT "KENEL32.DLL" ALIAS "AreFileApisANSI" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetVolumeInformationA IMPORT "KERNEL32.DLL" ALIAS "GetVolumeInformationA" ( _
   BYREF lpRootPathName AS ASCIIZ _                     ' __in  LPCSTR lpRootPathName
 , BYREF lpVolumeNameBuffer AS ASCIIZ _                 ' __out LPSTR lpVolumeNameBuffer
 , BYVAL nVolumeNameSize AS DWORD _                     ' __in  DWORD nVolumeNameSize
 , BYREF lpVolumeSerialNumber AS DWORD _                ' __out LPDWORD lpVolumeSerialNumber
 , BYREF lpMaximumComponentLength AS DWORD _            ' __out LPDWORD lpMaximumComponentLength
 , BYREF lpFileSystemFlags AS DWORD _                   ' __out LPDWORD lpFileSystemFlags
 , BYREF lpFileSystemNameBuffer AS ASCIIZ _             ' __out LPSTR lpFileSystemNameBuffer
 , BYVAL nFileSystemNameSize AS DWORD _                 ' __in  DWORD nFileSystemNameSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetVolumeInformationW IMPORT "KERNEL32.DLL" ALIAS "GetVolumeInformationW" ( _
   BYREF lpRootPathName AS WSTRINGZ _                   ' __in  LPCWSTR lpRootPathName
 , BYREF lpVolumeNameBuffer AS WSTRINGZ _               ' __out LPWSTR lpVolumeNameBuffer
 , BYVAL nVolumeNameSize AS DWORD _                     ' __in  DWORD nVolumeNameSize
 , BYREF lpVolumeSerialNumber AS DWORD _                ' __out LPDWORD lpVolumeSerialNumber
 , BYREF lpMaximumComponentLength AS DWORD _            ' __out LPDWORD lpMaximumComponentLength
 , BYREF lpFileSystemFlags AS DWORD _                   ' __out LPDWORD lpFileSystemFlags
 , BYREF lpFileSystemNameBuffer AS WSTRINGZ _           ' __out LPWSTR lpFileSystemNameBuffer
 , BYVAL nFileSystemNameSize AS DWORD _                 ' __in  DWORD nFileSystemNameSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetVolumeInformation = GetVolumeInformationW
#ELSE
   MACRO GetVolumeInformation = GetVolumeInformationA
#ENDIF

'#if(_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION GetVolumeInformationByHandleW IMPORT "KERNEL32.DLL" ALIAS "GetVolumeInformationByHandleW" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpVolumeNameBuffer AS WSTRINGZ _               ' __out LPWSTR lpVolumeNameBuffer
 , BYVAL nVolumeNameSize AS DWORD _                     ' __in  DWORD nVolumeNameSize
 , BYREF lpVolumeSerialNumber AS DWORD _                ' __out LPDWORD lpVolumeSerialNumber
 , BYREF lpMaximumComponentLength AS DWORD _            ' __out LPDWORD lpMaximumComponentLength
 , BYREF lpFileSystemFlags AS DWORD _                   ' __out LPDWORD lpFileSystemFlags
 , BYREF lpFileSystemNameBuffer AS WSTRINGZ _           ' __out LPWSTR lpFileSystemNameBuffer
 , BYVAL nFileSystemNameSize AS DWORD _                 ' __in  DWORD nFileSystemNameSize
 ) AS LONG                                              ' BOOL

MACRO GetVolumeInformationByHandle = GetVolumeInformationByHandleW
#ENDIF ' /* _WIN32_WINNT >=  0x0600 */

DECLARE FUNCTION CancelSynchronousIo IMPORT "KERNEL32.DLL" ALIAS "CancelSynchronousIo" ( _
   BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CancelIoEx IMPORT "KERNEL32.DLL" ALIAS "CancelIoEx" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __in LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CancelIo IMPORT "KERNEL32.DLL" ALIAS "CancelIo" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileBandwidthReservation IMPORT "KERNEL32.DLL" ALIAS "SetFileBandwidthReservation" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE  hFile
 , BYVAL nPeriodMilliseconds AS DWORD _                 ' __in  DWORD   nPeriodMilliseconds
 , BYVAL nBytesPerPeriod AS DWORD _                     ' __in  DWORD   nBytesPerPeriod
 , BYVAL bDiscardable AS LONG _                         ' __in  BOOL    bDiscardable
 , BYREF lpTransferSize AS DWORD _                      ' __out LPDWORD lpTransferSize
 , BYREF lpNumOutstandingRequests AS DWORD _            ' __out LPDWORD lpNumOutstandingRequests
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileBandwidthReservation IMPORT "KERNEL32.DLL" ALIAS "GetFileBandwidthReservation" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE  hFile
 , BYREF lpPeriodMilliseconds AS DWORD _                ' __out LPDWORD lpPeriodMilliseconds
 , BYREF lpBytesPerPeriod AS DWORD _                    ' __out LPDWORD lpBytesPerPeriod
 , BYREF pDiscardable AS DWORD _                        ' __out LPBOOL  pDiscardable
 , BYREF lpTransferSize AS DWORD _                      ' __out LPDWORD lpTransferSize
 , BYREF lpNumOutstandingRequests AS DWORD _            ' __out LPDWORD lpNumOutstandingRequests
 ) AS LONG                                              ' BOOL

'//
'// Event logging APIs
'//

DECLARE FUNCTION ClearEventLogA IMPORT "ADVAPI32.DLL" ALIAS "ClearEventLogA" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYREF lpBackupFileName AS ASCIIZ _                   ' __in LPCSTR lpBackupFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ClearEventLogW IMPORT "ADVAPI32.DLL" ALIAS "ClearEventLogW" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYREF lpBackupFileName AS WSTRINGZ _                 ' __in LPCWSTR lpBackupFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ClearEventLog = ClearEventLogW
#ELSE
   MACRO ClearEventLog = ClearEventLogA
#ENDIF

DECLARE FUNCTION BackupEventLogA IMPORT "ADVAPI32.DLL" ALIAS "BackupEventLogA" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYREF lpBackupFileName AS ASCIIZ _                   ' __in LPCSTR lpBackupFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BackupEventLogW IMPORT "ADVAPI32.DLL" ALIAS "BackupEventLogW" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYREF lpBackupFileName AS WSTRINGZ _                 ' __in LPCWSTR lpBackupFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO BackupEventLog = BackupEventLogW
#ELSE
   MACRO BackupEventLog = BackupEventLogA
#ENDIF

DECLARE FUNCTION CloseEventLog IMPORT "ADVAPI32.DLL" ALIAS "CloseEventLog" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeregisterEventSource IMPORT "ADVAPI32.DLL" ALIAS "DeregisterEventSource" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION NotifyChangeEventLog IMPORT "ADVAPI32.DLL" ALIAS "NotifyChangeEventLog" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE  hEventLog
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE  hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNumberOfEventLogRecords IMPORT "ADVAPI32.DLL" ALIAS "GetNumberOfEventLogRecords" ( _
   BYVAL hEventLog AS DWORD _                           ' __in  HANDLE hEventLog
 , BYREF NumberOfRecords AS DWORD _                     ' __out PDWORD NumberOfRecords
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetOldestEventLogRecord IMPORT "ADVAPI32.DLL" ALIAS "GetOldestEventLogRecord" ( _
   BYVAL hEventLog AS DWORD _                           ' __in  HANDLE hEventLog
 , BYREF OldestRecord AS DWORD _                        ' __out PDWORD OldestRecord
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenEventLogA IMPORT "ADVAPI32.DLL" ALIAS "OpenEventLogA" ( _
   BYREF lpUNCServerName AS ASCIIZ _                    ' __in LPCSTR lpUNCServerName
 , BYREF lpSourceName AS ASCIIZ _                       ' __in LPCSTR lpSourceName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenEventLogW IMPORT "ADVAPI32.DLL" ALIAS "OpenEventLogW" ( _
   BYREF lpUNCServerName AS WSTRINGZ _                  ' __in LPCWSTR lpUNCServerName
 , BYREF lpSourceName AS WSTRINGZ _                     ' __in LPCWSTR lpSourceName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenEventLog = OpenEventLogW
#ELSE
   MACRO OpenEventLog = OpenEventLogA
#ENDIF

DECLARE FUNCTION RegisterEventSourceA IMPORT "ADVAPI32.DLL" ALIAS "RegisterEventSourceA" ( _
   BYREF lpUNCServerName AS ASCIIZ _                    ' __in LPCSTR lpUNCServerName
 , BYREF lpSourceName AS ASCIIZ _                       ' __in LPCSTR lpSourceName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION RegisterEventSourceW IMPORT "ADVAPI32.DLL" ALIAS "RegisterEventSourceW" ( _
   BYREF lpUNCServerName AS WSTRINGZ _                  ' __in LPCWSTR lpUNCServerName
 , BYREF lpSourceName AS WSTRINGZ _                     ' __in LPCWSTR lpSourceName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO RegisterEventSource = RegisterEventSourceW
#ELSE
   MACRO RegisterEventSource = RegisterEventSourceA
#ENDIF

DECLARE FUNCTION OpenBackupEventLogA IMPORT "ADVAPI32.DLL" ALIAS "OpenBackupEventLogA" ( _
   BYREF lpUNCServerName AS ASCIIZ _                    ' __in LPCSTR lpUNCServerName
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenBackupEventLogW IMPORT "ADVAPI32.DLL" ALIAS "OpenBackupEventLogW" ( _
   BYREF lpUNCServerName AS WSTRINGZ _                  ' __in LPCWSTR lpUNCServerName
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenBackupEventLog = OpenBackupEventLogW
#ELSE
   MACRO OpenBackupEventLog = OpenBackupEventLogA
#ENDIF

DECLARE FUNCTION ReadEventLogA IMPORT "ADVAPI32.DLL" ALIAS "ReadEventLogA" ( _
   BYVAL hEventLog AS DWORD _                           ' __in  HANDLE hEventLog
 , BYVAL dwReadFlags AS DWORD _                         ' __in  DWORD dwReadFlags
 , BYVAL dwRecordOffset AS DWORD _                      ' __in  DWORD dwRecordOffset
 , BYREF lpBuffer AS EVENTLOGRECORD _                   ' __out LPVOID lpBuffer
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in  DWORD nNumberOfBytesToRead
 , BYREF pnBytesRead AS DWORD _                         ' __out DWORD *pnBytesRead
 , BYREF pnMinNumberOfBytesNeeded AS DWORD _            ' __out DWORD *pnMinNumberOfBytesNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReadEventLogW IMPORT "ADVAPI32.DLL" ALIAS "ReadEventLogW" ( _
   BYVAL hEventLog AS DWORD _                           ' __in  HANDLE hEventLog
 , BYVAL dwReadFlags AS DWORD _                         ' __in  DWORD dwReadFlags
 , BYVAL dwRecordOffset AS DWORD _                      ' __in  DWORD dwRecordOffset
 , BYREF lpBuffer AS EVENTLOGRECORD _                   ' __out LPVOID lpBuffer
 , BYVAL nNumberOfBytesToRead AS DWORD _                ' __in  DWORD nNumberOfBytesToRead
 , BYREF pnBytesRead AS DWORD _                         ' __out DWORD *pnBytesRead
 , BYREF pnMinNumberOfBytesNeeded AS DWORD _            ' __out DWORD *pnMinNumberOfBytesNeeded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ReadEventLog = ReadEventLogW
#ELSE
   MACRO ReadEventLog = ReadEventLogA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReportEventA LIB "AdvApi32.dll" ALIAS "ReportEventA" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReportEventA IMPORT "ADVAPI32.DLL" ALIAS "ReportEventA" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYVAL wType AS WORD _                                ' __in WORD wType
 , BYVAL wCategory AS WORD _                            ' __in WORD wCategory
 , BYVAL dwEventID AS DWORD _                           ' __in DWORD dwEventID
 , BYVAL lpUserSid AS SID PTR _                         ' __in PSID lpUserSid
 , BYVAL wNumStrings AS WORD _                          ' __in WORD wNumStrings
 , BYVAL dwDataSize AS DWORD _                          ' __in DWORD dwDataSize
 , BYREF lpStrings AS ASCIIZ _                          ' __in LPCSTR *lpStrings
 , BYREF lpRawData AS ANY _                             ' __in LPVOID lpRawData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReportEventW LIB "AdvApi32.dll" ALIAS "ReportEventW" _
    (BYVAL hEventLog AS DWORD, BYVAL wType AS WORD, BYVAL wCategory AS WORD, _
    BYVAL dwEventId AS DWORD, lpUserSid AS SID, BYVAL wNumStrings AS WORD, _
    BYVAL dwDataSize AS DWORD, BYVAL lpStrings AS DWORD, _
    BYVAL lpRawData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReportEventW IMPORT "ADVAPI32.DLL" ALIAS "ReportEventW" ( _
   BYVAL hEventLog AS DWORD _                           ' __in HANDLE hEventLog
 , BYVAL wType AS WORD _                                ' __in WORD wType
 , BYVAL wCategory AS WORD _                            ' __in WORD wCategory
 , BYVAL dwEventID AS DWORD _                           ' __in DWORD dwEventID
 , BYVAL lpUserSid AS SID PTR _                         ' __in PSID lpUserSid
 , BYVAL wNumStrings AS WORD _                          ' __in WORD wNumStrings
 , BYVAL dwDataSize AS DWORD _                          ' __in DWORD dwDataSize
 , BYREF lpStrings AS WSTRINGZ _                        ' __in LPCWSTR *lpStrings
 , BYREF lpRawData AS ANY _                             ' __in LPVOID lpRawData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ReportEvent = ReportEventW
#ELSE
   MACRO ReportEvent = ReportEventA
#ENDIF

%EVENTLOG_FULL_INFO    = 0

' // Size = 4 bytes
TYPE EVENTLOG_FULL_INFORMATION DWORD
   dwFull AS DWORD                     ' DWORD dwFull
END TYPE

DECLARE FUNCTION GetEventLogInformation IMPORT "KERNEL32.DLL" ALIAS "GetEventLogInformation" ( _
   BYVAL hEventLog AS DWORD _                           ' __in  HANDLE hEventLog
 , BYVAL dwInfoLevel AS DWORD _                         ' __in  DWORD  dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL cbBufSize AS DWORD _                           ' __in  DWORD  cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL

'//
'//
'// Security APIs
'//


DECLARE FUNCTION DuplicateToken IMPORT "ADVAPI32.DLL" ALIAS "DuplicateToken" ( _
   BYVAL ExistingTokenHandle AS DWORD _                 ' __in  HANDLE ExistingTokenHandle
 , BYREF ImpersonationLevel AS LONG _                   ' __in  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
 , BYREF DuplicateTokenHandle AS DWORD _                ' __out PHANDLE DuplicateTokenHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetKernelObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "GetKernelObjectSecurity" ( _
   BYVAL Handle AS DWORD _                              ' __in  HANDLE Handle
 , BYVAL RequestedInformation AS SECURITY_INFORMATION _ ' __in  SECURITY_INFORMATION RequestedInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL nLength AS DWORD _                             ' __in  DWORD nLength
 , BYREF lpnLengthNeeded AS DWORD _                     ' __out LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImpersonateNamedPipeClient IMPORT "ADVAPI32.DLL" ALIAS "ImpersonateNamedPipeClient" ( _
   BYVAL hNamedPipe AS DWORD _                          ' __in HANDLE hNamedPipe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImpersonateSelf IMPORT "ADVAPI32.DLL" ALIAS "ImpersonateSelf" ( _
   BYVAL ImpersonationLevel AS LONG _                   ' __in SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RevertToSelf IMPORT "ADVAPI32.DLL" ALIAS "RevertToSelf" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadToken IMPORT "ADVAPI32.DLL" ALIAS "SetThreadToken" ( _
   BYREF Thread AS DWORD _                              ' __in PHANDLE Thread
 , BYVAL Token AS DWORD _                               ' __in HANDLE Token
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheck LIB "AdvApi32.dll" ALIAS "AccessCheck" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatus AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheck IMPORT "ADVAPI32.DLL" ALIAS "AccessCheck" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 , BYREF PrivilegeSet AS PRIVILEGE_SET _                ' __out PPRIVILEGE_SET PrivilegeSet
 , BYREF PrivilegeSetLength AS DWORD _                  ' __inout LPDWORD PrivilegeSetLength
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 ) AS LONG                                              ' BOOL
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByType LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByType" (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, _
    BYVAL ObjectTypeList AS OBJECT_TYPE_LIST PTR, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatus AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByType IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByType" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in PSID PrincipalSelfSid
 , BYVAL ClientToken AS SID PTR _                       ' __in HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 , BYREF PrivilegeSet AS PRIVILEGE_SET _                ' __out PPRIVILEGE_SET PrivilegeSet
 , BYREF PrivilegeSetLength AS DWORD _                  ' __inout LPDWORD PrivilegeSetLength
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeResultList LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultList" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, _
    BYVAL ObjectTypeList AS OBJECT_TYPE_LIST PTR, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL PrivilegeSet AS DWORD, PrivilegeSetLength AS DWORD, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultList IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeResultList" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in PSID PrincipalSelfSid
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 , BYREF PrivilegeSet AS PRIVILEGE_SET _                ' __out PPRIVILEGE_SET PrivilegeSet
 , BYREF PrivilegeSetLength AS DWORD _                  ' __inout LPDWORD PrivilegeSetLength
 , BYREF GrantedAccessList AS DWORD _                   ' __out LPDWORD GrantedAccessList
 , BYREF AccessStatusList AS DWORD _                    ' __out LPDWORD AccessStatusList
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif /* _WIN32_WINNT >=  0x0500 */

DECLARE FUNCTION OpenProcessToken IMPORT "ADVAPI32.DLL" ALIAS "OpenProcessToken" ( _
   BYVAL ProcessHandle AS DWORD _                       ' __in  HANDLE ProcessHandle
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYREF TokenHandle AS DWORD _                         ' __out PHANDLE TokenHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenThreadToken IMPORT "ADVAPI32.DLL" ALIAS "OpenThreadToken" ( _
   BYVAL ThreadHandle AS DWORD _                        ' __in  HANDLE ThreadHandle
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL OpenAsSelf AS LONG _                           ' __in  BOOL OpenAsSelf
 , BYREF TokenHandle AS DWORD _                         ' __out PHANDLE TokenHandle
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetTokenInformation LIB "AdvApi32.dll" _
    ALIAS "GetTokenInformation" (BYVAL TokenHandle AS DWORD, _
    BYVAL TokenInformationClass AS LONG, BYVAL TokenInformation AS DWORD, _
    BYVAL TokenInformationLength AS DWORD, ReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetTokenInformation IMPORT "ADVAPI32.DLL" ALIAS "GetTokenInformation" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in  HANDLE TokenHandle
 , BYVAL TokenInformationClass AS LONG _                ' __in  TOKEN_INFORMATION_CLASS TokenInformationClass
 , BYREF TokenInformation AS ANY _                      ' __out LPVOID TokenInformation
 , BYVAL TokenInformationLength AS DWORD _              ' __in  DWORD TokenInformationLength
 , BYREF ReturnLength AS DWORD _                        ' __out PDWORD ReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetTokenInformation LIB "AdvApi32.dll" _
    ALIAS "SetTokenInformation" (BYVAL TokenHandle AS DWORD, _
    BYVAL TokenInformationClass AS LONG, BYVAL TokenInformation AS DWORD, _
    BYVAL TokenInformationLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetTokenInformation IMPORT "ADVAPI32.DLL" ALIAS "SetTokenInformation" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in HANDLE TokenHandle
 , BYVAL TokenInformationClass AS LONG _                ' __in TOKEN_INFORMATION_CLASS TokenInformationClass
 , BYREF TokenInformation AS ANY _                      ' __in LPVOID TokenInformation
 , BYVAL TokenInformationLength AS DWORD _              ' __in DWORD TokenInformationLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AdjustTokenPrivileges LIB "AdvApi32.dll" _
    ALIAS "AdjustTokenPrivileges" (BYVAL TokenHandle AS DWORD, _
    BYVAL DisableAllPrivileges AS LONG, BYVAL NewState AS DWORD, _
    BYVAL BufferLength AS DWORD, BYVAL PreviousState AS DWORD, _
    ReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION AdjustTokenPrivileges IMPORT "ADVAPI32.DLL" ALIAS "AdjustTokenPrivileges" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in  HANDLE TokenHandle
 , BYVAL DisableAllPrivileges AS LONG _                 ' __in  BOOL DisableAllPrivileges
 , BYREF NewState AS TOKEN_PRIVILEGES _                 ' __in  PTOKEN_PRIVILEGES NewState
 , BYVAL BufferLength AS DWORD _                        ' __in  DWORD BufferLength
 , BYREF PreviousState AS TOKEN_PRIVILEGES _            ' __out PTOKEN_PRIVILEGES PreviousState
 , BYREF ReturnLength AS DWORD _                        ' __out PDWORD ReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AdjustTokenGroups LIB "AdvApi32.dll" _
    ALIAS "AdjustTokenGroups" (BYVAL TokenHandle AS DWORD, _
    BYVAL ResetToDefault AS LONG, BYVAL NewState AS DWORD, _
    BYVAL BufferLength AS DWORD, BYVAL PreviousState AS DWORD, _
    ReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION AdjustTokenGroups IMPORT "ADVAPI32.DLL" ALIAS "AdjustTokenGroups" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in  HANDLE TokenHandle
 , BYVAL ResetToDefault AS LONG _                       ' __in  BOOL ResetToDefault
 , BYREF NewState AS TOKEN_GROUPS _                     ' __in  PTOKEN_GROUPS NewState
 , BYVAL BufferLength AS DWORD _                        ' __in  DWORD BufferLength
 , BYREF PreviousState AS TOKEN_GROUPS _                ' __out PTOKEN_GROUPS PreviousState
 , BYREF ReturnLength AS DWORD _                        ' __out PDWORD ReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PrivilegeCheck LIB "AdvApi32.dll" ALIAS "PrivilegeCheck" _
    (BYVAL ClientToken AS LONG, BYVAL RequiredPrivileges AS DWORD, _
    pfResult AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PrivilegeCheck IMPORT "ADVAPI32.DLL" ALIAS "PrivilegeCheck" ( _
   BYVAL ClientToken AS LONG _                          ' __in HANDLE ClientToken
 , BYREF RequiredPrivileges AS PRIVILEGE_SET _          ' __inout PPRIVILEGE_SET RequiredPrivileges
 , BYREF pfResult AS LONG _                             ' __out LPBOOL pfResult
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckAndAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckAndAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in  LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS ASCIIZ _                     ' __in  LPSTR ObjectTypeName
 , BYREF ObjectName AS ASCIIZ _                         ' __in  LPSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL DesiredAccess AS DWORD, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, BYVAL AccessStatus AS LONG, _
    BYVAL pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckAndAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckAndAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in  LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS WSTRINGZ _                   ' __in  LPWSTR ObjectTypeName
 , BYREF ObjectName AS WSTRINGZ _                       ' __in  LPWSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AccessCheckAndAuditAlarm = AccessCheckAndAuditAlarmW
#ELSE
   MACRO AccessCheckAndAuditAlarm = AccessCheckAndAuditAlarmA
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeAndAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in  LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS ASCIIZ _                     ' __in  LPCSTR ObjectTypeName
 , BYREF ObjectName AS ASCIIZ _                         ' __in  LPCSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in  POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF AccessStatus AS DWORD _                        ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeAndAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    BYVAL ObjectTypeListLength AS DWORD, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatus AS LONG, pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeAndAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeAndAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in  LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS WSTRINGZ _                   ' __in  LPCWSTR ObjectTypeName
 , BYREF ObjectName AS WSTRINGZ _                       ' __in  LPCWSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in  POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF AccessStatus AS DWORD _                        ' __out LPDWORD GrantedAccess
 , BYREF AccessStatus AS LONG _                         ' __out LPBOOL AccessStatus
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AccessCheckByTypeAndAuditAlarm = AccessCheckByTypeAndAuditAlarmW
#ELSE
   MACRO AccessCheckByTypeAndAuditAlarm = AccessCheckByTypeAndAuditAlarmW
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, ObjectTypeName AS ASCIIZ, _
    ObjectName AS ASCIIZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, GenericMapping AS GENERIC_MAPPING, _
    BYVAL ObjectCreation AS LONG, GrantedAccess AS DWORD, _
    AccessStatusList AS DWORD, pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeResultListAndAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in  LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS ASCIIZ _                     ' __in  LPCSTR ObjectTypeName
 , BYREF ObjectName AS ASCIIZ _                         ' __in  LPCSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeListLength AS OBJECT_TYPE_LIST _     ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatusList AS DWORD _                    ' __out LPDWORD AccessStatusList
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, PrincipalSelfSid AS SID, _
    BYVAL DesiredAccess AS DWORD, BYVAL AuditType AS LONG, _
    BYVAL Flags AS DWORD, ObjectTypeList AS OBJECT_TYPE_LIST, _
    GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeResultListAndAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in  LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS WSTRINGZ _                   ' __in  LPCWSTR ObjectTypeName
 , BYREF ObjectName AS WSTRINGZ _                       ' __in  LPCWSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeListLength AS OBJECT_TYPE_LIST _     ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatusList AS DWORD _                    ' __out LPDWORD AccessStatusList
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AccessCheckByTypeResultListAndAuditAlarm = AccessCheckByTypeResultListAndAuditAlarmW
#ELSE
   MACRO AccessCheckByTypeResultListAndAuditAlarm = AccessCheckByTypeResultListAndAuditAlarmA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleA _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleA" _
    (SubsystemName AS ASCIIZ, HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleA IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleA" ( _
   BYREF pfGenerateOnClose AS ASCIIZ _                  ' __in  LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYVAL ClientToken AS DWORD _                         ' __in  HANDLE ClientToken
 , BYREF ObjectTypeName AS ASCIIZ _                     ' __in  LPCSTR ObjectTypeName
 , BYREF ObjectName AS ASCIIZ _                         ' __in  LPCSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in  POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatusList AS DWORD _                    ' __out LPDWORD AccessStatusList
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleW _
    LIB "AdvApi32.dll" _
    ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleW" _
    (SubsystemName AS WSTRINGZ, HandleId AS DWORD, _
    BYVAL ClientToken AS DWORD, ObjectTypeName AS WSTRINGZ, _
    ObjectName AS WSTRINGZ, SecurityDescriptor AS SECURITY_DESCRIPTOR, _
    PrincipalSelfSid AS SID, BYVAL DesiredAccess AS DWORD, _
    BYVAL AuditType AS LONG, BYVAL Flags AS DWORD, _
    ObjectTypeList AS OBJECT_TYPE_LIST, BYVAL ObjectTypeListLength AS DWORD, _
    BYVAL GenericMapping AS GENERIC_MAPPING, BYVAL ObjectCreation AS LONG, _
    GrantedAccess AS DWORD, AccessStatusList AS DWORD, _
    pfGenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AccessCheckByTypeResultListAndAuditAlarmByHandleW IMPORT "ADVAPI32.DLL" ALIAS "AccessCheckByTypeResultListAndAuditAlarmByHandleW" ( _
   BYREF pfGenerateOnClose AS WSTRINGZ _                ' __in  LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYVAL ClientToken AS DWORD _                         ' __in  HANDLE ClientToken
 , BYREF ObjectTypeName AS WSTRINGZ _                   ' __in  LPCWSTR ObjectTypeName
 , BYREF ObjectName AS WSTRINGZ _                       ' __in  LPCWSTR ObjectName
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL PrincipalSelfSid AS SID PTR _                  ' __in  PSID PrincipalSelfSid
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL AuditType AS LONG _                            ' __in  AUDIT_EVENT_TYPE AuditType
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF ObjectTypeList AS OBJECT_TYPE_LIST _           ' __in  POBJECT_TYPE_LIST ObjectTypeList
 , BYVAL ObjectTypeListLength AS DWORD _                ' __in  DWORD ObjectTypeListLength
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYREF GrantedAccess AS DWORD _                       ' __out LPDWORD GrantedAccess
 , BYREF AccessStatusList AS DWORD _                    ' __out LPDWORD AccessStatusList
 , BYREF pfGenerateOnClose AS LONG _                    ' __out LPBOOL pfGenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AccessCheckByTypeResultListAndAuditAlarmByHandle = AccessCheckByTypeResultListAndAuditAlarmByHandleW
#ELSE
   MACRO AccessCheckByTypeResultListAndAuditAlarmByHandle = AccessCheckByTypeResultListAndAuditAlarmByHandleA
#ENDIF

'#endif //(_WIN32_WINNT >= 0x0500)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectOpenAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, ObjectTypeName AS ASCIIZ, ObjectName AS ASCIIZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectOpenAuditAlarmA IMPORT "KERNEL32.DLL" ALIAS "ObjectOpenAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in  LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS ASCIIZ _                     ' __in  LPSTR ObjectTypeName
 , BYREF ObjectName AS ASCIIZ _                         ' __in  LPSTR ObjectName
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL ClientToken AS DWORD _                         ' __in  HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL GrantedAccess AS DWORD _                       ' __in  DWORD GrantedAccess
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in  PPRIVILEGE_SET Privileges
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYVAL AccessGranted AS LONG _                        ' __in  BOOL AccessGranted
 , BYREF GenerateOnClose AS LONG _                      ' __out LPBOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectOpenAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectOpenAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, ObjectTypeName AS WSTRINGZ, ObjectName AS WSTRINGZ, _
    pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL ClientToken AS LONG, _
    BYVAL DesiredAccess AS LONG, BYVAL GrantedAccess AS LONG, _
    BYVAL Privileges AS DWORD, BYVAL ObjectCreation AS LONG, _
    BYVAL AccessGranted AS LONG, GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectOpenAuditAlarmW IMPORT "KERNEL32.DLL" ALIAS "ObjectOpenAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in  LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in  LPVOID HandleId
 , BYREF ObjectTypeName AS WSTRINGZ _                   ' __in  LPWSTR ObjectTypeName
 , BYREF ObjectName AS WSTRINGZ _                       ' __in  LPWSTR ObjectName
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR  _  ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL ClientToken AS DWORD _                         ' __in  HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in  DWORD DesiredAccess
 , BYVAL GrantedAccess AS DWORD _                       ' __in  DWORD GrantedAccess
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in  PPRIVILEGE_SET Privileges
 , BYVAL ObjectCreation AS LONG _                       ' __in  BOOL ObjectCreation
 , BYVAL AccessGranted AS LONG _                        ' __in  BOOL AccessGranted
 , BYREF GenerateOnClose AS LONG _                      ' __out LPBOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ObjectOpenAuditAlarm = ObjectOpenAuditAlarmW
#ELSE
   MACRO ObjectOpenAuditAlarm = ObjectOpenAuditAlarmA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectPrivilegeAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectPrivilegeAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "ObjectPrivilegeAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in PPRIVILEGE_SET Privileges
 , BYVAL AccessGranted AS LONG _                        ' __in BOOL AccessGranted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectPrivilegeAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectPrivilegeAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL ClientToken AS DWORD, _
    BYVAL DesiredAccess AS DWORD, BYVAL Privileges AS DWORD, _
    BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectPrivilegeAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "ObjectPrivilegeAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in PPRIVILEGE_SET Privileges
 , BYVAL AccessGranted AS LONG _                        ' __in BOOL AccessGranted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ObjectPrivilegeAuditAlarm = ObjectPrivilegeAuditAlarmW
#ELSE
   MACRO ObjectPrivilegeAuditAlarm = ObjectPrivilegeAuditAlarmA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectCloseAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectCloseAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "ObjectCloseAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL GenerateOnClose AS LONG _                      ' __in BOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectCloseAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectCloseAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectCloseAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "ObjectCloseAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL GenerateOnClose AS LONG _                      ' __in BOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ObjectCloseAuditAlarm = ObjectCloseAuditAlarmW
#ELSE
   MACRO ObjectCloseAuditAlarm = ObjectCloseAuditAlarmA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectDeleteAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmA" (SubsystemName AS ASCIIZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectDeleteAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "ObjectDeleteAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in LPCSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL GenerateOnClose AS LONG _                      ' __in BOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ObjectDeleteAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "ObjectDeleteAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    HandleId AS DWORD, BYVAL GenerateOnClose AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ObjectDeleteAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "ObjectDeleteAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in LPCWSTR SubsystemName
 , BYVAL HandleId AS DWORD _                            ' __in LPVOID HandleId
 , BYVAL GenerateOnClose AS LONG _                      ' __in BOOL GenerateOnClose
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ObjectDeleteAuditAlarm = ObjectDeleteAuditAlarmW
#ELSE
   MACRO ObjectDeleteAuditAlarm = ObjectDeleteAuditAlarmA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PrivilegedServiceAuditAlarmA LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmA" (SubsystemName AS ASCIIZ, _
    ServiceName AS ASCIIZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PrivilegedServiceAuditAlarmA IMPORT "ADVAPI32.DLL" ALIAS "PrivilegedServiceAuditAlarmA" ( _
   BYREF SubsystemName AS ASCIIZ _                      ' __in LPCSTR SubsystemName
 , BYREF ServiceName AS ASCIIZ _                        ' __in LPCSTR ServiceName
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in PPRIVILEGE_SET Privileges
 , BYVAL AccessGranted AS LONG _                        ' __in BOOL AccessGranted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PrivilegedServiceAuditAlarmW LIB "AdvApi32.dll" _
    ALIAS "PrivilegedServiceAuditAlarmW" (SubsystemName AS WSTRINGZ, _
    ServiceName AS WSTRINGZ, BYVAL ClientToken AS DWORD, _
    BYVAL Privileges AS DWORD, BYVAL AccessGranted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION PrivilegedServiceAuditAlarmW IMPORT "ADVAPI32.DLL" ALIAS "PrivilegedServiceAuditAlarmW" ( _
   BYREF SubsystemName AS WSTRINGZ _                    ' __in LPCWSTR SubsystemName
 , BYREF ServiceName AS WSTRINGZ _                      ' __in LPCWSTR ServiceName
 , BYVAL ClientToken AS DWORD _                         ' __in HANDLE ClientToken
 , BYREF Privileges AS PRIVILEGE_SET _                  ' __in PPRIVILEGE_SET Privileges
 , BYVAL AccessGranted AS LONG _                        ' __in BOOL AccessGranted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO PrivilegedServiceAuditAlarm = PrivilegedServiceAuditAlarmW
#ELSE
   MACRO PrivilegedServiceAuditAlarm = PrivilegedServiceAuditAlarmA
#ENDIF

'#if(_WIN32_WINNT >= 0x0501)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION IsWellKnownSid LIB "AdvApi32.dll" ALIAS "IsWellKnownSid" _
    (pSid AS SID, BYVAL WellKnownSidType AS LONG) AS LONG
#ELSE
DECLARE FUNCTION IsWellKnownSid IMPORT "ADVAPI32.DLL" ALIAS "IsWellKnownSid" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYVAL WellKnownSidType AS LONG _                     ' __in WELL_KNOWN_SID_TYPE WellKnownSidType
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateWellKnownSid LIB "AdvApi32.dll" _
    ALIAS "CreateWellKnownSid" (BYVAL WellKnownSidType AS LONG, _
    DomainSid AS SID, pSid AS SID, cbSid AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CreateWellKnownSid IMPORT "ADVAPI32.DLL" ALIAS "CreateWellKnownSid" ( _
   BYVAL WellKnownSidType AS LONG _                     ' __in WELL_KNOWN_SID_TYPE WellKnownSidType
 , BYVAL DomainSid AS SID PTR _                         ' __in PSID DomainSid
 , BYREF pSid AS ANY _                                  ' __out PSID pSid
 , BYREF cbSid AS DWORD _                               ' __inout DWORD *cbSid
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EqualDomainSid LIB "AdvApi32.dll" _
    ALIAS "EqualDomainSid" (pSid1 AS SID, pSid2 AS SID, pfEqual AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION EqualDomainSid IMPORT "ADVAPI32.DLL" ALIAS "EqualDomainSid" ( _
   BYVAL pSid1 AS SID PTR _                             ' __in  PSID pSid1
 , BYVAL pSid1 AS SID PTR _                             ' __in  PSID pSid2
 , BYREF pfEqual AS LONG _                              ' __out BOOL *pfEqual
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetWindowsAccountDomainSid LIB "AdvApi32.dll" _
    ALIAS "GetWindowsAccountDomainSid" (pSid AS SID, pDomainSid AS SID, _
    cbDomainSid AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetWindowsAccountDomainSid IMPORT "ADVAPI32.DLL" ALIAS "GetWindowsAccountDomainSid" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYREF pDomainSid AS ANY _                            ' __out PSID pDomainSid
 , BYREF cbDomainSid AS DWORD _                         ' __inout DWORD* cbDomainSid
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif //(_WIN32_WINNT >= 0x0501)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION IsValidSid LIB "AdvApi32.dll" ALIAS "IsValidSid" _
    (pSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION IsValidSid IMPORT "ADVAPI32.DLL" ALIAS "IsValidSid" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EqualSid LIB "AdvApi32.dll" ALIAS "EqualSid" _
    (pSid1 AS SID, pSid2 AS SID) AS LONG
#ELSE
DECLARE FUNCTION EqualSid IMPORT "ADVAPI32.DLL" ALIAS "EqualSid" ( _
   BYVAL pSid1 AS SID PTR _                             ' __in PSID pSid1
 , BYVAL pSid2 AS SID PTR _                             ' __in PSID pSid2
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EqualPrefixSid LIB "AdvApi32.dll" ALIAS "EqualPrefixSid" _
    (pSid1 AS SID, pSid2 AS SID) AS LONG
#ELSE
DECLARE FUNCTION EqualPrefixSid IMPORT "ADVAPI32.DLL" ALIAS "EqualPrefixSid" ( _
   BYVAL pSid1 AS SID PTR _                             ' __in PSID pSid1
 , BYVAL pSid2 AS SID PTR _                             ' __in PSID pSid2
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION GetSidLengthRequired IMPORT "ADVAPI32.DLL" ALIAS "GetSidLengthRequired" ( _
   BYVAL nSubAuthorityCount AS BYTE _                   ' __in UCHAR nSubAuthorityCount
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION AllocateAndInitializeSid IMPORT "ADVAPI32.DLL" ALIAS "AllocateAndInitializeSid" ( _
   BYREF pIdentifierAuthority AS SID_IDENTIFIER_AUTHORITY _ ' __in  PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority
 , BYVAL nSubAuthorityCount AS BYTE _                   ' __in  BYTE nSubAuthorityCount
 , BYVAL nSubAuthority0 AS DWORD _                      ' __in  DWORD nSubAuthority0
 , BYVAL nSubAuthority1 AS DWORD _                      ' __in  DWORD nSubAuthority1
 , BYVAL nSubAuthority2 AS DWORD _                      ' __in  DWORD nSubAuthority2
 , BYVAL nSubAuthority3 AS DWORD _                      ' __in  DWORD nSubAuthority3
 , BYVAL nSubAuthority4 AS DWORD _                      ' __in  DWORD nSubAuthority4
 , BYVAL nSubAuthority5 AS DWORD _                      ' __in  DWORD nSubAuthority5
 , BYVAL nSubAuthority6 AS DWORD _                      ' __in  DWORD nSubAuthority6
 , BYVAL nSubAuthority7 AS DWORD _                      ' __in  DWORD nSubAuthority7
 , BYREF pSid AS ANY _                                  ' __out PSID *pSid
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE SUB FreeSid LIB "AdvApi32.dll" ALIAS "FreeSid" (pSid AS SID)
#ELSE
DECLARE FUNCTION FreeSid IMPORT "ADVAPI32.DLL" ALIAS "FreeSid" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS DWORD                                             ' PVOID
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InitializeSid LIB "AdvApi32.dll" ALIAS "InitializeSid" _
    (pSid AS SID, pIdentifierAuthority AS SID_IDENTIFIER_AUTHORITY, _
    BYVAL nSubAuthorityCount AS BYTE) AS LONG
#ELSE
DECLARE FUNCTION InitializeSid IMPORT "ADVAPI32.DLL" ALIAS "InitializeSid" ( _
   BYVAL pSid AS SID PTR _                              ' __out PSID Sid
 , BYREF pIdentifierAuthority AS SID_IDENTIFIER_AUTHORITY _ ' __in  PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority
 , BYVAL nSubAuthorityCount AS BYTE _                   ' __in  BYTE nSubAuthorityCount
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSidIdentifierAuthority LIB "AdvApi32.dll" _
    ALIAS "GetSidIdentifierAuthority" (pSid AS SID) AS DWORD
#ELSE
DECLARE FUNCTION GetSidIdentifierAuthority IMPORT "ADVAPI32.DLL" ALIAS "GetSidIdentifierAuthority" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS DWORD                                             ' PSID_IDENTIFIER_AUTHORITY
#ENDIF

'#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION GetSidSubAuthority LIB "AdvApi32.dll" _
'    ALIAS "GetSidSubAuthority" (dwFlags AS DWORD, _
'    BYVAL nSubAuthority AS DWORD) AS DWORD
'#ELSE
DECLARE FUNCTION GetSidSubAuthority IMPORT "ADVAPI32.DLL" ALIAS "GetSidSubAuthority" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYVAL nSubAuthority AS DWORD _                       ' __in DWORD nSubAuthority
 ) AS DWORD                                             ' PDWORD
'#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSidSubAuthorityCount LIB "AdvApi32.dll" _
    ALIAS "GetSidSubAuthorityCount" (pSid AS SID) AS DWORD
#ELSE
DECLARE FUNCTION GetSidSubAuthorityCount IMPORT "ADVAPI32.DLL" ALIAS "GetSidSubAuthorityCount" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS DWORD                                             ' PUCHAR
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetLengthSid LIB "AdvApi32.dll" ALIAS "GetLengthSid" _
    (pSid AS SID) AS DWORD
#ELSE
DECLARE FUNCTION GetLengthSid IMPORT "ADVAPI32.DLL" ALIAS "GetLengthSid" ( _
   BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CopySid LIB "AdvApi32.dll" ALIAS "CopySid" _
    (BYVAL nDestinationSidLength AS DWORD, pDestinationSid AS SID, _
    pSourceSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION CopySid IMPORT "ADVAPI32.DLL" ALIAS "CopySid" ( _
   BYVAL nDestinationSidLength AS DWORD _               ' __in  DWORD nDestinationSidLength
 , BYREF pDestinationSid AS ANY _                       ' __out PSID pDestinationSid
 , BYVAL pSourceSid AS SID PTR _                        ' __in  PSID pSourceSid
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION AreAllAccessesGranted IMPORT "ADVAPI32.DLL" ALIAS "AreAllAccessesGranted" ( _
   BYVAL GrantedAccess AS DWORD _                       ' __in DWORD GrantedAccess
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AreAnyAccessesGranted IMPORT "ADVAPI32.DLL" ALIAS "AreAnyAccessesGranted" ( _
   BYVAL GrantedAccess AS DWORD _                       ' __in DWORD GrantedAccess
 , BYVAL DesiredAccess AS DWORD _                       ' __in DWORD DesiredAccess
 ) AS LONG                                              ' BOOL

DECLARE SUB MapGenericMask IMPORT "ADVAPI32.DLL" ALIAS "MapGenericMask" ( _
   BYREF AccessMask AS DWORD _                          ' __inout PDWORD AccessMask
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION IsValidAcl LIB "AdvApi32.dll" ALIAS "IsValidAcl" _
    (pAcl AS ACL) AS LONG
#ELSE
DECLARE FUNCTION IsValidAcl IMPORT "ADVAPI32.DLL" ALIAS "IsValidAcl" ( _
   BYVAL pAcl AS ACL PTR _                              ' __in PACL pAcl
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InitializeAcl LIB "AdvApi32.dll" ALIAS "InitializeAcl" _
    (pAcl AS ACL, BYVAL nAclLength AS DWORD, BYVAL dwAclRevision AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION InitializeAcl IMPORT "ADVAPI32.DLL" ALIAS "InitializeAcl" ( _
   BYVAL pAcl AS ACL PTR _                              ' __out PACL pAcl
 , BYVAL nAclLength AS DWORD _                          ' __in DWORD nAclLength
 , BYVAL dwAclRevision AS DWORD _                       ' __in DWORD dwAclRevision
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAclInformation LIB "AdvApi32.dll" _
    ALIAS "GetAclInformation" (pAcl AS ACL, BYVAL pAclInformation AS DWORD, _
    BYVAL nAclInformationLength AS DWORD, _
    BYVAL dwAclInformationClass AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetAclInformation IMPORT "ADVAPI32.DLL" ALIAS "GetAclInformation" ( _
   BYVAL pAcl AS ACL PTR _                              ' __in PACL pAcl
 , BYREF pAclInformation AS ANY _                       ' __out LPVOID pAclInformation
 , BYVAL nAclInformationLength AS DWORD _               ' __in DWORD nAclInformationLength
 , BYVAL dwAclInformationClass AS DWORD _               ' __in ACL_INFORMATION_CLASS dwAclInformationClass
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetAclInformation LIB "AdvApi32.dll" _
    ALIAS "SetAclInformation" (pAcl AS ACL, BYVAL pAclInformation AS DWORD, _
    BYVAL nAclInformationLength AS DWORD, _
    BYVAL dwAclInformationClass AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetAclInformation IMPORT "ADVAPI32.DLL" ALIAS "SetAclInformation" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYREF pAclInformation AS ANY _                       ' __in LPVOID pAclInformation
 , BYVAL nAclInformationLength AS DWORD _               ' __in DWORD nAclInformationLength
 , BYVAL dwAclInformationClass AS DWORD _               ' __in ACL_INFORMATION_CLASS dwAclInformationClass
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAce LIB "AdvApi32.dll" ALIAS "AddAce" _
    (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL dwStartingAceIndex AS DWORD, BYVAL pAceList AS DWORD, _
    BYVAL nAceListLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION AddAce IMPORT "ADVAPI32.DLL" ALIAS "AddAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL dwStartingAceIndex AS DWORD _                  ' __in DWORD dwStartingAceIndex
 , BYREF pAceList AS ANY _                              ' __in LPVOID pAceList
 , BYVAL nAceListLength AS DWORD _                      ' __in DWORD nAceListLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DeleteAce LIB "AdvApi32.dll" ALIAS "DeleteAce" _
    (pAcl AS ACL, BYVAL dwAceIndex AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DeleteAce IMPORT "ADVAPI32.DLL" ALIAS "DeleteAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceIndex AS DWORD _                          ' __in DWORD dwAceIndex
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAce LIB "AdvApi32.dll" ALIAS "GetAce" _
    (pAcl AS ACL, BYVAL dwAceIndex AS DWORD, BYVAL pAce AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetAce IMPORT "ADVAPI32.DLL" ALIAS "GetAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __in  PACL pAcl
 , BYVAL dwAceIndex AS DWORD _                          ' __in  DWORD dwAceIndex
 , BYREF pAce AS ANY _                                  ' __out LPVOID *pAce
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAccessAllowedAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AccessMask AS DWORD, dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION AddAccessAllowedAce IMPORT "ADVAPI32.DLL" ALIAS "AddAccessAllowedAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAccessAllowedAceEx LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddAccessAllowedAceEx IMPORT "ADVAPI32.DLL" ALIAS "AddAccessAllowedAceEx" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF
'#endif /* _WIN32_WINNT >=  0x0500 */

'#if(_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddMandatoryAce LIB "AdvApi32.dll" ALIAS "AddMandatoryAce" ( _
    pAcl AS ACL, BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL MandatoryPolicy AS DWORD, pLabelSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddMandatoryAce IMPORT "ADVAPI32.DLL" ALIAS "AddMandatoryAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL MandatoryPolicy AS DWORD _                     ' __in DWORD MandatoryPolicy
 , BYVAL pLabelSid AS SID PTR _                         ' __in PSID pLabelSid
 ) AS LONG                                              ' BOOL
#ENDIF
#ENDIF ' /* _WIN32_WINNT >=  0x0600 */

'#if(_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601
'#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION AddConditionalAce LIB "AdvApi32.dll" _
'    ALIAS "AddConditionalAce" ( _
'    pAcl                AS ACL, _
'    BYVAL dwAceRevision AS DWORD, _
'    BYVAL AceFlags      AS DWORD, _
'    BYVAL AceType       AS BYTE, _
'    BYVAL AccessMask    AS DWORD, _
'    BYVAL pSid          AS SID, _
'    ConditionStr        AS WSTRINGZ, _
'    ReturnLength        AS DWORD) _
'    AS LONG
'#ELSE
DECLARE FUNCTION AddConditionalAce IMPORT "ADVAPI32.DLL" ALIAS "AddConditionalAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AceType AS BYTE _                              ' __in UCHAR AceType
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYREF ConditionStr AS WSTRINGZ _                     ' __in PWCHAR ConditionStr
 , BYREF ReturnLength AS DWORD _                        ' __out DWORD *ReturnLength
 ) AS LONG                                              ' BOOL
'#ENDIF
#ENDIF   ' /* _WIN32_WINNT >=  0x0601 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAccessDeniedAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessDeniedAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddAccessDeniedAce IMPORT "ADVAPI32.DLL" ALIAS "AddAccessDeniedAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AccessDeniedAceEx LIB "AdvApi32.dll" _
    ALIAS "AccessDeniedAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL AccessMask AS DWORD, pSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AccessDeniedAceEx IMPORT "ADVAPI32.DLL" ALIAS "AccessDeniedAceEx" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF
'#endif /* _WIN32_WINNT >=  0x0500 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAuditAccessAce LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessAce" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL dwAccessMask AS DWORD, pSid AS SID, BYVAL bAuditSuccess AS LONG, _
    BYVAL bAuditFailure AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AddAuditAccessAce IMPORT "ADVAPI32.DLL" ALIAS "AddAuditAccessAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL dwAccessMask AS DWORD _                        ' __in DWORD dwAccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYVAL bAuditSuccess AS LONG _                        ' __in BOOL bAuditSuccess
 , BYVAL bAuditFailure AS LONG _                        ' __in BOOL bAuditFailure
 ) AS LONG                                              ' BOOL
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAuditAccessAceEx LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessAceEx" (pAcl AS ACL, BYVAL dwAceRevision AS DWORD, _
    BYVAL AceFlags AS DWORD, BYVAL dwAccessMask AS DWORD, pSid AS SID, _
    BYVAL bAuditSuccess AS LONG, BYVAL bAuditFailure AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AddAuditAccessAceEx IMPORT "ADVAPI32.DLL" ALIAS "AddAuditAccessAceEx" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL dwAccessMask AS DWORD _                        ' __in DWORD dwAccessMask
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYVAL bAuditSuccess AS LONG _                        ' __in BOOL bAuditSuccess
 , BYVAL bAuditFailure AS LONG _                        ' __in BOOL bAuditFailure
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAccessAllowedObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessAllowedObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, psid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddAccessAllowedObjectAce IMPORT "ADVAPI32.DLL" ALIAS "AddAccessAllowedObjectAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYREF ObjectTypeGuid AS GUID _                       ' __in GUID *ObjectTypeGuid
 , BYREF InheritedObjectTypeGuid AS GUID _              ' __in GUID *InheritedObjectTypeGuid
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAccessDeniedObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAccessDeniedObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, pSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddAccessDeniedObjectAce IMPORT "ADVAPI32.DLL" ALIAS "AddAccessDeniedObjectAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYREF ObjectTypeGuid AS GUID _                       ' __in GUID *ObjectTypeGuid
 , BYREF InheritedObjectTypeGuid AS GUID _              ' __in GUID *InheritedObjectTypeGuid
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddAuditAccessObjectAce LIB "AdvApi32.dll" _
    ALIAS "AddAuditAccessObjectAce" (pAcl AS ACL, _
    BYVAL dwAceRevision AS DWORD, BYVAL AceFlags AS DWORD, _
    BYVAL AccessMask AS DWORD, ObjectTypeGuid AS GUID, _
    InheritedObjectTypeGuid AS GUID, pSid AS SID, _
    BYVAL bAuditSuccess AS LONG, BYVAL bAuditFailure AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AddAuditAccessObjectAce IMPORT "ADVAPI32.DLL" ALIAS "AddAuditAccessObjectAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __inout PACL pAcl
 , BYVAL dwAceRevision AS DWORD _                       ' __in DWORD dwAceRevision
 , BYVAL AceFlags AS DWORD _                            ' __in DWORD AceFlags
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD AccessMask
 , BYREF ObjectTypeGuid AS GUID _                       ' __in GUID *ObjectTypeGuid
 , BYREF InheritedObjectTypeGuid AS GUID _              ' __in GUID *InheritedObjectTypeGuid
 , BYVAL pSid AS SID PTR _                              ' __in PSID pSid
 , BYVAL bAuditSuccess AS LONG _                        ' __in BOOL bAuditSuccess
 , BYVAL bAuditFailure AS LONG _                        ' __in BOOL bAuditFailure
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif /* _WIN32_WINNT >=  0x0500 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FindFirstFreeAce LIB "AdvApi32.dll" ALIAS "FindFirstFreeAce" _
    (pAcl AS ACL, pAce AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FindFirstFreeAce IMPORT "ADVAPI32.DLL" ALIAS "FindFirstFreeAce" ( _
   BYVAL pAcl AS ACL PTR _                              ' __in  PACL pAcl
 , BYREF pAce AS ANY _                                  ' __out LPVOID *pAce
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION InitializeSecurityDescriptor IMPORT "ADVAPI32.DLL" ALIAS "InitializeSecurityDescriptor" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL dwRevision AS DWORD _                          ' __in  DWORD dwRevision
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsValidSecurityDescriptor IMPORT "ADVAPI32.DLL" ALIAS "IsValidSecurityDescriptor" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsValidRelativeSecurityDescriptor IMPORT "ADVAPI32.DLL" ALIAS "IsValidRelativeSecurityDescriptor" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL SecurityDescriptorLength AS DWORD _            ' __in ULONG SecurityDescriptorLength
 , BYVAL RequiredInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION RequiredInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSecurityDescriptorLength IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorLength" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS DWORD                                             ' DWORD

'#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION GetSecurityDescriptorControl LIB "AdvApi32.dll" _
'    ALIAS "GetSecurityDescriptorControl" _
'    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
'    pControl AS SECURITY_DESCRIPTOR, lpdwRevision AS DWORD) AS LONG
'#ELSE
DECLARE FUNCTION GetSecurityDescriptorControl IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorControl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF pControl AS WORD _                             ' __out PSECURITY_DESCRIPTOR_CONTROL pControl
 , BYREF lpdwRevision AS DWORD _                        ' __out LPDWORD lpdwRevision
 ) AS LONG                                              ' BOOL
'#ENDIF

'#if(_WIN32_WINNT >= 0x0500)
DECLARE FUNCTION SetSecurityDescriptorControl IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorControl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAl ControlBitsOfInterest AS WORD _                ' __in SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest
 , BYVAL ControlBitsToSet AS WORD _                     ' __in SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >=  0x0500 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSecurityDescriptorDacl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorDacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL bDaclPresent AS LONG, pDacl AS ACL, BYVAL bDaclDefaulted AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION SetSecurityDescriptorDacl IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorDacl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR  _  ' __inout  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL bDaclPresent AS LONG _                         ' __in BOOL bDaclPresent
 , BYVAL pDacl AS ACL PTR _                             ' __in PACL pDacl
 , BYVAL bDaclDefaulted AS LONG _                       ' __in BOOL bDaclDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSecurityDescriptorDacl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorDacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, lpbDaclPresent AS LONG, _
    pDacl AS DWORD, lpbDaclDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetSecurityDescriptorDacl IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorDacl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF lpbDaclPresent AS LONG _                       ' __out LPBOOL lpbDaclPresent
 , BYREF pDacl AS ANY _                                 ' __out PACL *pDacl
 , BYREF lpbDaclDefaulted AS LONG _                     ' __out LPBOOL lpbDaclDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSecurityDescriptorSacl LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorSacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, BYVAL bSaclPresent AS LONG, _
    pSacl AS ACL, BYVAL bSaclDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SetSecurityDescriptorSacl IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorSacl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __inout  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL bSaclPresent AS LONG _                         ' __in BOOL bSaclPresent
 , BYVAL pSacl AS ACL PTR _                             ' __in PACL pSacl
 , BYVAL bSaclDefaulted AS LONG _                       ' __in BOOL bSaclDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSecurityDescriptorSacl LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorSacl" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    BYVAL lpbSaclPresent AS LONG, pSacl AS DWORD, lpbSaclDefaulted AS LONG) _
    AS LONG
#ELSE
DECLARE FUNCTION GetSecurityDescriptorSacl IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorSacl" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF lpbSaclPresent AS LONG _                       ' __out LPBOOL lpbSaclPresent
 , BYREF pSacl AS ANY _                                 ' __out PACL *pSacl
 , BYREF lpbSaclDefaulted AS LONG _                     ' __out LPBOOL lpbSaclDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSecurityDescriptorOwner LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorOwner" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pOwner AS SID, _
    BYVAL bOwnerDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SetSecurityDescriptorOwner IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorOwner" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __inout  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL pOwner AS SID PTR _                            ' __in PSID pOwner
 , BYVAL bOwnerDefaulted AS LONG _                      ' __in BOOL bOwnerDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSecurityDescriptorOwner LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorOwner" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pOwner AS DWORD, _
    BYVAL lpbOwnerDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetSecurityDescriptorOwner IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorOwner" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF pOwner AS ANY _                                ' __out PSID *pOwner
 , BYREF lpbOwnerDefaulted AS LONG _                    ' __out LPBOOL lpbOwnerDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSecurityDescriptorGroup LIB "AdvApi32.dll" _
    ALIAS "SetSecurityDescriptorGroup" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pGroup AS SID, _
    BYVAL bGroupDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SetSecurityDescriptorGroup IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorGroup" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __inout  PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL pGroup AS SID PTR _                            ' __in PSID pGroup
 , BYVAL bGroupDefaulted AS LONG _                      ' __in BOOL bGroupDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSecurityDescriptorGroup LIB "AdvApi32.dll" _
    ALIAS "GetSecurityDescriptorGroup" _
    (pSecurityDescriptor AS SECURITY_DESCRIPTOR, pGroup AS DWORD, _
    lpbGroupDefaulted AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetSecurityDescriptorGroup IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorGroup" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF pGroup AS ANY _                                ' __out PSID *pGroup
 , BYREF lpbGroupDefaulted AS LONG _                    ' __out LPBOOL lpbGroupDefaulted
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetSecurityDescriptorRMControl IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityDescriptorRMControl" ( _
   BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __inout  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL RMControl AS BYTE PTR _                        ' __in PUCHAR RMControl
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetSecurityDescriptorRMControl IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityDescriptorRMControl" ( _
   BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in  PSECURITY_DESCRIPTOR SecurityDescriptor
 , BYVAL RMControl AS BYTE PTR _                        ' __out PUCHAR RMControl
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CreatePrivateObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "CreatePrivateObjectSecurity" ( _
   BYREF ParentDescriptor AS SECURITY_DESCRIPTOR _      ' __in  PSECURITY_DESCRIPTOR ParentDescriptor
 , BYREF CreatorDescriptor AS SECURITY_DESCRIPTOR _     ' __in  PSECURITY_DESCRIPTOR CreatorDescriptor
 , BYREF NewDescriptor AS DWORD _                       ' __out PSECURITY_DESCRIPTOR * NewDescriptor
 , BYVAL IsDirectoryObject AS LONG _                    ' __in  BOOL IsDirectoryObject
 , BYVAL Token AS DWORD _                               ' __in  HANDLE Token
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION ConvertToAutoInheritPrivateObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "ConvertToAutoInheritPrivateObjectSecurity" ( _
   BYREF ParentDescriptor AS SECURITY_DESCRIPTOR _      ' __in  PSECURITY_DESCRIPTOR ParentDescriptor
 , BYREF CurrentSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __in  PSECURITY_DESCRIPTOR CurrentSecurityDescriptor
 , BYREF NewSecurityDescriptor AS DWORD _               ' __out PSECURITY_DESCRIPTOR *NewSecurityDescriptor
 , BYREF ObjectType AS GUID _                           ' __in  GUID *ObjectType
 , BYVAL IsDirectoryObject AS BYTE _                    ' __in  BOOLEAN IsDirectoryObject
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreatePrivateObjectSecurityEx IMPORT "ADVAPI32.DLL" ALIAS "CreatePrivateObjectSecurityEx" ( _
   BYREF ParentDescriptor AS SECURITY_DESCRIPTOR _      ' __in  PSECURITY_DESCRIPTOR ParentDescriptor
 , BYREF CreatorDescriptor AS SECURITY_DESCRIPTOR _     ' __in  PSECURITY_DESCRIPTOR CreatorDescriptor
 , BYREF NewDescriptor AS DWORD _                       ' __out PSECURITY_DESCRIPTOR * NewDescriptor
 , BYREF ObjectType AS GUID _                           ' __in  GUID *ObjectType
 , BYVAL IsContainerObject AS LONG _                    ' __in  BOOL IsContainerObject
 , BYVAL AutoInheritFlags AS DWORD _                    ' __in  ULONG AutoInheritFlags
 , BYVAL Token AS DWORD _                               ' __in  HANDLE Token
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreatePrivateObjectSecurityWithMultipleInheritance _
    LIB "AdvApi32.dll" _
    ALIAS "CreatePrivateObjectSecurityWithMultipleInheritance" _
    (ParentDescriptor AS SECURITY_DESCRIPTOR, _
    CreatorDescriptor AS SECURITY_DESCRIPTOR, _
    NewDescriptor AS DWORD, BYVAL ObjectTypes AS DWORD, _
    BYVAL GuidCount AS DWORD, BYVAL IsDirectoryObject AS LONG, _
    BYVAL AutoInheritFlags AS DWORD, BYVAL Token AS DWORD, _
    GenericMapping AS GENERIC_MAPPING) AS LONG
#ELSE
DECLARE FUNCTION CreatePrivateObjectSecurityWithMultipleInheritance IMPORT "ADVAPI32.DLL" ALIAS "CreatePrivateObjectSecurityWithMultipleInheritance" ( _
   BYREF ParentDescriptor AS SECURITY_DESCRIPTOR _      ' __in  PSECURITY_DESCRIPTOR ParentDescriptor
 , BYREF CreatorDescriptor AS SECURITY_DESCRIPTOR _     ' __in  PSECURITY_DESCRIPTOR CreatorDescriptor
 , BYREF NewDescriptor AS DWORD _                       ' __out PSECURITY_DESCRIPTOR * NewDescriptor
 , BYREF ObjectTypes AS GUID _                          ' __in  GUID **ObjectTypes
 , BYVAL GuidCount AS DWORD _                           ' __in  ULONG GuidCount
 , BYVAL IsContainerObject AS LONG _                    ' __in  BOOL IsContainerObject
 , BYVAL AutoInheritFlags AS DWORD _                    ' __in  ULONG AutoInheritFlags
 , BYVAL Token AS DWORD _                               ' __in  HANDLE Token
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in  PGENERIC_MAPPING GenericMapping
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif /* _WIN32_WINNT >=  0x0500 */

DECLARE FUNCTION SetPrivateObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "SetPrivateObjectSecurity" ( _
   BYVAL SecurityInformation AS SECURITY_INFORMATION _   ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF ModificationDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR ModificationDescriptor
 , BYREF ObjectsSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __inout PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 , BYVAL Token AS DWORD _                               ' __in HANDLE Token
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)
DECLARE FUNCTION SetPrivateObjectSecurityEx IMPORT "ADVAPI32.DLL" ALIAS "SetPrivateObjectSecurityEx" ( _
   BYVAL SecurityInformation AS SECURITY_INFORMATION _   ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF ModificationDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR ModificationDescriptor
 , BYREF ObjectsSecurityDescriptor AS DWORD _           ' __inout PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor
 , BYVAL AutoInheritFlags AS DWORD _                    ' __in ULONG AutoInheritFlags
 , BYREF GenericMapping AS GENERIC_MAPPING _            ' __in PGENERIC_MAPPING GenericMapping
 , BYVAL Token AS DWORD _                               ' __in HANDLE Token
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >=  0x0500 */

DECLARE FUNCTION GetPrivateObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "GetPrivateObjectSecurity" ( _
   BYREF ObjectDescriptor AS SECURITY_DESCRIPTOR _      ' __in  PSECURITY_DESCRIPTOR ObjectDescriptor
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ResultantDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR ResultantDescriptor
 , BYVAL DescriptorLength AS DWORD _                    ' __in  DWORD DescriptorLength
 , BYREF ReturnLengt AS DWORD _                         ' __out PDWORD ReturnLengt
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DestroyPrivateObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "DestroyPrivateObjectSecurity" _
    (ObjectDescriptor AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DestroyPrivateObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "DestroyPrivateObjectSecurity" ( _
   BYREF ObjectDescriptor AS SECURITY_DESCRIPTOR _      ' __in PSECURITY_DESCRIPTOR * ObjectDescriptor
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION MakeSelfRelativeSD IMPORT "ADVAPI32.DLL" ALIAS "MakeSelfRelativeSD" ( _
   BYREF pAbsoluteSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor
 , BYREF pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __out PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MakeAbsoluteSD LIB "AdvApi32.dll" ALIAS "MakeAbsoluteSD" _
    (pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    pAbsoluteSecurityDescriptor AS SECURITY_DESCRIPTOR, _
    lpdwAbsoluteSecurityDescriptorSize AS DWORD, pDacl AS ACL, _
    lpdwDaclSize AS DWORD, pSacl AS ACL, lpdwSaclSize AS DWORD, _
    pOwner AS SID, lpdwOwnerSize AS DWORD, pPrimaryGroup AS SID, _
    lpdwPrimaryGroupSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MakeAbsoluteSD IMPORT "ADVAPI32.DLL" ALIAS "MakeAbsoluteSD" ( _
   BYREF pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor
 , BYREF pAbsoluteSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __out PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor
 , BYREF lpdwAbsoluteSecurityDescriptorSize AS DWORD _  ' __inout LPDWORD lpdwAbsoluteSecurityDescriptorSize
 , BYREF pDacl AS ANY _                                 ' __out PACL pDacl
 , BYREF lpdwDaclSize AS DWORD _                        ' __inout LPDWORD lpdwDaclSize
 , BYREF pSacl AS ANY _                                 ' __out PACL pSacl
 , BYREF lpdwSaclSize AS DWORD _                        ' __inout LPDWORD lpdwSaclSize
 , BYREF pOwner AS ANY _                                ' __out PSID pOwner
 , BYREF lpdwOwnerSize AS DWORD _                       ' __inout LPDWORD lpdwOwnerSize
 , BYREF pPrimaryGroup AS ANY _                         ' __out PSID pPrimaryGroup
 , BYREF lpdwPrimaryGroupSize AS DWORD _                ' __inout LPDWORD lpdwPrimaryGroupSize
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION MakeAbsoluteSD2 IMPORT "ADVAPI32.DLL" ALIAS "MakeAbsoluteSD2" ( _
   BYREF pSelfRelativeSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
 , BYREF lpdwBufferSize AS DWORD _                      ' __inout LPDWORD lpdwBufferSize
 ) AS LONG                                              ' BOOL

DECLARE SUB QuerySecurityAccessMask IMPORT "ADVAPI32.DLL" ALIAS "QuerySecurityAccessMask" ( _
   BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF DesiredAccess AS DWORD _                       ' __inout LPDWORD DesiredAccess
 )                                                      ' VOID

DECLARE FUNCTION SetFileSecurityA IMPORT "ADVAPI32.DLL" ALIAS "SetFileSecurityA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetFileSecurityW IMPORT "ADVAPI32.DLL" ALIAS "SetFileSecurityW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetFileSecurity = SetFileSecurityW
#ELSE
   MACRO SetFileSecurity = SetFileSecurityA
#ENDIF

DECLARE FUNCTION GetFileSecurityA IMPORT "ADVAPI32.DLL" ALIAS "GetFileSecurityA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in  LPCSTR lpFileName
 , BYVAL RequestedInformation AS SECURITY_INFORMATION _ ' __in  SECURITY_INFORMATION RequestedInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL nLength AS DWORD _                             ' __in  DWORD nLength
 , BYREF lpnLengthNeeded AS DWORD _                     ' __out LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileSecurityW IMPORT "ADVAPI32.DLL" ALIAS "GetFileSecurityW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYVAL RequestedInformation AS SECURITY_INFORMATION _ ' __in  SECURITY_INFORMATION RequestedInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL nLength AS DWORD _                             ' __in  DWORD nLength
 , BYREF lpnLengthNeeded AS DWORD _                     ' __out LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetFileSecurity = GetFileSecurityW
#ELSE
   MACRO GetFileSecurity = GetFileSecurityA
#ENDIF

DECLARE FUNCTION SetKernelObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "SetKernelObjectSecurity" ( _
   BYVAL Handle AS DWORD _                              ' __in HANDLE Handle
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in PSECURITY_DESCRIPTOR SecurityDescriptor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindFirstChangeNotificationA IMPORT "KERNEL32.DLL" ALIAS "FindFirstChangeNotificationA" ( _
   BYREF lpPathName AS ASCIIZ _                         ' __in LPCSTR lpPathName
 , BYVAL bWatchSubtree AS LONG _                        ' __in BOOL bWatchSubtree
 , BYVAL dwNotifyFilter AS DWORD _                      ' __in DWORD dwNotifyFilter
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstChangeNotificationW IMPORT "KERNEL32.DLL" ALIAS "FindFirstChangeNotificationW" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 , BYVAL bWatchSubtree AS LONG _                        ' __in BOOL bWatchSubtree
 , BYVAL dwNotifyFilter AS DWORD _                      ' __in DWORD dwNotifyFilter
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstChangeNotification = FindFirstChangeNotificationW
#ELSE
   MACRO FindFirstChangeNotification = FindFirstChangeNotificationA
#ENDIF

DECLARE FUNCTION FindNextChangeNotification IMPORT "KERNEL32.DLL" ALIAS "FindNextChangeNotification" ( _
   BYVAL hChangeHandle AS DWORD _                       ' __in HANDLE hChangeHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindCloseChangeNotification IMPORT "KERNEL32.DLL" ALIAS "FindCloseChangeNotification" ( _
   BYVAL hChangeHandle AS DWORD _                       ' __in HANDLE hChangeHandle
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0400)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadDirectoryChangesW LIB "Kernel32.dll" _
    ALIAS "ReadDirectoryChangesW" (BYVAL hDirectory AS DWORD, _
    BYVAL lpBuffer AS DWORD, BYVAL nBufferLength AS DWORD, _
    BYVAL bWatchSubtree AS LONG, BYVAL dwNotifyFilter AS DWORD, _
    lpBytesReturned AS DWORD, lpOverlapped AS OVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadDirectoryChangesW IMPORT "KERNEL32.DLL" ALIAS "ReadDirectoryChangesW" ( _
   BYVAL hDirectory AS DWORD _                          ' __in HANDLE hDirectory
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nBufferLength AS DWORD _                       ' __in DWORD nBufferLength
 , BYVAL bWatchSubtree AS LONG _                        ' __in BOOL bWatchSubtree
 , BYVAL dwNotifyFilter AS DWORD _                      ' __in DWORD dwNotifyFilter
 , BYREF lpBytesReturned AS DWORD _                     ' __out LPDWORD lpBytesReturned
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __inout LPOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO ReadDirectoryChanges = ReadDirectoryChangesW
'#endif /* _WIN32_WINNT >= 0x0400 */

DECLARE FUNCTION VirtualLock IMPORT "KERNEL32.DLL" ALIAS "VirtualLock" ( _
   BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VirtualUnlock IMPORT "KERNEL32.DLL" ALIAS "VirtualUnlock" ( _
   BYVAL lpAddress AS DWORD _                           ' __in LPVOID lpAddress
 , BYVAL dwSize AS DWORD _                              ' __in SIZE_T dwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MapViewOfFileEx LIB "Kernel32.dll" ALIAS "MapViewOfFileEx" _
    (BYVAL hFileMappingObject AS DWORD, BYVAL dwDesiredAccess AS DWORD, _
    BYVAL dwFileOffsetHigh AS DWORD, BYVAL dwFileOffsetLow AS DWORD, _
    BYVAL dwNumberOfBytesToMap AS DWORD, lpBaseAddress AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION MapViewOfFileEx IMPORT "KERNEL32.DLL" ALIAS "MapViewOfFileEx" ( _
   BYVAL hFileMappingObject AS DWORD _                  ' __in HANDLE hFileMappingObject
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwFileOffsetHigh AS DWORD _                    ' __in DWORD dwFileOffsetHigh
 , BYVAL dwFileOffsetLow AS DWORD _                     ' __in DWORD dwFileOffsetLow
 , BYVAL dwNumberOfBytesToMap AS DWORD _                ' __in SIZE_T dwNumberOfBytesToMap
 , OPTIONAL BYVAL lpBaseAddress AS DWORD _              ' __in_opt LPVOID lpBaseAddress
 ) AS DWORD                                             ' LPVOID
#ENDIF

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MapViewOfFileExNuma LIB "Kernel32.dll" _
    ALIAS "MapViewOfFileExNuma" (BYVAL hFileMappingObject AS DWORD, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwFileOffsetHigh AS DWORD, _
    BYVAL dwFileOffsetLow AS DWORD, BYVAL dwNumberOfBytesToMap AS DWORD, _
    lpBaseAddress AS DWORD, BYVAL nndPreferred AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION MapViewOfFileExNuma IMPORT "KERNEL32.DLL" ALIAS "MapViewOfFileExNuma" ( _
   BYVAL hFileMappingObject AS DWORD _                  ' __in HANDLE hFileMappingObject
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwFileOffsetHigh AS DWORD _                    ' __in DWORD dwFileOffsetHigh
 , BYVAL dwFileOffsetLow AS DWORD _                     ' __in DWORD dwFileOffsetLow
 , BYVAL dwNumberOfBytesToMap AS DWORD _                ' __in SIZE_T dwNumberOfBytesToMap
 , BYVAL lpBaseAddress AS DWORD _                       ' __in_opt LPVOID lpBaseAddress
 , BYVAL nndPreferred AS DWORD _                        ' __in DWORD nndPreferred
 ) AS DWORD                                             ' LPVOID
#ENDIF

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION SetPriorityClass IMPORT "KERNEL32.DLL" ALIAS "SetPriorityClass" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL dwPriorityClass AS DWORD _                     ' __in DWORD dwPriorityClass
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPriorityClass IMPORT "KERNEL32.DLL" ALIAS "GetPriorityClass" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION IsBadReadPtr IMPORT "KERNEL32.DLL" ALIAS "IsBadReadPtr" ( _
   BYVAL lp AS DWORD _                                  ' __in CONST VOID *lp
 , BYVAL ucb AS DWORD _                                 ' __in UINT_PTR ucb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadWritePtr IMPORT "KERNEL32.DLL" ALIAS "IsBadWritePtr" ( _
   BYVAL lp AS DWORD _                                  ' __in LPVOID lp
 , BYVAL ucb AS DWORD _                                 ' __in UINT_PTR ucb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadHugeReadPtr IMPORT "KERNEL32.DLL" ALIAS "IsBadHugeReadPtr" ( _
   BYVAL lp AS DWORD _                                  ' __in CONST VOID *lp
 , BYVAL ucb AS DWORD _                                 ' __in UINT_PTR ucb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadHugeWritePtr IMPORT "KERNEL32.DLL" ALIAS "IsBadHugeWritePtr" ( _
   BYVAL lp AS DWORD _                                  ' __in LPVOID lp
 , BYVAL ucb AS DWORD _                                 ' __in UINT_PTR ucb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadCodePtr IMPORT "KERNEL32.DLL" ALIAS "IsBadCodePtr" ( _
   BYVAL lpfn AS DWORD _                                ' __in FARPROC lpfn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadStringPtrA IMPORT "KERNEL32.DLL" ALIAS "IsBadStringPtrA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCSTR lpsz
 , BYVAL ucchMax AS DWORD _                             ' __in UINT_PTR ucchMax
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsBadStringPtrW IMPORT "KERNEL32.DLL" ALIAS "IsBadStringPtrW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCWSTR lpsz
 , BYVAL ucchMax AS DWORD _                             ' __in UINT_PTR ucchMax
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsBadStringPtr = IsBadStringPtrW
#ELSE
   MACRO IsBadStringPtr = IsBadStringPtrA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupAccountSidA LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidA" (lpSystemName AS ASCIIZ, pSid AS SID, _
    xName AS ASCIIZ, cbName AS DWORD, ReferencedDomainName AS ASCIIZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountSidA IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountSidA" ( _
   BYREF lpSystemName AS ASCIIZ _                       ' __in LPCSTR lpSystemName
 , BYVAL Sid AS SID PTR _                               ' __in PSID Sid
 , BYREF Name AS ASCIIZ _                               ' __out LPSTR Name
 , BYREF cchName AS DWORD _                             ' __inout  LPDWORD cchName
 , BYREF ReferencedDomainName AS ASCIIZ _               ' __out LPSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupAccountSidW LIB "AdvApi32.dll" _
    ALIAS "LookupAccountSidW" (lpSystemName AS WSTRINGZ, pSid AS SID, _
    xName AS WSTRINGZ, cbName AS DWORD, ReferencedDomainName AS WSTRINGZ, _
    cbReferencedDomainName AS LONG, peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountSidW IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountSidW" ( _
   BYREF lpSystemName AS WSTRINGZ _                     ' __in LPCWSTR lpSystemName
 , BYVAL Sid AS SID PTR _                               ' __in PSID Sid
 , BYREF Name AS WSTRINGZ _                             ' __out LPWSTR Name
 , BYREF cchName AS DWORD _                             ' __inout  LPDWORD cchName
 , BYREF ReferencedDomainName AS WSTRINGZ _             ' __out LPWSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO LookupAccountSid = LookupAccountSidW
#ELSE
   MACRO LookupAccountSid = LookupAccountSidA
#ENDIF

DECLARE FUNCTION LookupAccountSidLocalA IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountSidLocalA" ( _
   BYVAL Sid AS SID PTR _                               ' __in PSID Sid
 , BYREF Name AS ASCIIZ _                               ' __out LPSTR Name
 , BYREF cchName AS DWORD _                             ' __inout  LPDWORD cchName
 , BYREF ReferencedDomainName AS ASCIIZ _               ' __out LPSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupAccountSidLocalW IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountSidLocalW" ( _
   BYVAL Sid AS SID PTR _                               ' __in PSID Sid
 , BYREF Name AS WSTRINGZ _                             ' __out LPWSTR Name
 , BYREF cchName AS DWORD _                             ' __inout  LPDWORD cchName
 , BYREF ReferencedDomainName AS WSTRINGZ _             ' __out LPWSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LookupAccountSidLocal = LookupAccountSidLocalW
#ELSE
   MACRO LookupAccountSidLocal = LookupAccountSidLocalA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupAccountNameA LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameA" (lpSystemName AS ASCIIZ, _
    lpAccountName AS ASCIIZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS ASCIIZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountNameA IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountNameA" ( _
   BYREF lpSystemName AS ASCIIZ _                       ' __in LPCSTR lpSystemName
 , BYREF lpAccountName AS ASCIIZ _                      ' __in LPCSTR lpAccountName
 , BYREF Sid AS ANY _                                   ' __out PSID Sid
 , BYREF cbSid AS DWORD _                               ' __inout LPDWORD cbSid
 , BYREF ReferencedDomainName AS ASCIIZ _               ' __out LPSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupAccountNameW LIB "AdvApi32.dll" _
    ALIAS "LookupAccountNameW" (lpSystemName AS WSTRINGZ, _
    lpAccountName AS WSTRINGZ, pSid AS SID, cbSid AS DWORD, _
    ReferencedDomainName AS WSTRINGZ, cbReferencedDomainName AS DWORD, _
    peUse AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LookupAccountNameW IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountNameW" ( _
   BYREF lpSystemName AS WSTRINGZ _                     ' __in LPCWSTR lpSystemName
 , BYREF lpAccountName AS WSTRINGZ _                    ' __in LPCWSTR lpAccountName
 , BYREF Sid AS ANY _                                   ' __out PSID Sid
 , BYREF cbSid AS DWORD _                               ' __inout LPDWORD cbSid
 , BYREF ReferencedDomainName AS WSTRINGZ _             ' __out LPWSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO LookupAccountName = LookupAccountNameW
#ELSE
   MACRO LookupAccountName = LookupAccountNameA
#ENDIF

DECLARE FUNCTION LookupAccountNameLocalA IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountNameLocalA" ( _
   BYREF lpAccountName AS ASCIIZ _                      ' __in LPCSTR lpAccountName
 , BYREF Sid AS ANY _                                   ' __out PSID Sid
 , BYREF cbSid AS DWORD _                               ' __inout LPDWORD cbSid
 , BYREF ReferencedDomainName AS ASCIIZ _               ' __out LPSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupAccountNameLocalW IMPORT "ADVAPI32.DLL" ALIAS "LookupAccountNameLocalW" ( _
   BYREF lpAccountName AS WSTRINGZ _                    ' __in LPCWSTR lpAccountName
 , BYREF Sid AS ANY _                                   ' __out PSID Sid
 , BYREF cbSid AS DWORD _                               ' __inout LPDWORD cbSid
 , BYREF ReferencedDomainName AS WSTRINGZ _             ' __out LPWSTR ReferencedDomainName
 , BYREF cchReferencedDomainName AS DWORD _             ' __inout LPDWORD cchReferencedDomainName
 , BYREF peUse AS LONG _                                ' __out PSID_NAME_USE peUse
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LookupAccountNameLocal = LookupAccountNameLocalW
#ELSE
   MACRO LookupAccountNameLocal = LookupAccountNameLocalA
#ENDIF

DECLARE FUNCTION LookupPrivilegeValueA IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeValueA" ( _
   BYREF lpSystemName AS ASCIIZ _                       ' __in  LPCSTR lpSystemName
 , BYREF lpName AS ASCIIZ _                             ' __in  LPCSTR lpName
 , BYREF lpLuid AS ANY _                                ' __out PLUID   lpLuid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupPrivilegeValueW IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeValueW" ( _
   BYREF lpSystemName AS WSTRINGZ _                     ' __in  LPCWSTR lpSystemName
 , BYREF lpName AS WSTRINGZ _                           ' __in  LPCWSTR lpName
 , BYREF lpLuid AS ANY _                                ' __out PLUID   lpLuid
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LookupPrivilegeValue = LookupPrivilegeValueW
#ELSE
   MACRO LookupPrivilegeValue = LookupPrivilegeValueA
#ENDIF

DECLARE FUNCTION LookupPrivilegeNameA IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeNameA" ( _
   BYREF lpSystemName AS ASCIIZ _                       ' __in LPCSTR lpSystemName
 , BYREF lpLuid AS ANY _                                ' __in PLUID  lpLuid
 , BYREF lpName AS ASCIIZ _                             ' __out LPSTR lpName
 , BYREF cchName AS DWORD _                             ' __inout LPDWORD cchName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupPrivilegeNameW IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeNameW" ( _
   BYREF lpSystemName AS WSTRINGZ _                     ' __in LPCWSTR lpSystemName
 , BYREF lpLuid AS ANY _                                ' __in PLUID   lpLuid
 , BYREF lpName AS WSTRINGZ _                           ' __out LPWSTR lpName
 , BYREF cchName AS DWORD _                             ' __inout LPDWORD cchName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LookupPrivilegeName = LookupPrivilegeNameW
#ELSE
   MACRO LookupPrivilegeName = LookupPrivilegeNameA
#ENDIF

DECLARE FUNCTION LookupPrivilegeDisplayNameA IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeDisplayNameA" ( _
   BYREF lpSystemName AS ASCIIZ _                       ' __in LPCSTR lpSystemName
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYREF lpDisplayName AS ASCIIZ _                      ' __out LPSTR lpDisplayName
 , BYREF cchDisplayName AS DWORD _                      ' __inout LPDWORD cchDisplayName
 , BYREF lpLanguageId AS DWORD _                        ' __out LPDWORD lpLanguageId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupPrivilegeDisplayNameW IMPORT "ADVAPI32.DLL" ALIAS "LookupPrivilegeDisplayNameW" ( _
   BYREF lpSystemName AS WSTRINGZ _                     ' __in LPCWSTR lpSystemName
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYREF lpDisplayName AS WSTRINGZ _                    ' __out LPWSTR lpDisplayName
 , BYREF cchDisplayName AS DWORD _                      ' __inout LPDWORD cchDisplayName
 , BYREF lpLanguageId AS DWORD _                        ' __out LPDWORD lpLanguageId
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LookupPrivilegeDisplayName = LookupPrivilegeDisplayNameW
#ELSE
   MACRO LookupPrivilegeDisplayName = LookupPrivilegeDisplayNameA
#ENDIF

DECLARE FUNCTION AllocateLocallyUniqueId IMPORT "ADVAPI32.DLL" ALIAS "AllocateLocallyUniqueId" ( _
   BYREF Luid AS ANY _                                  ' __out PLUID Luid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BuildCommDCBA IMPORT "KERNEL32.DLL" ALIAS "BuildCommDCBA" ( _
   BYREF lpDef AS ASCIIZ _                              ' __in  LPCSTR lpDef
 , BYREF lpDCB AS DCB _                                 ' __out LPDCB lpDCB
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BuildCommDCBW IMPORT "KERNEL32.DLL" ALIAS "BuildCommDCBW" ( _
   BYREF lpDef AS WSTRINGZ _                            ' __in  LPCWSTR lpDef
 , BYREF lpDCB AS DCB _                                 ' __out LPDCB   lpDCB
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO BuildCommDCB = BuildCommDCBW
#ELSE
   MACRO BuildCommDCB = BuildCommDCBA
#ENDIF

DECLARE FUNCTION BuildCommDCBAndTimeoutsA IMPORT "KERNEL32.DLL" ALIAS "BuildCommDCBAndTimeoutsA" ( _
   BYREF lpDef AS ASCIIZ _                              ' __in  LPCSTR lpDef
 , BYREF lpDCB AS DCB _                                 ' __out LPDCB  lpDCB
 , BYREF lpCommTimeouts AS COMMTIMEOUTS _               ' __out LPCOMMTIMEOUTS lpCommTimeouts
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BuildCommDCBAndTimeoutsW IMPORT "KERNEL32.DLL" ALIAS "BuildCommDCBAndTimeoutsW" ( _
   BYREF lpDef AS WSTRINGZ _                            ' __in  LPCWSTR lpDef
 , BYREF lpDCB AS DCB _                                 ' __out LPDCB   lpDCB
 , BYREF lpCommTimeouts AS COMMTIMEOUTS _               ' __out LPCOMMTIMEOUTS lpCommTimeouts
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO BuildCommDCBAndTimeouts = BuildCommDCBAndTimeoutsW
#ELSE
   MACRO BuildCommDCBAndTimeouts = BuildCommDCBAndTimeoutsA
#ENDIF

DECLARE FUNCTION CommConfigDialogA IMPORT "KERNEL32.DLL" ALIAS "CommConfigDialogA" ( _
   BYREF lpszName AS ASCIIZ _                           ' __in LPCSTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND   hWnd
 , BYREF lpCC AS COMMCONFIG _                           ' __inout    LPCOMMCONFIG lpCC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CommConfigDialogW IMPORT "KERNEL32.DLL" ALIAS "CommConfigDialogW" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCWSTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND    hWnd
 , BYREF lpCC AS COMMCONFIG _                           ' __inout     LPCOMMCONFIG lpCC
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CommConfigDialog = CommConfigDialogW
#ELSE
   MACRO CommConfigDialog = CommConfigDialogA
#ENDIF

DECLARE FUNCTION GetDefaultCommConfigA IMPORT "KERNEL32.DLL" ALIAS "GetDefaultCommConfigA" ( _
   BYREF lpszName AS ASCIIZ _                           ' __in LPCSTR lpszName
 , BYREF lpCC AS COMMCONFIG _                           ' __out LPCOMMCONFIG lpCC
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDefaultCommConfigW IMPORT "KERNEL32.DLL" ALIAS "GetDefaultCommConfigW" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCWSTR lpszName
 , BYREF lpCC AS COMMCONFIG _                           ' __out LPCOMMCONFIG lpCC
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetDefaultCommConfig = GetDefaultCommConfigW
#ELSE
   MACRO GetDefaultCommConfig = GetDefaultCommConfigA
#ENDIF

DECLARE FUNCTION SetDefaultCommConfigA IMPORT "KERNEL32.DLL" ALIAS "SetDefaultCommConfigA" ( _
   BYREF lpszName AS ASCIIZ _                           ' __in LPCSTR lpszName
 , BYREF lpCC AS COMMCONFIG _                           ' __in LPCOMMCONFIG lpCC
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetDefaultCommConfigW IMPORT "KERNEL32.DLL" ALIAS "SetDefaultCommConfigW" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCWSTR lpszName
 , BYREF lpCC AS COMMCONFIG _                           ' __in LPCOMMCONFIG lpCC
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetDefaultCommConfig = SetDefaultCommConfigW
#ELSE
   MACRO SetDefaultCommConfig = SetDefaultCommConfigA
#ENDIF

%MAX_COMPUTERNAME_LENGTH = 15

DECLARE FUNCTION GetComputerNameA IMPORT "KERNEL32.DLL" ALIAS "GetComputerNameA" ( _
   BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetComputerNameW IMPORT "KERNEL32.DLL" ALIAS "GetComputerNameW" ( _
   BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetComputerName = GetComputerNameW
#ELSE
   MACRO GetComputerName = GetComputerNameA
#ENDIF

DECLARE FUNCTION SetComputerNameA IMPORT "KERNEL32.DLL" ALIAS "SetComputerNameA" ( _
   BYREF lpComputerName AS ASCIIZ _                     ' __in LPCSTR lpComputerName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetComputerNameW IMPORT "KERNEL32.DLL" ALIAS "SetComputerNameW" ( _
   BYREF lpComputerName AS WSTRINGZ _                   ' __in LPCWSTR lpComputerName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetComputerName = SetComputerNameW
#ELSE
   MACRO SetComputerName = SetComputerNameA
#ENDIF

'#if (_WIN32_WINNT >= 0x0500)

' COMPUTER_NAME_FORMAT enum
%ComputerNameNetBIOS                   = 0
%ComputerNameDnsHostname               = 1
%ComputerNameDnsDomain                 = 2
%ComputerNameDnsFullyQualified         = 3
%ComputerNamePhysicalNetBIOS           = 4
%ComputerNamePhysicalDnsHostname       = 5
%ComputerNamePhysicalDnsDomain         = 6
%ComputerNamePhysicalDnsFullyQualified = 7
%ComputerNameMax                       = 8

DECLARE FUNCTION GetComputerNameExA IMPORT "KERNEL32.DLL" ALIAS "GetComputerNameExA" ( _
   BYVAL NameType AS LONG _                             ' __in COMPUTER_NAME_FORMAT NameType
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetComputerNameExW IMPORT "KERNEL32.DLL" ALIAS "GetComputerNameExW" ( _
   BYVAL NameType AS LONG _                             ' __in COMPUTER_NAME_FORMAT NameType
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetComputerNameEx = GetComputerNameExW
#ELSE
   MACRO GetComputerNameEx = GetComputerNameExA
#ENDIF

DECLARE FUNCTION SetComputerNameExA IMPORT "KERNEL32.DLL" ALIAS "SetComputerNameExA" ( _
   BYVAL NameType AS LONG _                             ' __in COMPUTER_NAME_FORMAT NameType
 , BYREF lpBuffer AS ASCIIZ _                           ' __in LPCSTR lpBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetComputerNameExW IMPORT "KERNEL32.DLL" ALIAS "SetComputerNameExW" ( _
   BYVAL NameType AS LONG _                             ' __in COMPUTER_NAME_FORMAT NameType
 , BYREF lpBuffer AS WSTRINGZ _                         ' __in LPCWSTR lpBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetComputerNameEx = SetComputerNameExW
#ELSE
   MACRO SetComputerNameEx = SetComputerNameExA
#ENDIF

DECLARE FUNCTION DnsHostnameToComputerNameA IMPORT "KERNEL32.DLL" ALIAS "DnsHostnameToComputerNameA" ( _
   BYREF Hostname AS ASCIIZ _                           ' __in LPCSTR Hostname
 , BYREF ComputerName AS ASCIIZ _                       ' __out LPSTR ComputerName
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DnsHostnameToComputerNameW IMPORT "KERNEL32.DLL" ALIAS "DnsHostnameToComputerNameW" ( _
   BYREF Hostname AS WSTRINGZ _                         ' __in LPCWSTR Hostname
 , BYREF ComputerName AS WSTRINGZ _                     ' __out LPWSTR ComputerName
 , BYREF nSize AS DWORD _                               ' __inout LPDWORD nSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DnsHostnameToComputerName = DnsHostnameToComputerNameW
#ELSE
   MACRO DnsHostnameToComputerName = DnsHostnameToComputerNameA
#ENDIF

'#endif // _WIN32_WINNT

DECLARE FUNCTION GetUserNameA IMPORT "ADVAPI32.DLL" ALIAS "GetUserNameA" ( _
   BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYREF pcbBuffer AS DWORD _                           ' __inout LPDWORD pcbBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUserNameW IMPORT "ADVAPI32.DLL" ALIAS "GetUserNameW" ( _
   BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYREF pcbBuffer AS DWORD _                           ' __inout LPDWORD pcbBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUserName = GetUserNameW
#ELSE
   MACRO GetUserName = GetUserNameA
#ENDIF

'//
'// Logon Support APIs
'//

%LOGON32_LOGON_INTERACTIVE       = 2
%LOGON32_LOGON_NETWORK           = 3
%LOGON32_LOGON_BATCH             = 4
%LOGON32_LOGON_SERVICE           = 5
%LOGON32_LOGON_UNLOCK            = 7
'#if(_WIN32_WINNT >= 0x0500)
%LOGON32_LOGON_NETWORK_CLEARTEXT = 8
%LOGON32_LOGON_NEW_CREDENTIALS   = 9
'#endif // (_WIN32_WINNT >= 0x0500)

'#define LOGON32_PROVIDER_DEFAULT    0
'#define LOGON32_PROVIDER_WINNT35    1
'#if(_WIN32_WINNT >= 0x0400)
'#define LOGON32_PROVIDER_WINNT40    2
'#endif /* _WIN32_WINNT >= 0x0400 */
'#if(_WIN32_WINNT >= 0x0500)
'#define LOGON32_PROVIDER_WINNT50    3
'#endif // (_WIN32_WINNT >= 0x0500)
'#if(_WIN32_WINNT >= 0x0600)
'#define LOGON32_PROVIDER_VIRTUAL    4
'#endif // (_WIN32_WINNT >= 0x0600)

%LOGON32_PROVIDER_DEFAULT  = 0
%LOGON32_PROVIDER_WINNT35  = 1
%LOGON32_PROVIDER_WINNT40  = 2
%LOGON32_PROVIDER_WINNT50  = 3
%LOGON32_PROVIDER_VIRTUAL  = 4


DECLARE FUNCTION LogonUserA IMPORT "ADVAPI32.DLL" ALIAS "LogonUserA" ( _
   BYREF lpszUsername AS ASCIIZ _                       ' __in  LPCSTR  lpszUsername
 , BYREF lpszDomain AS ASCIIZ _                         ' __in  LPCSTR  lpszDomain
 , BYREF lpszPassword AS ASCIIZ _                       ' __in  LPCSTR  lpszPassword
 , BYVAL dwLogonType AS DWORD _                         ' __in  DWORD   dwLogonType
 , BYVAL dwLogonProvider AS DWORD _                     ' __in  DWORD   dwLogonProvider
 , BYREF phToken AS DWORD _                             ' __out PHANDLE phToken
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LogonUserW IMPORT "ADVAPI32.DLL" ALIAS "LogonUserW" ( _
   BYREF lpszUsername AS WSTRINGZ _                     ' __in  LPCWSTR lpszUsername
 , BYREF lpszDomain AS WSTRINGZ _                       ' __in  LPCWSTR lpszDomain
 , BYREF lpszPassword AS WSTRINGZ _                     ' __in  LPCWSTR lpszPassword
 , BYVAL dwLogonType AS DWORD _                         ' __in  DWORD   dwLogonType
 , BYVAL dwLogonProvider AS DWORD _                     ' __in  DWORD   dwLogonProvider
 , BYREF phToken AS DWORD _                             ' __out PHANDLE phToken
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO LogonUser = LogonUserW
#ELSE
   MACRO LogonUser = LogonUserA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LogonUserExA LIB "AdvApi32.dll" ALIAS "LogonUserExA" _
    (lpszUsername AS ASCIIZ, lpszDomain AS ASCIIZ, lpszPassword AS ASCIIZ, _
    BYVAL dwLogonType AS DWORD, BYVAL dwLogonProvider AS DWORD, _
    phToken AS DWORD, ppLogonSid AS DWORD, ppProfileBuffer AS DWORD, _
    pdwProfileLength AS DWORD, pQuotaLimits AS QUOTA_LIMITS) AS LONG
#ELSE
DECLARE FUNCTION LogonUserExA IMPORT "ADVAPI32.DLL" ALIAS "LogonUserExA" ( _
   BYREF lpszUsername AS ASCIIZ _                       ' __in  LPCSTR  lpszUsername
 , BYREF lpszDomain AS ASCIIZ _                         ' __in  LPCSTR  lpszDomain
 , BYREF lpszPassword AS ASCIIZ _                       ' __in  LPCSTR  lpszPassword
 , BYVAL dwLogonType AS DWORD _                         ' __in  DWORD   dwLogonType
 , BYVAL dwLogonProvider AS DWORD _                     ' __in  DWORD   dwLogonProvider
 , BYREF phToken AS DWORD _                             ' __out PHANDLE phToken
 , BYREF ppLogonSid AS ANY _                            ' __out PSID   *ppLogonSid
 , BYREF ppProfileBuffer AS ANY _                       ' __out PVOID  *ppProfileBuffer
 , BYREF pdwProfileLength AS DWORD _                    ' __out LPDWORD pdwProfileLength
 , BYREF pQuotaLimits AS QUOTA_LIMITS _                 ' __out PQUOTA_LIMITS pQuotaLimits
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LogonUserExW LIB "AdvApi32.dll" ALIAS "LogonUserExW" _
    (lpszUsername AS WSTRINGZ, lpszDomain AS WSTRINGZ, _
    lpszPassword AS WSTRINGZ, BYVAL dwLogonType AS DWORD, _
    BYVAL dwLogonProvider AS DWORD, phToken AS DWORD, ppLogonSid AS DWORD, _
    ppProfileBuffer AS DWORD, pdwProfileLength AS DWORD, _
    pQuotaLimits AS QUOTA_LIMITS) AS LONG
#ELSE
DECLARE FUNCTION LogonUserExW IMPORT "ADVAPI32.DLL" ALIAS "LogonUserExW" ( _
   BYREF lpszUsername AS WSTRINGZ _                     ' __in  LPCWSTR lpszUsername
 , BYREF lpszDomain AS WSTRINGZ _                       ' __in  LPCWSTR lpszDomain
 , BYREF lpszPassword AS WSTRINGZ _                     ' __in  LPCWSTR lpszPassword
 , BYVAL dwLogonType AS DWORD _                         ' __in  DWORD   dwLogonType
 , BYVAL dwLogonProvider AS DWORD _                     ' __in  DWORD   dwLogonProvider
 , BYREF phToken AS DWORD _                             ' __out PHANDLE phToken
 , BYREF ppLogonSid AS ANY _                            ' __out PSID   *ppLogonSid
 , BYREF ppProfileBuffer AS ANY _                       ' __out PVOID  *ppProfileBuffer,
 , BYREF pdwProfileLength AS DWORD _                    ' __out LPDWORD pdwProfileLength
 , BYREF pQuotaLimits AS QUOTA_LIMITS _                 ' __out PQUOTA_LIMITS pQuotaLimits
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO LogonUserEx = LogonUserExW
#ELSE
   MACRO LogonUserEx = LogonUserExA
#ENDIF

DECLARE FUNCTION ImpersonateLoggedOnUser IMPORT "ADVAPI32.DLL" ALIAS "ImpersonateLoggedOnUser" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE  hToken
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateProcessAsUserA IMPORT "ADVAPI32.DLL" ALIAS "CreateProcessAsUserA" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpApplicationName AS ASCIIZ _                  ' __in LPCSTR lpApplicationName
 , BYREF lpCommandLine AS ASCIIZ _                      ' __inout LPSTR lpCommandLine
 , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _   ' __in LPSECURITY_ATTRIBUTES lpProcessAttributes
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL bInheritHandles AS LONG _                      ' __in BOOL bInheritHandles
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS ASCIIZ _                 ' __in LPCSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOA _                ' __in LPSTARTUPINFOA lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateProcessAsUserW IMPORT "ADVAPI32.DLL" ALIAS "CreateProcessAsUserW" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYREF lpApplicationName AS WSTRINGZ _                ' __in LPCWSTR lpApplicationName
 , BYREF lpCommandLine AS WSTRINGZ _                    ' __inout LPWSTR lpCommandLine
 , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _   ' __in LPSECURITY_ATTRIBUTES lpProcessAttributes
 , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _    ' __in LPSECURITY_ATTRIBUTES lpThreadAttributes
 , BYVAL bInheritHandles AS LONG _                      ' __in BOOL bInheritHandles
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS WSTRINGZ _               ' __in LPCWSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOW _                ' __in LPSTARTUPINFOW lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateProcessAsUser = CreateProcessAsUserW
#ELSE
   MACRO CreateProcessAsUser = CreateProcessAsUserA
#ENDIF

'#if(_WIN32_WINNT >= 0x0500)

'//
'// LogonFlags
'//
%LOGON_WITH_PROFILE         = &H00000001???
%LOGON_NETCREDENTIALS_ONLY  = &H00000002???
%LOGON_ZERO_PASSWORD_BUFFER = &H80000000???

DECLARE FUNCTION CreateProcessWithLogonW IMPORT "ADVAPI32.DLL" ALIAS "CreateProcessWithLogonW" ( _
   BYREF lpUsername AS WSTRINGZ _                       ' __in LPCWSTR lpUsername
 , BYREF lpDomain AS WSTRINGZ _                         ' __in LPCWSTR lpDomain
 , BYREF lpPassword AS WSTRINGZ _                       ' __in LPCWSTR lpPassword
 , BYVAL dwLogonFlags AS DWORD _                        ' __in DWORD dwLogonFlags
 , BYREF lpApplicationName AS WSTRINGZ _                ' __in LPCWSTR lpApplicationName
 , BYREF lpCommandLine AS WSTRINGZ _                    ' __inout LPWSTR lpCommandLine
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS WSTRINGZ _               ' __in LPCWSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOW _                ' __in LPSTARTUPINFOW lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

MACRO CreateProcessWithLogon = CreateProcessWithLogonW

DECLARE FUNCTION CreateProcessWithTokenW IMPORT "ADVAPI32.DLL" ALIAS "CreateProcessWithTokenW" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL dwLogonFlags AS DWORD _                        ' __in DWORD dwLogonFlags
 , BYREF lpApplicationName AS WSTRINGZ _                ' __in LPCWSTR lpApplicationName
 , BYREF lpCommandLine AS WSTRINGZ _                    ' __inout LPWSTR lpCommandLine
 , BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL lpEnvironment AS DWORD _                       ' __in LPVOID lpEnvironment
 , BYREF lpCurrentDirectory AS WSTRINGZ _               ' __in LPCWSTR lpCurrentDirectory
 , BYREF lpStartupInfo AS STARTUPINFOW _                ' __in LPSTARTUPINFOW lpStartupInfo
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION lpProcessInformation
 ) AS LONG                                              ' BOOL

MACRO CreateProcessWithToken = CreateProcessWithTokenW

'#endif // (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION ImpersonateAnonymousToken IMPORT "ADVAPI32.DLL" ALIAS "ImpersonateAnonymousToken" ( _
   BYVAL ThreadHandle AS DWORD _                        ' __in HANDLE ThreadHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DuplicateTokenEx IMPORT "ADVAPI32.DLL" ALIAS "DuplicateTokenEx" ( _
   BYVAL hExistingToken AS DWORD _                      ' __in HANDLE hExistingToken
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYREF lpTokenAttributes AS SECURITY_ATTRIBUTES _     ' __in LPSECURITY_ATTRIBUTES lpTokenAttributes
 , BYVAL ImpersonationLevel AS LONG _                   ' __in SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
 , BYVAL TokenType AS LONG _                            ' __in TOKEN_TYPE TokenType
 , BYREF phNewToken AS DWORD _                          ' __out PHANDLE phNewToken
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateRestrictedToken LIB "AdvApi32.dll" _
    ALIAS "CreateRestrictedToken" (BYVAL ExistingTokenHandle AS DWORD, _
    BYVAL Flags AS DWORD, BYVAL DisableSidCount AS DWORD, _
    BYVAL SidsToDisable AS SID_AND_ATTRIBUTES PTR, _
    BYVAL DeletePrivilegeCount AS DWORD, _
    BYVAL PrivilegesToDelete AS LUID_AND_ATTRIBUTES PTR, _
    BYVAL RestrictedSidCount AS DWORD, _
    BYVAL SidsToRestrict AS SID_AND_ATTRIBUTES PTR, NewTokenHandle AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION CreateRestrictedToken IMPORT "ADVAPI32.DLL" ALIAS "CreateRestrictedToken" ( _
   BYVAL ExistingTokenHandle AS DWORD _                 ' __in HANDLE ExistingTokenHandle
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL DisableSidCount AS DWORD _                     ' __in DWORD DisableSidCount
 , BYREF SidsToDisable AS SID_AND_ATTRIBUTES _          ' __in PSID_AND_ATTRIBUTES SidsToDisable
 , BYVAL DeletePrivilegeCount AS DWORD _                ' __in DWORD DeletePrivilegeCount
 , BYREF PrivilegesToDelete AS LUID_AND_ATTRIBUTES _    ' __in PLUID_AND_ATTRIBUTES PrivilegesToDelete
 , BYVAL RestrictedSidCount AS DWORD _                  ' __in DWORD RestrictedSidCount
 , BYREF SidsToRestrict AS SID_AND_ATTRIBUTES _         ' __in PSID_AND_ATTRIBUTES SidsToRestrict
 , BYREF NewTokenHandle AS DWORD _                      ' __out PHANDLE NewTokenHandle
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION IsTokenRestricted IMPORT "ADVAPI32.DLL" ALIAS "IsTokenRestricted" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in HANDLE TokenHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsTokenUntrusted IMPORT "ADVAPI32.DLL" ALIAS "IsTokenUntrusted" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in HANDLE TokenHandle
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CheckTokenMembership LIB "AdvApi32.dll" _
    ALIAS "CheckTokenMembership" (BYVAL hToken AS DWORD, SidToCheck AS SID, _
    IsMember AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CheckTokenMembership IMPORT "ADVAPI32.DLL" ALIAS "CheckTokenMembership" ( _
   BYVAL TokenHandle AS DWORD _                         ' __in  HANDLE TokenHandle
 , BYVAL SidToCheck AS SID PTR _                        ' __in  PSID SidToCheck
 , BYREF IsMember AS LONG _                             ' __out PBOOL IsMember
 ) AS LONG                                              ' BOOL
#ENDIF

'//
'// Thread pool API's
'//

'#if (_WIN32_WINNT >= 0x0500)

'typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK ;

DECLARE FUNCTION RegisterWaitForSingleObject IMPORT "KERNEL32.DLL" ALIAS "RegisterWaitForSingleObject" ( _
   BYREF phNewWaitObject AS DWORD _                     ' __out PHANDLE phNewWaitObject
 , BYVAL hObject AS DWORD _                             ' __in  HANDLE hObject
 , BYVAL Callback AS DWORD _                            ' __in  WAITORTIMERCALLBACK Callback
 , BYVAL Context AS DWORD _                             ' __in  PVOID Context
 , BYVAL dwMilliseconds AS DWORD  _                     ' __in  ULONG dwMilliseconds
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RegisterWaitForSingleObjectEx IMPORT "KERNEL32.DLL" ALIAS "RegisterWaitForSingleObjectEx" ( _
   BYVAL hObject AS DWORD _                             ' __in HANDLE hObject
 , BYVAL Callback AS DWORD _                            ' __in WAITORTIMERCALLBACK Callback
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 , BYVAL dwMilliseconds AS DWORD _                      ' __in ULONG dwMilliseconds
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG dwFlags
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION UnregisterWait IMPORT "KERNEL32.DLL" ALIAS "UnregisterWait" ( _
   BYVAL WaitHandle AS DWORD _                          ' __in HANDLE WaitHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnregisterWaitEx IMPORT "KERNEL32.DLL" ALIAS "UnregisterWaitEx" ( _
   BYVAL WaitHandle AS DWORD _                          ' __in HANDLE WaitHandle
 , OPTIONAL BYVAL CompletionEvent AS DWORD _            ' __in_opt HANDLE CompletionEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueueUserWorkItem IMPORT "KERNEL32.DLL" ALIAS "QueueUserWorkItem" ( _
   BYVAL Function AS DWORD _                            ' __in LPTHREAD_START_ROUTINE Function
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BindIoCompletionCallback IMPORT "KERNEL32.DLL" ALIAS "BindIoCompletionCallback" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL Function AS DWORD _                            ' __in LPOVERLAPPED_COMPLETION_ROUTINE Function
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateTimerQueue IMPORT "KERNEL32.DLL" ALIAS "CreateTimerQueue" ( _
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateTimerQueueTimer IMPORT "KERNEL32.DLL" ALIAS "CreateTimerQueueTimer" ( _
   BYREF phNewTimer AS DWORD _                          ' __out PHANDLE phNewTimer
 , BYVAL TimerQueue AS DWORD _                          ' __in  HANDLE TimerQueue
 , BYVAL Callback AS DWORD _                            ' __in  WAITORTIMERCALLBACK Callback
 , BYVAL Parameter AS DWORD _                           ' __in  PVOID Parameter
 , BYVAL DueTime AS DWORD _                             ' __in  DWORD DueTime
 , BYVAL Period AS DWORD _                              ' __in  DWORD Period
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChangeTimerQueueTimer IMPORT "KERNEL32.DLL" ALIAS "ChangeTimerQueueTimer" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 , BYVAL Timer AS DWORD _                               ' __in HANDLE Timer
 , BYVAL DueTime AS DWORD _                             ' __in ULONG DueTime
 , BYVAL Period AS DWORD _                              ' __in ULONG Period
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteTimerQueueTimer IMPORT "KERNEL32.DLL" ALIAS "DeleteTimerQueueTimer" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 , BYVAL Timer AS DWORD _                               ' __in HANDLE Timer
 , BYVAL CompletionEvent AS DWORD _                     ' __in HANDLE CompletionEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteTimerQueueEx IMPORT "KERNEL32.DLL" ALIAS "DeleteTimerQueueEx" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 , BYVAL CompletionEvent AS DWORD _                     ' __in HANDLE CompletionEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetTimerQueueTimer IMPORT "KERNEL32.DLL" ALIAS "SetTimerQueueTimer" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 , BYVAL Callback AS DWORD _                            ' __in WAITORTIMERCALLBACK Callback
 , BYVAL Parameter AS DWORD _                           ' __in PVOID Parameter
 , BYVAL DueTime AS DWORD _                             ' __in DWORD DueTime
 , BYVAL Period AS DWORD _                              ' __in DWORD Period
 , BYVAL PreferIo AS LONG _                             ' __in BOOL PreferIo
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CancelTimerQueueTimer IMPORT "KERNEL32.DLL" ALIAS "CancelTimerQueueTimer" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 , BYVAL Timer AS DWORD _                               ' __in HANDLE Timer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteTimerQueue IMPORT "KERNEL32.DLL" ALIAS "DeleteTimerQueue" ( _
   BYVAL TimerQueue AS DWORD _                          ' __in HANDLE TimerQueue
 ) AS LONG                                              ' BOOL

'#endif // _WIN32_WINNT

'#if (_WIN32_WINNT >= 0x0600)

'typedef VOID (WINAPI *PTP_WIN32_IO_CALLBACK)(
'    __inout PTP_CALLBACK_INSTANCE Instance,
'    __inout PVOID                 Context,
'    __inout PVOID                 Overlapped,
'    __in     ULONG                 IoResult,
'    __in     ULONG_PTR             NumberOfBytesTransferred,
'    __inout PTP_IO                Io
'    );

DECLARE FUNCTION CreateThreadpool IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpool" ( _
   BYVAL reserved AS DWORD _                            ' __in PVOID reserved
 ) AS DWORD                                             ' PTP_POOL

DECLARE SUB SetThreadpoolThreadMaximum IMPORT "KERNEL32.DLL" ALIAS "SetThreadpoolThreadMaximum" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_POOL ptpp
 , BYVAL cthrdMost AS DWORD _                           ' __in DWORD cthrdMost
 )                                                      ' void

DECLARE FUNCTION SetThreadpoolThreadMinimum IMPORT "KERNEL32.DLL" ALIAS "SetThreadpoolThreadMinimum" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_POOL ptpp
 , BYVAL cthrdMic AS DWORD _                            ' __in DWORD cthrdMic
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadpoolStackInformation IMPORT "KERNEL32.DLL" ALIAS "SetThreadpoolStackInformation" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_POOL ptpp
 , BYREF ptpsi AS TP_POOL_STACK_INFORMATION _           ' __in PTP_POOL_STACK_INFORMATION ptpsi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryThreadpoolStackInformation IMPORT "KERNEL32.DLL" ALIAS "QueryThreadpoolStackInformation" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_POOL ptpp
 , BYREF ptpsi AS TP_POOL_STACK_INFORMATION _           ' __out PTP_POOL_STACK_INFORMATION ptpsi
 ) AS LONG                                              ' BOOL

DECLARE SUB CloseThreadpool IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpool" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_POOL ptpp
 )                                                      ' void

DECLARE FUNCTION CreateThreadpoolCleanupGroup IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpoolCleanupGroup" ( _
 ) AS DWORD                                             ' PTP_CLEANUP_GROUP


DECLARE SUB CloseThreadpoolCleanupGroupMembers IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolCleanupGroupMembers" ( _
   BYVAL ptpp AS DWORD _                                ' __in PTP_CLEANUP_GROUP ptpcg
 , BYVAL fCancelPendingCallbacks AS LONG _              ' __BOOL fCancelPendingCallbacks
 , BYVAL pvCleanupContext AS DWORD _                    ' __PVOID pvCleanupContext
 )                                                      ' void

DECLARE SUB CloseThreadpoolCleanupGroup IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolCleanupGroup" ( _
   BYVAL ptpcg AS DWORD _                               ' __in PTP_CLEANUP_GROUP ptpcg
 )                                                      ' void

'FORCEINLINE
'VOID
'InitializeThreadpoolEnvironment(
'    __out PTP_CALLBACK_ENVIRON pcbe
'    )
'{
'    TpInitializeCallbackEnviron(pcbe);
'}

MACRO InitializeThreadpoolEnvironment (pcbe)
   TpInitializeCallbackEnviron(pcbe)
END MACRO

'FORCEINLINE
'VOID
'SetThreadpoolCallbackPool(
'    __inout PTP_CALLBACK_ENVIRON pcbe,
'    __in    PTP_POOL             ptpp
'    )
'{
'    TpSetCallbackThreadpool(pcbe, ptpp);
'}

MACRO SetThreadpoolCallbackPool (pcbe, ptpp)
   TpSetCallbackThreadpool(pcbe, ptpp)
END MACRO

'FORCEINLINE
'VOID
'SetThreadpoolCallbackCleanupGroup(
'    __inout  PTP_CALLBACK_ENVIRON              pcbe,
'    __in     PTP_CLEANUP_GROUP                 ptpcg,
'    __in PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng
'    )
'{
'    TpSetCallbackCleanupGroup(pcbe, ptpcg, pfng);
'}

MACRO SetThreadpoolCallbackCleanupGroup (pcbe, ptpcg, pfng)
   TpSetCallbackCleanupGroup(pcbe, ptpcg, pfng)
END MACRO

'FORCEINLINE
'VOID
'SetThreadpoolCallbackRunsLong(
'    __inout PTP_CALLBACK_ENVIRON pcbe
'    )
'{
'    TpSetCallbackLongFunction(pcbe);
'}

MACRO SetThreadpoolCallbackRunsLong (pcbe)
   TpSetCallbackLongFunction(pcbe)
END MACRO

'FORCEINLINE
'VOID
'SetThreadpoolCallbackLibrary(
'    __inout PTP_CALLBACK_ENVIRON pcbe,
'    __in    PVOID                mod
'    )
'{
'    TpSetCallbackRaceWithDll(pcbe, mod);
'}

MACRO SetThreadpoolCallbackLibrary (pcbe, xmod)
   TpSetCallbackRaceWithDll(pcbe, xmod)
END MACRO

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0601

'FORCEINLINE
'VOID
'SetThreadpoolCallbackPriority(
'    __inout PTP_CALLBACK_ENVIRON pcbe,
'    __in    TP_CALLBACK_PRIORITY Priority
'    )
'{
'    TpSetCallbackPriority(pcbe, Priority);
'}

MACRO SetThreadpoolCallbackPriority (pcbe, nPriority)
   TpSetCallbackPriority(pcbe, nPriority)
END MACRO
#ENDIF

'FORCEINLINE
'VOID
'SetThreadpoolCallbackPersistent(
'    __inout PTP_CALLBACK_ENVIRON pcbe
'    )
'{
'    TpSetCallbackPersistent(pcbe);
'}

MACRO SetThreadpoolCallbackPersistent (pcbe)
   TpSetCallbackPersistent(pcbe)
END MACRO

'FORCEINLINE
'VOID
'DestroyThreadpoolEnvironment(
'    __inout PTP_CALLBACK_ENVIRON pcbe
'    )
'{
'    TpDestroyCallbackEnviron(pcbe);
'}

MACRO DestroyThreadpoolEnvironment (pcbe)
   TpDestroyCallbackEnviron(pcbe)
END MACRO

DECLARE SUB SetEventWhenCallbackReturns IMPORT "KERNEL32.DLL" ALIAS "SetEventWhenCallbackReturns" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 , BYVAL evt AS DWORD _                                 ' __in HANDLE evt
 )                                                      ' void

DECLARE SUB ReleaseSemaphoreWhenCallbackReturns IMPORT "KERNEL32.DLL" ALIAS "ReleaseSemaphoreWhenCallbackReturns" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 , BYVAL sem AS DWORD _                                 ' __in HANDLE sem
 , BYVAL crel AS DWORD _                                ' __in DWORD crel
 )                                                      ' void

DECLARE SUB ReleaseMutexWhenCallbackReturns IMPORT "KERNEL32.DLL" ALIAS "ReleaseMutexWhenCallbackReturns" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 , BYVAL mut AS DWORD _                                 ' __in HANDLE mut
 )                                                      ' void

DECLARE SUB LeaveCriticalSectionWhenCallbackReturns IMPORT "KERNEL32.DLL" ALIAS "LeaveCriticalSectionWhenCallbackReturns" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 , BYREF pcs AS CRITICAL_SECTION _                      ' __inout PCRITICAL_SECTION pcs
 )                                                      ' void

DECLARE SUB FreeLibraryWhenCallbackReturns IMPORT "KERNEL32.DLL" ALIAS "FreeLibraryWhenCallbackReturns" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 , BYVAL mod AS DWORD _                                 ' __in HMODULE mod
 )                                                      ' void

DECLARE FUNCTION CallbackMayRunLong IMPORT "KERNEL32.DLL" ALIAS "CallbackMayRunLong" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 ) AS LONG                                              ' BOOL

DECLARE SUB DisassociateCurrentThreadFromCallback IMPORT "KERNEL32.DLL" ALIAS "DisassociateCurrentThreadFromCallback" ( _
   BYVAL pci AS DWORD _                                 ' __in PTP_CALLBACK_INSTANCE pci
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TrySubmitThreadpoolCallback LIB "Kernel32.dll" _
    ALIAS "TrySubmitThreadpoolCallback" (BYVAL pfns AS DWORD, _
    BYVAL pv AS DWORD, BYVAL pcbe AS DWORD) AS LONG
#ELSE
DECLARE SUB TrySubmitThreadpoolCallback IMPORT "KERNEL32.DLL" ALIAS "TrySubmitThreadpoolCallback" ( _
   BYVAL pfns AS DWORD _                                ' __in PTP_SIMPLE_CALLBACK pfns
 , BYREF pv AS ANY _                                    ' __inout_opt PVOID pv
 , BYREF pcbe AS TP_CALLBACK_ENVIRON _                  ' __in PTP_CALLBACK_ENVIRON pcbe
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateThreadpoolWork LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolWork" (BYVAL pfnwk AS DWORD, BYVAL pv AS DWORD, _
    BYVAL pcbe AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateThreadpoolWork IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpoolWork" ( _
   BYVAL pfnwk AS DWORD _                               ' __in PTP_WORK_CALLBACK pfnwk
 , BYREF pv AS ANY _                                    ' __inout PVOID pv
 , BYREF pcbe AS TP_CALLBACK_ENVIRON _                  ' __in PTP_CALLBACK_ENVIRON pcbe
 ) AS DWORD                                             ' PTP_WORK
#ENDIF

DECLARE SUB SubmitThreadpoolWork IMPORT "KERNEL32.DLL" ALIAS "SubmitThreadpoolWork" ( _
   BYVAL pwk AS DWORD _                                 ' __in PTP_WORK pwk
 )                                                      ' void

DECLARE SUB WaitForThreadpoolWorkCallbacks IMPORT "KERNEL32.DLL" ALIAS "WaitForThreadpoolWorkCallbacks" ( _
   BYVAL pwk AS DWORD _                                 ' __in PTP_WORK pwk
 , BYVAL fCancelPendingCallbacks AS LONG _              ' __in BOOL fCancelPendingCallbacks
 )                                                      ' void

DECLARE SUB CloseThreadpoolWork IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolWork" ( _
   BYVAL pwk AS DWORD _                                 ' __in PTP_WORK pwk
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateThreadpoolTimer LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolTimer" (BYVAL pfnit AS DWORD, _
    BYVAL pv AS DWORD, BYVAL pcbe AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateThreadpoolTimer IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpoolTimer" ( _
   BYVAL pfnti AS DWORD _                               ' __in PTP_TIMER_CALLBACK pfnti
 , BYREF pv AS ANY _                                    ' __inout PVOID pv
 , BYREF pcbe AS TP_CALLBACK_ENVIRON _                  ' __in PTP_CALLBACK_ENVIRON pcbe
 ) AS DWORD                                             ' PTP_TIMER
#ENDIF

DECLARE SUB SetThreadpoolTimer IMPORT "KERNEL32.DLL" ALIAS "SetThreadpoolTimer" ( _
   BYVAL pti AS DWORD _                                 ' __in PTP_TIMER pti
 , BYREF pftDueTime AS FILETIME _                       ' __in PFILETIME pftDueTime
 , BYVAL msPeriod AS DWORD _                            ' __in DWORD msPeriod
 , BYVAL msWindowLength AS DWORD _                      ' __in DWORD msWindowLength
 )                                                      ' void

DECLARE FUNCTION IsThreadpoolTimerSet IMPORT "KERNEL32.DLL" ALIAS "IsThreadpoolTimerSet" ( _
   BYVAL pti AS DWORD _                                 ' __in PTP_TIMER pti
 ) AS LONG                                              ' BOOL

DECLARE SUB WaitForThreadpoolTimerCallbacks IMPORT "KERNEL32.DLL" ALIAS "WaitForThreadpoolTimerCallbacks" ( _
   BYVAL pti AS DWORD _                                 ' __in PTP_TIMER pti
 , BYVAL fCancelPendingCallbacks AS LONG _              ' __in BOOL fCancelPendingCallbacks
 )                                                      ' void

DECLARE SUB CloseThreadpoolTimer IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolTimer" ( _
   BYVAL pti AS DWORD _                                 ' __in PTP_TIMER pti
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateThreadpoolWait LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolWait" (BYVAL pfnwa AS DWORD, BYVAL pv AS DWORD, _
    BYVAL pcbe AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreateThreadpoolWait IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpoolWait" ( _
   BYVAL pfnwa AS DWORD _                               ' __in PTP_WAIT_CALLBACK pfnwa
 , BYREF pv AS ANY _                                    ' __inout PVOID pv
 , BYREF pcbe AS TP_CALLBACK_ENVIRON _                  ' __in PTP_CALLBACK_ENVIRON pcbe
 ) AS DWORD                                             ' PTP_WAIT
#ENDIF

DECLARE SUB SetThreadpoolWait IMPORT "KERNEL32.DLL" ALIAS "SetThreadpoolWait" ( _
   BYVAL pwa AS DWORD _                                 ' __in PTP_WAIT pwa
 , BYVAL h AS DWORD _                                   ' __in HANDLE h
 , BYREF pftTimeout AS FILETIME _                       ' __in PFILETIME pftTimeout
 )                                                      ' void

DECLARE SUB WaitForThreadpoolWaitCallbacks IMPORT "KERNEL32.DLL" ALIAS "WaitForThreadpoolWaitCallbacks" ( _
   BYVAL pwa AS DWORD _                                 ' __in PTP_WAIT pwa
 , BYVAL fCancelPendingCallbacks AS LONG _              ' __in BOOL fCancelPendingCallbacks
 )                                                      ' void

DECLARE SUB CloseThreadpoolWait IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolWait" ( _
   BYVAL pwa AS DWORD _                                 ' __in PTP_WAIT  pwa
 )                                                      ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateThreadpoolIo LIB "Kernel32.dll" _
    ALIAS "CreateThreadpoolIo" (BYVAL fl AS DWORD, BYVAL pfnio AS DWORD, _
    BYVAL pv AS DWORD, pbce AS TP_CALLBACK_ENVIRON) AS DWORD
#ELSE
DECLARE FUNCTION CreateThreadpoolIo IMPORT "KERNEL32.DLL" ALIAS "CreateThreadpoolIo" ( _
   BYVAL fl AS DWORD _                                  ' __in HANDLE fl
 , BYVAL pfnio AS DWORD _                               ' __in PTP_WIN32_IO_CALLBACK pfnio
 , BYREF pv AS ANY _                                    ' __inout PVOID pv
 , BYREF pcbe AS TP_CALLBACK_ENVIRON _                  ' __in PTP_CALLBACK_ENVIRON pcbe
 ) AS DWORD                                             ' PTP_IO
#ENDIF

DECLARE SUB StartThreadpoolIo IMPORT "KERNEL32.DLL" ALIAS "StartThreadpoolIo" ( _
   BYVAL pio AS DWORD _                                 ' __in PTP_IO pio
 )                                                      ' void

DECLARE SUB CancelThreadpoolIo IMPORT "KERNEL32.DLL" ALIAS "CancelThreadpoolIo" ( _
   BYVAL pio AS DWORD _                                 ' __in PTP_IO pio
 )                                                      ' void

DECLARE SUB WaitForThreadpoolIoCallbacks IMPORT "KERNEL32.DLL" ALIAS "WaitForThreadpoolIoCallbacks" ( _
   BYVAL pio AS DWORD _                                 ' __in PTP_IO pio
 , BYVAL fCancelPendingCallbacks AS LONG _              ' __in BOOL fCancelPendingCallbacks
 )                                                      ' void

DECLARE SUB CloseThreadpoolIo IMPORT "KERNEL32.DLL" ALIAS "CloseThreadpoolIo" ( _
   BYVAL pio AS DWORD _                                 ' __in PTP_IO pio
 )                                                      ' void

'//
'//  Private Namespaces support
'//

DECLARE FUNCTION CreatePrivateNamespaceA IMPORT "KERNEL32.DLL" ALIAS "CreatePrivateNamespaceA" ( _
   BYREF lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes
 , BYVAL lpBoundaryDescriptor AS DWORD _                ' __in LPVOID lpBoundaryDescriptor
 , BYREF lpAliasPrefix AS ASCIIZ _                      ' __in LPCSTR lpAliasPrefix
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreatePrivateNamespaceW IMPORT "KERNEL32.DLL" ALIAS "CreatePrivateNamespaceW" ( _
   BYREF lpPrivateNamespaceAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes
 , BYVAL lpBoundaryDescriptor AS DWORD _                ' __in LPVOID lpBoundaryDescriptor
 , BYREF lpAliasPrefix AS WSTRINGZ _                    ' __in LPCWSTR lpAliasPrefix
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreatePrivateNamespace = CreatePrivateNamespaceW
#ELSE
   MACRO CreatePrivateNamespace = CreatePrivateNamespaceA
#ENDIF

DECLARE FUNCTION OpenPrivateNamespaceA IMPORT "KERNEL32.DLL" ALIAS "OpenPrivateNamespaceA" ( _
   BYVAL lpBoundaryDescriptor AS DWORD _                ' __in LPVOID lpBoundaryDescriptor
 , BYREF lpAliasPrefix AS ASCIIZ _                      ' __in LPCSTR lpAliasPrefix
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenPrivateNamespaceW IMPORT "KERNEL32.DLL" ALIAS "OpenPrivateNamespaceW" ( _
   BYVAL lpBoundaryDescriptor AS DWORD _                ' __in LPVOID lpBoundaryDescriptor
 , BYREF lpAliasPrefix AS WSTRINGZ _                    ' __in LPCWSTR lpAliasPrefix
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenPrivateNamespace = OpenPrivateNamespaceW
#ELSE
   MACRO OpenPrivateNamespace = OpenPrivateNamespaceA
#ENDIF

%PRIVATE_NAMESPACE_FLAG_DESTROY      = &H00000001???

DECLARE FUNCTION ClosePrivateNamespace IMPORT "KERNEL32.DLL" ALIAS "ClosePrivateNamespace" ( _
   BYVAL Handle AS DWORD _                              ' __in HANDLE Handle
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS BYTE                                              ' BOOLEAN

'//
'//  Boundary descriptors support
'//

DECLARE FUNCTION CreateBoundaryDescriptorA IMPORT "KERNEL32.DLL" ALIAS "CreateBoundaryDescriptorA" ( _
   BYREF Name AS ASCIIZ _                               ' __in LPCSTR Name
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateBoundaryDescriptorW IMPORT "KERNEL32.DLL" ALIAS "CreateBoundaryDescriptorW" ( _
   BYREF Name AS WSTRINGZ _                             ' __in LPCWSTR Name
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateBoundaryDescriptor = CreateBoundaryDescriptorW
#ELSE
   MACRO CreateBoundaryDescriptor = CreateBoundaryDescriptorA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddSIDToBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "AddSIDToBoundaryDescriptor" (hBoundaryDescriptor AS DWORD, _
    RequiredSid AS SID) AS LONG
#ELSE
DECLARE FUNCTION AddSIDToBoundaryDescriptor IMPORT "KERNEL32.DLL" ALIAS "AddSIDToBoundaryDescriptor" ( _
   BYREF BoundaryDescriptor AS DWORD _                  ' __inout HANDLE * BoundaryDescriptor
 , BYVAL RequiredSid AS SID PTR _                       ' __in PSID RequiredSid
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddIntegrityLabelToBoundaryDescriptor LIB "Kernel32.dll" _
    ALIAS "AddIntegrityLabelToBoundaryDescriptor" ( _
    BoundaryDescriptor AS DWORD, _  ' HANDLE
    IntegrityLabel     AS SID) _
    AS LONG
#ELSE
DECLARE FUNCTION AddIntegrityLabelToBoundaryDescriptor IMPORT "KERNEL32.DLL" ALIAS "AddIntegrityLabelToBoundaryDescriptor" ( _
   BYREF BoundaryDescriptor AS DWORD _                  ' __inout HANDLE * BoundaryDescriptor
 , BYVAL IntegrityLabel AS SID PTR _                    ' __in PSID IntegrityLabel
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE SUB DeleteBoundaryDescriptor IMPORT "KERNEL32.DLL" ALIAS "DeleteBoundaryDescriptor" ( _
   BYVAL BoundaryDescriptor AS DWORD _                  ' __in HANDLE BoundaryDescriptor
 )                                                      ' void

'#endif // _WIN32_WINNT >= 0x0600

'#endif // _WIN32_WINNT >= 0x0500

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Plug-and-Play API's
'//

%HW_PROFILE_GUIDLEN = 39    ' 36-characters plus NULL terminator
%MAX_PROFILE_LEN    = 80

%DOCKINFO_UNDOCKED      = &H1???
%DOCKINFO_DOCKED        = &H2???
%DOCKINFO_USER_SUPPLIED = &H4???
%DOCKINFO_USER_UNDOCKED = %DOCKINFO_USER_SUPPLIED OR %DOCKINFO_UNDOCKED
%DOCKINFO_USER_DOCKED   = %DOCKINFO_USER_SUPPLIED OR %DOCKINFO_DOCKED

' // Size = 124 bytes
TYPE HW_PROFILE_INFOA DWORD
  dwDockInfo      AS DWORD                              ' DWORD  dwDockInfo
  szHwProfileGuid AS ASCIIZ * %HW_PROFILE_GUIDLEN       ' CHAR   szHwProfileGuid[HW_PROFILE_GUIDLEN]
  szHwProfileName AS ASCIIZ * %MAX_PROFILE_LEN          ' CHAR   szHwProfileName[MAX_PROFILE_LEN]
END TYPE

' // Size = 244 bytes
TYPE HW_PROFILE_INFOW DWORD
  dwDockInfo      AS DWORD                            ' DWORD  dwDockInfo
  szHwProfileGuid AS WSTRINGZ * %HW_PROFILE_GUIDLEN   ' WCHAR  szHwProfileGuid[HW_PROFILE_GUIDLEN]
  szHwProfileName AS WSTRINGZ * %MAX_PROFILE_LEN      ' WCHAR  szHwProfileName[MAX_PROFILE_LEN]
END TYPE

MACRO HW_PROFILE_INFO = HW_PROFILE_INFOA

DECLARE FUNCTION GetCurrentHwProfileA IMPORT "ADVAPI32.DLL" ALIAS "GetCurrentHwProfileA" ( _
   BYREF lpHwProfileInfo AS HW_PROFILE_INFOA _          ' __out LPHW_PROFILE_INFOA lpHwProfileInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCurrentHwProfileW IMPORT "ADVAPI32.DLL" ALIAS "GetCurrentHwProfileW" ( _
   BYREF lpHwProfileInfo AS HW_PROFILE_INFOW _          ' __out LPHW_PROFILE_INFOW lpHwProfileInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCurrentHwProfile = GetCurrentHwProfileW
#ELSE
   MACRO GetCurrentHwProfile = GetCurrentHwProfileA
#ENDIF

'//
'// Performance counter API's
'//

DECLARE FUNCTION QueryPerformanceCounter IMPORT "KERNEL32.DLL" ALIAS "QueryPerformanceCounter" ( _
   BYREF lpPerformanceCount AS QUAD _                   ' __out LARGE_INTEGER *lpPerformanceCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryPerformanceFrequency IMPORT "KERNEL32.DLL" ALIAS "QueryPerformanceFrequency" ( _
   BYREF lpFrequency AS QUAD _                          ' __out LARGE_INTEGER *lpFrequency
 ) AS LONG                                              ' BOOL

' Note: Parameter declared AS ANY because it may accept both an OSVERSIONINFOA
' or OSVERSIONINFOEXA structure.
DECLARE FUNCTION GetVersionExA IMPORT "KERNEL32.DLL" ALIAS "GetVersionExA" ( _
   BYREF lpVersionInformation AS ANY _                  ' __inout LPOSVERSIONINFOA lpVersionInformation
 ) AS LONG                                              ' BOOL

' Note: Parameter declared AS ANY because it may accept both an OSVERSIONINFOW
' or OSVERSIONINFOEXW structure.
DECLARE FUNCTION GetVersionExW IMPORT "KERNEL32.DLL" ALIAS "GetVersionExW" ( _
   BYREF lpVersionInformation AS ANY _                  ' __inout LPOSVERSIONINFOW lpVersionInformation
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetVersionEx = GetVersionExW
#ELSE
   MACRO GetVersionEx = GetVersionExA
#ENDIF

DECLARE FUNCTION VerifyVersionInfoA IMPORT "KERNEL32.DLL" ALIAS "VerifyVersionInfoA" ( _
   BYREF lpVersionInformation AS OSVERSIONINFOEXA _     ' __inout LPOSVERSIONINFOEXA lpVersionInformation
 , BYVAL dwTypeMask AS DWORD _                          ' __in DWORD dwTypeMask
 , BYVAL dwlConditionMask AS QUAD _                     ' __in DWORDLONG dwlConditionMask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VerifyVersionInfoW IMPORT "KERNEL32.DLL" ALIAS "VerifyVersionInfoW" ( _
   BYREF lpVersionInformation AS OSVERSIONINFOEXW _     ' __inout LPOSVERSIONINFOEXW lpVersionInformation
 , BYVAL dwTypeMask AS DWORD _                          ' __in DWORD dwTypeMask
 , BYVAL dwlConditionMask AS QUAD _                     ' __in DWORDLONG dwlConditionMask
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO VerifyVersionInfo = VerifyVersionInfoW
#ELSE
   MACRO VerifyVersionInfo = VerifyVersionInfoA
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION GetProductInfo IMPORT "KERNEL32.DLL" ALIAS "GetProductInfo" ( _
   BYVAL DWORD _                       ' __in  DWORD  dwOSMajorVersion
 , BYVAL DWORD _                       ' __in  DWORD  dwOSMinorVersion
 , BYVAL DWORD _                       ' __in  DWORD  dwSpMajorVersion
 , BYVAL DWORD _                       ' __in  DWORD  dwSpMinorVersion
 , BYREF DWORD _                       ' __out PDWORD pdwReturnedProductType
 ) AS LONG                                              ' BOOL

#ENDIF

'// DOS and OS/2 Compatible Error Code definitions returned by the Win32 Base
'// API functions.
'//

#INCLUDE ONCE "WINERROR.INC"

'/* Abnormal termination codes */

%TC_NORMAL  = 0
%TC_HARDERR = 1
%TC_GP_TRAP = 2
%TC_SIGNAL  = 3

'#if(WINVER >= 0x0400)
'//
'// Power Management APIs
'//

%AC_LINE_OFFLINE            = &H00?
%AC_LINE_ONLINE             = &H01?
%AC_LINE_BACKUP_POWER       = &H02?
%AC_LINE_UNKNOWN            = &HFF?

%BATTERY_FLAG_HIGH          = &H01?
%BATTERY_FLAG_LOW           = &H02?
%BATTERY_FLAG_CRITICAL      = &H04?
%BATTERY_FLAG_CHARGING      = &H08?
%BATTERY_FLAG_NO_BATTERY    = &H80?
%BATTERY_FLAG_UNKNOWN       = &HFF?

%BATTERY_PERCENTAGE_UNKNOWN = &HFF?

%BATTERY_LIFE_UNKNOWN       = &HFFFFFFFF???

' // Size = 12 bytes
TYPE SYSTEM_POWER_STATUS DWORD FILL
   ACLineStatus        AS BYTE    ' BYTE ACLineStatus
   BatteryFlag         AS BYTE    ' BYTE BatteryFlag
   BatteryLifePercent  AS BYTE    ' BYTE BatteryLifePercent
   Reserved1           AS BYTE    ' BYTE Reserved1
   BatteryLifeTime     AS DWORD   ' DWORD BatteryLifeTime
   BatteryFullLifeTime AS DWORD   ' DWORD BatteryFullLifeTime
END TYPE

DECLARE FUNCTION GetSystemPowerStatus IMPORT "KERNEL32.DLL" ALIAS "GetSystemPowerStatus" ( _
   BYREF lpSystemPowerStatus AS SYSTEM_POWER_STATUS _   ' __out LPSYSTEM_POWER_STATUS lpSystemPowerStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetSystemPowerState IMPORT "KERNEL32.DLL" ALIAS "SetSystemPowerState" ( _
   BYVAL fSuspend AS LONG _                             ' __in BOOL fSuspend
 , BYVAL fForce AS LONG _                               ' __in BOOL fForce
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0500)
'//
'// Very Large Memory API Subset
'//

DECLARE FUNCTION AllocateUserPhysicalPages IMPORT "KERNEL32.DLL" ALIAS "AllocateUserPhysicalPages" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF NumberOfPages AS DWORD _                       ' __inout PULONG_PTR NumberOfPages
 , BYREF PageArray AS DWORD _                           ' __out PULONG_PTR PageArray
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0600
#IF %WINVER >= &H0600

DECLARE FUNCTION AllocateUserPhysicalPagesNuma IMPORT "KERNEL32.DLL" ALIAS "AllocateUserPhysicalPagesNuma" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF NumberOfPages AS DWORD _                       ' __inout PULONG_PTR NumberOfPages
 , BYREF PageArray AS DWORD _                           ' __out PULONG_PTR PageArray
 , BYVAL nndPreferred AS DWORD _                        ' __in DWORD nndPreferred
 ) AS LONG                                              ' BOOL

#ENDIF ' // _WIN32_WINNT >= 0x0600

DECLARE FUNCTION FreeUserPhysicalPages IMPORT "KERNEL32.DLL" ALIAS "FreeUserPhysicalPages" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF NumberOfPages AS DWORD _                       ' __inout PULONG_PTR NumberOfPages
 , BYREF PageArray AS DWORD _                           ' __in PULONG_PTR PageArray
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MapUserPhysicalPages IMPORT "KERNEL32.DLL" ALIAS "MapUserPhysicalPages" ( _
   BYVAL VirtualAddress AS DWORD _                      ' __in PVOID VirtualAddress
 , BYVAL NumberOfPages AS DWORD _                       ' __in ULONG_PTR NumberOfPages
 , BYREF PageArray AS DWORD _                           ' __in PULONG_PTR PageArray
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MapUserPhysicalPagesScatter LIB "Kernel32.dll" _
    ALIAS "MapUserPhysicalPagesScatter" (BYVAL VirtualAddresses AS DWORD, _
    BYVAL NumberOfPages AS DWORD, PageArray AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MapUserPhysicalPagesScatter IMPORT "KERNEL32.DLL" ALIAS "MapUserPhysicalPagesScatter" ( _
   BYREF VirtualAddress AS DWORD _                      ' __in PVOID *VirtualAddresses
 , BYVAL NumberOfPages AS DWORD _                       ' __in ULONG_PTR NumberOfPages
 , BYREF PageArray AS DWORD _                           ' __in PULONG_PTR PageArray
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CreateJobObjectA IMPORT "KERNEL32.DLL" ALIAS "CreateJobObjectA" ( _
   BYREF lpJobAttributes AS SECURITY_ATTRIBUTES _       ' __in LPSECURITY_ATTRIBUTES lpJobAttributes
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateJobObjectW IMPORT "KERNEL32.DLL" ALIAS "CreateJobObjectW" ( _
   BYREF lpJobAttributes AS SECURITY_ATTRIBUTES _       ' __in LPSECURITY_ATTRIBUTES lpJobAttributes
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateJobObject = CreateJobObjectW
#ELSE
   MACRO CreateJobObject = CreateJobObjectA
#ENDIF

DECLARE FUNCTION OpenJobObjectA IMPORT "KERNEL32.DLL" ALIAS "OpenJobObjectA" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION OpenJobObjectW IMPORT "KERNEL32.DLL" ALIAS "OpenJobObjectW" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL bInheritHandle AS LONG _                       ' __in BOOL bInheritHandle
 , BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenJobObject = OpenJobObjectW
#ELSE
   MACRO OpenJobObject = OpenJobObjectA
#ENDIF

DECLARE FUNCTION AssignProcessToJobObject IMPORT "KERNEL32.DLL" ALIAS "AssignProcessToJobObject" ( _
   BYVAL hJob AS DWORD _                                ' __in HANDLE hJob
 , BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TerminateJobObject IMPORT "KERNEL32.DLL" ALIAS "TerminateJobObject" ( _
   BYVAL hJob AS DWORD _                                ' __in HANDLE hJob
 , BYVAL uExitCode AS DWORD _                           ' __in UINT uExitCode
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryInformationJobObject LIB "Kernel32.dll" _
    ALIAS "QueryInformationJobObject" (BYVAL hJob AS DWORD, _
    BYVAL JobObjectInformationClass AS LONG, _
    BYVAL lpJobObjectInformation AS DWORD, _
    BYVAL cbJobObjectInformationLength AS DWORD, lpReturnlength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION QueryInformationJobObject IMPORT "KERNEL32.DLL" ALIAS "QueryInformationJobObject" ( _
   BYVAL hJob AS DWORD _                                ' __in HANDLE hJob
 , BYVAL JobObjectInformationClass AS LONG _            ' __in JOBOBJECTINFOCLASS JobObjectInformationClass
 , BYREF lpJobObjectInformation AS ANY _                ' __out LPVOID lpJobObjectInformation
 , BYVAL cbJobObjectInformationLength AS DWORD _        ' __in DWORD cbJobObjectInformationLength
 , BYREF lpReturnLength AS DWORD _                      ' __out LPDWORD lpReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetInformationJobObject LIB "Kernel32.dll" _
    ALIAS "SetInformationJobObject" (BYVAL hJob AS DWORD, _
    BYVAL JobObjectInformationClass AS LONG, _
    BYVAL lpJobObjectInformation AS DWORD, _
    BYVAL cbJobObjectInformationLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetInformationJobObject IMPORT "KERNEL32.DLL" ALIAS "SetInformationJobObject" ( _
   BYVAL hJob AS DWORD _                                ' __in HANDLE hJob
 , BYVAL JobObjectInformationClass AS LONG _            ' __in JOBOBJECTINFOCLASS JobObjectInformationClass
 , BYREF lpJobObjectInformation AS ANY _                ' __in LPVOID lpJobObjectInformation
 , BYVAL cbJobObjectInformationLength AS DWORD _        ' __in DWORD cbJobObjectInformationLength
 ) AS LONG                                              ' BOOL
#ENDIF

'#if (_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION IsProcessInJob IMPORT "KERNEL32.DLL" ALIAS "IsProcessInJob" ( _
   BYVAL ProcessHandle AS DWORD _                       ' __in  HANDLE ProcessHandle
 , BYVAL JobHandle AS DWORD _                           ' __in  HANDLE JobHandle
 , BYREF Result AS LONG _                               ' __out PBOOL Result
 ) AS LONG                                              ' BOOL

'#endif

DECLARE FUNCTION CreateJobSet IMPORT "KERNEL32.DLL" ALIAS "CreateJobSet" ( _
   BYVAL NumJob AS DWORD _                              ' __in ULONG NumJob
 , BYREF UserJobSet AS JOB_SET_ARRAY _                  ' __in PJOB_SET_ARRAY UserJobSet
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddVectoredExceptionHandler IMPORT "KERNEL32.DLL" ALIAS "AddVectoredExceptionHandler" ( _
   BYVAL First AS DWORD _                               ' __in ULONG First
 , BYVAL Handler AS DWORD _                             ' __in PVECTORED_EXCEPTION_HANDLER Handler
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION RemoveVectoredExceptionHandler IMPORT "KERNEL32.DLL" ALIAS "RemoveVectoredExceptionHandler" ( _
   BYVAL Handle AS DWORD _                              ' __in PVOID Handle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION AddVectoredContinueHandler IMPORT "KERNEL32.DLL" ALIAS "AddVectoredContinueHandler" ( _
   BYVAL First AS DWORD _                               ' __in ULONG First
 , BYVAL Handler AS DWORD _                             ' __in PVECTORED_EXCEPTION_HANDLER Handler
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION RemoveVectoredContinueHandler IMPORT "KERNEL32.DLL" ALIAS "RemoveVectoredContinueHandler" ( _
   BYVAL Handle AS DWORD _                              ' __in PVOID Handle
 ) AS DWORD                                             ' ULONG

'//
'// New Volume Mount Point API.
'//

DECLARE FUNCTION FindFirstVolumeA IMPORT "KERNEL32.DLL" ALIAS "FindFirstVolumeA" ( _
   BYREF lpszVolumeName AS ASCIIZ _                     ' __out LPSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstVolumeW IMPORT "KERNEL32.DLL" ALIAS "FindFirstVolumeW" ( _
   BYREF lpszVolumeName AS WSTRINGZ _                   ' __out LPWSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstVolume = FindFirstVolumeW
#ELSE
   MACRO FindFirstVolume = FindFirstVolumeA
#ENDIF

DECLARE FUNCTION FindNextVolumeA IMPORT "KERNEL32.DLL" ALIAS "FindNextVolumeA" ( _
   BYVAL hFindVolume AS DWORD _                         ' __in HANDLE hFindVolume
 , BYREF lpszVolumeName AS ASCIIZ _                     ' __out LPSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextVolumeW IMPORT "KERNEL32.DLL" ALIAS "FindNextVolumeW" ( _
   BYVAL hFindVolume AS DWORD _                         ' __in HANDLE hFindVolume
 , BYREF lpszVolumeName AS WSTRINGZ _                   ' __out LPWSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextVolume = FindNextVolumeW
#ELSE
   MACRO FindNextVolume = FindNextVolumeA
#ENDIF

DECLARE FUNCTION FindVolumeClose IMPORT "KERNEL32.DLL" ALIAS "FindVolumeClose" ( _
   BYVAL hFindVolume AS DWORD _                         ' __in HANDLE hFindVolume
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindFirstVolumeMountPointA IMPORT "KERNEL32.DLL" ALIAS "FindFirstVolumeMountPointA" ( _
   BYREF lpszRootPathName AS ASCIIZ _                   ' __in LPCSTR lpszRootPathName
 , BYREF lpszVolumeMountPoint AS ASCIIZ _               ' __out LPSTR lpszVolumeMountPoint
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstVolumeMountPointW IMPORT "KERNEL32.DLL" ALIAS "FindFirstVolumeMountPointW" ( _
   BYREF lpszRootPathName AS WSTRINGZ _                 ' __in LPCWSTR lpszRootPathName
 , BYREF lpszVolumeMountPoint AS WSTRINGZ _             ' __out LPWSTR lpszVolumeMountPoint
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstVolumeMountPoint = FindFirstVolumeMountPointW
#ELSE
   MACRO FindFirstVolumeMountPoint = FindFirstVolumeMountPointA
#ENDIF

DECLARE FUNCTION FindNextVolumeMountPointA IMPORT "KERNEL32.DLL" ALIAS "FindNextVolumeMountPointA" ( _
   BYVAL hFindVolumeMountPoint AS DWORD _               ' __in HANDLE hFindVolumeMountPoint
 , BYREF lpszVolumeMountPoint AS ASCIIZ _               ' __out LPSTR lpszVolumeMountPoint
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextVolumeMountPointW IMPORT "KERNEL32.DLL" ALIAS "FindNextVolumeMountPointW" ( _
   BYVAL hFindVolumeMountPoint AS DWORD _               ' __in HANDLE hFindVolumeMountPoint
 , BYREF lpszVolumeMountPoint AS WSTRINGZ _             ' __out LPWSTR lpszVolumeMountPoint
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextVolumeMountPoint = FindNextVolumeMountPointW
#ELSE
   MACRO FindNextVolumeMountPoint = FindNextVolumeMountPointA
#ENDIF

DECLARE FUNCTION FindVolumeMountPointClose IMPORT "KERNEL32.DLL" ALIAS "FindVolumeMountPointClose" ( _
   BYVAL hFindVolumeMountPoint AS DWORD _               ' __in HANDLE hFindVolumeMountPoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetVolumeMountPointA IMPORT "KERNEL32.DLL" ALIAS "SetVolumeMountPointA" ( _
   BYREF lpszVolumeMountPoint AS ASCIIZ _               ' __in LPCSTR lpszVolumeMountPoint
 , BYREF lpszVolumeName AS ASCIIZ _                     ' __in LPCSTR lpszVolumeName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetVolumeMountPointW IMPORT "KERNEL32.DLL" ALIAS "SetVolumeMountPointW" ( _
   BYREF lpszVolumeMountPoint AS WSTRINGZ _             ' __in LPCWSTR lpszVolumeMountPoint
 , BYREF lpszVolumeName AS WSTRINGZ _                   ' __in LPCWSTR lpszVolumeName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetVolumeMountPoint = SetVolumeMountPointW
#ELSE
   MACRO SetVolumeMountPoint = SetVolumeMountPointA
#ENDIF

DECLARE FUNCTION DeleteVolumeMountPointA IMPORT "KERNEL32.DLL" ALIAS "DeleteVolumeMountPointA" ( _
   BYREF lpszVolumeMountPoint AS ASCIIZ _               ' __in LPCSTR lpszVolumeMountPoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteVolumeMountPointW IMPORT "KERNEL32.DLL" ALIAS "DeleteVolumeMountPointW" ( _
   BYREF lpszVolumeMountPoint AS WSTRINGZ _             ' __in LPCWSTR lpszVolumeMountPoint
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteVolumeMountPoint = DeleteVolumeMountPointW
#ELSE
   MACRO DeleteVolumeMountPoint = DeleteVolumeMountPointA
#ENDIF

DECLARE FUNCTION GetVolumeNameForVolumeMountPointA IMPORT "KERNEL32.DLL" ALIAS "GetVolumeNameForVolumeMountPointA" ( _
   BYREF lpszVolumeMountPoint AS ASCIIZ _               ' __in LPCSTR lpszVolumeMountPoint
 , BYREF lpszVolumeName AS ASCIIZ _                     ' __out LPSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetVolumeNameForVolumeMountPointW IMPORT "KERNEL32.DLL" ALIAS "GetVolumeNameForVolumeMountPointW" ( _
   BYREF lpszVolumeMountPoint AS WSTRINGZ _             ' __in LPCWSTR lpszVolumeMountPoint
 , BYREF lpszVolumeName AS WSTRINGZ _                   ' __out LPWSTR lpszVolumeName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetVolumeNameForVolumeMountPoint = GetVolumeNameForVolumeMountPointW
#ELSE
   MACRO GetVolumeNameForVolumeMountPoint = GetVolumeNameForVolumeMountPointA
#ENDIF

DECLARE FUNCTION GetVolumePathNameA IMPORT "KERNEL32.DLL" ALIAS "GetVolumePathNameA" ( _
   BYREF lpszFileName AS ASCIIZ _                       ' __in LPCSTR lpszFileName
 , BYREF lpszVolumePathName AS ASCIIZ _                 ' __out LPSTR lpszVolumePathName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetVolumePathNameW IMPORT "KERNEL32.DLL" ALIAS "GetVolumePathNameW" ( _
   BYREF lpszFileName AS WSTRINGZ _                     ' __in LPCWSTR lpszFileName
 , BYREF lpszVolumePathName AS WSTRINGZ _               ' __out LPWSTR lpszVolumePathName
 , BYVAL cchBufferLength AS DWORD _                     ' __in DWORD cchBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetVolumePathName = GetVolumePathNameW
#ELSE
   MACRO GetVolumePathName = GetVolumePathNameA
#ENDIF

'#endif

'#if(_WIN32_WINNT >= 0x0501)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetVolumePathNamesForVolumeNameA LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameA" (lpszVolumeName AS ASCIIZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumePathNamesForVolumeNameA IMPORT "KERNEL32.DLL" ALIAS "GetVolumePathNamesForVolumeNameA" ( _
   BYREF lpszVolumeName AS ASCIIZ _                     ' __in  LPCSTR lpszVolumeName
 , BYREF lpszVolumePathNames AS ANY _                   ' __out LPCH lpszVolumePathNames
 , BYVAL cchBufferLength AS DWORD _                     ' __in  DWORD cchBufferLength
 , BYREF lpcchReturnLength AS DWORD _                   ' __out PDWORD lpcchReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetVolumePathNamesForVolumeNameW LIB "Kernel32.dll" _
    ALIAS "GetVolumePathNamesForVolumeNameW" (lpszVolumeName AS WSTRINGZ, _
    BYVAL lpszVolumePathNames AS DWORD, BYVAL ccBufferLength AS DWORD, _
    lpcchReturnLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetVolumePathNamesForVolumeNameW IMPORT "KERNEL32.DLL" ALIAS "GetVolumePathNamesForVolumeNameW" ( _
   BYREF lpszVolumeName AS WSTRINGZ _                   ' __in  LPCWSTR lpszVolumeName
 , BYREF lpszVolumePathNames AS ANY _                   ' __out LPWCH lpszVolumePathNames
 , BYVAL cchBufferLength AS DWORD _                     ' __in  DWORD cchBufferLength
 , BYREF lpcchReturnLength AS DWORD _                   ' __out PDWORD lpcchReturnLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetVolumePathNamesForVolumeName = GetVolumePathNamesForVolumeNameW
#ELSE
   MACRO GetVolumePathNamesForVolumeName = GetVolumePathNamesForVolumeNameA
#ENDIF

'#endif // (_WIN32_WINNT >= 0x0501)

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

%ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID    = &H00000001???
%ACTCTX_FLAG_LANGID_VALID                    = &H00000002???
%ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID        = &H00000004???
%ACTCTX_FLAG_RESOURCE_NAME_VALID             = &H00000008???
%ACTCTX_FLAG_SET_PROCESS_DEFAULT             = &H00000010???
%ACTCTX_FLAG_APPLICATION_NAME_VALID          = &H00000020???
%ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF           = &H00000040???
%ACTCTX_FLAG_HMODULE_VALID                   = &H00000080???

' // Size = 32 bytes
TYPE ACTCTXA DWORD FILL
   cbSize                 AS DWORD        ' ULONG       cbSize
   dwFlags                AS DWORD        ' DWORD       dwFlags
   lpSource               AS ASCIIZ PTR   ' LPCSTR      lpSource
   wProcessorArchitecture AS WORD         ' USHORT      wProcessorArchitecture
   wLangId                AS WORD         ' LANGID      wLangId
   lpAssemblyDirectory    AS ASCIIZ PTR   ' LPCSTR      lpAssemblyDirectory
   lpResourceName         AS ASCIIZ PTR   ' LPCSTR      lpResourceName
   lpApplicationName      AS ASCIIZ PTR   ' LPCSTR      lpApplicationName
   hModule                AS DWORD        ' HMODULE     hModule
END TYPE

' // Size = 32 bytes
TYPE ACTCTXW DWORD FILL
   cbSize                 AS DWORD          ' ULONG       cbSize
   dwFlags                AS DWORD          ' DWORD       dwFlags
   lpSource               AS WSTRINGZ PTR   ' LPWCSTR     lpSource
   wProcessorArchitecture AS WORD           ' USHORT      wProcessorArchitecture
   wLangId                AS WORD           ' LANGID      wLangId
   lpAssemblyDirectory    AS WSTRINGZ PTR   ' LPCWSTR     lpAssemblyDirectory
   lpResourceName         AS WSTRINGZ PTR   ' LPCWSTR     lpResourceName
   lpApplicationName      AS WSTRINGZ PTR   ' LPCWSTR     lpApplicationName
   hModule                AS DWORD          ' HMODULE     hModule
END TYPE

MACRO ACTCTX = ACTCTXA

'#endif

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)


DECLARE FUNCTION CreateActCtxA IMPORT "KERNEL32.DLL" ALIAS "CreateActCtxA" ( _
   BYREF pActCtx AS ACTCTXA _                           ' __in PCACTCTXA pActCtx
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CreateActCtxW IMPORT "KERNEL32.DLL" ALIAS "CreateActCtxW" ( _
   BYREF pActCtx AS ACTCTXW _                           ' __in PCACTCTXW pActCtx
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateActCtx = CreateActCtxW
#ELSE
   MACRO CreateActCtx = CreateActCtxA
#ENDIF

DECLARE SUB AddRefActCtx IMPORT "KERNEL32.DLL" ALIAS "AddRefActCtx" ( _
   BYVAL hActCtx AS DWORD _                             ' __in HANDLE hActCtx
 )                                                      ' void

DECLARE SUB ReleaseActCtx IMPORT "KERNEL32.DLL" ALIAS "ReleaseActCtx" ( _
   BYVAL hActCtx AS DWORD _                             ' __in HANDLE hActCtx
 )                                                      ' void

DECLARE FUNCTION ZombifyActCtx IMPORT "KERNEL32.DLL" ALIAS "ZombifyActCtx" ( _
   BYVAL hActCtx AS DWORD _                             ' __in HANDLE hActCtx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ActivateActCtx IMPORT "KERNEL32.DLL" ALIAS "ActivateActCtx" ( _
   BYVAL hActCtx AS DWORD _                             ' __in HANDLE hActCtx
 , BYREF lpCookie AS DWORD _                            ' __out ULONG_PTR *lpCookie
 ) AS LONG                                              ' BOOL

%DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION = &H00000001???

DECLARE FUNCTION DeactivateActCtx IMPORT "KERNEL32.DLL" ALIAS "DeactivateActCtx" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL ulCookie AS DWORD _                            ' __in ULONG_PTR ulCookie
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCurrentActCtx IMPORT "KERNEL32.DLL" ALIAS "GetCurrentActCtx" ( _
   BYREF lphActCtx AS DWORD _                           ' __out HANDLE *lphActCtx
 ) AS LONG                                              ' BOOL

'#endif

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

' // Size = 40 bytes
TYPE ACTCTX_SECTION_KEYED_DATA_2600 DWORD
   cbSize                    AS DWORD   ' ULONG cbSize
   ulDataFormatVersion       AS DWORD   ' ULONG ulDataFormatVersion
   lpData                    AS DWORD   ' PVOID lpData
   ulLength                  AS DWORD   ' ULONG ulLength
   lpSectionGlobalData       AS DWORD   ' PVOID lpSectionGlobalData
   ulSectionGlobalDataLength AS DWORD   ' ULONG ulSectionGlobalDataLength
   lpSectionBase             AS DWORD   ' PVOID lpSectionBase
   ulSectionTotalLength      AS DWORD   ' ULONG ulSectionTotalLength
   hActCtx                   AS DWORD   ' HANDLE hActCtx
   ulAssemblyRosterIndex     AS DWORD   ' ULONG ulAssemblyRosterIndex
END TYPE

' // Size = 20 bytes
TYPE ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA DWORD
   lpInformation             AS DWORD   ' PVOID lpInformation
   lpSectionBase             AS DWORD   ' PVOID lpSectionBase
   ulSectionLength           AS DWORD   ' ULONG ulSectionLength
   lpSectionGlobalDataBase   AS DWORD   ' PVOID lpSectionGlobalDataBase
   ulSectionGlobalDataLength AS DWORD   ' ULONG ulSectionGlobalDataLength
END TYPE

' // Size = 64 bytes
TYPE ACTCTX_SECTION_KEYED_DATA DWORD
   cbSize                    AS DWORD   ' ULONG cbSize
   ulDataFormatVersion       AS DWORD   ' ULONG ulDataFormatVersion
   lpData                    AS DWORD   ' PVOID lpData
   ulLength                  AS DWORD   ' ULONG ulLength
   lpSectionGlobalData       AS DWORD   ' PVOID lpSectionGlobalData
   ulSectionGlobalDataLength AS DWORD   ' ULONG ulSectionGlobalDataLength
   lpSectionBase             AS DWORD   ' PVOID lpSectionBase
   ulSectionTotalLength      AS DWORD   ' ULONG ulSectionTotalLength
   hActCtx                   AS DWORD   ' HANDLE hActCtx
   ulAssemblyRosterIndex     AS DWORD   ' ULONG ulAssemblyRosterIndex
   '// 2600 stops here
   ulFlags                   AS DWORD   ' ULONG ulFlags
   AssemblyMetadata          AS ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA   ' ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata
END TYPE

%FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX           = &H00000001???
%FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS             = &H00000002???
%FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA = &H00000004???

'#endif

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)

DECLARE FUNCTION FindActCtxSectionStringA IMPORT "KERNEL32.DLL" ALIAS "FindActCtxSectionStringA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lpExtensionGuid AS GUID _                      ' __in  const GUID *lpExtensionGuid
 , BYVAL ulSectionId AS DWORD _                         ' __in  ULONG ulSectionId
 , BYREF lpStringToFind AS ASCIIZ _                     ' __in  LPCSTR lpStringToFind
 , BYREF ReturnedData AS ACTCTX_SECTION_KEYED_DATA _    ' __out PACTCTX_SECTION_KEYED_DATA ReturnedData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindActCtxSectionStringW IMPORT "KERNEL32.DLL" ALIAS "FindActCtxSectionStringW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lpExtensionGuid AS GUID _                      ' __in  const GUID *lpExtensionGuid
 , BYVAL ulSectionId AS DWORD _                         ' __in  ULONG ulSectionId
 , BYREF lpStringToFind AS WSTRINGZ _                   ' __in  LPCWSTR lpStringToFind
 , BYREF ReturnedData AS ACTCTX_SECTION_KEYED_DATA _    ' __out PACTCTX_SECTION_KEYED_DATA ReturnedData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindActCtxSectionString = FindActCtxSectionStringW
#ELSE
   MACRO FindActCtxSectionString = FindActCtxSectionStringA
#ENDIF

DECLARE FUNCTION FindActCtxSectionGuid IMPORT "KERNEL32.DLL" ALIAS "FindActCtxSectionGuid" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lpExtensionGuid AS GUID _                      ' __in  const GUID *lpExtensionGuid
 , BYVAL ulSectionId AS DWORD  _                        ' __in  ULONG ulSectionId
 , BYREF lpGuidToFind AS GUID  _                        ' __in  const GUID *lpGuidToFind
 , BYREF ReturnedData AS ACTCTX_SECTION_KEYED_DATA _    ' __out PACTCTX_SECTION_KEYED_DATA ReturnedData
 ) AS LONG                                              ' BOOL

'#endif

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

'#if !defined(RC_INVOKED) /* RC complains about long symbols in #ifs */
'#if !defined(ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)

' // Size = 8 bytes
TYPE ACTIVATION_CONTEXT_BASIC_INFORMATION DWORD
   hActCtx AS DWORD   ' HANDLE  hActCtx
   dwFlags AS DWORD   ' DWORD   dwFlags
END TYPE

%ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED = 1

'#endif // !defined(ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)
'#endif

%QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX = &H00000004???
%QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE = &H00000008???
%QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS = &H00000010???
%QUERY_ACTCTX_FLAG_NO_ADDREF         = &H80000000???

'#endif

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)


'//
'// switch (ulInfoClass)
'//
'//  case ActivationContextBasicInformation:
'//    pvSubInstance == NULL
'//    pvBuffer is of type PACTIVATION_CONTEXT_BASIC_INFORMATION
'//
'//  case ActivationContextDetailedInformation:
'//    pvSubInstance == NULL
'//    pvBuffer is of type PACTIVATION_CONTEXT_DETAILED_INFORMATION
'//
'//  case AssemblyDetailedInformationInActivationContext:
'//    pvSubInstance is of type PULONG
'//      *pvSubInstance < ACTIVATION_CONTEXT_DETAILED_INFORMATION::ulAssemblyCount
'//    pvBuffer is of type PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION
'//
'//  case FileInformationInAssemblyOfAssemblyInActivationContext:
'//    pvSubInstance is of type PACTIVATION_CONTEXT_QUERY_INDEX
'//      pvSubInstance->ulAssemblyIndex < ACTIVATION_CONTEXT_DETAILED_INFORMATION::ulAssemblyCount
'//      pvSubInstance->ulFileIndexInAssembly < ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION::ulFileCount
'//    pvBuffer is of type PASSEMBLY_FILE_DETAILED_INFORMATION
'//
'// String are placed after the structs.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryActCtxW LIB "Kernel32.dll" ALIAS "QueryActCtxW" _
    (BYVAL dwFlags AS DWORD, BYVAL hActCtx AS DWORD, _
    BYVAL pvSubInstance AS DWORD, BYVAL ulInfoClass AS DWORD, _
    BYVAL pvBuffer AS DWORD, BYVAL cbBuffer AS DWORD, _
    pcbWrittenOrRequired AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION QueryActCtxW IMPORT "KERNEL32.DLL" ALIAS "QueryActCtxW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYVAL hActCtx AS DWORD _                             ' __in  HANDLE hActCtx
 , BYVAL pvSubInstance AS DWORD _                       ' __in  PVOID pvSubInstance
 , BYVAL ulInfoClass AS DWORD _                         ' __in  ULONG ulInfoClass
 , BYREF pvBuffer AS ANY _                              ' __out PVOID pvBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in  SIZE_T cbBuffer
 , BYREF pcbWrittenOrRequired AS DWORD _                ' __out SIZE_T *pcbWrittenOrRequired
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO QueryActCtx = QueryActCtxW

'#endif // (_WIN32_WINNT > 0x0500) || (_WIN32_FUSION >= 0x0100)

DECLARE FUNCTION ProcessIdToSessionId IMPORT "KERNEL32.DLL" ALIAS "ProcessIdToSessionId" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in  DWORD dwProcessId
 , BYREF pSessionId AS DWORD _                          ' __out DWORD *pSessionId
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0501

DECLARE FUNCTION WTSGetActiveConsoleSessionId IMPORT "KERNEL32.DLL" ALIAS "WTSGetActiveConsoleSessionId" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION IsWow64Process IMPORT "KERNEL32.DLL" ALIAS "IsWow64Process" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF Wow64Process AS LONG _                         ' __out PBOOL Wow64Process
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION GetLogicalProcessorInformation IMPORT "KERNEL32.DLL" ALIAS "GetLogicalProcessorInformation" ( _
   BYREF Buffer AS SYSTEM_LOGICAL_PROCESSOR_INFORMATION _ ' __out PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer
 , BYREF ReturnedLength AS DWORD _                      ' __inout PDWORD ReturnedLength
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetLogicalProcessorInformationEx IMPORT "KERNEL32.DLL" ALIAS "GetLogicalProcessorInformationEx" ( _
   BYVAL RelationshipType AS LONG _                     ' __in LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType
 , BYREF Buffer AS SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX _  ' __out_bcount_part_opt(*ReturnedLength, *ReturnedLength) PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer
 , BYREF ReturnedLength AS DWORD _                      ' __inout PDWORD ReturnedLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetActiveProcessorGroupCount IMPORT "KERNEL32.DLL" ALIAS "GetActiveProcessorGroupCount" ( _
 ) AS WORD                                              ' WORD

DECLARE FUNCTION GetMaximumProcessorGroupCount IMPORT "KERNEL32.DLL" ALIAS "GetMaximumProcessorGroupCount" ( _
 ) AS WORD                                              ' WORD

DECLARE FUNCTION GetActiveProcessorCount IMPORT "KERNEL32.DLL" ALIAS "GetActiveProcessorCount" ( _
   BYVAL GroupNumber AS WORD _                          ' __in WORD GroupNumber
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetMaximumProcessorCount IMPORT "KERNEL32.DLL" ALIAS "GetMaximumProcessorCount" ( _
   BYVAL GroupNumber AS WORD _                          ' __in WORD GroupNumber
 ) AS DWORD                                             ' DWORD

#ENDIF   ' // (_WIN32_WINNT >=0x0601)

'//
'// NUMA Information routines.
'//

DECLARE FUNCTION GetNumaHighestNodeNumber IMPORT "KERNEL32.DLL" ALIAS "GetNumaHighestNodeNumber" ( _
   BYREF HighestNodeNumber AS DWORD _                   ' __out PULONG HighestNodeNumber
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNumaProcessorNode IMPORT "KERNEL32.DLL" ALIAS "GetNumaProcessorNode" ( _
   BYVAL Processor AS BYTE _                            ' __in  UCHAR Processor
 , BYREF NodeNumber AS BYTE _                           ' __out PUCHAR NodeNumber
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetNumaNodeNumberFromHandle IMPORT "KERNEL32.DLL" ALIAS "GetNumaNodeNumberFromHandle" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF NodeNumber AS WORD _                           ' __out PUSHORT NodeNumber
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >=0x0601)

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetNumaProcessorNodeEx IMPORT "KERNEL32.DLL" ALIAS "GetNumaProcessorNodeEx" ( _
   BYREF Processor AS PROCESSOR_NUMBER _                ' __in  PPROCESSOR_NUMBER Processor
 , BYREF NodeNumber AS WORD _                           ' __out PUSHORT NodeNumber
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >=0x0601)

DECLARE FUNCTION GetNumaNodeProcessorMask IMPORT "KERNEL32.DLL" ALIAS "GetNumaNodeProcessorMask" ( _
   BYVAL Node AS BYTE _                                 ' __in  UCHAR Node
 , BYREF ProcessorMask AS QUAD _                        ' __out PULONGLONG ProcessorMask
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetNumaNodeProcessorMaskEx IMPORT "KERNEL32.DLL" ALIAS "GetNumaNodeProcessorMaskEx" ( _
   BYVAL Node AS WORD _                                 ' __in  USHORT Node
 , BYREF ProcessorMask AS GROUP_AFFINITY _              ' __out PGROUP_AFFINITY ProcessorMask
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >=0x0601)


DECLARE FUNCTION GetNumaAvailableMemoryNode IMPORT "KERNEL32.DLL" ALIAS "GetNumaAvailableMemoryNode" ( _
   BYVAL Node AS BYTE _                                 ' __in  UCHAR Node
 , BYREF AvailableBytes AS QUAD _                       ' __out PULONGLONG AvailableBytes
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetNumaAvailableMemoryNodeEx IMPORT "KERNEL32.DLL" ALIAS "GetNumaAvailableMemoryNodeEx" ( _
   BYVAL Node AS WORD _                                 ' __in  USHORT Node
 , BYREF AvailableBytes AS QUAD _                       ' __out PULONGLONG AvailableBytes
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >=0x0601)

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION GetNumaProximityNode IMPORT "KERNEL32.DLL" ALIAS "GetNumaProximityNode" ( _
   BYVAL ProximityId AS DWORD _                         ' __in  ULONG ProximityId
 , BYREF NodeNumber AS BYTE _                           ' __out PUCHAR NodeNumber
 ) AS LONG                                              ' BOOL

#ENDIF

'#if _WIN32_WINNT >= 0x0601
#IF %WINVER >= &H0601

DECLARE FUNCTION GetNumaProximityNodeEx IMPORT "KERNEL32.DLL" ALIAS "GetNumaProximityNodeEx" ( _
   BYVAL ProximityId AS DWORD _                         ' __in  ULONG ProximityId
 , BYREF NodeNumber AS WORD _                           ' __out PUSHORT NodeNumber
 ) AS LONG                                              ' BOOL

#ENDIF   ' // (_WIN32_WINNT >=0x0601)

'//
'// Application restart and data recovery callback
'//
'typedef DWORD (WINAPI *APPLICATION_RECOVERY_CALLBACK)(PVOID pvParameter);

'//
'// Max length of commandline in characters (including the NULL character that can be registered for restart)
'//
%RESTART_MAX_CMD_LINE   = 1024

'//
'// Do not restart the process for termination due to application crashes
'//
%RESTART_NO_CRASH       = 1

'//
'// Do not restart the process for termination due to application hangs
'//
%RESTART_NO_HANG        = 2

'//
'// Do not restart the process for termination due to patch installations
'//
%RESTART_NO_PATCH       = 4

'//
'// Do not restart the process when the system is rebooted due to patch installations
'//
%RESTART_NO_REBOOT      = 8

DECLARE FUNCTION RegisterApplicationRecoveryCallback IMPORT "KERNEL32.DLL" ALIAS "RegisterApplicationRecoveryCallback" ( _
   BYVAL pRecoveyCallback AS DWORD _                    ' __in APPLICATION_RECOVERY_CALLBACK pRecoveyCallback
 , BYVAL pvParameter AS DWORD _                         ' __in PVOID pvParameter
 , BYVAL dwPingInterval AS DWORD _                      ' __in DWORD dwPingInterval
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UnregisterApplicationRecoveryCallback IMPORT "KERNEL32.DLL" ALIAS "UnregisterApplicationRecoveryCallback" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegisterApplicationRestart IMPORT "KERNEL32.DLL" ALIAS "RegisterApplicationRestart" ( _
   BYREF pwzCommandline AS WSTRINGZ _                   ' __in PCWSTR pwzCommandline
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UnregisterApplicationRestart IMPORT "KERNEL32.DLL" ALIAS "UnregisterApplicationRestart" ( _
 ) AS LONG                                              ' HRESULT

%RECOVERY_DEFAULT_PING_INTERVAL = 5000
%RECOVERY_MAX_PING_INTERVAL     = (5 * 60 * 1000)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetApplicationRecoveryCallback LIB "Kernel32.dll" _
    ALIAS "GetApplicationRecoveryCallback" (BYVAL hProcess AS DWORD, _
    BYVAL pRecoveryCallback AS DWORD, BYVAL ppvParameter AS DWORD, _
    pdwPingInterval AS DWORD, pdwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetApplicationRecoveryCallback IMPORT "KERNEL32.DLL" ALIAS "GetApplicationRecoveryCallback" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF pRecoveryCallback AS DWORD _                   ' __out APPLICATION_RECOVERY_CALLBACK* pRecoveryCallback
 , BYREF ppvParameter AS ANY _                          ' __out PVOID* ppvParameter
 , BYREF pdwPingInterval AS DWORD _                     ' __out PDWORD pdwPingInterval
 , BYREF pdwFlags AS DWORD _                            ' __out PDWORD pdwFlags
 ) AS LONG                                              ' HRESULT
#ENDIF

DECLARE FUNCTION GetApplicationRestartSettings IMPORT "KERNEL32.DLL" ALIAS "GetApplicationRestartSettings" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF pwzCommandline AS WSTRINGZ _                   ' __out PWSTR pwzCommandline
 , BYREF pcchSize AS DWORD _                            ' __inout PDWORD pcchSize
 , BYREF pdwFlags AS DWORD _                            ' __out PDWORD pdwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ApplicationRecoveryInProgress IMPORT "KERNEL32.DLL" ALIAS "ApplicationRecoveryInProgress" ( _
   BYREF pbCancelled AS LONG _                          ' __out PBOOL pbCancelled
 ) AS LONG                                              ' HRESULT

DECLARE SUB ApplicationRecoveryFinished IMPORT "KERNEL32.DLL" ALIAS "ApplicationRecoveryFinished" ( _
   BYVAL bSuccess AS LONG _                             ' __in BOOL bSuccess
 )                                                      ' void

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

' enum FILE_INFO_BY_HANDLE_CLASS
%FileBasicInfo                  = 0
%FileStandardInfo               = 1
%FileNameInfo                   = 2
%FileRenameInfo                 = 3
%FileDispositionInfo            = 4
%FileAllocationInfo             = 5
%FileEndOfFileInfo              = 6
%FileStreamInfo                 = 7
%FileCompressionInfo            = 8
%FileAttributeTagInfo           = 9
%FileIdBothDirectoryInfo        = 10
%FileIdBothDirectoryRestartInfo = 11
%FileIoPriorityHintInfo         = 12
%FileRemoteProtocolInfo         = 13
%MaximumFileInfoByHandleClass   = 14

' // Size = 40 bytes
TYPE FILE_BASIC_INFO   ' Must be 8 byte aligned
   CreationTime   AS QUAD    ' LARGE_INTEGER
   LastAccessTime AS QUAD    ' LARGE_INTEGER
   LastWriteTime  AS QUAD    ' LARGE_INTEGER
   ChangeTime     AS QUAD    ' LARGE_INTEGER
   FileAttributes AS DWORD   ' DWORD
   alignment__    AS DWORD   ' // To keep 8 byte alignment
END TYPE

' // Size = 24 bytes
TYPE FILE_STANDARD_INFO   ' Must be 8 byte aligned
   AllocationSize AS QUAD    ' LARGE_INTEGER
   EndOfFile      AS QUAD    ' LARGE_INTEGER
   NumberOfLinks  AS DWORD   ' DWORD
   DeletePending  AS BYTE    ' BOOLEAN
   Directory      AS BYTE    ' BOOLEAN
   alignment__    AS WORD    ' // To keep 8 byte alignment
END TYPE

' // Size = 8 bytes
TYPE FILE_NAME_INFO DWORD
   FileNameLength AS DWORD          ' DWORD
   FileName       AS WSTRINGZ * 1   ' WCHAR - variable length
END TYPE

' // Size = 16 bytes
TYPE FILE_RENAME_INFO DWORD
   ReplaceIfExists AS BYTE           ' BOOLEAN
   RootDirectory   AS DWORD          ' HANDLE
   FileNameLength  AS DWORD          ' DWORD
   FileName        AS WSTRINGZ * 1   ' WCHAR - variable length
END TYPE

' // Size = 8 bytes
TYPE FILE_ALLOCATION_INFO QWORD
   AllocationSize AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 8 bytes
TYPE FILE_END_OF_FILE_INFO QWORD
   EndOfFile AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 32 bytes
TYPE FILE_STREAM_INFO QWORD FILL
   NextEntryOffset      AS DWORD          ' DWORD
   StreamNameLength     AS DWORD          ' DWORD
   StreamSize           AS QUAD           ' LARGE_INTEGER
   StreamAllocationSize AS QUAD           ' LARGE_INTEGER
   StreamName           AS WSTRINGZ * 4   ' WCHAR - variable length
   ' Note: We are using * 4 instead of * 1 to keep 8 byte alignment
END TYPE

' // Size = 16 bytes
TYPE FILE_COMPRESSION_INFO QWORD FILL
   CompressedFileSize   AS QUAD   ' LARGE_INTEGER
   CompressionFormat    AS WORD   ' WORD
   CompressionUnitShift AS BYTE   ' UCHAR
   ChunkShift           AS BYTE   ' UCHAR
   ClusterShift         AS BYTE   ' UCHAR
   Reserved(2)          AS BYTE   ' UCHAR[3]
END TYPE

' // Size = 8 bytes
TYPE FILE_ATTRIBUTE_TAG_INFO DWORD
   FileAttributes AS DWORD   ' DWORD
   ReparseTag     AS DWORD   ' DWORD
END TYPE

' // Size = 1 byte
TYPE FILE_DISPOSITION_INFO BYTE
   DeleteFile AS BYTE   ' BOOLEAN
END TYPE

' // Size = 112 byte
TYPE FILE_ID_BOTH_DIR_INFO QWORD FILL
   NextEntryOffset AS DWORD           ' DWORD
   FileIndex       AS DWORD           ' DWORD
   CreationTime    AS QUAD            ' LARGE_INTEGER
   LastAccessTime  AS QUAD            ' LARGE_INTEGER
   LastWriteTime   AS QUAD            ' LARGE_INTEGER
   ChangeTime      AS QUAD            ' LARGE_INTEGER
   EndOfFile       AS QUAD            ' LARGE_INTEGER
   AllocationSize  AS QUAD            ' LARGE_INTEGER
   FileAttributes  AS DWORD           ' DWORD
   FileNameLength  AS DWORD           ' DWORD
   EaSize          AS DWORD           ' DWORD
   ShortNameLength AS ASCIIZ PTR      ' CCHAR
   ShortName       AS WSTRINGZ * 12   ' WCHAR
   FileId          AS QUAD            ' LARGE_INTEGER
   FileName        AS WSTRINGZ * 4    ' WCHAR - variable length
   ' Note: We are using * 4 instead of * 1 to keep 8 byte alignment
END TYPE

' enum PRIORITY_HINT
%IoPriorityHintVeryLow     = 0
%IoPriorityHintLow         = 1
%IoPriorityHintNormal      = 2
%MaximumIoPriorityHintType = 3

' // Size = 4 byte
TYPE FILE_IO_PRIORITY_HINT_INFO DWORD
   PriorityHint AS DWORD   ' PRIORITY_HINT
END TYPE

'// Structure and constants must match those in ntioapi_x.w

%REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK       = &H00000001???
%REMOTE_PROTOCOL_INFO_FLAG_OFFLINE        = &H00000002???

' // Size = 32 byte
TYPE FILE_REMOTE_PROTOCOL_INFO_GenericReserved
   Reserved(7) AS DWORD   ' DWORD[8]
END TYPE

' // Size = 64 byte
TYPE FILE_REMOTE_PROTOCOL_INFO_ProtocolSpecificReserved
   Reserved(15) AS DWORD   ' DWORD[16]
END TYPE

' // Size = 116 byte
TYPE FILE_REMOTE_PROTOCOL_INFO DWORD FILL
   ' // Structure Version
   StructureVersion         AS WORD   ' USHORT // 1
   StructureSize            AS WORD   ' USHORT // sizeof(FILE_REMOTE_PROTOCOL_INFO)
   Protocol                 AS DWORD  ' DWORD  // Protocol (WNNC_NET_*) defined in wnnc.h or ntifs.h.
   ' // Protocol Version & Type
   ProtocolMajorVersion     AS WORD   ' USHORT
   ProtocolMinorVersion     AS WORD   ' USHORT
   ProtocolRevision         AS WORD   ' USHORT
   Reserved                 AS WORD   ' USHORT
   ' // Protocol-Generic Information
   Flags                    AS DWORD   ' DWORD
   GenericReserved          AS FILE_REMOTE_PROTOCOL_INFO_GenericReserved
   ' // Protocol specific information
   ProtocolSpecificReserved AS FILE_REMOTE_PROTOCOL_INFO_ProtocolSpecificReserved
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetFileInformationByHandle LIB "Kernel32.dll" _
    ALIAS "SetFileInformationByHandle" (BYVAL hFile AS DWORD, _
    BYVAL FileInformationClass AS LONG, BYVAL lpFileInformation AS DWORD, _
    BYVAL dwBufferSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetFileInformationByHandle IMPORT "KERNEL32.DLL" ALIAS "SetFileInformationByHandle" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL FileInformationClass AS DWORD _                ' __in FILE_INFO_BY_HANDLE_CLASS FileInformationClass
 , BYREF lpFileInformation AS ANY _                     ' __in LPVOID lpFileInformation
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD dwBufferSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFileInformationByHandleEx LIB "Kernel32.dll" _
    ALIAS "GetFileInformationByHandleEx" (BYVAL hFile AS DWORD, _
    BYVAL FileInformationClass AS LONG, BYVAL lpFileInformation AS DWORD, _
    BYVAL dwBufferSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetFileInformationByHandleEx IMPORT "KERNEL32.DLL" ALIAS "GetFileInformationByHandleEx" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYVAL FileInformationClass AS DWORD _                ' __in  FILE_INFO_BY_HANDLE_CLASS FileInformationClass
 , BYREF lpFileInformation AS ANY _                     ' __out LPVOID lpFileInformation
 , BYVAL dwBufferSize AS DWORD _                        ' __in  DWORD dwBufferSize
 ) AS LONG                                              ' BOOL
#ENDIF

' enum FILE_ID_TYPE
%FileIdType        = 0
%ObjectIdType      = 1
%MaximumFileIdType = 2

' // Size = 116 byte
UNION FILE_ID_DESCRIPTOR_UNION QWORD FILL
   FileId   AS QUAD   ' LARGE_INTEGER
   ObjectId AS GUID   ' GUID
END UNION

UNION FILE_ID_DESCRIPTOR_TYPE_UNION
   Type    AS DWORD   ' FILE_ID_TYPE // Describes the type of identifier passed in.
   ' // For compoatibility with the PB declares
   fidType AS DWORD
END UNION

' // Size = 24 byte
TYPE FILE_ID_DESCRIPTOR QWORD FILL
   dwSize AS DWORD   ' DWORD // Size of the struct
   FILE_ID_DESCRIPTOR_TYPE_UNION
   FILE_ID_DESCRIPTOR_UNION
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION OpenFileById LIB "Kernel32.dll" ALIAS "OpenFileById" _
    (BYVAL hVolumeHint AS DWORD, lpFileId AS LONG, _
    BYVAL dwDesiredAccess AS DWORD, BYVAL dwShareMode AS DWORD, _
    lpSecurityAttributes AS SECURITY_ATTRIBUTES, _
    BYVAL dwFlagsAndAttributes AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION OpenFileById IMPORT "KERNEL32.DLL" ALIAS "OpenFileById" ( _
   BYVAL hVolumeHint AS DWORD _                         ' __in HANDLE hVolumeHint
 , BYREF lpFileId AS FILE_ID_DESCRIPTOR _               ' __in LPFILE_ID_DESCRIPTOR lpFileId
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 ) AS DWORD                                             ' HANDLE
#ENDIF

#ENDIF   ' #if (_WIN32_WINNT >= 0x0600)

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

'//
'//  Flags to be passed into CREATE_SYMBOLIC_LINK
'//

%SYMBOLIC_LINK_FLAG_DIRECTORY            = &H1

%VALID_SYMBOLIC_LINK_FLAGS  = %SYMBOLIC_LINK_FLAG_DIRECTORY  ' // & whatever other flags we think of!

DECLARE FUNCTION CreateSymbolicLinkA IMPORT "KERNEL32.DLL" ALIAS "CreateSymbolicLinkA" ( _
   BYREF lpSymlinkFileName AS ASCIIZ _                  ' __in LPCSTR lpSymlinkFileName
 , BYREF lpTargetFileName AS ASCIIZ _                   ' __in LPCSTR lpTargetFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION CreateSymbolicLinkW IMPORT "KERNEL32.DLL" ALIAS "CreateSymbolicLinkW" ( _
   BYREF lpSymlinkFileName AS WSTRINGZ _                ' __in LPCWSTR lpSymlinkFileName
 , BYREF lpTargetFileName AS WSTRINGZ _                 ' __in LPCWSTR lpTargetFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO CreateSymbolicLink = CreateSymbolicLinkW
#ELSE
   MACRO CreateSymbolicLink = CreateSymbolicLinkA
#ENDIF

DECLARE FUNCTION CreateSymbolicLinkTransactedA IMPORT "KERNEL32.DLL" ALIAS "CreateSymbolicLinkTransactedA" ( _
   BYREF lpSymlinkFileName AS ASCIIZ _                  ' __in LPCSTR lpSymlinkFileName
 , BYREF lpTargetFileName AS ASCIIZ _                   ' __in LPCSTR lpTargetFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION CreateSymbolicLinkTransactedW IMPORT "KERNEL32.DLL" ALIAS "CreateSymbolicLinkTransactedW" ( _
   BYREF lpSymlinkFileName AS WSTRINGZ _                ' __in LPCWSTR lpSymlinkFileName
 , BYREF lpTargetFileName AS WSTRINGZ _                 ' __in LPCWSTR lpTargetFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE  hTransaction
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO CreateSymbolicLinkTransacted = CreateSymbolicLinkTransactedW
#ELSE
   MACRO CreateSymbolicLinkTransacted = CreateSymbolicLinkTransactedA
#ENDIF

DECLARE FUNCTION GetFinalPathNameByHandleA IMPORT "KERNEL32.DLL" ALIAS "GetFinalPathNameByHandleA" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpszFilePath AS ASCIIZ _                       ' __out LPSTR  lpszFilePath
 , BYVAL cchFilePath AS DWORD _                         ' __in  DWORD  cchFilePath
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD  dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFinalPathNameByHandleW IMPORT "KERNEL32.DLL" ALIAS "GetFinalPathNameByHandleW" ( _
   BYVAL hFile AS DWORD _                               ' __in  HANDLE hFile
 , BYREF lpszFilePath AS WSTRINGZ _                     ' __out LPWSTR lpszFilePath
 , BYVAL cchFilePath AS DWORD _                         ' __in  DWORD  cchFilePath
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD  dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFinalPathNameByHandle = GetFinalPathNameByHandleW
#ELSE
   MACRO GetFinalPathNameByHandle = GetFinalPathNameByHandleA
#ENDIF

#ENDIF ' // (_WIN32_WINNT >= 0x0600)


'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION QueryActCtxSettingsW IMPORT "KERNEL32.DLL" ALIAS "QueryActCtxSettingsW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 , BYVAL hActCtx AS DWORD _                             ' __in  HANDLE  hActCtx
 , BYREF settingsNameSpace AS WSTRINGZ _                ' __in  PCWSTR  settingsNameSpace
 , BYREF settingName AS WSTRINGZ _                      ' __in  PCWSTR  settingName
 , BYREF pvBuffer AS WSTRINGZ _                         ' __out PWSTR   pvBuffer
 , BYVAL dwBuffer AS DWORD _                            ' __in  SIZE_T  dwBuffer
 , BYREF pdwWrittenOrRequired AS DWORD _                ' __out SIZE_T *pdwWrittenOrRequired
 ) AS LONG                                              ' BOOL

MACRO QueryActCtxSettings = QueryActCtxSettingsW
#ENDIF   ' #if (_WIN32_WINNT >= 0x0600)

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
DECLARE FUNCTION ReplacePartitionUnit IMPORT "KERNEL32.DLL" ALIAS "ReplacePartitionUnit" ( _
   BYREF TargetPartition AS WSTRINGZ _                  ' __in PWSTR TargetPartition
 , BYREF SparePartition AS WSTRINGZ _                   ' __in PWSTR SparePartition
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS LONG                                              ' BOOL
#ENDIF
'#endif

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600

DECLARE FUNCTION AddSecureMemoryCacheCallback IMPORT "KERNEL32.DLL" ALIAS "AddSecureMemoryCacheCallback" ( _
   BYVAL pfnCallBack AS DWORD _                         ' __in __callback PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveSecureMemoryCacheCallback IMPORT "KERNEL32.DLL" ALIAS "RemoveSecureMemoryCacheCallback" ( _
   BYVAL pfnCallBack AS DWORD _                         ' __in __callback PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
 ) AS LONG                                              ' BOOL

#ENDIF
'#endif

'#if (_WIN32_WINNT >= 0x0601)
#IF %WINVER >= &H0601

DECLARE FUNCTION CopyExtendedContext IMPORT "KERNEL32.DLL" ALIAS "CopyExtendedContext" ( _
   BYREF Destination AS CONTEXT_EX _                    ' __out PCONTEXT_EX Destination
 , BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF Source AS CONTEXT_EX _                         ' __in PCONTEXT_EX Source
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitializeExtendedContext IMPORT "KERNEL32.DLL" ALIAS "InitializeExtendedContext" ( _
   BYREF Context AS ANY _                               ' __out PVOID Context
 , BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF ContextEx AS CONTEXT_EX _                      ' __out PCONTEXT_EX* ContextEx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetEnabledExtendedFeatures IMPORT "KERNEL32.DLL" ALIAS "GetEnabledExtendedFeatures" ( _
   BYVAL FeatureMask AS QUAD _                          ' __in DWORD64 FeatureMask
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION GetExtendedContextLength IMPORT "KERNEL32.DLL" ALIAS "GetExtendedContextLength" ( _
   BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF ContextLength AS DWORD _                       ' __out PDWORD ContextLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetExtendedFeaturesMask IMPORT "KERNEL32.DLL" ALIAS "GetExtendedFeaturesMask" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION LocateExtendedFeature IMPORT "KERNEL32.DLL" ALIAS "LocateExtendedFeature" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 , BYVAL FeatureId AS DWORD _                           ' __in DWORD FeatureId
 , BYREF Length AS DWORD _                              ' __out_opt PDWORD Length
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION LocateLegacyContext IMPORT "KERNEL32.DLL" ALIAS "LocateLegacyContext" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 , BYREF Length AS DWORD _                              ' __out_opt PDWORD Length
 ) AS DWORD                                             ' PCONTEXT

DECLARE SUB SetExtendedFeaturesMask IMPORT "KERNEL32.DLL" ALIAS "SetExtendedFeaturesMask" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __out PCONTEXT_EX ContextEx
 , BYVAL FeatureMask AS QUAD _                          ' __in DWORD64 FeatureMask
 )                                                      ' VOID

DECLARE FUNCTION EnableThreadProfiling IMPORT "KERNEL32.DLL" ALIAS "EnableThreadProfiling" ( _
   BYVAL ThreadHandle AS DWORD _                        ' __in HANDLE ThreadHandle
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL HardwareCounters AS QUAD _                     ' __in DWORD64 HardwareCounters
 , BYREF PerformanceDataHandle AS DWORD _               ' __out HANDLE *PerformanceDataHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DisableThreadProfiling IMPORT "KERNEL32.DLL" ALIAS "DisableThreadProfiling" ( _
   BYVAL PerformanceDataHandle AS DWORD _               ' __in HANDLE PerformanceDataHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION QueryThreadProfiling IMPORT "KERNEL32.DLL" ALIAS "QueryThreadProfiling" ( _
   BYVAL ThreadHandle AS DWORD _                        ' __in HANDLE ThreadHandle
 , BYREF Enabled AS BYTE _                              ' __out PBOOLEAN Enabled
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ReadThreadProfilingData IMPORT "KERNEL32.DLL" ALIAS "ReadThreadProfilingData" ( _
   BYVAL PerformanceDataHandle AS DWORD _               ' __in HANDLE PerformanceDataHandle
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PerformanceData AS PERFORMANCE_DATA _          ' __out PPERFORMANCE_DATA PerformanceData
 ) AS DWORD                                             ' DWORD

#ENDIF
