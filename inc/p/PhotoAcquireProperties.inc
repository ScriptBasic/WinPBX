' ########################################################################################
' Microsoft Windows
' File: PhotoAcquireProperties.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'/*
' * Copyright (c) Microsoft Corporation.  All Rights Reserved.
' *
' * PROPERTYKEYs used internally by the Photo Acquisition engine
' *
' */

#INCLUDE THIS ONCE
%PHOTOACQUIREPROPERTIES_INC = 1

'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_RelativePathname, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 2); // VT_LPWSTR
MACRO PKEY_PhotoAcquire_RelativePathname = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(2)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_FinalFilename, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 3);    // VT_LPWSTR
MACRO PKEY_PhotoAcquire_FinalFilename = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(3)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_GroupTag, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 4);    // VT_LPWSTR
MACRO PKEY_PhotoAcquire_GroupTag = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(4)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_TransferResult, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 5);    // VT_SCODE
MACRO PKEY_PhotoAcquire_TransferResult = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(5)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_OriginalFilename, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 6);    // VT_LPWSTR
MACRO PKEY_PhotoAcquire_OriginalFilename = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(6)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_CameraSequenceNumber, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 7);    // VT_LPWSTR
MACRO PKEY_PhotoAcquire_CameraSequenceNumber = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(7)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_IntermediateFile, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 8);    // VT_LPWSTR
MACRO PKEY_PhotoAcquire_IntermediateFile = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(8)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_SkipImport, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 9);    // VT_BOOL
MACRO PKEY_PhotoAcquire_SkipImport = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(9)
'DEFINE_PROPERTYKEY(PKEY_PhotoAcquire_DuplicateDetectionID, 0x00f23377, 0x7ac6, 0x4b7a, 0x84, 0x43, 0x34, 0x5e, 0x73, 0x1f, 0xa5, 0x7a, 10);    // VT_I4
MACRO PKEY_PhotoAcquire_DuplicateDetectionID = GUID$("{00f23377-7ac6-4b7a-8443-345e731fa57a}") & MKDWD$(10)
