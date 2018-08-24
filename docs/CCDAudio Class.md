# CCDAudio Class

The **CCDAudio** class allows to play a CD Rom using MCI.

### Constructor

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#Constructor) | Creates an instance of the **CCDAudio** class. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Backward](#Backward) | Moves to the previous track. |
| [Close](#Close) | Closes the device or file and any associated resources. MCI unloads a device when all instances of the device or all files are closed.  |
| [CloseDoor](#CloseDoor) | Closes the CDRom door. |
| [Forward](#Forward) | Moves to the next track. |
| [GetAllTracksLength](#GetAllTracksLength) | Returns the total length in seconds of all the tracks. |
| [GetAllTracksLengthString](#GetAllTracksLengthString) | Returns the total length of all the tracks. |
| [GetCurrentPos](#GetCurrentPos) | Returns the current track position in seconds. |
| [GetCurrentPosString](#GetCurrentPosString) | Returns the current track position. |
| [GetCurrentTrack](#GetCurrentTrack) | Returns the current track number. |
| [GetErrorString](#GetErrorString) | Retrieves a string that describes the specified MCI error code. |
| [GetLastError](#GetLastError) | Retrieves a The last MCI error code. |
| [GetTrackLength](#GetTrackLength) | Returns the length in seconds of the given track. |
| [GetTrackLengthString](#GetTrackLengthString) | Returns the length of the given track. |
| [GetTracksCount](#GetTracksCount) | Returns the count of tracks. |
| [GetTrackStartTime](#GetTrackStartTime) | Returns the start time of the given track. |
| [GetTrackStartTimeString](#GetTrackStartTimeString) | Returns the start time of the given track. |
| [IsMediaInserted](#IsMediaInserted) | Checks whether CD media is inserted. |
| [IsPaused](#IsPaused) | Checks whether is in paused mode. |
| [IsPlaying](#IsPlaying) | Checks whether is in play mode. |
| [IsReady](#IsReady) | Checks if the device is ready. |
| [IsSeeking](#IsSeeking) | Checks whether is in seeking mode. |
| [IsStopped](#IsStopped) | Checks whether is in stopped mode. |
| [Open](#Open) | Initializes the device. |
| [OpenDoor](#OpenDoor) | Opens the CDRom door. |
| [Pause](#Pause) | Pauses playing CD Audio. |
| [Play](#Play) | Starts playing CD Audio. |
| [PlayFrom](#PlayFrom) | Starts playing CD Audio on the given track. |
| [PlayFromTo](#PlayFromTo) | Starts playing CD Audio from a given track to a given track. |
| [Stop](#Stop) | Stops playing CD Audio. |
| [ToEnd](#ToEnd) | Sets the position to the end of the audio CD. |
| [ToStart](#ToStart) | Sets the position to the start of the audio CD. |


# <a name="Constructor"></a>Constructor

Creates an instance of the **CCDAudio** class.

```
CONSTRUCTOR CCDAudio
```

#### Usage example:

```
DIM pAudio AS CCDAudio
pAudio.Open
pAudio.Play
```
