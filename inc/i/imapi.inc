' ########################################################################################
' Microsoft Windows
' File: imapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Image Mastering API
' The Image Mastering API (IMAPI) allows an application to stage and burn a simple audio
' or data image to CD-R and CD-RW devices. The API supports the following formats: Redbook
' audio and data discs with both Joliet and ISO 9660. The architecture allows for future
' expansion of the supported format set.
' ########################################################################################

#INCLUDE THIS ONCE
%IMAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "imapierror.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSDiscMasterObj               = GUID$("{520CCA63-51A5-11D3-9144-00104BA11C5E}")
$CLSID_MSDiscRecorderObj             = GUID$("{520CCA61-51A5-11D3-9144-00104BA11C5E}")
$CLSID_MSEnumDiscRecordersObj        = GUID$("{8A03567A-63CB-4BA8-BAF6-52119816D1EF}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDiscMaster                     = GUID$("{520CCA62-51A5-11D3-9144-00104BA11C5E}")
$IID_IDiscRecorder                   = GUID$("{85AC9776-CA88-4CF2-894E-09598C078A41}")
$IID_IEnumDiscMasterFormats          = GUID$("{DDF445E1-54BA-11D3-9144-00104BA11C5E}")
$IID_IEnumDiscRecorders              = GUID$("{9B1921E1-54AC-11D3-9144-00104BA11C5E}")
$IID_IJolietDiscMaster               = GUID$("{E3BC42CE-4E5C-11D3-9144-00104BA11C5E}")
$IID_IRedbookDiscMaster              = GUID$("{E3BC42CD-4E5C-11D3-9144-00104BA11C5E}")
$IID_IDiscMasterProgressEvents       = GUID$("{EC9E51C1-4E5D-11D3-9144-00104BA11C5E}")

' ========================================================================================
' MEDIA_TYPES enum
' ========================================================================================

%MEDIA_CDDA_CDROM                    = 1
%MEDIA_CD_ROM_XA                     = %MEDIA_CDDA_CDROM + 1
%MEDIA_CD_I                          = %MEDIA_CD_ROM_XA  + 1
%MEDIA_CD_EXTRA                      = %MEDIA_CD_I       + 1
%MEDIA_CD_OTHER                      = %MEDIA_CD_EXTRA   + 1
%MEDIA_SPECIAL                       = %MEDIA_CD_OTHER   + 1

' ========================================================================================
' MEDIA_FLAGS enum
' ========================================================================================

%MEDIA_BLANK                         = &H1
%MEDIA_RW                            = &H2
%MEDIA_WRITABLE                      = &H4
%MEDIA_FORMAT_UNUSABLE_BY_IMAPI      = &H8

' ========================================================================================
' RECORDER_TYPES enum
' ========================================================================================

%RECORDER_CDR                        = &H1
%RECORDER_CDRW                       = &H2

' ========================================================================================
' Recorder states
' ========================================================================================

%RECORDER_DOING_NOTHING              = 0
%RECORDER_OPENED                     = &H1
%RECORDER_BURNING                    = &H2


' ########################################################################################
' Interface name = IDiscRecorder
' IID = {85AC9776-CA88-4CF2-894E-09598C078A41}
' Inherited interface = IUnknown
' The IDiscRecorder interface enables access to a single disc recorder device, labeled the
' active disc recorder. An IMAPI object such as MSDiscMasterObj maintains an active disc
' recorder.
' An IDiscRecorder object represents a single hardware device, but there can be multiple
' instances of IDiscRecorder all referencing the same hardware device. In this case, use
' OpenExclusive to access that device.
' When To Use
' Use an instance of this object to select the recorder for a burn through IDiscMaster and
' to perform basic control tasks on a specific physical disc recorder.
' Note  An application does not call CoCreateInstance for one of these objects, but
' instead uses the IDiscMaster.EnumDiscRecorders method to retrieve an enumerator that
' returns pointers to all the recorders valid for a specific format.
' ########################################################################################

INTERFACE IDiscRecorder $IID_IDiscRecorder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pbyUniqueID AS BYTE PTR _                    ' __in byte *pbyUniqueID
   , BYVAL nulIDSize AS DWORD _                         ' __in ULONG nulIDSize
   , BYVAL nulDriveNumber AS DWORD _                    ' __in ULONG nulDriveNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecorderGUID ( _                           ' VTable offset = 16
     BYVAL pbyUniqueID AS BYTE PTR _                    ' __inout byte *pbyUniqueID
   , BYVAL ulBufferSize AS DWORD _                      ' __in ULONG ulBufferSize
   , BYREF pulReturnSizeRequired AS DWORD _             ' __out ULONG *pulReturnSizeRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecorderType ( _                           ' VTable offset = 20
     BYREF fTypeCode AS LONG _                          ' __out long *fTypeCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayNames ( _                           ' VTable offset = 24
     BYREF pbstrVendorID AS WSTRING _                   ' __inout BSTR *pbstrVendorID
   , BYREF pbstrProductID AS WSTRING _                  ' __inout BSTR *pbstrProductID
   , BYREF pbstrRevision AS WSTRING _                   ' __inout BSTR *pbstrRevision
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBasePnPID ( _                              ' VTable offset = 28
     BYREF pbstrBasePnPID AS WSTRING _                  ' __out BSTR *pbstrBasePnPID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 32
     BYREF pbstrPath AS WSTRING _                       ' __out BSTR *pbstrPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecorderProperties ( _                     ' VTable offset = 36
     BYREF ppPropStg AS IPropertyStorage _              ' __out IPropertyStorage **ppPropStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecorderProperties ( _                     ' VTable offset = 40
     BYVAL pPropStg AS IPropertyStorage _               ' __in IPropertyStorage *pPropStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecorderState ( _                          ' VTable offset = 44
     BYREF pulDevStateFlags AS DWORD _                  ' __out ULONG *pulDevStateFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenExclusive ( _                             ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryMediaType ( _                            ' VTable offset = 52
     BYREF fMediaType AS LONG _                         ' __out long *fMediaType
   , BYREF fMediaFlags AS LONG _                        ' __out long *fMediaFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryMediaInfo ( _                            ' VTable offset = 56
     BYREF pbSessions AS BYTE _                         ' __out byte *pbSessions
   , BYREF pbLastTrack AS BYTE _                        ' __out byte *pbLastTrack
   , BYREF ulStartAddress AS BYTE _                     ' __out ULONG *ulStartAddress
   , BYREF ulNextWritable AS DWORD _                    ' __out ULONG *ulNextWritable
   , BYREF ulFreeBlocks AS DWORD _                      ' __out ULONG *ulFreeBlocks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Eject ( _                                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Erase ( _                                     ' VTable offset = 64
     BYVAL bFullErase AS BYTE _                         ' __in boolean bFullErase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IEnumDiscRecorders
' IID = {9B1921E1-54AC-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' Enumerates all disc recorders supported by the active disc master format.
' ########################################################################################

INTERFACE IEnumDiscRecorders $IID_IEnumDiscRecorders

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRecorders AS DWORD _                        ' __in ULONG cRecorders
   , BYREF ppRecorder AS IDiscRecorder _                ' __out IDiscRecorder **ppRecorder
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cRecorders AS DWORD _                        ' __in ULONG cRecorders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDiscRecorders _               ' __out IEnumDiscRecorders **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IEnumDiscMasterFormats
' IID = {DDF445E1-54BA-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IEnumDiscMasterFormats $IID_IEnumDiscMasterFormats

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFormats AS DWORD _                          ' __in ULONG cFormats
   , BYREF lpiidFormatID AS GUID _                      ' __out LPIID lpiidFormatID
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cFormats AS DWORD _                          ' __in ULONG cFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDiscMasterFormats _           ' __out IEnumDiscMasterFormats **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IRedbookDiscMaster
' IID = {E3BC42CD-4E5C-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' The IRedbookDiscMaster interface enables the staging of an audio CD image. It represents
' one of the formats supported by MSDiscMasterObj, and it allows the creation of
' multi-track audio discs in Track-at-Once mode (fixed-size audio gaps).
' Tracks are created in the stash file, data is added to them, and then they are closed.
' Only one track is staged at a time; this is called the open track. The remaining tracks
' are closed and committed to the image, while the open track has available to it all the
' blocks that are not in use by closed tracks.
' When To Use
' Use this interface to stage a Redbook audio image.
' ########################################################################################

INTERFACE IRedbookDiscMaster $IID_IRedbookDiscMaster

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetTotalAudioTracks ( _                       ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long *pnTracks
   ' =====================================================================================
   METHOD GetTotalAudioBlocks ( _                       ' VTable offset = 16
   ) AS LONG                                            ' __retval_out long *pnBlocks
   ' =====================================================================================
   METHOD GetUsedAudioBlocks ( _                        ' VTable offset = 20
   ) AS LONG                                            ' __retval_out long *pnBlocks
   ' =====================================================================================
   METHOD GetAvailableAudioTrackBlocks ( _              ' VTable offset = 24
   ) AS LONG                                            ' __retval_out long *pnBlocks
   ' =====================================================================================
   METHOD GetAudioBlockSize ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pnBlockBytes
   ' =====================================================================================
   METHOD CreateAudioTrack ( _                          ' VTable offset = 32
     BYVAL nBlocks AS LONG _                            ' __in long nBlocks
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAudioTrackBlocks ( _                       ' VTable offset = 36
     BYVAL pby AS BYTE PTR _                            ' __in byte *pby
   , BYVAL cb AS LONG _                                 ' __in long cb
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseAudioTrack ( _                           ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IJolietDiscMaster
' IID = {E3BC42CE-4E5C-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' The IJolietDiscMaster interface enables the staging of a CD data disc. It represents one
' of the formats supported by MSDiscMasterObj, and it allows the creation of a single
' Track-at-Once data disc. The data is written to the disc with the Joliet and ISO-9660
' file systems.
' A temporary folder is constructed and added to the image. This can be repeated multiple
' times with the directory and file structures overlapping. The overlapping file
' structures appear seamlessly when read back. When the overwrite option is used,
' overlapping paths cause the last file added to show up in the directory, while the
' earlier files with conflicting names are still present on the disc but now not readable
' by normal means.
' ########################################################################################

INTERFACE IJolietDiscMaster $IID_IJolietDiscMaster

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetTotalDataBlocks ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long *pnBlocks
   ' =====================================================================================
   METHOD GetUsedDataBlocks ( _                         ' VTable offset = 16
   ) AS LONG                                            ' __retval_out long *pnBlocks
   ' =====================================================================================
   METHOD GetDataBlockSize ( _                          ' VTable offset = 20
   ) AS LONG                                            ' __retval_out long *pnBlockBytes
   ' =====================================================================================
   METHOD AddData ( _                                   ' VTable offset = 24
     BYVAL pStorage AS IStorage _                       ' __in IStorage *pStorage
   , BYVAL lFileOverwrite AS LONG _                     ' __in long lFileOverwrite
   )                                                    ' void
   ' =====================================================================================
   METHOD GetJolietProperties ( _                       ' VTable offset = 28
     BYREF ppPropStg AS IPropertyStorage _              ' __out IPropertyStorage **ppPropStg
   )                                                    ' void
   ' =====================================================================================
   METHOD SetJolietProperties ( _                       ' VTable offset = 32
     BYVAL pPropStg AS IPropertyStorage _               ' __in IPropertyStorage *pPropStg
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDiscMasterProgressEvents
' IID = {EC9E51C1-4E5D-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' The IDiscMasterProgressEvents interface provides a single interface for all callbacks
' that can be made from IMAPI to an application. An application implements this interface
' on one of its objects and then registers it using IDiscMaster.ProgressAdvise. All but
' one of the methods in this interface are related to progress during staging or burns.
' Even if an application is not interested in a particular callback, it must implement the
' callback function and return E_NOTIMPL on the call.
' ########################################################################################

'INTERFACE IDiscMasterProgressEvents $IID_IDiscMasterProgressEvents

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD QueryCancel ( _                               ' VTable offset = 12
'     BYVAL pbCancel AS BYTE _                           ' __retval_out boolean *pbCancel
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyPnPActivity ( _                         ' VTable offset = 16
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyAddProgress ( _                         ' VTable offset = 20
'     BYVAL nCompletedSteps AS LONG _                    ' __in long nCompletedSteps
'   , BYVAL nTotalSteps AS LONG _                        ' __in long nTotalSteps
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyBlockProgress ( _                       ' VTable offset = 24
'     BYVAL nCompleted AS LONG _                         ' __in long nCompleted
'   , BYVAL nTotal AS LONG _                             ' __in long nTotal
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyTrackProgress ( _                       ' VTable offset = 28
'     BYVAL nCurrentTrack AS LONG _                      ' __in long nCurrentTrack
'   , BYVAL nTotalTracks AS LONG _                       ' __in long nTotalTracks
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyPreparingBurn ( _                       ' VTable offset = 32
'     BYVAL nEstimatedSeconds AS LONG _                  ' __in long nEstimatedSeconds
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyClosingDisc ( _                         ' VTable offset = 36
'     BYVAL nEstimatedSeconds AS LONG _                  ' __in long nEstimatedSeconds
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyBurnComplete ( _                        ' VTable offset = 40
'     BYVAL status AS LONG _                             ' __in HRESULT status
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NotifyEraseComplete ( _                       ' VTable offset = 44
'     BYVAL status AS LONG _                             ' __in HRESULT status
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

' ########################################################################################
' Interface name = IDiscMaster
' IID = {520CCA62-51A5-11D3-9144-00104BA11C5E}
' Inherited interface = IUnknown
' The IDiscMaster interface allows an application to reserve an image mastering API,
' enumerate disc mastering formats and disc recorders supported by an image mastering
' object, and start a simulated or actual burn of a disc. Although an image mastering
' object can support several formats, it may not be possible to access all formats
' through a specific recorder. For this reason, you must select a recorder with
' SetActiveDiscRecorder after selecting a format with SetActiveDiscMasterFormat.
' ########################################################################################

INTERFACE IDiscMaster $IID_IDiscMaster

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDiscMasterFormats ( _                     ' VTable offset = 16
     BYREF ppEnum AS IEnumDiscMasterFormats _           ' __out IEnumDiscMasterFormats **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveDiscMasterFormat ( _                 ' VTable offset = 20
     BYREF lpiid AS GUID _                              ' __out LPIID lpiid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveDiscMasterFormat ( _                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppUnk AS IUnknown _                          ' __out void **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDiscRecorders ( _                         ' VTable offset = 28
     BYREF ppEnum AS IEnumDiscRecorders _               ' __out IEnumDiscRecorders **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveDiscRecorder ( _                     ' VTable offset = 32
     BYREF ppRecorder AS IDiscRecorder _                ' __out IDiscRecorder **ppRecorder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveDiscRecorder ( _                     ' VTable offset = 36
     BYVAL pRecorder AS IDiscRecorder _                 ' __in IDiscRecorder *pRecorder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearFormatContent ( _                        ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProgressAdvise ( _                            ' VTable offset = 44
     BYVAL pEvents AS IUnknown _                        ' __in IDiscMasterProgressEvents *pEvents
   , BYREF pvCookie AS DWORD _                          ' __retval_out UINT_PTR *pvCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProgressUnadvise ( _                          ' VTable offset = 48
     BYVAL vCookie AS DWORD _                           ' __in UINT_PTR vCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordDisc ( _                                ' VTable offset = 52
     BYVAL bSimulate AS BYTE _                          ' __in boolean bSimulate
   , BYVAL bEjectAfterBurn AS BYTE _                    ' __in boolean bEjectAfterBurn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
