# CWinHttpRequest Class

Wrapper class for Microsoft WinHTTP Services, version 5.1

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Abort](#Abort) | Aborts a WinHTTP **Send** method. |
| [GetAllResponseHeaders](#GetAllResponseHeaders) | Gets all HTTP response headers. |
| [GetErrorInfo](#GetErrorInfo) | Returns the description of the most recent error. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |
| [GetOption](#GetOption) | Retrieves a Microsoft Windows HTTP Services (WinHTTP) option value. |
| [GetResponseBody](#GetResponseBody) | Retrieves the response entity body as an array of unsigned bytes. |
| [GetResponseHeader](#GetResponseHeader) | Gets the specified HTTP response header. |
| [GetResponseStream](#GetResponseStream) | Retrieves the response entity body as a stream. |
| [GetResponseText](#GetResponseText) | Retrieves the response entity body as an string. |
| [GetStatus](#GetStatus) | Retrieves the HTTP status code from the last response. |
| [GetStatusText](#GetStatusText) | Retrieves the HTTP status text. |
| [Open](#Open) | Opens an HTTP connection to an HTTP resource. |
| [Send](#Send) | Sends an HTTP request to an HTTP server. |
| [SetAutoLogonPolicy](#SetAutoLogonPolicy) | Sets the current Automatic Logon Policy. |
| [SetClientCertificate](#SetClientCertificate) | Selects a client certificate to send to a Secure Hypertext Transfer Protocol (HTTPS) server. |
| [SetCredentials](#SetCredentials) | Sets credentials to be used with an HTTP server, whether it is a proxy server or an originating server. |
| [SetOption](#SetOption) | Sets a Microsoft Windows HTTP Services (WinHTTP) option value. |
| [SetProxy](#SetProxy) | Sets proxy server information. |
| [SetRequestHeader](#SetRequestHeader) | Adds, changes, or deletes an HTTP request header. |
| [SetTimeouts](#SetTimeouts) | Specifies the individual time-out components of a send/receive operation, in milliseconds. |
| [WaitForResponse](#WaitForResponse) | Waits for an asynchronous Send method to complete, with optional time-out value, in seconds. |

# <a name="Abort"></a>Abort

Aborts a WinHTTP **Send** method.

```
FUNCTION Abort () AS HRESULT
```

#### Return value

The return value is S_OK (0) on success or an error value otherwise.

#### Remarks

You can abort both asynchronous and synchronous **Send** methods. To abort a synchronous **Send** method, you must call **Abort** from within an **IWinHttpRequestEvents** event.

# <a name="GetAllResponseHeaders"></a>GetAllResponseHeaders

Gets all HTTP response headers.

```
FUNCTION GetAllResponseHeaders () AS CBSTR
```

#### Return value

The resulting header information.


#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

This method returns all of the headers contained in the most recent server response. The individual headers are delimited by a carriage return and line feed combination (ASCII 13 and 10). The last entry is followed by two delimiters (13, 10, 13, 10). Invoke this method only after the **Send** method has been called.

#### Example

```
#include once "windows.bi"
#include once "Afx/CWinHttpRequest.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
' // Get the response headers
DIM cbsResponseHeaders AS CBSTR = pWHttp.GetAllResponseHeaders
PRINT cbsResponseHeaders
```

# <a name="GetErrorInfo"></a>GetErrorInfo

Returns the description of the most recent OLE error in the current logical thread and clears the error state for the thread. It should be called as soon as possible after calling a method of this class. The numerical error code can obtained calling the **GetLastResult** method.

```
FUNCTION GetErrorInfo() AS CBSTR
```

#### Return value

A localized description of the error.


# <a name="GetLastResult"></a>GetLastResult

Returns the last result code.

```
FUNCTION GetLastResult () AS HRESULT
```

#### Return value

The result code returned by the last executed method. The **WinHttpRequest** object uses the **IErrorInfo** interface to provide error data. A description of the error can be obtained calling the **GetOleErrorInfo** method.

# <a name="GetOption"></a>GetOption

Retrieves a Microsoft Windows HTTP Services (WinHTTP) option value.

```
FUNCTION GetOption (BYVAL nOption AS WinHttpRequestOption) AS CVAR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nOption* | Value of type **WinHttpRequestOption** that specifies the option to retrieve. |

#### Return value

Variant that contains the option value.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

# <a name="GetResponseBody"></a>GetResponseBody

Retrieves the response entity body as an array of unsigned bytes.

```
FUNCTION GetResponseBody () AS STRING
```

#### Return value

An string containing the response entity body as an array of unsigned bytes. This array contains the raw data as received directly from the server.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

This method returns the response data in an array of unsigned bytes. If the response does not have a response body, an empty variant is returned. This method can only be invoked after the **Send** method has been called.

#### Examples

```
#include once "Afx/CWinHttpRequest.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
' // Get the response body
DIM strResponseBody AS STRING = pWHttp.GetResponseBody
PRINT strResponseBody
```
```
#include once "Afx/CWinHttpRequest.inc"
#include once "Afx/CStream.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "https://i.ytimg.com/vi/nPUi1XNiRzQ/maxresdefault.jpg"
print pWHttp.GetErrorInfo
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
' // Get the reponse body and sae it into a file
DIM st AS STRING = pWHttp.GetResponseBody
' // Open a file stream
DIM pFileStream AS CFileStream
IF pFileStream.Open("image.jpg", STGM_CREATE OR STGM_WRITE) = S_OK then
   pFileStream.WriteTextA(st)
END IF
```

# <a name="GetResponseHeader"></a>GetResponseHeader

Gets the specified HTTP response header.

```
FUNCTION GetResponseHeader (BYREF cbsHeader AS CBSTR) AS CBSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsHeader* | The case-insensitive header name. |

#### Return value

The resulting header information.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

Invoke this method only after the **Send** method has been called.

#### Example

```
#include "Afx/CWinHttpRequest.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
' // Get the response headers
DIM cbsResponseHeader AS CBSTR = pWHttp.GetResponseHeader("Date")
PRINT cbsResponseHeader
```

# <a name="GetResponseStream"></a>GetResponseStream

Retrieves the response entity body as a stream.

```
FUNCTION GetResponseStream () AS IStream PTR
```

#### Return value

Returns a pointer to an **IStream** interface if successful or NULL otherwise.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

This method can only be invoked after the **Send** method has been called.

# <a name="GetResponseText"></a>GetResponseText

Retrieves the response entity body as a CBSTR.

```
FUNCTION GetResponseText () AS CBSTR
```

#### Return value

A CBSTR containing the entity body of the response as text.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

This method can only be invoked after the **Send** method has been called.

When using this property in synchronous mode, the limit to the number of characters it returns is approximately 2,169,895.


# <a name="GetStatus"></a>GetStatus

Retrieves the HTTP status code from the last response.

```
FUNCTION GetStatus () AS LONG
```

#### Return value

Value of type LONG that receives the returned status code.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

The results of this method are valid only after the **Send** method has successfully completed. For a list of status codes see HTTP Status Codes.

# <a name="GetStatusText"></a>GetStatusText

Retrieves the HTTP status code from the last response.

```
FUNCTION GetStatusText () AS CBSTR
```

#### Return value

A CBSTR containing the HTTP status text.

#### GetLastResult

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

Retrieves the text portion of the server response line, making available the "user-friendly" equivalent to the numeric HTTP status code. The results of this property are valid only after the Send method has successfully completed.

# <a name="Open"></a>Open

Opens an HTTP connection to an HTTP resource.

```
FUNCTION Open (BYREF cbsMethod AS CBSTR, BYREF cbsUrl AS CBSTR, BYVAL bAsync AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsMethod* | An unicode strring that specifies the HTTP verb used for the Open method, such as "GET" or "PUT". Always use uppercase as some servers ignore lowercase HTTP verbs. |
| *cbsUrl* | An unicode string that contains the name of the resource. This must be an absolute URL. |
| *bAsync* | Optional. A value of type Boolean that specifies whether to open in asynchronous mode.<br>**TRUE**: Opens the HTTP connection in asynchronous mode.<br>**FALSE**: Opens the HTTP connection in synchronous mode. A call to Send does not return until WinHTTP has completely received the response. |

#### Return value

The return value is S_OK (0) on success or an error value otherwise.

#### Remarks

This method opens a connection to the resource identified in *cbsUrl* using the HTTP verb given in *cbsMethod*.

#### Example

```
#include "Afx/CWinHttpRequest.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
```

# <a name="Send"></a>Send

Sends an HTTP request to an HTTP server.

```
FUNCTION Send (BYREF cvBody AS CVAR = "") AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cvBody* | Optional. Data to be sent to the server. |

#### Return  value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

The request to be sent was defined in a prior call to the **Open** method. The calling application can provide data to be sent to the server through the *cvBody* parameter. If the HTTP verb of the object's Open is "GET", this method sends the request without *cvBody*, even if it is provided by the calling application.

# <a name="SetAutoLogonPolicy"></a>SetAutoLogonPolicy

Sets the current Automatic Logon Policy.

```
FUNCTION SetAutoLogonPolicy (BYVAL AutoLogonPolicy AS WinHttpRequestAutoLogonPolicy) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *AutoLogonPolicy* | A value of type **WinHttpRequestAutoLogonPolicy** that specifies the current automatic logon policy. |

#### Return  value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

The default policy is **AutoLogonPolicy_OnlyIfBypassProxy**.

Call **SetAutoLogonPolicy** to set the automatic logon policy before calling **Send** to send the request.

# <a name="SetClientCertificate"></a>SetClientCertificate

Selects a client certificate to send to a Secure Hypertext Transfer Protocol (HTTPS) server.

```
FUNCTION SetClientCertificate (BYREF cbsClientCertificate AS CBSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsClientCertificate* | An string that specifies the location, certificate store, and subject of a client certificate. |

#### Return value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

The string specified in the *cbsClientCertificate* parameter consists of the certificate location, certificate store, and subject name delimited by backslashes. For more information about the components of the certificate string, see [Client Certificates](https://docs.microsoft.com/en-us/windows/desktop/winhttp/ssl-in-winhttp).

The certificate store name and location are optional. However, if you specify a certificate store, you must also specify the location of that certificate store. The default location is CURRENT_USER and the default certificate store is "MY". A blank subject indicates that the first certificate in the certificate store should be used.

Call **SetClientCertificate** to select a certificate before calling **Send** to send the request.

Microsoft Windows HTTP Services (WinHTTP) does not provide client certificates to proxy servers that request certificates for authentication.

# <a name="SetCredentials"></a>SetCredentials

Sets credentials to be used with an HTTP server, whether it is a proxy server or an originating server.

```
FUNCTION SetCredentials (BYREF cbsUserName AS CBSTR, BYREF cbsPassword AS CBSTR, _
   BYVAL Flags AS HTTPREQUEST_SETCREDENTIALS_FLAGS) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsUserName* | An string that specifies the user name for authentication. |
| *cwsPassword* | An string specifies the password for authentication. This parameter is ignored if *cbsUserName* is NULL or missing. |
| *Flags* | A value that specifies when **CWinHttpRequest** uses credentials. Can be one of the below values. |

| Flag       | Meaning     |
| ---------- | ----------- |
| HTTPREQUEST_SETCREDENTIALS_FOR_SERVER | Credentials are passed to a server. |
| HTTPREQUEST_SETCREDENTIALS_FOR_PROXY | Credentials are passed to a proxy. |

#### Return value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

This method returns an error value if a call to **Open** has not completed successfully. It is assumed that some measure of interaction with a proxy server or origin server must occur before users can set credentials for the session. Moreover, until users know which authentication scheme(s) are supported, they cannot format the credentials.

To authenticate with both the server and the proxy, the application must call **SetCredentials** twice; first with the *Flags* parameter set to HTTPREQUEST_SETCREDENTIALS_FOR_SERVER, and second, with the *Flags* parameter set to HTTPREQUEST_SETCREDENTIALS_FOR_PROXY.


# <a name="SetOption"></a>SetOption

Sets a Microsoft Windows HTTP Services (WinHTTP) option value.

```
FUNCTION SetOption (BYVAL nOption AS WinHttpRequestOption, BYREF cvValue AS CVAR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *nOption* | Value of type **WinHttpRequestOption** that specifies the option to set. |
| *cvValue* | CVAR. Value to set. |

#### Return value

Returns S_OK (0) if successful or an error value otherwise.

#### Example

```
#include "Afx/CWinHttpRequest.inc"
using Afx

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Specify the user agent
pWHttp.SetOption(WinHttpRequestOption_UserAgentString, "A WinHttpRequest Example Program")

' // Send an HTTP request to the HTTP server
pWHttp.Send
IF pWHttp.GetLastResult = S_OK THEN
   ' // Get user agent string.
   DIM cvText AS CVAR = pWHttp.GetOption(WinHttpRequestOption_UserAgentString)
   PRINT cvText
   ' // We can also use:
   ' PRINT pWHttp.GetOption(WinHttpRequestOption_UserAgentString)
   ' // Get URL
   PRINT pWHttp.GetOption(WinHttpRequestOption_URL)
   ' // Get URL Code Page.
   PRINT pWHttp.GetOption(WinHttpRequestOption_URLCodePage)
   ' // Convert percent symbols to escape sequences.
   PRINT pWHttp.GetOption(WinHttpRequestOption_EscapePercentInURL)
END IF
```
