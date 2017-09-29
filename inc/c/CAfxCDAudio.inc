' ########################################################################################
' Microsoft Windows
' File: CAfxCDAudio.inc
' Contents: MCI CD Audio wrapper class.
' Copyright (c) 2011 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXCDAUDIO_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "mmsystem.inc"

' ########################################################################################
' CAfxCDAudio class.
' ########################################################################################
CLASS CAfxCDAudio

   INSTANCE m_ErrorCode AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Stop and close the audio CD
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) = UCASE$("not ready") THEN EXIT METHOD
      IF UCASE$(wszBuff) = UCASE$("paused") OR UCASE$(wszBuff) = UCASE$("playing") THEN
         m_ErrorCode = mciSendStringW("stop cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      END IF
      m_ErrorCode = mciSendStringW("close cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxCDAudio : INHERIT IAutomation

   ' =====================================================================================
   ' Retrieves a string that describes the specified MCI error code.
   ' =====================================================================================
   METHOD GetErrorString (OPTIONAL BYVAL dwError AS DWORD) AS WSTRING
      LOCAL wszBuff AS WSTRINGZ * 128
      IF dwError = 0 THEN dwError = m_ErrorCode
      IF dwError = 0 THEN EXIT METHOD
      IF ISFALSE mciGetErrorStringW(dwError, wszBuff, 128) THEN wszBuff = "Unknown error"
      METHOD = wszBuff
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the last error code.
   ' =====================================================================================
   METHOD GetError () AS DWORD
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Opens the audio CD
   ' =====================================================================================
   METHOD Open () AS DWORD
      m_ErrorCode = mciSendStringW("open cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the audio CD
   ' =====================================================================================
   METHOD Close () AS DWORD
      IF ME.IsReady THEN
         IF ME.IsPaused OR ME.IsPlaying THEN
            m_ErrorCode = mciSendStringW("stop cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
         END IF
         m_ErrorCode = mciSendStringW("close cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks if MCI is ready.
   ' =====================================================================================
   METHOD IsReady () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) = UCASE$("not ready") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks whether CD media is inserted.
   ' =====================================================================================
   METHOD IsMediaInserted () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 16
      m_ErrorCode = mciSendStringW("status cdaudio media present", wszBuff, 16, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) <> UCASE$("true") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks whether is in paused mode.
   ' =====================================================================================
   METHOD IsPaused () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) <> UCASE$("paused") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks whether is in stopped mode.
   ' =====================================================================================
   METHOD IsStopped () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) <> UCASE$("stopped") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks whether is in play mode.
   ' =====================================================================================
   METHOD IsPlaying () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) <> UCASE$("playing") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks whether is in seeking mode.
   ' =====================================================================================
   METHOD IsSeeking () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      m_ErrorCode = mciSendStringW("status cdaudio mode wait", wszBuff, 64, BYVAL %NULL)
      IF m_ErrorCode <> 0 THEN EXIT METHOD
      IF UCASE$(wszBuff) <> UCASE$("seeking") THEN EXIT METHOD
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Opens the CDRom door.
   ' =====================================================================================
   METHOD OpenDoor () AS DWORD
      m_ErrorCode = mciSendStringW("set cdaudio door open", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the CDRom door.
   ' =====================================================================================
   METHOD CloseDoor () AS DWORD
      m_ErrorCode = mciSendStringW("set cdaudio door closed", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Starts playing CD Audio.
   ' =====================================================================================
   METHOD Play () AS DWORD
      m_ErrorCode = mciSendStringW("play cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Starts playing CD Audio on the given track.
   ' =====================================================================================
   METHOD PlayFrom (BYVAL nTrack AS LONG) AS DWORD
      m_ErrorCode = mciSendStringW("play cdaudio from" & STR$(nTrack), BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Starts playing CD Audio from a given track to a given track.
   ' =====================================================================================
   METHOD PlayFromTo (BYVAL nStartTrack AS LONG, BYVAL nEndTrack AS LONG) AS DWORD
      m_ErrorCode = mciSendStringW("play cdaudio from" & STR$(nStartTrack) & " to" & STR$(nEndTrack), BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stops playing CD Audio.
   ' =====================================================================================
   METHOD Stop () AS DWORD
      m_ErrorCode = mciSendStringW("stop cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      IF m_ErrorCode THEN METHOD = m_ErrorCode : EXIT METHOD
      m_ErrorCode = mciSendStringW("seek cdaudio to start", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Pauses playing CD Audio.
   ' =====================================================================================
   METHOD Pause () AS DWORD
      m_ErrorCode = mciSendStringW("pause cdaudio", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the count of tracks.
   ' =====================================================================================
   METHOD GetTracksCount () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 16
      m_ErrorCode = mciSendStringW("status cdaudio number of tracks", wszBuff, 16, BYVAL %NULL)
      METHOD = VAL(wszBuff)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current track number.
   ' =====================================================================================
   METHOD GetCurrentTrack () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 16
      m_ErrorCode = mciSendStringW("status cdaudio current track", wszBuff, 16, BYVAL %NULL)
      METHOD = VAL(wszBuff)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the length of the given track.
   ' =====================================================================================
   METHOD GetTrackLengthString (BYVAL nTrack AS LONG) AS WSTRING
      LOCAL wszBuff AS WSTRINGZ * 64
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio length track" & STR$(nTrack), wszBuff, 64, BYVAL %NULL)
      METHOD = wszBuff
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the length in seconds of the given track.
   ' =====================================================================================
   METHOD GetTrackLength (BYVAL nTrack AS LONG) AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      LOCAL wszMin AS WSTRINGZ * 3
      LOCAL wszSec AS WSTRINGZ * 3
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio length track" & STR$(nTrack), wszBuff, 64, BYVAL %NULL)
      wszMin = LEFT$(wszBuff, 2)
      wszSec = MID$(wszBuff, 4, 2)
      METHOD = VAL(wszMin) * 60 + VAL(wszSec)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the total length of all the tracks.
   ' =====================================================================================
   METHOD GetAllTracksLengthString () AS WSTRING
      LOCAL wszBuff AS WSTRINGZ * 16
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio length", wszBuff, 16, BYVAL %NULL)
      METHOD = wszBuff
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the total length in seconds of all the tracks.
   ' =====================================================================================
   METHOD GetAllTracksLength () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 16
      LOCAL wszMin AS WSTRINGZ * 3
      LOCAL wszSec AS WSTRINGZ * 3
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio length", wszBuff, 16, BYVAL %NULL)
      wszMin = LEFT$(wszBuff, 2)
      wszSec = MID$(wszBuff, 4, 2)
      METHOD = VAL(wszMin) * 60 + VAL(wszSec)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current track position.
   ' =====================================================================================
   METHOD GetCurrentPosString () AS WSTRING
      LOCAL wszBuff AS WSTRINGZ * 16
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio position", wszBuff, 16, BYVAL %NULL)
      METHOD = wszBuff
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current track position in seconds.
   ' =====================================================================================
   METHOD GetCurrentPos () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 16
      LOCAL wszMin AS WSTRINGZ * 3
      LOCAL wszSec AS WSTRINGZ * 3
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio position", wszBuff, 16, BYVAL %NULL)
      wszMin = LEFT$(wszBuff, 2)
      wszSec = MID$(wszBuff, 4, 2)
      METHOD = VAL(wszMin) * 60 + VAL(wszSec)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the position to the start of the audio CD.
   ' =====================================================================================
   METHOD ToStart () AS DWORD
      m_ErrorCode = mciSendStringW("seek cdaudio to start", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the position to the end of the audio CD.
   ' =====================================================================================
   METHOD ToEnd () AS DWORD
      m_ErrorCode = mciSendStringW("seek cdaudio to end", BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = m_ErrorCode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Moves to the next track.
   ' =====================================================================================
   METHOD Forward () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 32
      LOCAL nCurrTrack AS LONG
      LOCAL nLastTrack AS LONG
      nCurrTrack = ME.GetCurrentTrack
      nLastTrack = ME.GetTracksCount
      IF nCurrTrack = nLastTrack OR nLastTrack = 0 THEN EXIT METHOD
      nCurrTrack += 1
      m_ErrorCode = mciSendStringW("status cdaudio position track" & STR$(nCurrTrack), wszBuff, 32, BYVAL %NULL)
      IF m_ErrorCode THEN EXIT METHOD
      wszBuff = "play cdaudio from " & wszBuff
      m_ErrorCode = mciSendStringW(wszBuff, BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Moves to the previous track.
   ' =====================================================================================
   METHOD Backward () AS LONG
      LOCAL wszBuff AS WSTRINGZ * 32
      LOCAL nCurrTrack AS LONG
      LOCAL nLastTrack AS LONG
      nCurrTrack = ME.GetCurrentTrack
      nLastTrack = ME.GetTracksCount
      IF nCurrTrack < 2 OR nLastTrack = 0 THEN EXIT METHOD
      nCurrTrack -=1
      m_ErrorCode = mciSendStringW("status cdaudio position track" & STR$(nCurrTrack), wszBuff, 32, BYVAL %NULL)
      IF m_ErrorCode THEN EXIT METHOD
      wszBuff = "play cdaudio from " & wszBuff
      m_ErrorCode = mciSendStringW(wszBuff, BYVAL %NULL, 0, BYVAL %NULL)
      METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the start time of the given track.
   ' =====================================================================================
   METHOD GetTrackStartTimeString (BYVAL nTrack AS LONG) AS WSTRING
      LOCAL wszBuff AS WSTRINGZ * 64
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio position track" & STR$(nTrack), wszBuff, 64, BYVAL %NULL)
      METHOD = wszBuff
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the start time of the given track.
   ' =====================================================================================
   METHOD GetTrackStartTime (BYVAL nTrack AS LONG) AS LONG
      LOCAL wszBuff AS WSTRINGZ * 64
      LOCAL wszMin AS WSTRINGZ * 3
      LOCAL wszSec AS WSTRINGZ * 3
      IF ISFALSE ME.IsMediaInserted THEN EXIT METHOD
      m_ErrorCode = mciSendStringW("status cdaudio position track" & STR$(nTrack), wszBuff, 64, BYVAL %NULL)
      wszMin = LEFT$(wszBuff, 2)
      wszSec = MID$(wszBuff, 4, 2)
      METHOD = VAL(wszMin) * 60 + VAL(wszSec)
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates a new instance of the class and opens the CD Audio.
' ========================================================================================
FUNCTION NewAfxwCDAudio () AS IAfxCDAudio
   LOCAL pAudio AS IAfxCDAudio
   pAudio = CLASS "CAfxCDAudio"
   IF ISNOTHING(pAudio) THEN EXIT FUNCTION
   pAudio.Open
   FUNCTION = pAudio
END FUNCTION
' ========================================================================================
