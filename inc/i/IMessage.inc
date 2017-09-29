' ########################################################################################
' Microsoft Windows
' File: Imessage.inc
' Contents: External definitions for MAPI's IMessage-on-IStorage facility
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IMESSAGE_INC = 1

#INCLUDE ONCE "mapidefs.inc"

'typedef struct _MSGSESS      FAR * LPMSGSESS;

'/*   Typedef of optional callback routine to be called on last release of
' *   top-level messages opened with OpenIMsgOnIStg
' */
'typedef void (STDAPICALLTYPE MSGCALLRELEASE)(
'   ULONG       ulCallerData,
'   LPMESSAGE   lpMessage );

'/* DLL Entry Points (found in mapiu.dll) */

'/* OpenIMsgSession
' * CloseIMsgSession
' *
' * These entry points allow the caller to "wrap" the creation of messages
' * inside a session, so that when the session is closed, all messages
' * created within that session are closed as well. Use of IMSG sessions
' * is optional. If OpenIMsgOnIStg is called with a NULL for the lpmsgsess
' * parameter, the message is created independent of any session, and has
' * no way to be shutdown. If the caller forgets to release the message, or
' * to release open tables within the message, the memory will be leaked until
' * the external application terminates.
' */

DECLARE FUNCTION OpenIMsgSession IMPORT "MAPI32.DLL" ALIAS "OpenIMsgSession@12" ( _
   BYVAL lpMalloc AS IMalloc _                          ' __in  LPMALLOC lpMalloc
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG ulFlags
 , BYREF lppMsgSess AS IMessage _                       ' __out LPMSGSESS FAR * lppMsgSess
 ) AS LONG                                              ' SCODE

DECLARE SUB CloseIMsgSession IMPORT "MAPI32.DLL" ALIAS "CloseIMsgSession@4" ( _
   BYVAL lpMsgSess AS IMessage _                        ' __in LPMSGSESS lpMsgSess
 )                                                      ' void

'/*   OpenIMsgOnIStg - Main entry point
' *
' *   NOTE 1:  The IStg must be opened with STGM_TRANSACTED if STGM_READWRITE
' *   is specified.  Since messages don't support a write only mode, IMessage
' *   doesn't allow a storage object opened in write only mode. If the storage
' *   is opened STGM_READ, then STGM_TRANSACTED is NOT required.
' *
' *   NOTE 2:  The lpMapiSup parameter is optional.  If supplied then IMessage
' *   will support the MAPI_DIALOG and ATTACH_DIALOG flags (by calling
' *   support method: DoMCDialog) on CopyTo and DeleteAttach methods.
' *   If lpMapiSup is not supplied (i.e. passed 0) then dialog flags will be
' *   ignored.  If supplied then ModifyRecipients will attempt to convert
' *   short term entryids to long term entryids (by calling support method
' *   OpenAddressBook and calls on the returned object).  If not supplied
' *   then short term entryid's will be stored without conversion.
' *
' *   NOTE 3:  The lpfMsgCallRelease parameter is optional.  If supplied then
' *   IMessage will call the routine when the last release on (the toplevel only)
' *   message is called.  It is intended to allow the callee to free the IStorage
' *   that contains the message.  IMessage will not use the IStorage object after
' *   making this call.
' *
' *   NOTE 4:  Behavior of multiple opens of sub-objects (Attachments, Streams,
' *   Storages, Messages, etc.) within a message is deliberately undefined in
' *   MAPI.  This implementation allows them, but will do it by AddRef'ing the
' *   existing open and returning it to the caller of OpenAttachment or
' *   OpenProperty.  This means that whatever access mode the first open on a
' *   specific Attachment or Property had is what all others will get regardless
' *   of what the subsequent opens asked for.
' *
' *   NOTE 5:  There is currently one flag defined for use with the ulFlags
' *   parameter. The IMSG_NO_ISTG_COMMIT flag controls whether the commit
' *   method of IStorage is called when the client calls SaveChanges on the
' *   IMessage object. Some clients of IMessage may wish to commit the IStorage
' *   themselves after writing additional data to the storage (beyond what
' *   IMessage itself writes). To aid in this, the IMessage implementation
' *   guarantees to name all sub-storages starting with "__". Therefore,
' *   if the client keeps its names out of that namespace, there will be no
' *   accidental collisions.
' *
' *   WARNING:
' *
' *   This implementation of IMessage will support OpenProperty w/MAPI_CREATE
' *   where the source interface is IID_IStorage if the property id is
' *   'PR_ATTACH_DATA'.  Once this has been done, the caller has an IStorage
' *   interface on this property.  This is ok and should allow for
' *   easier implementation of OLE 2.0 Server functionality.  However, if you
' *   pass in the new IStorage ptr (to the attachment data) through the
' *   OpenIMsgOnIStg entry point and then proceed to release things in the
' *   wrong order we will make no attempt to behave in a predictable fashion.
' *   Keep in mind that the correct method for placing a message into an
' *   attachment is to call OpenProperty where the source interface is
' *   IID_IMessage.  The IStorage interface is supported to allow an easy way
' *   to stick a WWord doc. into an attachment w/o converting to/from IStream.
' *
' */

DECLARE FUNCTION OpenIMsgOnIStg IMPORT "MAPI32.DLL" ALIAS "OpenIMsgOnIStg@44" ( _
   BYVAL lpMsgSess AS IMessage _                        ' __in  LPMSGSESS lpMsgSess
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in  LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in  LPALLOCATEMORE lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in  LPFREEBUFFER lpFreeBuffer
 , BYVAL lpmalloc AS IMalloc _                          ' __in  LPMALLOC lpmalloc
 , BYVAL lpMapiSup AS IUnknown _                        ' __in  LPVOID lpMapiSup
 , BYVAL lpStg AS IStorage _                            ' __in  LPSTORAGE lpStg
 , BYVAL lpfMsgCallRelease AS DWORD _                   ' __in  MSGCALLRELEASE FAR * lpfMsgCallRelease
 , BYVAL ulCallerData AS DWORD _                        ' __in  ULONG ulCallerData
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG ulFlags
 , BYREF lppMsg AS IMessage _                           ' __out LPMESSAGE FAR * lppMsg
 ) AS LONG                                              ' SCODE

%IMSG_NO_ISTG_COMMIT = &H00000001???


'/* NOTE: Property Attributes are specific to this IMessage on IStorage       */
'/* implementation and are not a part of standard MAPI 1.0 property methods    */

'/* Property Attributes */

%PROPATTR_MANDATORY   = &H00000001???
%PROPATTR_READABLE    = &H00000002???
%PROPATTR_WRITEABLE   = &H00000004???

%PROPATTR_NOT_PRESENT = &H00000008???

'/* Attribute Array */

' // Size = 8 bytes
TYPE SPropAttrArray DWORD
   cValues AS DWORD                    ' ULONG
   aPropAttr(%MAPI_DIM - 1) AS DWORD   ' ULONG [variable-length array]
END TYPE


'/*   GetAttribIMsgOnIStg - To get attributes on properties
' *
' *   This call is provided because there is no method of IMAPIPropSet to allow
' *   getting attributes.
' */

DECLARE FUNCTION GetAttribIMsgOnIStg IMPORT "MAPI32.DLL" ALIAS "GetAttribIMsgOnIStg@12" ( _
   BYVAL lpObject AS IUnknown _                         ' __in  LPVOID lpObject
 , BYVAL lpPropTagArray AS SPropAttrArray PTR _         ' __in  LPSPropTagArray lpPropTagArray
 , BYREF lppPropAttrArray AS DWORD _                    ' __out LPSPropAttrArray FAR * lppPropAttrArray
 ) AS LONG                                              ' HRESULT

'/*   SetAttribIMsgOnIStg - To set attributes on properties
' *
' *   This call is provided because there is no method of IMAPIPropSet to allow
' *   setting of attributes.
' */

DECLARE FUNCTION SetAttribIMsgOnIStg IMPORT "MAPI32.DLL" ALIAS "SetAttribIMsgOnIStg@16" ( _
   BYVAL lpObject AS IUnknown _                         ' __in  LPVOID lpObject
 , BYVAL lpPropTags AS SPropTagArray PTR _              ' __in  LPSPropTagArray lpPropTags
 , BYVAL lpPropAttrs AS SPropAttrArray PTR _            ' __in  LPSPropAttrArray lpPropAttrs
 , BYREF lppPropProblems AS DWORD _                     ' __out LPSPropProblemArray FAR * lppPropProblems
 ) AS LONG                                              ' HRESULT

'/*   MapStorageSCode - To map an IStorage hResult to a MAPI sCode value
' *
' *   This call is provided for the internal use of PDK components that base
' *   their message implementations on IMessage.  Since these components must
' *   open the storage themselves, there is a common need to map OLE 2.0
' *   Storage error returns to MAPI sCodes.
' *
' *   WARNING:   There is no guarantee that this entry point will exist in
' *   shipped versions of mapiu.dll.
' */

DECLARE FUNCTION MapStorageSCode IMPORT "MAPI32.DLL" ALIAS "MapStorageSCode@4" ( _
   BYVAL StgSCode AS LONG _                             ' __in SCODE StgSCode
 ) AS LONG                                              ' SCODE
