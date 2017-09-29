' ########################################################################################
' Microsoft Windows
' File: WinCodecSdk.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINCODECSDK_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "wincodec.inc"

$GUID_MetadataFormatUnknown                = GUID$("{A45E592F-9078-4A7C-ADB5-4EDC4FD6011F}")
$GUID_MetadataFormatIfd                    = GUID$("{537396C6-2D8A-4BB6-9BF8-2F0A8E2A3ADF}")
$GUID_MetadataFormatSubIfd                 = GUID$("{58A2E128-2DB9-4E57-BB14-5177891ED331}")
$GUID_MetadataFormatExif                   = GUID$("{1C3C4F9D-B84A-467D-9493-36CFBD59EA57}")
$GUID_MetadataFormatGps                    = GUID$("{7134AB8A-9351-44AD-AF62-448DB6B502EC}")
$GUID_MetadataFormatInterop                = GUID$("{ED686F8E-681F-4C8B-BD41-A8ADDBF6B3FC}")
$GUID_MetadataFormatApp0                   = GUID$("{79007028-268D-45d6-A3C2-354E6A5004C9}")
$GUID_MetadataFormatApp1                   = GUID$("{8FD3DFC3-F951-492B-817F-69C2E6D9A5B0}")
$GUID_MetadataFormatApp13                  = GUID$("{326556A2-F502-4354-9CC0-8E3F48EAF6B5}")
$GUID_MetadataFormatIPTC                   = GUID$("{4FAB0914-E129-4087-A1D1-BC812D45A7B5}")
$GUID_MetadataFormatIRB                    = GUID$("{16100D66-8570-4BB9-B92D-FDA4B23ECE67}")
$GUID_MetadataFormat8BIMIPTC               = GUID$("{0010568c-0852-4e6a-b191-5c33ac5b0430}")
$GUID_MetadataFormat8BIMResolutionInfo     = GUID$("{739F305D-81DB-43CB-AC5E-55013EF9F003}")
$GUID_MetadataFormat8BIMIPTCDigest         = GUID$("{1CA32285-9CCD-4786-8BD8-79539DB6A006}")
$GUID_MetadataFormatXMP                    = GUID$("{BB5ACC38-F216-4CEC-A6C5-5F6E739763A9}")
$GUID_MetadataFormatThumbnail              = GUID$("{243dcee9-8703-40ee-8ef0-22a600b8058c}")
$GUID_MetadataFormatChunktEXt              = GUID$("{568d8936-c0a9-4923-905d-df2b38238fbc}")
$GUID_MetadataFormatXMPStruct              = GUID$("{22383CF1-ED17-4E2E-AF17-D85B8F6B30D0}")
$GUID_MetadataFormatXMPBag                 = GUID$("{833CCA5F-DCB7-4516-806F-6596AB26DCE4}")
$GUID_MetadataFormatXMPSeq                 = GUID$("{63E8DF02-EB6C-456C-A224-B25E794FD648}")
$GUID_MetadataFormatXMPAlt                 = GUID$("{7B08A675-91AA-481B-A798-4DA94908613B}")
$GUID_MetadataFormatLSD                    = GUID$("{E256031E-6299-4929-B98D-5AC884AFBA92}")
$GUID_MetadataFormatIMD                    = GUID$("{BD2BB086-4D52-48DD-9677-DB483E85AE8F}")
$GUID_MetadataFormatGCE                    = GUID$("{2A25CAD8-DEEB-4C69-A788-0EC2266DCAFD}")
$GUID_MetadataFormatAPE                    = GUID$("{2E043DC2-C967-4E05-875E-618BF67E85C3}")
$GUID_MetadataFormatJpegChrominance        = GUID$("{F73D0DCF-CEC6-4F85-9B0E-1C3956B1BEF7}")
$GUID_MetadataFormatJpegLuminance          = GUID$("{86908007-EDFC-4860-8D4B-4EE6E83E6058}")
$GUID_MetadataFormatJpegComment            = GUID$("{220E5F33-AFD3-474E-9D31-7D4FE730F557}")
$GUID_MetadataFormatGifComment             = GUID$("{C4B6E0E0-CFB4-4AD3-AB33-9AAD2355A34A}")
$GUID_MetadataFormatChunkgAMA              = GUID$("{F00935A5-1D5D-4CD1-81B2-9324D7ECA781}")
$GUID_MetadataFormatChunkbKGD              = GUID$("{E14D3571-6B47-4DEA-B60A-87CE0A78DFB7}")
$GUID_MetadataFormatChunkiTXt              = GUID$("{C2BEC729-0B68-4B77-AA0E-6295A6AC1814}")
$GUID_MetadataFormatChunkcHRM              = GUID$("{9DB3655B-2842-44B3-8067-12E9B375556A}")
$GUID_MetadataFormatChunkhIST              = GUID$("{C59A82DA-DB74-48A4-BD6A-B69C4931EF95}")
$GUID_MetadataFormatChunkiCCP              = GUID$("{EB4349AB-B685-450F-91B5-E802E892536C}")
$GUID_MetadataFormatChunksRGB              = GUID$("{C115FD36-CC6F-4E3F-8363-524B87C6B0D9}")
$GUID_MetadataFormatChunktIME              = GUID$("{6B00AE2D-E24B-460A-98B6-878BD03072FD}")
$CLSID_WICUnknownMetadataReader            = GUID$("{699745c2-5066-4b82-a8e3-d40478dbec8c}")
$CLSID_WICUnknownMetadataWriter            = GUID$("{a09cca86-27ba-4f39-9053-121fa4dc08fc}")
$CLSID_WICApp0MetadataWriter               = GUID$("{F3C633A2-46C8-498e-8FBB-CC6F721BBCDE}")
$CLSID_WICApp0MetadataReader               = GUID$("{43324B33-A78F-480f-9111-9638AACCC832}")
$CLSID_WICApp1MetadataWriter               = GUID$("{ee366069-1832-420f-b381-0479ad066f19}")
$CLSID_WICApp1MetadataReader               = GUID$("{dde33513-774e-4bcd-ae79-02f4adfe62fc}")
$CLSID_WICApp13MetadataWriter              = GUID$("{7B19A919-A9D6-49E5-BD45-02C34E4E4CD5}")
$CLSID_WICApp13MetadataReader              = GUID$("{AA7E3C50-864C-4604-BC04-8B0B76E637F6}")
$CLSID_WICIfdMetadataReader                = GUID$("{8f914656-9d0a-4eb2-9019-0bf96d8a9ee6}")
$CLSID_WICIfdMetadataWriter                = GUID$("{b1ebfc28-c9bd-47a2-8d33-b948769777a7}")
$CLSID_WICSubIfdMetadataReader             = GUID$("{50D42F09-ECD1-4B41-B65D-DA1FDAA75663}")
$CLSID_WICSubIfdMetadataWriter             = GUID$("{8ADE5386-8E9B-4F4C-ACF2-F0008706B238}")
$CLSID_WICExifMetadataReader               = GUID$("{d9403860-297f-4a49-bf9b-77898150a442}")
$CLSID_WICExifMetadataWriter               = GUID$("{c9a14cda-c339-460b-9078-d4debcfabe91}")
$CLSID_WICGpsMetadataReader                = GUID$("{3697790B-223B-484E-9925-C4869218F17A}")
$CLSID_WICGpsMetadataWriter                = GUID$("{CB8C13E4-62B5-4C96-A48B-6BA6ACE39C76}")
$CLSID_WICInteropMetadataReader            = GUID$("{B5C8B898-0074-459F-B700-860D4651EA14}")
$CLSID_WICInteropMetadataWriter            = GUID$("{122EC645-CD7E-44D8-B186-2C8C20C3B50F}")
$CLSID_WICThumbnailMetadataReader          = GUID$("{fb012959-f4f6-44d7-9d09-daa087a90d57}")
$CLSID_WICThumbnailMetadataWriter          = GUID$("{d049b20c-5dd0-44fe-b0b3-8f92c8e6d080}")
$CLSID_WICIPTCMetadataReader               = GUID$("{03012959-f4f6-44d7-9d09-daa087a90d57}")
$CLSID_WICIPTCMetadataWriter               = GUID$("{1249b20c-5dd0-44fe-b0b3-8f92c8e6d080}")
$CLSID_WICIRBMetadataReader                = GUID$("{D4DCD3D7-B4C2-47D9-A6BF-B89BA396A4A3}")
$CLSID_WICIRBMetadataWriter                = GUID$("{5C5C1935-0235-4434-80BC-251BC1EC39C6}")
$CLSID_WIC8BIMIPTCMetadataReader           = GUID$("{0010668c-0801-4da6-a4a4-826522b6d28f}")
$CLSID_WIC8BIMIPTCMetadataWriter           = GUID$("{00108226-ee41-44a2-9e9c-4be4d5b1d2cd}")
$CLSID_WIC8BIMResolutionInfoMetadataReader = GUID$("{5805137A-E348-4F7C-B3CC-6DB9965A0599}")
$CLSID_WIC8BIMResolutionInfoMetadataWriter = GUID$("{4ff2fe0e-e74a-4b71-98c4-ab7dc16707ba}")
$CLSID_WIC8BIMIPTCDigestMetadataReader     = GUID$("{02805F1E-D5AA-415b-82C5-61C033A988A6}")
$CLSID_WIC8BIMIPTCDigestMetadataWriter     = GUID$("{2DB5E62B-0D67-495f-8F9D-C2F0188647AC}")
$CLSID_WICPngTextMetadataReader            = GUID$("{4b59afcc-b8c3-408a-b670-89e5fab6fda7}")
$CLSID_WICPngTextMetadataWriter            = GUID$("{b5ebafb9-253e-4a72-a744-0762d2685683}")
$CLSID_WICXMPMetadataReader                = GUID$("{72B624DF-AE11-4948-A65C-351EB0829419}")
$CLSID_WICXMPMetadataWriter                = GUID$("{1765E14E-1BD4-462E-B6B1-590BF1262AC6}")
$CLSID_WICXMPStructMetadataReader          = GUID$("{01B90D9A-8209-47F7-9C52-E1244BF50CED}")
$CLSID_WICXMPStructMetadataWriter          = GUID$("{22C21F93-7DDB-411C-9B17-C5B7BD064ABC}")
$CLSID_WICXMPBagMetadataReader             = GUID$("{E7E79A30-4F2C-4FAB-8D00-394F2D6BBEBE}")
$CLSID_WICXMPBagMetadataWriter             = GUID$("{ED822C8C-D6BE-4301-A631-0E1416BAD28F}")
$CLSID_WICXMPSeqMetadataReader             = GUID$("{7F12E753-FC71-43D7-A51D-92F359770AB5}")
$CLSID_WICXMPSeqMetadataWriter             = GUID$("{6D68D1DE-D432-4B0F-923A-091183A9BDA7}")
$CLSID_WICXMPAltMetadataReader             = GUID$("{AA94DCC2-B8B0-4898-B835-000AABD74393}")
$CLSID_WICXMPAltMetadataWriter             = GUID$("{076C2A6C-F78F-4C46-A723-3583E70876EA}")
$CLSID_WICLSDMetadataReader                = GUID$("{41070793-59E4-479A-A1F7-954ADC2EF5FC}")
$CLSID_WICLSDMetadataWriter                = GUID$("{73C037E7-E5D9-4954-876A-6DA81D6E5768}")
$CLSID_WICGCEMetadataReader                = GUID$("{B92E345D-F52D-41F3-B562-081BC772E3B9}")
$CLSID_WICGCEMetadataWriter                = GUID$("{AF95DC76-16B2-47F4-B3EA-3C31796693E7}")
$CLSID_WICIMDMetadataReader                = GUID$("{7447A267-0015-42C8-A8F1-FB3B94C68361}")
$CLSID_WICIMDMetadataWriter                = GUID$("{8C89071F-452E-4E95-9682-9D1024627172}")
$CLSID_WICAPEMetadataReader                = GUID$("{1767B93A-B021-44EA-920F-863C11F4F768}")
$CLSID_WICAPEMetadataWriter                = GUID$("{BD6EDFCA-2890-482F-B233-8D7339A1CF8D}")
$CLSID_WICJpegChrominanceMetadataReader    = GUID$("{50B1904B-F28F-4574-93F4-0BADE82C69E9}")
$CLSID_WICJpegChrominanceMetadataWriter    = GUID$("{3FF566F0-6E6B-49D4-96E6-B78886692C62}")
$CLSID_WICJpegLuminanceMetadataReader      = GUID$("{356F2F88-05A6-4728-B9A4-1BFBCE04D838}")
$CLSID_WICJpegLuminanceMetadataWriter      = GUID$("{1D583ABC-8A0E-4657-9982-A380CA580F4B}")
$CLSID_WICJpegCommentMetadataReader        = GUID$("{9f66347C-60C4-4C4D-AB58-D2358685f607}")
$CLSID_WICJpegCommentMetadataWriter        = GUID$("{E573236F-55B1-4EDA-81EA-9F65DB0290D3}")
$CLSID_WICGifCommentMetadataReader         = GUID$("{32557D3B-69DC-4F95-836E-F5972B2F6159}")
$CLSID_WICGifCommentMetadataWriter         = GUID$("{A02797fC-C4AE-418C-AF95-E637C7EAD2A1}")
$CLSID_WICPngGamaMetadataReader            = GUID$("{3692CA39-E082-4350-9E1F-3704CB083CD5}")
$CLSID_WICPngGamaMetadataWriter            = GUID$("{FF036D13-5D4B-46DD-B10F-106693D9FE4F}")
$CLSID_WICPngBkgdMetadataReader            = GUID$("{0CE7A4A6-03E8-4A60-9D15-282EF32EE7DA}")
$CLSID_WICPngBkgdMetadataWriter            = GUID$("{68E3F2FD-31AE-4441-BB6A-FD7047525F90}")
$CLSID_WICPngItxtMetadataReader            = GUID$("{AABFB2FA-3E1E-4A8F-8977-5556FB94EA23}")
$CLSID_WICPngItxtMetadataWriter            = GUID$("{31879719-E751-4DF8-981D-68DFF67704ED}")
$CLSID_WICPngChrmMetadataReader            = GUID$("{F90B5F36-367B-402A-9DD1-BC0FD59D8F62}")
$CLSID_WICPngChrmMetadataWriter            = GUID$("{E23CE3EB-5608-4E83-BCEF-27B1987E51D7}")
$CLSID_WICPngHistMetadataReader            = GUID$("{877A0BB7-A313-4491-87B5-2E6D0594F520}")
$CLSID_WICPngHistMetadataWriter            = GUID$("{8A03E749-672E-446E-BF1F-2C11D233B6FF}")
$CLSID_WICPngIccpMetadataReader            = GUID$("{F5D3E63B-CB0F-4628-A478-6D8244BE36B1}")
$CLSID_WICPngIccpMetadataWriter            = GUID$("{16671E5F-0CE6-4CC4-9768-E89FE5018ADE}")
$CLSID_WICPngSrgbMetadataReader            = GUID$("{FB40360C-547E-4956-A3B9-D4418859BA66}")
$CLSID_WICPngSrgbMetadataWriter            = GUID$("{A6EE35C6-87EC-47DF-9F22-1D5AAD840C82}")
$CLSID_WICPngTimeMetadataReader            = GUID$("{D94EDF02-EFE5-4F0D-85C8-F5A68B3000B1}")
$CLSID_WICPngTimeMetadataWriter            = GUID$("{1AB78400-B5A3-4D91-8ACE-33FCD14909E6}")


' enum WICMetadataCreationOptions
%WICMetadataCreationDefault      = 0
%WICMetadataCreationAllowUnknown = %WICMetadataCreationDefault
%WICMetadataCreationFailUnknown  = &H10000???
%WICMetadataCreationMask         = &Hffff0000???

' enum WICPersistOptions
%WICPersistOptionDefault         = 0
%WICPersistOptionLittleEndian    = 0
%WICPersistOptionBigEndian       = &H1???
%WICPersistOptionStrictFormat    = &H2???
%WICPersistOptionNoCacheStream   = &H4???
%WICPersistOptionPreferUTF8      = &H8???
%WICPersistOptionMask            = &Hffff???

' ########################################################################################
' Interface name = IWICMetadataBlockReader
' IID = FEAA2A8D-B3F3-43E4-B25C-D1DE990A1AE1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICMetadataBlockReader_INTERFACE_DEFINED)
    %IWICMetadataBlockReader_INTERFACE_DEFINED = 1

$IID_IWICMetadataBlockReader = GUID$("{FEAA2A8D-B3F3-43E4-B25C-D1DE990A1AE1}")

INTERFACE IWICMetadataBlockReader $IID_IWICMetadataBlockReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 12
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
     BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReaderByIndex ( _                          ' VTable offset = 20
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppIMetadataReader AS IWICMetadataReader _    ' __out IWICMetadataReader **ppIMetadataReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 24
     BYREF ppIEnumMetadata AS IEnumUnknown _            ' __out IEnumUnknown **ppIEnumMetadata
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataBlockReader_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICMetadataBlockWriter
' IID = 08FB9676-B444-41E8-8DBE-6A53A542BFF1
' Inherited interface = IWICMetadataBlockReader
' ########################################################################################

#IF NOT %DEF(%IWICMetadataBlockWriter_INTERFACE_DEFINED)
    %IWICMetadataBlockWriter_INTERFACE_DEFINED = 1

$IID_IWICMetadataBlockWriter = GUID$("{08FB9676-B444-41E8-8DBE-6A53A542BFF1}")

INTERFACE IWICMetadataBlockWriter $IID_IWICMetadataBlockWriter

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICMetadataBlockReader methods
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 12
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
     BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReaderByIndex ( _                          ' VTable offset = 20
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppIMetadataReader AS IWICMetadataReader _    ' __out IWICMetadataReader **ppIMetadataReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 24
     BYREF ppIEnumMetadata AS IEnumUnknown _            ' __out IEnumUnknown **ppIEnumMetadata
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataBlockWriter methods
   ' =====================================================================================
   METHOD InitializeFromBlockReader ( _                 ' VTable offset = 28
     BYVAL pIMDBlockReader AS IWICMetadataBlockReader _ ' __in IWICMetadataBlockReader *pIMDBlockReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWriterByIndex ( _                          ' VTable offset = 32
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF ppIMetadataWriter AS IWICMetadataWriter _    ' __out IWICMetadataWriter **ppIMetadataWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddWriter ( _                                 ' VTable offset = 36
     BYVAL pIMetadataWriter AS IWICMetadataWriter _     ' __in IWICMetadataWriter *pIMetadataWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWriterByIndex ( _                          ' VTable offset = 40
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYVAL pIMetadataWriter AS IWICMetadataWriter _     ' __in IWICMetadataWriter **pIMetadataWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveWriterByIndex ( _                       ' VTable offset = 44
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataBlockWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICMetadataReader
' IID = 9204FE99-D8FC-4FD5-A001-9536B067A899
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICMetadataReader_INTERFACE_DEFINED)
    %IWICMetadataReader_INTERFACE_DEFINED = 1

$IID_IWICMetadataReader = GUID$("{9204FE99-D8FC-4FD5-A001-9536B067A899}")

INTERFACE IWICMetadataReader $IID_IWICMetadataReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMetadataFormat ( _                         ' VTable offset = 12
     BYREF pguidMetadataFormat AS GUID _                ' __out GUID *pguidMetadataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataHandlerInfo ( _                    ' VTable offset = 16
     BYREF ppIHandler AS IWICMetadataHandlerInfo _      ' __out IWICMetadataHandlerInfo **ppIHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 20
     BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueByIndex ( _                           ' VTable offset = 24
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF pvarSchema AS PROPVARIANT _                  ' __inout_opt PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __inout_opt PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout_opt PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 28
     BYREF pvarSchema AS PROPVARIANT _                  ' __in_opt const PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __in const PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout_opt PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 32
     BYREF ppIEnumMetadata AS IWICEnumMetadataItem _    ' __out IWICEnumMetadataItem **ppIEnumMetadata
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataReader_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICMetadataWriter
' IID = F7836E16-3BE0-470B-86BB-160D0AECD7DE
' Inherited interface = IWICMetadataReader
' ########################################################################################

#IF NOT %DEF(%IWICMetadataWriter_INTERFACE_DEFINED)
    %IWICMetadataWriter_INTERFACE_DEFINED = 1

$IID_IWICMetadataWriter = GUID$("{F7836E16-3BE0-470B-86BB-160D0AECD7DE}")

INTERFACE IWICMetadataWriter $IID_IWICMetadataWriter

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICMetadataReader methods
   ' =====================================================================================
   METHOD GetMetadataFormat ( _                         ' VTable offset = 12
     BYREF pguidMetadataFormat AS GUID _                ' __out GUID *pguidMetadataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataHandlerInfo ( _                    ' VTable offset = 16
     BYREF ppIHandler AS IWICMetadataHandlerInfo _      ' __out IWICMetadataHandlerInfo **ppIHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 20
     BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueByIndex ( _                           ' VTable offset = 24
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF pvarSchema AS PROPVARIANT _                  ' __inout_opt PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __inout_opt PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout_opt PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 28
     BYREF pvarSchema AS PROPVARIANT _                  ' __in_opt const PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __in const PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout_opt PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 32
     BYREF ppIEnumMetadata AS IWICEnumMetadataItem _    ' __out IWICEnumMetadataItem **ppIEnumMetadata
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataWriter methods
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYREF pvarSchema AS PROPVARIANT _                  ' __in_opt const PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __in const PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __in const PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueByIndex ( _                           ' VTable offset = 40
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF pvarSchema AS PROPVARIANT _                  ' __in_opt const PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __in const PROPVARIANT *pvarId
   , BYREF pvarValue AS PROPVARIANT _                   ' __in const PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveValue ( _                               ' VTable offset = 44
     BYREF pvarSchema AS PROPVARIANT _                  ' __in_opt const PROPVARIANT *pvarSchema
   , BYREF pvarId AS PROPVARIANT _                      ' __in const PROPVARIANT *pvarId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveValueByIndex ( _                        ' VTable offset = 48
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICStreamProvider
' IID = 449494BC-B468-4927-96D7-BA90D31AB505
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICStreamProvider_INTERFACE_DEFINED)
    %IWICStreamProvider_INTERFACE_DEFINED = 1

$IID_IWICStreamProvider = GUID$("{449494BC-B468-4927-96D7-BA90D31AB505}")

INTERFACE IWICStreamProvider $IID_IWICStreamProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 12
     BYREF ppIStream AS IStream _                       ' __out IStream **ppIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPersistOptions ( _                         ' VTable offset = 16
     BYREF pdwPersistOptions AS DWORD _                 ' __out DWORD *pdwPersistOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreferredVendorGUID ( _                    ' VTable offset = 20
     BYREF pguidPreferredVendor AS GUID _               ' __out GUID *pguidPreferredVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshStream ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICStreamProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICPersistStream
' IID = 00675040-6908-45F8-86A3-49C7DFD6D9AD
' Inherited interface = IPersistStream
' ########################################################################################

#IF NOT %DEF(%IWICPersistStream_INTERFACE_DEFINED)
    %IWICPersistStream_INTERFACE_DEFINED = 1

$IID_IWICPersistStream = GUID$("{00675040-6908-45F8-86A3-49C7DFD6D9AD}")

INTERFACE IWICPersistStream $IID_IWICPersistStream

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersistStream methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICPersistStream methods
   ' =====================================================================================
   METHOD LoadEx ( _                                    ' VTable offset = 32
     BYVAL pIStream AS IStream _                        ' __in_opt IStream *pIStream
   , BYREF pguidPreferredVendor AS GUID _               ' __in_opt const GUID *pguidPreferredVendor
   , BYVAL dwPersistOptions AS DWORD _                  ' __in DWORD dwPersistOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveEx ( _                                    ' VTable offset = 36
     BYVAL pIStream AS IStream _                        ' __in_opt IStream *pIStream
   , BYVAL dwPersistOptions AS DWORD _                  ' __in DWORD dwPersistOptions
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICPersistStream_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICMetadataHandlerInfo
' IID = ABA958BF-C672-44D1-8D61-CE6DF2E682C2
' Inherited interface = IWICComponentInfo
' ########################################################################################

#IF NOT %DEF(%IWICMetadataHandlerInfo_INTERFACE_DEFINED)
    %IWICMetadataHandlerInfo_INTERFACE_DEFINED = 1

$IID_IWICMetadataHandlerInfo = GUID$("{ABA958BF-C672-44D1-8D61-CE6DF2E682C2}")

INTERFACE IWICMetadataHandlerInfo $IID_IWICMetadataHandlerInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataHandlerInfo methods
   ' =====================================================================================
   METHOD GetMetadataFormat ( _                         ' VTable offset = 44
     BYREF pguidMetadataFormat AS GUID _                ' __out GUID *pguidMetadataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormats ( _                       ' VTable offset = 48
     BYVAL cContainerFormats AS DWORD _                 ' __in UINT cContainerFormats
   , BYREF pguidContainerFormats AS GUID _              ' __inout GUID *pguidContainerFormats
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 52
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 56
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFullStream ( _                     ' VTable offset = 60
     BYREF pfRequiresFullStream AS LONG _               ' __out BOOL *pfRequiresFullStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportPadding ( _                        ' VTable offset = 64
     BYREF pfSupportsPadding AS LONG _                  ' __out BOOL *pfSupportsPadding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFixedSize ( _                      ' VTable offset = 68
     BYREF pfFixedSize AS LONG _                        ' __out BOOL *pfFixedSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataHandlerInfo_INTERFACE_DEFINED__ */

' // Size = 32 bytes
TYPE WICMetadataPattern QWORD FILL   ' Must be 8 byte aligned
   Position   AS QUAD       ' ULARGE_INTEGER
   Length     AS DWORD      ' ULONG
   Pattern    AS BYTE PTR   ' BYTE *
   Mask       AS BYTE PTR   ' BYTE *
   DataOffset AS QUAD       ' ULARGE_INTEGER
END TYPE

' ########################################################################################
' Interface name = IWICMetadataReaderInfo
' IID = EEBF1F5B-07C1-4447-A3AB-22ACAF78A804
' Inherited interface = IWICMetadataHandlerInfo
' ########################################################################################

#IF NOT %DEF(%IWICMetadataReaderInfo_INTERFACE_DEFINED)
    %IWICMetadataReaderInfo_INTERFACE_DEFINED = 1

$IID_IWICMetadataReaderInfo = GUID$("{EEBF1F5B-07C1-4447-A3AB-22ACAF78A804}")

INTERFACE IWICMetadataReaderInfo $IID_IWICMetadataReaderInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataHandlerInfo methods
   ' =====================================================================================
   METHOD GetMetadataFormat ( _                         ' VTable offset = 44
     BYREF pguidMetadataFormat AS GUID _                ' __out GUID *pguidMetadataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormats ( _                       ' VTable offset = 48
     BYVAL cContainerFormats AS DWORD _                 ' __in UINT cContainerFormats
   , BYREF pguidContainerFormats AS GUID _              ' __inout GUID *pguidContainerFormats
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 52
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 56
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFullStream ( _                     ' VTable offset = 60
     BYREF pfRequiresFullStream AS LONG _               ' __out BOOL *pfRequiresFullStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportPadding ( _                        ' VTable offset = 64
     BYREF pfSupportsPadding AS LONG _                  ' __out BOOL *pfSupportsPadding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFixedSize ( _                      ' VTable offset = 68
     BYREF pfFixedSize AS LONG _                        ' __out BOOL *pfFixedSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataReaderInfo methods
   ' =====================================================================================
   METHOD GetPatterns ( _                               ' VTable offset = 72
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYVAL cbSize AS DWORD _                            ' __in UINT cbSize
   , BYREF pPattern AS WICMetadataPattern _             ' __out WICMetadataPattern *pPattern
   , BYREF pcCount AS DWORD _                           ' __out_opt UINT *pcCount
   , BYREF pcbActual AS DWORD _                         ' __out_opt UINT *pcbActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesPattern ( _                            ' VTable offset = 76
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYVAL pIStream AS IStream _                        ' __in_opt IStream *pIStream
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 80
     BYREF ppIReader AS IWICMetadataReader _            ' __out_opt IWICMetadataReader **ppIReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataReaderInfo_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE WICMetadataHeader QWORD FILL   ' Must be 8 byte aligned
   Position   AS QUAD       ' ULARGE_INTEGER
   Length     AS DWORD      ' ULONG
   Header     AS BYTE PTR   ' BYTE *
   DataOffset AS QUAD       ' ULARGE_INTEGER
END TYPE

' ########################################################################################
' Interface name = IWICMetadataWriterInfo
' IID = B22E3FBA-3925-4323-B5C1-9EBFC430F236
' Inherited interface = IWICMetadataHandlerInfo
' ########################################################################################

#IF NOT %DEF(%IWICMetadataWriterInfo_INTERFACE_DEFINED_)
    %IWICMetadataWriterInfo_INTERFACE_DEFINED = 1

$IID_IWICMetadataWriterInfo = GUID$("{B22E3FBA-3925-4323-B5C1-9EBFC430F236}")

INTERFACE IWICMetadataWriterInfo $IID_IWICMetadataWriterInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataHandlerInfo methods
   ' =====================================================================================
   METHOD GetMetadataFormat ( _                         ' VTable offset = 44
     BYREF pguidMetadataFormat AS GUID _                ' __out GUID *pguidMetadataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormats ( _                       ' VTable offset = 48
     BYVAL cContainerFormats AS DWORD _                 ' __in UINT cContainerFormats
   , BYREF pguidContainerFormats AS GUID _              ' __inout GUID *pguidContainerFormats
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 52
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 56
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFullStream ( _                     ' VTable offset = 60
     BYREF pfRequiresFullStream AS LONG _               ' __out BOOL *pfRequiresFullStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportPadding ( _                        ' VTable offset = 64
     BYREF pfSupportsPadding AS LONG _                  ' __out BOOL *pfSupportsPadding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesRequireFixedSize ( _                      ' VTable offset = 68
     BYREF pfFixedSize AS LONG _                        ' __out BOOL *pfFixedSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataWriterInfo methods
   ' =====================================================================================
   METHOD GetHeader ( _                                 ' VTable offset = 72
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYVAL cbSize AS DWORD _                            ' __in UINT cbSize
   , BYREF pHeader AS WICMetadataHeader _               ' __out_opt WICMetadataHeader *pHeader
   , BYREF pcbActual AS DWORD _                         ' __out_opt UINT *pcbActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 76
     BYREF ppIWriter AS IWICMetadataWriter _            ' __out_opt IWICMetadataWriter **ppIWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataWriterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWICComponentFactory
' IID = 412D0C3A-9650-44FA-AF5B-DD2A06C8E8FB
' Inherited interface = IWICImagingFactory
' ########################################################################################

#IF NOT %DEF(%IWICComponentFactory_INTERFACE_DEFINED)
    %IWICComponentFactory_INTERFACE_DEFINED = 1

$IID_IWICComponentFactory = GUID$("{412D0C3A-9650-44FA-AF5B-DD2A06C8E8FB}")

INTERFACE IWICComponentFactory $IID_IWICComponentFactory

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICImagingFactory methods
   ' =====================================================================================
   METHOD CreateDecoderFromFilename ( _                 ' VTable offset = 12
     BYREF wzFilename AS WSTRINGZ _                     ' __in LPCWSTR wzFilename
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL dwDesiredAccess AS DWORD _                   ' __in DWORD dwDesiredAccess
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoderFromStream ( _                   ' VTable offset = 16
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoderFromFileHandle ( _               ' VTable offset = 20
     BYVAL hFile AS DWORD _                             ' __in ULONG_PTR hFile
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentInfo ( _                       ' VTable offset = 24
     BYREF clsidComponent AS GUID _                     ' __in REFCLSID clsidComponent
   , BYREF ppIInfo AS IWICComponentInfo _               ' __out IWICComponentInfo **ppIInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoder ( _                             ' VTable offset = 28
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEncoder ( _                             ' VTable offset = 32
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 28
     BYREF ppIPalette AS IWICPalette _                  ' __out IWICPalette **ppIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFormatConverter ( _                     ' VTable offset = 32
     BYREF ppIFormatConverter AS IWICFormatConverter _  ' __out IWICFormatConverter **ppIFormatConverter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapScaler ( _                        ' VTable offset = 36
     BYREF ppIBitmapScaler AS IWICBitmapScaler _        ' __out IWICBitmapScaler **ppIBitmapScaler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapClipper ( _                       ' VTable offset = 40
     BYREF ppIBitmapClipper AS IWICBitmapClipper _      ' __out IWICBitmapClipper **ppIBitmapClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFlipRotator ( _                   ' VTable offset = 44
     BYREF ppIBitmapFlipRotator AS IWICBitmapFlipRotator _ ' __out IWICBitmapFlipRotator **ppIBitmapFlipRotator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 48
     BYREF ppIWICStream AS IWICStream _                 ' __out IWICStream **ppIWICStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateColorContext ( _                        ' VTable offset = 52
     BYREF ppIWICColorContext AS IWICColorContext _     ' __out IWICColorContext **ppIWICColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateColorTransformer ( _                    ' VTable offset = 56
     BYREF ppIWICColorTransform AS IWICColorTransform _ ' __out IWICColorTransform **ppIWICColorTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 60
     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromSource ( _                    ' VTable offset = 64
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromSourceRect ( _                ' VTable offset = 68
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYVAL x AS DWORD _                                 ' __in UINT x
   , BYVAL y AS DWORD _                                 ' __in UINT y
   , BYVAL width AS DWORD _                             ' __in UINT width
   , BYVAL height AS DWORD _                            ' __in UINT height
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromMemory ( _                    ' VTable offset = 72
     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromHBITMAP ( _                   ' VTable offset = 76
     BYVAL hBitmap AS DWORD _                           ' __in HBITMAP hBitmap
   , BYVAL hPalette AS DWORD _                          ' __in HPALETTE hPalette
   , BYVAL options AS DWORD _                           ' __in WICBitmapAlphaChannelOption options
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromHICON ( _                     ' VTable offset = 80
     BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentEnumerator ( _                 ' VTable offset = 84
     BYVAL componentTypes AS DWORD _                    ' __in DWORD componentTypes
   , BYVAL options AS DWORD _                           ' __in DWORD options
   , BYREF ppIEnumUnknown AS IEnumUnknown _             ' __out IEnumUnknown **ppIEnumUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFastMetadataEncoderFromDecoder ( _      ' VTable offset = 88
     BYVAL pIDecoder AS IWICBitmapDecoder _             ' __in IWICBitmapDecoder *pIDecoder
   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFastMetadataEncoderFromFrameDecode ( _  ' VTable offset = 92
     BYVAL pIFrameDecoder AS IWICBitmapFrameDecode _    ' __in IWICBitmapFrameDecode *pIFrameDecoder
   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryWriter ( _                         ' VTable offset = 96
     BYREF guidMetadataFormat AS GUID _                 ' __in REFGUID guidMetadataFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryWriterFromReader ( _               ' VTable offset = 100
     BYVAL pIQueryReader AS IWICMetadataQueryReader _   ' __in IWICMetadataQueryReader *pIQueryReader
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICComponentFactory methods
   ' =====================================================================================
   METHOD CreateMetadataReader ( _                      ' VTable offset = 104
     BYREF guidMetadataFormat AS GUID _                 ' __in REFGUID guidMetadataFormat
   , BYREF pguidVendor AS GUID _                        ' __in_opt const GUID *pguidVendor
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   , BYVAL pIStream AS IStream _                        ' __in_opt IStream *pIStream
   , BYREF ppIReader AS IWICMetadataReader _            ' __out_opt IWICMetadataReader **ppIReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMetadataReaderFromContainer ( _         ' VTable offset = 108
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYREF pguidVendor AS GUID _                        ' __in_opt const GUID *pguidVendor
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   , BYVAL pIStream AS IStream _                        ' __in_opt IStream *pIStream
   , BYREF ppIReader AS IWICMetadataReader _            ' __out_opt IWICMetadataReader **ppIReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMetadataWriter ( _                      ' VTable offset = 112
     BYREF guidMetadataFormat AS GUID _                 ' __in REFGUID guidMetadataFormat
   , BYREF pguidVendor AS GUID _                        ' __in_opt const GUID *pguidVendor
   , BYVAL dwMetadataOptions AS DWORD _                 ' __in DWORD dwMetadataOptions
   , BYREF ppIWriter AS IWICMetadataWriter _            ' __out_opt IWICMetadataWriter **ppIWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMetadataWriterFromReader ( _            ' VTable offset = 116
     BYVAL pIReader AS IWICMetadataReader _             ' __in_opt IWICMetadataReader *pIReader
   , BYREF pguidVendor AS GUID _                        ' __in_opt const GUID *pguidVendor
   , BYREF ppIWriter AS IWICMetadataWriter _            ' __out_opt IWICMetadataWriter **ppIWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryReaderFromBlockReader ( _          ' VTable offset = 120
     BYVAL pIBlockReader AS IWICMetadataBlockReader _   ' __in_opt IWICMetadataBlockReader *pIBlockReader
   , BYREF ppIQueryReader AS IWICMetadataQueryReader _  ' __out_opt IWICMetadataQueryReader **ppIQueryReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryWriterFromBlockWriter ( _          ' VTable offset = 124
     BYVAL pIBlockWriter AS IWICMetadataBlockWriter _   ' __in_opt IWICMetadataBlockWriter *pIBlockWriter
   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out_opt IWICMetadataQueryWriter **ppIQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEncoderPropertyBag ( _                  ' VTable offset = 128
     BYREF ppropOptions AS PROPBAG2 _                   ' __in PROPBAG2 *ppropOptions
   , BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIPropertyBag AS IPropertyBag2 _            ' __out_opt IPropertyBag2 **ppIPropertyBag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICComponentFactory_INTERFACE_DEFINED__ */

DECLARE FUNCTION WICMatchMetadataContent IMPORT "Windowscodecs.dll" ALIAS "WICMatchMetadataContent" ( _
   BYREF guidContainerFormat AS GUID _                  ' __in REFGUID guidContainerFormat
 , BYREF pguidVendor AS GUID _                          ' __in_opt const GUID *pguidVendor
 , BYVAL pIStream AS IStream _                          ' __in IStream *pIStream
 , BYREF pguidMetadataFormat AS GUID _                  ' __out GUID *pguidMetadataFormat
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICSerializeMetadataContent IMPORT "Windowscodecs.dll" ALIAS "WICSerializeMetadataContent" ( _
   BYREF guidContainerFormat AS GUID _                  ' __in REFGUID guidContainerFormat
 , BYVAL pIWriter AS IWICMetadataWriter _               ' __in IWICMetadataWriter *pIWriter
 , BYVAL dwPersistOptions AS DWORD _                    ' __in DWORD dwPersistOptions
 , BYVAL pIStream AS IStream _                          ' __in IStream *pIStream
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICGetMetadataContentSize IMPORT "Windowscodecs.dll" ALIAS "WICGetMetadataContentSize" ( _
   BYREF guidContainerFormat AS GUID _                  ' __in REFGUID guidContainerFormat
 , BYVAL pIWriter AS IWICMetadataWriter _               ' __in IWICMetadataWriter *pIWriter
 , BYREF pcbSize AS QUAD _                              ' __out ULARGE_INTEGER *pcbSize
 ) AS LONG                                              ' HRESULT
