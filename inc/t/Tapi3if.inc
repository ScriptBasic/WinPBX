' ########################################################################################
' Microsoft Windows
' File: Tapi3if.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TAPI3IF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "tapi3.inc"

'typedef long TAPIHWND;

'#endif
'#ifdef _X86_
'typedef long TAPIHWND;
'#else
'typedef LONGLONG TAPIHWND;
'#endif
'typedef long TAPI_DIGITMODE;

' enum TAPI_TONEMODE
%TTM_RINGBACK = &H2
%TTM_BUSY     = &H4
%TTM_BEEP     = &H8
%TTM_BILLING  = &H10

' enum TAPI_GATHERTERM
%TGT_BUFFERFULL   = &H1
%TGT_TERMDIGIT    = &H2
%TGT_FIRSTTIMEOUT = &H4
%TGT_INTERTIMEOUT = &H8
%TGT_CANCEL       = &H10

' // Size = 16 bytes
TYPE TAPI_CUSTOMTONE DWORD
   dwFrequency  AS DWORD
   dwCadenceOn  AS DWORD
   dwCadenceOff AS DWORD
   dwVolume     AS DWORD
END TYPE

' // Size = 20 bytes
TYPE TAPI_DETECTTONE DWORD
   dwAppSpecific AS DWORD
   dwDuration    AS DWORD
   dwFrequency1  AS DWORD
   dwFrequency2  AS DWORD
   dwFrequency3  AS DWORD
END TYPE

' enum ADDRESS_EVENT
%AE_STATE          = 0
%AE_CAPSCHANGE     = %AE_STATE          + 1
%AE_RINGING        = %AE_CAPSCHANGE     + 1
%AE_CONFIGCHANGE   = %AE_RINGING        + 1
%AE_FORWARD        = %AE_CONFIGCHANGE   + 1
%AE_NEWTERMINAL    = %AE_FORWARD        + 1
%AE_REMOVETERMINAL = %AE_NEWTERMINAL    + 1
%AE_MSGWAITON      = %AE_REMOVETERMINAL + 1
%AE_MSGWAITOFF     = %AE_MSGWAITON      + 1
%AE_LASTITEM       = %AE_MSGWAITOFF

' enum ADDRESS_STATE
%AS_INSERVICE    = 0
%AS_OUTOFSERVICE = 1

' enum CALL_STATE
%CS_IDLE         = 0
%CS_INPROGRESS   = %CS_IDLE         + 1
%CS_CONNECTED    = %CS_INPROGRESS   + 1
%CS_DISCONNECTED = %CS_CONNECTED    + 1
%CS_OFFERING     = %CS_DISCONNECTED + 1
%CS_HOLD         = %CS_OFFERING     + 1
%CS_QUEUED       = %CS_HOLD         + 1
%CS_LASTITEM     = %CS_QUEUED

' enum CALL_STATE_EVENT_CAUSE
%CEC_NONE                  = 0
%CEC_DISCONNECT_NORMAL     = %CEC_NONE                  + 1
%CEC_DISCONNECT_BUSY       = %CEC_DISCONNECT_NORMAL     + 1
%CEC_DISCONNECT_BADADDRESS = %CEC_DISCONNECT_BUSY       + 1
%CEC_DISCONNECT_NOANSWER   = %CEC_DISCONNECT_BADADDRESS + 1
%CEC_DISCONNECT_CANCELLED  = %CEC_DISCONNECT_NOANSWER   + 1
%CEC_DISCONNECT_REJECTED   = %CEC_DISCONNECT_CANCELLED  + 1
%CEC_DISCONNECT_FAILED     = %CEC_DISCONNECT_REJECTED   + 1
%CEC_DISCONNECT_BLOCKED    = %CEC_DISCONNECT_FAILED     + 1

' enum CALL_MEDIA_EVENT
%CME_NEW_STREAM      = 0
%CME_STREAM_FAIL     = %CME_NEW_STREAM      + 1
%CME_TERMINAL_FAIL   = %CME_STREAM_FAIL     + 1
%CME_STREAM_NOT_USED = %CME_TERMINAL_FAIL   + 1
%CME_STREAM_ACTIVE   = %CME_STREAM_NOT_USED + 1
%CME_STREAM_INACTIVE = %CME_STREAM_ACTIVE   + 1
%CME_LASTITEM        = %CME_STREAM_INACTIVE

' enum CALL_MEDIA_EVENT_CAUSE
%CMC_UNKNOWN            = 0
%CMC_BAD_DEVICE         = %CMC_UNKNOWN         + 1
%CMC_CONNECT_FAIL       = %CMC_BAD_DEVICE      + 1
%CMC_LOCAL_REQUEST      = %CMC_CONNECT_FAIL    + 1
%CMC_REMOTE_REQUEST     = %CMC_LOCAL_REQUEST   + 1
%CMC_MEDIA_TIMEOUT      = %CMC_REMOTE_REQUEST  + 1
%CMC_MEDIA_RECOVERED    = %CMC_MEDIA_TIMEOUT   + 1
%CMC_QUALITY_OF_SERVICE = %CMC_MEDIA_RECOVERED + 1

' enum DISCONNECT_CODE
%DC_NORMAL   = 0
%DC_NOANSWER = %DC_NORMAL   + 1
%DC_REJECTED = %DC_NOANSWER + 1

' enum TERMINAL_STATE
%TS_INUSE    = 0
%TS_NOTINUSE = %TS_INUSE + 1

' enum TERMINAL_DIRECTION
%TD_CAPTURE          = 0
%TD_RENDER           = %TD_CAPTURE          + 1
%TD_BIDIRECTIONAL    = %TD_RENDER           + 1
%TD_MULTITRACK_MIXED = %TD_BIDIRECTIONAL    + 1
%TD_NONE             = %TD_MULTITRACK_MIXED + 1

' enum TERMINAL_TYPE
%TT_STATIC  = 0
%TT_DYNAMIC = %TT_STATIC + 1

' enum CALL_PRIVILEGE
%CP_OWNER   = 0
%CP_MONITOR = %CP_OWNER + 1

' enum TAPI_EVENT
%TE_TAPIOBJECT         = &H1
%TE_ADDRESS            = &H2
%TE_CALLNOTIFICATION   = &H4
%TE_CALLSTATE          = &H8
%TE_CALLMEDIA          = &H10
%TE_CALLHUB            = &H20
%TE_CALLINFOCHANGE     = &H40
%TE_PRIVATE            = &H80
%TE_REQUEST            = &H100
%TE_AGENT              = &H200
%TE_AGENTSESSION       = &H400
%TE_QOSEVENT           = &H800
%TE_AGENTHANDLER       = &H1000
%TE_ACDGROUP           = &H2000
%TE_QUEUE              = &H4000
%TE_DIGITEVENT         = &H8000
%TE_GENERATEEVENT      = &H10000
%TE_ASRTERMINAL        = &H20000
%TE_TTSTERMINAL        = &H40000
%TE_FILETERMINAL       = &H80000
%TE_TONETERMINAL       = &H100000
%TE_PHONEEVENT         = &H200000
%TE_TONEEVENT          = &H400000
%TE_GATHERDIGITS       = &H800000
%TE_ADDRESSDEVSPECIFIC = &H1000000
%TE_PHONEDEVSPECIFIC   = &H2000000

' enum CALL_NOTIFICATION_EVENT
%CNE_OWNER    = 0
%CNE_MONITOR  = %CNE_OWNER   + 1
%CNE_LASTITEM = %CNE_MONITOR

' enum CALLHUB_EVENT
%CHE_CALLJOIN    = 0
%CHE_CALLLEAVE   = %CHE_CALLJOIN    + 1
%CHE_CALLHUBNEW  = %CHE_CALLLEAVE   + 1
%CHE_CALLHUBIDLE = %CHE_CALLHUBNEW  + 1
%CHE_LASTITEM    = %CHE_CALLHUBIDLE

' enum CALLHUB_STATE
%CHS_ACTIVE = 0
%CHS_IDLE   = %CHS_ACTIVE + 1

' enum TAPIOBJECT_EVENT
%TE_ADDRESSCREATE   = 0
%TE_ADDRESSREMOVE   = %TE_ADDRESSCREATE   + 1
%TE_REINIT          = %TE_ADDRESSREMOVE   + 1
%TE_TRANSLATECHANGE = %TE_REINIT          + 1
%TE_ADDRESSCLOSE    = %TE_TRANSLATECHANGE + 1
%TE_PHONECREATE     = %TE_ADDRESSCLOSE    + 1
%TE_PHONEREMOVE     = %TE_PHONECREATE     + 1

' enum TAPI_OBJECT_TYPE
%TOT_NONE     = 0
%TOT_TAPI     = %TOT_NONE     + 1
%TOT_ADDRESS  = %TOT_TAPI     + 1
%TOT_TERMINAL = %TOT_ADDRESS  + 1
%TOT_CALL     = %TOT_TERMINAL + 1
%TOT_CALLHUB  = %TOT_CALL     + 1
%TOT_PHONE    = %TOT_CALLHUB  + 1

' enum QOS_SERVICE_LEVEL
%QSL_NEEDED       = 1
%QSL_IF_AVAILABLE = 2
%QSL_BEST_EFFORT  = 3

' enum QOS_EVENT
%QE_NOQOS            = 1
%QE_ADMISSIONFAILURE = 2
%QE_POLICYFAILURE    = 3
%QE_GENERICERROR     = 4
%QE_LASTITEM         = %QE_GENERICERROR

' enum CALLINFOCHANGE_CAUSE
%CIC_OTHER         = 0
%CIC_DEVSPECIFIC   = %CIC_OTHER         + 1
%CIC_BEARERMODE    = %CIC_DEVSPECIFIC   + 1
%CIC_RATE          = %CIC_BEARERMODE    + 1
%CIC_APPSPECIFIC   = %CIC_RATE          + 1
%CIC_CALLID        = %CIC_APPSPECIFIC   + 1
%CIC_RELATEDCALLID = %CIC_CALLID        + 1
%CIC_ORIGIN        = %CIC_RELATEDCALLID + 1
%CIC_REASON        = %CIC_ORIGIN        + 1
%CIC_COMPLETIONID  = %CIC_REASON        + 1
%CIC_NUMOWNERINCR  = %CIC_COMPLETIONID  + 1
%CIC_NUMOWNERDECR  = %CIC_NUMOWNERINCR  + 1
%CIC_NUMMONITORS   = %CIC_NUMOWNERDECR  + 1
%CIC_TRUNK         = %CIC_NUMMONITORS   + 1
%CIC_CALLERID      = %CIC_TRUNK         + 1
%CIC_CALLEDID      = %CIC_CALLERID      + 1
%CIC_CONNECTEDID   = %CIC_CALLEDID      + 1
%CIC_REDIRECTIONID = %CIC_CONNECTEDID   + 1
%CIC_REDIRECTINGID = %CIC_REDIRECTIONID + 1
%CIC_USERUSERINFO  = %CIC_REDIRECTINGID + 1
%CIC_HIGHLEVELCOMP = %CIC_USERUSERINFO  + 1
%CIC_LOWLEVELCOMP  = %CIC_HIGHLEVELCOMP + 1
%CIC_CHARGINGINFO  = %CIC_LOWLEVELCOMP  + 1
%CIC_TREATMENT     = %CIC_CHARGINGINFO  + 1
%CIC_CALLDATA      = %CIC_TREATMENT     + 1
%CIC_PRIVILEGE     = %CIC_CALLDATA      + 1
%CIC_MEDIATYPE     = %CIC_PRIVILEGE     + 1
%CIC_LASTITEM      = %CIC_MEDIATYPE

' enum CALLINFO_LONG
%CIL_MEDIATYPESAVAILABLE      = 0
%CIL_BEARERMODE               = %CIL_MEDIATYPESAVAILABLE      + 1
%CIL_CALLERIDADDRESSTYPE      = %CIL_BEARERMODE               + 1
%CIL_CALLEDIDADDRESSTYPE      = %CIL_CALLERIDADDRESSTYPE      + 1
%CIL_CONNECTEDIDADDRESSTYPE   = %CIL_CALLEDIDADDRESSTYPE      + 1
%CIL_REDIRECTIONIDADDRESSTYPE = %CIL_CONNECTEDIDADDRESSTYPE   + 1
%CIL_REDIRECTINGIDADDRESSTYPE = %CIL_REDIRECTIONIDADDRESSTYPE + 1
%CIL_ORIGIN                   = %CIL_REDIRECTINGIDADDRESSTYPE + 1
%CIL_REASON                   = %CIL_ORIGIN                   + 1
%CIL_APPSPECIFIC              = %CIL_REASON                   + 1
%CIL_CALLPARAMSFLAGS          = %CIL_APPSPECIFIC              + 1
%CIL_CALLTREATMENT            = %CIL_CALLPARAMSFLAGS          + 1
%CIL_MINRATE                  = %CIL_CALLTREATMENT            + 1
%CIL_MAXRATE                  = %CIL_MINRATE                  + 1
%CIL_COUNTRYCODE              = %CIL_MAXRATE                  + 1
%CIL_CALLID                   = %CIL_COUNTRYCODE              + 1
%CIL_RELATEDCALLID            = %CIL_CALLID                   + 1
%CIL_COMPLETIONID             = %CIL_RELATEDCALLID            + 1
%CIL_NUMBEROFOWNERS           = %CIL_COMPLETIONID             + 1
%CIL_NUMBEROFMONITORS         = %CIL_NUMBEROFOWNERS           + 1
%CIL_TRUNK                    = %CIL_NUMBEROFMONITORS         + 1
%CIL_RATE                     = %CIL_TRUNK                    + 1
%CIL_GENERATEDIGITDURATION    = %CIL_RATE                     + 1
%CIL_MONITORDIGITMODES        = %CIL_GENERATEDIGITDURATION    + 1
%CIL_MONITORMEDIAMODES        = %CIL_MONITORDIGITMODES        + 1

' enum CALLINFO_STRING
%CIS_CALLERIDNAME            = 0
%CIS_CALLERIDNUMBER          = %CIS_CALLERIDNAME            + 1
%CIS_CALLEDIDNAME            = %CIS_CALLERIDNUMBER          + 1
%CIS_CALLEDIDNUMBER          = %CIS_CALLEDIDNAME            + 1
%CIS_CONNECTEDIDNAME         = %CIS_CALLEDIDNUMBER          + 1
%CIS_CONNECTEDIDNUMBER       = %CIS_CONNECTEDIDNAME         + 1
%CIS_REDIRECTIONIDNAME       = %CIS_CONNECTEDIDNUMBER       + 1
%CIS_REDIRECTIONIDNUMBER     = %CIS_REDIRECTIONIDNAME       + 1
%CIS_REDIRECTINGIDNAME       = %CIS_REDIRECTIONIDNUMBER     + 1
%CIS_REDIRECTINGIDNUMBER     = %CIS_REDIRECTINGIDNAME       + 1
%CIS_CALLEDPARTYFRIENDLYNAME = %CIS_REDIRECTINGIDNUMBER     + 1
%CIS_COMMENT                 = %CIS_CALLEDPARTYFRIENDLYNAME + 1
%CIS_DISPLAYABLEADDRESS      = %CIS_COMMENT                 + 1
%CIS_CALLINGPARTYID          = %CIS_DISPLAYABLEADDRESS      + 1

' enum CALLINFO_BUFFER
%CIB_USERUSERINFO                 = 0
%CIB_DEVSPECIFICBUFFER            = %CIB_USERUSERINFO                 + 1
%CIB_CALLDATABUFFER               = %CIB_DEVSPECIFICBUFFER            + 1
%CIB_CHARGINGINFOBUFFER           = %CIB_CALLDATABUFFER               + 1
%CIB_HIGHLEVELCOMPATIBILITYBUFFER = %CIB_CHARGINGINFOBUFFER           + 1
%CIB_LOWLEVELCOMPATIBILITYBUFFER  = %CIB_HIGHLEVELCOMPATIBILITYBUFFER + 1

' enum ADDRESS_CAPABILITY
%AC_ADDRESSTYPES                 = 0
%AC_BEARERMODES                  = %AC_ADDRESSTYPES                 + 1
%AC_MAXACTIVECALLS               = %AC_BEARERMODES                  + 1
%AC_MAXONHOLDCALLS               = %AC_MAXACTIVECALLS               + 1
%AC_MAXONHOLDPENDINGCALLS        = %AC_MAXONHOLDCALLS               + 1
%AC_MAXNUMCONFERENCE             = %AC_MAXONHOLDPENDINGCALLS        + 1
%AC_MAXNUMTRANSCONF              = %AC_MAXNUMCONFERENCE             + 1
%AC_MONITORDIGITSUPPORT          = %AC_MAXNUMTRANSCONF              + 1
%AC_GENERATEDIGITSUPPORT         = %AC_MONITORDIGITSUPPORT          + 1
%AC_GENERATETONEMODES            = %AC_GENERATEDIGITSUPPORT         + 1
%AC_GENERATETONEMAXNUMFREQ       = %AC_GENERATETONEMODES            + 1
%AC_MONITORTONEMAXNUMFREQ        = %AC_GENERATETONEMAXNUMFREQ       + 1
%AC_MONITORTONEMAXNUMENTRIES     = %AC_MONITORTONEMAXNUMFREQ        + 1
%AC_DEVCAPFLAGS                  = %AC_MONITORTONEMAXNUMENTRIES     + 1
%AC_ANSWERMODES                  = %AC_DEVCAPFLAGS                  + 1
%AC_LINEFEATURES                 = %AC_ANSWERMODES                  + 1
%AC_SETTABLEDEVSTATUS            = %AC_LINEFEATURES                 + 1
%AC_PARKSUPPORT                  = %AC_SETTABLEDEVSTATUS            + 1
%AC_CALLERIDSUPPORT              = %AC_PARKSUPPORT                  + 1
%AC_CALLEDIDSUPPORT              = %AC_CALLERIDSUPPORT              + 1
%AC_CONNECTEDIDSUPPORT           = %AC_CALLEDIDSUPPORT              + 1
%AC_REDIRECTIONIDSUPPORT         = %AC_CONNECTEDIDSUPPORT           + 1
%AC_REDIRECTINGIDSUPPORT         = %AC_REDIRECTIONIDSUPPORT         + 1
%AC_ADDRESSCAPFLAGS              = %AC_REDIRECTINGIDSUPPORT         + 1
%AC_CALLFEATURES1                = %AC_ADDRESSCAPFLAGS              + 1
%AC_CALLFEATURES2                = %AC_CALLFEATURES1                + 1
%AC_REMOVEFROMCONFCAPS           = %AC_CALLFEATURES2                + 1
%AC_REMOVEFROMCONFSTATE          = %AC_REMOVEFROMCONFCAPS           + 1
%AC_TRANSFERMODES                = %AC_REMOVEFROMCONFSTATE          + 1
%AC_ADDRESSFEATURES              = %AC_TRANSFERMODES                + 1
%AC_PREDICTIVEAUTOTRANSFERSTATES = %AC_ADDRESSFEATURES              + 1
%AC_MAXCALLDATASIZE              = %AC_PREDICTIVEAUTOTRANSFERSTATES + 1
%AC_LINEID                       = %AC_MAXCALLDATASIZE              + 1
%AC_ADDRESSID                    = %AC_LINEID                       + 1
%AC_FORWARDMODES                 = %AC_ADDRESSID                    + 1
%AC_MAXFORWARDENTRIES            = %AC_FORWARDMODES                 + 1
%AC_MAXSPECIFICENTRIES           = %AC_MAXFORWARDENTRIES            + 1
%AC_MINFWDNUMRINGS               = %AC_MAXSPECIFICENTRIES           + 1
%AC_MAXFWDNUMRINGS               = %AC_MINFWDNUMRINGS               + 1
%AC_MAXCALLCOMPLETIONS           = %AC_MAXFWDNUMRINGS               + 1
%AC_CALLCOMPLETIONCONDITIONS     = %AC_MAXCALLCOMPLETIONS           + 1
%AC_CALLCOMPLETIONMODES          = %AC_CALLCOMPLETIONCONDITIONS     + 1
%AC_PERMANENTDEVICEID            = %AC_CALLCOMPLETIONMODES          + 1
%AC_GATHERDIGITSMINTIMEOUT       = %AC_PERMANENTDEVICEID            + 1
%AC_GATHERDIGITSMAXTIMEOUT       = %AC_GATHERDIGITSMINTIMEOUT       + 1
%AC_GENERATEDIGITMINDURATION     = %AC_GATHERDIGITSMAXTIMEOUT       + 1
%AC_GENERATEDIGITMAXDURATION     = %AC_GENERATEDIGITMINDURATION     + 1
%AC_GENERATEDIGITDEFAULTDURATION = %AC_GENERATEDIGITMAXDURATION     + 1

' enum ADDRESS_CAPABILITY_STRING
%ACS_PROTOCOL              = 0
%ACS_ADDRESSDEVICESPECIFIC = %ACS_PROTOCOL              + 1
%ACS_LINEDEVICESPECIFIC    = %ACS_ADDRESSDEVICESPECIFIC + 1
%ACS_PROVIDERSPECIFIC      = %ACS_LINEDEVICESPECIFIC    + 1
%ACS_SWITCHSPECIFIC        = %ACS_PROVIDERSPECIFIC      + 1
%ACS_PERMANENTDEVICEGUID   = %ACS_SWITCHSPECIFIC        + 1

' enum FULLDUPLEX_SUPPORT
%FDS_SUPPORTED    = 0
%FDS_NOTSUPPORTED = %FDS_SUPPORTED    + 1
%FDS_UNKNOWN      = %FDS_NOTSUPPORTED + 1

' enum FINISH_MODE
%FM_ASTRANSFER   = 0
%FM_ASCONFERENCE = %FM_ASTRANSFER + 1

' enum PHONE_PRIVILEGE
%PP_OWNER   = 0
%PP_MONITOR = %PP_OWNER + 1

' enum PHONE_HOOK_SWITCH_DEVICE
%PHSD_HANDSET      = &H1
%PHSD_SPEAKERPHONE = &H2
%PHSD_HEADSET      = &H4

' enum PHONE_HOOK_SWITCH_STATE
%PHSS_ONHOOK               = &H1
%PHSS_OFFHOOK_MIC_ONLY     = &H2
%PHSS_OFFHOOK_SPEAKER_ONLY = &H4
%PHSS_OFFHOOK              = &H8

' enum PHONE_LAMP_MODE
%LM_DUMMY         = &H1
%LM_OFF           = &H2
%LM_STEADY        = &H4
%LM_WINK          = &H8
%LM_FLASH         = &H10
%LM_FLUTTER       = &H20
%LM_BROKENFLUTTER = &H40
%LM_UNKNOWN       = &H80

' enum PHONECAPS_LONG
%PCL_HOOKSWITCHES                = 0
%PCL_HANDSETHOOKSWITCHMODES      = %PCL_HOOKSWITCHES                + 1
%PCL_HEADSETHOOKSWITCHMODES      = %PCL_HANDSETHOOKSWITCHMODES      + 1
%PCL_SPEAKERPHONEHOOKSWITCHMODES = %PCL_HEADSETHOOKSWITCHMODES      + 1
%PCL_DISPLAYNUMROWS              = %PCL_SPEAKERPHONEHOOKSWITCHMODES + 1
%PCL_DISPLAYNUMCOLUMNS           = %PCL_DISPLAYNUMROWS              + 1
%PCL_NUMRINGMODES                = %PCL_DISPLAYNUMCOLUMNS           + 1
%PCL_NUMBUTTONLAMPS              = %PCL_NUMRINGMODES                + 1
%PCL_GENERICPHONE                = %PCL_NUMBUTTONLAMPS              + 1

' enum PHONECAPS_STRING
%PCS_PHONENAME    = 0
%PCS_PHONEINFO    = %PCS_PHONENAME + 1
%PCS_PROVIDERINFO = %PCS_PHONEINFO + 1

' enum PHONECAPS_BUFFER
%PCB_DEVSPECIFICBUFFER = 0

' enum PHONE_BUTTON_STATE
%PBS_UP      = &H1
%PBS_DOWN    = &H2
%PBS_UNKNOWN = &H4
%PBS_UNAVAIL = &H8

' enum PHONE_BUTTON_MODE
%PBM_DUMMY   = 0
%PBM_CALL    = %PBM_DUMMY   + 1
%PBM_FEATURE = %PBM_CALL    + 1
%PBM_KEYPAD  = %PBM_FEATURE + 1
%PBM_LOCAL   = %PBM_KEYPAD  + 1
%PBM_DISPLAY = %PBM_LOCAL   + 1

' enum PHONE_BUTTON_FUNCTION
%PBF_UNKNOWN      = 0
%PBF_CONFERENCE   = %PBF_UNKNOWN      + 1
%PBF_TRANSFER     = %PBF_CONFERENCE   + 1
%PBF_DROP         = %PBF_TRANSFER     + 1
%PBF_HOLD         = %PBF_DROP         + 1
%PBF_RECALL       = %PBF_HOLD         + 1
%PBF_DISCONNECT   = %PBF_RECALL       + 1
%PBF_CONNECT      = %PBF_DISCONNECT   + 1
%PBF_MSGWAITON    = %PBF_CONNECT      + 1
%PBF_MSGWAITOFF   = %PBF_MSGWAITON    + 1
%PBF_SELECTRING   = %PBF_MSGWAITOFF   + 1
%PBF_ABBREVDIAL   = %PBF_SELECTRING   + 1
%PBF_FORWARD      = %PBF_ABBREVDIAL   + 1
%PBF_PICKUP       = %PBF_FORWARD      + 1
%PBF_RINGAGAIN    = %PBF_PICKUP       + 1
%PBF_PARK         = %PBF_RINGAGAIN    + 1
%PBF_REJECT       = %PBF_PARK         + 1
%PBF_REDIRECT     = %PBF_REJECT       + 1
%PBF_MUTE         = %PBF_REDIRECT     + 1
%PBF_VOLUMEUP     = %PBF_MUTE         + 1
%PBF_VOLUMEDOWN   = %PBF_VOLUMEUP     + 1
%PBF_SPEAKERON    = %PBF_VOLUMEDOWN   + 1
%PBF_SPEAKEROFF   = %PBF_SPEAKERON    + 1
%PBF_FLASH        = %PBF_SPEAKEROFF   + 1
%PBF_DATAON       = %PBF_FLASH        + 1
%PBF_DATAOFF      = %PBF_DATAON       + 1
%PBF_DONOTDISTURB = %PBF_DATAOFF      + 1
%PBF_INTERCOM     = %PBF_DONOTDISTURB + 1
%PBF_BRIDGEDAPP   = %PBF_INTERCOM     + 1
%PBF_BUSY         = %PBF_BRIDGEDAPP   + 1
%PBF_CALLAPP      = %PBF_BUSY         + 1
%PBF_DATETIME     = %PBF_CALLAPP      + 1
%PBF_DIRECTORY    = %PBF_DATETIME     + 1
%PBF_COVER        = %PBF_DIRECTORY    + 1
%PBF_CALLID       = %PBF_COVER        + 1
%PBF_LASTNUM      = %PBF_CALLID       + 1
%PBF_NIGHTSRV     = %PBF_LASTNUM      + 1
%PBF_SENDCALLS    = %PBF_NIGHTSRV     + 1
%PBF_MSGINDICATOR = %PBF_SENDCALLS    + 1
%PBF_REPDIAL      = %PBF_MSGINDICATOR + 1
%PBF_SETREPDIAL   = %PBF_REPDIAL      + 1
%PBF_SYSTEMSPEED  = %PBF_SETREPDIAL   + 1
%PBF_STATIONSPEED = %PBF_SYSTEMSPEED  + 1
%PBF_CAMPON       = %PBF_STATIONSPEED + 1
%PBF_SAVEREPEAT   = %PBF_CAMPON       + 1
%PBF_QUEUECALL    = %PBF_SAVEREPEAT   + 1
%PBF_NONE         = %PBF_QUEUECALL    + 1
%PBF_SEND         = %PBF_NONE         + 1

' enum PHONE_TONE
%PT_KEYPADZERO       = 0
%PT_KEYPADONE        = %PT_KEYPADZERO       + 1
%PT_KEYPADTWO        = %PT_KEYPADONE        + 1
%PT_KEYPADTHREE      = %PT_KEYPADTWO        + 1
%PT_KEYPADFOUR       = %PT_KEYPADTHREE      + 1
%PT_KEYPADFIVE       = %PT_KEYPADFOUR       + 1
%PT_KEYPADSIX        = %PT_KEYPADFIVE       + 1
%PT_KEYPADSEVEN      = %PT_KEYPADSIX        + 1
%PT_KEYPADEIGHT      = %PT_KEYPADSEVEN      + 1
%PT_KEYPADNINE       = %PT_KEYPADEIGHT      + 1
%PT_KEYPADSTAR       = %PT_KEYPADNINE       + 1
%PT_KEYPADPOUND      = %PT_KEYPADSTAR       + 1
%PT_KEYPADA          = %PT_KEYPADPOUND      + 1
%PT_KEYPADB          = %PT_KEYPADA          + 1
%PT_KEYPADC          = %PT_KEYPADB          + 1
%PT_KEYPADD          = %PT_KEYPADC          + 1
%PT_NORMALDIALTONE   = %PT_KEYPADD          + 1
%PT_EXTERNALDIALTONE = %PT_NORMALDIALTONE   + 1
%PT_BUSY             = %PT_EXTERNALDIALTONE + 1
%PT_RINGBACK         = %PT_BUSY             + 1
%PT_ERRORTONE        = %PT_RINGBACK         + 1
%PT_SILENCE          = %PT_ERRORTONE        + 1

' enum PHONE_EVENT
%PE_DISPLAY        = 0
%PE_LAMPMODE       = %PE_DISPLAY        + 1
%PE_RINGMODE       = %PE_LAMPMODE       + 1
%PE_RINGVOLUME     = %PE_RINGMODE       + 1
%PE_HOOKSWITCH     = %PE_RINGVOLUME     + 1
%PE_CAPSCHANGE     = %PE_HOOKSWITCH     + 1
%PE_BUTTON         = %PE_CAPSCHANGE     + 1
%PE_CLOSE          = %PE_BUTTON         + 1
%PE_NUMBERGATHERED = %PE_CLOSE          + 1
%PE_DIALING        = %PE_NUMBERGATHERED + 1
%PE_ANSWER         = %PE_DIALING        + 1
%PE_DISCONNECT     = %PE_ANSWER         + 1
%PE_LASTITEM       = %PE_DISCONNECT

%INTERFACEMASK                  = &Hff0000
%DISPIDMASK                     = &Hffff
%IDISPTAPI                      = &H10000
%IDISPTAPICALLCENTER            = &H20000
%IDISPCALLINFO                  = &H10000
%IDISPBASICCALLCONTROL          = &H20000
%IDISPLEGACYCALLMEDIACONTROL    = &H30000
%IDISPAGGREGATEDMSPCALLOBJ      = &H40000
%IDISPADDRESS                   = &H10000
%IDISPADDRESSCAPABILITIES       = &H20000
%IDISPMEDIASUPPORT              = &H30000
%IDISPADDRESSTRANSLATION        = &H40000
%IDISPLEGACYADDRESSMEDIACONTROL = &H50000
%IDISPAGGREGATEDMSPADDRESSOBJ   = &H60000
%IDISPPHONE                     = &H10000
%IDISPAPC                       = &H20000
%IDISPMULTITRACK                = &H10000
%IDISPMEDIACONTROL              = &H20000
%IDISPMEDIARECORD               = &H30000
%IDISPMEDIAPLAYBACK             = &H40000
%IDISPFILETRACK                 = &H10000


' ########################################################################################
' Interface name = ITTAPI
' IID = {B1EFC382-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTAPI_INTERFACE_DEFINED)
    %ITTAPI_INTERFACE_DEFINED = 1

INTERFACE ITTAPI $IID_ITTAPI

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <65549> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown <65550> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Addresses <65537> ( _                   ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateAddresses <65538> ( _                ' VTable offset = 40
   ) AS IEnumAddress                                    ' __retval_out IEnumAddress **ppEnumAddress
   ' =====================================================================================
   METHOD RegisterCallNotifications <65539> ( _         ' VTable offset = 44
     BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   , BYVAL fMonitor AS INTEGER _                        ' __in VARIANT_BOOL fMonitor
   , BYVAL fOwner AS INTEGER _                          ' __in VARIANT_BOOL fOwner
   , BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   , BYVAL lCallbackInstance AS LONG _                  ' __in long lCallbackInstance
   ) AS LONG                                            ' __retval_out long *plRegister
   ' =====================================================================================
   METHOD UnregisterNotifications <65540> ( _           ' VTable offset = 48
     BYVAL lRegister AS LONG _                          ' __in long lRegister
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallHubs <65541> ( _                    ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCallHubs <65542> ( _                 ' VTable offset = 56
   ) AS IEnumCallHub                                    ' __retval_out IEnumCallHub **ppEnumCallHub
   ' =====================================================================================
   METHOD SetCallHubTracking <65543> ( _                ' VTable offset = 60
     BYVAL pAddresses AS VARIANT _                      ' __in VARIANT pAddresses
   , BYVAL bTracking AS INTEGER _                       ' __in VARIANT_BOOL bTracking
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumeratePrivateTAPIObjects <65544> ( _       ' VTable offset = 64
     BYREF ppEnumUnknown AS IEnumUnknown _              ' __out IEnumUnknown **ppEnumUnknown
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivateTAPIObjects <65545> ( _          ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD RegisterRequestRecipient <65546> ( _          ' VTable offset = 72
     BYVAL lRegistrationInstance AS LONG _              ' __in long lRegistrationInstance
   , BYVAL lRequestMode AS LONG _                       ' __in long lRequestMode
   , BYVAL fEnable AS INTEGER _                         ' __in VARIANT_BOOL fEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAssistedTelephonyPriority <65547> ( _      ' VTable offset = 76
     BYVAL pAppFilename AS WSTRING _                    ' __in BSTR pAppFilename
   , BYVAL fPriority AS INTEGER _                       ' __in VARIANT_BOOL fPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD SetApplicationPriority <65548> ( _            ' VTable offset = 80
     BYVAL pAppFilename AS WSTRING _                    ' __in BSTR pAppFilename
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL fPriority AS INTEGER _                       ' __in VARIANT_BOOL fPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EventFilter <65551> ( _                 ' VTable offset = 84
     BYVAL lFilterMask AS LONG _                        ' __in long lFilterMask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventFilter <65551> ( _                 ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plFilterMask
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPI_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTAPI2
' IID = {54FBDC8C-D90F-4DAD-9695-B373097F094B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITTAPI
' ########################################################################################

#IF NOT %DEF(%ITTAPI2_INTERFACE_DEFINED)
    %ITTAPI2_INTERFACE_DEFINED = 1

INTERFACE ITTAPI2 $IID_ITTAPI2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITTAPI Methods
   ' =====================================================================================
   METHOD Initialize <65549> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown <65550> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Addresses <65537> ( _                   ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateAddresses <65538> ( _                ' VTable offset = 40
   ) AS IEnumAddress                                    ' __retval_out IEnumAddress **ppEnumAddress
   ' =====================================================================================
   METHOD RegisterCallNotifications <65539> ( _         ' VTable offset = 44
     BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   , BYVAL fMonitor AS INTEGER _                        ' __in VARIANT_BOOL fMonitor
   , BYVAL fOwner AS INTEGER _                          ' __in VARIANT_BOOL fOwner
   , BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   , BYVAL lCallbackInstance AS LONG _                  ' __in long lCallbackInstance
   ) AS LONG                                            ' __retval_out long *plRegister
   ' =====================================================================================
   METHOD UnregisterNotifications <65540> ( _           ' VTable offset = 48
     BYVAL lRegister AS LONG _                          ' __in long lRegister
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallHubs <65541> ( _                    ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCallHubs <65542> ( _                 ' VTable offset = 56
   ) AS IEnumCallHub                                    ' __retval_out IEnumCallHub **ppEnumCallHub
   ' =====================================================================================
   METHOD SetCallHubTracking <65543> ( _                ' VTable offset = 60
     BYVAL pAddresses AS VARIANT _                      ' __in VARIANT pAddresses
   , BYVAL bTracking AS INTEGER _                       ' __in VARIANT_BOOL bTracking
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumeratePrivateTAPIObjects <65544> ( _       ' VTable offset = 64
     BYREF ppEnumUnknown AS IEnumUnknown _              ' __out IEnumUnknown **ppEnumUnknown
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivateTAPIObjects <65545> ( _          ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD RegisterRequestRecipient <65546> ( _          ' VTable offset = 72
     BYVAL lRegistrationInstance AS LONG _              ' __in long lRegistrationInstance
   , BYVAL lRequestMode AS LONG _                       ' __in long lRequestMode
   , BYVAL fEnable AS INTEGER _                         ' __in VARIANT_BOOL fEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAssistedTelephonyPriority <65547> ( _      ' VTable offset = 76
     BYVAL pAppFilename AS WSTRING _                    ' __in BSTR pAppFilename
   , BYVAL fPriority AS INTEGER _                       ' __in VARIANT_BOOL fPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD SetApplicationPriority <65548> ( _            ' VTable offset = 80
     BYVAL pAppFilename AS WSTRING _                    ' __in BSTR pAppFilename
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL fPriority AS INTEGER _                       ' __in VARIANT_BOOL fPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EventFilter <65551> ( _                 ' VTable offset = 84
     BYVAL lFilterMask AS LONG _                        ' __in long lFilterMask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventFilter <65551> ( _                 ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plFilterMask
   ' =====================================================================================

   ' =====================================================================================
   ' ITTAPI2 Methods
   ' =====================================================================================
   PROPERTY GET Phones <65552> ( _                      ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *pPhones
   ' =====================================================================================
   METHOD EnumeratePhones <65553> ( _                   ' VTable offset = 96
   ) AS IEnumPhone                                      ' __retval_out IEnumPhone **ppEnumPhone
   ' =====================================================================================
   METHOD CreateEmptyCollectionObject <65554> ( _       ' VTable offset = 100
   ) AS ITCollection2                                   ' __retval_out ITCollection2 **ppCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPI2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMediaSupport
' IID = {B1EFC384-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMediaSupport_INTERFACE_DEFINED)
    %ITMediaSupport_INTERFACE_DEFINED = 1

INTERFACE ITMediaSupport $IID_ITMediaSupport

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MediaTypes <196609> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   METHOD QueryMediaType <196610> ( _                   ' VTable offset = 32
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSupport
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMediaSupport_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalClassInfo
' IID = {41757F4A-CF09-4B34-BC96-0A79D2390076}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalClassInfo_INTERFACE_DEFINED)
    %ITPluggableTerminalClassInfo_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalClassInfo $IID_ITPluggableTerminalClassInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY GET Company <2> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pCompany
   ' =====================================================================================
   PROPERTY GET Version <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVersion
   ' =====================================================================================
   PROPERTY GET TerminalClass <4> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pTerminalClass
   ' =====================================================================================
   PROPERTY GET CLSID <5> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pCLSID
   ' =====================================================================================
   PROPERTY GET Direction <6> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out TERMINAL_DIRECTION *pDirection
   ' =====================================================================================
   PROPERTY GET MediaTypes <7> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pMediaTypes
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalClassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalSuperclassInfo
' IID = {6D54E42C-4625-4359-A6F7-631999107E05}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalSuperclassInfo_INTERFACE_DEFINED)
    %ITPluggableTerminalSuperclassInfo_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalSuperclassInfo $IID_ITPluggableTerminalSuperclassInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY GET CLSID <2> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pCLSID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalSuperclassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTerminalSupport
' IID = {B1EFC385-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTerminalSupport_INTERFACE_DEFINED)
    %ITTerminalSupport_INTERFACE_DEFINED = 1

INTERFACE ITTerminalSupport $IID_ITTerminalSupport

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StaticTerminals <393217> ( _            ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateStaticTerminals <393218> ( _         ' VTable offset = 32
   ) AS IEnumTerminal                                   ' __retval_out IEnumTerminal **ppTerminalEnumerator
   ' =====================================================================================
   PROPERTY GET DynamicTerminalClasses <393219> ( _     ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDynamicTerminalClasses <393220> ( _  ' VTable offset = 40
   ) AS IEnumTerminalClass                              ' __retval_out IEnumTerminalClass **ppTerminalClassEnumerator
   ' =====================================================================================
   METHOD CreateTerminal <393221> ( _                   ' VTable offset = 44
     BYVAL pTerminalClass AS WSTRING _                  ' __in BSTR pTerminalClass
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   METHOD GetDefaultStaticTerminal <393222> ( _         ' VTable offset = 48
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminalSupport_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTerminalSupport2
' IID = {F3EB39BC-1B1F-4E99-A0C0-56305C4DD591}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITTerminalSupport
' ########################################################################################

#IF NOT %DEF(%ITTerminalSupport2_INTERFACE_DEFINED)
    %ITTerminalSupport2_INTERFACE_DEFINED = 1

INTERFACE ITTerminalSupport2 $IID_ITTerminalSupport2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITTerminalSupport Methods
   ' =====================================================================================
   PROPERTY GET StaticTerminals <393217> ( _            ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateStaticTerminals <393218> ( _         ' VTable offset = 32
   ) AS IEnumTerminal                                   ' __retval_out IEnumTerminal **ppTerminalEnumerator
   ' =====================================================================================
   PROPERTY GET DynamicTerminalClasses <393219> ( _     ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDynamicTerminalClasses <393220> ( _  ' VTable offset = 40
   ) AS IEnumTerminalClass                              ' __retval_out IEnumTerminalClass **ppTerminalClassEnumerator
   ' =====================================================================================
   METHOD CreateTerminal <393221> ( _                   ' VTable offset = 44
     BYVAL pTerminalClass AS WSTRING _                  ' __in BSTR pTerminalClass
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   METHOD GetDefaultStaticTerminal <393222> ( _         ' VTable offset = 48
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================

   ' =====================================================================================
   ' ITTerminalSupport2 Methods
   ' =====================================================================================
   PROPERTY GET PluggableSuperclasses <393223> ( _      ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumeratePluggableSuperclasses <393224> ( _   ' VTable offset = 56
   ) AS IEnumPluggableSuperclassInfo                    ' __retval_out IEnumPluggableSuperclassInfo **ppSuperclassEnumerator
   ' =====================================================================================
   PROPERTY GET PluggableTerminalClasses <393225> ( _   ' VTable offset = 60
     BYVAL bstrTerminalSuperclass AS WSTRING _          ' __in BSTR bstrTerminalSuperclass
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumeratePluggableTerminalClasses <393226> ( _ ' VTable offset = 64
     BYREF iidTerminalSuperclass AS GUID _              ' __in CLSID iidTerminalSuperclass
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   ) AS IEnumPluggableTerminalClassInfo                 ' __retval_out IEnumPluggableTerminalClassInfo **ppClassEnumerator
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminalSupport2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddress
' IID = {B1EFC386-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddress_INTERFACE_DEFINED)
    %ITAddress_INTERFACE_DEFINED = 1

INTERFACE ITAddress $IID_ITAddress

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET State <65537> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out ADDRESS_STATE *pAddressState
   ' =====================================================================================
   PROPERTY GET AddressName <65538> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY GET ServiceProviderName <65539> ( _         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY GET TAPIObject <65540> ( _                  ' VTable offset = 40
   ) AS ITTAPI                                          ' __retval_out ITTAPI **ppTapiObject
   ' =====================================================================================
   METHOD CreateCall <65541> ( _                        ' VTable offset = 44
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL lAddressType AS LONG _                       ' __in long lAddressType
   , BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   ) AS ITBasicCallControl                              ' __retval_out ITBasicCallControl **ppCall
   ' =====================================================================================
   PROPERTY GET Calls <65542> ( _                       ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCalls <65543> ( _                    ' VTable offset = 52
   ) AS IEnumCall                                       ' __retval_out IEnumCall **ppCallEnum
   ' =====================================================================================
   PROPERTY GET DialableAddress <65544> ( _             ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pDialableAddress
   ' =====================================================================================
   METHOD CreateForwardInfoObject <65546> ( _           ' VTable offset = 60
   ) AS ITForwardInformation                            ' __retval_out ITForwardInformation **ppForwardInfo
   ' =====================================================================================
   METHOD Forward <65547> ( _                           ' VTable offset = 64
     BYVAL pForwardInfo AS ITForwardInformation _       ' __in ITForwardInformation *pForwardInfo
   , BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentForwardInfo <65548> ( _          ' VTable offset = 68
   ) AS ITForwardInformation                            ' __retval_out ITForwardInformation **ppForwardInfo
   ' =====================================================================================
   PROPERTY SET MessageWaiting <65550> ( _              ' VTable offset = 72
     BYVAL fMessageWaiting AS INTEGER _                 ' __in VARIANT_BOOL fMessageWaiting
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageWaiting <65550> ( _              ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMessageWaiting
   ' =====================================================================================
   PROPERTY SET DoNotDisturb <65551> ( _                ' VTable offset = 80
     BYVAL fDoNotDisturb AS INTEGER _                   ' __in VARIANT_BOOL fDoNotDisturb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DoNotDisturb <65551> ( _                ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfDoNotDisturb
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddress_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddress2
' IID = {B0AE5D9B-BE51-46C9-B0F7-DFA8A22A8BC4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITAddress
' ########################################################################################

#IF NOT %DEF(%ITAddress2_INTERFACE_DEFINED)
    %ITAddress2_INTERFACE_DEFINED = 1

INTERFACE ITAddress2 $IID_ITAddress2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITAddress Methods
   ' =====================================================================================
   PROPERTY GET State <65537> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out ADDRESS_STATE *pAddressState
   ' =====================================================================================
   PROPERTY GET AddressName <65538> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY GET ServiceProviderName <65539> ( _         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY GET TAPIObject <65540> ( _                  ' VTable offset = 40
   ) AS ITTAPI                                          ' __retval_out ITTAPI **ppTapiObject
   ' =====================================================================================
   METHOD CreateCall <65541> ( _                        ' VTable offset = 44
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL lAddressType AS LONG _                       ' __in long lAddressType
   , BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   ) AS ITBasicCallControl                              ' __retval_out ITBasicCallControl **ppCall
   ' =====================================================================================
   PROPERTY GET Calls <65542> ( _                       ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCalls <65543> ( _                    ' VTable offset = 52
   ) AS IEnumCall                                       ' __retval_out IEnumCall **ppCallEnum
   ' =====================================================================================
   PROPERTY GET DialableAddress <65544> ( _             ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pDialableAddress
   ' =====================================================================================
   METHOD CreateForwardInfoObject <65546> ( _           ' VTable offset = 60
   ) AS ITForwardInformation                            ' __retval_out ITForwardInformation **ppForwardInfo
   ' =====================================================================================
   METHOD Forward <65547> ( _                           ' VTable offset = 64
     BYVAL pForwardInfo AS ITForwardInformation _       ' __in ITForwardInformation *pForwardInfo
   , BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentForwardInfo <65548> ( _          ' VTable offset = 68
   ) AS ITForwardInformation                            ' __retval_out ITForwardInformation **ppForwardInfo
   ' =====================================================================================
   PROPERTY SET MessageWaiting <65550> ( _              ' VTable offset = 72
     BYVAL fMessageWaiting AS INTEGER _                 ' __in VARIANT_BOOL fMessageWaiting
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageWaiting <65550> ( _              ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMessageWaiting
   ' =====================================================================================
   PROPERTY SET DoNotDisturb <65551> ( _                ' VTable offset = 80
     BYVAL fDoNotDisturb AS INTEGER _                   ' __in VARIANT_BOOL fDoNotDisturb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DoNotDisturb <65551> ( _                ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfDoNotDisturb
   ' =====================================================================================

   ' =====================================================================================
   ' ITAddress2 Methods
   ' =====================================================================================
   PROPERTY GET Phones <65552> ( _                      ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pPhones
   ' =====================================================================================
   METHOD EnumeratePhones <65553> ( _                   ' VTable offset = 92
   ) AS IEnumPhone                                      ' __retval_out IEnumPhone **ppEnumPhone
   ' =====================================================================================
   METHOD GetPhoneFromTerminal <65554> ( _              ' VTable offset = 96
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   ) AS ITPhone                                         ' __retval_out ITPhone **ppPhone
   ' =====================================================================================
   PROPERTY GET PreferredPhones <65556> ( _             ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pPhones
   ' =====================================================================================
   METHOD EnumeratePreferredPhones <65557> ( _          ' VTable offset = 104
   ) AS IEnumPhone                                      ' __retval_out IEnumPhone **ppEnumPhone
   ' =====================================================================================
   PROPERTY GET EventFilter <65555> ( _                 ' VTable offset = 108
     BYVAL TapiEvent AS LONG _                          ' __in TAPI_EVENT TapiEvent
   , BYVAL lSubEvent AS LONG _                          ' __in long lSubEvent
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pEnable
   ' =====================================================================================
   PROPERTY SET EventFilter <65555> ( _                 ' VTable offset = 112
     BYVAL TapiEvent AS LONG _                          ' __in TAPI_EVENT TapiEvent
   , BYVAL lSubEvent AS LONG _                          ' __in long lSubEvent
   , BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL bEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD DeviceSpecific <65558> ( _                    ' VTable offset = 116
     BYVAL pCall AS ITCallInfo _                        ' __in ITCallInfo *pCall
   , BYVAL pParams AS BYTE PTR _                        ' __in BYTE *pParams
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   )                                                    ' void
   ' =====================================================================================
   METHOD DeviceSpecificVariant <65559> ( _             ' VTable offset = 120
     BYVAL pCall AS ITCallInfo _                        ' __in ITCallInfo *pCall
   , BYVAL varDevSpecificByteArray AS VARIANT _         ' __in VARIANT varDevSpecificByteArray
   )                                                    ' void
   ' =====================================================================================
   METHOD NegotiateExtVersion <65560> ( _               ' VTable offset = 124
     BYVAL lLowVersion AS LONG _                        ' __in long lLowVersion
   , BYVAL lHighVersion AS LONG _                       ' __in long lHighVersion
   ) AS LONG                                            ' __retval_out long *plExtVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddress2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddressCapabilities
' IID = {8DF232F5-821B-11D1-BB5C-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddressCapabilities_INTERFACE_DEFINED)
    %ITAddressCapabilities_INTERFACE_DEFINED = 1

INTERFACE ITAddressCapabilities $IID_ITAddressCapabilities

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AddressCapability <131073> ( _          ' VTable offset = 28
     BYVAL AddressCap AS LONG _                         ' __in ADDRESS_CAPABILITY AddressCap
   ) AS LONG                                            ' __retval_out long *plCapability
   ' =====================================================================================
   PROPERTY GET AddressCapabilityString <131074> ( _    ' VTable offset = 32
     BYVAL AddressCapString AS LONG _                   ' __in ADDRESS_CAPABILITY_STRING AddressCapString
   ) AS WSTRING                                         ' __retval_out BSTR *ppCapabilityString
   ' =====================================================================================
   PROPERTY GET CallTreatments <131075> ( _             ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCallTreatments <131076> ( _          ' VTable offset = 40
   ) AS IEnumBstr                                       ' __retval_out IEnumBstr **ppEnumCallTreatment
   ' =====================================================================================
   PROPERTY GET CompletionMessages <131077> ( _         ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCompletionMessages <131078> ( _      ' VTable offset = 48
   ) AS IEnumBstr                                       ' __retval_out IEnumBstr **ppEnumCompletionMessage
   ' =====================================================================================
   PROPERTY GET DeviceClasses <131079> ( _              ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDeviceClasses <131080> ( _           ' VTable offset = 56
   ) AS IEnumBstr                                       ' __retval_out IEnumBstr **ppEnumDeviceClass
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddressCapabilities_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPhone
' IID = {09D48DB4-10CC-4388-9DE7-A8465618975A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPhone_INTERFACE_DEFINED)
    %ITPhone_INTERFACE_DEFINED = 1

INTERFACE ITPhone $IID_ITPhone

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Open <65537> ( _                              ' VTable offset = 28
     BYVAL Privilege AS LONG _                          ' __in PHONE_PRIVILEGE Privilege
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <65538> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Addresses <65539> ( _                   ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pAddresses
   ' =====================================================================================
   METHOD EnumerateAddresses <65540> ( _                ' VTable offset = 40
   ) AS IEnumAddress                                    ' __retval_out IEnumAddress **ppEnumAddress
   ' =====================================================================================
   PROPERTY GET PhoneCapsLong <65541> ( _               ' VTable offset = 44
     BYVAL pclCap AS LONG _                             ' __in PHONECAPS_LONG pclCap
   ) AS LONG                                            ' __retval_out long *plCapability
   ' =====================================================================================
   PROPERTY GET PhoneCapsString <65542> ( _             ' VTable offset = 48
     BYVAL pcsCap AS LONG _                             ' __in PHONECAPS_STRING pcsCap
   ) AS WSTRING                                         ' __retval_out BSTR *ppCapability
   ' =====================================================================================
   PROPERTY GET Terminals <65543> ( _                   ' VTable offset = 52
     BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   ) AS VARIANT                                         ' __retval_out VARIANT *pTerminals
   ' =====================================================================================
   METHOD EnumerateTerminals <65544> ( _                ' VTable offset = 56
     BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   ) AS IEnumTerminal                                   ' __retval_out IEnumTerminal **ppEnumTerminal
   ' =====================================================================================
   PROPERTY GET ButtonMode <65545> ( _                  ' VTable offset = 60
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   ) AS LONG                                            ' __retval_out PHONE_BUTTON_MODE *pButtonMode
   ' =====================================================================================
   PROPERTY SET ButtonMode <65545> ( _                  ' VTable offset = 64
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   , BYVAL ButtonMode AS LONG _                         ' __in PHONE_BUTTON_MODE ButtonMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonFunction <65546> ( _              ' VTable offset = 68
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   ) AS LONG                                            ' __retval_out PHONE_BUTTON_FUNCTION *pButtonFunction
   ' =====================================================================================
   PROPERTY SET ButtonFunction <65546> ( _              ' VTable offset = 72
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   , BYVAL ButtonFunction AS LONG _                     ' __in PHONE_BUTTON_FUNCTION ButtonFunction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonText <65547> ( _                  ' VTable offset = 76
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   ) AS WSTRING                                         ' __retval_out BSTR *ppButtonText
   ' =====================================================================================
   PROPERTY SET ButtonText <65547> ( _                  ' VTable offset = 80
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   , BYVAL bstrButtonText AS WSTRING _                  ' __in BSTR bstrButtonText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonState <65548> ( _                 ' VTable offset = 84
     BYVAL lButtonID AS LONG _                          ' __in long lButtonID
   ) AS LONG                                            ' __retval_out PHONE_BUTTON_STATE *pButtonState
   ' =====================================================================================
   PROPERTY GET HookSwitchState <65549> ( _             ' VTable offset = 88
     BYVAL HookSwitchDevice AS LONG _                   ' __in PHONE_HOOK_SWITCH_DEVICE HookSwitchDevice
   ) AS LONG                                            ' __retval_out PHONE_HOOK_SWITCH_STATE *pHookSwitchState
   ' =====================================================================================
   PROPERTY SET HookSwitchState <65549> ( _             ' VTable offset = 92
     BYVAL HookSwitchDevice AS LONG _                   ' __in PHONE_HOOK_SWITCH_DEVICE HookSwitchDevice
   , BYVAL HookSwitchState AS LONG _                    ' __in PHONE_HOOK_SWITCH_STATE HookSwitchState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET RingMode <65550> ( _                    ' VTable offset = 96
     BYVAL lRingMode AS LONG _                          ' __in long lRingMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RingMode <65550> ( _                    ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *plRingMode
   ' =====================================================================================
   PROPERTY SET RingVolume <65551> ( _                  ' VTable offset = 104
     BYVAL lRingVolume AS LONG _                        ' __in long lRingVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RingVolume <65551> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plRingVolume
   ' =====================================================================================
   PROPERTY GET Privilege <65552> ( _                   ' VTable offset = 112
   ) AS LONG                                            ' __retval_out PHONE_PRIVILEGE *pPrivilege
   ' =====================================================================================
   METHOD GetPhoneCapsBuffer <65553> ( _                ' VTable offset = 116
     BYVAL pcbCaps AS LONG _                            ' __in PHONECAPS_BUFFER pcbCaps
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppPhoneCapsBuffer AS DWORD _                 ' __out BYTE **ppPhoneCapsBuffer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PhoneCapsBuffer <65554> ( _             ' VTable offset = 120
     BYVAL pcbCaps AS LONG _                            ' __in PHONECAPS_BUFFER pcbCaps
   ) AS VARIANT                                         ' __retval_out VARIANT *pVarBuffer
   ' =====================================================================================
   PROPERTY GET LampMode <65555> ( _                    ' VTable offset = 124
     BYVAL lLampID AS LONG _                            ' __in long lLampID
   ) AS LONG                                            ' __retval_out PHONE_LAMP_MODE *pLampMode
   ' =====================================================================================
   PROPERTY SET LampMode <65555> ( _                    ' VTable offset = 128
     BYVAL lLampID AS LONG _                            ' __in long lLampID
   , BYVAL LampMode AS LONG _                           ' __in PHONE_LAMP_MODE LampMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Display <65556> ( _                     ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDisplay
   ' =====================================================================================
   METHOD SetDisplay <65557> ( _                        ' VTable offset = 136
     BYVAL lRow AS LONG _                               ' __in long lRow
   , BYVAL lColumn AS LONG _                            ' __in long lColumn
   , BYVAL bstrDisplay AS WSTRING _                     ' __in BSTR bstrDisplay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredAddresses <65558> ( _          ' VTable offset = 140
   ) AS VARIANT                                         ' __retval_out VARIANT *pAddresses
   ' =====================================================================================
   METHOD EnumeratePreferredAddresses <65559> ( _       ' VTable offset = 144
   ) AS IEnumAddress                                    ' __retval_out IEnumAddress **ppEnumAddress
   ' =====================================================================================
   METHOD DeviceSpecific <65560> ( _                    ' VTable offset = 148
     BYVAL pParams AS  BYTE PTR _                       ' __in BYTE *pParams
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   )                                                    ' void
   ' =====================================================================================
   METHOD DeviceSpecificVariant <65561> ( _             ' VTable offset = 152
     BYVAL varDevSpecificByteArray AS VARIANT _         ' __in VARIANT varDevSpecificByteArray
   )                                                    ' void
   ' =====================================================================================
   METHOD NegotiateExtVersion <65562> ( _               ' VTable offset = 156
     BYVAL lLowVersion AS LONG _                        ' __in long lLowVersion
   , BYVAL lHighVersion AS LONG _                       ' __in long lHighVersion
   ) AS LONG                                            ' __retval_out long *plExtVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPhone_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAutomatedPhoneControl
' IID = {1EE1AF0E-6159-4A61-B79B-6A4BA3FC9DFC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAutomatedPhoneControl_INTERFACE_DEFINED)
    %ITAutomatedPhoneControl_INTERFACE_DEFINED = 1

INTERFACE ITAutomatedPhoneControl $IID_ITAutomatedPhoneControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StartTone <131073> ( _                        ' VTable offset = 28
     BYVAL Tone AS LONG _                               ' __in PHONE_TONE Tone
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD StopTone <131074> ( _                         ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tone <131075> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out PHONE_TONE *pTone
   ' =====================================================================================
   METHOD StartRinger <131076> ( _                      ' VTable offset = 40
     BYVAL lRingMode AS LONG _                          ' __in long lRingMode
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD StopRinger <131077> ( _                       ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ringer <131078> ( _                     ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRinging
   ' =====================================================================================
   PROPERTY SET PhoneHandlingEnabled <131079> ( _       ' VTable offset = 52
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PhoneHandlingEnabled <131079> ( _       ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET AutoEndOfNumberTimeout <131080> ( _     ' VTable offset = 60
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoEndOfNumberTimeout <131080> ( _     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plTimeout
   ' =====================================================================================
   PROPERTY SET AutoDialtone <131081> ( _               ' VTable offset = 68
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoDialtone <131081> ( _               ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET AutoStopTonesOnOnHook <131082> ( _      ' VTable offset = 76
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoStopTonesOnOnHook <131082> ( _      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET AutoStopRingOnOffHook <131083> ( _      ' VTable offset = 84
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoStopRingOnOffHook <131083> ( _      ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET AutoKeypadTones <131084> ( _            ' VTable offset = 92
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoKeypadTones <131084> ( _            ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET AutoKeypadTonesMinimumDuration <131085> ( _ ' VTable offset = 100
     BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoKeypadTonesMinimumDuration <131085> ( _ ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plDuration
   ' =====================================================================================
   PROPERTY SET AutoVolumeControl <131086> ( _          ' VTable offset = 108
     BYVAL fEnabled AS INTEGER _                        ' __in VARIANT_BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoVolumeControl <131086> ( _          ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fEnabled
   ' =====================================================================================
   PROPERTY SET AutoVolumeControlStep <131087> ( _      ' VTable offset = 116
     BYVAL lStepSize AS LONG _                          ' __in long lStepSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoVolumeControlStep <131087> ( _      ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *plStepSize
   ' =====================================================================================
   PROPERTY SET AutoVolumeControlRepeatDelay <131088> ( _ ' VTable offset = 124
     BYVAL lDelay AS LONG _                             ' __in long lDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoVolumeControlRepeatDelay <131088> ( _ ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *plDelay
   ' =====================================================================================
   PROPERTY SET AutoVolumeControlRepeatPeriod <131089> ( _ ' VTable offset = 132
     BYVAL lPeriod AS LONG _                            ' __in long lPeriod
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoVolumeControlRepeatPeriod <131089> ( _ ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *plPeriod
   ' =====================================================================================
   METHOD SelectCall <131090> ( _                       ' VTable offset = 140
     BYVAL pCall AS ITCallInfo _                        ' __in ITCallInfo *pCall
   , BYVAL fSelectDefaultTerminals AS INTEGER _         ' __in VARIANT_BOOL fSelectDefaultTerminals
   )                                                    ' void
   ' =====================================================================================
   METHOD UnselectCall <131091> ( _                     ' VTable offset = 144
     BYVAL pCall AS ITCallInfo _                        ' __in ITCallInfo *pCall
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateSelectedCalls <131092> ( _           ' VTable offset = 148
   ) AS IEnumCall                                       ' __retval_out IEnumCall **ppCallEnum
   ' =====================================================================================
   PROPERTY GET SelectedCalls <131093> ( _              ' VTable offset = 152
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAutomatedPhoneControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITBasicCallControl
' IID = {B1EFC389-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITBasicCallControl_INTERFACE_DEFINED)
    %ITBasicCallControl_INTERFACE_DEFINED = 1

INTERFACE ITBasicCallControl $IID_ITBasicCallControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Connect <131075> ( _                          ' VTable offset = 28
     BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD Answer <131076> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <131077> ( _                       ' VTable offset = 36
     BYVAL code AS LONG _                               ' __in DISCONNECT_CODE code
   )                                                    ' void
   ' =====================================================================================
   METHOD Hold <131078> ( _                             ' VTable offset = 40
     BYVAL fHold AS INTEGER _                           ' __in VARIANT_BOOL fHold
   )                                                    ' void
   ' =====================================================================================
   METHOD HandoffDirect <131079> ( _                    ' VTable offset = 44
     BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   )                                                    ' void
   ' =====================================================================================
   METHOD HandoffIndirect <131080> ( _                  ' VTable offset = 48
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Conference <131081> ( _                       ' VTable offset = 52
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   , BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD Transfer <131082> ( _                         ' VTable offset = 56
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   , BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD BlindTransfer <131083> ( _                    ' VTable offset = 60
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD SwapHold <131084> ( _                         ' VTable offset = 64
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   )                                                    ' void
   ' =====================================================================================
   METHOD ParkDirect <131085> ( _                       ' VTable offset = 68
     BYVAL pParkAddress AS WSTRING _                    ' __in BSTR pParkAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD ParkIndirect <131086> ( _                     ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *ppNonDirAddress
   ' =====================================================================================
   METHOD Unpark <131087> ( _                           ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQOS <131088> ( _                           ' VTable offset = 80
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL ServiceLevel AS LONG _                       ' __in QOS_SERVICE_LEVEL ServiceLevel
   )                                                    ' void
   ' =====================================================================================
   METHOD Pickup <131091> ( _                           ' VTable offset = 84
     BYVAL pGroupID AS WSTRING _                        ' __in BSTR pGroupID
   )                                                    ' void
   ' =====================================================================================
   METHOD Dial <131092> ( _                             ' VTable offset = 88
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish <131093> ( _                           ' VTable offset = 92
     BYVAL finishMode AS LONG _                         ' __in FINISH_MODE finishMode
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromConference <131094> ( _             ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITBasicCallControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallInfo
' IID = {350F85D1-1227-11D3-83D4-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallInfo_INTERFACE_DEFINED)
    %ITCallInfo_INTERFACE_DEFINED = 1

INTERFACE ITCallInfo $IID_ITCallInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Address <65537> ( _                     ' VTable offset = 28
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET CallState <65538> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALL_STATE *pCallState
   ' =====================================================================================
   PROPERTY GET Privilege <65539> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CALL_PRIVILEGE *pPrivilege
   ' =====================================================================================
   PROPERTY GET CallHub <65540> ( _                     ' VTable offset = 40
   ) AS ITCallHub                                       ' __retval_out ITCallHub **ppCallHub
   ' =====================================================================================
   PROPERTY GET CallInfoLong <65541> ( _                ' VTable offset = 44
     BYVAL CallInfoLong AS LONG _                       ' __in CALLINFO_LONG CallInfoLong
   ) AS LONG                                            ' __retval_out long *plCallInfoLongVal
   ' =====================================================================================
   PROPERTY SET CallInfoLong <65541> ( _                ' VTable offset = 48
     BYVAL CallInfoLong AS LONG _                       ' __in CALLINFO_LONG CallInfoLong
   , BYVAL lCallInfoLongVal AS LONG _                   ' __in long lCallInfoLongVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallInfoString <65542> ( _              ' VTable offset = 52
     BYVAL CallInfoString AS LONG _                     ' __in CALLINFO_STRING CallInfoString
   ) AS WSTRING                                         ' __retval_out BSTR *ppCallInfoString
   ' =====================================================================================
   PROPERTY SET CallInfoString <65542> ( _              ' VTable offset = 56
     BYVAL CallInfoString AS LONG _                     ' __in CALLINFO_STRING CallInfoString
   , BYVAL pCallInfoString AS WSTRING _                 ' __in BSTR pCallInfoString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallInfoBuffer <65543> ( _              ' VTable offset = 60
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   ) AS VARIANT                                         ' __retval_out VARIANT *ppCallInfoBuffer
   ' =====================================================================================
   PROPERTY SET CallInfoBuffer <65543> ( _              ' VTable offset = 64
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYVAL pCallInfoBuffer AS VARIANT _                 ' __in VARIANT pCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCallInfoBuffer <65544> ( _                 ' VTable offset = 68
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppCallInfoBuffer AS DWORD _                  ' __out BYTE **ppCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCallInfoBuffer <65545> ( _                 ' VTable offset = 72
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL ppCallInfoBuffer AS BYTE PTR _               ' __in BYTE *pCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseUserUserInfo <65546> ( _               ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallInfo2
' IID = {94D70CA6-7AB0-4DAA-81CA-B8F8643FAEC1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITCallInfo
' ########################################################################################

#IF NOT %DEF(%ITCallInfo2_INTERFACE_DEFINED)
    %ITCallInfo2_INTERFACE_DEFINED = 1

INTERFACE ITCallInfo2 $IID_ITCallInfo2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITCallInfo Methods
   ' =====================================================================================
   PROPERTY GET Address <65537> ( _                     ' VTable offset = 28
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET CallState <65538> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALL_STATE *pCallState
   ' =====================================================================================
   PROPERTY GET Privilege <65539> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CALL_PRIVILEGE *pPrivilege
   ' =====================================================================================
   PROPERTY GET CallHub <65540> ( _                     ' VTable offset = 40
   ) AS ITCallHub                                       ' __retval_out ITCallHub **ppCallHub
   ' =====================================================================================
   PROPERTY GET CallInfoLong <65541> ( _                ' VTable offset = 44
     BYVAL CallInfoLong AS LONG _                       ' __in CALLINFO_LONG CallInfoLong
   ) AS LONG                                            ' __retval_out long *plCallInfoLongVal
   ' =====================================================================================
   PROPERTY SET CallInfoLong <65541> ( _                ' VTable offset = 48
     BYVAL CallInfoLong AS LONG _                       ' __in CALLINFO_LONG CallInfoLong
   , BYVAL lCallInfoLongVal AS LONG _                   ' __in long lCallInfoLongVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallInfoString <65542> ( _              ' VTable offset = 52
     BYVAL CallInfoString AS LONG _                     ' __in CALLINFO_STRING CallInfoString
   ) AS WSTRING                                         ' __retval_out BSTR *ppCallInfoString
   ' =====================================================================================
   PROPERTY SET CallInfoString <65542> ( _              ' VTable offset = 56
     BYVAL CallInfoString AS LONG _                     ' __in CALLINFO_STRING CallInfoString
   , BYVAL pCallInfoString AS WSTRING _                 ' __in BSTR pCallInfoString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallInfoBuffer <65543> ( _              ' VTable offset = 60
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   ) AS VARIANT                                         ' __retval_out VARIANT *ppCallInfoBuffer
   ' =====================================================================================
   PROPERTY SET CallInfoBuffer <65543> ( _              ' VTable offset = 64
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYVAL pCallInfoBuffer AS VARIANT _                 ' __in VARIANT pCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCallInfoBuffer <65544> ( _                 ' VTable offset = 68
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppCallInfoBuffer AS DWORD _                  ' __out BYTE **ppCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCallInfoBuffer <65545> ( _                 ' VTable offset = 72
     BYVAL CallInfoBuffer AS LONG _                     ' __in CALLINFO_BUFFER CallInfoBuffer
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL ppCallInfoBuffer AS BYTE PTR _               ' __in BYTE *pCallInfoBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseUserUserInfo <65546> ( _               ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITCallInfo2 Methods
   ' =====================================================================================
   PROPERTY GET EventFilter <65547> ( _                 ' VTable offset = 80
     BYVAL TapiEvent AS LONG _                          ' __in TAPI_EVENT TapiEvent
   , BYVAL lSubEvent AS LONG _                          ' __in long lSubEvent
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pEnable
   ' =====================================================================================
   PROPERTY SET EventFilter <65547> ( _                 ' VTable offset = 84
     BYVAL TapiEvent AS LONG _                          ' __in TAPI_EVENT TapiEvent
   , BYVAL lSubEvent AS LONG _                          ' __in long lSubEvent
   , BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL bEnable
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTerminal
' IID = {B1EFC38A-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTerminal_INTERFACE_DEFINED)
    %ITTerminal_INTERFACE_DEFINED = 1

INTERFACE ITTerminal $IID_ITTerminal

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY GET State <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out TERMINAL_STATE *pTerminalState
   ' =====================================================================================
   PROPERTY GET TerminalType <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TERMINAL_TYPE *pType
   ' =====================================================================================
   PROPERTY GET TerminalClass <4> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ppTerminalClass
   ' =====================================================================================
   PROPERTY GET MediaType <5> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================
   PROPERTY GET Direction <6> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out TERMINAL_DIRECTION *pDirection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminal_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMultiTrackTerminal
' IID = {FE040091-ADE8-4072-95C9-BF7DE8C54B44}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMultiTrackTerminal_INTERFACE_DEFINED)
    %ITMultiTrackTerminal_INTERFACE_DEFINED = 1

INTERFACE ITMultiTrackTerminal $IID_ITMultiTrackTerminal

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TrackTerminals <65537> ( _              ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateTrackTerminals <65538> ( _           ' VTable offset = 32
   ) AS IEnumTerminal                                   ' __retval_out IEnumTerminal **ppEnumTerminal
   ' =====================================================================================
   METHOD CreateTrackTerminal <65539> ( _               ' VTable offset = 36
     BYVAL MediaType AS LONG _                          ' __in long MediaType
   , BYVAL TerminalDirection AS LONG _                  ' __in TERMINAL_DIRECTION TerminalDirection
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET MediaTypesInUse <65540> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMediaTypesInUse
   ' =====================================================================================
   PROPERTY GET DirectionsInUse <65541> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out TERMINAL_DIRECTION *plDirectionsInUsed
   ' =====================================================================================
   METHOD RemoveTrackTerminal <65542> ( _               ' VTable offset = 48
     BYVAL pTrackTerminalToRemove AS ITTerminal _       ' __in ITTerminal *pTrackTerminalToRemove
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMultiTrackTerminal_INTERFACE_DEFINED__ */


' enum TERMINAL_MEDIA_STATE
%TMS_IDLE     = 0
%TMS_ACTIVE   = %TMS_IDLE   + 1
%TMS_PAUSED   = %TMS_ACTIVE + 1
%TMS_LASTITEM = %TMS_PAUSED

' enum FT_STATE_EVENT_CAUSE
%FTEC_NORMAL      = 0
%FTEC_END_OF_FILE = %FTEC_NORMAL      + 1
%FTEC_READ_ERROR  = %FTEC_END_OF_FILE + 1
%FTEC_WRITE_ERROR = %FTEC_READ_ERROR  + 1


' ########################################################################################
' Interface name = ITFileTrack
' IID = {31CA6EA9-C08A-4BEA-8811-8E9C1BA3EA3A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITFileTrack_INTERFACE_DEFINED)
    %ITFileTrack_INTERFACE_DEFINED = 1

INTERFACE ITFileTrack $IID_ITFileTrack

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Format <65537> ( _                      ' VTable offset = 28
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE **ppmt
   ' =====================================================================================
   PROPERTY SET Format <65537> ( _                      ' VTable offset = 32
     BYREF IN pmt AS AM_MEDIA_TYPE _                    ' __in const AM_MEDIA_TYPE *pmt
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControllingTerminal <65538> ( _         ' VTable offset = 36
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppControllingTerminal
   ' =====================================================================================
   PROPERTY GET AudioFormatForScripting <65539> ( _     ' VTable offset = 40
   ) AS ITScriptableAudioFormat                         ' __retval_out ITScriptableAudioFormat **ppAudioFormat
   ' =====================================================================================
   PROPERTY SET AudioFormatForScripting <65539> ( _     ' VTable offset = 44
     BYVAL pAudioFormat AS ITScriptableAudioFormat _    ' __in ITScriptableAudioFormat *pAudioFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmptyAudioFormatForScripting <65541> ( _ ' VTable offset = 48
   ) AS ITScriptableAudioFormat                         ' __retval_out ITScriptableAudioFormat **ppAudioFormat
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITFileTrack_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMediaPlayback
' IID = {627E8AE6-AE4C-4A69-BB63-2AD625404B77}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMediaPlayback_INTERFACE_DEFINED)
    %ITMediaPlayback_INTERFACE_DEFINED = 1

INTERFACE ITMediaPlayback $IID_ITMediaPlayback

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET PlayList <262145> ( _                   ' VTable offset = 28
     BYVAL PlayListVariant AS VARIANT _                 ' __in VARIANTARG PlayListVariant
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayList <262145> ( _                   ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANTARG *pPlayListVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMediaPlayback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMediaRecord
' IID = {F5DD4592-5476-4CC1-9D4D-FAD3EEFE7DB2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMediaRecord_INTERFACE_DEFINED)
    %ITMediaRecord_INTERFACE_DEFINED = 1

INTERFACE ITMediaRecord $IID_ITMediaRecord

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET FileName <196609> ( _                   ' VTable offset = 28
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <196609> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMediaRecord_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMediaControl
' IID = {C445DDE8-5199-4BC7-9807-5FFB92E42E09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMediaControl_INTERFACE_DEFINED)
    %ITMediaControl_INTERFACE_DEFINED = 1

INTERFACE ITMediaControl $IID_ITMediaControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Start <131073> ( _                            ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <131074> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <131075> ( _                            ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaState <131076> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out TERMINAL_MEDIA_STATE *pTerminalMediaState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMediaControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITBasicAudioTerminal
' IID = {B1EFC38D-9355-11D0-835C-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITBasicAudioTerminal_INTERFACE_DEFINED)
    %ITBasicAudioTerminal_INTERFACE_DEFINED = 1

INTERFACE ITBasicAudioTerminal $IID_ITBasicAudioTerminal

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Volume <1> ( _                          ' VTable offset = 28
     BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET Balance <2> ( _                         ' VTable offset = 36
     BYVAL lBalance AS LONG _                           ' __in long lBalance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <2> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plBalance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITBasicAudioTerminal_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITStaticAudioTerminal
' IID = {A86B7871-D14C-48E6-922E-A8D15F984800}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITStaticAudioTerminal_INTERFACE_DEFINED)
    %ITStaticAudioTerminal_INTERFACE_DEFINED = 1

INTERFACE ITStaticAudioTerminal $IID_ITStaticAudioTerminal

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET WaveId <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plWaveId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITStaticAudioTerminal_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallHub
' IID = {A3C1544E-5B92-11D1-8F4E-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallHub_INTERFACE_DEFINED)
    %ITCallHub_INTERFACE_DEFINED = 1

INTERFACE ITCallHub $IID_ITCallHub

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Clear <1> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateCalls <2> ( _                        ' VTable offset = 32
   ) AS IEnumCall                                       ' __retval_out IEnumCall **ppEnumCall
   ' =====================================================================================
   PROPERTY GET Calls <3> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pCalls
   ' =====================================================================================
   PROPERTY GET NumCalls <4> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET State <5> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CALLHUB_STATE *pState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallHub_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLegacyAddressMediaControl
' IID = {AB493640-4C0B-11D2-A046-00C04FB6809F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITLegacyAddressMediaControl_INTERFACE_DEFINED)
    %ITLegacyAddressMediaControl_INTERFACE_DEFINED = 1

INTERFACE ITLegacyAddressMediaControl $IID_ITLegacyAddressMediaControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 12
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceID AS DWORD _                        ' __out BYTE **ppDeviceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevConfig ( _                              ' VTable offset = 16
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceConfig AS DWORD _                    ' __out BYTE **ppDeviceConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDevConfig ( _                              ' VTable offset = 20
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL pDeviceConfig AS BYTE PTR _                  ' __in BYTE *pDeviceConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLegacyAddressMediaControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPrivateEvent
' IID = {0E269CD0-10D4-4121-9C22-9C85D625650D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPrivateEvent_INTERFACE_DEFINED)
    %ITPrivateEvent_INTERFACE_DEFINED = 1

INTERFACE ITPrivateEvent $IID_ITPrivateEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Address <1> ( _                         ' VTable offset = 28
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET Call <2> ( _                            ' VTable offset = 32
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET CallHub <3> ( _                         ' VTable offset = 36
   ) AS ITCallHub                                       ' __retval_out ITCallHub **ppCallHub
   ' =====================================================================================
   PROPERTY GET EventCode <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plEventCode
   ' =====================================================================================
   PROPERTY GET EventInterface <5> ( _                  ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **pEventInterface
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPrivateEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLegacyAddressMediaControl2
' IID = {B0EE512B-A531-409E-9DD9-4099FE86C738}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = ITLegacyAddressMediaControl
' ########################################################################################

#IF NOT %DEF(%ITLegacyAddressMediaControl2_INTERFACE_DEFINED)
    %ITLegacyAddressMediaControl2_INTERFACE_DEFINED = 1

INTERFACE ITLegacyAddressMediaControl2 $IID_ITLegacyAddressMediaControl2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITLegacyAddressMediaControl Methods
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 12
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceID AS DWORD _                        ' __out BYTE **ppDeviceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevConfig ( _                              ' VTable offset = 16
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceConfig AS DWORD _                    ' __out BYTE **ppDeviceConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDevConfig ( _                              ' VTable offset = 20
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL pDeviceConfig AS BYTE PTR _                  ' __in BYTE *pDeviceConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITLegacyAddressMediaControl2 Methods
   ' =====================================================================================
   METHOD ConfigDialog ( _                              ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigDialogEdit ( _                          ' VTable offset = 28
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYVAL dwSizeIn AS DWORD _                          ' __in DWORD dwSizeIn
   , BYVAL pDeviceConfigIn AS BYTE PTR _                ' __in BYTE *pDeviceConfigIn
   , BYREF pdwSizeOut AS DWORD _                        ' __out DWORD *pdwSizeOut
   , BYREF ppDeviceConfigOut AS DWORD _                 ' __out BYTE **ppDeviceConfigOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLegacyAddressMediaControl2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLegacyCallMediaControl
' IID = {D624582F-CC23-4436-B8A5-47C625C8045D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITLegacyCallMediaControl_INTERFACE_DEFINED)
    %ITLegacyCallMediaControl_INTERFACE_DEFINED = 1

INTERFACE ITLegacyCallMediaControl $IID_ITLegacyCallMediaControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD DetectDigits <196609> ( _                     ' VTable offset = 28
     BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateDigits <196610> ( _                   ' VTable offset = 32
     BYVAL pDigits AS WSTRING _                         ' __in BSTR pDigits
   , BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetID <196611> ( _                            ' VTable offset = 36
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceID AS DWORD _                        ' __out BYTE **ppDeviceID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMediaType <196612> ( _                     ' VTable offset = 40
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD MonitorMedia <196613> ( _                     ' VTable offset = 44
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLegacyCallMediaControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLegacyCallMediaControl2
' IID = {57CA332D-7BC2-44F1-A60C-936FE8D7CE73}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITLegacyCallMediaControl
' ########################################################################################

#IF NOT %DEF(%ITLegacyCallMediaControl2_INTERFACE_DEFINED)
    %ITLegacyCallMediaControl2_INTERFACE_DEFINED = 1

INTERFACE ITLegacyCallMediaControl2 $IID_ITLegacyCallMediaControl2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITLegacyCallMediaControl Methods
   ' =====================================================================================
   METHOD DetectDigits <196609> ( _                     ' VTable offset = 28
     BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateDigits <196610> ( _                   ' VTable offset = 32
     BYVAL pDigits AS WSTRING _                         ' __in BSTR pDigits
   , BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetID <196611> ( _                            ' VTable offset = 36
     BYVAL pDeviceClass AS WSTRING _                    ' __in BSTR pDeviceClass
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF ppDeviceID AS DWORD _                        ' __out BYTE **ppDeviceID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMediaType <196612> ( _                     ' VTable offset = 40
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD MonitorMedia <196613> ( _                     ' VTable offset = 44
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITLegacyCallMediaControl2 Methods
   ' =====================================================================================
   METHOD GenerateDigits2 <196614> ( _                  ' VTable offset = 48
     BYVAL pDigits AS WSTRING _                         ' __in BSTR pDigits
   , BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD GatherDigits <196615> ( _                     ' VTable offset = 52
     BYVAL DigitMode AS LONG _                          ' __in TAPI_DIGITMODE DigitMode
   , BYVAL lNumDigits AS LONG _                         ' __in long lNumDigits
   , BYVAL pTerminationDigits AS WSTRING _              ' __in BSTR pTerminationDigits
   , BYVAL lFirstDigitTimeout AS LONG _                 ' __in long lFirstDigitTimeout
   , BYVAL lInterDigitTimeout AS LONG _                 ' __in long lInterDigitTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD DetectTones <196616> ( _                      ' VTable offset = 56
     BYREF pToneList AS TAPI_DETECTTONE _               ' __in TAPI_DETECTTONE *pToneList
   , BYVAL lNumTones AS LONG _                          ' __in long lNumTones
   )                                                    ' void
   ' =====================================================================================
   METHOD DetectTonesByCollection <196617> ( _          ' VTable offset = 60
     BYVAL pDetectToneCollection AS ITCollection2 _     ' __in ITCollection2 *pDetectToneCollection
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateTone <196618> ( _                     ' VTable offset = 64
     BYVAL ToneMode AS LONG _                           ' __in TAPI_TONEMODE ToneMode
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateCustomTones <196619> ( _              ' VTable offset = 68
     BYREF pToneList AS TAPI_CUSTOMTONE _               ' __in TAPI_CUSTOMTONE *pToneList
   , BYVAL lNumTones AS LONG _                          ' __in long lNumTones
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateCustomTonesByCollection <196620> ( _  ' VTable offset = 72
     BYVAL pCustomToneCollection AS ITCollection2 _     ' __in ITCollection2 *pCustomToneCollection
   , BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDetectToneObject <196621> ( _           ' VTable offset = 76
   ) AS ITDetectTone                                    ' __retval_out ITDetectTone **ppDetectTone
   ' =====================================================================================
   METHOD CreateCustomToneObject <196622> ( _           ' VTable offset = 80
   ) AS ITCustomTone                                    ' __retval_out ITCustomTone **ppCustomTone
   ' =====================================================================================
   METHOD GetIDAsVariant <196623> ( _                   ' VTable offset = 84
     BYVAL bstrDeviceClass AS WSTRING _                 ' __in BSTR bstrDeviceClass
   ) AS VARIANT                                         ' __retval_out VARIANT *pVarDeviceID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLegacyCallMediaControl2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDetectTone
' IID = {961F79BD-3097-49DF-A1D6-909B77E89CA0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDetectTone_INTERFACE_DEFINED)
    %ITDetectTone_INTERFACE_DEFINED = 1

INTERFACE ITDetectTone $IID_ITDetectTone

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AppSpecific <1> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY SET AppSpecific <1> ( _                     ' VTable offset = 32
     BYVAL lAppSpecific AS LONG _                       ' __in long lAppSpecific
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <2> ( _                        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plDuration
   ' =====================================================================================
   PROPERTY SET Duration <2> ( _                        ' VTable offset = 40
     BYVAL lDuration AS LONG _                          ' __in long lDuration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Frequency <3> ( _                       ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS LONG                                            ' __retval_out long *plFrequency
   ' =====================================================================================
   PROPERTY SET Frequency <3> ( _                       ' VTable offset = 48
     BYVAL Index AS LONG _                              ' __in long Index
   , BYVAL lFrequency AS LONG _                         ' __in long lFrequency
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDetectTone_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCustomTone
' IID = {357AD764-B3C6-4B2A-8FA5-0722827A9254}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCustomTone_INTERFACE_DEFINED)
    %ITCustomTone_INTERFACE_DEFINED = 1

INTERFACE ITCustomTone $IID_ITCustomTone

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Frequency <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plFrequency
   ' =====================================================================================
   PROPERTY SET Frequency <1> ( _                       ' VTable offset = 32
     BYVAL lFrequency AS LONG _                         ' __in long lFrequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CadenceOn <2> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCadenceOn
   ' =====================================================================================
   PROPERTY SET CadenceOn <2> ( _                       ' VTable offset = 40
     BYVAL CadenceOn AS LONG _                          ' __in long CadenceOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CadenceOff <3> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCadenceOff
   ' =====================================================================================
   PROPERTY SET CadenceOff <3> ( _                      ' VTable offset = 48
     BYVAL lCadenceOff AS LONG _                        ' __in long lCadenceOff
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <4> ( _                          ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET Volume <4> ( _                          ' VTable offset = 56
     BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCustomTone_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumPhone
' IID = {F15B7669-4780-4595-8C89-FB369C8CF7AA}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPhone_INTERFACE_DEFINED)
    %IEnumPhone_INTERFACE_DEFINED = 1

INTERFACE IEnumPhone $IID_IEnumPhone

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITPhone _                      ' __out ITPhone **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumPhone _                       ' __retval_out IEnumPhone **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPhone_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumTerminal
' IID = {AE269CF4-935E-11D0-835C-00AA003CCABD}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTerminal_INTERFACE_DEFINED)
    %IEnumTerminal_INTERFACE_DEFINED = 1

INTERFACE IEnumTerminal $IID_IEnumTerminal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITTerminal _                   ' __out ITTerminal **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumTerminal _                    ' __retval_out IEnumTerminal **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTerminal_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumTerminalClass
' IID = {AE269CF5-935E-11D0-835C-00AA003CCABD}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTerminalClass_INTERFACE_DEFINED)
    %IEnumTerminalClass_INTERFACE_DEFINED = 1

INTERFACE IEnumTerminalClass $IID_IEnumTerminalClass

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pElements AS GUID _                          ' __out GUID *pElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumTerminalClass _               ' __retval_out IEnumTerminalClass **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTerminalClass_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCall
' IID = {AE269CF6-935E-11D0-835C-00AA003CCABD}
' TAPI 3.0 IEnumCall interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumCall_INTERFACE_DEFINED)
    %IEnumCall_INTERFACE_DEFINED = 1

INTERFACE IEnumCall $IID_IEnumCall

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITCallInfo _                   ' __out ITCallInfo **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumCall _                        ' __retval_out IEnumCall **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCall_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumAddress
' IID = {1666FCA1-9363-11D0-835C-00AA003CCABD}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAddress_INTERFACE_DEFINED)
    %IEnumAddress_INTERFACE_DEFINED = 1

INTERFACE IEnumAddress $IID_IEnumAddress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITAddress _                    ' __out ITAddress **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumAddress _                     ' __retval_out IEnumAddress **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAddress_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCallHub
' IID = {A3C15450-5B92-11D1-8F4E-00C04FB6809F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumCallHub_INTERFACE_DEFINED)
    %IEnumCallHub_INTERFACE_DEFINED = 1

INTERFACE IEnumCallHub $IID_IEnumCallHub

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITCallHub _                    ' __out ITCallHub **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumCallHub _                     ' __retval_out IEnumCallHub **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCallHub_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumBstr
' IID = {35372049-0BC6-11D2-A033-00C04FB6809F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBstr_INTERFACE_DEFINED)
    %IEnumBstr_INTERFACE_DEFINED = 1

INTERFACE IEnumBstr $IID_IEnumBstr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppStrings AS WSTRING _                       ' __out BSTR *ppStrings
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumBstr _                        ' __retval_out IEnumBstr **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBstr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumPluggableTerminalClassInfo
' IID = {4567450C-DBEE-4E3F-AAF5-37BF9EBF5E29}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPluggableTerminalClassInfo_INTERFACE_DEFINED)
   %IEnumPluggableTerminalClassInfo_INTERFACE_DEFINED = 1

INTERFACE IEnumPluggableTerminalClassInfo $IID_IEnumPluggableTerminalClassInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITPluggableTerminalClassInfo _ ' __out ITPluggableTerminalClassInfo **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumPluggableTerminalClassInfo _  ' __retval_out IEnumPluggableTerminalClassInfo **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPluggableTerminalClassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumPluggableSuperclassInfo
' IID = {E9586A80-89E6-4CFF-931D-478D5751F4C0}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPluggableSuperclassInfo_INTERFACE_DEFINED)
    %IEnumPluggableSuperclassInfo_INTERFACE_DEFINED = 1

INTERFACE IEnumPluggableSuperclassInfo $IID_IEnumPluggableSuperclassInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITPluggableTerminalSuperclassInfo _ ' __out ITPluggableTerminalSuperclassInfo **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumPluggableSuperclassInfo _     ' __retval_out IEnumPluggableSuperclassInfo **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPluggableSuperclassInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPhoneEvent
' IID = {8F942DD8-64ED-4AAF-A77D-B23DB0837EAD}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPhoneEvent_INTERFACE_DEFINED)
    %ITPhoneEvent_INTERFACE_DEFINED = 1

INTERFACE ITPhoneEvent $IID_ITPhoneEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Phone <1> ( _                           ' VTable offset = 28
   ) AS ITPhone                                         ' __retval_out ITPhone **ppPhone
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out PHONE_EVENT *pEvent
   ' =====================================================================================
   PROPERTY GET ButtonState <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out PHONE_BUTTON_STATE *pState
   ' =====================================================================================
   PROPERTY GET HookSwitchState <4> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out PHONE_HOOK_SWITCH_STATE *pState
   ' =====================================================================================
   PROPERTY GET HookSwitchDevice <5> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out PHONE_HOOK_SWITCH_DEVICE *pDevice
   ' =====================================================================================
   PROPERTY GET RingMode <6> ( _                        ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plRingMode
   ' =====================================================================================
   PROPERTY GET ButtonLampId <7> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plButtonLampId
   ' =====================================================================================
   PROPERTY GET NumberGathered <8> ( _                  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *ppNumber
   ' =====================================================================================
   PROPERTY GET Call <9> ( _                            ' VTable offset = 60
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPhoneEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallStateEvent
' IID = {62F47097-95C9-11D0-835D-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallStateEvent_INTERFACE_DEFINED)
    %ITCallStateEvent_INTERFACE_DEFINED = 1

INTERFACE ITCallStateEvent $IID_ITCallStateEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      '  __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET State <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALL_STATE *pCallState
   ' =====================================================================================
   PROPERTY GET Cause <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CALL_STATE_EVENT_CAUSE *pCEC
   ' =====================================================================================
   PROPERTY GET CallbackInstance <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallStateEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPhoneDeviceSpecificEvent
' IID = {63FFB2A6-872B-4CD3-A501-326E8FB40AF7}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPhoneDeviceSpecificEvent_INTERFACE_DEFINED)
    %ITPhoneDeviceSpecificEvent_INTERFACE_DEFINED = 1

INTERFACE ITPhoneDeviceSpecificEvent $IID_ITPhoneDeviceSpecificEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Phone <1> ( _                           ' VTable offset = 28
   ) AS ITPhone                                         ' __retval_out ITPhone **ppPhone
   ' =====================================================================================
   PROPERTY GET lParam1 <2> ( _                         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pParam1
   ' =====================================================================================
   PROPERTY GET lParam2 <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pParam2
   ' =====================================================================================
   PROPERTY GET lParam3 <4> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pParam3
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPhoneDeviceSpecificEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallMediaEvent
' IID = {FF36B87F-EC3A-11D0-8EE4-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallMediaEvent_INTERFACE_DEFINED)
    %ITCallMediaEvent_INTERFACE_DEFINED = 1

INTERFACE ITCallMediaEvent $IID_ITCallMediaEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALL_MEDIA_EVENT *pCallMediaEvent
   ' =====================================================================================
   PROPERTY GET Error <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out HRESULT *phrError
   ' =====================================================================================
   PROPERTY GET Terminal <4> ( _                        ' VTable offset = 40
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET Stream <5> ( _                          ' VTable offset = 44
   ) AS ITStream                                        ' __retval_out ITStream **ppStream
   ' =====================================================================================
   PROPERTY GET Cause <6> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out CALL_MEDIA_EVENT_CAUSE *pCause
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallMediaEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDigitDetectionEvent
' IID = {80D3BFAC-57D9-11D2-A04A-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDigitDetectionEvent_INTERFACE_DEFINED)
    %ITDigitDetectionEvent_INTERFACE_DEFINED = 1

INTERFACE ITDigitDetectionEvent $IID_ITDigitDetectionEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET Digit <2> ( _                           ' VTable offset = 32
   ) AS BYTE                                            ' __retval_out unsigned char *pucDigit
   ' =====================================================================================
   PROPERTY GET DigitMode <3> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TAPI_DIGITMODE *pDigitMode
   ' =====================================================================================
   PROPERTY GET TickCount <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plTickCount
   ' =====================================================================================
   PROPERTY GET CallbackInstance <5> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDigitDetectionEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDigitGenerationEvent
' IID = {80D3BFAD-57D9-11D2-A04A-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDigitGenerationEvent_INTERFACE_DEFINED)
    %ITDigitGenerationEvent_INTERFACE_DEFINED = 1

INTERFACE ITDigitGenerationEvent $IID_ITDigitGenerationEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET GenerationTermination <2> ( _           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plGenerationTermination
   ' =====================================================================================
   PROPERTY GET TickCount <3> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plTickCount
   ' =====================================================================================
   PROPERTY GET CallbackInstance <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDigitGenerationEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDigitsGatheredEvent
' IID = {E52EC4C1-CBA3-441A-9E6A-93CB909E9724}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDigitsGatheredEvent_INTERFACE_DEFINED)
    %ITDigitsGatheredEvent_INTERFACE_DEFINED = 1

INTERFACE ITDigitsGatheredEvent $IID_ITDigitsGatheredEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET Digits <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppDigits
   ' =====================================================================================
   PROPERTY GET GatherTermination <3> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TAPI_GATHERTERM *pGatherTermination
   ' =====================================================================================
   PROPERTY GET TickCount <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plTickCount
   ' =====================================================================================
   PROPERTY GET CallbackInstance <5> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDigitsGatheredEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITToneDetectionEvent
' IID = {407E0FAF-D047-4753-B0C6-8E060373FECD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITToneDetectionEvent_INTERFACE_DEFINED)
    %ITToneDetectionEvent_INTERFACE_DEFINED = 1

INTERFACE ITToneDetectionEvent $IID_ITToneDetectionEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCallInfo
   ' =====================================================================================
   PROPERTY GET AppSpecific <2> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY GET TickCount <3> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plTickCount
   ' =====================================================================================
   PROPERTY GET CallbackInstance <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITToneDetectionEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTAPIObjectEvent
' IID = {F4854D48-937A-11D1-BB58-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTAPIObjectEvent_INTERFACE_DEFINED)
    %ITTAPIObjectEvent_INTERFACE_DEFINED = 1

INTERFACE ITTAPIObjectEvent $IID_ITTAPIObjectEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TAPIObject <1> ( _                      ' VTable offset = 28
   ) AS ITTAPI                                          ' __retval_out ITTAPI **ppTAPIObject
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out TAPIOBJECT_EVENT *pEvent
   ' =====================================================================================
   PROPERTY GET Address <3> ( _                         ' VTable offset = 36
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET CallbackInstance <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPIObjectEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTAPIObjectEvent2
' IID = {359DDA6E-68CE-4383-BF0B-169133C41B46}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = ITTAPIObjectEvent
' ########################################################################################

#IF NOT %DEF(%ITTAPIObjectEvent2_INTERFACE_DEFINED)
    %ITTAPIObjectEvent2_INTERFACE_DEFINED = 1

INTERFACE ITTAPIObjectEvent2 $IID_ITTAPIObjectEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITTAPIObjectEvent Methods
   ' =====================================================================================
   PROPERTY GET TAPIObject <1> ( _                      ' VTable offset = 28
   ) AS ITTAPI                                          ' __retval_out ITTAPI **ppTAPIObject
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out TAPIOBJECT_EVENT *pEvent
   ' =====================================================================================
   PROPERTY GET Address <3> ( _                         ' VTable offset = 36
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET CallbackInstance <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

   ' =====================================================================================
   ' ITTAPIObjectEvent2 Methods
   ' =====================================================================================
   PROPERTY GET Phone <5> ( _                           ' VTable offset = 44
   ) AS ITPhone                                         ' __retval_out ITPhone **ppPhone
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPIObjectEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTAPIEventNotification
' IID = {EDDB9426-3B91-11D1-8F30-00C04FB6809F}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITTAPIEventNotification_INTERFACE_DEFINED)
    %ITTAPIEventNotification_INTERFACE_DEFINED = 1

INTERFACE ITTAPIEventNotification $IID_ITTAPIEventNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Event ( _                                     ' VTable offset = 12
     BYVAL TapiEvent AS LONG _                          ' __in TAPI_EVENT TapiEvent
   , BYVAL pEvent AS IDispatch _                        ' __in IDispatch *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPIEventNotification_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallHubEvent
' IID = {A3C15451-5B92-11D1-8F4E-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallHubEvent_INTERFACE_DEFINED)
    %ITCallHubEvent_INTERFACE_DEFINED = 1

INTERFACE ITCallHubEvent $IID_ITCallHubEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Event <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CALLHUB_EVENT *pEvent
   ' =====================================================================================
   PROPERTY GET CallHub <2> ( _                         ' VTable offset = 32
   ) AS ITCallHub                                       ' __retval_out ITCallHub **ppCallHub
   ' =====================================================================================
   PROPERTY GET Call <3> ( _                            ' VTable offset = 36
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallHubEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddressEvent
' IID = {831CE2D1-83B5-11D1-BB5C-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddressEvent_INTERFACE_DEFINED)
    %ITAddressEvent_INTERFACE_DEFINED = 1

INTERFACE ITAddressEvent $IID_ITAddressEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Address <1> ( _                         ' VTable offset = 28
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ADDRESS_EVENT *pEvent
   ' =====================================================================================
   PROPERTY GET Terminal <3> ( _                        ' VTable offset = 36
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddressEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddressDeviceSpecificEvent
' IID = {3ACB216B-40BD-487A-8672-5CE77BD7E3A3}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddressDeviceSpecificEvent_INTERFACE_DEFINED)
    %ITAddressDeviceSpecificEvent_INTERFACE_DEFINED = 1

INTERFACE ITAddressDeviceSpecificEvent $IID_ITAddressDeviceSpecificEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Address <1> ( _                         ' VTable offset = 28
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET Call <2> ( _                            ' VTable offset = 32
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET lParam1 <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pParam1
   ' =====================================================================================
   PROPERTY GET lParam2 <4> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pParam2
   ' =====================================================================================
   PROPERTY GET lParam3 <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pParam3
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddressDeviceSpecificEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITFileTerminalEvent
' IID = {E4A7FBAC-8C17-4427-9F55-9F589AC8AF00}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITFileTerminalEvent_INTERFACE_DEFINED)
    %ITFileTerminalEvent_INTERFACE_DEFINED = 1

INTERFACE ITFileTerminalEvent $IID_ITFileTerminalEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Terminal <1> ( _                        ' VTable offset = 28
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET Track <2> ( _                           ' VTable offset = 32
   ) AS ITFileTrack                                     ' __retval_out ITFileTrack **ppTrackTerminal
   ' =====================================================================================
   PROPERTY GET Call <3> ( _                            ' VTable offset = 36
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET State <4> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out TERMINAL_MEDIA_STATE *pState
   ' =====================================================================================
   PROPERTY GET Cause <5> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out FT_STATE_EVENT_CAUSE *pCause
   ' =====================================================================================
   PROPERTY GET Error <6> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out HRESULT *phrErrorCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITFileTerminalEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTTSTerminalEvent
' IID = {D964788F-95A5-461D-AB0C-B9900A6C2713}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTTSTerminalEvent_INTERFACE_DEFINED)
    %ITTTSTerminalEvent_INTERFACE_DEFINED = 1

INTERFACE ITTTSTerminalEvent $IID_ITTTSTerminalEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Terminal <1> ( _                        ' VTable offset = 28
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET Call <2> ( _                            ' VTable offset = 32
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Error <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out HRESULT *phrErrorCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTTSTerminalEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITASRTerminalEvent
' IID = {EE016A02-4FA9-467C-933F-5A15B12377D7}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITASRTerminalEvent_INTERFACE_DEFINED)
    %ITASRTerminalEvent_INTERFACE_DEFINED = 1

INTERFACE ITASRTerminalEvent $IID_ITASRTerminalEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Terminal <1> ( _                        ' VTable offset = 28
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET Call <2> ( _                            ' VTable offset = 32
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Error <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out HRESULT *phrErrorCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITASRTerminalEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITToneTerminalEvent
' IID = {E6F56009-611F-4945-BBD2-2D0CE5612056}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITToneTerminalEvent_INTERFACE_DEFINED)
    %ITToneTerminalEvent_INTERFACE_DEFINED = 1

INTERFACE ITToneTerminalEvent $IID_ITToneTerminalEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Terminal <1> ( _                        ' VTable offset = 28
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   PROPERTY GET Call <2> ( _                            ' VTable offset = 32
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Error <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out HRESULT *phrErrorCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITToneTerminalEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITQOSEvent
' IID = {CFA3357C-AD77-11D1-BB68-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITQOSEvent_INTERFACE_DEFINED)
    %ITQOSEvent_INTERFACE_DEFINED = 1

INTERFACE ITQOSEvent $IID_ITQOSEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Event <3> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out QOS_EVENT *pQosEvent
   ' =====================================================================================
   PROPERTY GET MediaType <4> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITQOSEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallInfoChangeEvent
' IID = {5D4B65F9-E51C-11D1-A02F-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallInfoChangeEvent_INTERFACE_DEFINED)
    %ITCallInfoChangeEvent_INTERFACE_DEFINED = 1

INTERFACE ITCallInfoChangeEvent $IID_ITCallInfoChangeEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Cause <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALLINFOCHANGE_CAUSE *pCIC
   ' =====================================================================================
   PROPERTY GET CallbackInstance <3> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallInfoChangeEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITRequest
' IID = {AC48FFDF-F8C4-11D1-A030-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITRequest_INTERFACE_DEFINED)
    %ITRequest_INTERFACE_DEFINED = 1

INTERFACE ITRequest $IID_ITRequest

   INHERIT IDispatch

   ' =====================================================================================
   METHOD MakeCall <1> ( _                              ' VTable offset = 28
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL pAppName AS WSTRING _                        ' __in BSTR pAppName
   , BYVAL pCalledParty AS WSTRING _                    ' __in BSTR pCalledParty
   , BYVAL pComment AS WSTRING _                        ' __in BSTR pComment
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITRequest_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITRequestEvent
' IID = {AC48FFDE-F8C4-11D1-A030-00C04FB6809F}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITRequestEvent_INTERFACE_DEFINED)
    %ITRequestEvent_INTERFACE_DEFINED = 1

INTERFACE ITRequestEvent $IID_ITRequestEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RegistrationInstance <1> ( _            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plRegistrationInstance
   ' =====================================================================================
   PROPERTY GET RequestMode <2> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRequestMode
   ' =====================================================================================
   PROPERTY GET DestAddress <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppDestAddress
   ' =====================================================================================
   PROPERTY GET AppName <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ppAppName
   ' =====================================================================================
   PROPERTY GET CalledParty <6> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *ppCalledParty
   ' =====================================================================================
   PROPERTY GET Comment <7> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ppComment
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITRequestEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCollection
' IID = {5EC5ACF2-9C02-11D0-8362-00AA003CCABD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCollection_INTERFACE_DEFINED)
    %ITCollection_INTERFACE_DEFINED = 1

INTERFACE ITCollection $IID_ITCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCollection2
' IID = {E6DDDDA5-A6D3-48FF-8737-D32FC4D95477}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITCollection
' ########################################################################################

#IF NOT %DEF(%ITCollection2_INTERFACE_DEFINED)
    %ITCollection2_INTERFACE_DEFINED = 1

INTERFACE ITCollection2 $IID_ITCollection2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITCollection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppNewEnum
   ' =====================================================================================

   ' =====================================================================================
   ' ITCollection2 Methods
   ' =====================================================================================
   METHOD Add <1> ( _                                   ' VTable offset = 40
     BYVAL Index AS LONG _                              ' __in long Index
   , BYREF pVariant AS VARIANT _                        ' __in VARIANT *pVariant
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <2> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCollection2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITForwardInformation
' IID = {449F659E-88A3-11D1-BB5D-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITForwardInformation_INTERFACE_DEFINED)
    %ITForwardInformation_INTERFACE_DEFINED = 1

INTERFACE ITForwardInformation $IID_ITForwardInformation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET NumRingsNoAnswer <1> ( _                ' VTable offset = 28
     BYVAL lNumRings AS LONG _                          ' __in long lNumRings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumRingsNoAnswer <1> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plNumRings
   ' =====================================================================================
   METHOD SetForwardType <2> ( _                        ' VTable offset = 36
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL pCallerAddress AS WSTRING _                  ' __in BSTR pCallerAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForwardTypeDestination <3> ( _          ' VTable offset = 40
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   ) AS WSTRING                                         ' __retval_out BSTR *ppDestAddress
   ' =====================================================================================
   PROPERTY GET ForwardTypeCaller <4> ( _               ' VTable offset = 44
     BYVAL ForwardType AS LONG _                        ' __in long Forwardtype
   ) AS WSTRING                                         ' __retval_out BSTR *ppCallerAddress
   ' =====================================================================================
   METHOD GetForwardType <5> ( _                        ' VTable offset = 48
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYREF ppDestinationAddress AS WSTRING _            ' __out BSTR *ppDestinationAddress
   , BYREF ppCallerAddress AS WSTRING _                 ' __out BSTR *ppCallerAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <6> ( _                                 ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITForwardInformation_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITForwardInformation2
' IID = {5229B4ED-B260-4382-8E1A-5DF3A8A4CCC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITForwardInformation
' ########################################################################################

#IF NOT %DEF(%ITForwardInformation2_INTERFACE_DEFINED)
    %ITForwardInformation2_INTERFACE_DEFINED = 1

INTERFACE ITForwardInformation2 $IID_ITForwardInformation2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITForwardInformation Methods
   ' =====================================================================================
   PROPERTY SET NumRingsNoAnswer <1> ( _                ' VTable offset = 28
     BYVAL lNumRings AS LONG _                          ' __in long lNumRings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumRingsNoAnswer <1> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plNumRings
   ' =====================================================================================
   METHOD SetForwardType <2> ( _                        ' VTable offset = 36
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL pCallerAddress AS WSTRING _                  ' __in BSTR pCallerAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForwardTypeDestination <3> ( _          ' VTable offset = 40
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   ) AS WSTRING                                         ' __retval_out BSTR *ppDestAddress
   ' =====================================================================================
   PROPERTY GET ForwardTypeCaller <4> ( _               ' VTable offset = 44
     BYVAL ForwardType AS LONG _                        ' __in long Forwardtype
   ) AS WSTRING                                         ' __retval_out BSTR *ppCallerAddress
   ' =====================================================================================
   METHOD GetForwardType <5> ( _                        ' VTable offset = 48
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYREF ppDestinationAddress AS WSTRING _            ' __out BSTR *ppDestinationAddress
   , BYREF ppCallerAddress AS WSTRING _                 ' __out BSTR *ppCallerAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <6> ( _                                 ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITForwardInformation2 Methods
   ' =====================================================================================
   METHOD SetForwardType2 <7> ( _                       ' VTable offset = 56
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   , BYVAL DestAddressType AS LONG _                    ' __in long DestAddressType
   , BYVAL pCallerAddress AS WSTRING _                  ' __in BSTR pCallerAddress
   , BYVAL CallerAddressType AS LONG _                  ' __in long CallerAddressType
   )                                                    ' void
   ' =====================================================================================
   METHOD GetForwardType2 <8> ( _                       ' VTable offset = 60
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   , BYREF ppDestinationAddress AS WSTRING _            ' __out BSTR *ppDestinationAddress
   , BYREF pDestAddressType AS LONG _                   ' __out long *pDestAddressType
   , BYREF ppCallerAddress AS WSTRING _                 ' __out BSTR *ppCallerAddress
   , BYREF pCallerAddressType AS LONG _                 ' __out long *pCallerAddressType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForwardTypeDestinationAddressType <9> ( _ ' VTable offset = 64
     BYVAL ForwardType AS LONG _                        ' __in long ForwardType
   ) AS LONG                                            ' __retval_out long *pDestAddressType
   ' =====================================================================================
   PROPERTY GET ForwardTypeCallerAddressType <10> ( _   ' VTable offset = 68
     BYVAL ForwardType AS LONG _                        ' __in long Forwardtype
   ) AS LONG                                            ' __retval_out long *pCallerAddressType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITForwardInformation2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddressTranslation
' IID = {0C4D8F03-8DDB-11D1-A09E-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddressTranslation_INTERFACE_DEFINED)
    %ITAddressTranslation_INTERFACE_DEFINED = 1

INTERFACE ITAddressTranslation $IID_ITAddressTranslation

   INHERIT IDispatch

   ' =====================================================================================
   METHOD TranslateAddress <262145> ( _                 ' VTable offset = 28
     BYVAL pAddressToTranslate AS WSTRING _             ' __in BSTR pAddressToTranslate
   , BYVAL lCard AS LONG _                              ' __in long lCard
   , BYVAL lTranslateOptions AS LONG _                  ' __in long lTranslateOptions
   ) AS ITAddressTranslationInfo                        ' __retval_out ITAddressTranslationInfo **ppTranslated
   ' =====================================================================================
   METHOD TranslateDialog <262146> ( _                  ' VTable offset = 32
     BYVAL hwndOwner AS LONG _                          ' __in TAPIHWND hwndOwner
   , BYVAL pAddressIn AS WSTRING _                      ' __in BSTR pAddressIn
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateLocations <262147> ( _               ' VTable offset = 36
   ) AS IEnumLocation                                   ' __retval_out IEnumLocation **ppEnumLocation
   ' =====================================================================================
   PROPERTY GET Locations <262148> ( _                  ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateCallingCards <262149> ( _            ' VTable offset = 44
   ) AS IEnumCallingCard                                ' __retval_out IEnumCallingCard **ppEnumCallingCard
   ' =====================================================================================
   PROPERTY GET CallingCards <262150> ( _               ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddressTranslation_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAddressTranslationInfo
' IID = {AFC15945-8D40-11D1-A09E-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAddressTranslationInfo_INTERFACE_DEFINED)
    %ITAddressTranslationInfo_INTERFACE_DEFINED = 1

INTERFACE ITAddressTranslationInfo $IID_ITAddressTranslationInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DialableString <1> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppDialableString
   ' =====================================================================================
   PROPERTY GET DisplayableString <2> ( _               ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppDisplayableString
   ' =====================================================================================
   PROPERTY GET CurrentCountryCode <3> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *CountryCode
   ' =====================================================================================
   PROPERTY GET DestinationCountryCode <4> ( _          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *CountryCode
   ' =====================================================================================
   PROPERTY GET TranslationResults <5> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plResults
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAddressTranslationInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLocationInfo
' IID = {0C4D8EFF-8DDB-11D1-A09E-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITLocationInfo_INTERFACE_DEFINED)
    %ITLocationInfo_INTERFACE_DEFINED = 1

INTERFACE ITLocationInfo $IID_ITLocationInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PermanentLocationID <1> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plLocationID
   ' =====================================================================================
   PROPERTY GET CountryCode <2> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plCountryCode
   ' =====================================================================================
   PROPERTY GET CountryID <3> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCountryID
   ' =====================================================================================
   PROPERTY GET Options <4> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plOptions
   ' =====================================================================================
   PROPERTY GET PreferredCardID <5> ( _                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCardID
   ' =====================================================================================
   PROPERTY GET LocationName <6> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ppLocationName
   ' =====================================================================================
   PROPERTY GET CityCode <7> ( _                        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *ppCode
   ' =====================================================================================
   PROPERTY GET LocalAccessCode <8> ( _                 ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *ppCode
   ' =====================================================================================
   PROPERTY GET LongDistanceAccessCode <9> ( _          ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *ppCode
   ' =====================================================================================
   PROPERTY GET TollPrefixList <10> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *ppTollList
   ' =====================================================================================
   PROPERTY GET CancelCallWaitingCode <11> ( _          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *ppCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLocationInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumLocation
' IID = {0C4D8F01-8DDB-11D1-A09E-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumLocation_INTERFACE_DEFINED)
    %IEnumLocation_INTERFACE_DEFINED = 1

INTERFACE IEnumLocation $IID_IEnumLocation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITLocationInfo _               ' __out ITLocationInfo **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumLocation _                    ' __retval_out IEnumLocation **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumLocation_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallingCard
' IID = {0C4D8F00-8DDB-11D1-A09E-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallingCard_INTERFACE_DEFINED)
    %ITCallingCard_INTERFACE_DEFINED = 1

INTERFACE ITCallingCard $IID_ITCallingCard

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PermanentCardID <1> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCardID
   ' =====================================================================================
   PROPERTY GET NumberOfDigits <2> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plDigits
   ' =====================================================================================
   PROPERTY GET Options <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plOptions
   ' =====================================================================================
   PROPERTY GET CardName <4> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ppCardName
   ' =====================================================================================
   PROPERTY GET SameAreaDialingRule <5> ( _             ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *ppRule
   ' =====================================================================================
   PROPERTY GET LongDistanceDialingRule <6> ( _         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ppRule
   ' =====================================================================================
   PROPERTY GET InternationalDialingRule <7> ( _        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *ppRule
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallingCard_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCallingCard
' IID = {0C4D8F02-8DDB-11D1-A09E-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumCallingCard_INTERFACE_DEFINED)
    %IEnumCallingCard_INTERFACE_DEFINED = 1

INTERFACE IEnumCallingCard $IID_IEnumCallingCard

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITCallingCard _                ' __out ITCallingCard **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumCallingCard _                 ' __retval_out IEnumCallingCard **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCallingCard_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITCallNotificationEvent
' IID = {895801DF-3DD6-11D1-8F30-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITCallNotificationEvent_INTERFACE_DEFINED)
    %ITCallNotificationEvent_INTERFACE_DEFINED = 1

INTERFACE ITCallNotificationEvent $IID_ITCallNotificationEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Call <1> ( _                            ' VTable offset = 28
   ) AS ITCallInfo                                      ' __retval_out ITCallInfo **ppCall
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CALL_NOTIFICATION_EVENT *pCallNotificationEvent
   ' =====================================================================================
   PROPERTY GET CallbackInstance <3> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCallbackInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallNotificationEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDispatchMapper
' IID = {E9225295-C759-11D1-A02B-00C04FB6809F}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDispatchMapper_INTERFACE_DEFINED)
    %ITDispatchMapper_INTERFACE_DEFINED = 1

INTERFACE ITDispatchMapper $IID_ITDispatchMapper

   INHERIT IDispatch

   ' =====================================================================================
   METHOD QueryDispatchInterface <1> ( _                ' VTable offset = 28
     BYVAL pIID AS WSTRING _                            ' __in BSTR pIID
   , BYVAL pInterfaceToMap AS IDispatch _               ' __in IDispatch *pInterfaceToMap
   ) AS IDispatch                                       ' __retval_out IDispatch **ppReturnedInterface
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDispatchMapper_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITStreamControl
' IID = {EE3BD604-3868-11D2-A045-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITStreamControl_INTERFACE_DEFINED)
    %ITStreamControl_INTERFACE_DEFINED = 1

INTERFACE ITStreamControl $IID_ITStreamControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateStream <262145> ( _                     ' VTable offset = 28
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL td AS LONG _                                 ' __in TERMINAL_DIRECTION td
   ) AS ITStream                                        ' __retval_out ITStream **ppStream
   ' =====================================================================================
   METHOD RemoveStream <262146> ( _                     ' VTable offset = 32
     BYVAL pStream AS ITStream _                        ' __in ITStream *pStream
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateStreams <262147> ( _                 ' VTable offset = 36
     BYREF ppEnumStream AS IEnumStream _                ' __out IEnumStream **ppEnumStream
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Streams <262148> ( _                    ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITStreamControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITStream
' IID = {EE3BD605-3868-11D2-A045-00C04FB6809F}
' ITStream interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITStream_INTERFACE_DEFINED)
    %ITStream_INTERFACE_DEFINED = 1

INTERFACE ITStream $IID_ITStream

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MediaType <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================
   PROPERTY GET Direction <2> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out TERMINAL_DIRECTION *pTD
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   METHOD StartStream <4> ( _                           ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD PauseStream <5> ( _                           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD StopStream <6> ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectTerminal <7> ( _                        ' VTable offset = 52
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================
   METHOD UnselectTerminal <8> ( _                      ' VTable offset = 56
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateTerminals <9> ( _                    ' VTable offset = 60
     BYREF ppEnumTerminal AS IEnumTerminal _            ' __out IEnumTerminal **ppEnumTerminal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Terminals <10> ( _                      ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pTerminals
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumStream
' IID = {EE3BD606-3868-11D2-A045-00C04FB6809F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumStream_INTERFACE_DEFINED)
    %IEnumStream_INTERFACE_DEFINED = 1

INTERFACE IEnumStream $IID_IEnumStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITStream _                     ' __out ITStream **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumStream _                      ' __retval_out IEnumStream **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITSubStreamControl
' IID = {EE3BD607-3868-11D2-A045-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITSubStreamControl_INTERFACE_DEFINED)
    %ITSubStreamControl_INTERFACE_DEFINED = 1

INTERFACE ITSubStreamControl $IID_ITSubStreamControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateSubStream <1> ( _                       ' VTable offset = 28
   ) AS ITSubStream                                     ' __retval_out ITSubStream **ppSubStream
   ' =====================================================================================
   METHOD RemoveSubStream <2> ( _                       ' VTable offset = 32
     BYVAL pSubStream AS ITSubStream _                  ' __in ITSubStream *pSubStream
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateSubStreams <3> ( _                   ' VTable offset = 36
     BYREF ppEnumSubStream AS IEnumSubStream _          ' __out IEnumSubStream **ppEnumSubStream
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubStreams <4> ( _                      ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITSubStreamControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITSubStream
' IID = {EE3BD608-3868-11D2-A045-00C04FB6809F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITSubStream_INTERFACE_DEFINED)
    %ITSubStream_INTERFACE_DEFINED = 1

INTERFACE ITSubStream $IID_ITSubStream

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StartSubStream <1> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD PauseSubStream <2> ( _                        ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD StopSubStream <3> ( _                         ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectTerminal <4> ( _                        ' VTable offset = 40
     BYVAL pTerminal AS IDispatch _                     ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================
   METHOD UnselectTerminal <5> ( _                      ' VTable offset = 44
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateTerminals <6> ( _                    ' VTable offset = 48
     BYREF ppEnumTerminal AS IEnumTerminal _            ' __out IEnumTerminal **ppEnumTerminal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Terminals <7> ( _                       ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pTerminals
   ' =====================================================================================
   PROPERTY GET Stream <8> ( _                          ' VTable offset = 56
   ) AS ITStream                                        ' __retval_out ITStream **ppITStream
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITSubStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumSubStream
' IID = {EE3BD609-3868-11D2-A045-00C04FB6809F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSubStream_INTERFACE_DEFINED)
    %IEnumSubStream_INTERFACE_DEFINED = 1

INTERFACE IEnumSubStream $IID_IEnumSubStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITSubStream _                  ' __out ITSubStream **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumSubStream _                   ' __retval_out IEnumSubStream **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSubStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITLegacyWaveSupport
' IID = {207823EA-E252-11D2-B77E-0080C7135381}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITLegacyWaveSupport_INTERFACE_DEFINED)
    %ITLegacyWaveSupport_INTERFACE_DEFINED = 1

INTERFACE ITLegacyWaveSupport $IID_ITLegacyWaveSupport

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsFullDuplex <1610743808> ( _                 ' VTable offset = 28
     BYREF pSupport AS LONG _                           ' __out FULLDUPLEX_SUPPORT *pSupport
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITLegacyWaveSupport_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITBasicCallControl2
' IID = {161A4A56-1E99-4B3F-A46A-168F38A5EE4C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ITBasicCallControl
' ########################################################################################

#IF NOT %DEF(%ITBasicCallControl2_INTERFACE_DEFINED)
    %ITBasicCallControl2_INTERFACE_DEFINED = 1

INTERFACE ITBasicCallControl2 $IID_ITBasicCallControl2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITBasicCallControl Methods
   ' =====================================================================================
   METHOD Connect <131075> ( _                          ' VTable offset = 28
     BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD Answer <131076> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <131077> ( _                       ' VTable offset = 36
     BYVAL code AS LONG _                               ' __in DISCONNECT_CODE code
   )                                                    ' void
   ' =====================================================================================
   METHOD Hold <131078> ( _                             ' VTable offset = 40
     BYVAL fHold AS INTEGER _                           ' __in VARIANT_BOOL fHold
   )                                                    ' void
   ' =====================================================================================
   METHOD HandoffDirect <131079> ( _                    ' VTable offset = 44
     BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   )                                                    ' void
   ' =====================================================================================
   METHOD HandoffIndirect <131080> ( _                  ' VTable offset = 48
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Conference <131081> ( _                       ' VTable offset = 52
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   , BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD Transfer <131082> ( _                         ' VTable offset = 56
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   , BYVAL fSync AS INTEGER _                           ' __in VARIANT_BOOL fSync
   )                                                    ' void
   ' =====================================================================================
   METHOD BlindTransfer <131083> ( _                    ' VTable offset = 60
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD SwapHold <131084> ( _                         ' VTable offset = 64
     BYVAL pCall AS ITBasicCallControl _                ' __in ITBasicCallControl *pCall
   )                                                    ' void
   ' =====================================================================================
   METHOD ParkDirect <131085> ( _                       ' VTable offset = 68
     BYVAL pParkAddress AS WSTRING _                    ' __in BSTR pParkAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD ParkIndirect <131086> ( _                     ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *ppNonDirAddress
   ' =====================================================================================
   METHOD Unpark <131087> ( _                           ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQOS <131088> ( _                           ' VTable offset = 80
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL ServiceLevel AS LONG _                       ' __in QOS_SERVICE_LEVEL ServiceLevel
   )                                                    ' void
   ' =====================================================================================
   METHOD Pickup <131091> ( _                           ' VTable offset = 84
     BYVAL pGroupID AS WSTRING _                        ' __in BSTR pGroupID
   )                                                    ' void
   ' =====================================================================================
   METHOD Dial <131092> ( _                             ' VTable offset = 88
     BYVAL pDestAddress AS WSTRING _                    ' __in BSTR pDestAddress
   )                                                    ' void
   ' =====================================================================================
   METHOD Finish <131093> ( _                           ' VTable offset = 92
     BYVAL finishMode AS LONG _                         ' __in FINISH_MODE finishMode
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromConference <131094> ( _             ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITBasicCallControl2 Methods
   ' =====================================================================================
   METHOD RequestTerminal <131095> ( _                  ' VTable offset = 100
     BYVAL bstrTerminalClassGUID AS WSTRING _           ' __in BSTR bstrTerminalClassGUID
   , BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   ) AS ITTerminal                                      ' __retval_out ITTerminal **ppTerminal
   ' =====================================================================================
   METHOD SelectTerminalOnCall <131096> ( _             ' VTable offset = 104
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================
   METHOD UnselectTerminalOnCall <131097> ( _           ' VTable offset = 108
     BYVAL pTerminal AS ITTerminal _                    ' __in ITTerminal *pTerminal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITBasicCallControl2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITScriptableAudioFormat
' IID = {B87658BD-3C59-4F64-BE74-AEDE3E86A81E}
' TAPI 3.0 ITScriptableAudioFormat Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITScriptableAudioFormat_INTERFACE_DEFINED)
    %ITScriptableAudioFormat_INTERFACE_DEFINED = 1

INTERFACE ITScriptableAudioFormat $IID_ITScriptableAudioFormat

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Channels <1> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Channels <1> ( _                        ' VTable offset = 32
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SamplesPerSec <2> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SamplesPerSec <2> ( _                   ' VTable offset = 40
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvgBytesPerSec <3> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET AvgBytesPerSec <3> ( _                  ' VTable offset = 48
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockAlign <4> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET BlockAlign <4> ( _                      ' VTable offset = 56
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BitsPerSample <5> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET BitsPerSample <5> ( _                   ' VTable offset = 64
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatTag <6> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET FormatTag <6> ( _                       ' VTable offset = 72
     BYVAL nNewVal AS LONG _                            ' __in const long nNewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITScriptableAudioFormat_INTERFACE_DEFINED__ */


'/****************************************
' * Terminal Classes
' ****************************************/

'// Video Windows - {F7438990-D6EB-11D0-82A6-00AA00B5CA1B}
$CLSID_VideoWindowTerm = GUID$("{F7438990-D6EB-11D0-82A6-00AA00B5CA1B}")

'// Video input (camera) {AAF578EC-DC70-11D0-8ED3-00C04FB6809F}
$CLSID_VideoInputTerminal = GUID$("{AAF578EC-DC70-11D0-8ED3-00C04FB6809F}")

'// Handset device {AAF578EB-DC70-11D0-8ED3-00C04FB6809F}
$CLSID_HandsetTerminal = GUID$("{AAF578EB-DC70-11D0-8ED3-00C04FB6809F}")

'// Headset device {AAF578ED-DC70-11D0-8ED3-00C04FB6809F}
$CLSID_HeadsetTerminal = GUID$("{AAF578ED-DC70-11D0-8ED3-00C04FB6809F}")

'// Speakerphone device {AAF578EE-DC70-11D0-8ED3-00C04FB6809F}
$CLSID_SpeakerphoneTerminal = GUID$("{AAF578EE-DC70-11D0-8ED3-00C04FB6809F}")

'// Microphone (sound card) {AAF578EF-DC70-11d0-8ED3-00C04FB6809F}
$CLSID_MicrophoneTerminal = GUID$("{AAF578EF-DC70-11d0-8ED3-00C04FB6809F}")

'// Speakers (sound card) {AAF578F0-DC70-11D0-8ED3-00C04FB6809F}
$CLSID_SpeakersTerminal = GUID$("{AAF578F0-DC70-11D0-8ED3-00C04FB6809F}")

'// Media stream terminal {E2F7AEF7-4971-11D1-A671-006097C9A2E8}
$CLSID_MediaStreamTerminal = GUID$("{E2F7AEF7-4971-11D1-A671-006097C9A2E8}")

'// File Recording terminal {521F3D06-C3D0-4511-8617-86B9A783DA77}
$CLSID_FileRecordingTerminal = GUID$("{521F3D06-C3D0-4511-8617-86B9A783DA77}")

'// File Recording Track {BF14A2E4-E88B-4EF5-9740-5AC5D022F8C9}
$CLSID_FileRecordingTrack = GUID$("{BF14A2E4-E88B-4EF5-9740-5AC5D022F8C9}")

'// File Playback Terminal {0CB9914C-79CD-47DC-ADB0-327F47CEFB20}
$CLSID_FilePlaybackTerminal = GUID$("{0CB9914C-79CD-47DC-ADB0-327F47CEFB20}")

'// define the media modes
%TAPIMEDIATYPE_AUDIO                     = &H8
%TAPIMEDIATYPE_VIDEO                     = &H8000
%TAPIMEDIATYPE_DATAMODEM                 = &H10
%TAPIMEDIATYPE_G3FAX                     = &H20
%TAPIMEDIATYPE_MULTITRACK                = &H10000

'// {831CE2D6-83B5-11D1-BB5C-00C04FB6809F}
$TAPIPROTOCOL_PSTN = GUID$("{831CE2D6-83B5-11D1-BB5C-00C04FB6809F}")

'// {831CE2D7-83B5-11D1-BB5C-00C04FB6809F}
$TAPIPROTOCOL_H323 = GUID$("{831CE2D7-83B5-11D1-BB5C-00C04FB6809F}")

'// {831CE2D8-83B5-11D1-BB5C-00C04FB6809F}
$TAPIPROTOCOL_Multicast = GUID$("{831CE2D8-83B5-11D1-BB5C-00C04FB6809F}")

%TapiConstants_MODULE_DEFINED = 1
