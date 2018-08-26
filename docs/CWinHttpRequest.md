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

### Enumerations

| Name       | Description |
| ---------- | ----------- |
| [WinHttpRequestAutoLogonPolicy](#WinHttpRequestAutoLogonPolicy) | Includes possible settings for the Automatic Logon Policy. |
| [WinHttpRequestOption](#WinHttpRequestOption) | Includes options that can be set or retrieved for the current Microsoft Windows HTTP Services (WinHTTP) session. |
| [WinHttpRequestSecureProtocols](#WinHttpRequestSecureProtocols) | Type of secure protocol. |
| [WinHttpRequestSslErrorFlags](#WinHttpRequestSslErrorFlags) | Request error flags. |

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

# <a name="SetProxy"></a>SetProxy

Sets proxy server information.

```
FUNCTION SetProxy (BYVAL ProxySetting AS HTTPREQUEST_PROXY_SETTING, BYREF cvProxyServer AS CVAR = "", _
   BYVAL cvBypassList AS CVAR = "") AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *ProxySetting* | A value of type LONG that receives the flags that control this method. Can be one of the values in the table below. |
| *cvProxyServer* | Optional. A value of type Variant that is set to a proxy server string when *ProxySetting* equals HTTPREQUEST_PROXYSETTING_PROXY. |
| *cvBypassList* | Optional. A value of type Variant that is set to a domain bypass list string when *ProxySetting* equals HTTPREQUEST_PROXYSETTING_PROXY. |

| Flag       | Description |
| ---------- | ----------- |
| HTTPREQUEST_PROXYSETTING_DEFAULT | Default proxy setting. Equivalent to HTTPREQUEST_PROXYSETTING_PRECONFIG. |
| HTTPREQUEST_PROXYSETTING_PRECONFIG | Indicates that the proxy settings should be obtained from the registry. This assumes that Proxycfg.exe has been run. If Proxycfg.exe has not been run and HTTPREQUEST_PROXYSETTING_PRECONFIG is specified, then the behavior is equivalent to HTTPREQUEST_PROXYSETTING_DIRECT. |
| HTTPREQUEST_PROXYSETTING_DIRECT | Indicates that all HTTP and HTTPS servers should be accessed directly. Use this command if there is no proxy server. |
| HTTPREQUEST_PROXYSETTING_PROXY | When HTTPREQUEST_PROXYSETTING_PROXY is specified, *cvProxyServer* should be set to a proxy server string and *cvBypassList* should be set to a domain bypass list string. This proxy configuration applies only to the current instance of the WinHttpRequest object. |

#### Return value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

Enables the calling application to specify use of default proxy information (configured by the proxy configuration tool) or to override Proxycfg.exe. This method must be called before calling the Send method. If this method is called after the **Send** method, it has no effect.

**CWinHttpRequest** passes these parameters to Microsoft Windows HTTP Services (WinHTTP).

# <a name="SetRequestHeader"></a>SetRequestHeader

Adds, changes, or deletes an HTTP request header.

```
FUNCTION SetRequestHeader (BYREF cbsHeader AS CBSTR, BYREF cbsValue AS CBSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsHeader* | A value of type CBSTR that specifies the name of the header to be set, for example, "depth". This parameter should not contain a colon and must be the actual text of the HTTP header. |
| *cbsValue* | An string that specifies the value of the header, for example, "infinity". |

Return value

Returns S_OK if successful or an error value otherwise.

#### Remarks

Headers are transferred across redirects. This can create a security vulnerability. To avoid having headers transferred if a redirect occurs, use the WINHTTP_STATUS_CALLBACK callback to correct the specific headers when a redirect occurs.

The **SetRequestHeader** method enables the calling application to add or delete an HTTP request header prior to sending the request. The header name is given in *cbsHeader*, and the header token or value is given in *cbsValue*. To add a header, supply a header name and value. If another header already exists with this name, it is replaced. To delete a header, set *cbsHeader* to the name of the header to delete and set *cbsValue* to NULL.

The name and value of request headers added with this method are validated. Headers must be well formed. For more information about valid HTTP headers, see RFC 2616. If an invalid header is used, an error occurs and the header is not added.

# <a name="SetTimeouts"></a>SetTimeouts

Specifies the individual time-out components of a send/receive operation, in milliseconds.

```
FUNCTION SetTimeouts (BYVAL ResolveTimeout AS LONG, BYVAL ConnectTimeout AS LONG, _
   BYVAL SendTimeout AS LONG, BYVAL ReceiveTimeout AS LONG) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *ResolveTimeout* | Time-out value applied when resolving a host name (such as www.microsoft.com) to an IP address (such as 192.168.131.199), in milliseconds. The default value is zero, meaning no time-out (infinite). If DNS timeout is specified using NAME_RESOLUTION_TIMEOUT, there is an overhead of one thread per request. |
| *ConnectTimeout* | Time-out value applied when establishing a communication socket with the target server, in milliseconds. The default value is 60,000 (60 seconds). |
| *SendTimeout* | Time-out value applied when sending an individual packet of request data on the communication socket to the target server, in milliseconds. A large request sent to an HTTP server are normally be broken up into multiple packets; the send time-out applies to sending each packet individually. The default value is 30,000 (30 seconds). |
| *ReceiveTimeout* | Time-out value applied when receiving a packet of response data from the target server, in milliseconds. Large responses are be broken up into multiple packets; the receive time-out applies to fetching each packet of data off the socket. The default value is 30,000 (30 seconds). |

#### Return value

Returns S_OK (0) if successful or an error value otherwise.

#### Remarks

All parameters are required. A value of 0 or -1 sets a time-out to wait infinitely. A value greater than 0 sets the time-out value in milliseconds. For example, 30,000 would set the time-out to 30 seconds. All negative values other than -1 cause this method to fail.

Time-out values are applied at the Winsock layer.


# <a name="WaitForResponse"></a>WaitForResponse

Waits for an asynchronous **Send** method to complete, with optional time-out value, in seconds.

```
FUNCTION WaitForResponse (BYVAL nTimeout AS LONG = 0) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *nTimeout* | Optional. Time-out value, in seconds. Default time-out is infinite. To explicitly set time-out to infinite, use the value -1. |

#### Return value

TRUE or FALSE.

#### Remarks

This method suspends execution while waiting for a response to an asynchronous request. This method should be called after a **Send**. Calling applications can specify an optional Timeout value, in seconds. If this method times out, the request is not aborted. This way, the calling application can continue to wait for the request, if desired, in a subsequent call to this method.

Calling this property after a synchronous **Send** method returns immediately and has no effect.


# <a name="WinHttpRequestAutoLogonPolicy"></a>WinHttpRequestAutoLogonPolicy Enumeration

The WinHttpRequestAutoLogonPolicy enumeration includes possible settings for the Automatic Logon Policy.

| Constant   | Description |
| ---------- | ----------- |
| **AutoLogonPolicy_Always** | An authenticated log on, using the default credentials, is performed for all requests. |
| **AutoLogonPolicy_OnlyIfBypassProxy** | An authenticated log on, using the default credentials, is performed only for requests on the local intranet. The local intranet is considered to be any server on the proxy bypass list in the current proxy configuration. |
| **AutoLogonPolicy_Never** | Authentication is not used automatically. |

#### Remarks

To set the automatic logon policy, call the **SetAutoLogonPolicy** method and specify one of the preceding constants.

# <a name="WinHttpRequestOption"></a>WinHttpRequestOption Enumeration

The WinHttpRequestOption enumeration includes options that can be set or retrieved for the current Microsoft Windows HTTP Services (WinHTTP) session.

| Constant   | Description |
| ---------- | ----------- |
| **WinHttpRequestOption_UserAgentString** | Sets or retrieves a VARIANT that contains the user agent string. |
| **WinHttpRequestOption_URL** | Retrieves a VARIANT that contains the URL of the resource. This value is read-only; you cannot set the URL using this property. The URL cannot be read until the **Open** method is called. This option is useful for checking the URL after the **Send** method is finished to verify that any redirection occurred. |
| **WinHttpRequestOption_URLCodePage** | Sets or retrieves a VARIANT that identifies the code page for the URL string. The default value is the UTF-8 code page. The code page is used to convert the Unicode URL string, passed in the **Open** method, to a single-byte string representation. |
| **WinHttpRequestOption_EscapePercentInURL** | Sets or retrieves a VARIANT that indicates whether percent characters in the URL string are converted to an escape sequence. The default value of this option is VARIANT_TRUE which specifies all unsafe American National Standards Institute (ANSI) characters except the percent symbol are converted to an escape sequence. |
| **WinHttpRequestOption_SslErrorIgnoreFlags** | Sets or retrieves a VARIANT that indicates which server certificate errors should be ignored. This can be a combination of one or more of the following flags.<br>**&H0100**: Unknown certification authority (CA) or untrusted root.<br>**&H0200**: Wrong usage.<br>**&H1000**: Invalid common name (CN)<br>**&H2000**: Invalid date or certificate expired.<br>The default value of this option in Version 5.1 of WinHTTP is zero, which results in no errors being ignored. In earlier versions of WinHTTP, the default setting was 0x3300, which resulted in all server certificate errors being ignored by default. |
| **WinHttpRequestOption_SelectCertificate** | Sets a VARIANT that specifies the client certificate that is sent to a server for authentication. This option indicates the location, certificate store, and subject of a client certificate delimited with backslashes. For more information about selecting a client certificate, see [SSL in WinHTTP](https://docs.microsoft.com/en-us/windows/desktop/winhttp/ssl-in-winhttp). |
| **WinHttpRequestOption_EnableRedirects** | Sets or retrieves a VARIANT that indicates whether requests are automatically redirected when the server specifies a new location for the resource. The default value of this option is VARIANT_TRUE to indicate that requests are automatically redirected. |
| **WinHttpRequestOption_UrlEscapeDisable** | Sets or retrieves a VARIANT that indicates whether unsafe characters in the path and query components of a URL are converted to escape sequences. The default value of this option is VARIANT_TRUE, which specifies that characters in the path and query are converted. |
| **WinHttpRequestOption_UrlEscapeDisableQuery** | Sets or retrieves a VARIANT that indicates whether unsafe characters in the query component of the URL are converted to escape sequences. The default value of this option is VARIANT_TRUE, which specifies that characters in the query are converted. |
| **WinHttpRequestOption_SecureProtocols** | Sets or retrieves a VARIANT that indicates which secure protocols can be used. This option selects the protocols acceptable to the client. The protocol is negotiated during the Secure Sockets Layer (SSL) handshake. This can be a combination of one or more of the following flags:<be>**&H0008**: SSL 2.0.<br>**&H0020**: SSL 3.0.<br>**&H0080**:Transport Layer Security (TLS) 1.0.<br>The default value of this option is 0x0028, which indicates that SSL 2.0 or SSL 3.0 can be used. If this option is set to zero, the client and server are not able to determine an acceptable security protocol and the next **Send** results in an error. |
| **WinHttpRequestOption_EnableTracing** | Sets or retrieves a VARIANT that indicates whether tracing is currently enabled. For more information about the trace facility in Microsoft Windows HTTP Services (WinHTTP), see [WinHTTP Trace Facility](https://docs.microsoft.com/en-us/windows/desktop/winhttp/winhttptracecfg-exe--a-trace-configuration-tool). |
| **WinHttpRequestOption_RevertImpersonationOverSsl** | Controls whether the WinHttpRequest object temporarily reverts client impersonation for the duration of the SSL certificate authentication operations. The default setting for the WinHttpRequest object is TRUE. Set this option to FALSE to keep impersonation while performing certificate authentication operations. |
| **WinHttpRequestOption_EnableHttpsToHttpRedirects** | Controls whether or not WinHTTP allows redirects. By default, all redirects are automatically followed, except those that transfer from a secure (https) URL to an non-secure (http) URL. Set this option to TRUE to enable HTTPS to HTTP redirects. |
| **WinHttpRequestOption_EnablePassportAuthentication** | Enables or disables support for Passport authentication. By default, automatic support for Passport authentication is disabled; set this option to TRUE to enable Passport authentication support. |
| **WinHttpRequestOption_MaxAutomaticRedirects** | Sets or retrieves the maximum number of redirects that WinHTTP follows; the default is 10. This limit prevents unauthorized sites from making the WinHTTP client stall following a large number of redirects. |
| **WinHttpRequestOption_MaxResponseHeaderSize** | Sets or retrieves a bound set on the maximum size of the header portion of the server’s response. This bound protects the client from a malicious server attempting to stall the client by sending a response with an infinite amount of header data. The default value is 64 KB. |
| **WinHttpRequestOption_MaxResponseDrainSize** | Sets or retrieves a bound on the amount of data that will be drained from responses in order to reuse a connection. The default is 1 MB. |
| **WinHttpRequestOption_EnableHttp1_1** | Sets or retrieves a boolean value that indicates whether HTTP/1.1 or HTTP/1.0 should be used. The default is TRUE, so that HTTP/1.1 is used by default. |
| **WinHttpRequestOption_EnableCertificateRevocationCheck** | Enables server certificate revocation checking during SSL negotiation. When the server presents a certificate, a check is performed to determine whether the certificate has been revoked by its issuer. If the certificate is indeed revoked, or the revocation check fails because the Certificate Revocation List (CRL) cannot be downloaded, the request fails; such revocation errors cannot be suppressed. |

#### Remarks

Set an option by specifying one of the preceding constants as the parameter of the **Option** property.

# <a name="WinHttpRequestSecureProtocols"></a>WinHttpRequestSecureProtocols Enumeration

The WinHttpRequestOption enumeration includes options that can be set or retrieved for the current Microsoft Windows HTTP Services (WinHTTP) session.

| Constant   | Description |
| ---------- | ----------- |
| **SecureProtocol_SSL2** | SSL 2.0 |
| **SecureProtocol_SSL3** | SSL 3.0 |
| **SecureProtocol_TLS1** | Transport Layer Security (TLS) 1.0. |
| **SecureProtocol_ALL** | All the protocols. |

