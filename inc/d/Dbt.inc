'/*****************************************************************************
' *
' *  (C) Copyright MICROSOFT Corp., 1993-1999
' *
' *  Title:      DBT.H - Equates for WM_DEVICECHANGE and BroadcastSystemMessage
' *
' *  Version:    4.00
' *
' *  Date:       24-May-1993
' *
' *----------------------------------------------------------------------------
' *
' *  Change log:
' *
' *     DATE     REV                 DESCRIPTION
' *  ----------- --- ----------------------------------------------------------
' *
' *****************************************************************************/

#INCLUDE THIS ONCE
%DBT_INC = 1

'/*
' * BroadcastSpecialMessage constants.
' */
%WM_DEVICECHANGE         = &H0219???

'/* XLATOFF */
'#ifdef  IS_32
'#define DBTFAR
'#else
'#define DBTFAR  far
'#endif
'/* XLATON */

'#if !defined(_WCHAR_T_DEFINED) && !defined(_NATIVE_WCHAR_T_DEFINED)
'typedef unsigned short wchar_t;
'#define _WCHAR_T_DEFINED
'#endif

'#ifndef GUID_DEFINED
'#include <guiddef.h>
'#endif // !defined(GUID_DEFINED)

'/*
' * Broadcast message and receipient flags.
' *
' * Note that there is a third "flag". If the wParam has:
' *
' * bit 15 on:   lparam is a pointer and bit 14 is meaningfull.
' * bit 15 off:  lparam is just a UNLONG data type.
' *
' * bit 14 on:   lparam is a pointer to an ASCIIZ string.
' * bit 14 off:  lparam is a pointer to a binary struture starting with
' *              a dword describing the length of the structure.
' */
%BSF_QUERY               = &H00000001???
%BSF_IGNORECURRENTTASK   = &H00000002???     ' /* Meaningless for VxDs */
%BSF_FLUSHDISK           = &H00000004???     ' /* Shouldn't be used by VxDs */
%BSF_NOHANG              = &H00000008???
%BSF_POSTMESSAGE         = &H00000010???
%BSF_FORCEIFHUNG         = &H00000020???
%BSF_NOTIMEOUTIFNOTHUNG  = &H00000040???
%BSF_MSGSRV32ISOK        = &H80000000???     ' /* Called synchronously from PM API */
%BSF_MSGSRV32ISOK_BIT    = 31                ' /* Called synchronously from PM API */

%BSM_ALLCOMPONENTS       = &H00000000???
%BSM_VXDS                = &H00000001???
%BSM_NETDRIVER           = &H00000002???
%BSM_INSTALLABLEDRIVERS  = &H00000004???
%BSM_APPLICATIONS        = &H00000008???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_APPYBEGIN
' * lParam  = (not used)
' *
' *      'Appy-time is now available.  This message is itself sent
' *      at 'Appy-time.
' *
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_APPYEND
' * lParam  = (not used)
' *
' *      'Appy-time is no longer available.  This message is *NOT* sent
' *      at 'Appy-time.  (It cannot be, because 'Appy-time is gone.)
' *
' * NOTE!  It is possible for DBT_APPYBEGIN and DBT_APPYEND to be sent
' * multiple times during a single Windows session.  Each appearance of
' * 'Appy-time is bracketed by these two messages, but 'Appy-time may
' * momentarily become unavailable during otherwise normal Windows
' * processing.  The current status of 'Appy-time availability can always
' * be obtained from a call to _SHELL_QueryAppyTimeAvailable.
' */
%DBT_APPYBEGIN                   = &H0000???
%DBT_APPYEND                     = &H0001???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_DEVNODES_CHANGED
' * lParam  = 0
' *
' *      send when configmg finished a process tree batch. Some devnodes
' *      may have been added or removed. This is used by ring3 people which
' *      need to be refreshed whenever any devnode changed occur (like
' *      device manager). People specific to certain devices should use
' *      DBT_DEVICE* instead.
' */

%DBT_DEVNODES_CHANGED            = &H0007???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_QUERYCHANGECONFIG
' * lParam  = 0
' *
' *      sent to ask if a config change is allowed
' */

%DBT_QUERYCHANGECONFIG           = &H0017???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_CONFIGCHANGED
' * lParam  = 0
' *
' *      sent when a config has changed
' */

%DBT_CONFIGCHANGED               = &H0018???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_CONFIGCHANGECANCELED
' * lParam  = 0
' *
' *      someone cancelled the config change
' */

%DBT_CONFIGCHANGECANCELED        = &H0019???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_MONITORCHANGE
' * lParam  = new resolution to use (LOWORD=x, HIWORD=y)
' *           if 0, use the default res for current config
' *
' *      this message is sent when the display monitor has changed
' *      and the system should change the display mode to match it.
' */

%DBT_MONITORCHANGE               = &H001B???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_SHELLLOGGEDON
' * lParam  = 0
' *
' *      The shell has finished login on: VxD can now do Shell_EXEC.
' */

%DBT_SHELLLOGGEDON               = &H0020???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_CONFIGMGAPI
' * lParam  = CONFIGMG API Packet
' *
' *      CONFIGMG ring 3 call.
' */
%DBT_CONFIGMGAPI32               = &H0022???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_VXDINITCOMPLETE
' * lParam  = 0
' *
' *      CONFIGMG ring 3 call.
' */
%DBT_VXDINITCOMPLETE             = &H0023???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_VOLLOCK*
' * lParam  = pointer to VolLockBroadcast structure described below
' *
' *      Messages issued by IFSMGR for volume locking purposes on WM_DEVICECHANGE.
' *      All these messages pass a pointer to a struct which has no pointers.
' */

%DBT_VOLLOCKQUERYLOCK    = &H8041???
%DBT_VOLLOCKLOCKTAKEN    = &H8042???
%DBT_VOLLOCKLOCKFAILED   = &H8043???
%DBT_VOLLOCKQUERYUNLOCK  = &H8044???
%DBT_VOLLOCKLOCKRELEASED = &H8045???
%DBT_VOLLOCKUNLOCKFAILED = &H8046???

'/*
' * Device broadcast header
' */

'struct _DEV_BROADCAST_HDR {     /* */
'    DWORD       dbch_size;
'    DWORD       dbch_devicetype;
'    DWORD       dbch_reserved;
'};

'typedef struct  _DEV_BROADCAST_HDR      DEV_BROADCAST_HDR;
'typedef         DEV_BROADCAST_HDR       DBTFAR *PDEV_BROADCAST_HDR;

' // Size = 12 bytes
TYPE DEV_BROADCAST_HDR DWORD
   dbch_size       AS DWORD   ' DWORD
   dbch_devicetype AS DWORD   ' DWORD
   dbch_reserved   AS DWORD   ' DWORD
END TYPE

'/*
' * Structure for volume lock broadcast
' */

'typedef struct VolLockBroadcast VolLockBroadcast;
'typedef VolLockBroadcast *pVolLockBroadcast;
'struct VolLockBroadcast {
'        struct  _DEV_BROADCAST_HDR vlb_dbh;
'        DWORD   vlb_owner;              // thread on which lock request is being issued
'        BYTE    vlb_perms;              // lock permission flags defined below
'        BYTE    vlb_lockType;           // type of lock
'        BYTE    vlb_drive;              // drive on which lock is issued
'        BYTE    vlb_flags;              // miscellaneous flags
'};

' // Size = 20 bytes
TYPE VolLockBroadcast BYTE
   vlb_dbh      AS DEV_BROADCAST_HDR
   vlb_owner    AS DWORD               ' // thread on which lock request is being issued
   vlb_perms    AS BYTE                ' // lock permission flags defined below
   vlb_lockType AS BYTE                ' // type of lock
   vlb_drive    AS BYTE                ' // drive on which lock is issued
   vlb_flags    AS BYTE                ' // miscellaneous flags
END TYPE

'/*
' * Values for vlb_perms
' */
%LOCKP_ALLOW_WRITES              = &H01?   ' // Bit 0 set - allow writes
%LOCKP_FAIL_WRITES               = &H00?   ' // Bit 0 clear - fail writes
%LOCKP_FAIL_MEM_MAPPING          = &H02?   ' // Bit 1 set - fail memory mappings
%LOCKP_ALLOW_MEM_MAPPING         = &H00?   ' // Bit 1 clear - allow memory mappings
%LOCKP_USER_MASK                 = &H03?   ' // Mask for user lock flags
%LOCKP_LOCK_FOR_FORMAT           = &H04?   ' // Level 0 lock for format

'/*
' * Values for vlb_flags
' */
%LOCKF_LOGICAL_LOCK              = &H00?   ' // Bit 0 clear - logical lock
%LOCKF_PHYSICAL_LOCK             = &H01?   ' // Bit 0 set - physical lock

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_NODISKSPACE
' * lParam  = drive number of drive that is out of disk space (1-based)
' *
' * Message issued by IFS manager when it detects that a drive is run out of
' * free space.
' */

%DBT_NO_DISK_SPACE               = &H0047???

'/*
' * Message = WM_DEVICECHANGE
' * wParam  = DBT_LOW_DISK_SPACE
' * lParam  = drive number of drive that is low on disk space (1-based)
' *
' * Message issued by VFAT when it detects that a drive it has mounted
' * has the remaning free space below a threshold specified by the
' * registry or by a disk space management application.
' * The broadcast is issued by VFAT ONLY when space is either allocated
' * or freed by VFAT.
' */

%DBT_LOW_DISK_SPACE      = &H0048???

%DBT_CONFIGMGPRIVATE             = &H7FFF???

'/*
' * The following messages are for WM_DEVICECHANGE. The immediate list
' * is for the wParam. ALL THESE MESSAGES PASS A POINTER TO A STRUCT
' * STARTING WITH A DWORD SIZE AND HAVING NO POINTER IN THE STRUCT.
' *
' */
%DBT_DEVICEARRIVAL               = &H8000???   ' // system detected a new device
%DBT_DEVICEQUERYREMOVE           = &H8001???   ' // wants to remove, may fail
%DBT_DEVICEQUERYREMOVEFAILED     = &H8002???   ' // removal aborted
%DBT_DEVICEREMOVEPENDING         = &H8003???   ' // about to remove, still avail.
%DBT_DEVICEREMOVECOMPLETE        = &H8004???   ' // device is gone
%DBT_DEVICETYPESPECIFIC          = &H8005???   ' // type specific event

'#if(WINVER >= = &H040A)
%DBT_CUSTOMEVENT                 = &H8006???   ' // user-defined event
'#endif /* WINVER >= = &H040A */

'#if(WINVER >= _WIN32_WINNT_WIN7)
%DBT_DEVINSTENUMERATED           = &H8007???   ' // system detected a new device
%DBT_DEVINSTSTARTED              = &H8008???   ' // device installed and started
%DBT_DEVINSTREMOVED              = &H8009???   ' // device removed from system
%DBT_DEVINSTPROPERTYCHANGED      = &H800A???   ' // a property on the device changed
'#endif /* WINVER >= _WIN32_WINNT_WIN7 */

%DBT_DEVTYP_OEM                  = &H00000000???   ' // oem-defined device type
%DBT_DEVTYP_DEVNODE              = &H00000001???   ' // devnode number
%DBT_DEVTYP_VOLUME               = &H00000002???   ' // logical volume
%DBT_DEVTYP_PORT                 = &H00000003???   ' // serial, parallel
%DBT_DEVTYP_NET                  = &H00000004???   ' // network resource

'#if(WINVER >= = &H040A)
%DBT_DEVTYP_DEVICEINTERFACE      = &H00000005???   ' // device interface class
%DBT_DEVTYP_HANDLE               = &H00000006???   ' // file system handle
'#endif /* WINVER >= = &H040A */

'#if(WINVER >= _WIN32_WINNT_WIN7)
%DBT_DEVTYP_DEVINST              = &H00000007???   ' // device instance
'#endif /* WINVER >= _WIN32_WINNT_WIN7 */

'struct _DEV_BROADCAST_HEADER { /* */
'    DWORD       dbcd_size;
'    DWORD       dbcd_devicetype;
'    DWORD       dbcd_reserved;
'};

' // Size = 12 bytes
TYPE DEV_BROADCAST_HEADER DWORD
   dbcd_size       AS DWORD   ' DWORD
   dbcd_devicetype AS DWORD   ' DWORD
   dbcd_reserved   AS DWORD   ' DWORD
END TYPE

'struct _DEV_BROADCAST_OEM {     /* */
'    DWORD       dbco_size;
'    DWORD       dbco_devicetype;
'    DWORD       dbco_reserved;
'    DWORD       dbco_identifier;
'    DWORD       dbco_suppfunc;
'};

'typedef struct  _DEV_BROADCAST_OEM      DEV_BROADCAST_OEM;
'typedef         DEV_BROADCAST_OEM       DBTFAR *PDEV_BROADCAST_OEM;

' // Size = 20 bytes
TYPE DEV_BROADCAST_OEM DWORD
   dbco_size       AS DWORD   ' DWORD
   dbco_devicetype AS DWORD   ' DWORD
   dbco_reserved   AS DWORD   ' DWORD
   dbco_identifier AS DWORD   ' DWORD
   dbco_suppfunc   AS DWORD   ' DWORD
END TYPE

'struct _DEV_BROADCAST_DEVNODE { /* */
'    DWORD       dbcd_size;
'    DWORD       dbcd_devicetype;
'    DWORD       dbcd_reserved;
'    DWORD       dbcd_devnode;
'};

'typedef struct  _DEV_BROADCAST_DEVNODE  DEV_BROADCAST_DEVNODE;
'typedef         DEV_BROADCAST_DEVNODE   DBTFAR *PDEV_BROADCAST_DEVNODE;

' // Size = 16 bytes
TYPE DEV_BROADCAST_DEVNODE DWORD
   dbcd_size       AS DWORD   ' DWORD
   dbcd_devicetype AS DWORD   ' DWORD
   dbcd_reserved   AS DWORD   ' DWORD
   dbcd_devnode    AS DWORD   ' DWORD
END TYPE

'struct _DEV_BROADCAST_VOLUME { /* */
'    DWORD       dbcv_size;
'    DWORD       dbcv_devicetype;
'    DWORD       dbcv_reserved;
'    DWORD       dbcv_unitmask;
'    WORD        dbcv_flags;
'};

'typedef struct  _DEV_BROADCAST_VOLUME   DEV_BROADCAST_VOLUME;
'typedef         DEV_BROADCAST_VOLUME    DBTFAR *PDEV_BROADCAST_VOLUME;

' // Size = 20 bytes
TYPE DEV_BROADCAST_VOLUME DWORD
   dbcv_size       AS DWORD   ' DWORD
   dbcv_devicetype AS DWORD   ' DWORD
   dbcv_reserved   AS DWORD   ' DWORD
   dbcv_unitmask   AS DWORD   ' DWORD
   dbcv_flags      AS WORD    ' WORD
END TYPE

%DBTF_MEDIA      = &H0001??         ' // media comings and goings
%DBTF_NET        = &H0002??         ' // network volume

'typedef struct _DEV_BROADCAST_PORT_A {
'    DWORD       dbcp_size;
'    DWORD       dbcp_devicetype;
'    DWORD       dbcp_reserved;
'    char        dbcp_name[1];
'} DEV_BROADCAST_PORT_A, *PDEV_BROADCAST_PORT_A;

' // Size = 16 bytes
TYPE DEV_BROADCAST_PORT_A DWORD
   dbcp_size       AS DWORD        ' DWORD
   dbcp_devicetype AS DWORD        ' DWORD
   dbcp_reserved   AS DWORD        ' DWORD
   dbcp_name       AS ASCIIZ * 1   ' char dbcp_name[1]  // variable-length
END TYPE

'typedef struct _DEV_BROADCAST_PORT_W {
'    DWORD       dbcp_size;
'    DWORD       dbcp_devicetype;
'    DWORD       dbcp_reserved;
'    wchar_t     dbcp_name[1];
'} DEV_BROADCAST_PORT_W, DBTFAR *PDEV_BROADCAST_PORT_W;

' // Size = 16 bytes
TYPE DEV_BROADCAST_PORT_W DWORD
   dbcp_size       AS DWORD          ' DWORD
   dbcp_devicetype AS DWORD          ' DWORD
   dbcp_reserved   AS DWORD          ' DWORD
   dbcp_name       AS WSTRINGZ * 1   ' wchar_t dbcp_name[1]  // variable-length
END TYPE

'#ifdef UNICODE
'typedef DEV_BROADCAST_PORT_W     DEV_BROADCAST_PORT;
'typedef PDEV_BROADCAST_PORT_W    PDEV_BROADCAST_PORT;
'#else
'typedef DEV_BROADCAST_PORT_A     DEV_BROADCAST_PORT;
'typedef PDEV_BROADCAST_PORT_A    PDEV_BROADCAST_PORT;
'#endif

#IF %DEF(%UNICODE)
   MACRO DEV_BROADCAST_PORT = DEV_BROADCAST_PORT_W
#ELSE
   MACRO DEV_BROADCAST_PORT = DEV_BROADCAST_PORT_A
#ENDIF

'struct _DEV_BROADCAST_NET { /* */
'    DWORD       dbcn_size;
'    DWORD       dbcn_devicetype;
'    DWORD       dbcn_reserved;
'    DWORD       dbcn_resource;
'    DWORD       dbcn_flags;
'};

'typedef struct  _DEV_BROADCAST_NET      DEV_BROADCAST_NET;
'typedef         DEV_BROADCAST_NET       DBTFAR *PDEV_BROADCAST_NET;

' // Size = 20 bytes
TYPE DEV_BROADCAST_NET DWORD
   dbcn_size       AS DWORD   ' DWORD
   dbcn_devicetype AS DWORD   ' DWORD
   dbcn_reserved   AS DWORD   ' DWORD
   dbcn_resource   AS DWORD   ' DWORD
   dbcn_flags      AS DWORD   ' DWORD
END TYPE

'#if(WINVER >= = &H040A)

'typedef struct _DEV_BROADCAST_DEVICEINTERFACE_A {
'    DWORD       dbcc_size;
'    DWORD       dbcc_devicetype;
'    DWORD       dbcc_reserved;
'    GUID        dbcc_classguid;
'    char        dbcc_name[1];
'} DEV_BROADCAST_DEVICEINTERFACE_A, *PDEV_BROADCAST_DEVICEINTERFACE_A;

' // Size = 32 bytes
TYPE DEV_BROADCAST_DEVICEINTERFACE_A DWORD
   dbcc_size       AS DWORD        ' DWORD
   dbcc_devicetype AS DWORD        ' DWORD
   dbcc_reserved   AS DWORD        ' DWORD
   dbcc_classguid  AS GUID         ' GUID
   dbcc_name       AS ASCIIZ * 1   ' char dbcc_name[1]
END TYPE

'typedef struct _DEV_BROADCAST_DEVICEINTERFACE_W {
'    DWORD       dbcc_size;
'    DWORD       dbcc_devicetype;
'    DWORD       dbcc_reserved;
'    GUID        dbcc_classguid;
'    wchar_t     dbcc_name[1];
'} DEV_BROADCAST_DEVICEINTERFACE_W, *PDEV_BROADCAST_DEVICEINTERFACE_W;

' // Size = 32 bytes
TYPE DEV_BROADCAST_DEVICEINTERFACE_W DWORD
   dbcc_size       AS DWORD          ' DWORD
   dbcc_devicetype AS DWORD          ' DWORD
   dbcc_reserved   AS DWORD          ' DWORD
   dbcc_classguid  AS GUID           ' GUID
   dbcc_name       AS WSTRINGZ * 1   ' wchar_t dbcc_name[1]
END TYPE

'#ifdef UNICODE
'typedef DEV_BROADCAST_DEVICEINTERFACE_W   DEV_BROADCAST_DEVICEINTERFACE;
'typedef PDEV_BROADCAST_DEVICEINTERFACE_W  PDEV_BROADCAST_DEVICEINTERFACE;
'#else
'typedef DEV_BROADCAST_DEVICEINTERFACE_A   DEV_BROADCAST_DEVICEINTERFACE;
'typedef PDEV_BROADCAST_DEVICEINTERFACE_A  PDEV_BROADCAST_DEVICEINTERFACE;
'#endif

#IF %DEF(%UNICODE)
   MACRO DEV_BROADCAST_DEVICEINTERFACE = DEV_BROADCAST_DEVICEINTERFACE_W
#ELSE
   MACRO DEV_BROADCAST_DEVICEINTERFACE = DEV_BROADCAST_DEVICEINTERFACE_A
#ENDIF

'typedef struct _DEV_BROADCAST_HANDLE {
'    DWORD       dbch_size;
'    DWORD       dbch_devicetype;
'    DWORD       dbch_reserved;
'    HANDLE      dbch_handle;     // file handle used in call to RegisterDeviceNotification
'    HDEVNOTIFY  dbch_hdevnotify; // returned from RegisterDeviceNotification
'    //
'    // The following 3 fields are only valid if wParam is DBT_CUSTOMEVENT.
'    //
'    GUID        dbch_eventguid;
'    LONG        dbch_nameoffset; // offset (bytes) of variable-length string buffer (-1 if none)
'    BYTE        dbch_data[1];    // variable-sized buffer, potentially containing binary and/or text data
'} DEV_BROADCAST_HANDLE, *PDEV_BROADCAST_HANDLE;

' // Size = 44 bytes
TYPE DEV_BROADCAST_HANDLE DWORD
   dbch_size       AS DWORD   ' DWORD
   dbch_devicetype AS DWORD   ' DWORD
   dbch_reserved   AS DWORD   ' DWORD
   dbch_handle     AS DWORD   ' HANDLE // file handle used in call to RegisterDeviceNotification
   dbch_hdevnotify AS DWORD   ' HDEVNOTIFY // returned from RegisterDeviceNotification
   ' //
   ' // The following 3 fields are only valid if wParam is DBT_CUSTOMEVENT.
   ' //
   dbch_eventguid  AS GUID    ' GUID
   dbch_nameoffset AS LONG    ' LONG // offset (bytes) of variable-length string buffer (-1 if none)
   dbch_data(0)    AS BYTE    ' BYTE dbch_data[1]  // variable-sized buffer, potentially containing binary and/or text data
END TYPE

'#if(WINVER >= = &H0501)

'//
'// Define 32-bit and 64-bit versions of the DEV_BROADCAST_HANDLE structure
'// for WOW64.  These must be kept in sync with the above structure.
'//

'typedef struct _DEV_BROADCAST_HANDLE32 {
'    DWORD       dbch_size;
'    DWORD       dbch_devicetype;
'    DWORD       dbch_reserved;
'    ULONG32     dbch_handle;
'    ULONG32     dbch_hdevnotify;
'    GUID        dbch_eventguid;
'    LONG        dbch_nameoffset;
'    BYTE        dbch_data[1];
'} DEV_BROADCAST_HANDLE32, *PDEV_BROADCAST_HANDLE32;

' // Size = 44 bytes
TYPE DEV_BROADCAST_HANDLE32 DWORD
   dbch_size       AS DWORD   ' DWORD
   dbch_devicetype AS DWORD   ' DWORD
   dbch_reserved   AS DWORD   ' DWORD
   dbch_handle     AS DWORD   ' ULONG32
   dbch_hdevnotify AS DWORD   ' ULONG32
   dbch_eventguid  AS GUID    ' GUID
   dbch_nameoffset AS LONG    ' LONG
   dbch_data(0)    AS BYTE    ' BYTE dbch_data[1]
END TYPE

'typedef struct _DEV_BROADCAST_HANDLE64 {
'    DWORD       dbch_size;
'    DWORD       dbch_devicetype;
'    DWORD       dbch_reserved;
'    ULONG64     dbch_handle;
'    ULONG64     dbch_hdevnotify;
'    GUID        dbch_eventguid;
'    LONG        dbch_nameoffset;
'    BYTE        dbch_data[1];
'} DEV_BROADCAST_HANDLE64, *PDEV_BROADCAST_HANDLE64;

' // Size = 56 bytes
TYPE DEV_BROADCAST_HANDLE64 QWORD FILL
   dbch_size       AS DWORD   ' DWORD
   dbch_devicetype AS DWORD   ' DWORD
   dbch_reserved   AS DWORD   ' DWORD
   dbch_handle     AS QUAD    ' ULONG64
   dbch_hdevnotify AS QUAD    ' ULONG64
   dbch_eventguid  AS GUID    ' GUID
   dbch_nameoffset AS LONG    ' LONG
   dbch_data(0)    AS BYTE    ' BYTE dbch_data[1]
END TYPE

'#endif /* WINVER >= = &H0501 */

'#endif /* WINVER >= = &H040A */

'#if(WINVER >= _WIN32_WINNT_WIN7)

'//
'// Define the DEV_BROADCAST_DEVINST structure
'//
'typedef struct _DEV_BROADCAST_DEVINST_A {
'    DWORD       dbci_size;
'    DWORD       dbci_devicetype;
'    DWORD       dbci_reserved;
'    DWORD       dbci_flags;
'    char        dbci_devinst[200];  // MAX_DEVICE_ID_LEN
'} DEV_BROADCAST_DEVINST_A, *PDEV_BROADCAST_DEVINST_A;

' // Size = 216 bytes
TYPE DEV_BROADCAST_DEVINST_A
   dbci_size       AS DWORD          ' DWORD
   dbci_devicetype AS DWORD          ' DWORD
   dbci_reserved   AS DWORD          ' DWORD
   dbci_flags      AS DWORD          ' DWORD
   dbci_devinst    AS STRING * 200   ' char dbci_devinst[200];  // MAX_DEVICE_ID_LEN
END TYPE

'typedef struct _DEV_BROADCAST_DEVINST_W {
'    DWORD       dbci_size;
'    DWORD       dbci_devicetype;
'    DWORD       dbci_reserved;
'    DWORD       dbci_flags;
'    wchar_t     dbci_devinst[200];  // MAX_DEVICE_ID_LEN
'} DEV_BROADCAST_DEVINST_W, *PDEV_BROADCAST_DEVINST_W;

' // Size = 416 bytes
TYPE DEV_BROADCAST_DEVINST_W
   dbci_size       AS DWORD          ' DWORD
   dbci_devicetype AS DWORD          ' DWORD
   dbci_reserved   AS DWORD          ' DWORD
   dbci_flags      AS DWORD          ' DWORD
   dbci_devinst    AS WSTRING * 200  ' char dbci_devinst[200];  // MAX_DEVICE_ID_LEN
END TYPE

'#ifdef UNICODE
'typedef DEV_BROADCAST_DEVINST_W   DEV_BROADCAST_DEVINST;
'typedef PDEV_BROADCAST_DEVINST_W  PDEV_BROADCAST_DEVINST;
'#else
'typedef DEV_BROADCAST_DEVINST_A   DEV_BROADCAST_DEVINST;
'typedef PDEV_BROADCAST_DEVINST_A  PDEV_BROADCAST_DEVINST;
'#endif

#IF %DEF(%UNICODE)
   MACRO DEV_BROADCAST_DEVINST = DEV_BROADCAST_DEVINST_W
#ELSE
   MACRO DEV_BROADCAST_DEVINST = DEV_BROADCAST_DEVINST_A
#ENDIF

'//
'// Valid flags for DEV_BROADCAST_DEVINST
'//
%NOTIFY_DEVICE_ALLDEVICES        = &H00000001???

%NOTIFY_DEVICE_ARRIVALREMOVAL    = &H00000010???
%NOTIFY_DEVICE_PROPERTYCHANGED   = &H00000020???

'%NOTIFY_DEVICE_BITS              (NOTIFY_DEVICE_ALLDEVICES | NOTIFY_DEVICE_ARRIVALREMOVAL | NOTIFY_DEVICE_PROPERTYCHANGED)
%NOTIFY_DEVICE_BITS = %NOTIFY_DEVICE_ALLDEVICES OR %NOTIFY_DEVICE_ARRIVALREMOVAL OR %NOTIFY_DEVICE_PROPERTYCHANGED

'#endif /* WINVER >= _WIN32_WINNT_WIN7 */

%DBTF_RESOURCE   = &H00000001???    ' // network resource
%DBTF_XPORT      = &H00000002???    ' // new transport coming or going
%DBTF_SLOWNET    = &H00000004???    ' // new incoming transport is slow
                                    ' // (dbcn_resource undefined for now)

%DBT_VPOWERDAPI  = &H8100??         ' // VPOWERD API for Win95

'/*
' *  User-defined message types all use wParam = = &HFFFF with the
' *  lParam a pointer to the structure below.
' *
' *  dbud_dbh - DEV_BROADCAST_HEADER must be filled in as usual.
' *
' *  dbud_szName contains a case-sensitive ASCIIZ name which names the
' *  message.  The message name consists of the vendor name, a backslash,
' *  then arbitrary user-defined ASCIIZ text.  For example:
' *
' *      "WidgetWare\QueryScannerShutdown"
' *      "WidgetWare\Video Q39S\AdapterReady"
' *
' *  After the ASCIIZ name, arbitrary information may be provided.
' *  Make sure that dbud_dbh.dbch_size is big enough to encompass
' *  all the data.  And remember that nothing in the structure may
' *  contain pointers.
' */

%DBT_USERDEFINED = &HFFFF??

'struct _DEV_BROADCAST_USERDEFINED { /* */
'    struct _DEV_BROADCAST_HDR dbud_dbh;
'    char        dbud_szName[1];     /* ASCIIZ name */
'/*  BYTE        dbud_rgbUserDefined[];*/ /* User-defined contents */
'};

TYPE DEV_BROADCAST_USERDEFINED
   dbh AS DEV_BROADCAST_HDR    ' struct _DEV_BROADCAST_HDR dbud_dbh;
   dbud_szName AS ASCIIZ * 1   ' char        dbud_szName[1];     /* ASCIIZ name */
'/*  BYTE        dbud_rgbUserDefined[];*/ /* User-defined contents */
END TYPE
