' ########################################################################################
' Microsoft Windows
' File: Nb30.inc
' Contents: Definitions for portable NetBIOS 3.0 support.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NB30_INC = 1

'/****************************************************************
' *                                                              *
' *              Data structure templates                        *
' *                                                              *
' ****************************************************************/

%NCBNAMSZ         = 16  ' absolute length of a net name
%MAX_LANA         = 254  ' lana's in range 0 to MAX_LANA

'/*
' * Network Control Block
' */

' // Size = 64 bytes
TYPE NCB BYTE
   ncb_command     AS BYTE                  ' UCHAR   ncb_command;            /* command code                   */
   ncb_retcode     AS BYTE                  ' UCHAR   ncb_retcode;            /* return code                    */
   ncb_lsn         AS BYTE                  ' UCHAR   ncb_lsn;                /* local session number           */
   ncb_num         AS BYTE                  ' UCHAR   ncb_num;                /* number of our network name     */
   ncb_buffer      AS BYTE PTR              ' PUCHAR  ncb_buffer;             /* address of message buffer      */
   ncb_length      AS WORD                  ' WORD    ncb_length;             /* size of message buffer         */
   ncb_callname    AS STRING * %NCBNAMSZ    ' UCHAR   ncb_callname[NCBNAMSZ]; /* blank-padded name of remote    */
   ncb_name        AS STRING * %NCBNAMSZ    ' UCHAR   ncb_name[NCBNAMSZ];     /* our blank-padded netname       */
   ncb_rto         AS BYTE                  ' UCHAR   ncb_rto;                /* rcv timeout/retry count        */
   ncb_sto         AS BYTE                  ' UCHAR   ncb_sto;                /* send timeout/sys timeout       */
   ncb_post        AS DWORD                 ' void (CALLBACK *ncb_post)( struct _NCB * ); /* POST routine address        */
   ncb_lana_num    AS BYTE                  ' UCHAR   ncb_lana_num;           /* lana (adapter) number          */
   ncb_cmd_cplt    AS BYTE                  ' UCHAR   ncb_cmd_cplt;           /* 0xff => commmand pending       */
'#IF %DEF(%WIN64)
'   ncb_reserve(17) AS BYTE                  ' UCHAR   ncb_reserve[18];        /* reserved, used by BIOS         */
'#ELSE
   ncb_reserve(9)  AS BYTE                  ' UCHAR   ncb_reserve[10];        /* reserved, used by BIOS         */
'#ENDIF
   ncb_event       AS DWORD                 ' HANDLE  ncb_event;              /* HANDLE to Win32 event which    */
                                            '                                 /* will be set to the signalled   */
                                            '                                 /* state when an ASYNCH command completes  */
END TYPE

'/*
' *  Structure returned to the NCB command NCBASTAT is ADAPTER_STATUS followed
' *  by an array of NAME_BUFFER structures.
' */

UNION ADAPTER_STATUS_ADAPTER_ADDRESS_UNION
   adapter_address(5) AS BYTE   ' UCHAR adapter_address[6]
   ' // For compatibiloity with PB includes
   adapter_address    AS STRING * 6
END UNION

' // Size = 60 bytes
TYPE ADAPTER_STATUS BYTE
   ADAPTER_STATUS_ADAPTER_ADDRESS_UNION
   rev_major          AS BYTE   ' UCHAR
   reserved0          AS BYTE   ' UCHAR
   adapter_type       AS BYTE   ' UCHAR
   rev_minor          AS BYTE   ' UCHAR
   duration           AS WORD   ' WORD
   frmr_recv          AS WORD   ' WORD
   frmr_xmit          AS WORD   ' WORD
   iframe_recv_err    AS WORD   ' WORD
   xmit_aborts        AS WORD   ' WORD
   xmit_success       AS DWORD  ' DWORD
   recv_success       AS DWORD  ' DWORD
   iframe_xmit_err    AS WORD   ' WORD
   recv_buff_unavail  AS WORD   ' WORD
   t1_timeouts        AS WORD   ' WORD
   ti_timeouts        AS WORD   ' WORD
   reserved1          AS DWORD  ' DWORD
   free_ncbs          AS WORD   ' WORD
   max_cfg_ncbs       AS WORD   ' WORD
   max_ncbs           AS WORD   ' WORD
   xmit_buf_unavail   AS WORD   ' WORD
   max_dgram_size     AS WORD   ' WORD
   pending_sess       AS WORD   ' WORD
   max_cfg_sess       AS WORD   ' WORD
   max_sess           AS WORD   ' WORD
   max_sess_pkt_size  AS WORD   ' WORD
   name_count         AS WORD   ' WORD
END TYPE

UNION NAME_BUFFER_NAME_UNION BYTE
   name       AS STRING * %NCBNAMSZ   ' UCHAR   name[NCBNAMSZ]
   ' // For compatibility with PB includes
   sname      AS STRING * %NCBNAMSZ   ' UCHAR   name[NCBNAMSZ]
END UNION
' // Size = 18 bytes
TYPE NAME_BUFFER BYTE
   NAME_BUFFER_NAME_UNION
   name_num   AS BYTE                 ' UCHAR   name_num
   name_flags AS BYTE                 ' UCHAR   name_flags
END TYPE

'//  values for name_flags bits.

%NAME_FLAGS_MASK  = &H87

%GROUP_NAME       = &H80
%UNIQUE_NAME      = &H00

%REGISTERING      = &H00
%REGISTERED       = &H04
%DEREGISTERED     = &H05
%DUPLICATE        = &H06
%DUPLICATE_DEREG  = &H07

'/*
' *  Structure returned to the NCB command NCBSSTAT is SESSION_HEADER followed
' *  by an array of SESSION_BUFFER structures. If the NCB_NAME starts with an
' *  asterisk then an array of these structures is returned containing the
' *  status for all names.
' */

' // Size = 4 bytes
TYPE SESSION_HEADER BYTE
   sess_name           AS BYTE   ' UCHAR
   num_sess            AS BYTE   ' UCHAR
   rcv_dg_outstanding  AS BYTE   ' UCHAR
   rcv_any_outstanding AS BYTE   ' UCHAR
END TYPE

' // Size = 36 bytes
TYPE SESSION_BUFFER BYTE
   lsn               AS BYTE                 ' UCHAR lsn
   state             AS BYTE                 ' UCHAR state
   local_name        AS STRING * %NCBNAMSZ   ' UCHAR   local_name[NCBNAMSZ]
   remote_name       AS STRING * %NCBNAMSZ   ' UCHAR   remote_name[NCBNAMSZ]
   rcvs_outstanding  AS BYTE                 ' UCHAR rcvs_outstanding
   sends_outstanding AS BYTE                 ' UCHAR sends_outstanding
END TYPE

'//  Values for state

%LISTEN_OUTSTANDING   = &H01
%CALL_PENDING         = &H02
%SESSION_ESTABLISHED  = &H03
%HANGUP_PENDING       = &H04
%HANGUP_COMPLETE      = &H05
%SESSION_ABORTED      = &H06

'/*
' *  Structure returned to the NCB command NCBENUM.
' *
' *  On a system containing lana's 0, 2 and 3, a structure with
' *  length =3, lana[0]=0, lana[1]=2 and lana[2]=3 will be returned.
' */

' // Size = 256 bytes
TYPE LANA_ENUM BYTE
   length AS BYTE            ' UCHAR   length
   lana(%MAX_LANA) AS BYTE   ' UCHAR   lana[MAX_LANA+1]
END TYPE

'/*
' *  Structure returned to the NCB command NCBFINDNAME is  followed
' *  by an array of FIND_NAME_BUFFER structures.
' */

' // Size = 4 bytes
TYPE FIND_NAME_HEADER BYTE
   node_count   AS WORD   ' WORD   ' // Note: In the PB includes it is wrongly declared as DWORD
   reserved     AS BYTE   ' UCHAR
   unique_group AS BYTE   ' UCHAR
END TYPE

UNION FIND_NAME_BUFFER_UNION
   destination_addr(5) AS BYTE   ' UCHAR destination_addr[6]
   source_addr(5)      AS BYTE   ' UCHAR source_addr[6]
   routing_info(17)    AS BYTE   ' UCHAR routing_info[18]
   ' // For compatibility with the PB includes
   destination_addr    AS STRING * 6
   source_addr         AS STRING * 6
   routing_info        AS STRING * 18
END UNION
' // Size = 33 bytes
TYPE FIND_NAME_BUFFER BYTE
   length              AS BYTE   ' UCHAR length
   access_control      AS BYTE   ' UCHAR access_control
   frame_control       AS BYTE   ' UCHAR frame_control
   FIND_NAME_BUFFER_UNION
END TYPE

'/*
' *  Structure provided with NCBACTION. The purpose of NCBACTION is to provide
' *  transport specific extensions to netbios.
' */

' // Size = 8 bytes
TYPE ACTION_HEADER BYTE
   transport_id AS DWORD   ' ULONG
   action_code  AS WORD    ' USHORT
   reserved     AS WORD    ' USHORT
END TYPE

'//  Values for transport_id

'#define ALL_TRANSPORTS  "M\0\0\0"
'#define MS_NBF          "MNBF"

$ALL_TRANSPORTS = "M" & CHR$(0,0,0)   ' // Declared as $ALL_TRANSPORTS = "M\0\0\0" in the PB includes
$MS_NBF         = "MNBF"


'/****************************************************************
' *                                                              *
' *              Special values and constants                    *
' *                                                              *
' ****************************************************************/

'/*
' *      NCB Command codes
' */

%NCBCALL          = &H10  ' NCB CALL
%NCBLISTEN        = &H11  ' NCB LISTEN
%NCBHANGUP        = &H12  ' NCB HANG UP
%NCBSEND          = &H14  ' NCB SEND
%NCBRECV          = &H15  ' NCB RECEIVE
%NCBRECVANY       = &H16  ' NCB RECEIVE ANY
%NCBCHAINSEND     = &H17  ' NCB CHAIN SEND
%NCBDGSEND        = &H20  ' NCB SEND DATAGRAM
%NCBDGRECV        = &H21  ' NCB RECEIVE DATAGRAM
%NCBDGSENDBC      = &H22  ' NCB SEND BROADCAST DATAGRAM
%NCBDGRECVBC      = &H23  ' NCB RECEIVE BROADCAST DATAGRAM
%NCBADDNAME       = &H30  ' NCB ADD NAME
%NCBDELNAME       = &H31  ' NCB DELETE NAME
%NCBRESET         = &H32  ' NCB RESET
%NCBASTAT         = &H33  ' NCB ADAPTER STATUS
%NCBSSTAT         = &H34  ' NCB SESSION STATUS
%NCBCANCEL        = &H35  ' NCB CANCEL
%NCBADDGRNAME     = &H36  ' NCB ADD GROUP NAME
%NCBENUM          = &H37  ' NCB ENUMERATE LANA NUMBERS
%NCBUNLINK        = &H70  ' NCB UNLINK
%NCBSENDNA        = &H71  ' NCB SEND NO ACK
%NCBCHAINSENDNA   = &H72  ' NCB CHAIN SEND NO ACK
%NCBLANSTALERT    = &H73  ' NCB LAN STATUS ALERT
%NCBACTION        = &H77  ' NCB ACTION
%NCBFINDNAME      = &H78  ' NCB FIND NAME
%NCBTRACE         = &H79  ' NCB TRACE

'#define ASYNCH          0x80            /* high bit set == asynchronous       */
%ASYNCH           = &H80  ' high bit set == asynchronous

'/*
' *      NCB Return codes
' */

%NRC_GOODRET      = &H00  ' good return
                               ' also returned when ASYNCH request accepted
%NRC_BUFLEN       = &H01  ' illegal buffer length
%NRC_ILLCMD       = &H03  ' illegal command
%NRC_CMDTMO       = &H05  ' command timed out
%NRC_INCOMP       = &H06  ' message incomplete, issue another command
%NRC_BADDR        = &H07  ' illegal buffer address
%NRC_SNUMOUT      = &H08  ' session number out of range
%NRC_NORES        = &H09  ' no resource available
%NRC_SCLOSED      = &H0A  ' session closed
%NRC_CMDCAN       = &H0B  ' command cancelled
%NRC_DUPNAME      = &H0D  ' duplicate name
%NRC_NAMTFUL      = &H0E  ' name table full
%NRC_ACTSES       = &H0F  ' no deletions, name has active sessions
%NRC_LOCTFUL      = &H11  ' local session table full
%NRC_REMTFUL      = &H12  ' remote session table full
%NRC_ILLNN        = &H13  ' illegal name number
%NRC_NOCALL       = &H14  ' no callname
%NRC_NOWILD       = &H15  ' cannot put  in NCB_NAME
%NRC_INUSE        = &H16  ' name in use on remote adapter
%NRC_NAMERR       = &H17  ' name deleted
%NRC_SABORT       = &H18  ' session ended abnormally
%NRC_NAMCONF      = &H19  ' name conflict detected
%NRC_IFBUSY       = &H21  ' interface busy, IRET before retrying
%NRC_TOOMANY      = &H22  ' too many commands outstanding, retry later
%NRC_BRIDGE       = &H23  ' ncb_lana_num field invalid
%NRC_CANOCCR      = &H24  ' command completed while cancel occurring
%NRC_CANCEL       = &H26  ' command not valid to cancel
%NRC_DUPENV       = &H30  ' name defined by anther local process
%NRC_ENVNOTDEF    = &H34  ' environment undefined. RESET required
%NRC_OSRESNOTAV   = &H35  ' required OS resources exhausted
%NRC_MAXAPPS      = &H36  ' max number of applications exceeded
%NRC_NOSAPS       = &H37  ' no saps available for netbios
%NRC_NORESOURCES  = &H38  ' requested resources are not available
%NRC_INVADDRESS   = &H39  ' invalid ncb address or length > segment
%NRC_INVDDID      = &H3B  ' invalid NCB DDID
%NRC_LOCKFAIL     = &H3C  ' lock of user area failed
%NRC_OPENERR      = &H3F  ' NETBIOS not loaded
%NRC_SYSTEM       = &H40  ' system error

%NRC_PENDING      = &HFF  ' asynchronous command is not yet finished

'/****************************************************************
' *                                                              *
' *              main user entry point for NetBIOS 3.0           *
' *                                                              *
' * Usage: result = Netbios( pncb );                             *
' ****************************************************************/

DECLARE FUNCTION Netbios IMPORT "NETAPI32.DLL" ALIAS "Netbios" ( _
   BYREF pncb AS NCB _                                  ' __out PNCB pncb
 ) AS BYTE                                              ' UCHAR

'/****************************************************************
' *                                                              *
' *              Prefix for callback routines                    *
' *                                                              *
' * Usage in a declaration: NCB_POST MyPostRoutine( PNCB pncb ); *
' ****************************************************************/

'#define NCB_POST void CALLBACK
