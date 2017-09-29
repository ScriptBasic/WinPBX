' ########################################################################################
' Microsoft Windows
' File: Ole2Utils.inc
' Contents: COM helper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLE2UTILS_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "olectl.inc"

' ========================================================================================
' Takes a null terminated wide string as input, and returns a pointer to a new wide string
' allocated with CoTaskMemAlloc. Free the returned string later with CoTaskMemFree.
' Note: This is useful when we need to pass a pointer to a null terminated wide string to a
' function or method that will release it. If we pass a PB WSTRINGZ it will GPF.
' For BSTR use SysAllocString(wsz).
' ========================================================================================
FUNCTION WStrAlloc (BYVAL bstrIn AS WSTRING) AS DWORD
   LOCAL pAddr AS DWORD
   pAddr = CoTaskMemAlloc(LEN(bstrIn) * 2)
   IF pAddr THEN MEMORY COPY STRPTR(bstrIn), pAddr, LEN(bstrIn) * 2
   FUNCTION = pAddr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of an OLE unicode string, given its address.
' ========================================================================================
FUNCTION BStr2Str (BYVAL pbstr AS DWORD, OPTIONAL BYVAL bFree AS LONG) AS WSTRING
   IF pbstr = %NULL THEN EXIT FUNCTION
   FUNCTION = PEEK$$(pbstr, SysStringLen(BYVAL pbstr))
   IF bFree THEN SysFreeString(pbstr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of a null-terminated unicode string, given its address
' ========================================================================================
FUNCTION WStr2Str (BYVAL pwstr AS DWORD, OPTIONAL BYVAL bFree AS LONG) AS WSTRING
   IF pwstr = %NULL THEN EXIT FUNCTION
   FUNCTION = PEEK$$(pwstr, lstrlenW(BYVAL pwstr))
   IF bFree THEN CoTaskMemFree(BYVAL pwstr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves exported guids.
' - szDllPath = Path of the DLL that exports the guid.
' - szGuidName = Name of the exported guid (always an ansi string)
' Return value:
' - The requested GUID on success or an empty string on failure.
' ========================================================================================
FUNCTION OleGetExportedGuid (BYREF wszDllPath AS WSTRINGZ, BYREF szGuidName AS ASCIIZ) AS WSTRING

   LOCAL hLib AS DWORD
   LOCAL pGuid AS GUID PTR

   hLib = LoadLibraryW(wszDllPath)
   IF hLib = 0 THEN EXIT FUNCTION
   pGuid = GetProcAddress(hLib, szGuidName)
   IF pGuid THEN FUNCTION = GUIDTXT$(@pGuid)
   FreeLibrary hLib

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a licensed instance of an ActiveX visual control (OCX).
' Parameters:
' strProgID
'   The ProgID or the CLSID of the object to create.
'   - A ProgID such as "MSCAL.Calendar.7"
'   - A CLSID such as "{8E27C92B-1264-101C-8A2F-040224009C02}"
' bstrLicKey
'   The license key as an unicode string.
' Return value:
'   A pointer to the IDispatch interface of the control.
' ========================================================================================
FUNCTION CreateControlLic (BYVAL strProgID AS STRING, BYVAL bstrLicKey AS WSTRING) AS IDispatch

   LOCAL hr              AS LONG             ' // HRESULT
   LOCAL ClassID         AS GUID             ' // CLSID
   LOCAL pIClassFactory2 AS IClassFactory2   ' // IClassFactory2 interface
   LOCAL pUnk            AS IUnknown         ' // The IUnknow interface pointer
   LOCAL pDisp           AS IDispatch        ' // The IDispatch interface pointer

   ' Exit if strProgID is a null string
   IF strProgID = "" THEN EXIT FUNCTION
   ' Convert the ProgID in a CLSID
   ClassID = CLSID$(strProgID)
   ' If it fails, see if it is a CLSID
   IF ClassID = $IID_NULL THEN ClassID = GUID$(strProgID)
   ' If not a valid ProgID or CLSID return an error
   IF ClassID = $IID_NULL THEN EXIT FUNCTION
   ' Get a reference to the IClassFactory2 interface of the control
   ' Context: &H15 (%CLSCTX_SERVER)
   hr = CoGetClassObject(ClassID, &H15, BYVAL %NULL, $IID_IClassFactory2, pIClassFactory2)
   ' Create an instance of the object
   IF hr = %S_OK AND ISOBJECT(pIClassFactory2) THEN
      ' Create a licensed instance of the control
      hr = pIClassFactory2.CreateInstanceLic(NOTHING, NOTHING, $IID_IUnknown, bstrLicKey, pUnk)
      pDisp = pUnk
      IF ISOBJECT(pDisp) THEN
         FUNCTION = pDisp
      ELSE
         FUNCTION = pUnk
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads the specified library and creates an instance of an object.
' If it succeeds, returns a reference to the requested interface; otherwise, it returns null.
' Not every component is a suitable candidate for use under CreateInstanceFromDll.
'  - Only in-process servers (DLLs) are supported.
'  - Components that are system components or part of the operating system, such as XML,
'    Data Access, Internet Explorer, or DirectX, aren't supported
'  - Components that are part of an application, such Microsoft Office, aren't supported.
'  - Components intended for use as an add-in or a snap-in, such as an Office add-in or
'    a control in a Web browser, aren't supported.
'  - Components that manage a shared physical or virtual system resource aren't supported.
'  - Visual ActiveX controls aren't supported because they need to be initilized and
'    activated by the OLE container.
' Note: Do not use FreeLibrary to unload the library once you have got a valid reference
' to an interface or your application will GPF. Before calling FreeLibrary, all the
' interface references must be released. If you don't need to unload the library until
' the application ends, then you don't need to call FreeLibrary because PB calls
' CoUninitialize under the hood, that closes the COM library on the current thread,
' unloads all DLLs loaded by the thread, frees any other resources that the thread
' maintains, and forces all RPC connections on the thread to close.
' ========================================================================================
FUNCTION CreateInstanceFromDll ( _
   BYVAL strLibName AS STRING _               ' // [in] Library name and path
 , BYREF rclsid AS GUID _                     ' // [in] CLSID that will associate the correct data and code
 , BYREF riid AS GUID _                       ' // [in] IID of the interface to be used to communicate with the newly created object
 , OPTIONAL BYVAL bstrLicKey AS WSTRING _     ' // [in] License key (ansi string)
 ) AS IUnknown                                ' // [out] The interface pointer requested in riid

   LOCAL hr AS LONG                           ' // HRESULT
   LOCAL hLib AS DWORD                        ' // Library handle
   LOCAL pProc AS DWORD                       ' // Procedure address
   LOCAL pIClassFactory AS IClassFactory      ' // IClassFactory interface
   LOCAL pIClassFactory2 AS IClassFactory2    ' // IClassFactory2 interface
   LOCAL pUnk AS IUnknown                     ' // The requested interface pointer

   ' // See if the library is already loaded in the address space
   hLib = GetModuleHandle(BYCOPY strLibName)
   ' // If it is not loaded, load it
   IF hLib = %NULL THEN hLib = LoadLibrary(BYCOPY strLibName)
   ' // If it fails, abort
   IF hLib = %NULL THEN EXIT FUNCTION

   ' // Retrieve the address of the exported function DllGetClassObject
   pProc = GetProcAddress(hLib, "DllGetClassObject")
   IF pProc = %NULL THEN EXIT FUNCTION

   IF LEN(bstrLicKey) = 0 THEN
      ' // Request a reference to the IClassFactory interface
      CALL DWORD pProc USING DllGetClassObject(rclsid, $IID_IClassFactory, pIClassFactory) TO hr
      IF hr <> %S_OK THEN EXIT FUNCTION
      ' // Create an instance of the server or control
      hr = pIClassFactory.CreateInstance(%NULL, riid, BYVAL VARPTR(pUnk))
      IF hr <> %S_OK THEN EXIT FUNCTION
   ELSE
      ' // Request a reference to the IClassFactory2 interface
      CALL DWORD pProc USING DllGetClassObject(rclsid, $IID_IClassFactory2, pIClassFactory2) TO hr
      IF hr <> %S_OK THEN EXIT FUNCTION
      ' // Create a licensed instance of the server or control
      hr = pIClassFactory2.CreateInstanceLic(NOTHING, NOTHING, riid, bstrLicKey, pUnk)
      IF hr <> %S_OK THEN EXIT FUNCTION
   END IF

   FUNCTION = pUnk

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a display name into a moniker that identifies the object named, and then binds
' to the object identified by the moniker.
' ========================================================================================
FUNCTION OleGetObject (BYREF wszDisplayName AS WSTRINGZ) AS IDispatch
   LOCAL hr AS LONG
   LOCAL pDisp AS IDispatch
   hr = CoGetObject(wszDisplayName, BYVAL %NULL, $IID_IDispatch, pDisp)
   IF hr = %S_OK THEN FUNCTION = pDisp
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a standard IFont object
' ========================================================================================
FUNCTION OleCreateFont ( _
   BYREF wszFontName AS WSTRINGZ, _           ' __in  Font name
   BYVAL cySize AS CUR, _                     ' __in  Point size
   BYVAL fWeight AS INTEGER, _                ' __in  Weight (%FW_NORMAL, etc.)
   BYVAL fCharset AS INTEGER, _               ' __in  Character set
   BYVAL fItalic AS LONG, _                   ' __in  Italic state
   BYVAL fUnderline AS LONG, _                ' __in  Underline state
   BYVAL fStrikethrough AS LONG, _            ' __in  Strikethrough state
   BYREF pFont AS IUnknown _                  ' __out The font object
   ) AS LONG                                  ' HRESULT

   LOCAL tf AS FONTDESC
   LOCAL riid AS GUID

   riid = $IID_IUnknown
   tf.cbSizeOfStruct = SIZEOF(FONTDESC)
   tf.lpstrName = VARPTR(wszFontName)
   tf.cySize = cySize
   tf.sWeight = fWeight
   tf.sCharset = fCharset
   tf.fItalic = fItalic
   tf.fUnderline = fUnderline
   tf.fStrikethrough = fStrikethrough
   FUNCTION = OleCreateFontIndirect(tf, riid, pFont)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a standard IFontDisp object
' ========================================================================================
FUNCTION OleCreateFontDisp ( _
   BYREF wszFontName AS WSTRINGZ, _           ' __in  Font name
   BYVAL cySize AS CUR, _                     ' __in  Point size
   BYVAL fWeight AS INTEGER, _                ' __in  Weight (%FW_NORMAL, etc.)
   BYVAL fCharset AS INTEGER, _               ' __in  Character set
   BYVAL fItalic AS LONG, _                   ' __in  Italic state
   BYVAL fUnderline AS LONG, _                ' __in  Underline state
   BYVAL fStrikethrough AS LONG, _            ' __in  Strikethrough state
   BYREF pFont AS IDispatch _                 ' __out The font object
   ) AS LONG                                  ' HRESULT

   LOCAL tf AS FONTDESC
   LOCAL riid AS GUID

   riid = $IID_IDispatch
   tf.cbSizeOfStruct = SIZEOF(FONTDESC)
   tf.lpstrName = VARPTR(wszFontName)
   tf.cySize = cySize
   tf.sWeight = fWeight
   tf.sCharset = fCharset
   tf.fItalic = fItalic
   tf.fUnderline = fUnderline
   tf.fStrikethrough = fStrikethrough
   FUNCTION = OleCreateFontIndirect(tf, riid, pFont)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a standard IPicture object.
' ========================================================================================
FUNCTION OleCreatePicture ( _
   BYVAL hPicHandle AS DWORD, _               ' __in  Handle of the icon or bitmap
   BYVAL picType AS DWORD, _                  ' __in  Picture type: %PICTYPE_BITMAP or %PICTYPE_ICON
   BYVAL fOwn AS INTEGER, _                   ' __in  %TRUE or %FALSE
   BYREF pPicture AS IUnknown _               ' __out The picture object
   ) AS LONG                                  ' HRESULT

   LOCAL tpd AS PICTDESC
   LOCAL riid AS GUID

   riid = $IID_IUnknown
   IF hPicHandle = 0 THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   SELECT CASE picType
      CASE %PICTYPE_BITMAP        ' Bitmap
         tpd.hbitmap = hPicHandle
      CASE %PICTYPE_ICON          ' Icon
         tpd.hicon = hPicHandle
      CASE ELSE
         FUNCTION = %E_INVALIDARG
         EXIT FUNCTION
   END SELECT

   tpd.cbSizeOfStruct = SIZEOF(PICTDESC)
   tpd.picType = picType
   IF fOwn THEN fOwn = -1
   FUNCTION = OleCreatePictureIndirect(tpd, riid, fOwn, pPicture)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a standard IPictureDisp object.
' ========================================================================================
FUNCTION OleCreatePictureDisp ( _
   BYVAL hPicHandle AS DWORD, _               ' __in  Handle of the icon or bitmap
   BYVAL picType AS DWORD, _                  ' __in  Picture type: %PICTYPE_BITMAP or %PICTYPE_ICON
   BYVAL fOwn AS INTEGER, _                   ' __in  %TRUE or %FALSE
   BYREF pPicture AS IDispatch _              ' __out The picture object
   ) AS LONG                                  ' HRESULT

   LOCAL tpd AS PICTDESC
   LOCAL riid AS GUID

   riid = $IID_IDispatch
   IF hPicHandle = 0 THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   SELECT CASE picType
      CASE %PICTYPE_BITMAP        ' Bitmap
         tpd.hbitmap = hPicHandle
      CASE %PICTYPE_ICON          ' Icon
         tpd.hicon = hPicHandle
      CASE ELSE
         FUNCTION = %E_INVALIDARG
         EXIT FUNCTION
   END SELECT

   tpd.cbSizeOfStruct = SIZEOF(PICTDESC)
   tpd.picType = picType
   IF fOwn THEN fOwn = -1
   FUNCTION = OleCreatePictureIndirect(tpd, riid, fOwn, pPicture)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves an icon to a file.
' Parameters:
' - hIcon = Icon handle
' - bstrFileName = Name of the file to save
' Return Value:
'   %S_OK on success, or an error value.
' Note: The results are always 4bpp (bits per pixel) images, with 16 colors.
' Function discarded because the resulting icons look horrible.
' ========================================================================================
'FUNCTION OleSaveHICONToFile (BYVAL hIcon AS DWORD, BYVAL bstrFileName AS WSTRING) AS LONG

'   LOCAL hr AS LONG
'   LOCAL riid AS GUID
'   LOCAL tpd AS PICTDESC
'   LOCAL pPicture AS IPicture

'   IF hIcon = 0 OR bstrFileName = "" THEN
'      FUNCTION = %E_INVALIDARG
'      EXIT FUNCTION
'   END IF

'   riid = $IID_IPicture
'   tpd.cbSizeOfStruct = SIZEOF(PICTDESC)
'   tpd.picType = %PICTYPE_ICON
'   tpd.hicon = hIcon

'   hr = OleCreatePictureIndirect(tpd, riid, %FALSE, pPicture)
'   IF FAILED(hr) THEN
'      FUNCTION = hr
'      EXIT FUNCTION
'   END IF

'   ' // Create a stream and save the image
'   LOCAL pStream AS IStream
'   LOCAL cbSize AS LONG
'   CreateStreamOnHGlobal(0, %TRUE, pStream)
'   hr = pPicture.SaveAsFile(pStream, %TRUE, cbSize)
'   IF FAILED(hr) THEN
'      FUNCTION = hr
'      EXIT FUNCTION
'   END IF

'   ' // Write the stream content to the file
'   LOCAL hBuf AS DWORD
'   GetHGlobalFromStream(pStream, hBuf)
'   LOCAL pBuffer AS DWORD
'   pBuffer = GlobalLock(hBuf)
'   LOCAL hFile AS DWORD
'   hFile = CreateFileW(BYCOPY bstrFileName, %GENERIC_WRITE, 0, BYVAL %NULL, %CREATE_ALWAYS, 0, %NULL)
'   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN
'      hr = HRESULT_FROM_WIN32(GetLastError)
'   ELSE
'      LOCAL cbWritten AS DWORD
'      WriteFile(hFile, BYVAL pBuffer, cbSize, cbWritten, BYVAL %NULL)
'      CloseHandle(hFile)
'   END IF
'   GlobalUnlock(pBuffer)

'   ' // Cleanup
'   pStream = NOTHING
'   pPicture = NOTHING

'   FUNCTION = hr

'END FUNCTION
' ========================================================================================


' /////////////////////////////////////////////////////////////////////////////////////////
'                             IUNKNOWN WRAPPER FUNCTIONS
' /////////////////////////////////////////////////////////////////////////////////////////

' ========================================================================================
' QueryInterface method
' Returns a pointer to a specified interface on an object to which a client currently
' holds an interface pointer. You must release the returned interface, when no longer
' needed, with a call to the Release method.
' ========================================================================================
FUNCTION IUnknown_QueryInterface (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   IF pthis = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   CALL DWORD @@pthis[0] USING IUnknown_QueryInterface (pthis, riid, ppvObj) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ========================================================================================

' ========================================================================================
' AddRef method
' Increments the reference count for an interface on an object. It should be called for
' every new copy of a pointer to an interface on a given object.
' ========================================================================================
FUNCTION IUnknown_AddRef (BYVAL pthis AS DWORD PTR) AS DWORD
   LOCAL DWRESULT AS DWORD
   IF pthis = %NULL THEN EXIT FUNCTION
   CALL DWORD @@pthis[1] USING IUnknown_AddRef (pthis) TO DWRESULT
   FUNCTION = DWRESULT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Release method
' Decrements the reference count for the calling interface on a object. If the reference
' count on the object falls to 0, the object is freed from memory.
' ========================================================================================
FUNCTION IUnknown_Release (BYVAL pthis AS DWORD PTR) AS DWORD
   LOCAL DWRESULT AS DWORD
   IF pthis = %NULL THEN EXIT FUNCTION
   CALL DWORD @@pthis[2] USING IUnknown_Release (pthis) TO DWRESULT
   FUNCTION = DWRESULT
END FUNCTION
' ========================================================================================


' /////////////////////////////////////////////////////////////////////////////////////////
'                              IERRORINFO WRAPPER FUNCTIONS
' /////////////////////////////////////////////////////////////////////////////////////////

' ========================================================================================
' Sets rich error information.
' ========================================================================================
FUNCTION OleSetErrorInfo ( _
   OPTIONAL BYVAL rguid AS GUID _
 , OPTIONAL BYVAL bstrSource AS WSTRING _
 , OPTIONAL BYVAL bstrDescription AS WSTRING _
 , OPTIONAL BYVAL bstrHelpFile AS WSTRING _
 , OPTIONAL BYVAL dwHelpContext AS DWORD _
 ) AS LONG

   LOCAL hr AS LONG
   LOCAL pICreateErrorInfo AS ICreateErrorInfo
   LOCAL pIErrorInfo AS IErrorInfo

   hr = CreateErrorInfo(pICreateErrorInfo)
   IF hr <> %S_OK OR ISNOTHING(pICreateErrorInfo) THEN EXIT FUNCTION
   pICreateErrorInfo.SetGUID(rguid)
   pICreateErrorInfo.SetSource(BYCOPY bstrSource)
   pICreateErrorInfo.SetDescription(BYCOPY bstrDescription)
   pICreateErrorInfo.SetHelpFile(BYCOPY bstrHelpFile)
   pICreateErrorInfo.SetHelpContext(dwHelpContext)

   ' Get the IErrorInfo interface
   pIErrorInfo = pICreateErrorInfo
   ' Set this error information in the current thread
   hr = SetErrorInfo(0, pIErrorInfo)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function to retrieve detailed contextual error information.
' Return values: S_OK (Success), S_FALSE (no error object to return).
' ========================================================================================
FUNCTION IErrorInfo_GetErrorInfo ( _
   BYVAL pObj AS IUnknown _                     ' Object pointer
 , BYREF riid AS GUID _                         ' Interface IID
 , BYREF bstrDescription AS WSTRING _           ' Textual description of the error.
 , OPTIONAL BYREF bstrSource AS WSTRING _       ' Name of the component that generated the error
 , OPTIONAL BYREF rguid AS GUID _               ' GUID of the interface that defined the error
 , OPTIONAL BYREF bstrHelpFile AS WSTRING _     ' Name of the component that generated the error
 , OPTIONAL BYREF dwHelpContext AS DWORD _      ' Help context ID for the error
 ) AS LONG                                      ' BOOL

   LOCAL hr AS LONG
   LOCAL pIErrorInfo AS IErrorInfo
   LOCAL pISupportErrorInfo AS ISupportErrorInfo

   FUNCTION = %S_FALSE
   ' Get a pointer to the ISupportErrorInfo interface
   IF ISOBJECT(pObj) THEN
      pISupportErrorInfo = pObj
      IF ISNOTHING(pISupportErrorInfo) THEN EXIT FUNCTION
      ' See if the interface supports ErrorInfo
      IF VARPTR(riid) THEN
         hr = pISupportErrorInfo.InterfaceSupportsErrorInfo(riid)
         IF hr <> %S_OK THEN EXIT FUNCTION
      END IF
   END IF
   ' Get a pointer to the IErrorInfo interface
   hr = GetErrorInfo(0, pIErrorInfo)
   IF hr <> %S_OK OR ISNOTHING(pIErrorInfo) THEN EXIT FUNCTION
   ' Retrieve the information
   IF VARPTR(rguid) THEN pIErrorInfo.GetGUID(rguid)
   IF VARPTR(bstrSource) THEN pIErrorInfo.GetSource(bstrSource)
   IF VARPTR(bstrDescription) THEN pIErrorInfo.GetDescription(bstrDescription)
   IF VARPTR(bstrHelpFile) THEN pIErrorInfo.GetHelpFile(bstrHelpFile)
   IF VARPTR(dwHelpContext) THEN pIErrorInfo.GetHelpContext(dwHelpContext)
   FUNCTION = %S_OK

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves rich error information.
' For complete accuracy, pass the three parameters. Otherwise, the returned error
' information could belong to a previous call.
' ========================================================================================
FUNCTION OleGetErrorInfo (OPTIONAL BYVAL nErrorCode AS LONG, OPTIONAL BYVAL pObj AS IUnknown, OPTIONAL BYREF riid AS GUID) AS WSTRING

   LOCAL bstrMsg AS WSTRING
   LOCAL bstrDescription AS WSTRING
   LOCAL rguid AS GUID
   LOCAL bstrSource AS WSTRING
   LOCAL bstrHelpFile AS WSTRING
   LOCAL dwHelpContext AS DWORD
   LOCAL priid AS DWORD

   priid = VARPTR(riid)
   IF IErrorInfo_GetErrorInfo(pObj, BYVAL priid, bstrDescription, bstrSource, rguid, bstrHelpFile, dwHelpContext) = %S_OK THEN
      IF nErrorCode THEN bstrMsg = "Error code: &H" & HEX$(nErrorCode, 8) & " [" & FORMAT$(nErrorCode) & "]" & $CRLF
      IF LEN(bstrDescription) THEN bstrMsg += "Description: " & bstrDescription & $CRLF
      IF LEN(bstrSource) THEN bstrMsg += "Source: " & bstrSource & $CRLF
      IF rguid <> $IID_NULL THEN bstrMsg += "GUID: " & GUIDTXT$(rguid) & $CRLF
      IF LEN(bstrHelpFile) THEN bstrMsg += "Help file: " & bstrHelpFile & $CRLF
      IF dwHelpContext THEN bstrMsg += "Help context: " & FORMAT$(dwHelpContext)
   ELSE
      IF nErrorCode THEN bstrMsg = FORMAT$(nErrorCode) & " [&H" & HEX$(nErrorCode, 8) & "] " & OBJRESULT$(nErrorCode)
   END IF
   IF LEN(bstrMsg) = 0 AND nErrorCode <> 0 THEN bstrMsg = "Error code: &H" & HEX$(nErrorCode) & " [" & FORMAT$(nErrorCode) & "]"
   FUNCTION = bstrMsg

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays rich error information.
' For complete accuracy, pass the three parameters. Otherwise, the returned error
' information could belong to a previous call.
' ========================================================================================
SUB OleShowErrorInfo (OPTIONAL BYVAL nErrorCode AS LONG, OPTIONAL BYVAL pObj AS IUnknown, OPTIONAL BYREF riid AS GUID)

   LOCAL bstrMsg AS WSTRING

   bstrMsg = OleGetErrorInfo(nErrorCode, pObj, BYVAL VARPTR(riid))
   #IF %DEF(%PB_CC32)
      STDOUT bstrMsg
   #ELSE
      MSGBOX bstrMsg, &H00001000&, "Error" ' %MB_SYSTEMMODAL
   #ENDIF

END SUB
' ========================================================================================


' ////////////////////////////////////////////////////////////////////////////////////////
'                               ISTREAM WRAPPER FUNCTIONS
' ////////////////////////////////////////////////////////////////////////////////////////

' Note: The Windows API provides the IStream_Read, IStream_Write, IStream_Reset, IStream_Size,
' IStream_ReadPidl, IStream_WritePidl, IStream_ReadStr, IStream_WriteStr and IStream_Copy
' functions, although they aren't available in all Windows versions.

' ========================================================================================
' Retrieves the seek position.
' ========================================================================================
FUNCTION IStream_GetSeekPosition (BYVAL pIStream AS IStream) AS QUAD
   LOCAL libNewPosition AS QUAD
   pIStream.Seek(0, %STREAM_SEEK_CUR, libNewPosition)
   FUNCTION = libNewPosition
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the seek position at the beginning of the stream.
' ========================================================================================
FUNCTION IStream_ResetSeekPosition (BYVAL pIStream AS IStream) AS QUAD
   LOCAL libNewPosition AS QUAD
   pIStream.Seek(0, %STREAM_SEEK_SET, libNewPosition)
   FUNCTION = libNewPosition
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the seek position at the end of the stream.
' ========================================================================================
FUNCTION IStream_SeekAtEndOfFile (BYVAL pIStream AS IStream) AS QUAD
   LOCAL libNewPosition AS QUAD
   pIStream.Seek(0, %STREAM_SEEK_END, libNewPosition)
   FUNCTION = libNewPosition
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size of the stream.
' ========================================================================================
FUNCTION IStream_GetSize (BYVAL pIStream AS IStream) AS QUAD
   LOCAL tstatstg AS STATSTG
   pIStream.Stat(tstatstg, %STATFLAG_NONAME)
   FUNCTION = tstatstg.cbsize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Writes a string at the current seek position.
' ========================================================================================
FUNCTION IStream_WriteTextA (BYVAL pIStream AS IStream, BYVAL strText AS STRING) AS DWORD
   LOCAL cbWritten AS DWORD
   pIStream.Write(STRPTR(strText), LEN(strText), cbWritten)
   FUNCTION = cbWritten
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION IStream_WriteTextW (BYVAL pIStream AS IStream, BYVAL bstrText AS WSTRING) AS DWORD
   LOCAL cbWritten AS DWORD
   pIStream.Write(STRPTR(bstrText), LEN(bstrText) * 2, cbWritten)
   FUNCTION = cbWritten
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO IStream_WriteText = IStream_WriteTextW
#ELSE
   MACRO IStream_WriteText = IStream_WriteTextA
#ENDIF

' ========================================================================================
' Writes an string and a carriage return+line feed at the current seek position
' ========================================================================================
FUNCTION IStream_WriteLineA (BYVAL pIStream AS IStream, BYVAL strText AS STRING) AS DWORD
   LOCAL cbWritten AS DWORD
   strText += $CRLF
   pIStream.Write(STRPTR(strText), LEN(strText), cbWritten)
   FUNCTION = cbWritten
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION IStream_WriteLineW (BYVAL pIStream AS IStream, BYVAL bstrText AS WSTRING) AS DWORD
   LOCAL cbWritten AS DWORD
   bstrText += $CRLF
   pIStream.Write(STRPTR(bstrText), LEN(bstrText) * 2, cbWritten)
   FUNCTION = cbWritten
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO IStream_WriteLine = IStream_WriteLineW
#ELSE
   MACRO IStream_WriteLine = IStream_WriteLineA
#ENDIF

' ========================================================================================
' Reads numchars at the current Seek position. If numchars = 0 or -1, it returns all the
' content of the stream.
' ========================================================================================
FUNCTION IStream_ReadTextA (BYVAL pIStream AS IStream, BYVAL numchars AS LONG) AS STRING

   LOCAL hr AS LONG
   LOCAL plibNewPosition AS QUAD
   LOCAL pcbRead AS DWORD
   LOCAL tstatstg AS STATSTG
   LOCAL strText AS STRING

   IF ISNOTHING(pIStream) THEN EXIT FUNCTION
   IF numchars < -1 THEN EXIT FUNCTION
   IF numchars = 0 THEN numchars = -1

   hr = pIStream.Seek(0, %STREAM_SEEK_SET, plibNewPosition)
   IF hr <> %S_OK THEN EXIT FUNCTION
   IF numchars = -1 THEN
      hr = pIStream.Stat(tstatstg, %STATFLAG_NONAME)
      IF hr <> %S_OK THEN EXIT FUNCTION
      IF tstatstg.cbsize < 1 THEN EXIT FUNCTION
      IF tstatstg.cbsize <= 2147483647& THEN
         numchars = tstatstg.cbsize
      ELSE
'         numchars = 2147483647&
         EXIT FUNCTION
      END IF
   END IF

   strText = SPACE$(numchars)
   hr = pIStream.Read(STRPTR(strText), LEN(strText), pcbRead)
   IF hr <> %S_OK THEN EXIT FUNCTION
   IF pcbRead < numchars THEN strText = LEFT$(strText, pcbRead)
   IF IsTextUnicode(STRPTR(strText), LEN(strText)) THEN
      FUNCTION = ACODE$(strText)
   ELSE
      FUNCTION = strText
   END IF

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION IStream_ReadTextW (BYVAL pIStream AS IStream, BYVAL numchars AS LONG) AS WSTRING

   LOCAL hr AS LONG
   LOCAL plibNewPosition AS QUAD
   LOCAL pcbRead AS DWORD
   LOCAL tstatstg AS STATSTG
   LOCAL strText AS STRING

   IF ISNOTHING(pIStream) THEN EXIT FUNCTION
   IF numchars < -1 THEN EXIT FUNCTION
   IF numchars = 0 THEN numchars = -1

   hr = pIStream.Seek(0, %STREAM_SEEK_SET, plibNewPosition)
   IF hr <> %S_OK THEN EXIT FUNCTION
   IF numchars = -1 THEN
      hr = pIStream.Stat(tstatstg, %STATFLAG_NONAME)
      IF hr <> %S_OK THEN EXIT FUNCTION
      IF tstatstg.cbsize < 1 THEN EXIT FUNCTION
      IF tstatstg.cbsize <= 2147483647& THEN
         numchars = tstatstg.cbsize
      ELSE
'         numchars = 2147483647&
         EXIT FUNCTION
      END IF
   ELSE
      numchars *= 2
   END IF

   strText = SPACE$(numchars)
   hr = pIStream.Read(STRPTR(strText), LEN(strText), pcbRead)
   IF hr <> %S_OK THEN EXIT FUNCTION
   IF pcbRead < numchars THEN strText = LEFT$(strText, pcbRead)
   IF IsTextUnicode(STRPTR(strText), LEN(strText)) THEN
      FUNCTION = ACODE$(strText)
   ELSE
      FUNCTION = strText
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO IStream_ReadText = IStream_ReadTextW
#ELSE
   MACRO IStream_ReadText = IStream_ReadTextA
#ENDIF
