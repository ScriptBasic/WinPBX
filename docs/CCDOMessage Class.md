# CCDOMessage Class

Collaboration Data Objects (CDO) is a Component Object Model (COM) component designed to simplify writing programs that create or manipulate Internet messages. It supports creating and managing messages formatted and sent using Internet standards such as the Multipurpose Internet Mail Extensions (MIME) standard. CDO supports sending messages using both the SMTP and NNTP protocols, as well as through a local SMTP/NNTP service pickup directory. CDO integrates with the Microsoft® ActiveX® Data Objects (ADO) component to present a consistent mechanism for managing data that comprises a message.

**CCDOMessage** is a Free Basic class that allows to send messages using CDO.

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
