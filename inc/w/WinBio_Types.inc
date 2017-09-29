' ########################################################################################
' Microsoft Windows
' File: WinBio_Types.inc
' Contents: Contains custom WIA definitions for the WSD scan class driver
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#ifndef _WINBIO_TYPES_H_712486DB_3EF5_41da_937A_55DCB7B66A53_
'#define _WINBIO_TYPES_H_712486DB_3EF5_41da_937A_55DCB7B66A53_

#INCLUDE THIS ONCE
%WINBIO_TYPES_INC = 1

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'///////////////////////////////////////////////////////////////////////////////
'//
'// Types used throughout WinBio
'//
'///////////////////////////////////////////////////////////////////////////////

'typedef ULONG WINBIO_UNIT_ID, *PWINBIO_UNIT_ID;
'typedef ULONG WINBIO_SESSION_HANDLE, *PWINBIO_SESSION_HANDLE;

'//
'// A GUID
'//
'typedef GUID WINBIO_UUID, *PWINBIO_UUID;

'//
'// Represents a NULL-terminated Unicode character
'// string inside a fixed-length buffer.
'//
%WINBIO_MAX_STRING_LEN = 256
'typedef WCHAR WINBIO_STRING[WINBIO_MAX_STRING_LEN];
'typedef WINBIO_STRING *PWINBIO_STRING;

'//
'// Version
'//
' // Size = 8 bytes
TYPE WINBIO_VERSION DWORD
   MajorVersion AS DWORD   ' DWORD
   MinorVersion AS DWORD   ' DWORD
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'//
'// Enumeration for template identity types...
'//

'typedef ULONG WINBIO_IDENTITY_TYPE, *PWINBIO_IDENTITY_TYPE;

%WINBIO_ID_TYPE_NULL     = 0???   ' ((WINBIO_IDENTITY_TYPE)0)  // The Identity structure is empty.
%WINBIO_ID_TYPE_WILDCARD = 1???   ' ((WINBIO_IDENTITY_TYPE)1)  // The Identity matches "all identities"
%WINBIO_ID_TYPE_GUID     = 2???   ' ((WINBIO_IDENTITY_TYPE)2)  // A GUID identifies the template.
%WINBIO_ID_TYPE_SID      = 3???   ' ((WINBIO_IDENTITY_TYPE)3)  // An account SID identifies the template.

'//
'// Structure that contains the identity value associated
'// with a biometric template.
'//
'//#ifndef SECURITY_MAX_SID_SIZE
'//#define SECURITY_MAX_SID_SIZE 68
'//#endif
'typedef struct _WINBIO_IDENTITY {
'    WINBIO_IDENTITY_TYPE Type;
'    union {
'        ULONG Null;
'        ULONG Wildcard;
'        GUID TemplateGuid;
'        struct {
'            ULONG Size;
'            UCHAR Data[SECURITY_MAX_SID_SIZE];
'        } AccountSid;
'    } Value;
'} WINBIO_IDENTITY;

' // Size = 72 bytes
TYPE WINBIO_IDENTITY_ACCOUNTSID DWORD
   Size AS DWORD         ' ULONG
   Data AS STRING * 68   ' UCHAR[SECURITY_MAX_SID_SIZE]
END TYPE

' // Size = 72 bytes
UNION WINBIO_IDENTITY_VALUE DWORD
   Null         AS DWORD   ' ULONG
   Wildcard     AS DWORD   ' ULONG
   TemplateGuid AS GUID    ' GUID
   WINBIO_IDENTITY_ACCOUNTSID
END UNION

' // Size = 76 bytes
TYPE WINBIO_IDENTITY DWORD
   Type AS DWORD   ' WINBIO_IDENTITY_TYPE
   WINBIO_IDENTITY_VALUE
END TYPE

%WINBIO_IDENTITY_WILDCARD = &H25066282???   ' ((ULONG)0x25066282)

'///////////////////////////////////////////////////////////////////////////////
'//
'// Things related to get/set property operations
'//
'typedef ULONG32 WINBIO_PROPERTY_TYPE, *PWINBIO_PROPERTY_TYPE;

%WINBIO_PROPERTY_TYPE_SESSION  = 1???   ' ((WINBIO_PROPERTY_TYPE)1)
%WINBIO_PROPERTY_TYPE_UNIT     = 2???   ' ((WINBIO_PROPERTY_TYPE)2)
%WINBIO_PROPERTY_TYPE_TEMPLATE = 3???   ' ((WINBIO_PROPERTY_TYPE)3)


'typedef ULONG32 WINBIO_PROPERTY_ID, *PWINBIO_PROPERTY_ID;

%WINBIO_PROPERTY_SAMPLE_HINT   = 1???   ' ((WINBIO_PROPERTY_ID)1)  //(read-only)

'///////////////////////////////////////////////////////////////////////////////
'//
'// Bitmask describing the supported set of biometric types (factors).
'//
'typedef ULONG32 WINBIO_BIOMETRIC_TYPE, *PWINBIO_BIOMETRIC_TYPE;

%WINBIO_STANDARD_TYPE_MASK          = &H00FFFFFF???   ' ((WINBIO_BIOMETRIC_TYPE)0x00FFFFFF)

%WINBIO_NO_TYPE_AVAILABLE           = &H00000000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000000)
'//
'// Standard biometric types (from NISTIR 6529-A)
'//
%WINBIO_TYPE_MULTIPLE               = &H00000001???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000001)
%WINBIO_TYPE_FACIAL_FEATURES        = &H00000002???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000002)
%WINBIO_TYPE_VOICE                  = &H00000004???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000004)
%WINBIO_TYPE_FINGERPRINT            = &H00000008???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000008)
%WINBIO_TYPE_IRIS                   = &H00000010???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000010)
%WINBIO_TYPE_RETINA                 = &H00000020???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000020)
%WINBIO_TYPE_HAND_GEOMETRY          = &H00000040???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000040)
%WINBIO_TYPE_SIGNATURE_DYNAMICS     = &H00000080???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000080)
%WINBIO_TYPE_KEYSTROKE_DYNAMICS     = &H00000100???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000100)
%WINBIO_TYPE_LIP_MOVEMENT           = &H00000200???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000200)
%WINBIO_TYPE_THERMAL_FACE_IMAGE     = &H00000400???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000400)
%WINBIO_TYPE_THERMAL_HAND_IMAGE     = &H00000800???   ' ((WINBIO_BIOMETRIC_TYPE)0x00000800)
%WINBIO_TYPE_GAIT                   = &H00001000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00001000)
%WINBIO_TYPE_SCENT                  = &H00002000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00002000)
%WINBIO_TYPE_DNA                    = &H00004000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00004000)
%WINBIO_TYPE_EAR_SHAPE              = &H00008000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00008000)
%WINBIO_TYPE_FINGER_GEOMETRY        = &H00010000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00010000)
%WINBIO_TYPE_PALM_PRINT             = &H00020000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00020000)
%WINBIO_TYPE_VEIN_PATTERN           = &H00040000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00040000)
%WINBIO_TYPE_FOOT_PRINT             = &H00080000???   ' ((WINBIO_BIOMETRIC_TYPE)0x00080000)
'//
'// WinBio extended types
'//
%WINBIO_TYPE_OTHER                  = &H40000000???   ' ((WINBIO_BIOMETRIC_TYPE)0x40000000)
%WINBIO_TYPE_PASSWORD               = &H80000000???   ' ((WINBIO_BIOMETRIC_TYPE)0x80000000)

%WINBIO_TYPE_ANY                    = %WINBIO_STANDARD_TYPE_MASK OR %WINBIO_TYPE_OTHER OR %WINBIO_TYPE_PASSWORD

'//
'// WinBio sensor sub-types.  These are defined per Biometric type, and are
'// defined only for fingerprints in this version.
'//
'typedef ULONG WINBIO_BIOMETRIC_SENSOR_SUBTYPE, *PWINBIO_BIOMETRIC_SENSOR_SUBTYPE;

%WINBIO_SENSOR_SUBTYPE_UNKNOWN      = &H00000000???   ' ((WINBIO_BIOMETRIC_SENSOR_SUBTYPE)0x00000000)

%WINBIO_FP_SENSOR_SUBTYPE_SWIPE     = &H00000001???   ' ((WINBIO_BIOMETRIC_SENSOR_SUBTYPE)0x00000001)
%WINBIO_FP_SENSOR_SUBTYPE_TOUCH     = &H00000002???   ' ((WINBIO_BIOMETRIC_SENSOR_SUBTYPE)0x00000002)

'//
'// Bitmask of sensor capabilities
'//
'typedef ULONG WINBIO_CAPABILITIES, *PWINBIO_CAPABILITIES;

%WINBIO_CAPABILITY_SENSOR       = &H00000001???   ' ((WINBIO_CAPABILITIES)0x00000001)
%WINBIO_CAPABILITY_MATCHING     = &H00000002???   ' ((WINBIO_CAPABILITIES)0x00000002)
%WINBIO_CAPABILITY_DATABASE     = &H00000004???   ' ((WINBIO_CAPABILITIES)0x00000004)
%WINBIO_CAPABILITY_PROCESSING   = &H00000008???   ' ((WINBIO_CAPABILITIES)0x00000008)
%WINBIO_CAPABILITY_ENCRYPTION   = &H00000010???   ' ((WINBIO_CAPABILITIES)0x00000010)
%WINBIO_CAPABILITY_NAVIGATION   = &H00000020???   ' ((WINBIO_CAPABILITIES)0x00000020)
%WINBIO_CAPABILITY_INDICATOR    = &H00000040???   ' ((WINBIO_CAPABILITIES)0x00000040)

'//
'// Values used to set the indicator on or off
'//
'// By default, sensors will not have a light on.
'// Applications can use these values to enable
'// or disable indicator lights on the sensor.
'// WINBIO_SENSOR_STATUS will provide more detail
'// about the status of the light when it is "on."
'//
'typedef DWORD WINBIO_INDICATOR_STATUS, *PWINBIO_INDICATOR_STATUS;

%WINBIO_INDICATOR_ON    = 1???   ' ((WINBIO_INDICATOR_STATUS)1)
%WINBIO_INDICATOR_OFF   = 2???   ' ((WINBIO_INDICATOR_STATUS)2)

'///////////////////////////////////////////////////////////////////////////////
'//
'// Sensor operating modes
'//
'typedef ULONG WINBIO_SENSOR_MODE, *PWINBIO_SENSOR_MODE;

%WINBIO_SENSOR_UNKNOWN_MODE     = 0???   ' ((WINBIO_SENSOR_MODE)0)
%WINBIO_SENSOR_BASIC_MODE       = 1???   ' ((WINBIO_SENSOR_MODE)1)
%WINBIO_SENSOR_ADVANCED_MODE    = 2???   ' ((WINBIO_SENSOR_MODE)2)
%WINBIO_SENSOR_NAVIGATION_MODE  = 3???   ' ((WINBIO_SENSOR_MODE)3)
%WINBIO_SENSOR_SLEEP_MODE       = 4???   ' ((WINBIO_SENSOR_MODE)4)

'///////////////////////////////////////////////////////////////////////////////
'//
'// Factor-specific value giving additional information about
'// a biometric measurement (e.g., *which* finger a fingerprint
'// sample was taken from).
'//
'typedef UCHAR WINBIO_BIOMETRIC_SUBTYPE, *PWINBIO_BIOMETRIC_SUBTYPE;

%WINBIO_SUBTYPE_NO_INFORMATION      = &H00?   ' ((WINBIO_BIOMETRIC_SUBTYPE)0x00)
%WINBIO_SUBTYPE_ANY                 = &HFF?   ' ((WINBIO_BIOMETRIC_SUBTYPE)0xFF)
'//
'// If the biometric type is WINBIO_TYPE_FINGERPRINT, WinBio uses
'// 'WINBIO_ANSI_381_POS_xyz' constants to represent fingerprint sub-type
'// information. (These are defined below in the WINBIO_BDB_ANSI_381_RECORD.)
'//

'///////////////////////////////////////////////////////////////////////////////
'//
'// Factor-specific value that describes the reason a
'// biometric sampling operation failed.
'//
'typedef ULONG WINBIO_REJECT_DETAIL, *PWINBIO_REJECT_DETAIL;

'//
'// Failure detail values for WINBIO_TYPE_FINGERPRINT
'//
%WINBIO_FP_TOO_HIGH         = 1???    ' ((WINBIO_REJECT_DETAIL)1)
%WINBIO_FP_TOO_LOW          = 2???    ' ((WINBIO_REJECT_DETAIL)2)
%WINBIO_FP_TOO_LEFT         = 3???    ' ((WINBIO_REJECT_DETAIL)3)
%WINBIO_FP_TOO_RIGHT        = 4???    ' ((WINBIO_REJECT_DETAIL)4)
%WINBIO_FP_TOO_FAST         = 5???    ' ((WINBIO_REJECT_DETAIL)5)
%WINBIO_FP_TOO_SLOW         = 6???    ' ((WINBIO_REJECT_DETAIL)6)
%WINBIO_FP_POOR_QUALITY     = 7???    ' ((WINBIO_REJECT_DETAIL)7)
%WINBIO_FP_TOO_SKEWED       = 8???    ' ((WINBIO_REJECT_DETAIL)8)
%WINBIO_FP_TOO_SHORT        = 9???    ' ((WINBIO_REJECT_DETAIL)9)
%WINBIO_FP_MERGE_FAILURE    = 10???   ' ((WINBIO_REJECT_DETAIL)10)


'///////////////////////////////////////////////////////////////////////////////
'//
'// Biometric Information Record (BIR)
'//
'///////////////////////////////////////////////////////////////////////////////
'//
'//      +---------------------------------------+
'// 1.   |   WINBIO_BIR                          |
'//      +---------------------------------------+
'// 2.   |   WINBIO_BIR_HEADER                   |
'//      +---------------------------------------+
'// 3.   |   Standard Data Block (optional)      |
'//      |                                       |
'//      |       WINBIO_BDB_ANSI_381_HEADER      |
'//      |       [0] WINBIO_BDB_ANSI_381_RECORD  |
'//      |           :                           |
'//      |       [N] WINBIO_BDB_ANSI_381_RECORD  |
'//      +---------------------------------------+
'// 4.   |   Vendor Data Block (optional)        |
'//      +---------------------------------------+
'// 5.   |   Signature Block (optional)          |
'//      +---------------------------------------+
'//
'// NOTES:
'//      - The format of the Standard Data Block is determined
'//      by the 'BiometricDataFormat' field of WINBIO_BIR_HEADER.
'//
'//      - Currently, the only supported format for the Standard
'//      Data Block is ANSI 381 fingerprint image data. Data in
'//      any other form must go into the Vendor Data Block instead.
'//
'//      - It's vital that BIR structures and sub-structures be aligned
'//      on 8-byte boundaries. This means both C++ and MIDL compilation
'//      with at least /Zp8 alignment. This also applies to BIRs that
'//      are allocated dynamically from the heap.
'//
%WINBIO_BIR_ALIGN_SIZE = 8
'//
'// Also define legacy typo to be synonymous
'//
%WINBIO_BIR_ALGIN_SIZE = %WINBIO_BIR_ALIGN_SIZE

'//
'// The following gives the location and size of a block
'// in a BIR. The offset is measured from the beginning of
'// the WINBIO_BIR structure.
'//
' // Size = 8 bytes
TYPE WINBIO_BIR_DATA DWORD
   Size   AS DWORD   ' ULONG
   Offset AS DWORD   ' ULONG
END TYPE

'//
'// Top-level structure contains offset/size
'// information needed to find other items.
'//
' // Size = 32 bytes
TYPE WINBIO_BIR DWORD
   HeaderBlock       AS WINBIO_BIR_DATA
   StandardDataBlock AS WINBIO_BIR_DATA
   VendorDataBlock   AS WINBIO_BIR_DATA
   SignatureBlock    AS WINBIO_BIR_DATA
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'//
'// Elements used in a BIR header
'//
'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'ValidFields' flags...
'//
%WINBIO_BIR_FIELD_SUBHEAD_COUNT          = &H0001??   ' ((USHORT)0x0001)
%WINBIO_BIR_FIELD_PRODUCT_ID             = &H0002??   ' ((USHORT)0x0002)
%WINBIO_BIR_FIELD_PATRON_ID              = &H0004??   ' ((USHORT)0x0004)
%WINBIO_BIR_FIELD_INDEX                  = &H0008??   ' ((USHORT)0x0008)

%WINBIO_BIR_FIELD_CREATION_DATE          = &H0010??   ' ((USHORT)0x0010)
%WINBIO_BIR_FIELD_VALIDITY_PERIOD        = &H0020??   ' ((USHORT)0x0020)
%WINBIO_BIR_FIELD_BIOMETRIC_TYPE         = &H0040??   ' ((USHORT)0x0040)
%WINBIO_BIR_FIELD_BIOMETRIC_SUBTYPE      = &H0080??   ' ((USHORT)0x0080)

%WINBIO_BIR_FIELD_CBEFF_HEADER_VERSION   = &H0100??   ' ((USHORT)0x0100)
%WINBIO_BIR_FIELD_PATRON_HEADER_VERSION  = &H0200??   ' ((USHORT)0x0200)
%WINBIO_BIR_FIELD_BIOMETRIC_PURPOSE      = &H0400??   ' ((USHORT)0x0400)
%WINBIO_BIR_FIELD_BIOMETRIC_CONDITION    = &H0800??   ' ((USHORT)0x0800)

%WINBIO_BIR_FIELD_QUALITY                = &H1000??   ' ((USHORT)0x1000)
%WINBIO_BIR_FIELD_CREATOR                = &H2000??   ' ((USHORT)0x2000)
%WINBIO_BIR_FIELD_CHALLENGE              = &H4000??   ' ((USHORT)0x4000)
%WINBIO_BIR_FIELD_PAYLOAD                = &H8000??   ' ((USHORT)0x8000)

'//
'// The following collection of optional fields will NEVER be
'// part of a WinBio BIR. If any of these bits are asserted,
'// the BIR is malformed.
'//
%WINBIO_BIR_FIELD_NEVER_VALID  = %WINBIO_BIR_FIELD_SUBHEAD_COUNT OR _
                                 %WINBIO_BIR_FIELD_PATRON_ID OR _
                                 %WINBIO_BIR_FIELD_INDEX OR _
                                 %WINBIO_BIR_FIELD_CHALLENGE OR _
                                 %WINBIO_BIR_FIELD_PAYLOAD

'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'HeaderVersion' and 'PatronHeaderVersion' fields:
'//
'// Versions are represented as 8-bit values of the
'// form: 0xNM, where 'N' is the major version and 'M'
'// is the minor version.
'//
'typedef UCHAR WINBIO_BIR_VERSION, *PWINBIO_BIR_VERSION;

%WINBIO_CBEFF_HEADER_VERSION   = &H11?   ' ((WINBIO_BIR_VERSION)0x11)
%WINBIO_PATRON_HEADER_VERSION  = &H11?   ' ((WINBIO_BIR_VERSION)0x11)

'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'DataFlags' field:
'//      * Security and integrity-checking options
'//          PRIVACY     - BDB is encrypted
'//          INTEGRITY   - BDB is signed or MAC'ed
'//          SIGNED      - 1 -> BDB is signed; 0 -> BDB is MAC'ed
'//      * Processing level of the data
'//
'typedef UCHAR WINBIO_BIR_DATA_FLAGS, *PWINBIO_BIR_DATA_FLAGS;

%WINBIO_DATA_FLAG_PRIVACY               = &H02?   ' ((UCHAR)0x02)
%WINBIO_DATA_FLAG_INTEGRITY             = &H01?   ' ((UCHAR)0x01)
%WINBIO_DATA_FLAG_SIGNED                = &H04?   ' ((UCHAR)0x04)

%WINBIO_DATA_FLAG_RAW                   = &H20?   ' ((UCHAR)0x20)
%WINBIO_DATA_FLAG_INTERMEDIATE          = &H40?   ' ((UCHAR)0x40)
%WINBIO_DATA_FLAG_PROCESSED             = &H80?   ' ((UCHAR)0x80)

%WINBIO_DATA_FLAG_OPTION_MASK_PRESENT   = &H08?   ' ((UCHAR)0x08)   // Always '1'.

'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'Purpose' field:
'//
'// A value defining the purpose for which the BIR
'//
'//  - is intended, when used as input to a WinBio function
'//
'//  - is suitable, when used as output from a WinBio function
'//  or within a BIR header.
'//
'// NOTE:
'//  In a WINBIO BIR, the 'Purpose' field is defined as a set of flag bits
'//  rather than an enumerated type (as specified in NISTIR 6529-A). Transferring
'//  a WINBIO BIR to another environment (e.g., BioAPI) will require conversion.
'//
'//  The suggested way to handle this conversion is to generate a set of nested
'//  BIRs for any WINBIO BIRs that have multiple 'Purpose' bits set.
'//
'typedef UCHAR WINBIO_BIR_PURPOSE, *PWINBIO_BIR_PURPOSE;

%WINBIO_NO_PURPOSE_AVAILABLE                    = &H00?   ' ((WINBIO_BIR_PURPOSE)0x00)
%WINBIO_PURPOSE_VERIFY                          = &H01?   ' ((WINBIO_BIR_PURPOSE)0x01)
%WINBIO_PURPOSE_IDENTIFY                        = &H02?   ' ((WINBIO_BIR_PURPOSE)0x02)
%WINBIO_PURPOSE_ENROLL                          = &H04?   ' ((WINBIO_BIR_PURPOSE)0x04)
%WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION         = &H08?   ' ((WINBIO_BIR_PURPOSE)0x08)
%WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION       = &H10?   ' ((WINBIO_BIR_PURPOSE)0x10)
%WINBIO_PURPOSE_AUDIT                           = &H80?   ' ((WINBIO_BIR_PURPOSE)0x80)

'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'DataQuality' field:
'//
'// FIndicates the relative quality of the biometric
'// data in the BIR.
'//
'// Quality measurements are represented as signed
'// integers in the range 0-100, except:
'//
'//      -1  Quality measurements are supported by the
'//          BIR creator, but no value is set in the BIR.
'//
'//      -2  Quality measurements are not supported
'//          by the BIR creator.
'//
'typedef CHAR WINBIO_BIR_QUALITY, *PWINBIO_BIR_QUALITY;

%WINBIO_DATA_QUALITY_NOT_SET        = -1   ' ((WINBIO_BIR_QUALITY)-1)
%WINBIO_DATA_QUALITY_NOT_SUPPORTED  = -2   ' ((WINBIO_BIR_QUALITY)-2)

'///////////////////////////////////////////////////////////////////////////////
'//
'// BIR 'BiometricDataFormat' and 'ProductId' fields:
'//
'// Identifies a registered data format as a pair consisting of
'// an IBIA-assigned owner value plus an owner-assigned format-type
'// value.
'//
' // Size = 4 bytes
TYPE WINBIO_REGISTERED_FORMAT WORD
   Owner AS WORD   ' USHORT
   Type  AS WORD   ' USHORT
END TYPE

%WINBIO_NO_FORMAT_OWNER_AVAILABLE   = 0??   ' ((USHORT)0)
%WINBIO_NO_FORMAT_TYPE_AVAILABLE    = 0??   ' ((USHORT)0)

'///////////////////////////////////////////////////////////////////////////////
'//
'// NISTIR 6529-A -- Common Biometric Exchange Formats Framework (CBEFF)
'// April 5, 2004
'//
'// CBEFF Patron Format A: Standard Biometric Header Block
'//
'// NOTE:
'//      This structure is COMPATIBLE with CBEFF Patron Format A in that
'//      it can be transformed to/from a fully-conformant Format A record.
'//      The following fields are NOT part of this structure:
'//          - Subheader -- WinBio doesn't support nested CBEFF structures
'//          - Patron format owner/type -- used only for nested CBEFF structures
'//          - Index
'//          - Creator
'//          - Challenge/response
'//          - Payload
'//
'///////////////////////////////////////////////////////////////////////////////
'typedef struct _WINBIO_BIR_HEADER {
'    //
'    // Mask indicating which fields are valid
'    //
'    // Annex A -- Note (1) to Table A.1
'    //
'    USHORT ValidFields;

'    //
'    // CBEFF Header version
'    //
'    // SECTION 5.2.1.3
'    //
'    WINBIO_BIR_VERSION HeaderVersion;   // = WINBIO_CBEFF_HEADER_VERSION

'    //
'    // Patron header version
'    //
'    // SECTION 5.2.1.4
'    //
'    WINBIO_BIR_VERSION PatronHeaderVersion; // = WINBIO_PATRON_HEADER_VERSION

'    //
'    // 'DataFlags' is a combination of the 'Security
'    // Options' field and the 'Biometric Data Type'
'    // (RAW, INTERMEDIATE,PROCESSED) field.
'    //
'    // SECTION 5.2.1.1, 5.2.1.2, and 5.2.1.7
'    //
'    WINBIO_BIR_DATA_FLAGS DataFlags;

'    //
'    // Biometric type
'    //
'    // SECTION 5.2.1.5
'    //
'    WINBIO_BIOMETRIC_TYPE Type;

'    //
'    // Biometric subtype
'    //
'    // SECTION 5.2.1.6
'    //
'    WINBIO_BIOMETRIC_SUBTYPE Subtype;

'    //
'    // Intended use of the data
'    //
'    // SECTION 5.2.1.8
'    //
'    WINBIO_BIR_PURPOSE Purpose;

'    //
'    // Biometric data quality
'    //
'    // SECTION 5.2.1.9
'    //
'    WINBIO_BIR_QUALITY DataQuality;

'    //
'    // Creation date and time of this BIR (in UTC)
'    //
'    // SECTION 5.2.1.10
'    //
'    LARGE_INTEGER CreationDate;

'    //
'    // Validity period of this BIR (in UTC)
'    //
'    // SECTION 5.2.1.11
'    //
'    struct {
'        LARGE_INTEGER BeginDate;
'        LARGE_INTEGER EndDate;
'    } ValidityPeriod;

'    ///////////////////////////////////////////////////////////////////////////
'    //
'    // Data format of Standard Data Block.
'    //
'    // NOTE: If BIR doesn't contain 'StandardDataBlock'
'    // element, this is set to "no owner/type available".
'    //
'    WINBIO_REGISTERED_FORMAT BiometricDataFormat;

'    //
'    // Product identifier for the component that
'    // generated the 'StandardDataBlock' element.
'    //
'    // NOTE: If BIR doesn't contain 'StandardDataBlock'
'    // element, this is set to "no owner/type available".
'    //
'    WINBIO_REGISTERED_FORMAT ProductId;

'} WINBIO_BIR_HEADER;

' // Size = 16 bytes
TYPE WINBIO_BIR_HEADER_VALIDITYPERIOD QWORD
   BeginDate AS QUAD   ' LARGE_INTEGER
   EndDate   AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 48 bytes
TYPE WINBIO_BIR_HEADER QWORD FILL   ' Must be 8 byte aligned
   ValidFields         AS WORD    ' USHORT
   HeaderVersion       AS BYTE    ' WINBIO_BIR_VERSION // = WINBIO_CBEFF_HEADER_VERSION
   PatronHeaderVersion AS BYTE    ' WINBIO_BIR_VERSION // = WINBIO_PATRON_HEADER_VERSION
   DataFlags           AS BYTE    ' WINBIO_BIR_DATA_FLAGS
   Type                AS DWORD   ' WINBIO_BIOMETRIC_TYPE
   Subtype             AS BYTE    ' WINBIO_BIOMETRIC_SUBTYPE
   Purpose             AS BYTE    ' WINBIO_BIR_PURPOSE
   DataQuality         AS BYTE    ' WINBIO_BIR_QUALITY
   CreationDate        AS QUAD    ' LARGE_INTEGER
   WINBIO_BIR_HEADER_VALIDITYPERIOD
   BiometricDataFormat AS WINBIO_REGISTERED_FORMAT
   ProductId           AS WINBIO_REGISTERED_FORMAT
END TYPE


'///////////////////////////////////////////////////////////////////////////////
'//
'// ANSI INCITS 381-2004 -- Finger Image-Based Data Interchange Format
'//
'///////////////////////////////////////////////////////////////////////////////
'//
'// SECTION 7 -- Registered Format
'//
'// WINBIO_BIR_HEADER.BiometricDataFormat.Owner = WINBIO_ANSI_381_FORMAT_OWNER
'// WINBIO_BIR_HEADER.BiometricDataFormat.Type  = WINBIO_ANSI_381_FORMAT_TYPE
'//
%WINBIO_ANSI_381_FORMAT_OWNER   = &H001B??   ' ((USHORT)0x001B)    // INCITS Technical Committee M1
%WINBIO_ANSI_381_FORMAT_TYPE    = &H0401??   ' ((USHORT)0x0401)    // ANSI-381

'//
'// SECTION 7.1 -- General Record Header
'//
' // Size = 40 bytes
TYPE WINBIO_BDB_ANSI_381_HEADER QWORD FILL   ' Must be 8 byte aligned
   RecordLength              AS QUAD    ' ULONG64 // Only the low 6 bytes of this number are valid.
                                        '         // sizeof(WINBIO_BDB_ANSI_381_HEADER)
                                        '         // + sizeof( all WINBIO_BDB_ANSI_381_RECORD records)

   FormatIdentifier          AS DWORD   ' ULONG // Must be 0x46495200 (ASCII: 'F' 'I' 'R' 0x0)
   VersionNumber             AS DWORD   ' ULONG // Must be 0x30313000 (ASCII: '0' '1' '0' 0x0)

   ProductId                 AS WINBIO_REGISTERED_FORMAT

   CaptureDeviceId           AS WORD    ' USHORT
   ImageAcquisitionLevel     AS WORD    ' USHORT
   HorizontalScanResolution  AS WORD    ' USHORT
   VerticalScanResolution    AS WORD    ' USHORT
   HorizontalImageResolution AS WORD    ' USHORT
   VerticalImageResolution   AS WORD    ' USHORT

   ElementCount              AS BYTE    ' UCHAR // Number of finger/palm records in the block
   ScaleUnits                AS BYTE    ' UCHAR // cm or inch
   PixelDepth                AS BYTE    ' UCHAR // 1-16 bits per pixel (2-64K gray levels)
   ImageCompressionAlg       AS BYTE    ' UCHAR

   Reserved                  AS WORD    ' USHORT
   ' // 38 bytes (because of unused 2 bytes in ULONG64) vs. 36 bytes defined in ANSI INCITS spec
   alignment__               AS WORD    ' // To keep 8 byte alignment
END TYPE

'//
'// SECTION 7.1.6 Image acquistion level
'//
'// Table 1 -- Image acquistion setting levels
'//
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_10   = &10??   ' ((USHORT)10)
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_20   = &20??   ' ((USHORT)20)
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_30   = &30??   ' ((USHORT)30)
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_31   = &31??   ' ((USHORT)31)
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_40   = &40??   ' ((USHORT)40)
%WINBIO_ANSI_381_IMG_ACQ_LEVEL_41   = &41??   ' ((USHORT)41)

'//
'// SECTION 7.1.8 -- Scale units
'//
%WINBIO_ANSI_381_PIXELS_PER_INCH    = &H01?   ' ((UCHAR)0x01)
%WINBIO_ANSI_381_PIXELS_PER_CM      = &H02?   ' ((UCHAR)0x02)

'//
'// SECTION 7.1.14 -- Image compression algorithm
'//
'// Table 3 -- Compression algorithm codes
'//
%WINBIO_ANSI_381_IMG_UNCOMPRESSED           = 0?   ' ((UCHAR)0)
%WINBIO_ANSI_381_IMG_BIT_PACKED             = 1?   ' ((UCHAR)1)
%WINBIO_ANSI_381_IMG_COMPRESSED_WSQ         = 2?   ' ((UCHAR)2)
%WINBIO_ANSI_381_IMG_COMPRESSED_JPEG        = 3?   ' ((UCHAR)3)
%WINBIO_ANSI_381_IMG_COMPRESSED_JPEG2000    = 4?   ' ((UCHAR)4)
%WINBIO_ANSI_381_IMG_COMPRESSED_PNG         = 5?   ' ((UCHAR)5)

'//
'// SECTION 7.2 -- Finger Record Header
'//
' // Size = 16 bytes
TYPE WINBIO_BDB_ANSI_381_RECORD DWORD FILL
   BlockLength          AS DWORD   ' ULONG  // sizeof(WINBIO_BDB_ANSI_381_RECORD)
                                   '        // + sizeof(image data)
   HorizontalLineLength AS WORD    ' USHORT  // Number of pixels in a horizontal line
   VerticalLineLength   AS WORD    ' USHORT  // Number of horizontal lines in the image
   Position             AS BYTE    ' WINBIO_BIOMETRIC_SUBTYPE
   CountOfViews         AS BYTE    ' UCHAR // Must be set to one (1)
   ViewNumber           AS BYTE    ' UCHAR // Must be set to one (1)
   ImageQuality         AS BYTE    ' UCHAR // Reserved -- must be set to 254 (0xFE)
   ImpressionType       AS BYTE    ' UCHAR
   Reserved             AS BYTE    ' UCHAR // Must be set to zero
   ' // 14 bytes of header data
   alignment__          AS WORD    ' // To keep DWORD alignment
END TYPE

'//
'// Followed immediately by compressed/uncompressed image data.
'// (Image data must be < 43 * 10^8 bytes in length.)
'//

'//
'// SECTION 7.2.2 -- Finger position codes
'//
'// Table 5 -- Finger position codes, areas, and maximum dimensions
'//

%WINBIO_ANSI_381_POS_UNKNOWN            = 0?    ' ((WINBIO_BIOMETRIC_SUBTYPE)0)
%WINBIO_ANSI_381_POS_RH_THUMB           = 1?    ' ((WINBIO_BIOMETRIC_SUBTYPE)1)
%WINBIO_ANSI_381_POS_RH_INDEX_FINGER    = 2?    ' ((WINBIO_BIOMETRIC_SUBTYPE)2)
%WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER   = 3?    ' ((WINBIO_BIOMETRIC_SUBTYPE)3)
%WINBIO_ANSI_381_POS_RH_RING_FINGER     = 4?    ' ((WINBIO_BIOMETRIC_SUBTYPE)4)
%WINBIO_ANSI_381_POS_RH_LITTLE_FINGER   = 5?    ' ((WINBIO_BIOMETRIC_SUBTYPE)5)
%WINBIO_ANSI_381_POS_LH_THUMB           = 6?    ' ((WINBIO_BIOMETRIC_SUBTYPE)6)
%WINBIO_ANSI_381_POS_LH_INDEX_FINGER    = 7?    ' ((WINBIO_BIOMETRIC_SUBTYPE)7)
%WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER   = 8?    ' ((WINBIO_BIOMETRIC_SUBTYPE)8)
%WINBIO_ANSI_381_POS_LH_RING_FINGER     = 9?    ' ((WINBIO_BIOMETRIC_SUBTYPE)9)
%WINBIO_ANSI_381_POS_LH_LITTLE_FINGER   = 10?   ' ((WINBIO_BIOMETRIC_SUBTYPE)10)

%WINBIO_ANSI_381_POS_RH_FOUR_FINGERS    = 13?   ' ((WINBIO_BIOMETRIC_SUBTYPE)13)
%WINBIO_ANSI_381_POS_LH_FOUR_FINGERS    = 14?   ' ((WINBIO_BIOMETRIC_SUBTYPE)14)
%WINBIO_ANSI_381_POS_TWO_THUMBS         = 15?   ' ((WINBIO_BIOMETRIC_SUBTYPE)15)
'//
'// Table 6 -- Palm codes, areas, and maximum dimensions
'//
%WINBIO_ANSI_381_POS_UNKNOWN_PALM       = 20?   ' ((WINBIO_BIOMETRIC_SUBTYPE)20)
%WINBIO_ANSI_381_POS_RH_FULL_PALM       = 21?   ' ((WINBIO_BIOMETRIC_SUBTYPE)21)
%WINBIO_ANSI_381_POS_RH_WRITERS_PALM    = 22?   ' ((WINBIO_BIOMETRIC_SUBTYPE)22)
%WINBIO_ANSI_381_POS_LH_FULL_PALM       = 23?   ' ((WINBIO_BIOMETRIC_SUBTYPE)23)
%WINBIO_ANSI_381_POS_LH_WRITERS_PALM    = 24?   ' ((WINBIO_BIOMETRIC_SUBTYPE)24)
%WINBIO_ANSI_381_POS_RH_LOWER_PALM      = 25?   ' ((WINBIO_BIOMETRIC_SUBTYPE)25)
%WINBIO_ANSI_381_POS_RH_UPPER_PALM      = 26?   ' ((WINBIO_BIOMETRIC_SUBTYPE)26)
%WINBIO_ANSI_381_POS_LH_LOWER_PALM      = 27?   ' ((WINBIO_BIOMETRIC_SUBTYPE)27)
%WINBIO_ANSI_381_POS_LH_UPPER_PALM      = 28?   ' ((WINBIO_BIOMETRIC_SUBTYPE)28)
%WINBIO_ANSI_381_POS_RH_OTHER           = 29?   ' ((WINBIO_BIOMETRIC_SUBTYPE)29)
%WINBIO_ANSI_381_POS_LH_OTHER           = 30?   ' ((WINBIO_BIOMETRIC_SUBTYPE)30)
%WINBIO_ANSI_381_POS_RH_INTERDIGITAL    = 31?   ' ((WINBIO_BIOMETRIC_SUBTYPE)31)
%WINBIO_ANSI_381_POS_RH_THENAR          = 32?   ' ((WINBIO_BIOMETRIC_SUBTYPE)32)
%WINBIO_ANSI_381_POS_RH_HYPOTHENAR      = 33?   ' ((WINBIO_BIOMETRIC_SUBTYPE)33)
%WINBIO_ANSI_381_POS_LH_INTERDIGITAL    = 34?   ' ((WINBIO_BIOMETRIC_SUBTYPE)34)
%WINBIO_ANSI_381_POS_LH_THENAR          = 35?   ' ((WINBIO_BIOMETRIC_SUBTYPE)35)
%WINBIO_ANSI_381_POS_LH_HYPOTHENAR      = 36?   ' ((WINBIO_BIOMETRIC_SUBTYPE)36)

'//
'// SECTION 7.2.6 -- Impression-Type Codes
'//
'// Table 7 -- Finger and palm impression types
'//
%WINBIO_ANSI_381_IMP_TYPE_LIVE_SCAN_PLAIN        = 0?   ' ((UCHAR)0)
%WINBIO_ANSI_381_IMP_TYPE_LIVE_SCAN_ROLLED       = 1?   ' ((UCHAR)1)
%WINBIO_ANSI_381_IMP_TYPE_NONLIVE_SCAN_PLAIN     = 2?   ' ((UCHAR)2)
%WINBIO_ANSI_381_IMP_TYPE_NONLIVE_SCAN_ROLLED    = 3?   ' ((UCHAR)3)
%WINBIO_ANSI_381_IMP_TYPE_LATENT                 = 7?   ' ((UCHAR)7)
%WINBIO_ANSI_381_IMP_TYPE_SWIPE                  = 8?   ' ((UCHAR)8)
%WINBIO_ANSI_381_IMP_TYPE_LIVE_SCAN_CONTACTLESS  = 9?   ' ((UCHAR)9)


'//
'//
'//
'typedef ULONG WINBIO_POOL_TYPE, *PWINBIO_POOL_TYPE;

%WINBIO_POOL_UNKNOWN        = 0???   ' ((WINBIO_POOL_TYPE)0)
%WINBIO_POOL_SYSTEM         = 1???   ' ((WINBIO_POOL_TYPE)1)
%WINBIO_POOL_PRIVATE        = 2???   ' ((WINBIO_POOL_TYPE)2)
%WINBIO_POOL_UNASSIGNED     = 3???   ' ((WINBIO_POOL_TYPE)3) // Reserved for Microsoft - do not use.

'//
'// Specific access rights for Biometric Units
'//
%BIO_UNIT_RAW               = &H0001??   ' ((USHORT)0x0001)
%BIO_UNIT_MAINTENANCE       = &H0002??   ' ((USHORT)0x0002)
%BIO_UNIT_OPEN_SESSION      = &H0004??   ' ((USHORT)0x0004)
%BIO_UNIT_EXTENDED_ACCESS   = &H0008??   ' ((USHORT)0x0008)
%BIO_UNIT_ENROLL            = &H0010??   ' ((USHORT)0x0010)

'//
'// OpenSession parameter that controls session attributes...
'//
'typedef ULONG WINBIO_SESSION_FLAGS, *PWINBIO_SESSION_FLAGS;
'//
'// Sensor configuration flags...
'//
%WINBIO_FLAG_DEFAULT        = &H00000000???   ' ((WINBIO_SESSION_FLAGS)0x00000000)
%WINBIO_FLAG_BASIC          = &H00010000???   ' ((WINBIO_SESSION_FLAGS)((WINBIO_SENSOR_BASIC_MODE & 0xFFFF)<<16))
%WINBIO_FLAG_ADVANCED       = &H00020000???   ' ((WINBIO_SESSION_FLAGS)((WINBIO_SENSOR_ADVANCED_MODE & 0xFFFF)<<16))
'//
'// Desired access flags...
'//
%WINBIO_FLAG_RAW            = %BIO_UNIT_RAW           ' ((WINBIO_SESSION_FLAGS)BIO_UNIT_RAW)
%WINBIO_FLAG_MAINTENANCE    = %BIO_UNIT_MAINTENANCE   ' ((WINBIO_SESSION_FLAGS)BIO_UNIT_MAINTENANCE)

'//
'// Well-known database IDs used by WinBioOpenSession
'//
%WINBIO_DB_DEFAULT          = 1   ' ((GUID *)1)
%WINBIO_DB_BOOTSTRAP        = 2   ' ((GUID *)2)
%WINBIO_DB_ONCHIP           = 3   ' ((GUID *)3)

'//
'// Identify one of the components in a Biometric Unit's
'// processing pipeline (for ControlUnit operations)...
'//
'typedef ULONG WINBIO_COMPONENT, *PWINBIO_COMPONENT;

%WINBIO_COMPONENT_SENSOR    = 1???   ' ((WINBIO_COMPONENT)1)
%WINBIO_COMPONENT_ENGINE    = 2???   ' ((WINBIO_COMPONENT)2)
%WINBIO_COMPONENT_STORAGE   = 3???   ' ((WINBIO_COMPONENT)3)

'//
'// Event Monitor stuff...
'//
'typedef ULONG WINBIO_EVENT_TYPE, *PWINBIO_EVENT_TYPE;

'//
'// Generic events
'//
%WINBIO_EVENT_ERROR                 = &HFFFFFFFF???   ' ((WINBIO_EVENT_TYPE)0xFFFFFFFF)

'//
'// Fingerprint events.
'//
%WINBIO_EVENT_FP_UNCLAIMED          = &H00000001???   ' ((WINBIO_EVENT_TYPE)0x00000001)
%WINBIO_EVENT_FP_UNCLAIMED_IDENTIFY = &H00000002???   ' ((WINBIO_EVENT_TYPE)0x00000002)


'//
'// Event structure passed back to applications.
'//
'typedef struct _WINBIO_EVENT {
'    WINBIO_EVENT_TYPE Type;
'    union {
'        struct {
'            WINBIO_UNIT_ID UnitId;
'            WINBIO_REJECT_DETAIL RejectDetail;
'        } Unclaimed;
'        struct {
'            WINBIO_UNIT_ID UnitId;
'            WINBIO_IDENTITY Identity;
'            WINBIO_BIOMETRIC_SUBTYPE SubFactor;
'            WINBIO_REJECT_DETAIL RejectDetail;
'        } UnclaimedIdentify;
'        struct {
'            HRESULT ErrorCode;
'        } Error;
'    } Parameters;
'} WINBIO_EVENT, *PWINBIO_EVENT;

' // Size = 8 bytes
TYPE WINBIO_EVENT_UNCLAIMED DWORD
   UnitId       AS DWORD   ' WINBIO_UNIT_ID
   RejectDetail AS DWORD   ' WINBIO_REJECT_DETAIL
END TYPE

' // Size = 88 bytes
TYPE WINBIO_EVENT_UNCLAIMEDIDENTIFY DWORD
   UnitId       AS DWORD             ' WINBIO_UNIT_ID
   Identity     AS WINBIO_IDENTITY   ' WINBIO_IDENTITY
   SubFactor    AS BYTE              ' WINBIO_BIOMETRIC_SUBTYPE
   RejectDetail AS DWORD             ' WINBIO_REJECT_DETAIL
END TYPE

' // Size = 4 bytes
TYPE WINBIO_EVENT_ERROR DWORD
   ErrorCode AS LONG   ' HRESULT
END TYPE

' // Size = 88 bytes
UNION WINBIO_EVENT_PARAMETERS DWORD
   Unclaimed         AS WINBIO_EVENT_UNCLAIMED
   UnclaimedIdentify AS WINBIO_EVENT_UNCLAIMEDIDENTIFY
   Error             AS WINBIO_EVENT_ERROR
END UNION

' // Size = 92 bytes
TYPE WINBIO_EVENT DWORD
   Type AS DWORD   ' WINBIO_EVENT_TYPE
   WINBIO_EVENT_PARAMETERS
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'//
'// Schemata returned by enumeration APIs...
'//
'///////////////////////////////////////////////////////////////////////////////
'//
'// Results from EnumServiceProviders...
'//
' // Size = 1052 bytes
TYPE WINBIO_BSP_SCHEMA
   BiometricFactor AS DWORD                               ' WINBIO_BIOMETRIC_TYPE
   BspId           AS GUID                                ' WINBIO_UUID
   Description     AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   Vendor          AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   Version         AS WINBIO_VERSION                      ' WINBIO_VERSION
END TYPE

'//
'// Results from EnumBiometricUnits...
'//
' // Size = 2588 bytes
TYPE WINBIO_UNIT_SCHEMA DWORD
   UnitId           AS DWORD                               ' WINBIO_UNIT_ID
   PoolType         AS DWORD                               ' WINBIO_POOL_TYPE
   BiometricFactor  AS DWORD                               ' WINBIO_BIOMETRIC_TYPE
   SensorSubType    AS DWORD                               ' WINBIO_BIOMETRIC_SENSOR_SUBTYPE
   Capabilities     AS DWORD                               ' WINBIO_CAPABILITIES
   DeviceInstanceId AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   Description      AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   Manufacturer     AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   Model            AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   SerialNumber     AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   FirmwareVersion  AS WINBIO_VERSION                      ' WINBIO_VERSION
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'//
'// Definitions for the 'Attributes' database value...
'//
'///////////////////////////////////////////////////////////////////////////////
%WINBIO_DATABASE_TYPE_MASK      = &H0000FFFF???   ' ((ULONG)0x0000FFFF)
'//
'// Type values...
'//
%WINBIO_DATABASE_TYPE_FILE      = &H00000001???   ' ((ULONG)0x00000001)
%WINBIO_DATABASE_TYPE_DBMS      = &H00000002???   ' ((ULONG)0x00000002)
%WINBIO_DATABASE_TYPE_ONCHIP    = &H00000003???   ' ((ULONG)0x00000003)
%WINBIO_DATABASE_TYPE_SMARTCARD = &H00000004???   ' ((ULONG)0x00000004)

%WINBIO_DATABASE_FLAG_MASK      = &HFFFF0000???   ' ((ULONG)0xFFFF0000)
'//
'// Flag values...
'//
%WINBIO_DATABASE_FLAG_REMOVABLE = &H00010000???   ' ((ULONG)0x00010000)
%WINBIO_DATABASE_FLAG_REMOTE    = &H00020000???   ' ((ULONG)0x00020000)

'//
'// Results from EnumDatabases...
'//
' // Size = 1064 bytes
TYPE WINBIO_STORAGE_SCHEMA DWORD
   BiometricFactor  AS DWORD                               ' WINBIO_BIOMETRIC_TYPE
   DatabaseId       AS GUID                                ' WINBIO_UUID
   DataFormat       AS GUID                                ' WINBIO_UUID
   Attributes       AS DWORD                               ' ULONG
   FilePath         AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
   ConnectionString AS WSTRINGZ * %WINBIO_MAX_STRING_LEN   ' WINBIO_STRING
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'//
'// Credential management
'//
'///////////////////////////////////////////////////////////////////////////////

' enum WINBIO_CREDENTIAL_TYPE
%WINBIO_CREDENTIAL_PASSWORD = &H00000001???
%WINBIO_CREDENTIAL_ALL      = &Hffffffff???

' enum WINBIO_CREDENTIAL_FORMAT
%WINBIO_PASSWORD_GENERIC    = &H00000001???
%WINBIO_PASSWORD_PACKED     = &H00000002???

' enum WINBIO_CREDENTIAL_STATE {
%WINBIO_CREDENTIAL_NOT_SET  = &H00000001???
%WINBIO_CREDENTIAL_SET      = &H00000002???

'///////////////////////////////////////////////////////////////////////////////
'///////////////////////////////////////////////////////////////////////////////
'///////////////////////////////////////////////////////////////////////////////


'///////////////////////////////////////////////////////////////////////////////
'//
'// Settings
'//
'///////////////////////////////////////////////////////////////////////////////

'typedef ULONG32 WINBIO_SETTING_SOURCE_TYPE, *PWINBIO_SETTING_SOURCE_TYPE;

%WINBIO_SETTING_SOURCE_INVALID   = 0???   ' ((WINBIO_SETTING_SOURCE_TYPE)0)
%WINBIO_SETTING_SOURCE_DEFAULT   = 1???   ' ((WINBIO_SETTING_SOURCE_TYPE)1)
%WINBIO_SETTING_SOURCE_POLICY    = 2???   ' ((WINBIO_SETTING_SOURCE_TYPE)2)
%WINBIO_SETTING_SOURCE_LOCAL     = 3???   ' ((WINBIO_SETTING_SOURCE_TYPE)3)

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
