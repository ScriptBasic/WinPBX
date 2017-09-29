' ########################################################################################
' Microsoft Windows
' File: Mcx.inc
' Contents: Defines the 32-Bit Windows MCX APIs
' Copyright (c) 2011-2013 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MCX_INC = 1

' // Size = 80 bytes
TYPE MODEMDEVCAPS DWORD
   dwActualSize              AS DWORD   ' DWORD dwActualSize
   dwRequiredSize            AS DWORD   ' DWORD dwRequiredSize
   dwDevSpecificOffset       AS DWORD   ' DWORD dwDevSpecificOffset
   dwDevSpecificSize         AS DWORD   ' DWORD dwDevSpecificSize

   ' product and version identification
   dwModemProviderVersion    AS DWORD   ' DWORD dwModemProviderVersion
   dwModemManufacturerOffset AS DWORD   ' DWORD dwModemManufacturerOffset
   dwModemManufacturerSize   AS DWORD   ' DWORD dwModemManufacturerSize
   dwModemModelOffset        AS DWORD   ' DWORD dwModemModelOffset
   dwModemModelSize          AS DWORD   ' DWORD dwModemModelSize
   dwModemVersionOffset      AS DWORD   ' DWORD dwModemVersionOffset
   dwModemVersionSize        AS DWORD   ' DWORD dwModemVersionSize

   ' local option capabilities
   dwDialOptions             AS DWORD   ' DWORD dwDialOptions
   dwCallSetupFailTimer      AS DWORD   ' DWORD dwCallSetupFailTimer
   dwInactivityTimeout       AS DWORD   ' DWORD dwInactivityTimeout
   dwSpeakerVolume           AS DWORD   ' DWORD dwSpeakerVolume
   dwSpeakerMode             AS DWORD   ' DWORD dwSpeakerMode
   dwModemOptions            AS DWORD   ' DWORD dwModemOptions
   dwMaxDTERate              AS DWORD   ' DWORD dwMaxDTERate
   dwMaxDCERate              AS DWORD   ' DWORD dwMaxDCERate

   ' Variable portion for proprietary expansion
   abVariablePortion(0)      AS BYTE    ' BYTE    abVariablePortion [1]
END TYPE

' // Size = 48 bytes
TYPE MODEMSETTINGS DWORD
   dwActualSize              AS DWORD   ' DWORD dwActualSize
   dwRequiredSize            AS DWORD   ' DWORD dwRequiredSize
   dwDevSpecificOffset       AS DWORD   ' DWORD dwDevSpecificOffset
   dwDevSpecificSize         AS DWORD   ' DWORD dwDevSpecificSize

   ' static local options (read/write)
   dwCallSetupFailTimer      AS DWORD   ' DWORD dwCallSetupFailTimer
   dwInactivityTimeout       AS DWORD   ' DWORD dwInactivityTimeout
   dwSpeakerVolume           AS DWORD   ' DWORD dwSpeakerVolume
   dwSpeakerMode             AS DWORD   ' DWORD dwSpeakerMode
   dwPreferredModemOptions   AS DWORD   ' DWORD dwPreferredModemOptions

   ' negotiated options (read only) for current or last call
   dwNegotiatedModemOptions  AS DWORD   ' DWORD dwNegotiatedDCERate
   dwNegotiatedDCERate       AS DWORD   ' DWORD dwNegotiatedDCERate

   ' Variable portion for proprietary expansion
   abVariablePortion(0)      AS BYTE    ' BYTE    abVariablePortion [1]
END TYPE

'// Dial Options
%DIALOPTION_BILLING    = &H00000040???    ' Supports wait for bong "$"
%DIALOPTION_QUIET      = &H00000080???    ' Supports wait for quiet "@"
%DIALOPTION_DIALTONE   = &H00000100???    ' Supports wait for dial tone "W"

'// SpeakerVolume for MODEMDEVCAPS
%MDMVOLFLAG_LOW        = &H00000001???
%MDMVOLFLAG_MEDIUM     = &H00000002???
%MDMVOLFLAG_HIGH       = &H00000004???

'// SpeakerVolume for MODEMSETTINGS
%MDMVOL_LOW            = &H00000000???
%MDMVOL_MEDIUM         = &H00000001???
%MDMVOL_HIGH           = &H00000002???

'// SpeakerMode for MODEMDEVCAPS
'%MDMSPKRFLAG_OFF      = &H00000001???
%MDMSPKRFLAG_DIAL      = &H00000002???
%MDMSPKRFLAG_ON        = &H00000004???
%MDMSPKRFLAG_CALLSETUP = &H00000008???

'// SpeakerMode for MODEMSETTINGS
%MDMSPKR_OFF           = &H00000000???
%MDMSPKR_DIAL          = &H00000001???
%MDMSPKR_ON            = &H00000002???
%MDMSPKR_CALLSETUP     = &H00000003???

'// Modem Options
%MDM_COMPRESSION       = &H00000001???
%MDM_ERROR_CONTROL     = &H00000002???
%MDM_FORCED_EC         = &H00000004???
%MDM_CELLULAR          = &H00000008???
%MDM_FLOWCONTROL_HARD  = &H00000010???
%MDM_FLOWCONTROL_SOFT  = &H00000020???
%MDM_CCITT_OVERRIDE    = &H00000040???
%MDM_SPEED_ADJUST      = &H00000080???
%MDM_TONE_DIAL         = &H00000100???
%MDM_BLIND_DIAL        = &H00000200???
%MDM_V23_OVERRIDE      = &H00000400???
%MDM_DIAGNOSTICS       = &H00000800???

'//=========================================================================
'//
'//
'//      EXTENDED MODEM OPTIONS INFORMATION
'//
'//      THE following macros define additional bits in dwPreferredModemOptions.
'//
'//      These bits specify information relevant to making ISDN and GSM
'//      calls, such as which protocol to use.
'//
'//=========================================================================

%MDM_MASK_BEARERMODE    = &H0000f000???
%MDM_SHIFT_BEARERMODE   = 12

%MDM_MASK_PROTOCOLID    = &H000f0000???
%MDM_SHIFT_PROTOCOLID   = 16

%MDM_MASK_PROTOCOLDATA  = &H0ff00000???
%MDM_SHIFT_PROTOCOLDATA = 20

'//
'// PROTOCOLINFO is the union of PROTOCOLID and PROTOCOLDATA ...
'//
%MDM_MASK_PROTOCOLINFO  = %MDM_MASK_PROTOCOLID OR %MDM_MASK_PROTOCOLDATA
%MDM_SHIFT_PROTOCOLINFO = %MDM_SHIFT_PROTOCOLID

'//
'// EXTENDEDINFO is the union of BEARERMODE and PROTOCOLINFO
'//
%MDM_MASK_EXTENDEDINFO  = %MDM_MASK_BEARERMODE OR %MDM_MASK_PROTOCOLINFO
%MDM_SHIFT_EXTENDEDINFO = %MDM_SHIFT_BEARERMODE

'#define MDM_GET_BEARERMODE(_dwOptions) \
'                   (((_dwOptions)&MDM_MASK_BEARERMODE) >> MDM_SHIFT_BEARERMODE)

FUNCTION MDM_GET_BEARERMODE (BYVAL dwOptions_ AS DWORD) AS DWORD
   dwOptions_ = dwOptions_ AND %MDM_MASK_BEARERMODE
   SHIFT RIGHT dwOptions_, %MDM_SHIFT_BEARERMODE
   FUNCTION = dwOptions_
END FUNCTION

'#define MDM_SET_BEARERMODE(_dwOptions,_bm)     \
'    (((_dwOptions) &= ~MDM_MASK_BEARERMODE), \
'    ((_dwOptions)  |= (((_bm)<<MDM_SHIFT_BEARERMODE)&MDM_MASK_BEARERMODE)))

SUB MDM_SET_BEARERMODE (BYREF dwOptions_ AS DWORD, BYVAL bm_ AS DWORD)
   dwOptions_ AND= NOT %MDM_MASK_BEARERMODE
   SHIFT LEFT bm_, %MDM_SHIFT_BEARERMODE
   dwOptions_ OR= bm_ AND %MDM_MASK_BEARERMODE
END SUB

'#define MDM_GET_PROTOCOLID(_dwOptions) \
'               (((_dwOptions)&MDM_MASK_PROTOCOLID) >> MDM_SHIFT_PROTOCOLID)

FUNCTION MDM_GET_PROTOCOLID (BYVAL dwOptions_ AS DWORD) AS DWORD
   dwOptions_ = dwOptions_ AND %MDM_MASK_PROTOCOLID
   SHIFT RIGHT dwOptions_, %MDM_SHIFT_PROTOCOLID
   FUNCTION = dwOptions_
END FUNCTION

'#define MDM_SET_PROTOCOLID(_dwOptions,_prot)     \
'    (((_dwOptions) &= ~MDM_MASK_PROTOCOLID), \
'    ((_dwOptions)  |= (((_prot)<<MDM_SHIFT_PROTOCOLID)&MDM_MASK_PROTOCOLID)))

SUB MDM_SET_PROTOCOLID (BYREF dwOptions_ AS DWORD, BYVAL prot_ AS DWORD)
   dwOptions_ AND= NOT %MDM_MASK_PROTOCOLID
   SHIFT LEFT prot_, %MDM_SHIFT_PROTOCOLID
   dwOptions_ OR= prot_ AND %MDM_MASK_PROTOCOLID
END SUB

'#define MDM_GET_PROTOCOLDATA(_dwOptions) \
'               (((_dwOptions)&MDM_MASK_PROTOCOLDATA) >> MDM_SHIFT_PROTOCOLDATA)

FUNCTION MDM_GET_PROTOCOLDATA (BYVAL dwOptions_ AS DWORD) AS DWORD
   dwOptions_ = dwOptions_ AND %MDM_MASK_PROTOCOLDATA
   SHIFT RIGHT dwOptions_, %MDM_SHIFT_PROTOCOLDATA
   FUNCTION = dwOptions_
END FUNCTION

'#define MDM_SET_PROTOCOLDATA(_dwOptions,_pd)     \
'   (((_dwOptions) &= ~MDM_MASK_PROTOCOLDATA), \
'   ((_dwOptions)  |= (((_pd)<<MDM_SHIFT_PROTOCOLDATA)&MDM_MASK_PROTOCOLDATA)))

SUB MDM_SET_PROTOCOLDATA (BYREF dwOptions_ AS DWORD, BYVAL pd_ AS DWORD)
   dwOptions_ AND= NOT %MDM_MASK_PROTOCOLDATA
   SHIFT LEFT pd_, %MDM_SHIFT_PROTOCOLDATA
   dwOptions_ OR= pd_ AND %MDM_MASK_PROTOCOLDATA
END SUB

'//
'// MDM_GET_PROTOCOLINFO gets the protocol-id and info bits in
'// their IN-PLACE form (preserving their place in dwModemPreferredOptions)
'//
'#define MDM_GET_PROTOCOLINFO(_dwOptions) \
'               ((_dwOptions)&MDM_MASK_PROTOCOLINFO)

FUNCTION MDM_GET_PROTOCOLINFO (BYVAL dwOptions_ AS DWORD) AS DWORD
   dwOptions_ = dwOptions_ AND %MDM_MASK_PROTOCOLINFO
   FUNCTION = dwOptions_
END FUNCTION

'//
'// MDM_SET_PROTOCOLINFO takes as its argument the protocol-id and info bits in
'// their IN-PLACE form (final position within dwModemPreferredOptions)
'//
'#define MDM_SET_PROTOCOLINFO(_dwOptions,_pinfo)     \
'  (((_dwOptions) &= ~MDM_MASK_PROTOCOLINFO), \
'  ((_dwOptions)  |= ((_pinfo)&MDM_MASK_PROTOCOLINFO)))

SUB MDM_SET_PROTOCOLINFO (BYREF dwOptions_ AS DWORD, BYVAL pinfo_ AS DWORD)
   dwOptions_ AND= NOT %MDM_MASK_PROTOCOLINFO
   dwOptions_ OR= pinfo_ AND %MDM_MASK_PROTOCOLINFO
END SUB

'//
'// MDM_GEN_PROTOCOLINFO generates the  the protocol-id and info bits in
'// their IN-PLACE form (final position  within dwModemPreferredOptions).
'//
'#define MDM_GEN_PROTOCOLINFO(_pid, _pdata) \
'        ((((_pid  )<<MDM_SHIFT_PROTOCOLID  )&MDM_MASK_PROTOCOLID  )   \
'        |(((_pdata)<<MDM_SHIFT_PROTOCOLDATA)&MDM_MASK_PROTOCOLDATA))

FUNCTION MDM_GEN_PROTOCOLINFO (BYVAL pid_ AS DWORD, BYVAL pdata_ AS DWORD) AS DWORD
   SHIFT LEFT pid_, %MDM_SHIFT_PROTOCOLID
   pid_ AND= %MDM_MASK_PROTOCOLID
   SHIFT LEFT pdata_, %MDM_SHIFT_PROTOCOLDATA
   pdata_ AND= %MDM_MASK_PROTOCOLDATA
   FUNCTION = pid_ OR pdata_
END FUNCTION

'//
'// MDM_GET_EXTENDEDIONFO gets the bearermode and protocol information in
'// their IN-PLACE form (preserving their place in dwModemPreferredOptions)
'//
'#define MDM_GET_EXTENDEDINFO(_dwOptions) \
'               ((_dwOptions)&MDM_MASK_EXTENDEDINFO)

FUNCTION MDM_GET_EXTENDEDINFO (BYVAL dwOptions_ AS DWORD) AS DWORD
   dwOptions_ = dwOptions_ AND %MDM_MASK_EXTENDEDINFO
   FUNCTION = dwOptions_
END FUNCTION

'//
'// MDM_SET_PROTOCOLINFO takes as its argument the bearermode and
'// protocol bits in their IN-PLACE form (final position within
'// dwModemPreferredOptions)
'//
'#define MDM_SET_EXTENDEDINFO(_dwOptions,_extinfo)     \
'  (((_dwOptions) &= ~MDM_MASK_EXTENDEDINFO), \
'  ((_dwOptions)  |= ((_extinfo) & MDM_MASK_EXTENDEDINFO)))

SUB MDM_SET_EXTENDEDINFO (BYREF dwOptions_ AS DWORD, BYVAL extinfo_ AS DWORD)
   dwOptions_ AND= NOT %MDM_MASK_EXTENDEDINFO
   dwOptions_ OR= extinfo_ AND %MDM_MASK_EXTENDEDINFO
END SUB

'//
'// MDM_GEN_EXTENDEDINFO generates the bearermode and protocol information
'// in their IN-PLACE form (final position within dwModemPreferredOptions0.
'//
'#define MDM_GEN_EXTENDEDINFO(_bearermode, _pinfo)   \
'        (((_pinfo)&MDM_MASK_PROTOCOLINFO  )         \
'         |(((_bearermode)<<MDM_SHIFT_BEARERMODE)&MDM_MASK_BEARERMODE))

FUNCTION MDM_GEN_EXTENDEDINFO (BYVAL bearermode_ AS DWORD, BYVAL pinfo_ AS DWORD) AS DWORD
   SHIFT LEFT bearermode_, %MDM_SHIFT_BEARERMODE
   bearermode_ AND= %MDM_MASK_BEARERMODE
   bearermode_ OR= pinfo_ AND %MDM_MASK_PROTOCOLINFO
   FUNCTION = bearermode_
END FUNCTION

'//=========================================================================
'//  BEARER MODES
'//=========================================================================
'//
%MDM_BEARERMODE_ANALOG   = &H0
%MDM_BEARERMODE_ISDN     = &H1
%MDM_BEARERMODE_GSM      = &H2

'//=========================================================================
'//  PROTOCOL IDs
'//=========================================================================
'//
%MDM_PROTOCOLID_DEFAULT  = &H0
%MDM_PROTOCOLID_HDLCPPP  = &H1
%MDM_PROTOCOLID_V128     = &H2
%MDM_PROTOCOLID_X75      = &H3
%MDM_PROTOCOLID_V110     = &H4
%MDM_PROTOCOLID_V120     = &H5
%MDM_PROTOCOLID_AUTO     = &H6 ' // Auto protocol detection.
%MDM_PROTOCOLID_ANALOG   = &H7 ' // Applicable only to GSM
%MDM_PROTOCOLID_GPRS     = &H8
%MDM_PROTOCOLID_PIAFS    = &H9

'//=========================================================================
'//  HDLC PPP PROTOCOL INFORMATION
'//=========================================================================
'//
'// Following are specific to the HDLC-PPP protocol.
'// The shifts are w.r.t. the start of the PROTOCOLDATA field.

%MDM_SHIFT_HDLCPPP_SPEED    = &H0
%MDM_MASK_HDLCPPP_SPEED     = &H7  ' // 3 bits

%MDM_HDLCPPP_SPEED_DEFAULT  = &H0
%MDM_HDLCPPP_SPEED_64K      = &H1
%MDM_HDLCPPP_SPEED_56K      = &H2

%MDM_SHIFT_HDLCPPP_AUTH     = &H3
%MDM_MASK_HDLCPPP_AUTH      = &H38  ' (0x7<<3)  // 3 bits

%MDM_HDLCPPP_AUTH_DEFAULT   = &H0
%MDM_HDLCPPP_AUTH_NONE      = &H1
%MDM_HDLCPPP_AUTH_PAP       = &H2
%MDM_HDLCPPP_AUTH_CHAP      = &H3
%MDM_HDLCPPP_AUTH_MSCHAP    = &H4

%MDM_SHIFT_HDLCPPP_ML       = &H6
%MDM_MASK_HDLCPPP_ML        = &HC0   ' (0x3<<6)  // 2 bits

%MDM_HDLCPPP_ML_DEFAULT     = &H0
%MDM_HDLCPPP_ML_NONE        = &H1
%MDM_HDLCPPP_ML_2           = &H2

'#define MDM_GEN_HDLCPPP_PROTOCOL_DATA(_speed, _auth, _ml)           \
'    ((((_speed)<<MDM_SHIFT_HDLCPPP_SPEED)&MDM_MASK_HDLCPPP_SPEED)   \
'    |(((_auth )<<MDM_SHIFT_HDLCPPP_AUTH )&MDM_MASK_HDLCPPP_AUTH )   \
'    |(((_ml   )<<MDM_SHIFT_HDLCPPP_ML   )&MDM_MASK_HDLCPPP_ML   ))

FUNCTION MDM_GEN_HDLCPPP_PROTOCOL_DATA (BYVAL speed_ AS DWORD, BYVAL auth_ AS DWORD, BYVAL ml_ AS DWORD) AS DWORD
   SHIFT LEFT speed_, %MDM_SHIFT_HDLCPPP_SPEED
   speed_ AND= %MDM_MASK_HDLCPPP_SPEED
   SHIFT LEFT auth_, %MDM_SHIFT_HDLCPPP_AUTH
   auth_ AND= %MDM_MASK_HDLCPPP_AUTH
   SHIFT LEFT ml_, %MDM_SHIFT_HDLCPPP_ML
   ml_ AND= %MDM_MASK_HDLCPPP_ML
   FUNCTION = speed_ OR auth_ OR ml_
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_64K        \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_64K,      \
'            MDM_HDLCPPP_AUTH_DEFAULT,   \
'            MDM_HDLCPPP_ML_DEFAULT      \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_64K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K, %MDM_HDLCPPP_AUTH_DEFAULT, %MDM_HDLCPPP_ML_DEFAULT))
END FUNCTION


'#define MDM_PROTOCOL_HDLCPPP_56K        \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_56K,      \
'            MDM_HDLCPPP_AUTH_DEFAULT,   \
'            MDM_HDLCPPP_ML_DEFAULT      \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_56K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K, %MDM_HDLCPPP_AUTH_DEFAULT, %MDM_HDLCPPP_ML_DEFAULT))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_112K       \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_56K,      \
'            MDM_HDLCPPP_AUTH_DEFAULT,   \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_112K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K, %MDM_HDLCPPP_AUTH_DEFAULT, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_112K_PAP   \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_56K,      \
'            MDM_HDLCPPP_AUTH_PAP,       \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_112K_PAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K, %MDM_HDLCPPP_AUTH_PAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_112K_CHAP  \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_56K,      \
'            MDM_HDLCPPP_AUTH_CHAP,      \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_112K_CHAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K, %MDM_HDLCPPP_AUTH_CHAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_112K_MSCHAP\
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_56K,      \
'            MDM_HDLCPPP_AUTH_MSCHAP,    \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_112K_MSCHAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_56K, %MDM_HDLCPPP_AUTH_MSCHAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_128K       \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_64K,      \
'            MDM_HDLCPPP_AUTH_DEFAULT,   \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_128K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA (%MDM_HDLCPPP_SPEED_64K, %MDM_HDLCPPP_AUTH_DEFAULT, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_128K_PAP   \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_64K,      \
'            MDM_HDLCPPP_AUTH_PAP,       \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_128K_PAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K, %MDM_HDLCPPP_AUTH_PAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_128K_CHAP  \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_64K,      \
'            MDM_HDLCPPP_AUTH_CHAP,      \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_128K_CHAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K, %MDM_HDLCPPP_AUTH_CHAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_HDLCPPP_128K_MSCHAP\
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_HDLCPPP,         \
'        MDM_GEN_HDLCPPP_PROTOCOL_DATA ( \
'            MDM_HDLCPPP_SPEED_64K,      \
'            MDM_HDLCPPP_AUTH_MSCHAP,    \
'            MDM_HDLCPPP_ML_2            \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_HDLCPPP_128K_MSCHAP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_HDLCPPP, MDM_GEN_HDLCPPP_PROTOCOL_DATA(%MDM_HDLCPPP_SPEED_64K, %MDM_HDLCPPP_AUTH_MSCHAP, %MDM_HDLCPPP_ML_2))
END FUNCTION

'//=========================================================================
'//  V120 PROTOCOL INFORMATION
'//
'// The shifts are w.r.t. the start of the PROTOCOLDATA field.
'//
'//=========================================================================

%MDM_SHIFT_V120_SPEED    = &H0
%MDM_MASK_V120_SPEED     = &H7  ' // 3 bits

%MDM_V120_SPEED_DEFAULT  = &H0
%MDM_V120_SPEED_64K      = &H1
%MDM_V120_SPEED_56K      = &H2

%MDM_SHIFT_V120_ML       = &H6
%MDM_MASK_V120_ML        = &HC0   ' (0x3<<6)  // 2 bits

%MDM_V120_ML_DEFAULT     = &H0
%MDM_V120_ML_NONE        = &H1
%MDM_V120_ML_2           = &H2

'#define MDM_GEN_V120_PROTOCOL_DATA(_speed, _ml)               \
'    ((((_speed)<<MDM_SHIFT_V120_SPEED)&MDM_MASK_V120_SPEED)   \
'    |(((_ml   )<<MDM_SHIFT_V120_ML   )&MDM_MASK_V120_ML   ))

FUNCTION MDM_GEN_V120_PROTOCOL_DATA(BYVAL speed_ AS DWORD, BYVAL ml_ AS DWORD) AS DWORD
   SHIFT LEFT speed_, %MDM_SHIFT_V120_SPEED
   speed_ AND= %MDM_MASK_V120_SPEED
   SHIFT LEFT ml_, %MDM_SHIFT_V120_ML
   ml_ AND= %MDM_MASK_V120_ML
   FUNCTION = speed_ OR ml_
END FUNCTION

'#define MDM_PROTOCOL_V120_64K       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V120,        \
'        MDM_GEN_V120_PROTOCOL_DATA (\
'            MDM_V120_SPEED_64K,     \
'            MDM_V120_ML_NONE        \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V120_64K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120, MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_64K, %MDM_V120_ML_NONE))
END FUNCTION

'#define MDM_PROTOCOL_V120_56K       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V120,        \
'        MDM_GEN_V120_PROTOCOL_DATA (\
'            MDM_V120_SPEED_56K,     \
'            MDM_V120_ML_NONE        \
'            )                       \
'        )
FUNCTION MDM_PROTOCOL_V120_56K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120, MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_56K, %MDM_V120_ML_NONE))
END FUNCTION

'#define MDM_PROTOCOL_V120_112K      \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V120,        \
'        MDM_GEN_V120_PROTOCOL_DATA (\
'            MDM_V120_SPEED_56K,     \
'            MDM_V120_ML_2           \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V120_112K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120, MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_56K, %MDM_V120_ML_2))
END FUNCTION

'#define MDM_PROTOCOL_V120_128K      \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V120,        \
'        MDM_GEN_V120_PROTOCOL_DATA (\
'            MDM_V120_SPEED_64K,     \
'            MDM_V120_ML_2           \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V120_128K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V120, MDM_GEN_V120_PROTOCOL_DATA(%MDM_V120_SPEED_64K, %MDM_V120_ML_2))
END FUNCTION

'//=========================================================================
'//  X75 PROTOCOL INFORMATION
'//
'// The shifts are w.r.t. the start of the PROTOCOLDATA field.
'//
'//=========================================================================


%MDM_SHIFT_X75_DATA    = &H0
%MDM_MASK_X75_DATA     = &H7  ' // 3 bits

%MDM_X75_DATA_DEFAULT  = &H0
%MDM_X75_DATA_64K      = &H1
%MDM_X75_DATA_128K     = &H2
%MDM_X75_DATA_T_70     = &H3
%MDM_X75_DATA_BTX      = &H4

'#define MDM_GEN_X75_PROTOCOL_DATA(_data) \
'    (((_data)<<MDM_SHIFT_X75_DATA)&MDM_MASK_X75_DATA)

FUNCTION MDM_GEN_X75_PROTOCOL_DATA (BYVAL data_ AS DWORD) AS DWORD
   SHIFT LEFT data_, %MDM_SHIFT_X75_DATA
   data_ AND= %MDM_MASK_X75_DATA
   FUNCTION = data_
END FUNCTION


'#define MDM_PROTOCOL_X75_64K        \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_X75,         \
'        MDM_GEN_X75_PROTOCOL_DATA ( \
'            MDM_X75_DATA_64K        \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_X75_64K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75, MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_64K))
END FUNCTION

'#define MDM_PROTOCOL_X75_128K       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_X75,         \
'        MDM_GEN_X75_PROTOCOL_DATA ( \
'            MDM_X75_DATA_128K       \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_X75_128K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75, MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_128K))
END FUNCTION

'#define MDM_PROTOCOL_X75_T_70       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_X75,         \
'        MDM_GEN_X75_PROTOCOL_DATA ( \
'            MDM_X75_DATA_T_70       \
'            )                       \
'        )                           \

FUNCTION MDM_PROTOCOL_X75_T_70 () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75, MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_T_70))
END FUNCTION

'#define MDM_PROTOCOL_X75_BTX        \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_X75,         \
'        MDM_GEN_X75_PROTOCOL_DATA ( \
'            MDM_X75_DATA_BTX        \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_X75_BTX () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_X75, MDM_GEN_X75_PROTOCOL_DATA(%MDM_X75_DATA_BTX))
END FUNCTION

'//=========================================================================
'//  V110 PROTOCOL INFORMATION
'//
'// The shifts are w.r.t. the start of the PROTOCOLDATA field.
'//
'//=========================================================================


%MDM_SHIFT_V110_SPEED   = &H0
%MDM_MASK_V110_SPEED    = &Hf  ' // 4 bits

%MDM_V110_SPEED_DEFAULT = &H0
%MDM_V110_SPEED_1DOT2K  = &H1
%MDM_V110_SPEED_2DOT4K  = &H2
%MDM_V110_SPEED_4DOT8K  = &H3
%MDM_V110_SPEED_9DOT6K  = &H4
%MDM_V110_SPEED_12DOT0K = &H5
%MDM_V110_SPEED_14DOT4K = &H6
%MDM_V110_SPEED_19DOT2K = &H7
%MDM_V110_SPEED_28DOT8K = &H8
%MDM_V110_SPEED_38DOT4K = &H9
%MDM_V110_SPEED_57DOT6K = &HA

'#define MDM_GEN_V110_PROTOCOL_DATA(_data) \
'    (((_data)<<MDM_SHIFT_V110_SPEED)&MDM_MASK_V110_SPEED)

FUNCTION MDM_GEN_V110_PROTOCOL_DATA (BYVAL data_ AS DWORD) AS DWORD
   SHIFT LEFT data_, %MDM_SHIFT_V110_SPEED
   data_ AND= %MDM_MASK_V110_SPEED
   FUNCTION = data_
END FUNCTION

'#define MDM_PROTOCOL_V110_1DOT2K    \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_1DOT2K   \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_1DOT2K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_1DOT2K))
END FUNCTION

'#define MDM_PROTOCOL_V110_2DOT4K    \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_2DOT4K   \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_2DOT4K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_2DOT4K))
END FUNCTION

'#define MDM_PROTOCOL_V110_4DOT8K    \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_4DOT8K   \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_4DOT8K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_4DOT8K))
END FUNCTION

'#define MDM_PROTOCOL_V110_9DOT6K    \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_9DOT6K   \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_9DOT6K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_9DOT6K))
END FUNCTION

'#define MDM_PROTOCOL_V110_12DOT0K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_12DOT0K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_12DOT0K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_12DOT0K))
END FUNCTION

'#define MDM_PROTOCOL_V110_14DOT4K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_14DOT4K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_14DOT4K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_14DOT4K))
END FUNCTION

'#define MDM_PROTOCOL_V110_19DOT2K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_19DOT2K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_19DOT2K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_19DOT2K))
END FUNCTION

'#define MDM_PROTOCOL_V110_28DOT8K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_28DOT8K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_28DOT8K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_28DOT8K))
END FUNCTION

'#define MDM_PROTOCOL_V110_38DOT4K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_38DOT4K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_38DOT4K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_38DOT4K))
END FUNCTION

'#define MDM_PROTOCOL_V110_57DOT6K   \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_V110,        \
'        MDM_GEN_V110_PROTOCOL_DATA (\
'            MDM_V110_SPEED_57DOT6K  \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_V110_57DOT6K () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_V110, MDM_GEN_V110_PROTOCOL_DATA(%MDM_V110_SPEED_57DOT6K))
END FUNCTION

'//=========================================================================
'//  AUTO PROTOCOL INFORMATION (ie, when the protocol is detected automatically)
'//
'// The shifts are w.r.t. the start of the PROTOCOLDATA field.
'//
'//=========================================================================
'//
'// Following are specific to the AUTO-protocol
'//

%MDM_SHIFT_AUTO_SPEED    = &H0
%MDM_MASK_AUTO_SPEED     = &H7  ' // 3 bits
%MDM_AUTO_SPEED_DEFAULT  = &H0

%MDM_SHIFT_AUTO_ML       = &H6
%MDM_MASK_AUTO_ML        = &HC0  ' 0x3<<6)  // 2 bits
%MDM_AUTO_ML_DEFAULT     = &H0
%MDM_AUTO_ML_NONE        = &H1
%MDM_AUTO_ML_2           = &H2

'#define MDM_GEN_AUTO_PROTOCOL_DATA(_speed, _ml)             \
'    ((((_speed)<<MDM_SHIFT_AUTO_SPEED)&MDM_MASK_AUTO_SPEED) \
'    |(((_ml   )<<MDM_SHIFT_AUTO_ML   )&MDM_MASK_AUTO_ML))

FUNCTION MDM_GEN_AUTO_PROTOCOL_DATA (BYVAL speed_ AS DWORD, BYVAL ml_ AS DWORD) AS DWORD
   SHIFT LEFT speed_, %MDM_SHIFT_AUTO_SPEED
   speed_ AND= %MDM_MASK_AUTO_SPEED
   SHIFT LEFT ml_, %MDM_SHIFT_AUTO_ML
   ml_ AND= %MDM_MASK_AUTO_ML
   FUNCTION = speed_ OR ml_
END FUNCTION

'#define MDM_PROTOCOL_AUTO_1CH       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_AUTO,        \
'        MDM_GEN_AUTO_PROTOCOL_DATA (\
'            MDM_AUTO_SPEED_DEFAULT, \
'            MDM_AUTO_ML_NONE        \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_AUTO_1CH () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_AUTO, MDM_GEN_AUTO_PROTOCOL_DATA(%MDM_AUTO_SPEED_DEFAULT, %MDM_AUTO_ML_NONE))
END FUNCTION

'#define MDM_PROTOCOL_AUTO_2CH       \
'    MDM_GEN_PROTOCOLINFO(           \
'        MDM_PROTOCOLID_AUTO,        \
'        MDM_GEN_AUTO_PROTOCOL_DATA (\
'            MDM_AUTO_SPEED_DEFAULT, \
'            MDM_AUTO_ML_2           \
'            )                       \
'        )

FUNCTION MDM_PROTOCOL_AUTO_2CH () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_AUTO, MDM_GEN_AUTO_PROTOCOL_DATA(%MDM_AUTO_SPEED_DEFAULT, %MDM_AUTO_ML_2))
END FUNCTION

'//=========================================================================
'//  ANALOG PROTOCOL INFORMATION (Applicable only to GSM)
'//=========================================================================
'//
'// Following are specific to GSM Analog protocol
'//

%MDM_ANALOG_RLP_ON       = &H0
%MDM_ANALOG_RLP_OFF      = &H1
%MDM_ANALOG_V34          = &H2

'#define MDM_GEN_ANALOG_PROTOCOL_DATA(_rlp) \
'    (_rlp)

FUNCTION MDM_GEN_ANALOG_PROTOCOL_DATA (BYVAL rlp_ AS DWORD) AS DWORD
   FUNCTION = rlp_
END FUNCTION

'#define MDM_PROTOCOL_ANALOG_RLP         \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_ANALOG,          \
'        MDM_GEN_ANALOG_PROTOCOL_DATA (  \
'            MDM_ANALOG_RLP_ON           \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_ANALOG_RLP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG, MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_RLP_ON))
END FUNCTION

'#define MDM_PROTOCOL_ANALOG_NRLP        \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_ANALOG,          \
'        MDM_GEN_ANALOG_PROTOCOL_DATA (  \
'            MDM_ANALOG_RLP_OFF          \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_ANALOG_NRLP () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG, MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_RLP_OFF))
END FUNCTION

'//
'//  v34 anolog for isdn
'//
'#define MDM_PROTOCOL_ANALOG_V34         \
'    MDM_GEN_PROTOCOLINFO(               \
'        MDM_PROTOCOLID_ANALOG,          \
'        MDM_GEN_ANALOG_PROTOCOL_DATA (  \
'            MDM_ANALOG_V34              \
'            )                           \
'        )

FUNCTION MDM_PROTOCOL_ANALOG_V34 () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_ANALOG, MDM_GEN_ANALOG_PROTOCOL_DATA(%MDM_ANALOG_V34))
END FUNCTION

'//=========================================================================
'//  GPRS PROTOCOL INFORMATION (Applicable only to GSM)
'//=========================================================================
'//
'// Following are specific to GPRS protocol
'//

'#define MDM_PROTOCOL_GPRS             \
'    MDM_GEN_PROTOCOLINFO(             \
'        MDM_PROTOCOLID_GPRS,          \
'        0                             \
'        )

FUNCTION MDM_PROTOCOL_GPRS () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_GPRS, 0)
END FUNCTION

'//=========================================================================
'//  PIAFS PROTOCOL INFORMATION
'//=========================================================================
'//
'// Following are specific to PIAFS protocol
'//

%MDM_PIAFS_INCOMING           = 0
%MDM_PIAFS_OUTGOING           = 1

'#define MDM_PROTOCOL_PIAFS_INCOMING   \
'    MDM_GEN_PROTOCOLINFO(             \
'        MDM_PROTOCOLID_PIAFS,         \
'        MDM_PIAFS_INCOMING            \
'        )

FUNCTION MDM_PROTOCOL_PIAFS_INCOMING () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_PIAFS, %MDM_PIAFS_INCOMING)
END FUNCTION

'#define MDM_PROTOCOL_PIAFS_OUTGOING   \
'    MDM_GEN_PROTOCOLINFO(             \
'        MDM_PROTOCOLID_PIAFS,         \
'        MDM_PIAFS_OUTGOING           \
'        )

FUNCTION MDM_PROTOCOL_PIAFS_OUTGOING () AS DWORD
   FUNCTION = MDM_GEN_PROTOCOLINFO(%MDM_PROTOCOLID_PIAFS, %MDM_PIAFS_OUTGOING)
END FUNCTION
