' ########################################################################################
' Microsoft Windows
' File: hidpi.inc
' Contents: Public Interface to the HID parsing library.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HIDPI_INC = 1

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable:4115) // named type definition in parentheses
'#pragma warning(disable:4201) // nameless struct/union
'#pragma warning(disable:4214) // bit field types other than int

'#include <pshpack4.h>

'// Please include "hidsdi.h" to use the user space (dll / parser)
'// Please include "hidpddi.h" to use the kernel space parser

'//
'// Special Link collection values for using the query functions
'//
'// Root collection references the collection at the base of the link
'// collection tree.
'// Unspecifies, references all collections in the link collection tree.
'//
%HIDP_LINK_COLLECTION_ROOT        = -1%   ' ((USHORT) -1)
%HIDP_LINK_COLLECTION_UNSPECIFIED = 0%    ' ((USHORT) 0)


' enum HIDP_REPORT_TYPE
%HidP_Input   = 0
%HidP_Output  = 1
%HidP_Feature = 2

' // Size = 4 bytes
TYPE USAGE_AND_PAGE BYTE
   Usage     AS WORD   ' USAGE
   UsagePage AS WORD   ' USAGE
END TYPE

'#define HidP_IsSameUsageAndPage(u1, u2) ((* (PULONG) &u1) == (* (PULONG) &u2))

' // Size = 16 bytes
TYPE HIDP_CAPS_RANGE BYTE
   UsageMin      AS WORD   ' USAGE
   UsageMax      AS WORD   ' USAGE
   StringMin     AS WORD   ' USHORT
   StringMax     AS WORD   ' USHORT
   DesignatorMin AS WORD   ' USHORT
   DesignatorMax AS WORD   ' USHORT
   DataIndexMin  AS WORD   ' USHORT
   DataIndexMax  AS WORD   ' USHORT
END TYPE

' // Size = 16 bytes
TYPE HIDP_CAPS_NOTRANGE BYTE
   Usage           AS WORD   ' USAGE
   Reserved1       AS WORD   ' USAGE
   StringIndex     AS WORD   ' USHORT
   Reserved2       AS WORD   ' USHORT
   DesignatorIndex AS WORD   ' USHORT
   Reserved3       AS WORD   ' USHORT
   DataIndex       AS WORD   ' USHORT
   Reserved4       AS WORD   ' USHORT
END TYPE

' // Size = 16 bytes
UNION HIDP_CAPS_UNION BYTE
   HIDP_CAPS_RANGE
   HIDP_CAPS_NOTRANGE
END UNION

' // Size = 72 bytes
TYPE HIDP_BUTTON_CAPS BYTE
   UsagePage         AS WORD    ' USAGE
   ReportID          AS BYTE    ' UCHAR
   IsAlias           AS BYTE    ' BOOLEAN
   BitField          AS WORD    ' USHORT
   LinkCollection    AS WORD    ' USHORT // A unique internal index pointer
   LinkUsage         AS WORD    ' USAGE
   LinkUsagePage     AS WORD    ' USAGE
   IsRange           AS BYTE    ' BOOLEAN
   IsStringRange     AS BYTE    ' BOOLEAN
   IsDesignatorRange AS BYTE    ' BOOLEAN
   IsAbsolute        AS BYTE    ' BOOLEAN
   Reserved(9)       AS DWORD   ' ULONG[10]
   HIDP_CAPS_UNION
END TYPE

' // Size = 72 bytes
TYPE HIDP_VALUE_CAPS BYTE
   UsagePage         AS WORD    ' USAGE
   ReportID          AS BYTE    ' UCHAR
   IsAlias           AS BYTE    ' BOOLEAN
   BitField          AS WORD    ' USHORT
   LinkCollection    AS WORD    ' USHORT // A unique internal index pointer
   LinkUsage         AS WORD    ' USAGE
   LinkUsagePage     AS WORD    ' USAGE
   IsRange           AS BYTE    ' BOOLEAN
   IsStringRange     AS BYTE    ' BOOLEAN
   IsDesignatorRange AS BYTE    ' BOOLEAN
   IsAbsolute        AS BYTE    ' BOOLEAN
   HasNull           AS BYTE    ' BOOLEAN // Does this channel have a null report   union
   Reserved          AS BYTE    ' UCHAR
   BitSize           AS WORD    ' USHORT // How many bits are devoted to this value?
   ReportCount       AS WORD    ' USHORT // See Note below.  Usually set to 1.
   Reserved2(4)      AS WORD    ' USHORT[5]
   UnitsExp          AS DWORD   ' ULONG
   Units             AS DWORD   ' ULONG
   LogicalMin        AS LONG    ' LONG
   LogicalMax        AS LONG    ' LONG
   PhysicalMin       AS LONG    ' LONG
   PhysicalMax       AS LONG    ' LONG
   HIDP_CAPS_UNION
END TYPE

'//
'// Notes:
'//
'// ReportCount:  When a report descriptor declares an Input, Output, or
'// Feature main item with fewer usage declarations than the report count, then
'// the last usage applies to all remaining unspecified count in that main item.
'// (As an example you might have data that required many fields to describe,
'// possibly buffered bytes.)  In this case, only one value cap structure is
'// allocated for these associtated fields, all with the same usage, and Report
'// Count reflects the number of fields involved.  Normally ReportCount is 1.
'// To access all of the fields in such a value structure would require using
'// HidP_GetUsageValueArray and HidP_SetUsageValueArray.   HidP_GetUsageValue/
'// HidP_SetScaledUsageValue will also work, however, these functions will only
'// work with the first field of the structure.
'//

'//
'// The link collection tree consists of an array of LINK_COLLECTION_NODES
'// where the index into this array is the same as the collection number.
'//
'// Given a collection A which contains a subcollection B, A is defined to be
'// the parent B, and B is defined to be the child.
'//
'// Given collections A, B, and C where B and C are children of A, and B was
'// encountered before C in the report descriptor, B is defined as a sibling of
'// C.  (This implies, of course, that if B is a sibling of C, then C is NOT a
'// sibling of B).
'//
'// B is defined as the NextSibling of C if and only if there exists NO
'// child collection of A, call it D, such that B is a sibling of D and D
'// is a sibling of C.
'//
'// E is defined to be the FirstChild of A if and only if for all children of A,
'// F, that are not equivalent to E, F is a sibling of E.
'// (This implies, of course, that the does not exist a child of A, call it G,
'// where E is a sibling of G).  In other words the first sibling is the last
'// link collection found in the list.
'//
'// In other words, if a collection B is defined within the definition of another
'// collection A, B becomes a child of A.  All collections with the same parent
'// are considered siblings.  The FirstChild of the parent collection, A, will be
'// last collection defined that has A as a parent.  The order of sibling pointers
'// is similarly determined.  When a collection B is defined, it becomes the
'// FirstChild of it's parent collection.  The previously defined FirstChild of the
'// parent collection becomes the NextSibling of the new collection.  As new
'// collections with the same parent are discovered, the chain of sibling is built.
'//
'// With that in mind, the following describes conclusively a data structure
'// that provides direct traversal up, down, and accross the link collection
'// tree.
'//
'//
' // Size = 20 bytes
TYPE HIDP_LINK_COLLECTION_NODE BYTE
   LinkUsage        AS WORD                  ' USAGE
   LinkUsagePage    AS WORD                  ' USAGE
   Parent           AS WORD                  ' USAGE
   NumberOfChildren AS WORD                  ' USAGE
   NextSibling      AS WORD                  ' USAGE
   FirstChild       AS WORD                  ' USAGE
   CollectionType   AS BIT   * 8  IN DWORD   ' // As defined in 6.2.2.6 of HID spec
   IsAlias          AS BIT   * 1             ' // This link node is an allias of the next link node.
   Reserved         AS BIT   * 23
   UserContext      AS DWORD                 ' PVOID // The user can hang his coat here.
END TYPE

'//
'// When a link collection is described by a delimiter, alias link collection
'// nodes are created.  (One for each usage within the delimiter).
'// The parser assigns each capability description listed above only one
'// link collection.
'//
'// If a control is defined within a collection defined by
'// delimited usages, then that control is said to be within multiple link
'// collections, one for each usage within the open and close delimiter tokens.
'// Such multiple link collecions are said to be aliases.  The first N-1 such
'// collections, listed in the link collection node array, have their IsAlias
'// bit set.  The last such link collection is the link collection index used
'// in the capabilities described above.
'// Clients wishing to set a control in an aliased collection, should walk the
'// collection array once for each time they see the IsAlias flag set, and use
'// the last link collection as the index for the below accessor functions.
'//
'// NB: if IsAlias is set, then NextSibling should be one more than the current
'// link collection node index.
'//

'typedef PUCHAR  PHIDP_REPORT_DESCRIPTOR;
'typedef struct _HIDP_PREPARSED_DATA * PHIDP_PREPARSED_DATA;

' // Size = 64 bytes
TYPE HIDP_CAPS BYTE
   Usage                     AS WORD   ' USAGE
   UsagePage                 AS WORD   ' USAGE
   InputReportByteLength     AS WORD   ' USHORT
   OutputReportByteLength    AS WORD   ' USHORT
   FeatureReportByteLength   AS WORD   ' USHORT
   Reserved(16)              AS WORD   ' USHORT[17]
   NumberLinkCollectionNodes AS WORD   ' USHORT
   NumberInputButtonCaps     AS WORD   ' USHORT
   NumberInputValueCaps      AS WORD   ' USHORT
   NumberInputDataIndices    AS WORD   ' USHORT
   NumberOutputButtonCaps    AS WORD   ' USHORT
   NumberOutputValueCaps     AS WORD   ' USHORT
   NumberOutputDataIndices   AS WORD   ' USHORT
   NumberFeatureButtonCaps   AS WORD   ' USHORT
   NumberFeatureValueCaps    AS WORD   ' USHORT
   NumberFeatureDataIndices  AS WORD   ' USHORT
END TYPE

' // Size = 4 bytes
UNION HIDP_DATA_UNION BYTE
   RawValue AS DWORD   ' ULONG // for values
   On       AS BYTE   ' BOOLEAN // for buttons MUST BE TRUE for buttons.
END UNION

' // Size = 8 bytes
TYPE HIDP_DATA BYTE
   DataIndex AS WORD   ' USHORT
   Reserved  AS WORD   ' USHORT
   HIDP_DATA_UNION
END TYPE

'//
'// The HIDP_DATA structure is used with HidP_GetData and HidP_SetData
'// functions.
'//
'// The parser contiguously assigns every control (button or value) in a hid
'// device a unique data index from zero to NumberXXXDataIndices -1 , inclusive.
'// This value is found in the HIDP_BUTTON_CAPS and HIDP_VALUE_CAPS structures.
'//
'// Most clients will find the Get/Set Buttons / Value accessor functions
'// sufficient to their needs, as they will allow the clients to access the
'// data known to them while ignoring the other controls.
'//
'// More complex clients, which actually read the Button / Value Caps, and which
'// do a value add service to these routines (EG Direct Input), will need to
'// access all the data in the device without interest in the individual usage
'// or link collection location.  These are the clients that will find
'// HidP_Data useful.
'//

' // Size = 8 bytes
TYPE HIDP_UNKNOWN_TOKEN BYTE
   Token       AS BYTE    ' UCHAR
   Reserved(2) AS BYTE    ' UCHAR[3]
   BitField    AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE HIDP_EXTENDED_ATTRIBUTES BYTE
   NumGlobalUnknowns AS BYTE                     ' UCHAR
   Reserved(2)       AS BYTE                     ' UCHAR[3]
   GlobalUnknowns    AS HIDP_UNKNOWN_TOKEN PTR   ' PHIDP_UNKNOWN_TOKEN
   ' // ... Additional attributes
   Data(0)           AS DWORD                    ' ULONG[1]; // variableLength  DO NOT ACCESS THIS FIELD
END TYPE

DECLARE FUNCTION HidP_GetCaps LIB "Hid.dll" ALIAS "HidP_GetCaps" ( _
   BYVAL PreparsedData AS DWORD _                       ' __in  PHIDP_PREPARSED_DATA
 , BYREF Capabilities AS HIDP_CAPS _                    ' __out PHIDP_CAPS
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Description:
'   Returns a list of capabilities of a given hid device as described by its
'   preparsed data.

'Arguments:
'   PreparsedData    The preparsed data returned from HIDCLASS.
'   Capabilities     a HIDP_CAPS structure

'Return Value:
'   HIDP_STATUS_SUCCESS
'   HIDP_STATUS_INVALID_PREPARSED_DATA
'--*/

DECLARE FUNCTION HidP_GetLinkCollectionNodes LIB "Hid.dll" ALIAS "HidP_GetLinkCollectionNodes" ( _
   BYREF LinkCollectionNodes AS HIDP_LINK_COLLECTION_NODE _ ' __out   PHIDP_LINK_COLLECTION_NODE LinkCollectionNodes
 , BYREF LinkCollectionNodesLength AS DWORD _           ' __inout PULONG                     LinkCollectionNodesLength
 , BYVAL PreparsedData AS DWORD _                       ' __in    PHIDP_PREPARSED_DATA       PreparsedData
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Description:
'   Return a list of PHIDP_LINK_COLLECTION_NODEs used to describe the link
'   collection tree of this hid device.  See the above description of
'   struct _HIDP_LINK_COLLECTION_NODE.

'Arguments:
'   LinkCollectionNodes - a caller allocated array into which
'                 HidP_GetLinkCollectionNodes will store the information

'   LinKCollectionNodesLength - the caller sets this value to the length of the
'                 the array in terms of number of elements.
'                 HidP_GetLinkCollectionNodes sets this value to the actual
'                 number of elements set. The total number of nodes required to
'                 describe this HID device can be found in the
'                 NumberLinkCollectionNodes field in the HIDP_CAPS structure.

'--*/

DECLARE FUNCTION HidP_GetSpecificButtonCaps LIB "Hid.dll" ALIAS "HidP_GetSpecificButtonCaps" ( _
   BYVAL ReportType AS LONG _                           ' __in    HIDP_REPORT_TYPE     ReportType
 , BYVAL UsagePage AS WORD _                            ' __in    USAGE                UsagePage        // Optional (0 = > ignore)
 , BYVAL LinkCollection AS WORD _                       ' __in    USHORT               LinkCollection   // Optional (0 = > ignore)
 , BYVAL Usage AS WORD _                                ' __in    USAGE                Usage            // Optional (0 = > ignore)
 , BYREF ButtonCaps AS HIDP_BUTTON_CAPS _               ' __out   PHIDP_BUTTON_CAPS    ButtonCaps
 , BYREF ButtonCapsLength AS WORD _                     ' __inout PUSHORT              ButtonCapsLength
 , BYVAL PreparsedData AS DWORD _                       ' __in    PHIDP_PREPARSED_DATA PreparsedData
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description:
'   HidP_GetButtonCaps returns all the buttons (binary values) that are a part
'   of the given report type for the Hid device represented by the given
'   preparsed data.

'Parameters:
'   ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'   UsagePage   A usage page value used to limit the button caps returned to
'                those on a given usage page.  If set to 0, this parameter is
'                ignored.  Can be used with LinkCollection and Usage parameters
'                to further limit the number of button caps structures returned.

'   LinkCollection HIDP_LINK_COLLECTION node array index used to limit the
'                  button caps returned to those buttons in a given link
'                  collection.  If set to 0, this parameter is
'                  ignored.  Can be used with UsagePage and Usage parameters
'                  to further limit the number of button caps structures
'                  returned.

'   Usage      A usage value used to limit the button caps returned to those
'               with the specified usage value.  If set to 0, this parameter
'               is ignored.  Can be used with LinkCollection and UsagePage
'               parameters to further limit the number of button caps
'               structures returned.

'   ButtonCaps A _HIDP_BUTTON_CAPS array containing information about all the
'               binary values in the given report.  This buffer is provided by
'               the caller.

'   ButtonLength   As input, this parameter specifies the length of the
'                  ButtonCaps parameter (array) in number of array elements.
'                  As output, this value is set to indicate how many of those
'                  array elements were filled in by the function.  The maximum number of
'                  button caps that can be returned is found in the HIDP_CAPS
'                  structure.  If HIDP_STATUS_BUFFER_TOO_SMALL is returned,
'                  this value contains the number of array elements needed to
'                  successfully complete the request.

'   PreparsedData  The preparsed data returned from HIDCLASS.


'Return Value
'HidP_GetSpecificButtonCaps returns the following error codes:
'  HIDP_STATUS_SUCCESS.
'  HIDP_STATUS_INVALID_REPORT_TYPE
'  HIDP_STATUS_INVALID_PREPARSED_DATA
'  HIDP_STATUS_BUFFER_TOO_SMALL (all given entries however have been filled in)
'  HIDP_STATUS_USAGE_NOT_FOUND
'--*/

DECLARE FUNCTION HidP_GetButtonCaps LIB "Hid.dll" ALIAS "HidP_GetButtonCaps" ( _
   BYVAL ReportType AS LONG _                           ' __in       HIDP_REPORT_TYPE     ReportType
 , BYREF ButtonCaps AS HIDP_BUTTON_CAPS _               ' __out_ecount_part(*ButtonCapsLength, *ButtonCapsLength) PHIDP_BUTTON_CAPS ButtonCaps
 , BYREF ButtonCapsLength AS WORD _                     ' __inout    PUSHORT              ButtonCapsLength
 , BYVAL PreparsedData AS DWORD _                       ' __in       PHIDP_PREPARSED_DATA PreparsedData
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION HidP_GetSpecificValueCaps LIB "Hid.dll" ALIAS "HidP_GetSpecificValueCaps" ( _
   BYVAL ReportType AS LONG _                           ' __in       HIDP_REPORT_TYPE     ReportType
 , BYVAL UsagePage AS WORD _                            ' __in       USAGE                UsagePage      // Optional (0 => ignore)
 , BYVAL LinkCollection AS WORD _                       ' __in       USHORT               LinkCollection // Optional (0 => ignore)
 , BYVAL Usage AS WORD _                                ' __in       USAGE                Usage          // Optional (0 => ignore)
 , BYREF ValueCaps AS HIDP_VALUE_CAPS _                 ' __out      PHIDP_VALUE_CAPS     ValueCaps
 , BYREF ValueCapsLength AS WORD _                      ' __inout    PUSHORT              ValueCapsLength
 , BYVAL PreparsedData AS DWORD _                       ' __in       PHIDP_PREPARSED_DATA PreparsedData
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description:
'   HidP_GetValueCaps returns all the values (non-binary) that are a part
'   of the given report type for the Hid device represented by the given
'   preparsed data.

'Parameters:
'   ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'   UsagePage   A usage page value used to limit the value caps returned to
'                those on a given usage page.  If set to 0, this parameter is
'                ignored.  Can be used with LinkCollection and Usage parameters
'                to further limit the number of value caps structures returned.

'   LinkCollection HIDP_LINK_COLLECTION node array index used to limit the
'                  value caps returned to those buttons in a given link
'                  collection.  If set to 0, this parameter is
'                  ignored.  Can be used with UsagePage and Usage parameters
'                  to further limit the number of value caps structures
'                  returned.

'   Usage      A usage value used to limit the value caps returned to those
'               with the specified usage value.  If set to 0, this parameter
'               is ignored.  Can be used with LinkCollection and UsagePage
'               parameters to further limit the number of value caps
'               structures returned.

'   ValueCaps  A _HIDP_VALUE_CAPS array containing information about all the
'               non-binary values in the given report.  This buffer is provided
'               by the caller.

'   ValueLength   As input, this parameter specifies the length of the ValueCaps
'                  parameter (array) in number of array elements.  As output,
'                  this value is set to indicate how many of those array elements
'                  were filled in by the function.  The maximum number of
'                  value caps that can be returned is found in the HIDP_CAPS
'                  structure.  If HIDP_STATUS_BUFFER_TOO_SMALL is returned,
'                  this value contains the number of array elements needed to
'                  successfully complete the request.

'   PreparsedData  The preparsed data returned from HIDCLASS.


'Return Value
'HidP_GetValueCaps returns the following error codes:
'  HIDP_STATUS_SUCCESS.
'  HIDP_STATUS_INVALID_REPORT_TYPE
'  HIDP_STATUS_INVALID_PREPARSED_DATA
'  HIDP_STATUS_BUFFER_TOO_SMALL (all given entries however have been filled in)
'  HIDP_STATUS_USAGE_NOT_FOUND

'--*/

DECLARE FUNCTION HidP_GetValueCaps LIB "Hid.dll" ALIAS "HidP_GetValueCaps" ( _
   BYVAL ReportType AS LONG _                           ' __in       HIDP_REPORT_TYPE     ReportType
 , BYREF ButtonCaps AS HIDP_VALUE_CAPS _                ' __out_ecount_part(*ValueCapsLength, *ValueCapsLength) PHIDP_VALUE_CAPS ValueCaps,
 , BYREF ValueCapsLength AS WORD _                      ' __inout    PUSHORT              ValueCapsLength
 , BYVAL PreparsedData AS DWORD _                       ' __in       PHIDP_PREPARSED_DATA PreparsedData
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION HidP_GetExtendedAttributes LIB "Hid.dll" ALIAS "HidP_GetExtendedAttributes" ( _
   BYVAL ReportType AS LONG _                           ' __in      HIDP_REPORT_TYPE     ReportType
 , BYVAL DataIndex AS WORD _                            ' __in      USHORT                      DataIndex
 , BYVAL PreparsedData AS DWORD _                       ' __in      PHIDP_PREPARSED_DATA        PreparsedData
 , BYREF Attributes AS HIDP_EXTENDED_ATTRIBUTES _       ' __out_ecount_part(*LengthAttributes, *LengthAttributes) PHIDP_EXTENDED_ATTRIBUTES Attributes
 , BYREF LengthAttributes AS DWORD _                    ' __inout   PULONG                      LengthAttributes
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description:
'    Given a data index from the value or button capabilities of a given control
'    return any extended attributes for the control if any exist.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'    DataIndex   The data index for the given control, found in the capabilities
'                structure for that control

'    PreparsedData   The preparsed data returned from HIDCLASS.

'    Attributes  Pointer to a buffer into which the extended attribute data will
'                be copied.

'    LengthAttributes    Length of the given buffer in bytes.

'Return Value
'    HIDP_STATUS_SUCCESS
'    HIDP_STATUS_DATA_INDEX_NOT_FOUND
'--*/

DECLARE FUNCTION HidP_InitializeReportForID LIB "Hid.dll" ALIAS "HidP_InitializeReportForID" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL ReportID AS BYTE _                             ' __in UCHAR ReportID
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __out_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++

'Routine Description:

'    Initialize a report based on the given report ID.

'Parameters:

'    ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'    PreparasedData  Preparsed data structure returned by HIDCLASS

'    Report      Buffer which to set the data into.

'    ReportLength Length of Report...Report should be at least as long as the
'                value indicated in the HIDP_CAPS structure for the device and
'                the corresponding ReportType

'Return Value

'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not equal
'                                        to the length specified in HIDP_CAPS
'                                        structure for the given ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType

'--*/

DECLARE FUNCTION HidP_SetData LIB "Hid.dll" ALIAS "HidP_SetData" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYREF DataList AS HIDP_DATA _                        ' __inout_ecount_part(*DataLength,*DataLength) PHIDP_DATA DataList
 , BYREF DataLength AS DWORD _                          ' __inout PULONG DataLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __in_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++

'Routine Description:

'    Please Note: Since usage value arrays deal with multiple fields for
'                 for one usage value, they cannot be used with HidP_SetData
'                 and HidP_GetData.  In this case,
'                 HIDP_STATUS_IS_USAGE_VALUE_ARRAY will be returned.

'Parameters:

'    ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'    DataList    Array of HIDP_DATA structures that contains the data values
'                that are to be set into the given report

'    DataLength  As input, length in array elements of DataList.  As output,
'                contains the number of data elements set on successful
'                completion or an index into the DataList array to identify
'                the faulting HIDP_DATA value if an error code is returned.

'    PreparasedData  Preparsed data structure returned by HIDCLASS

'    Report      Buffer which to set the data into.

'    ReportLength Length of Report...Report should be at least as long as the
'                value indicated in the HIDP_CAPS structure for the device and
'                the corresponding ReportType

'Return Value
'    HidP_SetData returns the following error codes.  The report packet will
'        have all the data set up until the HIDP_DATA structure that caused the
'        error.  DataLength, in the error case, will return this problem index.

'  HIDP_STATUS_SUCCESS                -- upon successful insertion of all data
'                                        into the report packet.
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_DATA_INDEX_NOT_FOUND   -- if a HIDP_DATA structure referenced a
'                                        data index that does not exist for this
'                                        device's ReportType
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not equal
'                                        to the length specified in HIDP_CAPS
'                                        structure for the given ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_IS_USAGE_VALUE_ARRAY   -- if one of the HIDP_DATA structures
'                                        references a usage value array.
'                                        DataLength will contain the index into
'                                        the array that was invalid
'  HIDP_STATUS_BUTTON_NOT_PRESSED     -- if a HIDP_DATA structure attempted
'                                        to unset a button that was not already
'                                        set in the Report
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- a HIDP_DATA structure was found with
'                                        a valid index value but is contained
'                                        in a different report than the one
'                                        currently being processed
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if there are not enough entries in
'                                        a given Main Array Item to report all
'                                        buttons that have been requested to be
'                                        set
'--*/

DECLARE FUNCTION HidP_GetData LIB "Hid.dll" ALIAS "HidP_GetData" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYREF DataList AS HIDP_DATA _                        ' __out_ecount_part(*DataLength,*DataLength) PHIDP_DATA DataList
 , BYREF DataLength AS DWORD _                          ' __inout PULONG DataLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __out_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++

'Routine Description:

'    Please Note: For obvious reasons HidP_SetData and HidP_GetData will not
'    access UsageValueArrays.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output, or HidP_Feature.

'    DataList    Array of HIDP_DATA structures that will receive the data
'                values that are set in the given report

'    DataLength  As input, length in array elements of DataList.  As output,
'                contains the number of data elements that were successfully
'                set by HidP_GetData.  The maximum size necessary for DataList
'                can be determined by calling HidP_MaxDataListLength

'    PreparasedData  Preparsed data structure returned by HIDCLASS

'    Report      Buffer which to set the data into.

'    ReportLength Length of Report...Report should be at least as long as the
'                value indicated in the HIDP_CAPS structure for the device and
'                the corresponding ReportType

'Return Value
'    HidP_GetData returns the following error codes.

'  HIDP_STATUS_SUCCESS                -- upon successful retrieval of all data
'                                        from the report packet.
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not equal
'                                        to the length specified in HIDP_CAPS
'                                        structure for the given ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if there are not enough array entries in
'                                        DataList to store all the indice values
'                                        in the given report.  DataLength will
'                                        contain the number of array entries
'                                        required to hold all data
'--*/

DECLARE FUNCTION HidP_MaxDataListLength LIB "Hid.dll" ALIAS "HidP_MaxDataListLength" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 ) AS DWORD                                             ' ULONG

'/*++
'Routine Description:

'    This function returns the maximum length of HIDP_DATA elements that
'    HidP_GetData could return for the given report type.

'Parameters:

'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    PreparsedData    Preparsed data structure returned by HIDCLASS

'Return Value:

'    The length of the data list array required for the HidP_GetData function
'    call.  If an error occurs (either HIDP_STATUS_INVALID_REPORT_TYPE or
'    HIDP_STATUS_INVALID_PREPARSED_DATA), this function returns 0.

'--*/

'#define HidP_SetButtons(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle) \
'        HidP_SetUsages(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle)

DECLARE FUNCTION HidP_SetUsages LIB "Hid.dll" ALIAS "HidP_SetUsages" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE   UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT  LinkCollection
 , BYREF UsageList AS WORD _                            ' __inout_ecount_part(*UsageLength,*UsageLength) PUSAGE  UsageList
 , BYREF UsageLength AS DWORD _                         ' __inout  PULONG  UsageLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA  PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __in_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG   ReportLength
 ) AS LONG                                              ' NTSTATUS

MACRO HidP_SetButtons(Rty_, Up_, Lco_, ULi_, ULe_, Ppd_, Rep_, Rle_) = HidP_SetUsages(Rty_, Up_, Lco_, ULi_, ULe_, Ppd_, Rep_, Rle_)

'/*++

'Routine Description:
'    This function sets binary values (buttons) in a report.  Given an
'    initialized packet of correct length, it modifies the report packet so that
'    each element in the given list of usages has been set in the report packet.
'    For example, in an output report with 5 LED's, each with a given usage,
'    an application could turn on any subset of these lights by placing their
'    usages in any order into the usage array (UsageList).  HidP_SetUsages would,
'    in turn, set the appropriate bit or add the corresponding byte into the
'    HID Main Array Item.

'    A properly initialized Report packet is one of the correct byte length,
'    and all zeros.

'    NOTE: A packet that has already been set with a call to a HidP_Set routine
'          can also be passed in.  This routine then sets processes the UsageList
'          in the same fashion but verifies that the ReportID already set in
'          Report matches the report ID for the given usages.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    UsagePage   All of the usages in the usage array, which HidP_SetUsages will
'                set in the report, refer to this same usage page.
'                If a client wishes to set usages in a report for multiple
'                usage pages then that client needs to make multiple calls to
'                HidP_SetUsages for each of the usage pages.

'    UsageList   A usage array containing the usages that HidP_SetUsages will set in
'                the report packet.

'    UsageLength The length of the given usage array in array elements.
'                The parser will set this value to the position in the usage
'                array where it stopped processing.  If successful, UsageLength
'                will be unchanged.  In any error condition, this parameter
'                reflects how many of the usages in the usage list have
'                actually been set by the parser.  This is useful for finding
'                the usage in the list which caused the error.

'    PreparsedData The preparsed data recevied from HIDCLASS

'    Report      The report packet.

'    ReportLength   Length of the given report packet...Must be equal to the
'                   value reported in the HIDP_CAPS structure for the device
'                   and corresponding report type.

'Return Value
'    HidP_SetUsages returns the following error codes.  On error, the report packet
'    will be correct up until the usage element that caused the error.

'  HIDP_STATUS_SUCCESS                -- upon successful insertion of all usages
'                                        into the report packet.
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- if a usage was found that exists in a
'                                        different report.  If the report is
'                                        zero-initialized on entry the first
'                                        usage in the list will determine which
'                                        report ID is used.  Otherwise, the
'                                        parser will verify that usage matches
'                                        the passed in report's ID
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage does not exist for any
'                                        report (no matter what the report ID)
'                                        for the given report type.
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if there are not enough entries in a
'                                        given Main Array Item to list all of
'                                        the given usages.  The caller needs
'                                        to split his request into more than
'                                        one call
'--*/

'#define HidP_UnsetButtons(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle) \
'        HidP_UnsetUsages(Rty, Up, Lco, ULi, ULe, Ppd, Rep, Rle)

DECLARE FUNCTION HidP_UnsetUsages LIB "Hid.dll" ALIAS "HidP_UnsetUsages" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE   UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT  LinkCollection
 , BYREF UsageList AS WORD _                            ' __inout_ecount_part(*UsageLength,*UsageLength) PUSAGE  UsageList
 , BYREF UsageLength AS DWORD _                         ' __inout  PULONG  UsageLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA  PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __in_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG   ReportLength
 ) AS LONG                                              ' NTSTATUS

MACRO HidP_UnsetButtons(Rty_, Up_, Lco_, ULi_, ULe_, Ppd_, Rep_, Rle_) = HidP_UnsetUsages(Rty_, Up_, Lco_, ULi_, ULe_, Ppd_, Rep_, Rle_)

'/*++

'Routine Description:
'    This function unsets (turns off) binary values (buttons) in the report.  Given
'    an initialized packet of correct length, it modifies the report packet so
'    that each element in the given list of usages has been unset in the
'    report packet.

'    This function is the "undo" operation for SetUsages.  If the given usage
'    is not already set in the Report, it will return an error code of
'    HIDP_STATUS_BUTTON_NOT_PRESSED.  If the button is pressed, HidP_UnsetUsages
'    will unset the appropriate bit or remove the corresponding index value from
'    the HID Main Array Item.

'    A properly initialized Report packet is one of the correct byte length,
'    and all zeros..

'    NOTE: A packet that has already been set with a call to a HidP_Set routine
'          can also be passed in.  This routine then processes the UsageList
'          in the same fashion but verifies that the ReportID already set in
'          Report matches the report ID for the given usages.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    UsagePage   All of the usages in the usage array, which HidP_UnsetUsages will
'                unset in the report, refer to this same usage page.
'                If a client wishes to unset usages in a report for multiple
'                usage pages then that client needs to make multiple calls to
'                HidP_UnsetUsages for each of the usage pages.

'    UsageList   A usage array containing the usages that HidP_UnsetUsages will
'                unset in the report packet.

'    UsageLength The length of the given usage array in array elements.
'                The parser will set this value to the position in the usage
'                array where it stopped processing.  If successful, UsageLength
'                will be unchanged.  In any error condition, this parameter
'                reflects how many of the usages in the usage list have
'                actually been unset by the parser.  This is useful for finding
'                the usage in the list which caused the error.

'    PreparsedData The preparsed data recevied from HIDCLASS

'    Report      The report packet.

'    ReportLength   Length of the given report packet...Must be equal to the
'                   value reported in the HIDP_CAPS structure for the device
'                   and corresponding report type.

'Return Value
'    HidP_UnsetUsages returns the following error codes.  On error, the report
'    packet will be correct up until the usage element that caused the error.

'  HIDP_STATUS_SUCCESS                -- upon successful "unsetting" of all usages
'                                        in the report packet.
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- if a usage was found that exists in a
'                                        different report.  If the report is
'                                        zero-initialized on entry the first
'                                        usage in the list will determine which
'                                        report ID is used.  Otherwise, the
'                                        parser will verify that usage matches
'                                        the passed in report's ID
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage does not exist for any
'                                        report (no matter what the report ID)
'                                        for the given report type.
'  HIDP_STATUS_BUTTON_NOT_PRESSED     -- if a usage corresponds to a button that
'                                        is not already set in the given report
'--*/

'#define HidP_GetButtons(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe) \
'        HidP_GetUsages(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe)

DECLARE FUNCTION HidP_GetUsages LIB "Hid.dll" ALIAS "HidP_GetUsages" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE   UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT  LinkCollection
 , BYREF UsageList AS WORD _                            ' __out_ecount(UsageLength)  PUSAGE UsageList
 , BYREF UsageLength AS DWORD _                         ' __inout  PULONG  UsageLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA  PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __in_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG   ReportLength
 ) AS LONG                                              ' NTSTATUS

MACRO HidP_GetButtons(Rty_, UPa_, LCo_, ULi_, ULe_, Ppd_, Rep_, RLe_) = HidP_GetUsages(Rty_, UPa_, LCo_, ULi_, ULe_, Ppd_, Rep_, RLe_)

'/*++

'Routine Description:
'    This function returns the binary values (buttons) that are set in a HID
'    report.  Given a report packet of correct length, it searches the report
'    packet for each usage for the given usage page and returns them in the
'    usage list.

'Parameters:
'    ReportType One of HidP_Input, HidP_Output or HidP_Feature.

'    UsagePage  All of the usages in the usage list, which HidP_GetUsages will
'               retrieve in the report, refer to this same usage page.
'               If the client wishes to get usages in a packet for multiple
'               usage pages then that client needs to make multiple calls
'               to HidP_GetUsages.

'    LinkCollection  An optional value which can limit which usages are returned
'                    in the UsageList to those usages that exist in a specific
'                    LinkCollection.  A non-zero value indicates the index into
'                    the HIDP_LINK_COLLECITON_NODE list returned by
'                    HidP_GetLinkCollectionNodes of the link collection the
'                    usage should belong to.  A value of 0 indicates this
'                    should value be ignored.

'    UsageList  The usage array that will contain all the usages found in
'               the report packet.

'    UsageLength The length of the given usage array in array elements.
'                On input, this value describes the length of the usage list.
'                On output, HidP_GetUsages sets this value to the number of
'                usages that was found.  Use HidP_MaxUsageListLength to
'                determine the maximum length needed to return all the usages
'                that a given report packet may contain.

'    PreparsedData Preparsed data structure returned by HIDCLASS

'    Report       The report packet.

'    ReportLength  Length (in bytes) of the given report packet


'Return Value
'    HidP_GetUsages returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully retrieving all the
'                                        usages from the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if the UsageList is not big enough to
'                                        hold all the usages found in the report
'                                        packet.  If this is returned, the buffer
'                                        will contain UsageLength number of
'                                        usages.  Use HidP_MaxUsageListLength to
'                                        find the maximum length needed
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- if no usages were found but usages
'                                        that match the UsagePage and
'                                        LinkCollection specified could be found
'                                        in a report with a different report ID
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if there are no usages in a reports for
'                                        the device and ReportType that match the
'                                        UsagePage and LinkCollection that were
'                                        specified
'--*/

'#define HidP_GetButtonsEx(Rty, LCo, BLi, ULe, Ppd, Rep, RLe)  \
'         HidP_GetUsagesEx(Rty, LCo, BLi, ULe, Ppd, Rep, RLe)

DECLARE FUNCTION HidP_GetUsagesEx LIB "Hid.dll" ALIAS "HidP_GetUsagesEx" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE   UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT  LinkCollection // Optional
 , BYREF ButtonList AS USAGE_AND_PAGE _                 ' __inout_ecount_part(*UsageLength,*UsageLength) PUSAGE_AND_PAGE  ButtonList
 , BYREF UsageLength AS DWORD _                         ' __inout  PULONG  UsageLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA  PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __in_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG   ReportLength
 ) AS LONG                                              ' NTSTATUS

MACRO HidP_GetButtonsEx(Rty_, LCo_, BLi_, ULe_, Ppd_, Rep_, RLe_) = HidP_GetUsagesEx(Rty_, LCo_, BLi_, ULe_, Ppd_, Rep_, RLe_)

'/*++

'Routine Description:
'    This function returns the binary values (buttons) in a HID report.
'    Given a report packet of correct length, it searches the report packet
'    for all buttons and returns the UsagePage and Usage for each of the buttons
'    it finds.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    LinkCollection  An optional value which can limit which usages are returned
'                    in the ButtonList to those usages that exist in a specific
'                    LinkCollection.  A non-zero value indicates the index into
'                    the HIDP_LINK_COLLECITON_NODE list returned by
'                    HidP_GetLinkCollectionNodes of the link collection the
'                    usage should belong to.  A value of 0 indicates this
'                    should value be ignored.

'    ButtonList  An array of USAGE_AND_PAGE structures describing all the
'                buttons currently ``down'' in the device.

'    UsageLength The length of the given array in terms of elements.
'                On input, this value describes the length of the list.  On
'                output, HidP_GetUsagesEx sets this value to the number of
'                usages that were found.  Use HidP_MaxUsageListLength to
'                determine the maximum length needed to return all the usages
'                that a given report packet may contain.

'    PreparsedData Preparsed data returned by HIDCLASS

'    Report       The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value
'    HidP_GetUsagesEx returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully retrieving all the
'                                        usages from the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if ButtonList is not big enough to
'                                        hold all the usages found in the report
'                                        packet.  If this is returned, the buffer
'                                        will contain UsageLength number of
'                                        usages.  Use HidP_MaxUsageListLength to
'                                        find the maximum length needed
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- if no usages were found but usages
'                                        that match the specified LinkCollection
'                                        exist in report with a different report
'                                        ID.
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if there are no usages in any reports that
'                                        match the LinkCollection parameter
'--*/

DECLARE FUNCTION HidP_MaxUsageListLength LIB "Hid.dll" ALIAS "HidP_MaxUsageListLength" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE      ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE                 UsagePage// Optional
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA  PreparsedData
 ) AS DWORD                                             ' ULONG

'/*++
'Routine Description:
'    This function returns the maximum number of usages that a call to
'    HidP_GetUsages or HidP_GetUsagesEx could return for a given HID report.
'    If calling for number of usages returned by HidP_GetUsagesEx, use 0 as
'    the UsagePage value.

'Parameters:
'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    UsagePage   Specifies the optional UsagePage to query for.  If 0, will
'                return all the maximum number of usage values that could be
'                returned for a given ReportType.   If non-zero, will return
'                the maximum number of usages that would be returned for the
'                ReportType with the given UsagePage.

'    PreparsedData Preparsed data returned from HIDCLASS

'Return Value:
'    The length of the usage list array required for the HidP_GetUsages or
'    HidP_GetUsagesEx function call.  If an error occurs (such as
'    HIDP_STATUS_INVALID_REPORT_TYPE or HIDP_INVALID_PREPARSED_DATA, this
'    returns 0.
'--*/

DECLARE FUNCTION HidP_SetUsageValue LIB "Hid.dll" ALIAS "HidP_SetUsageValue" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYVAL UsageValue AS DWORD _                          ' __in ULONG UsageValue
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description:
'    HidP_SetUsageValue inserts a value into the HID Report Packet in the field
'    corresponding to the given usage page and usage.  HidP_SetUsageValue
'    casts this value to the appropriate bit length.  If a report packet
'    contains two different fields with the same Usage and UsagePage,
'    they can be distinguished with the optional LinkCollection field value.
'    Using this function sets the raw value into the report packet with
'    no checking done as to whether it actually falls within the logical
'    minimum/logical maximum range.  Use HidP_SetScaledUsageValue for this...

'    NOTE: Although the UsageValue parameter is a ULONG, any casting that is
'          done will preserve or sign-extend the value.  The value being set
'          should be considered a LONG value and will be treated as such by
'          this function.

'Parameters:

'    ReportType  One of HidP_Output or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will set the first field
'                                it finds that matches the usage page and
'                                usage.

'    Usage       The usage whose value HidP_SetUsageValue will set.

'    UsageValue  The raw value to set in the report buffer.  This value must be within
'                the logical range or if a NULL value this value should be the
'                most negative value that can be represented by the number of bits
'                for this field.

'    PreparsedData The preparsed data returned for HIDCLASS

'    Report      The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value:
'    HidP_SetUsageValue returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully setting the value
'                                        in the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call HidP_SetUsageValue
'                                        again with a zero-initizialed report
'                                        packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_SetScaledUsageValue LIB "Hid.dll" ALIAS "HidP_SetScaledUsageValue" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYVAL UsageValue AS DWORD _                          ' __in ULONG UsageValue
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description:
'    HidP_SetScaledUsageValue inserts the UsageValue into the HID report packet
'    in the field corresponding to the given usage page and usage.  If a report
'    packet contains two different fields with the same Usage and UsagePage,
'    they can be distinguished with the optional LinkCollection field value.

'    If the specified field has a defined physical range, this function converts
'    the physical value specified to the corresponding logical value for the
'    report.  If a physical value does not exist, the function will verify that
'    the value specified falls within the logical range and set according.

'    If the range checking fails but the field has NULL values, the function will
'    set the field to the defined NULL value (most negative number possible) and
'    return HIDP_STATUS_NULL.  In other words, use this function to set NULL
'    values for a given field by passing in a value that falls outside the
'    physical range if it is defined or the logical range otherwise.

'    If the field does not support NULL values, an out of range error will be
'    returned instead.

'Parameters:

'    ReportType  One of HidP_Output or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will set the first field
'                                it finds that matches the usage page and
'                                usage.

'    Usage       The usage whose value HidP_SetScaledUsageValue will set.

'    UsageValue  The value to set in the report buffer.  See the routine
'                description above for the different interpretations of this
'                value

'    PreparsedData The preparsed data returned from HIDCLASS

'    Report      The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value:
'   HidP_SetScaledUsageValue returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully setting the value
'                                        in the report packet
'  HIDP_STATUS_NULL                   -- upon successfully setting the value
'                                        in the report packet as a NULL value
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_VALUE_OUT_OF_RANGE     -- if the value specified failed to fall
'                                        within the physical range if it exists
'                                        or within the logical range otherwise
'                                        and the field specified by the usage
'                                        does not allow NULL values
'  HIDP_STATUS_BAD_LOG_PHY_VALUES     -- if the field has a physical range but
'                                        either the logical range is invalid
'                                        (max <= min) or the physical range is
'                                        invalid
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call
'                                        HidP_SetScaledUsageValue again with
'                                        a zero-initialized report packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_SetUsageValueArray LIB "Hid.dll" ALIAS "HidP_SetUsageValueArray" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYVAL UsageValue AS BYTE PTR _                       ' __in_bcount(UsageValueByteLength) PCHAR UsageValue
 , BYVAL UsageValueByteLength AS WORD _                 ' __in USHORT UsageValueByteLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report,
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Descripton:
'    A usage value array occurs when the last usage in the list of usages
'    describing a main item must be repeated because there are less usages defined
'    than there are report counts declared for the given main item.  In this case
'    a single value cap is allocated for that usage and the report count of that
'    value cap is set to reflect the number of fields to which that usage refers.

'    HidP_SetUsageValueArray sets the raw bits for that usage which spans
'    more than one field in a report.

'    NOTE: This function currently does not support value arrays where the
'          ReportSize for each of the fields in the array is not a multiple
'          of 8 bits.

'          The UsageValue buffer should have the values set as they would appear
'          in the report buffer.  If this function supported non 8-bit multiples
'          for the ReportSize then caller should format the input buffer so that
'          each new value begins at the bit immediately following the last bit
'          of the previous value

'Parameters:

'    ReportType  One of HidP_Output or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will set the first field
'                                it finds that matches the usage page and
'                                usage.

'    Usage       The usage whose value array HidP_SetUsageValueArray will set.

'    UsageValue  The buffer with the values to set into the value array.
'                The number of BITS required is found by multiplying the
'                BitSize and ReportCount fields of the Value Cap for this
'                control.  The least significant bit of this control found in the
'                given report will be placed in the least significan bit location
'                of the array given (little-endian format), regardless of whether
'                or not the field is byte alligned or if the BitSize is a multiple
'                of sizeof (CHAR).

'                See the above note for current implementation limitations.

'    UsageValueByteLength  Length of the UsageValue buffer (in bytes)

'    PreparsedData The preparsed data returned from HIDCLASS

'    Report      The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value:
'  HIDP_STATUS_SUCCESS                -- upon successfully setting the value
'                                        array in the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_NOT_VALUE_ARRAY        -- if the control specified is not a
'                                        value array -- a value array will have
'                                        a ReportCount field in the
'                                        HIDP_VALUE_CAPS structure that is > 1
'                                        Use HidP_SetUsageValue instead
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if the size of the passed in buffer with
'                                        the values to set is too small (ie. has
'                                        fewer values than the number of fields in
'                                        the array
'  HIDP_STATUS_NOT_IMPLEMENTED        -- if the usage value array has field sizes
'                                        that are not multiples of 8 bits, this
'                                        error code is returned since the function
'                                        currently does not handle setting into
'                                        such arrays.
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call
'                                        HidP_SetUsageValueArray again with
'                                        a zero-initialized report packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_GetUsageValue LIB "Hid.dll" ALIAS "HidP_GetUsageValue" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYREF UsageValue AS DWORD _                          ' __out PULONG UsageValue
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report,
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*
'Description
'    HidP_GetUsageValue retrieves the value from the HID Report for the usage
'    specified by the combination of usage page, usage and link collection.
'    If a report packet contains two different fields with the same
'    Usage and UsagePage, they can be distinguished with the optional
'    LinkCollection field value.

'Parameters:

'    ReportType  One of HidP_Input or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will set the first field
'                                it finds that matches the usage page and
'                                usage.

'    Usage       The usage whose value HidP_GetUsageValue will retrieve

'    UsageValue  The raw value that is set for the specified field in the report
'                buffer. This value will either fall within the logical range
'                or if NULL values are allowed, a number outside the range to
'                indicate a NULL

'    PreparsedData The preparsed data returned for HIDCLASS

'    Report      The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value:
'    HidP_GetUsageValue returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully retrieving the value
'                                        from the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_REPORT_DOES_NOT_EXIST  -- if there are no reports on this device
'                                        for the given ReportType
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call HidP_GetUsageValue
'                                        again with a different report packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_GetScaledUsageValue LIB "Hid.dll" ALIAS "HidP_GetScaledUsageValue" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYREF UsageValue AS LONG _                           ' __out PLONG UsageValue
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report,
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Description
'    HidP_GetScaledUsageValue retrieves a UsageValue from the HID report packet
'    in the field corresponding to the given usage page and usage.  If a report
'    packet contains two different fields with the same Usage and UsagePage,
'    they can be distinguished with the optional LinkCollection field value.

'    If the specified field has a defined physical range, this function converts
'    the logical value that exists in the report packet to the corresponding
'    physical value.  If a physical range does not exist, the function will
'    return the logical value.  This function will check to verify that the
'    logical value in the report falls within the declared logical range.

'    When doing the conversion between logical and physical values, this
'    function assumes a linear extrapolation between the physical max/min and
'    the logical max/min. (Where logical is the values reported by the device
'    and physical is the value returned by this function).  If the data field
'    size is less than 32 bits, then HidP_GetScaledUsageValue will sign extend
'    the value to 32 bits.

'    If the range checking fails but the field has NULL values, the function
'    will set UsageValue to 0 and return HIDP_STATUS_NULL.  Otherwise, it
'    returns a HIDP_STATUS_OUT_OF_RANGE error.

'Parameters:

'    ReportType  One of HidP_Output or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will retrieve the first
'                                field it finds that matches the usage page
'                                and usage.

'    Usage       The usage whose value HidP_GetScaledUsageValue will retrieve

'    UsageValue  The value retrieved from the report buffer.  See the routine
'                description above for the different interpretations of this
'                value

'    PreparsedData The preparsed data returned from HIDCLASS

'    Report      The report packet.

'    ReportLength Length (in bytes) of the given report packet.


'Return Value:
'   HidP_GetScaledUsageValue returns the following error codes:

'  HIDP_STATUS_SUCCESS                -- upon successfully retrieving the value
'                                        from the report packet
'  HIDP_STATUS_NULL                   -- if the report packet had a NULL value
'                                        set
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_VALUE_OUT_OF_RANGE     -- if the value retrieved from the packet
'                                        falls outside the logical range and
'                                        the field does not support NULL values
'  HIDP_STATUS_BAD_LOG_PHY_VALUES     -- if the field has a physical range but
'                                        either the logical range is invalid
'                                        (max <= min) or the physical range is
'                                        invalid
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call
'                                        HidP_GetScaledUsageValue with a
'                                        different report packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_GetUsageValueArray LIB "Hid.dll" ALIAS "HidP_GetUsageValueArray" ( _
   BYVAL ReportType AS LONG _                           ' __in HIDP_REPORT_TYPE ReportType
 , BYVAL UsagePage AS WORD _                            ' __in USAGE UsagePage
 , BYVAL LinkCollection AS WORD _                       ' __in USHORT LinkCollection
 , BYVAL Usage AS WORD _                                ' __in USAGE Usage
 , BYVAL UsageValue AS BYTE PTR _                       ' __inout_bcount(UsageValueByteLength) PCHAR UsageValue
 , BYVAL UsageValueByteLength AS WORD _                 ' __in USHORT UsageValueByteLength
 , BYVAL PreparsedData AS DWORD _                       ' __in PHIDP_PREPARSED_DATA PreparsedData
 , BYVAL Report AS BYTE PTR _                           ' __inout_bcount(ReportLength) PCHAR Report,
 , BYVAL ReportLength AS DWORD _                        ' __in ULONG ReportLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Descripton:
'    A usage value array occurs when the last usage in the list of usages
'    describing a main item must be repeated because there are less usages defined
'    than there are report counts declared for the given main item.  In this case
'    a single value cap is allocated for that usage and the report count of that
'    value cap is set to reflect the number of fields to which that usage refers.

'    HidP_GetUsageValueArray returns the raw bits for that usage which spans
'    more than one field in a report.

'    NOTE: This function currently does not support value arrays where the
'          ReportSize for each of the fields in the array is not a multiple
'          of 8 bits.

'          The UsageValue buffer will have the raw values as they are set
'          in the report packet.

'Parameters:

'    ReportType  One of HidP_Input, HidP_Output or HidP_Feature.

'    UsagePage   The usage page to which the given usage refers.

'    LinkCollection  (Optional)  This value can be used to differentiate
'                                between two fields that may have the same
'                                UsagePage and Usage but exist in different
'                                collections.  If the link collection value
'                                is zero, this function will set the first field
'                                it finds that matches the usage page and
'                                usage.

'   Usage       The usage whose value HidP_GetUsageValueArray will retreive.

'   UsageValue  A pointer to an array of characters where the value will be
'               placed.  The number of BITS required is found by multiplying the
'               BitSize and ReportCount fields of the Value Cap for this
'               control.  The least significant bit of this control found in the
'               given report will be placed in the least significant bit location
'               of the buffer (little-endian format), regardless of whether
'               or not the field is byte aligned or if the BitSize is a multiple
'               of sizeof (CHAR).

'               See note above about current implementation limitations

'   UsageValueByteLength
'               the length of the given UsageValue buffer.

'   PreparsedData The preparsed data returned by the HIDCLASS

'   Report      The report packet.

'   ReportLength   Length of the given report packet.

'Return Value:

'  HIDP_STATUS_SUCCESS                -- upon successfully retrieving the value
'                                        from the report packet
'  HIDP_STATUS_INVALID_REPORT_TYPE    -- if ReportType is not valid.
'  HIDP_STATUS_INVALID_PREPARSED_DATA -- if PreparsedData is not valid
'  HIDP_STATUS_INVALID_REPORT_LENGTH  -- the length of the report packet is not
'                                        equal to the length specified in
'                                        the HIDP_CAPS structure for the given
'                                        ReportType
'  HIDP_STATUS_NOT_VALUE_ARRAY        -- if the control specified is not a
'                                        value array -- a value array will have
'                                        a ReportCount field in the
'                                        HIDP_VALUE_CAPS structure that is > 1
'                                        Use HidP_GetUsageValue instead
'  HIDP_STATUS_BUFFER_TOO_SMALL       -- if the size of the passed in buffer in
'                                        which to return the array is too small
'                                        (ie. has fewer values than the number of
'                                        fields in the array
'  HIDP_STATUS_NOT_IMPLEMENTED        -- if the usage value array has field sizes
'                                        that are not multiples of 8 bits, this
'                                        error code is returned since the function
'                                        currently does not handle getting values
'                                        from such arrays.
'  HIDP_STATUS_INCOMPATIBLE_REPORT_ID -- the specified usage page, usage and
'                                        link collection exist but exists in
'                                        a report with a different report ID
'                                        than the report being passed in.  To
'                                        set this value, call
'                                        HidP_GetUsageValueArray with a
'                                        different report packet
'  HIDP_STATUS_USAGE_NOT_FOUND        -- if the usage page, usage, and link
'                                        collection combination does not exist
'                                        in any reports for this ReportType
'--*/

DECLARE FUNCTION HidP_UsageListDifference LIB "Hid.dll" ALIAS "HidP_UsageListDifference" ( _
   BYREF PreviousUsageList AS WORD _                    ' __in_ecount(UsageListLength) PUSAGE PreviousUsageList
 , BYREF CurrentUsageList AS WORD _                     ' __in_ecount(UsageListLength) PUSAGE CurrentUsageList
 , BYREF BreakUsageList AS WORD _                       ' __out_ecount(UsageListLength) PUSAGE BreakUsageList
 , BYREF MakeUsageList AS WORD _                        ' __out_ecount(UsageListLength) PUSAGE MakeUsageList
 , BYVAL UsageListLength AS DWORD _                     ' __in ULONG UsageListLength
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Description:
'    This function will return the difference between a two lists of usages
'    (as might be returned from HidP_GetUsages),  In other words, it will return
'    return a list of usages that are in the current list but not the previous
'    list as well as a list of usages that are in the previous list but not
'    the current list.

'Parameters:

'    PreviousUsageList   The list of usages before.
'    CurrentUsageList    The list of usages now.
'    BreakUsageList      Previous - Current.
'    MakeUsageList       Current - Previous.
'    UsageListLength     Represents the length of the usage lists in array
'                        elements.  If comparing two lists with a differing
'                        number of array elements, this value should be
'                        the size of the larger of the two lists.  Any
'                        zero found with a list indicates an early termination
'                        of the list and any usages found after the first zero
'                        will be ignored.
'--*/

DECLARE FUNCTION HidP_UsageAndPageListDifference LIB "Hid.dll" ALIAS "HidP_UsageAndPageListDifference" ( _
   BYREF PreviousUsageList AS USAGE_AND_PAGE _          ' __in_ecount(UsageListLength) PUSAGE_AND_PAGE PreviousUsageList
 , BYREF CurrentUsageList AS USAGE_AND_PAGE _           ' __in_ecount(UsageListLength) PUSAGE_AND_PAGE CurrentUsageList
 , BYREF BreakUsageList AS USAGE_AND_PAGE _             ' __out_ecount(UsageListLength) PUSAGE_AND_PAGE BreakUsageList
 , BYREF MakeUsageList AS USAGE_AND_PAGE _              ' __out_ecount(UsageListLength) PUSAGE_AND_PAGE MakeUsageList
 , BYVAL UsageListLength AS DWORD _                     ' __in ULONG UsageListLength
 ) AS LONG                                              ' NTSTATUS

'//
'// Produce Make or Break Codes
'//
' enum HIDP_KEYBOARD_DIRECTION
%HidP_Keyboard_Break = 0
%HidP_Keyboard_Make  = 1

'//
'// A bitmap of the current shift state of the keyboard when using the
'// below keyboard usages to i8042 translation function.
'//

' // Sizxe = 4 bytes
TYPE HIDP_KEYBOARD_MODIFIER_STATE_UNION_STRUCT BYTE
   LeftControl  AS BIT * 1  IN DWORD
   LeftShift    AS BIT * 1
   LeftAlt      AS BIT * 1
   LeftGUI      AS BIT * 1
   RightControl AS BIT * 1
   RightShift   AS BIT * 1
   RightAlt     AS BIT * 1
   RightGUI     AS BIT * 1
   CapsLock     AS BIT * 1
   ScollLock    AS BIT * 1
   NumLock      AS BIT * 1
   Reserved     AS BIT * 21
END TYPE

' // Sizxe = 4 bytes
UNION HIDP_KEYBOARD_MODIFIER_STATE_UNION BYTE
   HIDP_KEYBOARD_MODIFIER_STATE_UNION_STRUCT
   ul AS DWORD   ' ULONG
END UNION

' // Sizxe = 4 bytes
TYPE HIDP_KEYBOARD_MODIFIER_STATE BYTE
   HIDP_KEYBOARD_MODIFIER_STATE_UNION
END TYPE

'//
'// A call back function to give the i8042 scan codes to the caller of
'// the below translation function.
'//
'typedef BOOLEAN (* PHIDP_INSERT_SCANCODES) (
'                  __in_opt PVOID Context,  // Some caller supplied context.
'                  __in_bcount(Length) PCHAR NewScanCodes, // A list of i8042 scan codes.
'                  __in ULONG Length // the length of the scan codes.
'                  );

'FUNCTION HIDP_INSERT_SCANCODES ( _
'   BYVAL Context AS DWORD _                             ' __in_opt PVOID Context  // Some caller supplied context.
' , BYVAL NewScanCodes AS BYTE PTR _                     ' __in_bcount(Length) PCHAR NewScanCodes // A list of i8042 scan codes.
' , BYVAL Length AS DWORD _                              ' __in ULONG Length // the length of the scan codes.
' ) AS BYTE                                              ' BOOLEAN

' // Undocumented. Not exported.
DECLARE FUNCTION HidP_TranslateUsageAndPagesToI8042ScanCodes LIB "Hid.dll" ALIAS "HidP_TranslateUsageAndPagesToI8042ScanCodes" ( _
   BYREF ChangedUsageList AS USAGE_AND_PAGE _           ' __in_ecount(UsageListLength)           PUSAGE_AND_PAGE ChangedUsageList
 , BYVAL UsageListLength AS DWORD _                     ' __in     ULONG                         UsageListLength
 , BYVAL KeyAction AS LONG _                            ' __in     HIDP_KEYBOARD_DIRECTION       KeyAction
 , BYREF ModifierState AS HIDP_KEYBOARD_MODIFIER_STATE _ ' __inout  PHIDP_KEYBOARD_MODIFIER_STATE ModifierState
 , BYVAL InsertCodesProcedure AS DWORD _                ' __in     PHIDP_INSERT_SCANCODES        InsertCodesProcedure
 , BYVAL InsertCodesContext AS DWORD _                  ' __in_opt PVOID                         InsertCodesContext
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Description:
'Parameters:
'--*/

DECLARE FUNCTION HidP_TranslateUsagesToI8042ScanCodes LIB "Hid.dll" ALIAS "HidP_TranslateUsagesToI8042ScanCodes" ( _
   BYREF ChangedUsageList AS WORD _                     ' __in_ecount(UsageListLength)           __in_ecount(UsageListLength)           PUSAGE ChangedUsageList
 , BYVAL UsageListLength AS DWORD _                     ' __in     ULONG                         UsageListLength
 , BYVAL KeyAction AS LONG _                            ' __in     HIDP_KEYBOARD_DIRECTION       KeyAction
 , BYREF ModifierState AS HIDP_KEYBOARD_MODIFIER_STATE _ ' __inout  PHIDP_KEYBOARD_MODIFIER_STATE ModifierState
 , BYVAL InsertCodesProcedure AS DWORD _                ' __in     PHIDP_INSERT_SCANCODES        InsertCodesProcedure
 , BYVAL InsertCodesContext AS DWORD _                  ' __in_opt PVOID                         InsertCodesContext
 ) AS LONG                                              ' NTSTATUS

'/*++
'Routine Description:
'Parameters:
'--*/



'//
'// Define NT Status codes with Facility Code of FACILITY_HID_ERROR_CODE
'//

'// FACILITY_HID_ERROR_CODE defined in ntstatus.h
#IF NOT %DEF(%FACILITY_HID_ERROR_CODE)
%FACILITY_HID_ERROR_CODE = &H11
#endif

'#define HIDP_ERROR_CODES(SEV, CODE) \
'        ((NTSTATUS) (((SEV) << 28) | (FACILITY_HID_ERROR_CODE << 16) | (CODE)))

FUNCTION HIDP_ERROR_CODES (BYVAL SEV_ AS DWORD, BYVAL CODE_ AS DWORD) AS LONG
   LOCAL x AS DWORD
   SHIFT LEFT SEV_, 28
   x = %FACILITY_HID_ERROR_CODE
   SHIFT LEFT x, 16
   x = x OR CODE_
   FUNCTION = BITS(LONG, SEV_ OR x)
END FUNCTION

%HIDP_STATUS_SUCCESS                  = &H00110000&   ' (HIDP_ERROR_CODES(0x0,0))
%HIDP_STATUS_NULL                     = &H80110001&   ' (HIDP_ERROR_CODES(0x8,1))
%HIDP_STATUS_INVALID_PREPARSED_DATA   = &HC0110001&   ' (HIDP_ERROR_CODES(0xC,1))
%HIDP_STATUS_INVALID_REPORT_TYPE      = &HC0110002&   ' (HIDP_ERROR_CODES(0xC,2))
%HIDP_STATUS_INVALID_REPORT_LENGTH    = &HC0110003&   ' (HIDP_ERROR_CODES(0xC,3))
%HIDP_STATUS_USAGE_NOT_FOUND          = &HC0110004&   ' (HIDP_ERROR_CODES(0xC,4))
%HIDP_STATUS_VALUE_OUT_OF_RANGE       = &HC0110005&   ' (HIDP_ERROR_CODES(0xC,5))
%HIDP_STATUS_BAD_LOG_PHY_VALUES       = &HC0110006&   ' (HIDP_ERROR_CODES(0xC,6))
%HIDP_STATUS_BUFFER_TOO_SMALL         = &HC0110007&   ' (HIDP_ERROR_CODES(0xC,7))
%HIDP_STATUS_INTERNAL_ERROR           = &HC0110008&   ' (HIDP_ERROR_CODES(0xC,8))
%HIDP_STATUS_I8042_TRANS_UNKNOWN      = &HC0110009&   ' (HIDP_ERROR_CODES(0xC,9))
%HIDP_STATUS_INCOMPATIBLE_REPORT_ID   = &HC011000A&   ' (HIDP_ERROR_CODES(0xC,0xA))
%HIDP_STATUS_NOT_VALUE_ARRAY          = &HC011000B&   ' (HIDP_ERROR_CODES(0xC,0xB))
%HIDP_STATUS_IS_VALUE_ARRAY           = &HC011000C&   ' (HIDP_ERROR_CODES(0xC,0xC))
%HIDP_STATUS_DATA_INDEX_NOT_FOUND     = &HC011000D&   ' (HIDP_ERROR_CODES(0xC,0xD))
%HIDP_STATUS_DATA_INDEX_OUT_OF_RANGE  = &HC011000E&   ' (HIDP_ERROR_CODES(0xC,0xE))
%HIDP_STATUS_BUTTON_NOT_PRESSED       = &HC011000F&   ' (HIDP_ERROR_CODES(0xC,0xF))
%HIDP_STATUS_REPORT_DOES_NOT_EXIST    = &HC0110010&   ' (HIDP_ERROR_CODES(0xC,0x10))
%HIDP_STATUS_NOT_IMPLEMENTED          = &HC0110020&   ' (HIDP_ERROR_CODES(0xC,0x20))

'//
'// We blundered this status code.
'//
%HIDP_STATUS_I8242_TRANS_UNKNOWN = %HIDP_STATUS_I8042_TRANS_UNKNOWN

'#include <poppack.h>

'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning(default:4115)
'#pragma warning(default:4201)
'#pragma warning(default:4214)
'#endif
