' ########################################################################################
' Microsoft Windows
' File: CAfxSmtpMail.inc
' Contents: SMTP email class.
' Based on code posted by Paul Squires at:
' http://www.powerbasic.com/support/pbforums/showthread.php?t=41961&highlight=tcp
' with minimal changes by José Roca (also changed the logic of the return value of the
' SendMail method).
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXSMTPMAIL_INC = 1

#INCLUDE ONCE "windows.inc"

' ===========================================================================================
' Class CAfxSmtpMail.
' ===========================================================================================
CLASS CAfxSmtpMail

   INSTANCE m_SMTPPort     AS LONG     ' // Port number
   INSTANCE m_Timeout      AS LONG     ' // Timeout
   INSTANCE m_EnableAuth   AS LONG     ' // Enable authenticationh (TRUE or FALSE)
   INSTANCE m_Server       AS STRING   ' // Server name
   INSTANCE m_From         AS STRING   ' // Sender name
   INSTANCE m_ReplyTo      AS STRING   ' // Reply email address
   INSTANCE m_TO           AS STRING   ' // Comma delimited list of recipient addresses
   INSTANCE m_CC           AS STRING   ' // Carbon copy: comma delimited list of recipient addresses
   INSTANCE m_BCC          AS STRING   ' // Blind carbon copy: comma delimited list of recipient addresses
   INSTANCE m_Subject      AS STRING   ' // Subject
   INSTANCE m_PlainMessage AS STRING   ' // Plain text message
   INSTANCE m_HTMLMessage  AS STRING   ' // HTML message
   INSTANCE m_Response     AS STRING   ' // Response text
   INSTANCE m_AuthType     AS STRING   ' // Authentication type
   INSTANCE m_AuthUsername AS STRING   ' // Authentication user name
   INSTANCE m_AuthPassword AS STRING   ' // Authentication password
   INSTANCE m_Style        AS STRING   ' // Message style
   INSTANCE m_Attachments  AS STRING   ' // Comma delimited list of attachments
   INSTANCE m_LocalHost    AS STRING   ' // Local host name
   INSTANCE m_CharSet      AS STRING   ' // Character set


   ' ========================================================================================
   ' Constructor. Initializes default properties.
   ' ========================================================================================
   CLASS METHOD CREATE
      m_Timeout = 60000   ' (60 seconds)
      m_CharSet = "iso-8859- 1"
      m_Style   = "plain"
      HOST NAME TO m_LocalHost
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Private method. Base64 encoding.
   ' ========================================================================================
   CLASS METHOD MimeEncode (BYVAL sFileData AS STRING) AS STRING

      LOCAL lBlock, lcBlocks, lByte1, lByte2, lByte3, lIndex1, lIndex2, lIndex3, lIndex4 AS LONG
      LOCAL pInput, pOutput, pTable AS BYTE PTR
      LOCAL sBase64, sResult, Pad AS STRING

      sBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"   ' // Base64 table
      Pad = STRING$(2 - (LEN(sFileData) - 1) MOD 3, "=")          ' // Calculate padding on Base64 stream

      lcBlocks = (LEN(sFileData) + 2) \ 3                         ' // Round up the length of the input
      IF lcBlocks * 3 > LEN(sFileData) THEN                       ' // data to a multiple of three
         sFileData = LSET$(sFileData, lcBlocks * 3 USING $NUL)
      END IF

      sResult = SPACE$(lcBlocks * 4)                              ' // Allocate space for output string

      pInput  = STRPTR(sFileData)                                 ' // Set up pointers so we can treat
      pOutput = STRPTR(sResult)                                   ' // the data as byte streams
      pTable  = STRPTR(sBase64)

      FOR lBlock = 1 TO lcBlocks                                  ' // Loop through the input buffer
         lByte1 = @pInput : INCR pInput                           ' // Get the next three binary data-
         lByte2 = @pInput : INCR pInput                           ' // bytes to process
         lByte3 = @pInput : INCR pInput

         lIndex1 = lByte1 \ 4                                     ' // Translate 3 databytes to 4 Base64
         lIndex2 = (lByte1 AND 3) * 16 + lByte2 \ 16              ' // table indices
         lIndex3 = (lByte2 AND 15) * 4 + lByte3 \ 64
         lIndex4 = lByte3 AND 63

         @pOutput = @pTable[lIndex1] : INCR pOutput               ' // Use Base64 table to encode the
         @pOutput = @pTable[lIndex2] : INCR pOutput               ' // output string
         @pOutput = @pTable[lIndex3] : INCR pOutput
         @pOutput = @pTable[lIndex4] : INCR pOutput
      NEXT
      RSET ABS sResult = Pad                                      ' // Merge in the padding bytes
      METHOD = sResult
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Gets the local time.
   ' ========================================================================================
   CLASS METHOD GetMailDateTime () AS STRING

      ' // Retrieve the current time and date to put in E-mail header format
      LOCAL szFormat   AS ASCIIZ * 40
      LOCAL szTemp     AS ASCIIZ * 40
      LOCAL sResult    AS STRING
      LOCAL t          AS SYSTEMTIME
      LOCAL sUCTOffset AS STRING
      LOCAL tzi        AS TIME_ZONE_INFORMATION

      GetLocalTime t

      szFormat = "ddd',' dd MMM yyyy"
      GetDateFormat %LOCALE_USER_DEFAULT, 0, t, szFormat, szTemp, SIZEOF(szTemp)

      sResult = szTemp

      szFormat = "HH':'mm':'ss"
      GetTimeFormat %LOCALE_USER_DEFAULT, 0, t, szFormat, szTemp, SIZEOF(szTemp)

      SELECT CASE GetTimeZoneInformation(tzi)
         CASE %TIME_ZONE_ID_DAYLIGHT
            sUCTOffset = IIF$((tzi.bias + tzi.DaylightBias) <= 0, "+", "-") _
                       + FORMAT$(ABS(tzi.bias + tzi.DaylightBias) \ 60, "00") _
                       + FORMAT$(ABS(tzi.bias + tzi.DaylightBias) MOD 60, "00")
         CASE %TIME_ZONE_ID_STANDARD
            sUCTOffset = IIF$((tzi.bias + tzi.StandardBias) <= 0, "+", "-") _
                       + FORMAT$(ABS(tzi.bias + tzi.StandardBias) \ 60, "00") _
                       + FORMAT$(ABS(tzi.bias + tzi.StandardBias) MOD 60, "00")
         CASE ELSE
            sUCTOffset = "-0000"
      END SELECT

      METHOD = sResult & " " & szTemp & " " & sUCTOffset

   END METHOD
   ' ========================================================================================

   INTERFACE IAfxSmtpMail : INHERIT IUnknown

   ' ========================================================================================
   ' Gets/set the SMTP server name.
   ' ========================================================================================
   PROPERTY GET SMTPServer () AS STRING
      PROPERTY = m_Server
   END PROPERTY
   ' ========================================================================================
   ' ========================================================================================
   PROPERTY SET SMTPServer (BYVAL sServerName AS STRING)
      m_Server = RTRIM$(sServername)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Optional. Gets/sets the SMTP port number.
   ' ========================================================================================
   PROPERTY GET SMTPPort () AS LONG
      PROPERTY = m_SMTPPort
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET SMTPPort (BYVAL nSMTPPort AS LONG)
      m_SMTPPort = nSMTPPort
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the sender name.
   ' ========================================================================================
   PROPERTY GET SendFrom () AS STRING
      PROPERTY = m_From
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET SendFrom (BYVAL sSender AS STRING)
      m_From = RTRIM$(sSender)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets&sets the recipient name.
   ' ========================================================================================
   PROPERTY GET SendTo () AS STRING
      PROPERTY = m_TO
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET SendTo (BYVAL sRecipientTo AS STRING)
      m_TO = RTRIM$(sRecipientTo)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Carbon copy. Comma delimited list of recipient addresses.
   ' ========================================================================================
   PROPERTY GET CC () AS STRING
      PROPERTY = m_CC
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET CC (BYVAL sRecipientCC AS STRING)
      m_CC = RTRIM$(sRecipientCC)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Blind carbon copy. Comma delimited list of recipient addresses.
   ' ========================================================================================
   PROPERTY GET BCC () AS STRING
      PROPERTY = m_BCC
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET BCC (BYVAL sRecipientBCC AS STRING)
      m_BCC = RTRIM$(sRecipientBCC)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Email address to reply.
   ' ========================================================================================
   PROPERTY GET ReplyTo () AS STRING
      PROPERTY = m_ReplyTo
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET ReplyTo (BYVAL sReplyTo AS STRING)
      m_ReplyTo = RTRIM$(sReplyTo)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Subject.
   ' ========================================================================================
   PROPERTY GET Subject () AS STRING
      PROPERTY = m_Subject
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET Subject (BYVAL sSubject AS STRING)
      m_Subject = sSubject
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Plain text message.
   ' ========================================================================================
   PROPERTY GET PlainMessage () AS STRING
      PROPERTY = m_PlainMessage
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET PlainMessage (BYVAL sPlainMessage AS STRING)
      m_PlainMessage = sPlainMessage
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' HTML message
   ' ========================================================================================
   PROPERTY GET HTMLMessage () AS STRING
      PROPERTY = m_HTMLMessage
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET HTMLMessage (BYVAL sHTMLMessage AS STRING)
      m_HTMLMessage = sHTMLMessage
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets the response text.
   ' ========================================================================================
   PROPERTY GET Response () AS STRING
      PROPERTY = m_Response
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Boolean TRUE or FALSE. Enable authentication.
   ' ========================================================================================
   PROPERTY GET EnableAuth () AS LONG
      PROPERTY = m_EnableAuth
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET EnableAuth (BYVAL nEnableAuth AS LONG)
      m_EnableAuth = nEnableAuth
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the authentication type: "AUTH LOGIN", "AUTH PLAIN", "AUTH CRAM-MD5".
   ' ========================================================================================
   PROPERTY GET AuthType () AS STRING
      PROPERTY = m_AuthType
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET AuthType (BYVAL sAuthType AS STRING)
      m_AuthType = RTRIM$(sAuthType)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the authentication user name.
   ' ========================================================================================
   PROPERTY GET AuthUserName () AS STRING
      PROPERTY = m_AuthUserName
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET AuthUserName (BYVAL sAuthUserName AS STRING)
      m_AuthUserName = RTRIM$(sAuthUserName)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the authentication password.
   ' ========================================================================================
   PROPERTY GET AuthPassword () AS STRING
      PROPERTY = m_AuthPassword
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET AuthPassword (BYVAL sAuthPassword AS STRING)
      m_AuthPassword = RTRIM$(sAuthPassword)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the message style. Must be "PLAIN", "HTML" or "BOTH"
   ' ========================================================================================
   PROPERTY GET MessageStyle () AS STRING
      PROPERTY = m_Style
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET MessageStyle (BYVAL sMessageStyle AS STRING)
      m_Style = UCASE$(RTRIM$(sMessageStyle))
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the server timeout.
   ' ========================================================================================
   PROPERTY GET ServerTimeout () AS LONG
      PROPERTY = m_Timeout
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET ServerTimeout (BYVAL nServerTimeout AS LONG)
      m_Timeout = nServerTimeout
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the the comma delimited list of attachments.
   ' ========================================================================================
   PROPERTY GET Attachments () AS STRING
      PROPERTY = m_Attachments
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET Attachments (BYVAL sAttachments AS STRING)
      m_Attachments = RTRIM$(sAttachments)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the local host name.
   ' ========================================================================================
   PROPERTY GET LocalHost () AS STRING
      PROPERTY = m_LocalHost
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET LocalHost (BYVAL sLocalHost AS STRING)
      m_LocalHost = RTRIM$(sLocalHost)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Gets/sets the character set name.
   ' ========================================================================================
   PROPERTY GET CharSet () AS STRING
      PROPERTY = m_CharSet
   END PROPERTY
   ' ========================================================================================
   PROPERTY SET CharSet (BYVAL sCharSet AS STRING)
      m_CharSet = RTRIM$(sCharSet)
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Sends the email.
   ' Return value: TRUE on succes or FALSE on failure.
   ' Call the Response property to get the response text.
   ' ========================================================================================
   ' *** SMTP Error codes ***
   ' 211 - A system status message.
   ' 214 - A help message for a human reader follows.
   ' 220 - SMTP Service ready.
   ' 221 - Service closing.
   ' 250 - Requested action taken and completed. The best message of them all.
   ' 251 - The recipient is not local to the server, but the server will accept and forward the message.
   ' 252 - The recipient cannot be VRFYed, but the server accepts the message and attempts delivery.

   ' 354 - Start message input and end with <CRLF>.<CRLF>. This indicates that the server is ready to
   '       accept the message itself (after you have told it who it is from and where you want to to go).
   ' 421 - The service is not available and the connection will be closed.
   ' 450 - The requested command failed because the user's mailbox was unavailable (for example because
   '       it was locked). Try again later.
   ' 451 - The command has been aborted due to a server error. Not your fault. Maybe let the admin know.
   ' 452 - The command has been aborted because the server has insufficient system storage.
   ' 500 - The server could not recognize the command due to a syntax error.
   ' 501 - A syntax error was encountered in command arguments.
   ' 502 - This command is not implemented.
   ' 503 - The server has encountered a bad sequence of commands.
   ' 504 - A command parameter is not implemented.
   ' 550 - The requested command failed because the user's mailbox was unavailable (for example because
   '       it was not found, or because the command was rejected for policy reasons).
   ' 551 - The recipient is not local to the server. The server then gives a forward address to try.
   ' 552 - The action was aborted due to exceeded storage allocation.
   ' 553 - The command was aborted because the mailbox name is invalid.
   ' 554 - The transaction failed.
   ' ========================================================================================
   METHOD SendMail () AS LONG

      LOCAL hTCP           AS LONG
      LOCAL y              AS LONG
      LOCAL f              AS LONG
      LOCAL z              AS LONG
      LOCAL NumLines       AS LONG
      LOCAL errcode        AS LONG
      LOCAL sTmp           AS STRING
      LOCAL sBuffer        AS STRING
      LOCAL sBoundary      AS STRING
      LOCAL sAllRecipients AS STRING
      LOCAL NumAttachments AS LONG

      ' // Make a unique file data boundary marker
      sBoundary = "Boundary." & REMOVE$(GUIDTXT$(GUID$), ANY "{-}")

      ' // Connect to E-mail server (mailhost)
      hTCP = FREEFILE
      IF m_SMTPPort > 0 THEN
         TCP OPEN PORT m_SMTPPort AT m_Server AS hTCP TIMEOUT m_Timeout
      ELSE
         TCP OPEN "smtp" AT m_Server AS hTCP TIMEOUT m_Timeout
      END IF

      m_Response = "Cannot connect to E-mail server: " & m_Server
      errcode = ERR
      IF ERR THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "220" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      ' // Get the local host name
      IF RTRIM$(m_LocalHost) = "" THEN m_LocalHost = "localhost"

      ' // Greet the mailhost
      TCP PRINT hTCP, "HELO " & m_LocalHost
      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "250" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      ' // Send authentication if required
      IF m_EnableAuth THEN

         DO WHILE NOT EOF(hTCP)
            TCP LINE hTCP, sBuffer
            errcode = VAL(LEFT$(sBuffer, 3))
         LOOP
         TCP PRINT hTCP, m_AuthType

         DO WHILE NOT EOF(hTCP)
            TCP LINE hTCP, sBuffer
            errcode = VAL(LEFT$(sBuffer, 3))
         LOOP

         IF errcode = 334 THEN
            sTmp = ME.MimeEncode(m_AuthUsername)      ' // UserId (might be the same as the POP3 UserId)
            TCP PRINT hTCP, sTmp
            DO WHILE NOT EOF(hTCP)
               TCP LINE hTCP, sBuffer
               errcode = VAL(LEFT$(sBuffer, 3))
            LOOP
            IF errcode = 334 THEN
               sTmp = ME.MimeEncode(m_AuthPassword)  ' // Password (might be the same as the POP3 password)
               TCP PRINT hTCP, sTmp
               DO WHILE NOT EOF(hTCP)
                  TCP LINE hTCP, sBuffer
                  errcode = VAL(LEFT$(sBuffer, 3))
               LOOP
            END IF
         END IF

      END IF

      ' // Tell the mailhost who we are
      TCP PRINT hTCP, "MAIL FROM:<" & m_From & ">"
      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "250" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      ' // Tell the mailhost who the message is for.
      ' // There could be multiple recipients so iterate through
      ' // the semicolon or comma deliminated list. The total RCPT
      ' // list is the combination of the TO, CC, BCC lists.
      sAllRecipients = m_TO & ";" & m_CC & ";" & m_BCC

      NumLines = PARSECOUNT(sAllRecipients, ANY ";,")
      REDIM sArray(1 TO NumLines) AS STRING
      PARSE sAllRecipients, sArray(), ANY ";,"

      FOR y = 1 TO NumLines
         sTmp = RTRIM$(sArray(y))
         IF LEN(sTmp) THEN
            TCP PRINT hTCP, "RCPT TO:<" & sTmp & ">"
            TCP LINE hTCP, m_Response
            IF LEFT$(m_Response, 3) <> "250" THEN
               TCP CLOSE hTCP
               EXIT METHOD
            END IF
         END IF
      NEXT

      ' // Send the message
      TCP PRINT hTCP, "DATA"
      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "354" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      ' // The E-mail header
      TCP PRINT hTCP, "Date: " & ME.GetMailDateTime
      TCP PRINT hTCP, "From: " & m_From

      TCP PRINT hTCP, "To: " & m_To

      IF LEN(m_ReplyTo) THEN
         TCP PRINT hTCP, "Reply-To: " & m_ReplyTo
      END IF

      IF LEN(m_CC) THEN
         TCP PRINT hTCP, "Cc: "  & m_CC
      END IF

      ' // Obviously we won't output the BCC list to the email

      TCP PRINT hTCP, "Subject: " & m_Subject

      TCP PRINT hTCP, "X-Mailer: pMailer Mail"
      TCP PRINT hTCP, "MIME-Version: 1.0"

      TCP PRINT hTCP, "Content-Type: multipart/mixed; boundary=" & $DQ & sBoundary & $DQ
      TCP PRINT hTCP, ""


      ' // Create a main E-mail body section for the Plain message.
      ' // Break the message down into lines.

      IF (m_Style = "PLAIN") OR (m_Style = "BOTH") THEN
         TCP PRINT hTCP, "--" & sBoundary
         TCP PRINT hTCP, "Content-Type: text/plain; charset=" & $DQ & m_CharSet & $DQ
         TCP PRINT hTCP, "Content-Transfer-Encoding: 7bit"
         TCP PRINT hTCP, ""

        ' Any crlf pairs or plain lf's will be replaced with cr's for easy parsing
         REPLACE $CRLF WITH $CR IN m_PlainMessage
         REPLACE $LF   WITH $CR IN m_PlainMessage

         NumLines = PARSECOUNT( m_PlainMessage, $CR )
         REDIM sArray(1 TO NumLines) AS STRING
         PARSE m_PlainMessage, sArray(), $CR

         FOR y = 1 TO NumLines
            TCP PRINT hTCP, sArray(y)
         NEXT
      END IF

      IF (m_Style = "HTML") OR (m_Style = "BOTH") THEN
         TCP PRINT hTCP, "--" & sBoundary
         TCP PRINT hTCP, "Content-Type: text/html; charset=" & $DQ & m_CharSet & $DQ
         TCP PRINT hTCP, "Content-Transfer-Encoding: 7bit"
         TCP PRINT hTCP, ""

        ' // Any CR>LF pairs or plain lf's will be replaced with cr's for easy parsing.
         REPLACE $CRLF WITH $CR IN m_HTMLMessage
         REPLACE $LF   WITH $CR IN m_HTMLMessage

         NumLines = PARSECOUNT( m_HTMLMessage, $CR )
         REDIM sArray(1 TO NumLines) AS STRING
         PARSE m_HTMLMessage, sArray(), $CR

         FOR y = 1 TO NumLines
            TCP PRINT hTCP, sArray(y)
         NEXT
      END IF


      ' // Create the attachment body section
      IF LEN(m_Attachments) > 0 THEN
         NumAttachments = PARSECOUNT( m_Attachments, ANY ";," )
         REDIM sArray(1 TO NumAttachments) AS STRING
         PARSE m_Attachments, sArray(), ANY ";,"

         FOR y = 1 TO NumAttachments
            IF DIR$(sArray(y)) = "" THEN ITERATE FOR

            f = FREEFILE
            OPEN sArray(y) FOR BINARY AS #f
            GET$ #f, LOF(f), sBuffer
            CLOSE #f

            ' // Encode the file
            sBuffer = ME.MimeEncode(sBuffer)

            TCP PRINT hTCP, "--" & sBoundary
            TCP PRINT hTCP, "Content-Type: application/octet-stream; name=" & $DQ & PATHNAME$(NAMEX, sArray(y)) & $DQ
            TCP PRINT hTCP, "Content-Transfer-Encoding: base64"
            TCP PRINT hTCP, ""

            ' // Write the encoded data in lines of 76 characters.  Add an equality
            ' // character if the last line is less than 76 bytes long
            FOR z = 1 TO LEN(sBuffer) STEP 76
               IF LEN(sBuffer) - z >= 76 THEN
                  TCP PRINT hTCP, MID$(sBuffer, z, 76)
               ELSE
                  TCP PRINT hTCP, MID$(sBuffer, z) & "="
               END IF
            NEXT

         NEXT
      END IF

      ' // Send the terminating boundary marker.
      TCP PRINT hTCP, "--" & sBoundary & "--"

      ' // Now finish the E-mail off as we're done sending the message.
      TCP PRINT hTCP, "."
      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "250" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      ' // Say goodbye
      TCP PRINT hTCP, "QUIT"
      TCP LINE hTCP, m_Response
      IF LEFT$(m_Response, 3) <> "221" THEN
         TCP CLOSE hTCP
         EXIT METHOD
      END IF

      TCP CLOSE hTCP   ' // Close the port

      METHOD = %TRUE   ' // Success

   END METHOD
   ' ========================================================================================

   END INTERFACE

END CLASS
' ===========================================================================================

' ===========================================================================================
' Usage example.
' ===========================================================================================
'#COMPILE EXE
'#INCLUDE "CAfxSmtpMail.inc"

'FUNCTION PBMAIN () AS LONG

'   ' NOTES:
'   ' The 'SendTo', 'CC', 'BCC' fields can be a one address or a
'   ' semicolon(;) or comma(,) deliminated list of multiple addresses.
'   ' SMTP only allows 100 recipients max at a time (per rfc821), therefore
'   ' for large mailings you should break it into multiple emails.

'   ' Multiple attachments can be sent by simply separating the file
'   ' names with a semicolon or comma.

'   ' You can use 'Plain' text emails or 'HTML' emails, or 'Both'.
'   ' When sending "Both", the email client application will use whichever
'   ' one it can render based on the user's settings.

'   ' Default values for the following that are already set by the
'   ' class (constructor). Change them here if you want a different value.
'   ' e.g.
'   ' cMail.ServerTimeOut = 60000  ' milliseconds  ' default is 60000
'   ' cMail.LocalHost     = "MySuperComputer"      ' default is localhost
'   ' cMail.CharSet       = "us-ascii"             ' default is iso-8859-1
'   ' cMail.MessageStyle  = "both"                 ' default is Plain

'   LOCAL cMail AS IAfxSmtpMail
'   cMail = CLASS "CAfxSmtpMail"

'   cMail.SMTPServer   = "mysmtpxxxx.com"
'   cMail.SendFrom     = "support@planetsquires.com"
'   cMail.SendTo       = "support@planetsquires.com"
'   cMail.CC           = "support@planetsquires.com"
'   cMail.BCC          = "planetsquires@gmail.com"
'   cMail.ReplyTo      = "support@planetsquires.com"
'   cMail.Subject      = "test subject"

'   cMail.EnableAuth   = %TRUE
'   cMail.AuthType     = "AUTH LOGIN"
'   cMail.AuthUsername = "myusername@something.com"
'   cMail.AuthPassword = "mypassword"

'   cMail.MessageStyle = "both"
'   cMail.Attachments  = ""       ' eg. "myfilename.zip"

'   ' // HTML text email
'   cMail.HTMLMessage  = "<html>" & $CRLF  & _
'                        "<body>" & $CRLF  & _
'                        "<center><b>This Is a test!</b></center>" & $CRLF & _
'                        "</body>" & $CRLF & _
'                        "</html>" & $CRLF

'   ' // Send the actual email and deal with any error/message response.
'   IF ISFALSE cMail.SendMail THEN
'      MSGBOX "Error sending email:  " & cMail.Response
'   ELSE
'      MSGBOX "Email(s) sent okay."
'   END IF

'END FUNCTION
' ===========================================================================================
