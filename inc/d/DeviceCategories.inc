' ########################################################################################
' Microsoft Windows
' File: DeviceCategories.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DeviceCategories_INC = 1

'// Unknown
$$DEVICEDISPLAY_CATEGORY_UNKNOWN                              = "Unknown"$$

'// Other
$$DEVICEDISPLAY_CATEGORY_OTHER                                = "Other"$$

'// Audio
$$DEVICEDISPLAY_CATEGORY_AUDIO                                = "Audio"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_ADAPTER                        = "Audio.Adapter"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_HEADPHONE                      = "Audio.Headphone"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_MICROPHONE                     = "Audio.Microphone"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_SPEAKERPHONE                   = "Audio.Speakerphone"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_SPEAKERS                       = "Audio.Speakers"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_SPEAKERS_WIRELESS              = "Audio.Speakers.Wireless"$$
$$DEVICEDISPLAY_CATEGORY_AUDIO_SPEAKERS_USB                   = "Audio.Speakers.USB"$$

'// Communication
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION                        = "Communication"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_HEADSET                = "Communication.Headset"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_HEADSET_BLUETOOTH      = "Communication.Headset.Bluetooth"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_PHONE                  = "Communication.Phone"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_PHONE_CELL             = "Communication.Phone.Cell"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_PHONE_IP               = "Communication.Phone.IP"$$
$$DEVICEDISPLAY_CATEGORY_COMMUNICATION_PHONE_SPEAKER          = "Communication.Phone.Speaker"$$

'// Computer
$$DEVICEDISPLAY_CATEGORY_COMPUTER                             = "Computer"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_ALLINONE                    = "Computer.AllInOne"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_DESKTOP                     = "Computer.Desktop"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_DESKTOP_LOWPROFILE          = "Computer.Desktop.LowProfile"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_DESKTOP_PIZZABOX            = "Computer.Desktop.Pizzabox"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_HANDHELD                    = "Computer.Handheld"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_HANDHELD_WINDOWS            = "Computer.Handheld.Windows"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_LAPTOP                      = "Computer.Laptop"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_LUNCHBOX                    = "Computer.Lunchbox"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_NETBOOK                     = "Computer.Netbook"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_NOTEBOOK                    = "Computer.Notebook"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_NOTEBOOK_SUB                = "Computer.Notebook.Sub"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_PORTABLE                    = "Computer.Portable"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_RACKMOUNT                   = "Computer.Rackmount"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_SEALED                      = "Computer.Sealed"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_SERVER                      = "Computer.Server"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_SPACESAVING                 = "Computer.SpaceSaving"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_TABLET                      = "Computer.Tablet"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_THINCLIENT                  = "Computer.ThinClient"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_TOWER                       = "Computer.Tower"$$
$$DEVICEDISPLAY_CATEGORY_COMPUTER_TOWER_MINI                  = "Computer.Tower.Mini"$$

'// Display
$$DEVICEDISPLAY_CATEGORY_DISPLAY                              = "Display"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_MONITOR                      = "Display.Monitor"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_MONITOR_CRT                  = "Display.Monitor.CRT"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_MONITOR_LCD                  = "Display.Monitor.LCD"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_MONITOR_PLASMA               = "Display.Monitor.Plasma"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_PICTUREFRAME                 = "Display.PictureFrame"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_PROJECTOR                    = "Display.Projector"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_SIDESHOW                     = "Display.SideShow"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_TV                           = "Display.TV"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_TV_CRT                       = "Display.TV.CRT"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_TV_LCD                       = "Display.TV.LCD"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_TV_PLASMA                    = "Display.TV.Plasma"$$
$$DEVICEDISPLAY_CATEGORY_DISPLAY_TV_DLP                       = "Display.TV.DLP"$$

'// Component
$$DEVICEDISPLAY_CATEGORY_COMPONENT                            = "Component"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_AUDIOADAPTER               = "Component.AudioAdapter"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_BATTERY                    = "Component.Battery"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_BRIDGE                     = "Component.Bridge"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_BRIDGE_NETWORK             = "Component.Bridge.Network"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_BRIDGE_STORAGE             = "Component.Bridge.Storage"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CABLE                      = "Component.Cable"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CABLE_TRANSFER             = "Component.Cable.Transfer"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CABLE_TRANSFER_USB         = "Component.Cable.Transfer.USB"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CAPTURE                    = "Component.Capture"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CAPTURE_VIDEO              = "Component.Capture.Video"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER                 = "Component.Controller"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_1394            = "Component.Controller.1394"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_BLUETOOTH       = "Component.Controller.Bluetooth"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_CARDBUS         = "Component.Controller.CardBus"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_IR              = "Component.Controller.IR"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_IR_MCE          = "Component.Controller.IR.MCE"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_SDH             = "Component.Controller.SDH"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_SERIAL          = "Component.Controller.Serial"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE         = "Component.Controller.Storage"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE_IDE     = "Component.Controller.Storage.IDE"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE_ISCSI   = "Component.Controller.Storage.iSCSI"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE_SATA    = "Component.Controller.Storage.SATA"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE_SCSI    = "Component.Controller.Storage.SCSI"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_STORAGE_RAID    = "Component.Controller.Storage.Raid"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_USB             = "Component.Controller.USB"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_CONTROLLER_WUSB            = "Component.Controller.WUSB"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_GRAPHICSCARD               = "Component.GraphicsCard"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_HUB                        = "Component.Hub"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_HUB_1394                   = "Component.Hub.1394"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_HUB_USB                    = "Component.Hub.USB"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_KVM                        = "Component.KVM"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_NIC                        = "Component.NIC"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_SMARTCARDREADER            = "Component.SmartCardReader"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_SYSTEM                     = "Component.System"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_SYSTEM_BOARD               = "Component.System.Board"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_SYSTEM_MEMORY              = "Component.System.Memory"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_SYSTEM_PROCESSOR           = "Component.System.Processor"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER                      = "Component.Tuner"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV                   = "Component.Tuner.TV"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_ATSC              = "Component.Tuner.TV.ATSC"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_DCB_S             = "Component.Tuner.TV.DCB-S"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_DVB_C             = "Component.Tuner.TV.DVB-C"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_DVB_T             = "Component.Tuner.TV.DVB-T"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_ISDB_T            = "Component.Tuner.TV.ISDB-T"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_NTSC              = "Component.Tuner.TV.NTSC"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_NTSCMJ            = "Component.Tuner.TV.NTSCMJ"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_OPENCABLE         = "Component.Tuner.TV.OpenCable"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_PAL               = "Component.Tuner.TV.PAL"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_PROPRIETARY       = "Component.Tuner.TV.Proprietary"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_QAM               = "Component.Tuner.TV.QAM"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_TV_SECAM             = "Component.Tuner.TV.SECAM"$$
$$DEVICEDISPLAY_CATEGORY_COMPONENT_TUNER_RADIO                = "Component.Tuner.Radio"$$

'// Input
$$DEVICEDISPLAY_CATEGORY_INPUT                                = "Input"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_DIGITIZER                      = "Input.Digitizer"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_DIGITIZER_MULTITOUCH           = "Input.Digitizer.Multitouch"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_DIGITIZER_PEN                  = "Input.Digitizer.Pen"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_DIGITIZER_TOUCHPAD             = "Input.Digitizer.Touchpad"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_DIGITIZER_TOUCHSCREEN          = "Input.Digitizer.Touchscreen"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING                         = "Input.Gaming"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING_COMMON                  = "Input.Gaming.Common"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING_CONTROLLER              = "Input.Gaming.Controller"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING_GAMEPAD                 = "Input.Gaming.Gamepad"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING_GENERIC                 = "Input.Gaming.Generic"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_GAMING_STEERING                = "Input.Gaming.Steering"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_KEYBOARD                       = "Input.Keyboard"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_KVM                            = "Input.KVM"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_MOUSE                          = "Input.Mouse"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_TRACKBALL                      = "Input.Trackball"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_REMOTE                         = "Input.Remote"$$
$$DEVICEDISPLAY_CATEGORY_INPUT_REMOTE_MCE                     = "Input.Remote.MCE"$$

'// Health
$$DEVICEDISPLAY_CATEGORY_HEALTH                               = "Health"$$
$$DEVICEDISPLAY_CATEGORY_HEALTH_BLOODGLUCOSE                  = "Health.BloodGlucose"$$
$$DEVICEDISPLAY_CATEGORY_HEALTH_BLOODPRESSURE                 = "Health.BloodPressure"$$
$$DEVICEDISPLAY_CATEGORY_HEALTH_HEARTRATE                     = "Health.HeartRate"$$
$$DEVICEDISPLAY_CATEGORY_HEALTH_PEDOMETER                     = "Health.Pedometer"$$

'// Media
$$DEVICEDISPLAY_CATEGORY_MEDIA                                = "Media"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_SMARTCARD                      = "Media.SmartCard"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE                        = "Media.Storage"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_FLASH                  = "Media.Storage.Flash"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_FLASH_COMPACTFLASH     = "Media.Storage.Flash.CompactFlash"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_FLASH_MEMORYSTICK      = "Media.Storage.Flash.MemoryStick"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_FLASH_SD               = "Media.Storage.Flash.SD"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_OPTICAL                = "Media.Storage.Optical"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_OPTICAL_CD             = "Media.Storage.Optical.CD"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_OPTICAL_DVD            = "Media.Storage.Optical.DVD"$$
$$DEVICEDISPLAY_CATEGORY_MEDIA_STORAGE_OPTICAL_BLURAY         = "Media.Storage.Optical.BluRay"$$

'// Multimedia
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA                           = "Multimedia"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DMC                       = "Multimedia.DMC"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DMP                       = "Multimedia.DMP"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DMR                       = "Multimedia.DMR"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DMR_MCX                   = "Multimedia.DMR.MCX"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DMS                       = "Multimedia.DMS"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_DVR                       = "Multimedia.DVR"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_GAMECONSOLE               = "Multimedia.GameConsole"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_PMP                       = "Multimedia.PMP"$$
$$DEVICEDISPLAY_CATEGORY_MULTIMEDIA_VOICERECORDER             = "Multimedia.VoiceRecorder"$$

'// Network
$$DEVICEDISPLAY_CATEGORY_NETWORK                              = "Network"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_ACCESSPOINT                  = "Network.AccessPoint"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_BLUETOOTH                    = "Network.Bluetooth"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_BRIDGE                       = "Network.Bridge"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_BRIDGE_WIFI2ETHER            = "Network.Bridge.Wifi2Ether"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_HOMEAUTOMATION               = "Network.HomeAutomation"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_MOBILEBROADBAND              = "Network.MobileBroadband"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_MODEM                        = "Network.Modem"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_NIC                          = "Network.NIC"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_NIC_ETHERNET                 = "Network.NIC.Ethernet"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_NIC_IR                       = "Network.NIC.IR"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_NIC_PLC                      = "Network.NIC.PLC"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_NIC_WIRELESS                 = "Network.NIC.Wireless"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_PRINTSERVER                  = "Network.PrintServer"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_ROUTER                       = "Network.Router"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_ROUTER_WIRELESS              = "Network.Router.Wireless"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_SWITCH                       = "Network.Switch"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_UWB                          = "Network.UWB"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_WUSB                         = "Network.WUSB"$$
$$DEVICEDISPLAY_CATEGORY_NETWORK_WUSB_DWA                     = "Network.WUSB.DWA"$$

'// PrintFax
$$DEVICEDISPLAY_CATEGORY_PRINTFAX                             = "PrintFax"$$
$$DEVICEDISPLAY_CATEGORY_PRINTFAX_FAX                         = "PrintFax.FAX"$$
$$DEVICEDISPLAY_CATEGORY_PRINTFAX_MFP                         = "PrintFax.MFP"$$
$$DEVICEDISPLAY_CATEGORY_PRINTFAX_PRINTER                     = "PrintFax.Printer"$$
$$DEVICEDISPLAY_CATEGORY_PRINTFAX_PRINTER_INKJET              = "PrintFax.Printer.Inkjet"$$
$$DEVICEDISPLAY_CATEGORY_PRINTFAX_PRINTER_LASER               = "PrintFax.Printer.Laser"$$

'// Sensor
$$DEVICEDISPLAY_CATEGORY_SENSOR                               = "Sensor"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_ELECTRICAL                    = "Sensor.Electrical"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_ENVIRONMENTAL                 = "Sensor.Environmental"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_ENVIRONMENTAL_TEMP            = "Sensor.Environmental.Temp"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_LIGHT                         = "Sensor.Light"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_LOCATON                       = "Sensor.Location"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_LOCATON_GPS                   = "Sensor.Location.GPS"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_MECHANICAL                    = "Sensor.Mechanical"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_MOTION                        = "Sensor.Motion"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_ORIENTATION                   = "Sensor.Orientation"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_PROXIMITY                     = "Sensor.Proximity"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_PROXIMITY_NFC                 = "Sensor.Proximity.NFC"$$
$$DEVICEDISPLAY_CATEGORY_SENSOR_PROXIMITY_RFID                = "Sensor.Proximity.RFID"$$

'// Storage
$$DEVICEDISPLAY_CATEGORY_STORAGE                              = "Storage"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_CARDREADER                   = "Storage.CardReader"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_CARDREADER_COMBO             = "Storage.CardReader.Combo"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_CHANGER                      = "Storage.Changer"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_CHANGER_OPTICAL              = "Storage.Changer.Optical"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_FDD                          = "Storage.FDD"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_HDD                          = "Storage.HDD"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_HDD_SOLIDSTATE               = "Storage.HDD.SolidState"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_NETWORK                      = "Storage.Network"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_NETWORK_WIRELESS             = "Storage.Network.Wireless"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_OPTICAL                      = "Storage.Optical"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_OPTICAL_BLURAY               = "Storage.Optical.BluRay"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_OPTICAL_CD                   = "Storage.Optical.CD"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_OPTICAL_DVD                  = "Storage.Optical.DVD"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_TAPE                         = "Storage.Tape"$$
$$DEVICEDISPLAY_CATEGORY_STORAGE_UFD                          = "Storage.UFD"$$

'// Imaging
$$DEVICEDISPLAY_CATEGORY_IMAGING                              = "Imaging"$$
$$DEVICEDISPLAY_CATEGORY_IMAGING_CAMCORDER                    = "Imaging.Camcorder"$$
$$DEVICEDISPLAY_CATEGORY_IMAGING_CAMERA                       = "Imaging.Camera"$$
$$DEVICEDISPLAY_CATEGORY_IMAGING_SCANNER                      = "Imaging.Scanner"$$
$$DEVICEDISPLAY_CATEGORY_IMAGING_WEBCAM                       = "Imaging.Webcam"$$

'// Personal Identity
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY                     = "PersonalIdentity"$$
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY_FACESCANNER         = "PersonalIdentity.FaceScanner"$$
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY_FINGERPRINTREADER   = "PersonalIdentity.FingerprintReader"$$
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY_RETINALSCANNER      = "PersonalIdentity.RetinalScanner"$$
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY_SMARTCARD           = "PersonalIdentity.Smartcard"$$
$$DEVICEDISPLAY_CATEGORY_PERSONALIDENTITY_SMARTCARDREADER     = "PersonalIdentity.SmartcardReader"$$
