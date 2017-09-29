' ########################################################################################
' Microsoft Windows
' File: SCardSSp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SCARDSSPLib
' Version: 1.0, Locale ID = 0
' Description: scardssp 1.0 Type Library
' Path: C:\WINDOWS\system32\scardssp.dll
' Library GUID: {82C38704-19F1-11D3-A11F-00C04F79F800}
' ########################################################################################

#INCLUDE THIS ONCE
%SCARDSSP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

#IF NOT %DEF(%SCARDSSPLib_LIBRARY_DEFINED)
    %SCARDSSPLib_LIBRARY_DEFINED = 1

$LIBID_SCARDSSPLib = GUID$("{82C38704-19F1-11D3-A11F-00C04F79F800}")
$CLSID_CByteBuffer = GUID$("{E126F8FF-A7AF-11D0-B88A-00C04FD424B9}")
$CLSID_CSCardTypeConv = GUID$("{53B6AA67-3F56-11D0-916B-00AA00C18068}")
$CLSID_CSCardCmd = GUID$("{D5778AE7-43DE-11D0-9171-00AA00C18068}")
$CLSID_CSCardISO7816 = GUID$("{53B6AA6C-3F56-11D0-916B-00AA00C18068}")
$CLSID_CSCard = GUID$("{1461AAC7-6810-11D0-918F-00AA00C18068}")
$CLSID_CSCardDatabase = GUID$("{1461AACC-6810-11D0-918F-00AA00C18068}")
$CLSID_CSCardLocate = GUID$("{1461AAD1-6810-11D0-918F-00AA00C18068}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {E126F8FF-A7AF-11D0-B88A-00C04FD424B9}
$PROGID_ScardsspByteBuffer1 = "Scardssp.ByteBuffer.1"
' CLSID = {1461AAC7-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCard1 = "Scardssp.SCard.1"
' CLSID = {D5778AE7-43DE-11D0-9171-00AA00C18068}
$PROGID_ScardsspSCardCmd1 = "Scardssp.SCardCmd.1"
' CLSID = {1461AACC-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCardDatabase1 = "Scardssp.SCardDatabase.1"
' CLSID = {53B6AA6C-3F56-11D0-916B-00AA00C18068}
$PROGID_ScardsspSCardISO78161 = "Scardssp.SCardISO7816.1"
' CLSID = {1461AAD1-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCardLocate1 = "Scardssp.SCardLocate.1"
' CLSID = {53B6AA67-3F56-11D0-916B-00AA00C18068}
$PROGID_ScardsspSCardTypeConv1 = "Scardssp.SCardTypeConv.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {E126F8FF-A7AF-11D0-B88A-00C04FD424B9}
$PROGID_ScardsspByteBuffer = "Scardssp.ByteBuffer"
' CLSID = {1461AAC7-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCard = "Scardssp.SCard"
' CLSID = {D5778AE7-43DE-11D0-9171-00AA00C18068}
$PROGID_ScardsspSCardCmd = "Scardssp.SCardCmd"
' CLSID = {1461AACC-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCardDatabase = "Scardssp.SCardDatabase"
' CLSID = {53B6AA6C-3F56-11D0-916B-00AA00C18068}
$PROGID_ScardsspSCardISO7816 = "Scardssp.SCardISO7816"
' CLSID = {1461AAD1-6810-11D0-918F-00AA00C18068}
$PROGID_ScardsspSCardLocate = "Scardssp.SCardLocate"
' CLSID = {53B6AA67-3F56-11D0-916B-00AA00C18068}
$PROGID_ScardsspSCardTypeConv = "Scardssp.SCardTypeConv"

#ENDIF   ' /* __SCARDSSPLib_LIBRARY_DEFINED__ */

'//////////////////////////////////////////////////////////////////
'//
'// Interface declarations
'//

'//////////////////////////////////////////////////////////////////
'//
'// Types and Constants
'//

'typedef /* [public] */ unsigned char BYTE;
'typedef /* [public] */ BYTE *LPBYTE;
'typedef /* [public] */ const BYTE *LPCBYTE;
'typedef /* [public] */ ULONG_PTR HSCARD;
'typedef /* [unique] */ HSCARD *PHSCARD;
'typedef /* [unique] */ HSCARD *LPHSCARD;
'typedef /* [public] */ ULONG_PTR HSCARDCONTEXT;
'typedef /* [unique] */ *PHSCARDCONTEXT;
'typedef /* [unique] */ *LPHSCARDCONTEXT;

' // Size = 12 bytes
TYPE BYTEARRAY DWORD
   hMem    AS DWORD      ' HGLOBAL
   dwSize  AS DWORD      ' DWORD
   pbyData AS BYTE PTR   ' LPBYTE
END TYPE

'typedef /* [public] */ BYTEARRAY *PBYTEARRAY;
'typedef /* [public] */ const BYTEARRAY *PCBYTEARRAY;
'typedef /* [public] */ BYTEARRAY *LPBYTEARRAY;
'typedef /* [public] */ const BYTEARRAY *LPCBYTEARRAY;

' // Size = 20 bytes
TYPE STATSTRUCT DWORD
   type              AS LONG
   cbSize            AS LONG
   grfMode           AS LONG
   grfLocksSupported AS LONG
   grfStateBits      AS LONG
END TYPE

'typedef /* [public] */ STATSTRUCT *LPSTATSTRUCT;

' ISO_APDU_TYPE enum
%ISO_CASE_1 = 1
%ISO_CASE_2 = 2
%ISO_CASE_3 = 3
%ISO_CASE_4 = 4

' SCARD_SHARE_MODES enum
%SCARD_SHARE_MODES_EXCLUSIVE = 1
%SCARD_SHARE_MODES_SHARED    = 2

' SCARD_DISPOSITIONS enum
%SCARD_DISPOSITIONS_LEAVE   = 0
%SCARD_DISPOSITIONS_RESET   = 1
%SCARD_DISPOSITIONS_UNPOWER = 2
%SCARD_DISPOSITIONS_EJECT   = 3

' SCARD_STATES enum
%SCARD_STATES_ABSENT         = 1
%SCARD_STATES_PRESENT        = 2
%SCARD_STATES_SWALLOWED      = 3
%SCARD_STATES_POWERED        = 4
%SCARD_STATES_NEGOTIABLEMODE = 5
%SCARD_STATES_SPECIFICMODE   = 6

' SCARD_PROTOCOLS enum
%SCARD_PROTOCOLS_T0  = &H1
%SCARD_PROTOCOLS_T1  = &H2
%SCARD_PROTOCOLS_RAW = &Hff

' // Size = 32 bytes
TYPE SCARDINFO DWORD
   hCard              AS DWORD   ' HSCARD
   hContext           AS DWORD   ' HSCARDCONTEXT
   ActiveProtocol     AS LONG    ' SCARD_PROTOCOLS
   ShareMode          AS LONG    ' SCARD_SHARE_MODES
   hwndOwner          AS LONG    ' LONG_PTR
   lpfnConnectProc    AS LONG    ' LONG_PTR
   lpfnCheckProc      AS LONG    ' LONG_PTR
   lpfnDisconnectProc AS LONG    ' LONG_PTR
END TYPE

'typedef /* [unique] */ SCARDINFO *PSCARDINFO;
'typedef /* [unique] */ SCARDINFO *LPSCARDINFO;

' ########################################################################################
' Interface name = IByteBuffer
' IID = {E126F8FE-A7AF-11D0-B88A-00C04FD424B9}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IByteBuffer_INTERFACE_DEFINED)
    %IByteBuffer_INTERFACE_DEFINED = 1

$IID_IByteBuffer = GUID$("{E126F8FE-A7AF-11D0-B88A-00C04FD424B9}")

INTERFACE IByteBuffer $IID_IByteBuffer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Stream <0> ( _                          ' VTable offset = 28
   ) AS IStream                                         ' __retval_out LPSTREAM *ppStream
   ' =====================================================================================
   PROPERTY SET Stream <0> ( _                          ' VTable offset = 32
     BYVAL pStream AS IStream _                         ' __in LPSTREAM pStream
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1> ( _                                 ' VTable offset = 36
     BYREF ppByteBuffer AS IByteBuffer _                ' __in_out LPBYTEBUFFER *ppByteBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <2> ( _                                ' VTable offset = 40
     BYVAL grfCommitFlags AS LONG _                     ' __in LONG grfCommitFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyTo <3> ( _                                ' VTable offset = 44
     BYREF ppByteBuffer AS IByteBuffer _                ' __in_out LPBYTEBUFFER *ppByteBuffer
   , BYVAL cb AS LONG _                                 ' __in LONG cb
   , OPTIONAL BYREF pcbRead AS LONG _                   ' __in_out LONG *pcbRead = 0
   , OPTIONAL BYREF pcbWritten AS LONG _                ' __in_out LONG *pcbWritten = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <4> ( _                            ' VTable offset = 48
     OPTIONAL BYVAL lSize AS LONG _                     ' __in LONG lSize = 1
   , OPTIONAL BYREF pData AS BYTE _                     ' __in BYTE *pData = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD LockRegion <5> ( _                            ' VTable offset = 52
     BYVAL libOffset AS LONG _                          ' __in LONG libOffset
   , BYVAL cb AS LONG _                                 ' __in LONG cb
   , BYVAL dwLockType AS LONG _                         ' __in LONG dwLockType
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <6> ( _                                  ' VTable offset = 56
     BYREF pByte AS BYTE _                              ' __in_out BYTE *pByte
   , BYVAL cb AS LONG _                                 ' __in LONG cb
   , OPTIONAL BYREF pcbRead AS LONG _                   ' __in_out LONG *pcbRead = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Revert <7> ( _                                ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Seek <8> ( _                                  ' VTable offset = 64
     BYVAL dLibMove AS LONG _                           ' __in LONG dLibMove
   , BYVAL dwOrigin AS LONG _                           ' __in LONG dwOrigin
   , OPTIONAL BYREF pLibnewPosition AS LONG _           ' __in_out LONG *pLibnewPosition = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSize <9> ( _                               ' VTable offset = 68
     BYVAL libNewSize AS LONG _                         ' __in LONG libNewSize
   )                                                    ' void
   ' =====================================================================================
   METHOD Stat <10> ( _                                 ' VTable offset = 72
     BYVAL pstatstg AS DWORD _                          ' __in_out LPSTATSTRUCT pstatstg
   , BYVAL grfStatFlag AS LONG _                        ' __in LONG grfStatFlag
   )                                                    ' void
   ' =====================================================================================
   METHOD UnlockRegion <11> ( _                         ' VTable offset = 76
     BYVAL libOffset AS LONG _                          ' __in LONG libOffset
   , BYVAL cb AS LONG _                                 ' __in LONG cb
   , BYVAL dwLockType AS LONG _                         ' __in LONG dwLockType
   )                                                    ' void
   ' =====================================================================================
   METHOD Write <12> ( _                                ' VTable offset = 80
     BYREF pByte AS BYTE _                              ' __in_out BYTE *pByte
   , BYVAL cb AS LONG _                                 ' __in LONG cb
   , BYREF pcbWritten AS LONG _                         ' __in_out LONG *pcbWritten
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IByteBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCardTypeConv
' IID = {53B6AA63-3F56-11D0-916B-00AA00C18068}
' ISCardTypeConv Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCardTypeConv_INTERFACE_DEFINED)
    %ISCardTypeConv_INTERFACE_DEFINED = 1

$IID_ISCardTypeConv = GUID$("{53B6AA63-3F56-11D0-916B-00AA00C18068}")

INTERFACE ISCardTypeConv $IID_ISCardTypeConv

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ConvertByteArrayToByteBuffer <0> ( _          ' VTable offset = 28
     BYVAL pbyArray AS DWORD _                          ' __in LPBYTE pbyArray
   , BYVAL dwArraySize AS DWORD _                       ' __in DWORD dwArraySize
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppbyBuffer
   ' =====================================================================================
   METHOD ConvertByteBufferToByteArray <1> ( _          ' VTable offset = 32
     BYVAL pbyBuffer AS IByteBuffer _                   ' __in LPBYTEBUFFER pbyBuffer
   ) AS DWORD                                           ' __retval_out LPBYTEARRAY *ppArray
   ' =====================================================================================
   METHOD ConvertByteBufferToSafeArray <2> ( _          ' VTable offset = 36
     BYVAL pbyBuffer AS IByteBuffer _                   ' __in LPBYTEBUFFER pbyBuffer
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppbyArray
   ' =====================================================================================
   METHOD ConvertSafeArrayToByteBuffer <3> ( _          ' VTable offset = 40
     BYVAL pbyArray AS DWORD _                          ' __in LPSAFEARRAY pbyArray
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppbyBuff
   ' =====================================================================================
   METHOD CreateByteArray <4> ( _                       ' VTable offset = 44
     BYVAL dwAllocSize AS DWORD _                       ' __in DWORD dwAllocSize
   ) AS DWORD                                           ' __retval_out LPBYTE *ppbyArray
   ' =====================================================================================
   METHOD CreateByteBuffer <5> ( _                      ' VTable offset = 48
     BYVAL dwAllocSize AS DWORD _                       ' __in DWORD dwAllocSize
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppbyBuff
   ' =====================================================================================
   METHOD CreateSafeArray <6> ( _                       ' VTable offset = 52
     BYVAL nAllocSize AS DWORD _                        ' __in UINT nAllocSize
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppArray
   ' =====================================================================================
   METHOD FreeIStreamMemoryPtr <7> ( _                  ' VTable offset = 56
     BYVAL pStrm AS IStream _                           ' __in LPSTREAM pStrm
   , BYVAL pMem AS DWORD _                              ' __in LPBYTE pMem
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAtIStreamMemory <8> ( _                    ' VTable offset = 60
     BYVAL pStrm AS IStream _                           ' __in LPSTREAM pStrm
   ) AS DWORD                                           ' __retval_out LPBYTEARRAY *ppMem
   ' =====================================================================================
   METHOD SizeOfIStream <9> ( _                         ' VTable offset = 64
     BYVAL pStrm AS IStream _                           ' __in LPSTREAM pStrm
   ) AS QUAD                                            ' __retval_out ULARGE_INTEGER *puliSize
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCardTypeConv_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCardCmd
' IID = {D5778AE3-43DE-11D0-9171-00AA00C18068}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCardCmd_INTERFACE_DEFINED)
    %ISCardCmd_INTERFACE_DEFINED = 1

$IID_ISCardCmd = GUID$("{D5778AE3-43DE-11D0-9171-00AA00C18068}")

INTERFACE ISCardCmd $IID_ISCardCmd

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Apdu <0> ( _                            ' VTable offset = 28
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppApdu
   ' =====================================================================================
   PROPERTY SET Apdu <0> ( _                            ' VTable offset = 32
     BYVAL pApdu AS IByteBuffer _                       ' __in LPBYTEBUFFER pApdu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApduLength <1> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *plSize
   ' =====================================================================================
   PROPERTY GET ApduReply <2> ( _                       ' VTable offset = 40
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppReplyApdu
   ' =====================================================================================
   PROPERTY SET ApduReply <2> ( _                       ' VTable offset = 44
     BYVAL pReplyApdu AS IByteBuffer _                  ' __in LPBYTEBUFFER pReplyApdu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApduReplyLength <3> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *plSize
   ' =====================================================================================
   PROPERTY SET ApduReplyLength <3> ( _                 ' VTable offset = 52
     BYVAL lSiz AS LONG _                               ' __in LONG lSiz
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClassId <4> ( _                         ' VTable offset = 56
   ) AS BYTE                                            ' __retval_out BYTE *pbyClass
   ' =====================================================================================
   PROPERTY SET ClassId <4> ( _                         ' VTable offset = 60
     OPTIONAL BYVAL byClass AS BYTE _                   ' __in BYTE byClass = 0
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data <5> ( _                            ' VTable offset = 64
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppData
   ' =====================================================================================
   PROPERTY SET Data <5> ( _                            ' VTable offset = 68
     BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InstructionId <6> ( _                   ' VTable offset = 72
   ) AS BYTE                                            ' __retval_out BYTE *pbyIns
   ' =====================================================================================
   PROPERTY SET InstructionId <6> ( _                   ' VTable offset = 76
     BYVAL byIns AS BYTE _                              ' __in BYTE byIns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LeField <7> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *plSize
   ' =====================================================================================
   PROPERTY GET P1 <8> ( _                              ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BYTE *pbyP1
   ' =====================================================================================
   PROPERTY SET P1 <8> ( _                              ' VTable offset = 88
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET P2 <9> ( _                              ' VTable offset = 92
   ) AS BYTE                                            ' __retval_out BYTE *pbyP2
   ' =====================================================================================
   PROPERTY SET P2 <9> ( _                              ' VTable offset = 96
     BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET P3 <10> ( _                             ' VTable offset = 100
   ) AS BYTE                                            ' __retval_out BYTE *pbyP3
   ' =====================================================================================
   PROPERTY GET ReplyStatus <11> ( _                    ' VTable offset = 104
   ) AS WORD                                            ' __retval_out LPWORD pwStatus
   ' =====================================================================================
   PROPERTY SET ReplyStatus <11> ( _                    ' VTable offset = 108
     BYVAL wStatus AS WORD _                            ' __in WORD wStatus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplyStatusSW1 <12> ( _                 ' VTable offset = 112
   ) AS BYTE                                            ' __retval_out BYTE *pbySW1
   ' =====================================================================================
   PROPERTY GET ReplyStatusSW2 <13> ( _                 ' VTable offset = 116
   ) AS BYTE                                            ' __retval_out BYTE *pbySW2
   ' =====================================================================================
   PROPERTY GET type <14> ( _                           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out ISO_APDU_TYPE *pType
   ' =====================================================================================
   PROPERTY GET Nad <18> ( _                            ' VTable offset = 124
   ) AS BYTE                                            ' __retval_out BYTE *pbNad
   ' =====================================================================================
   PROPERTY SET Nad <18> ( _                            ' VTable offset = 128
     BYVAL bNad AS BYTE _                               ' __in BYTE bNad
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplyNad <19> ( _                       ' VTable offset = 132
   ) AS BYTE                                            ' __retval_out BYTE *pbNad
   ' =====================================================================================
   PROPERTY SET ReplyNad <19> ( _                       ' VTable offset = 136
     BYVAL bNad AS BYTE _                               ' __in BYTE bNad
   )                                                    ' void
   ' =====================================================================================
   METHOD BuildCmd <15> ( _                             ' VTable offset = 140
     BYVAL byClassId AS BYTE _                          ' __in BYTE byClassId
   , BYVAL byInsId AS BYTE _                            ' __in BYTE byInsId
   , OPTIONAL BYVAL byP1 AS BYTE _                      ' __in BYTE byP1 = 0
   , OPTIONAL BYVAL byP2 AS BYTE _                      ' __in BYTE byP2 = 0
   , OPTIONAL BYVAL pbyData AS IByteBuffer _            ' __in LPBYTEBUFFER pbyData = 0
   , OPTIONAL BYREF plLe AS LONG _                      ' __in LONG *plLe = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <16> ( _                                ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD Encapsulate <17> ( _                          ' VTable offset = 148
     BYVAL pApdu AS IByteBuffer _                       ' __in LPBYTEBUFFER pApdu
   , BYVAL ApduType AS LONG _                           ' __in ISO_APDU_TYPE ApduType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateClassId <20> ( _               ' VTable offset = 152
   ) AS BYTE                                            ' __retval_out BYTE *pbyClass
   ' =====================================================================================
   PROPERTY SET AlternateClassId <20> ( _               ' VTable offset = 156
     BYVAL byClass AS BYTE _                            ' __in BYTE byClass
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCardCmd_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCardISO7816
' IID = {53B6AA68-3F56-11D0-916B-00AA00C18068}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCardISO7816_INTERFACE_DEFINED)
    %ISCardISO7816_INTERFACE_DEFINED = 1

$IID_ISCardISO7816 = GUID$("{53B6AA68-3F56-11D0-916B-00AA00C18068}")

INTERFACE ISCardISO7816 $IID_ISCardISO7816

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AppendRecord <0> ( _                          ' VTable offset = 28
     BYVAL byRefCtrl AS BYTE _                          ' __in BYTE byRefCtrl
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD EraseBinary <1> ( _                           ' VTable offset = 32
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD ExternalAuthenticate <2> ( _                  ' VTable offset = 36
     BYVAL byAlgorithmRef AS BYTE _                     ' __in BYTE byAlgorithmRef
   , BYVAL bySecretRef AS BYTE _                        ' __in BYTE bySecretRef
   , BYVAL pChallenge AS IByteBuffer _                  ' __in LPBYTEBUFFER pChallenge
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChallenge <3> ( _                          ' VTable offset = 40
     BYVAL lBytesExpected AS LONG _                     ' __in LONG lBytesExpected
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData <4> ( _                               ' VTable offset = 44
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL lBytesToGet AS LONG _                        ' __in LONG lBytesToGet
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD GetResponse <5> ( _                           ' VTable offset = 48
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL lDataLength AS LONG _                        ' __in LONG lDataLength
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalAuthenticate <6> ( _                  ' VTable offset = 52
     BYVAL byAlgorithmRef AS BYTE _                     ' __in BYTE byAlgorithmRef
   , BYVAL bySecretRef AS BYTE _                        ' __in BYTE bySecretRef
   , BYVAL pChallenge AS IByteBuffer _                  ' __in LPBYTEBUFFER pChallenge
   , BYVAL lReplyBytes AS LONG _                        ' __in LONG lReplyBytes
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD ManageChannel <7> ( _                         ' VTable offset = 56
     BYVAL byChannelState AS BYTE _                     ' __in BYTE byChannelState
   , BYVAL byChannel AS BYTE _                          ' __in BYTE byChannel
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD PutData <8> ( _                               ' VTable offset = 60
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadBinary <9> ( _                            ' VTable offset = 64
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL lBytesToRead AS LONG _                       ' __in LONG lBytesToRead
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadRecord <10> ( _                           ' VTable offset = 68
     BYVAL byRecordId AS BYTE _                         ' __in BYTE byRecordId
   , BYVAL byRefCtrl AS BYTE _                          ' __in BYTE byRefCtrl
   , BYVAL lBytesToRead AS LONG _                       ' __in LONG lBytesToRead
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectFile <11> ( _                           ' VTable offset = 72
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYVAL lBytesToRead AS LONG _                       ' __in LONG lBytesToRead
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultClassId <12> ( _                    ' VTable offset = 76
     BYVAL byClass AS BYTE _                            ' __in BYTE byClass
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateBinary <13> ( _                         ' VTable offset = 80
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateRecord <14> ( _                         ' VTable offset = 84
     BYVAL byRecordId AS BYTE _                         ' __in BYTE byRecordId
   , BYVAL byRefCtrl AS BYTE _                          ' __in BYTE byRefCtrl
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD Verify <15> ( _                               ' VTable offset = 88
     BYVAL byRefCtrl AS BYTE _                          ' __in BYTE byRefCtrl
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBinary <16> ( _                          ' VTable offset = 92
     BYVAL byP1 AS BYTE _                               ' __in BYTE byP1
   , BYVAL byP2 AS BYTE _                               ' __in BYTE byP2
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteRecord <17> ( _                          ' VTable offset = 96
     BYVAL byRecordId AS BYTE _                         ' __in BYTE byRecordId
   , BYVAL byRefCtrl AS BYTE _                          ' __in BYTE byRefCtrl
   , BYVAL pData AS IByteBuffer _                       ' __in LPBYTEBUFFER pData
   , BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCardISO7816_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCard
' IID = {1461AAC3-6810-11D0-918F-00AA00C18068}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCard_INTERFACE_DEFINED)
    %ISCard_INTERFACE_DEFINED = 1

$IID_ISCard = GUID$("{1461AAC3-6810-11D0-918F-00AA00C18068}")

INTERFACE ISCard $IID_ISCard

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Atr <0> ( _                             ' VTable offset = 28
   ) AS IByteBuffer                                     ' __retval_out LPBYTEBUFFER *ppAtr
   ' =====================================================================================
   PROPERTY GET CardHandle <1> ( _                      ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out HSCARD *pHandle
   ' =====================================================================================
   PROPERTY GET Context <2> ( _                         ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out HSCARDCONTEXT *pContext
   ' =====================================================================================
   PROPERTY GET Protocol <3> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out SCARD_PROTOCOLS *pProtocol
   ' =====================================================================================
   PROPERTY GET Status <4> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out SCARD_STATES *pStatus
   ' =====================================================================================
   METHOD AttachByHandle <5> ( _                        ' VTable offset = 48
     BYVAL hCard AS DWORD _                             ' __in HSCARD hCard
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachByReader <6> ( _                        ' VTable offset = 52
     BYVAL bstrReaderName AS WSTRING _                  ' __in BSTR bstrReaderName
   , OPTIONAL BYVAL ShareMode AS LONG _                 ' __in SCARD_SHARE_MODES ShareMode = EXCLUSIVE
   , OPTIONAL BYVAL PrefProtocol AS LONG _              ' __in SCARD_PROTOCOLS PrefProtocol = T0
   )                                                    ' void
   ' =====================================================================================
   METHOD Detach <7> ( _                                ' VTable offset = 56
     OPTIONAL BYVAL Disposition AS LONG _               ' __in SCARD_DISPOSITIONS Disposition = LEAVE
   )                                                    ' void
   ' =====================================================================================
   METHOD LockSCard <8> ( _                             ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD ReAttach <9> ( _                              ' VTable offset = 64
     OPTIONAL BYVAL ShareMode AS LONG _                 ' __in SCARD_SHARE_MODES ShareMode = EXCLUSIVE
   , OPTIONAL BYVAL InitState AS LONG _                 ' __in SCARD_DISPOSITIONS InitState = LEAVE
   )                                                    ' void
   ' =====================================================================================
   METHOD Transaction <10> ( _                          ' VTable offset = 68
     BYREF ppCmd AS ISCardCmd _                         ' __in_out LPSCARDCMD *ppCmd
   )                                                    ' void
   ' =====================================================================================
   METHOD UnlockSCard <11> ( _                          ' VTable offset = 72
     OPTIONAL BYVAL Disposition AS LONG _               ' __in SCARD_DISPOSITIONS Disposition = LEAVE
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCard_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISCardDatabase
' IID = {1461AAC8-6810-11D0-918F-00AA00C18068}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCardDatabase_INTERFACE_DEFINED)
    %ISCardDatabase_INTERFACE_DEFINED = 1

$IID_ISCardDatabase = GUID$("{1461AAC8-6810-11D0-918F-00AA00C18068}")

INTERFACE ISCardDatabase $IID_ISCardDatabase

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProviderCardId <0> ( _                     ' VTable offset = 28
     BYVAL bstrCardName AS WSTRING _                    ' __in BSTR bstrCardName
   ) AS GUID                                            ' __retval_out LPGUID *ppguidProviderId
   ' =====================================================================================
   METHOD ListCardInterfaces <1> ( _                    ' VTable offset = 32
     BYVAL bstrCardName AS WSTRING _                    ' __in BSTR bstrCardName
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppInterfaceGuids
   ' =====================================================================================
   METHOD ListCards <2> ( _                             ' VTable offset = 36
     OPTIONAL BYVAL pAtr AS IByteBuffer _               ' __in LPBYTEBUFFER pAtr
   , OPTIONAL BYVAL pInterfaceGuids AS DWORD _          ' __in LPSAFEARRAY pInterfaceGuids
   , OPTIONAL BYVAL localeId AS LONG _                  ' __in long localeId
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppCardNames
   ' =====================================================================================
   METHOD ListReaderGroups <3> ( _                      ' VTable offset = 40
     OPTIONAL BYVAL localeId AS LONG _                  ' __in long localeId
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppReaderGroups
   ' =====================================================================================
   METHOD ListReaders <4> ( _                           ' VTable offset = 44
     OPTIONAL BYVAL localeId AS LONG _                  ' __in long localeId
   ) AS DWORD                                           ' __retval_out LPSAFEARRAY *ppReaders
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCardDatabase_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISCardLocate
' IID = {1461AACD-6810-11D0-918F-00AA00C18068}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISCardLocate_INTERFACE_DEFINED)
    %ISCardLocate_INTERFACE_DEFINED = 1

$IID_ISCardLocate = GUID$("{1461AACD-6810-11D0-918F-00AA00C18068}")

INTERFACE ISCardLocate $IID_ISCardLocate

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ConfigureCardGuidSearch <0> ( _               ' VTable offset = 28
     BYVAL pCardGuids AS DWORD _                        ' __in LPSAFEARRAY pCardGuids
   , OPTIONAL BYVAL pGroupNames AS DWORD _              ' __in LPSAFEARRAY pGroupNames = 0
   , OPTIONAL BYVAL bstrTitle AS WSTRING _              ' __in BSTR bstrTitle = L""
   , OPTIONAL BYVAL lFlags AS LONG _                    ' __in LONG lFlags = 1
   )                                                    ' void
   ' =====================================================================================
   METHOD ConfigureCardNameSearch <1> ( _               ' VTable offset = 32
     BYVAL pCardNames AS DWORD _                        ' __in LPSAFEARRAY pCardNames
   , OPTIONAL BYVAL pGroupNames AS DWORD _              ' __in LPSAFEARRAY pGroupNames = 0
   , OPTIONAL BYVAL bstrTitle AS WSTRING _              ' __in BSTR bstrTitle = L""
   , OPTIONAL BYVAL lFlags AS LONG _                    ' __in LONG lFlags = 1
   )                                                    ' void
   ' =====================================================================================
   METHOD FindCard <2> ( _                              ' VTable offset = 36
     OPTIONAL BYVAL ShareMode AS LONG _                 ' __in SCARD_SHARE_MODES ShareMode
   , OPTIONAL BYVAL Protocols AS LONG _                 ' __in SCARD_PROTOCOLS Protocols
   , OPTIONAL BYVAL lFlags AS LONG _                    ' __in LONG lFlags
   ) AS SCARDINFO                                       ' __retval_out LPSCARDINFO *ppCardInfo
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISCardLocate_INTERFACE_DEFINED__ */
