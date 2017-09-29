' ########################################################################################
' Microsoft Windows
' File: WinSmCrd.inc
' Contents: Smart Card class/port IOCTL codes. This file is required for all code user
' mode and kernel mode, using Smart Card IOCTL's, defines, data structures
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSMCRD_INC = 1

'#ifdef _WINSCARD_H_
'typedef DWORD ULONG;
'typedef WORD UWORD;
'typedef BYTE UCHAR;
'#else
'typedef ULONG DWORD;
'// typedef UWORD WORD;
'typedef UCHAR BYTE;
'#endif

%FILE_DEVICE_SMARTCARD = &H00000031???

'//
'// Various constants
'//

%SCARD_ATR_LENGTH = 33  ' // ISO 7816-3 spec.

'//
'///////////////////////////////////////////////////////////////////////////////
'//
'//  Protocol Flag definitions
'//

%SCARD_PROTOCOL_UNDEFINED    = &H00000000??? ' // There is no active protocol.
%SCARD_PROTOCOL_T0           = &H00000001??? ' // T=0 is the active protocol.
%SCARD_PROTOCOL_T1           = &H00000002??? ' // T=1 is the active protocol.
%SCARD_PROTOCOL_RAW          = &H00010000??? ' // Raw is the active protocol.
'//
'// This is the mask of ISO defined transmission protocols
'//
%SCARD_PROTOCOL_Tx           = %SCARD_PROTOCOL_T0 OR %SCARD_PROTOCOL_T1
'//
'// Use the default transmission parameters / card clock freq.
'//
%SCARD_PROTOCOL_DEFAULT      = &H80000000???
'//
'// Use optimal transmission parameters / card clock freq.
'// Since using the optimal parameters is the default case no bit is defined to be 1
'//
%SCARD_PROTOCOL_OPTIMAL      = &H00000000???


'//
'// Ioctl parameters 1 for IOCTL_SMARTCARD_POWER
'//
%SCARD_POWER_DOWN = 0         ' // Power down the card.
%SCARD_COLD_RESET = 1         ' // Cycle power and reset the card.
%SCARD_WARM_RESET = 2         ' // Force a reset on the card.

'//
'///////////////////////////////////////////////////////////////////////////////
'//
'//  Reader Action IOCTLs
'//

'#define SCARD_CTL_CODE(code)        CTL_CODE(FILE_DEVICE_SMARTCARD, \
'                                            (code), \
'                                            METHOD_BUFFERED, \
'                                            FILE_ANY_ACCESS)

MACRO SCARD_CTL_CODE(code) = CTL_CODE(%FILE_DEVICE_SMARTCARD, code, %METHOD_BUFFERED, %FILE_ANY_ACCESS)

%IOCTL_SMARTCARD_POWER           = &H00310004???   ' SCARD_CTL_CODE( 1)
%IOCTL_SMARTCARD_GET_ATTRIBUTE   = &H00310008???   ' SCARD_CTL_CODE( 2)
%IOCTL_SMARTCARD_SET_ATTRIBUTE   = &H0031000C???   ' SCARD_CTL_CODE( 3)
%IOCTL_SMARTCARD_CONFISCATE      = &H00310010???   ' SCARD_CTL_CODE( 4)
%IOCTL_SMARTCARD_TRANSMIT        = &H00310014???   ' SCARD_CTL_CODE( 5)
%IOCTL_SMARTCARD_EJECT           = &H00310018???   ' SCARD_CTL_CODE( 6)
%IOCTL_SMARTCARD_SWALLOW         = &H0031001C???   ' SCARD_CTL_CODE( 7)
'// #define IOCTL_SMARTCARD_READ            SCARD_CTL_CODE( 8) obsolete
'// #define IOCTL_SMARTCARD_WRITE           SCARD_CTL_CODE( 9) obsolete
%IOCTL_SMARTCARD_IS_PRESENT      = &H00310028???   ' SCARD_CTL_CODE(10)
%IOCTL_SMARTCARD_IS_ABSENT       = &H0031002C???   ' SCARD_CTL_CODE(11)
%IOCTL_SMARTCARD_SET_PROTOCOL    = &H00310030???   ' SCARD_CTL_CODE(12)
%IOCTL_SMARTCARD_GET_STATE       = &H00310038???   ' SCARD_CTL_CODE(14)
%IOCTL_SMARTCARD_GET_LAST_ERROR  = &H0031003C???   ' SCARD_CTL_CODE(15)
%IOCTL_SMARTCARD_GET_PERF_CNTR   = &H00310040???   ' SCARD_CTL_CODE(16)

'//
'///////////////////////////////////////////////////////////////////////////////
'//
'// Tags for requesting card and reader attributes
'//

%MAXIMUM_ATTR_STRING_LENGTH = 32  ' // Nothing bigger than this from getAttr
%MAXIMUM_SMARTCARD_READERS  = 10  ' // Limit the readers on the system

'#define SCARD_ATTR_VALUE(Class, Tag) ((((ULONG)(Class)) << 16) | ((ULONG)(Tag)))

FUNCTION SCARD_ATTR_VALUE (BYVAL nClass AS DWORD, BYVAL nTag AS DWORD) AS DWORD
   SHIFT LEFT nClass, 16
   FUNCTION = nClass OR nTag
END FUNCTION

%SCARD_CLASS_VENDOR_INFO     = 1  ' // Vendor information definitions
%SCARD_CLASS_COMMUNICATIONS  = 2  ' // Communication definitions
%SCARD_CLASS_PROTOCOL        = 3  ' // Protocol definitions
%SCARD_CLASS_POWER_MGMT      = 4  ' // Power Management definitions
%SCARD_CLASS_SECURITY        = 5  ' // Security Assurance definitions
%SCARD_CLASS_MECHANICAL      = 6  ' // Mechanical characteristic definitions
%SCARD_CLASS_VENDOR_DEFINED  = 7  ' // Vendor specific definitions
%SCARD_CLASS_IFD_PROTOCOL    = 8  ' // Interface Device Protocol options
%SCARD_CLASS_ICC_STATE       = 9  ' // ICC State specific definitions
%SCARD_CLASS_PERF       = &H7ffe  ' // performace counters
%SCARD_CLASS_SYSTEM     = &H7fff  ' // System-specific definitions

%SCARD_ATTR_VENDOR_NAME              = &H00010100???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_INFO, 0x0100)
%SCARD_ATTR_VENDOR_IFD_TYPE          = &H00010101???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_INFO, 0x0101)
%SCARD_ATTR_VENDOR_IFD_VERSION       = &H00010102???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_INFO, 0x0102)
%SCARD_ATTR_VENDOR_IFD_SERIAL_NO     = &H00010103???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_INFO, 0x0103)
%SCARD_ATTR_CHANNEL_ID               = &H00020110???   ' SCARD_ATTR_VALUE(SCARD_CLASS_COMMUNICATIONS, 0x0110)
%SCARD_ATTR_PROTOCOL_TYPES           = &H00030120???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0120)
'// #define SCARD_ATTR_ASYNC_PROTOCOL_TYPES SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0120)
%SCARD_ATTR_DEFAULT_CLK              = &H00030121???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0121)
%SCARD_ATTR_MAX_CLK                  = &H00030122???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0122)
%SCARD_ATTR_DEFAULT_DATA_RATE        = &H00030123???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0123)
%SCARD_ATTR_MAX_DATA_RATE            = &H00030124???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0124)
%SCARD_ATTR_MAX_IFSD                 = &H00030125???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0125)
'// #define SCARD_ATTR_SYNC_PROTOCOL_TYPES SCARD_ATTR_VALUE(SCARD_CLASS_PROTOCOL, 0x0126)
%SCARD_ATTR_POWER_MGMT_SUPPORT       = &H00040131???   ' SCARD_ATTR_VALUE(SCARD_CLASS_POWER_MGMT, 0x0131)
%SCARD_ATTR_USER_TO_CARD_AUTH_DEVICE = &H00050140???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SECURITY, 0x0140)
%SCARD_ATTR_USER_AUTH_INPUT_DEVICE   = &H00050142???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SECURITY, 0x0142)
%SCARD_ATTR_CHARACTERISTICS          = &H00060150???   ' SCARD_ATTR_VALUE(SCARD_CLASS_MECHANICAL, 0x0150)

%SCARD_ATTR_CURRENT_PROTOCOL_TYPE  = &H00080201???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0201)
%SCARD_ATTR_CURRENT_CLK            = &H00080202???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0202)
%SCARD_ATTR_CURRENT_F              = &H00080203???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0203)
%SCARD_ATTR_CURRENT_D              = &H00080204???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0204)
%SCARD_ATTR_CURRENT_N              = &H00080205???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0205)
%SCARD_ATTR_CURRENT_W              = &H00080206???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0206)
%SCARD_ATTR_CURRENT_IFSC           = &H00080207???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0207)
%SCARD_ATTR_CURRENT_IFSD           = &H00080208???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0208)
%SCARD_ATTR_CURRENT_BWT            = &H00080209???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x0209)
%SCARD_ATTR_CURRENT_CWT            = &H0008020a???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x020a)
%SCARD_ATTR_CURRENT_EBC_ENCODING   = &H0008020b???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x020b)
%SCARD_ATTR_EXTENDED_BWT           = &H0008020c???   ' SCARD_ATTR_VALUE(SCARD_CLASS_IFD_PROTOCOL, 0x020c)

%SCARD_ATTR_ICC_PRESENCE           = &H00090300???   ' SCARD_ATTR_VALUE(SCARD_CLASS_ICC_STATE, 0x0300)
%SCARD_ATTR_ICC_INTERFACE_STATUS   = &H00090301???   ' SCARD_ATTR_VALUE(SCARD_CLASS_ICC_STATE, 0x0301)
%SCARD_ATTR_CURRENT_IO_STATE       = &H00090302???   ' SCARD_ATTR_VALUE(SCARD_CLASS_ICC_STATE, 0x0302)
%SCARD_ATTR_ATR_STRING             = &H00090303???   ' SCARD_ATTR_VALUE(SCARD_CLASS_ICC_STATE, 0x0303)
%SCARD_ATTR_ICC_TYPE_PER_ATR       = &H00090304???   ' SCARD_ATTR_VALUE(SCARD_CLASS_ICC_STATE, 0x0304)

%SCARD_ATTR_ESC_RESET              = &HFFFFA000???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_DEFINED, 0xA000)
%SCARD_ATTR_ESC_CANCEL             = &HFFFFA003???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_DEFINED, 0xA003)
%SCARD_ATTR_ESC_AUTHREQUEST        = &HFFFFA005???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_DEFINED, 0xA005)
%SCARD_ATTR_MAXINPUT               = &HFFFFA007???   ' SCARD_ATTR_VALUE(SCARD_CLASS_VENDOR_DEFINED, 0xA007)

%SCARD_ATTR_DEVICE_UNIT            = &H7FFF0001???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0001)
%SCARD_ATTR_DEVICE_IN_USE          = &H7FFF0002???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0002)
%SCARD_ATTR_DEVICE_FRIENDLY_NAME_A = &H7FFF0003???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0003)
%SCARD_ATTR_DEVICE_SYSTEM_NAME_A   = &H7FFF0004???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0004)
%SCARD_ATTR_DEVICE_FRIENDLY_NAME_W = &H7FFF0005???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0005)
%SCARD_ATTR_DEVICE_SYSTEM_NAME_W   = &H7FFF0006???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0006)
%SCARD_ATTR_SUPRESS_T1_IFS_REQUEST = &H7FFF0007???   ' SCARD_ATTR_VALUE(SCARD_CLASS_SYSTEM, 0x0007)

#IF %DEF(%UNICODE)
   %SCARD_ATTR_DEVICE_FRIENDLY_NAME = %SCARD_ATTR_DEVICE_FRIENDLY_NAME_W
   %SCARD_ATTR_DEVICE_SYSTEM_NAME   = %SCARD_ATTR_DEVICE_SYSTEM_NAME_W
#ELSE
   %SCARD_ATTR_DEVICE_FRIENDLY_NAME = %SCARD_ATTR_DEVICE_FRIENDLY_NAME_A
   %SCARD_ATTR_DEVICE_SYSTEM_NAME   = %SCARD_ATTR_DEVICE_SYSTEM_NAME_A
#ENDIF

%SCARD_PERF_NUM_TRANSMISSIONS      = &H7FFE0001???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PERF, 0x0001)
%SCARD_PERF_BYTES_TRANSMITTED      = &H7FFE0002???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PERF, 0x0002)
%SCARD_PERF_TRANSMISSION_TIME      = &H7FFE0003???   ' SCARD_ATTR_VALUE(SCARD_CLASS_PERF, 0x0003)


'//
'// T=0 Protocol Defines
'//

%SCARD_T0_HEADER_LENGTH = 7
%SCARD_T0_CMD_LENGTH    = 5


'//
'// T=1 Protocol Defines
'//

%SCARD_T1_PROLOGUE_LENGTH = 3
%SCARD_T1_EPILOGUE_LENGTH = 2
%SCARD_T1_MAX_IFS         = 254


'//
'///////////////////////////////////////////////////////////////////////////////
'//
'//  Reader states
'//

%SCARD_UNKNOWN    = 0  ' // This value implies the driver is unaware
                       ' // of the current state of the reader.
%SCARD_ABSENT     = 1  ' // This value implies there is no card in
                       ' // the reader.
%SCARD_PRESENT    = 2  ' // This value implies there is a card is
                       ' // present in the reader, but that it has
                       ' // not been moved into position for use.
%SCARD_SWALLOWED  = 3  ' // This value implies there is a card in the
                       ' // reader in position for use.  The card is
                       ' // not powered.
%SCARD_POWERED    = 4  ' // This value implies there is power is
                       ' // being provided to the card, but the
                       ' // Reader Driver is unaware of the mode of
                       ' // the card.
%SCARD_NEGOTIABLE = 5  ' // This value implies the card has been
                       ' // reset and is awaiting PTS negotiation.
%SCARD_SPECIFIC   = 6  ' // This value implies the card has been
                       ' // reset and specific communication
                       ' // protocols have been established.

'////////////////////////////////////////////////////////////////////////////////
'//
'//  I/O Services
'//
'//      The following services provide access to the I/O capabilities of the
'//      reader drivers.  Services of the Smart Card are requested by placing the
'//      following structure into the protocol buffer:
'//

' // Size = 8 bytes
TYPE SCARD_IO_REQUEST DWORD
   dwProtocol  AS DWORD   ' DWORD
   cbPciLength AS DWORD   ' DWORD
END TYPE

'//
'// T=0 protocol services.
'//

' // Size = 5 bytes
TYPE SCARD_T0_COMMAND BYTE
   bCla AS BYTE  ' BYTE // The instruction class
   bIns AS BYTE  ' BYTE // The instruction code within the instruction class
   bP1  AS BYTE  ' BYTE
   bP2  AS BYTE  ' BYTE // Parameters to the instruction
   bP3  AS BYTE  ' BYTE // Size of I/O Transfer
END TYPE

' // Size = 5 bytes
UNION SCARD_T0_REQUEST_UNION
   CmdBytes     AS SCARD_T0_COMMAND   ' SCARD_T0_COMMAND
   rgbHeader(4) AS BYTE               ' BYTE[5]
END UNION

' // Size = 16 bytes
TYPE SCARD_T0_REQUEST   ' Must be DWORD aligned
   ioRequest   AS SCARD_IO_REQUEST   ' SCARD_IO_REQUEST
   bSw1        AS BYTE               ' BYTE
   bSw2        AS BYTE               ' BYTE
   SCARD_T0_REQUEST_UNION
   alignment__ AS BYTE
END TYPE

'//
'//  T=1 Protocol Services
'//

' // Size = 8 bytes
TYPE SCARD_T1_REQUEST DWORD
   ioRequest AS SCARD_IO_REQUEST
END TYPE

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Driver attribute flags
'//

%SCARD_READER_SWALLOWS      = &H00000001??? ' // Reader has a card swallowing
                                            ' // mechanism.
%SCARD_READER_EJECTS        = &H00000002??? ' // Reader has a card ejection
                                            ' // mechanism.
%SCARD_READER_CONFISCATES   = &H00000004??? ' // Reader has a card capture
                                            ' // mechanism.

'//
'///////////////////////////////////////////////////////////////////////////////
'//
'// Type of reader
'//
%SCARD_READER_TYPE_SERIAL    = &H01
%SCARD_READER_TYPE_PARALELL  = &H02
%SCARD_READER_TYPE_KEYBOARD  = &H04
%SCARD_READER_TYPE_SCSI      = &H08
%SCARD_READER_TYPE_IDE       = &H10
%SCARD_READER_TYPE_USB       = &H20
%SCARD_READER_TYPE_PCMCIA    = &H40
%SCARD_READER_TYPE_VENDOR    = &HF0
