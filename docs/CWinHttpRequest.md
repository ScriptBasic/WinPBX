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
| [GetResponseText](#GetResponseText) | Retrieves the response entity body as a string. |
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

| Parameter  | Description |
| ---------- | ----------- |
| *nOption* | Value of type **WinHttpRequestOption** that specifies the option to retrieve. |

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
