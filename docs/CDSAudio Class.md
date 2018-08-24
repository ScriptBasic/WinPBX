# CDSAudio Class

The **CDSAudio** class allows to play audio files of a variety of formats using **Direct Show**.

**Include file**: CDSAudio.inc

### Constructor

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#Constructor) | Creates an instance of the **CDSAudio** class and loads the specified audio file. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [GetBalance](#GetBalance) | Gets the balance for the audio signal. |
| [CurrentPosition](#CurrentPosition) | Gets the current position, relative to the total duration of the stream. |
| [GetDuration](#GetDuration) | Gets the duration of the stream, in 100-nanosecond units. |
| GetEvent | Retrieves the next event notification from the event queue. |
| GetVolume | Gets the volume (amplitude) of the audio signal. |
| Load | Builds a filter graph that renders the specified file. |
| Pause | Pauses all the filters in the filter graph. |
| Run | Runs all the filters in the filter graph. |
| SetBalance | Sets the balance for the audio signal. |
| SetNotifyWindow | Registers a window to process event notifications. |
| SetPositions | Sets the current position and the stop position. |
| SetVolume | Sets the volume (amplitude) of the audio signal. |
| Stop | Stops all the filters in the filter graph. |
| WaitForCompletion | Waits for the filter graph to render all available data. |

# <a name="Constructor"></a>Constructor

Creates an instance of the **CDSAudio** class and loads the specified audio file.

```
CONSTRUCTOR CDSAudio (BYREF wszFileName AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFilename* | The file to load. |

You can create an instance of the class and load the file at the same time with:

```
DIM pCDSAudio AS CDSAudio = "MyAudioFile.mp3"
```

or you can use the default constructor and then load the file:

```
DIM pCDSAudio AS CDSAudio
pCDSAudio.Load("MyAudioFile.mp3")
```

With the **Load** method you can change the audio file on the fly.

To receive event messages, you can define a custom message

```
#define WM_GRAPHNOTIFY  WM_APP + 1
```

and pass it to the **SetNotifyWindow** method, together with the handle of the window that will process the message:

```
pCDSAudio.SetNotifyWindow(pWindow.hWindow, WM_GRAPHNOTIFY, 0)
```

The messages will be processed in the window callback procedure:

```
      CASE WM_GRAPHNOTIFY
         DIM AS LONG lEventCode
         DIM AS LONG_PTR lParam1, lParam2
         WHILE (SUCCEEDED(pCDSAudio.GetEvent(lEventCode, lParam1, lParam2)))
            SELECT CASE lEventCode
               CASE EC_COMPLETE:    ' Handle event
               CASE EC_USERABORT:    ' Handle event
               CASE EC_ERRORABORT:   ' Handle event
            END SELECT
         WEND
```

Once loaded, you can start playing the audio file calling the **Run** method:

```
pCDSAudio.Run
```

There are other methods to get/set the volume and balance, to get the duration and current position, to set the positions, and to pause or stop.

# <a name="GetBalance"></a>GetBalance

Gets the balance for the audio signal.

```
FUNCTION GetBalance () AS LONG
```

#### Return value

The balance for the audio signal.

#### Remarks

The balance ranges from -10,000 to 10,000. The value -10,000 means the right channel is attenuated by 100 dB and is effectively silent. The value 10,000 means the left channel is silent. The neutral value is 0, which means that both channels are at full volume. When one channel is attenuated, the other remains at full volume.

# <a name="CurrentPosition"></a>CurrentPosition

Gets the current position, relative to the total duration of the stream.

```
FUNCTION CurrentPosition () AS LONG
```

# <a name="GetDuration"></a>GetDuration

Gets the duration of the stream, in 100-nanosecond units.

```
FUNCTION GetDuration () AS LONG
```
