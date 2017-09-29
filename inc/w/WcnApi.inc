' ########################################################################################
' Microsoft Windows
' File: WcnApi.inc
' Contents: Central header for WCN API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCNAPI_INC = 1

'#if !defined(NTDDI_VERSION) || NTDDI_VERSION < NTDDI_WIN7
'#  error WcnApi.h is only available when targeting Windows 7 and higher
'#endif // NTDDI_VERSION < NTDDI_WIN7

#INCLUDE ONCE "WcnTypes.inc"
#INCLUDE ONCE "WcnDevice.inc"

#IF NOT %DEF(%NO_WCN_PKEYS)
    #INCLUDE ONCE "WcnFunctionDiscoveryKeys.inc"
#ENDIF   ' // !NO_WCN_KEYS


