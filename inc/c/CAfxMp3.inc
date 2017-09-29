' ########################################################################################
' Microsoft Windows
' File: CAfxMp3.inc
' Contents: MP3 class.
' Copyright (c) 2012 José Roca.
' Based on Simple C++ DirectShow MP3 Player Class by Wong Shao Voon, 26 Apr 2012.
' http://www.codeproject.com/Articles/373613/Simple-Cplusplus-DirectShow-MP3-Player-Class
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXMP3_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "DShow.inc"     ' // Direct Show

' ########################################################################################
' CAfxMp3 class.
' ########################################################################################
CLASS CAfxMp3

   INSTANCE m_pIGraphBuilder AS IGraphBuilder
   INSTANCE m_pIMediaControl AS IMediaControl
   INSTANCE m_pIMediaEventEx AS IMediaEventEx
   INSTANCE m_pIBasicAudio AS IBasicAudio
   INSTANCE m_pIMediaSeeking AS IMediaSeeking
   INSTANCE m_ready AS LONG
   INSTANCE m_duration AS QUAD

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      m_pIGraphBuilder = NOTHING
      m_pIMediaControl = NOTHING
      m_pIMediaEventEx = NOTHING
      m_pIBasicAudio = NOTHING
      m_pIMediaSeeking = NOTHING
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxMp3 : INHERIT IAutomation

   ' =====================================================================================
   ' Cleans resources
   ' =====================================================================================
   METHOD Cleanup
      m_pIGraphBuilder = NOTHING
      m_pIMediaControl = NOTHING
      m_pIMediaEventEx = NOTHING
      m_pIBasicAudio = NOTHING
      m_pIMediaSeeking = NOTHING
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Builds a filter graph that renders the specified file.
   ' Return Value = %TRUE or %FALSE.
   ' OBJRESULT
   '   %S_OK = Success.
   '   %VFW_S_AUDIO_NOT_RENDERED = Partial success; the audio was not rendered.
   '   %VFW_S_DUPLICATE_NAME = Success; the Filter Graph Manager modified the filter name to avoid duplication.
   '   %VFW_S_PARTIAL_RENDER = Some of the streams in this movie are in an unsupported format.
   '   %VFW_S_VIDEO_NOT_RENDERED = Partial success; some of the streams in this movie are in an unsupported format.
   '   %E_ABORT = Operation aborted.
   '   %E_FAIL = Failure.
   '   %E_INVALIDARG = Argument is invalid.
   '   %E_OUTOFMEMORY = Insufficient memory.
   '   %E_POINTER = NULL pointer argument.
   '   %VFW_E_CANNOT_CONNECT = No combination of intermediate filters could be found to make the connection.
   '   %VFW_E_CANNOT_LOAD_SOURCE_FILTER = The source filter for this file could not be loaded.
   '   %VFW_E_CANNOT_RENDER = No combination of filters could be found to render the stream.
   '   %VFW_E_INVALID_FILE_FORMAT = The file format is invalid.
   '   %VFW_E_NOT_FOUND = An object or name was not found.
   '   %VFW_E_UNKNOWN_FILE_TYPE = The media type of this file is not recognized.
   '   %VFW_E_UNSUPPORTED_STREAM = Cannot play back the file: the format is not supported.
   ' =====================================================================================
   METHOD Load (BYVAL bstrFile AS WSTRING) AS LONG
      LOCAL hr AS LONG
      m_ready = %FALSE
      ME.Cleanup
      m_pIGraphBuilder = NEWCOM CLSID $CLSID_FilterGraph
      IF ISNOTHING(m_pIGraphBuilder) THEN EXIT METHOD
      m_pIMediaControl = m_pIGraphBuilder
      m_pIMediaEventEx = m_pIGraphBuilder
      m_pIBasicAudio = m_pIGraphBuilder
      m_pIMediaSeeking = m_pIGraphBuilder
      hr = m_pIGraphBuilder.RenderFile(BYCOPY bstrFile)
      IF SUCCEEDED(hr) THEN
         m_ready = %TRUE
         IF ISOBJECT(m_pIMediaSeeking) THEN
            m_pIMediaSeeking.SetTimeFormat($TIME_FORMAT_MEDIA_TIME)   ' // Reference time (100-nanosecond units).
            m_pIMediaSeeking.GetDuration(m_duration)                  ' // Returns 10,000,000 for a second.
         END IF
      END IF
      METHOD = m_ready
      IF hr THEN METHOD OBJRESULT = hr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Runs all the filters in the filter graph.
   ' Return Value = %TRUE or %FALSE.
   ' OBJRESULT
   '   %S_FALSE The graph is preparing to run, but some filters have not completed the transition to a running state.
   '   %S_OK = All filters in the graph completed the transition to a running state.
   ' =====================================================================================
   METHOD Run () AS LONG
      IF ISTRUE(m_ready) AND ISOBJECT(m_pIMediaControl) THEN
         m_pIMediaControl.Run
         IF ISFALSE OBJRESULT THEN METHOD = %TRUE ELSE METHOD OBJRESULT = OBJRESULT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Pauses all the filters in the filter graph.
   ' Return Value = %TRUE or %FALSE.
   ' OBJRESULT
   '   %S_FALSE = The graph paused successfully, but some filters have not completed the state transition.
   '   %S_OK = All filters in the graph completed the transition to a paused state.
   ' =====================================================================================
   METHOD Pause () AS LONG
      IF ISTRUE(m_ready) AND ISOBJECT(m_pIMediaControl) THEN
         m_pIMediaControl.Pause
         IF ISFALSE OBJRESULT THEN METHOD = %TRUE ELSE METHOD OBJRESULT = OBJRESULT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Stops all the filters in the filter graph.
   ' Return Value = %TRUE or %FALSE.
   ' OBJRESUT = Returns S_OK if successful, or an HRESULT value that indicates the cause of the error.
   ' =====================================================================================
   METHOD Stop () AS LONG
      IF ISTRUE(m_ready) AND ISOBJECT(m_pIMediaControl) THEN
         m_pIMediaControl.Stop
         IF ISFALSE OBJRESULT THEN METHOD = %TRUE ELSE METHOD OBJRESULT = OBJRESULT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Waits for the filter graph to render all available data.
   ' Parameters:
   ' msTimeout
   '   [in] Duration of the time-out, in milliseconds. Pass zero to return immediately.
   '   To block indefinitely, pass INFINITE.
   ' EvCode
   '   [out] Event that terminated the wait. This value can be one of the following:
   '   %EC_COMPLETE  = Operation completed.
   '   %EC_ERRORABORT = Error. Playback cannot continue.
   '   %EC_USERABORT  = User terminated the operation.
   '   Zero (0) = Operation has not completed.
   ' Return Value = %TRUE or %FALSE.
   ' OBJRESULT
   '   %S_OK = Success.
   '   %E_ABORT = Time-out expired.
   '   %VFW_E_WRONG_STATE = The filter graph is not running.
   ' Remarks
   ' This method blocks until the time-out expires, or one of the following events occurs:
   '   %EC_COMPLETE
   '   %EC_ERRORABORT
   '   %EC_USERABORT
   ' During the wait, the method discards all other event notifications.
   ' If the return value is S_OK, the EvCode parameter receives the event code that ended
   ' the wait. When the method returns, the filter graph is still running. The application
   ' can pause or stop the graph, as appropriate.
   ' =====================================================================================
   METHOD WaitForCompletion (BYVAL msTimeout AS LONG, BYREF EvCode AS LONG) AS LONG
      IF ISTRUE(m_ready) AND ISOBJECT(m_pIMediaEventEx) THEN
         m_pIMediaEventEx.WaitForcompletion(msTimeout, EvCode)
         IF ISFALSE OBJRESULT THEN METHOD = %TRUE ELSE METHOD OBJRESULT = OBJRESULT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the volume (amplitude) of the audio signal.
   ' Return Value = The volume. Divide by 100 to get equivalent decibel value.
   '                For example, –10,000 is –100 dB.
   ' OBJRESULT
   '   %E_NOTIMPL = The filter graph does not contain an audio renderer filter.
   '                (Possibly the source does not contain an audio stream.)
   '   %S_OK = Success.
   ' =====================================================================================
   PROPERTY GET Volume () AS LONG
      IF ISTRUE m_ready AND ISOBJECT(m_pIBasicAudio) THEN
         PROPERTY = m_pIBasicAudio.Volume
         IF OBJRESULT THEN PROPERTY OBJRESULT = OBJRESULT
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the volume (amplitude) of the audio signal.
   ' nVol = Specifies the volume, as a number from –10,000 to 0, inclusive. Full volume is 0, and
   '        –10,000 is silence. Multiply the desired decibel level by 100. For example, –10,000 = –100 dB.
   ' OBJRESULT
   '   %S_OK = Success.
   '   %E_FAIL = The underlying audio device returned an error.
   '   %E_INVALIDARG = The value of nVol is invalid.
   '   %E_NOTIMPL = The filter graph does not contain an audio renderer filter.
   '                (Possibly the source does not contain an audio stream.)
   ' =====================================================================================
   PROPERTY SET Volume (BYVAL nVol AS LONG)
      IF ISTRUE m_ready AND ISOBJECT(m_pIBasicAudio) THEN
         m_pIBasicAudio.Volume = nVol
         IF OBJRESULT THEN PROPERTY OBJRESULT = OBJRESULT
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the balance of the audio signal.
   ' Return Value = The balance ranges from -10,000 to 10,000. The value -10,000 means the
   '                right channel is attenuated by 100 dB and is effectively silent. The
   '                value 10,000 means the left channel is silent. The neutral value is 0,
   '                which means that both channels are at full volume. When one channel is
   '                attenuated, the other remains at full volume.
   ' OBJRESULT
   '   %E_NOTIMPL = The filter graph does not contain an audio renderer filter.
   '                (Possibly the source does not contain an audio stream.)
   '   %S_OK = Success.
   ' =====================================================================================
   PROPERTY GET Balance () AS LONG
      IF ISTRUE m_ready AND ISOBJECT(m_pIBasicAudio) THEN
         PROPERTY = m_pIBasicAudio.Balance
         IF OBJRESULT THEN PROPERTY OBJRESULT = OBJRESULT
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the balance of the audio signal.
   ' nBalance = Specifies the balance. The value can range from -10,000 to 10,000. The value
   '            -10,000 means the right channel is attenuated by 100 dB and is effectively
   '            silent. The value 10,000 means the left channel is silent. The neutral value
   '            is 0, which means that both channels are at full volume. When one channel is
   '            attenuated, the other remains at full volume.
   ' OBJRESULT
   '   %S_OK = Success.
   '   %E_FAIL = The underlying audio device returned an error.
   '   %E_INVALIDARG = The value of nBalance is invalid.
   '   %E_NOTIMPL = The filter graph does not contain an audio renderer filter.
   '                (Possibly the source does not contain an audio stream.)
   ' =====================================================================================
   PROPERTY SET Balance (BYVAL nBalance AS LONG)
      IF ISTRUE m_ready AND ISOBJECT(m_pIBasicAudio) THEN
         m_pIBasicAudio.Balance = nBalance
         IF OBJRESULT THEN PROPERTY OBJRESULT = OBJRESULT
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the duration of the stream, in 100-nanosecond units.
   ' Returns 10,000,000 for a second.
   ' =====================================================================================
   PROPERTY GET Duration () AS QUAD
      PROPERTY = m_duration
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the current position, relative to the total duration of the stream.
   ' =====================================================================================
   PROPERTY GET CurrentPosition () AS QUAD
      LOCAL hr AS LONG
      LOCAL curPos AS QUAD
      IF ISTRUE m_ready AND ISOBJECT(m_pIMediaSeeking) THEN
         hr = m_pIMediaSeeking.GetCurrentPosition(curPos)
         IF SUCCEEDED(hr) THEN PROPERTY = curPos ELSE PROPERTY OBJRESULT = hr
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the current position and the stop position.
   ' Return Value = %TRUE or %FALSE.
   ' Parameters:
   '   pCurrent = [in, out] Pointer to a variable that specifies the current position, in units of the current time format.
   '   pStop = [in, out] Pointer to a variable that specifies the stop time, in units of the current time format.
   '   bAbsolutePositioning = [in] %TRUE or %FALSE. IF %TRUE, the specified position is absolute.
   '                          IF %FALSE, the specified position is relative.
   ' OBJRESULT
   '   %S_FALSE = No position change. (Both flags specify no seeking.)
   '   %S_OK = Success.
   '   %E_INVALIDARG = Invalid argument.
   '   %E_NOTIMPL = Method is not supported.
   '   %E_POINTER = NULL pointer argument.
   ' =====================================================================================
   METHOD SetPositions (BYREF pCurrent AS QUAD, BYREF pStop AS QUAD, BYVAL bAbsolutePositioning AS LONG) AS LONG
      LOCAL hr AS LONG
      LOCAL dwFlags AS DWORD
      IF ISTRUE m_ready AND ISOBJECT(m_pIMediaSeeking) THEN
         IF bAbsolutePositioning THEN
            dwFlags = %AM_SEEKING_AbsolutePositioning OR %AM_SEEKING_SeekToKeyFrame
         ELSE
            dwFlags = %AM_SEEKING_RelativePositioning OR %AM_SEEKING_SeekToKeyFrame
         END IF
         hr = m_pIMediaSeeking.SetPositions(pCurrent, dwFlags, pStop, dwFlags)
         IF SUCCEEDED(hr) THEN METHOD = %TRUE ELSE METHOD OBJRESULT = hr
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the IMediaEventEx object
   ' =====================================================================================
   METHOD GetIMediaEventExObject () As IMediaEventEx
      METHOD = m_pIMediaEventEx
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
