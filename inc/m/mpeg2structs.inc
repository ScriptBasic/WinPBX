' ########################################################################################
' Microsoft Windows
' File: mpeg2structs.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEG2STRUCTS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "mpeg2bits.inc"

'#pragma pack(push)
'#pragma pack(1)

' // Size = 2 bytes
TYPE PID_BITS_MIDL BYTE
   Bits AS WORD
END TYPE

' // Size = 2 bytes
TYPE MPEG_HEADER_BITS_MIDL BYTE
   Bits AS WORD
END TYPE

' // Size = 1 byte
TYPE MPEG_HEADER_VERSION_BITS_MIDL BYTE
   Bits AS BYTE
END TYPE

'#pragma pack(pop)

'#pragma pack(push)

'#pragma pack(1)
'typedef WORD PID;
'typedef BYTE TID;
'typedef WORD TEID;
'typedef UINT ClientKey;

' enum MPEG_CURRENT_NEXT_BIT
%MPEG_SECTION_IS_NEXT    = 0
%MPEG_SECTION_IS_CURRENT = 1

' // Size = 4 bytes
TYPE TID_EXTENSION BYTE
   wTidExt AS WORD
   wCount  AS WORD
END TYPE

' // Size = 2 bytes
UNION SECTION_HEADER_UNION BYTE
   S AS MPEG_HEADER_BITS_MIDL
   W AS WORD
END UNION

' // Size = 4 bytes
TYPE SECTION BYTE
   TableId        AS BYTE   ' TID
   Header         AS SECTION_HEADER_UNION
   SectionData(0) AS BYTE   ' BYTE[1]
END TYPE

' // Size = 1 byte
UNION LONG_SECTION_VERSION_UNION BYTE
   S AS MPEG_HEADER_VERSION_BITS_MIDL
   B AS BYTE
END UNION

' // Size = 9 bytes
TYPE LONG_SECTION BYTE
   TableId           AS BYTE   ' TID
   Header            AS SECTION_HEADER_UNION
   TableIdExtension  AS WORD   ' TEID
   Version           AS LONG_SECTION_VERSION_UNION
   SectionNumber     AS BYTE
   LastSectionNumber AS BYTE
   RemainingData(0)  AS BYTE
END TYPE

' // Size = 21 bytes
TYPE DSMCC_SECTION BYTE
   TableId               AS BYTE   ' TID
   Header                AS SECTION_HEADER_UNION
   TableIdExtension      AS WORD   ' TEID
   Version               AS LONG_SECTION_VERSION_UNION
   SectionNumber         AS BYTE
   LastSectionNumber     AS BYTE
   ProtocolDiscriminator AS BYTE
   DsmccType             AS BYTE
   MessageId             AS WORD
   TransactionId         AS DWORD
   Reserved              AS BYTE
   AdaptationLength      AS BYTE
   MessageLength         AS WORD
   RemainingData(0)      AS BYTE
END TYPE

' // Size = 8 bytes
TYPE MPEG_RQST_PACKET BYTE
   dwLength AS DWORD
   pSection AS SECTION PTR
END TYPE

' // Size = 6 bytes
TYPE MPEG_PACKET_LIST BYTE
   wPacketCount  AS WORD
   PacketList(0) AS MPEG_RQST_PACKET PTR
END TYPE

' // Size = 45 bytes
TYPE DSMCC_FILTER_OPTIONS BYTE
   fSpecifyProtocol       AS LONG    ' BOOL
   Protocol               AS BYTE    ' BYTE
   fSpecifyType           AS LONG    ' BOOL
   Type                   AS BYTE    ' BYTE
   fSpecifyMessageId      AS LONG    ' BOOL
   MessageId              AS WORD    ' WORD
   fSpecifyTransactionId  AS LONG    ' BOOL
   fUseTrxIdMessageIdMask AS LONG    ' BOOL
   TransactionId          AS DWORD   ' DWORD
   fSpecifyModuleVersion  AS LONG    ' BOOL
   ModuleVersion          AS BYTE    ' BYTE
   fSpecifyBlockNumber    AS LONG    ' BOOL
   BlockNumber            AS WORD    ' WORD
   fGetModuleCall         AS LONG    ' BOOL
   NumberOfBlocksInModule AS WORD    ' WORD
END TYPE

' // Size = 8 bytes
TYPE ATSC_FILTER_OPTIONS BYTE
   fSpecifyEtmId AS LONG    ' BOOL
   EtmId         AS DWORD   ' DWORD
END TYPE

' // Size = 5 bytes
TYPE DVB_EIT_FILTER_OPTIONS BYTE
   fSpecifySegment AS LONG   ' BOOL
   bSegment        AS BYTE   ' BYTE
END TYPE

' // Size = 124 bytes
TYPE MPEG2_FILTER BYTE
   bVersionNumber           AS BYTE                   ' BYTE
   wFilterSize              AS WORD                   ' WORD
   fUseRawFilteringBits     AS LONG                   ' BOOL
   Filter(15)               AS BYTE                   ' BYTE[16]
   Mask(15)                 AS BYTE                   ' BYTE[16]
   fSpecifyTableIdExtension AS LONG                   ' BOOL
   TableIdExtension         AS WORD                   ' WORD
   fSpecifyVersion          AS LONG                   ' BOOL
   Version                  AS BYTE                   ' BYTE
   fSpecifySectionNumber    AS LONG                   ' BOOL
   SectionNumber            AS BYTE                   ' BYTE
   fSpecifyCurrentNext      AS LONG                   ' BOOL
   fNext                    AS LONG                   ' BOOL
   fSpecifyDsmccOptions     AS LONG                   ' BOOL
   Dsmcc                    AS DSMCC_FILTER_OPTIONS
   fSpecifyAtscOptions      AS LONG                   ' BOOL
   Atsc                     AS ATSC_FILTER_OPTIONS
END TYPE

' // Size = 124 bytes
TYPE MPEG2_FILTER2_UNION_STRUCT BYTE
   bVersionNumber           AS BYTE   ' BYTE
   wFilterSize              AS WORD   ' WORD
   fUseRawFilteringBits     AS LONG   ' BOOL
   Filter(15)               AS BYTE   ' BYTE[16]
   Mask(15)                 AS BYTE   ' BYTE[16]
   fSpecifyTableIdExtension AS LONG   ' BOOL
   TableIdExtension         AS WORD   ' WORD
   fSpecifyVersion          AS LONG   ' BOOL
   Version                  AS BYTE   ' BYTE
   fSpecifySectionNumber    AS LONG   ' BOOL
   SectionNumber            AS BYTE   ' BYTE
   fSpecifyCurrentNext      AS LONG   ' BOOL
   fNext                    AS LONG   ' BOOL
   fSpecifyDsmccOptions     AS LONG   ' BOOL
   Dsmcc                    AS DSMCC_FILTER_OPTIONS
   fSpecifyAtscOptions      AS LONG   ' BOOL
   Atsc                     AS ATSC_FILTER_OPTIONS
END TYPE

' // Size = 124 bytes
UNION MPEG2_FILTER2_UNION BYTE
   MPEG2_FILTER2_UNION_STRUCT
   bVersion1Bytes(123) AS BYTE   ' BYTE[124]
END UNION

' // Size = 133 bytes
TYPE MPEG2_FILTER2 BYTE
   MPEG2_FILTER2_UNION
   fSpecifyDvbEitOptions AS LONG   ' BOOL
   DvbEit AS DVB_EIT_FILTER_OPTIONS
END TYPE

%MPEG2_FILTER_VERSION_1_SIZE = 124
%MPEG2_FILTER_VERSION_2_SIZE = 133

' // Size = 16 bytes
TYPE MPEG_STREAM_BUFFER BYTE
   hr               AS LONG        ' HRESULT
   dwDataBufferSize AS DWORD       ' DWORD
   dwSizeOfDataRead AS DWORD       ' DWORD
   pDataBuffer      AS BYTE  PTR   ' BYTE*
END TYPE

' // Size = 3 bytes
TYPE MPEG_TIME BYTE
   Hours   AS BYTE   ' BYTE
   Minutes AS BYTE   ' BYTE
   Seconds AS BYTE   ' BYTE
END TYPE

MACRO MPEG_DURATION = MPEG_TIME

' // Size = 4 bytes
TYPE MPEG_DATE BYTE
   Date  AS BYTE   ' BYTE
   Month AS BYTE   ' BYTE
   Year  AS WORD   ' WORD
END TYPE

' // Size = 7 bytes
TYPE MPEG_DATE_AND_TIME BYTE
   D AS MPEG_DATE
   T AS MPEG_TIME
END TYPE

' enum MPEG_CONTEXT_TYPE
%MPEG_CONTEXT_BCS_DEMUX = 0
%MPEG_CONTEXT_WINSOCK   = %MPEG_CONTEXT_BCS_DEMUX + 1

' // Size = 4 bytes
TYPE MPEG_BCS_DEMUX BYTE
   AVMGraphId AS DWORD   ' DWORD
END TYPE

' // Size = 4 bytes
TYPE MPEG_WINSOCK BYTE
   AVMGraphId AS DWORD   ' DWORD
END TYPE

' // Size = 4 bytes
UNION MPEG_CONTEXT_UNION BYTE
   Demux   AS MPEG_BCS_DEMUX
   Winsock AS MPEG_WINSOCK
END UNION

' // Size = 8 bytes
TYPE MPEG_CONTEXT BYTE
   Type AS LONG   ' MPEG_CONTEXT_TYPE
   MPEG_CONTEXT_UNION
END TYPE

' enum MPEG_REQUEST_TYPE
%MPEG_RQST_UNKNOWN             = 0
%MPEG_RQST_GET_SECTION         = %MPEG_RQST_UNKNOWN             + 1
%MPEG_RQST_GET_SECTION_ASYNC   = %MPEG_RQST_GET_SECTION         + 1
%MPEG_RQST_GET_TABLE           = %MPEG_RQST_GET_SECTION_ASYNC   + 1
%MPEG_RQST_GET_TABLE_ASYNC     = %MPEG_RQST_GET_TABLE           + 1
%MPEG_RQST_GET_SECTIONS_STREAM = %MPEG_RQST_GET_TABLE_ASYNC     + 1
%MPEG_RQST_GET_PES_STREAM      = %MPEG_RQST_GET_SECTIONS_STREAM + 1
%MPEG_RQST_GET_TS_STREAM       = %MPEG_RQST_GET_PES_STREAM      + 1
%MPEG_RQST_START_MPE_STREAM    = %MPEG_RQST_GET_TS_STREAM       + 1

' // Size = 143 bytes
TYPE MPEG_SERVICE_REQUEST BYTE
   Type    AS LONG           ' MPEG_REQUEST_TYPE
   Context AS MPEG_CONTEXT
   Pid     AS WORD           ' PID
   TableId AS BYTE           ' TID
   Filter  AS MPEG2_FILTER
   Flags   AS DWORD          ' DWORD
END TYPE

' // Size = 6 bytes
TYPE MPEG_SERVICE_RESPONSE BYTE
   IPAddress AS DWORD   ' DWORD
   Port      AS WORD    ' WORD
END TYPE

' // Size = 15 bytes
TYPE DSMCC_ELEMENT BYTE
   pid             AS WORD                ' PID
   bComponentTag   AS BYTE                ' BYTE
   dwCarouselId    AS DWORD               ' DWORD
   dwTransactionId AS DWORD               ' DWORD
   pNext           AS DSMCC_ELEMENT PTR   ' _DSMCC_ELEMENT*
END TYPE

' // Size = 7 bytes
TYPE MPE_ELEMENT BYTE
   pid           AS WORD              ' PID
   bComponentTag AS BYTE              ' BYTE
   pNext         AS MPE_ELEMENT PTR   ' _MPE_ELEMENT*
END TYPE

' // Size = 42 bytes
TYPE MPEG_STREAM_FILTER BYTE
   wPidValue      AS WORD    ' WORD
   dwFilterSize   AS DWORD   ' DWORD
   fCrcEnabled    AS LONG    ' BOOL
   rgchFilter(15) AS BYTE    ' BYTE[16]
   rgchMask(15)   AS BYTE    ' BYTE[16]
END TYPE

'#undef BIG_ENDIAN_MACHINE
'#define LITTLE_ENDIAN_MACHINE

%LITTLE_ENDIAN_MACHINE = 1

'#define XCHG(x)             MAKEWORD(HIBYTE(x), LOBYTE(x))
'#define DXCHG(x)            MAKELONG(XCHG(HIWORD(x)), XCHG(LOWORD(x)))

MACRO XCHG(x) = MAK(WORD,HI(BYTE,x),LO(BYTE,x))
MACRO DXCHG(x) = MAK(LONG,XCHG(HI(WORD,x)), XCHG(LO(WORD,x)))

'#undef SWAPBYTES
'#undef SWAPWORDS

'#IF %DEF(%LITTLE_ENDIAN_MACHINE
'#define SWAPBYTES(w)        ((w) = XCHG(w))
'#define SWAPWORDS(d)        ((d) = DXCHG(d))
'#endif

#IF %DEF(%LITTLE_ENDIAN_MACHINE)
SUB SWAPBYTES(BYREF w AS WORD)
   IF VARPTR(w) THEN w = XCHG(w)
END SUB
SUB SWAPWORDS(BYREF d AS DWORD)
   IF VARPTR(d) THEN d = DXCHG(d)
END SUB
#ENDIF

'#ifdef BIG_ENDIAN_MACHINE
'#define SWAPBYTES(w)        (w)
'#define SWAPWORDS(d)        (d)
'#endif

'#define SWAP_MPEG_SECTION_HEADER_BYTES(_pSection)                                   \
'    {                                                                       \
'        if (_pSection)                                                      \
'        {                                                                   \
'            SWAPBYTES((_pSection)->Header.W);                                 \
'                                                                            \
'            if (reinterpret_cast<PMPEG_HEADER_BITS>(&((reinterpret_cast<PLONG_SECTION>(_pSection)->Header.W)))->SectionSyntaxIndicator || \
'                    (_pSection)->TableId == 0x00 ||                           \
'                    (_pSection)->TableId == 0x3A ||                           \
'                    (_pSection)->TableId == 0x3B ||                           \
'                    (_pSection)->TableId == 0x3C ||                           \
'                    (_pSection)->TableId == 0x3D ||                           \
'                    (_pSection)->TableId == 0x3E)                             \
'            {                                                               \
'                SWAPBYTES(reinterpret_cast<PLONG_SECTION>(_pSection)->TableIdExtension);    \
'            }                                                               \
'        }                                                                   \
'    }

MACRO SWAP_MPEG_SECTION_HEADER_BYTES(pSection)
   IF VARPTR(pSection) THEN
      SWAPBYTES(pSection.Header.W)
      IF pSection.Header.S.SectionSyntaxIndicator OR _
         pSection.TableId = &H00 OR _
         pSection.TableId = &H3A OR _
         pSection.TableId = &H3B OR _
         pSection.TableId = &H3C OR _
         pSection.TableId = &H3D OR _
         pSection.TableId = &H3E THEN
         SWAPBYTES(pSection.TableIdExtension)
      END IF
   END IF
END MACRO

'#define SWAP_MPEG_HEADER_BYTES(_pSection)                                   \
'    {                                                                       \
'        if (_pSection)                                                      \
'        {                                                                   \
'            SWAP_MPEG_SECTION_HEADER_BYTES(_pSection)                       \
'            if ((_pSection)->TableId == 0x3B ||                             \
'                (_pSection)->TableId == 0x3C)                               \
'            {                                                               \
'                SWAPBYTES(reinterpret_cast<PDSMCC_SECTION>(_pSection)->MessageId);          \
'                SWAPWORDS(reinterpret_cast<PDSMCC_SECTION>(_pSection)->TransactionId);      \
'                SWAPBYTES(reinterpret_cast<PDSMCC_SECTION>(_pSection)->MessageLength);      \
'            }                                                               \
'        }                                                                   \
'    }

MACRO SWAP_MPEG_HEADER_BYTES(pSection)
   IF VARPTR(pSection) THEN
      SWAP_MPEG_SECTION_HEADER_BYTES(pSection)
      IF pSection.TableId = &H3B OR _
         pSection.TableId = &H3C THEN
         SWAPBYTES(pSection.MessageId)
         SWAPWORDS(pSection.TransactionId)
         SWAPBYTES(pSection.MessageLength)
      END IF
   END IF
END MACRO

'#define UNSWAP_MPEG_HEADER_BYTES(_pSection)                                 \
'    {                                                                       \
'        if (_pSection)                                                      \
'        {                                                                   \
'            if ((_pSection)->TableId == 0x3B ||                             \
'                (_pSection)->TableId == 0x3C)                               \
'            {                                                               \
'                SWAPBYTES((reinterpret_cast<PDSMCC_SECTION>(_pSection))->MessageId);          \
'                SWAPWORDS((reinterpret_cast<PDSMCC_SECTION>(_pSection))->TransactionId);      \
'                SWAPBYTES((reinterpret_cast<PDSMCC_SECTION>(_pSection))->MessageLength);      \
'            }                                                                                 \
'            UNSWAP_MPEG_SECTION_HEADER_BYTES(_pSection)                       \
'        }                                                                     \
'    }

MACRO UNSWAP_MPEG_HEADER_BYTES(pSection)
   IF VARPTR(pSection) THEN
      IF pSection.TableId = &H3B OR _
         pSection.TableId = &H3C THEN
         SWAPBYTES(pSection.MessageId)
         SWAPWORDS(pSection.TransactionId)
         SWAPBYTES(pSection.MessageLength)
      END IF
      UNSWAP_MPEG_SECTION_HEADER_BYTES(pSection)
   END IF
END MACRO

'#define UNSWAP_MPEG_SECTION_HEADER_BYTES(_pSection)                         \
'    {                                                                       \
'        if (_pSection)                                                      \
'        {                                                                   \
'            if (reinterpret_cast<PMPEG_HEADER_BITS>(&((reinterpret_cast<PLONG_SECTION>(_pSection)->Header.W)))->SectionSyntaxIndicator || \
'                    (_pSection)->TableId == 0x00 ||                           \
'                    (_pSection)->TableId == 0x3A ||                           \
'                    (_pSection)->TableId == 0x3B ||                           \
'                    (_pSection)->TableId == 0x3C ||                           \
'                    (_pSection)->TableId == 0x3D ||                           \
'                    (_pSection)->TableId == 0x3E)                             \
'            {                                                                 \
'                SWAPBYTES(reinterpret_cast<PLONG_SECTION>(_pSection)->TableIdExtension);    \
'            }                                                                               \
'            SWAPBYTES(reinterpret_cast<PLONG_SECTION>(_pSection)->Header.W);                \
'        }                                                                                   \
'    }

MACRO UNSWAP_MPEG_SECTION_HEADER_BYTES(pSection)
   IF VARPTR(pSection) THEN
      IF pSection.Header.S.SectionSyntaxIndicator OR _
         pSection.TableId = &H00 OR _
         pSection.TableId = &H3A OR _
         pSection.TableId = &H3B OR _
         pSection.TableId = &H3C OR _
         pSection.TableId = &H3D OR _
         pSection.TableId = &H3E THEN
         SWAPBYTES(pSection.TableIdExtension)
      END IF
      SWAPBYTES(pSection.Header.W)
   END IF
END MACRO

'#pragma pack(pop)
