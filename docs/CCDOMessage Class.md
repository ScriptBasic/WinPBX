# CCDOMessage Class

Collaboration Data Objects (CDO) is a Component Object Model (COM) component designed to simplify writing programs that create or manipulate Internet messages. It supports creating and managing messages formatted and sent using Internet standards such as the Multipurpose Internet Mail Extensions (MIME) standard. CDO supports sending messages using both the SMTP and NNTP protocols, as well as through a local SMTP/NNTP service pickup directory. CDO integrates with the Microsoft® ActiveX® Data Objects (ADO) component to present a consistent mechanism for managing data that comprises a message.

**CCDOMessage** is a Free Basic class that allows to send messages using CDO.

**Include file:** CCDoMessage.inc.

#### Example

```
' // Create an instance of the CCdoMessage class
DIM pMsg AS CCDOMessage

' // Configuration
pMsg.ConfigValue(cdoSendUsingMethod, CdoSendUsingPort)
pMsg.ConfigValue(cdoSMTPServer, "smtp.xxxxx.xxx")
pMsg.ConfigValue(cdoSMTPServerPort, 25)
pMsg.ConfigValue(cdoSMTPAuthenticate, 1)
pMsg.ConfigValue(cdoSendUserName, "xxxx@xxxx.xxx")
pMsg.ConfigValue(cdoSendPassword, "xxxxxxxx")
pMsg.ConfigValue(cdoSMTPUseSSL, 1)
pMsg.ConfigUpdate
 
' // Recipient name --> change as needed
pMsg.Recipients("xxxxx@xxxxx")
' // Sender mail address --> change as needed
pMsg.From("xxxxx@xxxxx")
' // Subject --> change as needed
pMsg.Subject("This is a sample subject")
' // Text body --> change as needed
pMsg.TextBody("This is a sample message text")
' // Add the attachment (use absolute paths).
' // Note  By repeating the call you can attach more than one file.
pMsg.AddAttachment ExePath & "\xxxxx.xxx"
' // Send the message
pMsg.Send
IF pMsg.GetLastResult = S_OK THEN PRINT "Message sent" ELSE PRINT "Failure"

To send messages using gmail, simply change the values of the server name and the server port:

pMsg.ConfigValue(cdoSMTPServer, "smtp.gmail.com")
pMsg.ConfigValue(cdoSMTPServerPort, 465)
```

### Methods

| Name       | Description |
| ---------- | ----------- |
| [AddAttachment](#AddAttachment) | Adds an attachment to the message. |
| [BCC](#BCC) | The blind carbon copy (Bcc) recipients for the message. |
| [CC](#CC) | The secondary (carbon copy) recipients for this message. |
| [ConfigUpdate](#ConfigUpdate) | Saves the changes you make to the **Fields** collection of the CDO **IConfiguration** interface. |
| [ConfigValue](#ConfigValue) | Sets the value of the specified configuration field. |
| [DSNOptions](#DSNOptions) | Includes a request for a return report on the delivery status of the message. |
| [FollowUpTo](#FollowUpTo) | Newsgroups to which any responses to this message are posted. |
| [From](#From) | The messaging address of the principal author of the message. |
| [GetLastResult](#GetLastResult) | Returns the last result code. |
| [HTMLBody](#HTMLBody) | The Hypertext Markup Language (HTML) representation of the message. |
| [Keywords](#Keywords) | The list of keywords for the message. |
| [MDNRequested](#MDNRequested) | Indicates whether a Message Disposition Notification is requested on a message. |
| [MimeFormatted](#MimeFormatted) | Indicates whether a Message Disposition Notification is requested on a message. |
| [Newsgroups](#Newsgroups) | The newsgroup recipients for the message. |
| [Organization](#Organization) | The organization of the sender. |
| [Post](#Post) | Submits this message to the specified newsgroups. |
| [Recipients](#Recipients) | The principal (To) recipients for this message. |
| [ReplyTo](#ReplyTo) | The messaging addresses to which replies to this message should be sent. |
| [Send](#Send) | Sends the message. |
| [Sender](#Sender) | The messaging address of the message submitter. |
| [Subject](#Subject) | The message subject. |
| [TextBody](#TextBody) | The plain text representation of the message. |

# <a name="AddAttachment"></a>AddAttachment

Adds an attachment to the message.

```
FUNCTION AddAttachment (BYREF cbsURL AS CBSTR, BYREF cbsUserName AS CBSTR = "", _
   BYREF cbsPassword AS CBSTR = "") AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsURL* | The full path and file name of the message to be attached to this message. |
| *cbsUserName* | An optional user name to use for authentication when retrieving the resource using Hypertext Tranfer Protocol (HTTP). Can be used to set the credentials for both the basic and NTLM authentication mechanisms. |
| *cbsPassword* | An optional password to use for authentication when retrieving the resource using the HTTP. Can be used to set the credentials for the basic and NTLM authentication mechanisms. |

Return value

S_OK or an HRESULT code.

Remarks

The AddAttachment method adds the attachment by first retrieving the resource specified by the Uniform Resource Locator (URL) and then adding the content to the message's Attachments collection within a BodyPart object.

The URL prefixes supported in the URL parameter are file://, ftp://, http://, and https://. The default prefix is file://. This facilitates designation of paths starting with drive letters and of universal naming convention (UNC) paths.

The MIMEFormatted property determines how the attachment is formatted when the message is serialized for delivery to a Simple Mail Transfer Protocol (SMTP) service. If this property is set to True, the attachment is formatted using Multipurpose Internet Mail Extensions (MIME). If the property is set to False, the attachment is added to the serialized content stream in Uuencoded format.

If you populate the HTMLBody property before calling the AddAttachment method, any inline images are displayed as part of the message.

Use the UserName and Password parameters when you are requesting Web pages using Hypertext Transfer Protocol (HTTP) from a server that requires client authentication. If the Web server supports only the basic authentication mechanism, these credentials must be supplied. If the Web server supports the NTLM authentication mechanism, by default, the current process security context is used to authenticate; however, you can specify alternate credentials for NTLM authentication with the **UserName** and **Password** properties.

Important Storing user names and passwords inside source code can lead to security vulnerabilities in your software. Do not store user names and passwords in your production code.

# <a name="BCC"></a>BCC

The blind carbon copy (Bcc) recipients for the message.

```
FUNCTION BCC (BYREF cbsBCC AS CBSTR PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cbsBCC* | The string in the BCC method can represent a single recipient or multiple recipients. Each address in the list must be a full messaging address, such as "User" \<example@example.com> or example@example.com.<br>In lists of multiple recipients, commas separate addresses, as follows: "User1" \<example1@example.com >, "User 2" \<example2@example.com>, "User3" \<example3@example.com><br>A comma is not valid in any part of a messaging address unless it is enclosed in quotation marks.<br>To maintain the privacy intended by blind copies, **BCC** is regarded as an envelope property rather than a message property; accordingly, the corresponding header field and its contents are removed when the message is delivered, and the **BCC** property is always empty on a received message.<br>The default value of the **BCC** property is an empty string. |

#### Return value

S_OK or an HRESULT code.
