' ########################################################################################
' Microsoft Windows
' File: WinSCard.inc
' Contents: This header file provides the definitions and symbols necessary for an
' Application or Smart Card Service Provider to access the Smartcard Subsystem.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSCARD_INC = 1

#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "winioctl.inc"
#INCLUDE ONCE "winsmcrd.inc"
#IF NOT %DEF(%SCARD_S_SUCCESS)
#INCLUDE ONCE "SCardErr.inc"
#ENDIF

'/* In clr:pure we cannot mark data export with dllimport.
' * We should add small functions which returns the value of
' * the global.
' */
'#if !defined(_M_CEE_PURE)
'WINSCARDDATA extern const SCARD_IO_REQUEST
'    g_rgSCardT0Pci,
'    g_rgSCardT1Pci,
'    g_rgSCardRawPci;
'#define SCARD_PCI_T0  (&g_rgSCardT0Pci)
'#define SCARD_PCI_T1  (&g_rgSCardT1Pci)
'#define SCARD_PCI_RAW (&g_rgSCardRawPci)
'#endif


'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Service Manager Access Services
'//
'//      The following services are used to manage user and terminal contexts for
'//      Smart Cards.
'//

'typedef ULONG_PTR SCARDCONTEXT;
'typedef SCARDCONTEXT *PSCARDCONTEXT, *LPSCARDCONTEXT;

'typedef ULONG_PTR SCARDHANDLE;
'typedef SCARDHANDLE *PSCARDHANDLE, *LPSCARDHANDLE;

'#define SCARD_AUTOALLOCATE (DWORD)(-1)
%SCARD_AUTOALLOCATE = &HFFFFFFFF???

'#define SCARD_SCOPE_USER     0  // The context is a user context, and any
'                                // database operations are performed within the
'                                // domain of the user.
'#define SCARD_SCOPE_TERMINAL 1  // The context is that of the current terminal,
'                                // and any database operations are performed
'                                // within the domain of that terminal.  (The
'                                // calling application must have appropriate
'                                // access permissions for any database actions.)
'#define SCARD_SCOPE_SYSTEM    2 // The context is the system context, and any
'                                // database operations are performed within the
'                                // domain of the system.  (The calling
'                                // application must have appropriate access
'                                // permissions for any database actions.)

%SCARD_SCOPE_USER     = 0
%SCARD_SCOPE_TERMINAL = 1
%SCARD_SCOPE_SYSTEM   = 2

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardEstablishContext LIB "WinSCard.dll" _
    ALIAS "SCardEstablishContext" (BYVAL dwScope AS DWORD, _
    pvReserved1 AS DWORD, pvReserved2 AS DWORD, phContext AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardEstablishContext IMPORT "WINSCARD.DLL" ALIAS "SCardEstablishContext" ( _
   BYVAL dwScope AS DWORD _                             ' __in  DWORD dwScope
 , BYVAL pvReserved1 AS DWORD _                         ' __in  LPCVOID pvReserved1
 , BYVAL pvReserved2 AS DWORD _                         ' __in  LPCVOID pvReserved2
 , BYREF phContext AS DWORD _                           ' __out LPSCARDCONTEXT phContext
 ) AS LONG                                              ' LONG
#ENDIF

DECLARE FUNCTION SCardReleaseContext IMPORT "WINSCARD.DLL" ALIAS "SCardReleaseContext" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardIsValidContext IMPORT "WINSCARD.DLL" ALIAS "SCardIsValidContext" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 ) AS LONG                                              ' LONG

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Smart Card Database Management Services
'//
'//      The following services provide for managing the Smart Card Database.
'//

'#define SCARD_ALL_READERS       TEXT("SCard$AllReaders\000")
'#define SCARD_DEFAULT_READERS   TEXT("SCard$DefaultReaders\000")
'#define SCARD_LOCAL_READERS     TEXT("SCard$LocalReaders\000")
'#define SCARD_SYSTEM_READERS    TEXT("SCard$SystemReaders\000")

$SCARD_ALL_READERS     = "SCard$AllReaders" & $NUL & $NUL & $NUL
$SCARD_DEFAULT_READERS = "SCard$DefaultReaders" & $NUL & $NUL & $NUL
$SCARD_LOCAL_READERS   = "SCard$LocalReaders" & $NUL & $NUL & $NUL
$SCARD_SYSTEM_READERS  = "SCard$SystemReaders" & $NUL & $NUL & $NUL

%SCARD_PROVIDER_PRIMARY  = 1  ' // Primary Provider Id
%SCARD_PROVIDER_CSP      = 2  ' // Crypto Service Provider Id
%SCARD_PROVIDER_KSP      = 3  ' // Key Storage Provider Id

'//
'// Database Reader routines
'//

DECLARE FUNCTION SCardListReaderGroupsA IMPORT "WINSCARD.DLL" ALIAS "SCardListReaderGroupsA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszGroups AS ASCIIZ  _                         ' __out   LPSTR mszGroups
 , BYREF pcchGroups AS DWORD _                          ' __inout LPDWORD pcchGroups
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardListReaderGroupsW IMPORT "WINSCARD.DLL" ALIAS "SCardListReaderGroupsW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszGroups AS WSTRINGZ _                        ' __out   LPWSTR mszGroups
 , BYREF pcchGroups AS DWORD _                          ' __inout LPDWORD pcchGroups
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardListReaderGroups = SCardListReaderGroupsW
#ELSE
   MACRO SCardListReaderGroups = SCardListReaderGroupsA
#ENDIF

DECLARE FUNCTION SCardListReadersA IMPORT "WINSCARD.DLL" ALIAS "SCardListReadersA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszGroups AS ASCIIZ _                          ' __in    LPCSTR mszGroups
 , BYREF mszReaders AS ASCIIZ _                         ' __out   LPSTR mszReaders
 , BYREF pcchReaders AS DWORD _                         ' __inout LPDWORD pcchReaders
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardListReadersW IMPORT "WINSCARD.DLL" ALIAS "SCardListReadersW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszGroups AS WSTRINGZ _                        ' __in    LPCWSTR mszGroups
 , BYREF mszReaders AS WSTRINGZ _                       ' __out   LPWSTR mszReaders
 , BYREF pcchReaders AS DWORD _                         ' __inout LPDWORD pcchReaders
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardListReaders = SCardListReadersW
#ELSE
   MACRO SCardListReaders = SCardListReadersA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardListCardsA LIB "WinSCard.dll" ALIAS "SCardListCardsA" _
    (BYVAL hContext AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    BYVAL rgquidInterfaces AS GUID PTR, BYVAL cguidInterfaceCount AS DWORD, _
    mszCards AS ASCIIZ, pcchCards AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardListCardsA IMPORT "WINSCARD.DLL" ALIAS "SCardListCardsA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYVAL pbAtr AS BYTE PTR _                            ' __in    LPCBYTE pbAtr
 , BYREF rgquidInterfaces AS GUID _                     ' __in    LPCGUID rgquidInterfaces
 , BYVAL cguidInterfaceCount AS DWORD _                 ' __in    DWORD cguidInterfaceCount
 , BYREF mszCards AS ASCIIZ _                           ' __out   LPSTR mszCards
 , BYREF pcchCards AS DWORD _                           ' __inout LPDWORD pcchCards
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardListCardsW LIB "WinSCard.dll" ALIAS "SCardListCardsW" _
    (BYVAL hContext AS DWORD, BYVAL pbAtr AS BYTE PTR, _
    BYVAL rgquidInterfaces AS GUID PTR, BYVAL cguidInterfaceCount AS DWORD, _
    mszCards AS WSTRINGZ, pcchCards AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardListCardsW IMPORT "WINSCARD.DLL" ALIAS "SCardListCardsW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYVAL pbAtr AS BYTE PTR _                            ' __in    LPCBYTE pbAtr
 , BYREF rgquidInterfaces AS GUID _                     ' __in    LPCGUID rgquidInterfaces
 , BYVAL cguidInterfaceCount AS DWORD _                 ' __in    DWORD cguidInterfaceCount
 , BYREF mszCards AS WSTRINGZ _                         ' __out   LPWSTR mszCards
 , BYREF pcchCards AS DWORD _                           ' __inout LPDWORD pcchCards
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardListCards = SCardListCardsW
#ELSE
   MACRO SCardListCards = SCardListCardsA
#ENDIF

'//
'// NOTE:    The routine SCardListCards name differs from the PC/SC definition.
'//          It should be:
'//
'//              extern WINSCARDAPI LONG WINAPI
'//              SCardListCardTypes(
'//                  IN      SCARDCONTEXT hContext,
'//                  IN      LPCBYTE pbAtr,
'//                  IN      LPCGUID rgquidInterfaces,
'//                  IN      DWORD cguidInterfaceCount,
'//                  OUT     LPTSTR mszCards,
'//                  IN OUT  LPDWORD pcchCards);
'//
'//          Here's a work-around MACRO:
'#define SCardListCardTypes SCardListCards

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardListInterfacesA LIB "WinSCard.dll" _
    ALIAS "SCardListInterfacesA" (BYVAL hContext AS DWORD, szCard AS ASCIIZ, _
    BYVAL pguidInterfaces AS GUID PTR, pcguidInterfaces AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardListInterfacesA IMPORT "WINSCARD.DLL" ALIAS "SCardListInterfacesA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF szCard AS ASCIIZ _                             ' __in    LPCSTR szCard
 , BYREF pguidInterfaces AS GUID _                      ' __out   LPGUID pguidInterfaces
 , BYREF pcguidInterfaces AS DWORD _                    ' __inout LPDWORD pcguidInterfaces
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardListInterfacesW LIB "WinSCard.dll" _
    ALIAS "SCardListInterfacesW" (BYVAL hContext AS DWORD, _
    szCard AS WSTRINGZ, BYVAL pguidInterfaces AS GUID PTR, _
    pcguidInterfaces AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardListInterfacesW IMPORT "WINSCARD.DLL" ALIAS "SCardListInterfacesW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF szCard AS WSTRINGZ _                           ' __in    LPCWSTR szCard
 , BYREF pguidInterfaces AS GUID _                      ' __out   LPGUID pguidInterfaces
 , BYREF pcguidInterfaces AS DWORD _                    ' __inout LPDWORD pcguidInterfaces
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardListInterfaces = SCardListInterfacesW
#ELSE
   MACRO SCardListInterfaces = SCardListInterfacesA
#ENDIF

DECLARE FUNCTION SCardGetProviderIdA IMPORT "WINSCARD.DLL" ALIAS "SCardGetProviderIdA" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF szCard AS ASCIIZ _                             ' __in  LPCSTR szCard
 , BYREF pguidProviderId AS GUID _                      ' __out LPGUID pguidProviderId
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardGetProviderIdW IMPORT "WINSCARD.DLL" ALIAS "SCardGetProviderIdW" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF szCard AS WSTRINGZ _                           ' __in  LPCWSTR szCard
 , BYREF pguidProviderId AS GUID _                      ' __out LPGUID pguidProviderId
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardGetProviderId = SCardGetProviderIdW
#ELSE
   MACRO SCardGetProviderId = SCardGetProviderIdA
#ENDIF

'//
'// NOTE:    The routine SCardGetProviderId in this implementation uses GUIDs.
'//          The PC/SC definition uses BYTEs.
'//

DECLARE FUNCTION SCardGetCardTypeProviderNameA IMPORT "WINSCARD.DLL" ALIAS "SCardGetCardTypeProviderNameA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF szCardName AS ASCIIZ _                         ' __in    LPCSTR szCardName
 , BYVAL dwProviderId AS DWORD _                        ' __in    DWORD dwProviderId
 , BYREF szProvider AS ASCIIZ _                         ' __out   LPSTR szProvider
 , BYREF pcchProvider AS DWORD _                        ' __inout LPDWORD pcchProvider
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardGetCardTypeProviderNameW IMPORT "WINSCARD.DLL" ALIAS "SCardGetCardTypeProviderNameW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF szCardName AS WSTRINGZ _                       ' __in    LPCWSTR szCardName
 , BYVAL dwProviderId AS DWORD _                        ' __in    DWORD dwProviderId
 , BYREF szProvider AS WSTRINGZ _                       ' __out   LPWSTR szProvider
 , BYREF pcchProvider AS DWORD _                        ' __inout LPDWORD pcchProvider
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardGetCardTypeProviderName = SCardGetCardTypeProviderNameW
#ELSE
   MACRO SCardGetCardTypeProviderName = SCardGetCardTypeProviderNameA
#ENDIF

'//
'// NOTE:    This routine is an extension to the PC/SC definitions.
'//


'//
'// Database Writer routines
'//

DECLARE FUNCTION SCardIntroduceReaderGroupA IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceReaderGroupA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szGroupName AS ASCIIZ _                        ' __in LPCSTR szGroupName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardIntroduceReaderGroupW IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceReaderGroupW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szGroupName AS WSTRINGZ _                      ' __in LPCWSTR szGroupName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardIntroduceReaderGroup = SCardIntroduceReaderGroupW
#ELSE
   MACRO SCardIntroduceReaderGroup = SCardIntroduceReaderGroupA
#ENDIF

DECLARE FUNCTION SCardForgetReaderGroupA IMPORT "WINSCARD.DLL" ALIAS "SCardForgetReaderGroupA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szGroupName AS ASCIIZ _                        ' __in LPCSTR szGroupName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardForgetReaderGroupW IMPORT "WINSCARD.DLL" ALIAS "SCardForgetReaderGroupW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szGroupName AS WSTRINGZ _                      ' __in LPCWSTR szGroupName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardForgetReaderGroup = SCardForgetReaderGroupW
#ELSE
   MACRO SCardForgetReaderGroup = SCardForgetReaderGroupA
#ENDIF

DECLARE FUNCTION SCardIntroduceReaderA IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceReaderA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS ASCIIZ _                       ' __in LPCSTR szReaderName
 , BYREF szDeviceName AS ASCIIZ _                       ' __in LPCSTR szDeviceName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardIntroduceReaderW IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceReaderW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS WSTRINGZ _                     ' __in LPCWSTR szReaderName
 , BYREF szDeviceName AS WSTRINGZ _                     ' __in LPCWSTR szDeviceName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardIntroduceReader = SCardIntroduceReaderW
#ELSE
   MACRO SCardIntroduceReader = SCardIntroduceReaderA
#ENDIF

DECLARE FUNCTION SCardForgetReaderA IMPORT "WINSCARD.DLL" ALIAS "SCardForgetReaderA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS ASCIIZ _                       ' __in LPCSTR szReaderName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardForgetReaderW IMPORT "WINSCARD.DLL" ALIAS "SCardForgetReaderW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS WSTRINGZ _                     ' __in LPCWSTR szReaderName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardForgetReader = SCardForgetReaderW
#ELSE
   MACRO SCardForgetReader = SCardForgetReaderA
#ENDIF

DECLARE FUNCTION SCardAddReaderToGroupA IMPORT "WINSCARD.DLL" ALIAS "SCardAddReaderToGroupA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS ASCIIZ _                       ' __in LPCSTR szReaderName
 , BYREF szGroupName AS ASCIIZ _                        ' __in LPCSTR szGroupName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardAddReaderToGroupW IMPORT "WINSCARD.DLL" ALIAS "SCardAddReaderToGroupW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS WSTRINGZ _                     ' __in LPCWSTR szReaderName
 , BYREF szGroupName AS WSTRINGZ _                      ' __in LPCWSTR szGroupName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardAddReaderToGroup = SCardAddReaderToGroupW
#ELSE
   MACRO SCardAddReaderToGroup = SCardAddReaderToGroupA
#ENDIF

DECLARE FUNCTION SCardRemoveReaderFromGroupA IMPORT "WINSCARD.DLL" ALIAS "SCardRemoveReaderFromGroupA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS ASCIIZ _                       ' __in LPCSTR szReaderName
 , BYREF szGroupName AS ASCIIZ _                        ' __in LPCSTR szGroupName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardRemoveReaderFromGroupW IMPORT "WINSCARD.DLL" ALIAS "SCardRemoveReaderFromGroupW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szReaderName AS WSTRINGZ _                     ' __in LPCWSTR szReaderName
 , BYREF szGroupName AS WSTRINGZ _                      ' __in LPCWSTR szGroupName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardRemoveReaderFromGroup = SCardRemoveReaderFromGroupW
#ELSE
   MACRO SCardRemoveReaderFromGroup = SCardRemoveReaderFromGroupA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardIntroduceCardTypeA LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceCardTypeA" (BYVAL hContext AS DWORD, _
    szCardName AS ASCIIZ, pguidPrimaryProvider AS GUID, _
    BYVAL rgGuidInterfaces AS GUID PTR, BYVAL dwInterfaceCount AS DWORD, _
    BYVAL pbAtr AS BYTE PTR, BYVAL pbAtrMask AS BYTE PTR, _
    BYVAL cbAtrLen AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardIntroduceCardTypeA IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceCardTypeA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS ASCIIZ _                         ' __in LPCSTR szCardName
 , BYREF pguidPrimaryProvider AS GUID _                 ' __in LPCGUID pguidPrimaryProvider
 , BYREF rgguidInterfaces AS GUID _                     ' __in LPCGUID rgguidInterfaces
 , BYVAL dwInterfaceCount AS DWORD _                    ' __in DWORD dwInterfaceCount
 , BYVAL pbAtr AS BYTE PTR _                            ' __in LPCBYTE pbAtr
 , BYVAL pbAtrMask AS BYTE PTR _                        ' __in LPCBYTE pbAtrMask
 , BYVAL cbAtrLen AS DWORD _                            ' __in DWORD cbAtrLen
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardIntroduceCardTypeW LIB "WinSCard.dll" _
    ALIAS "SCardIntroduceCardTypeW" (BYVAL hContext AS DWORD, _
    szCardName AS WSTRINGZ, pguidPrimaryProvider AS GUID, _
    BYVAL rgGuidInterfaces AS GUID PTR, BYVAL dwInterfaceCount AS DWORD, _
    BYVAL pbAtr AS BYTE PTR, BYVAL pbAtrMask AS BYTE PTR, _
    BYVAL cbAtrLen AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardIntroduceCardTypeW IMPORT "WINSCARD.DLL" ALIAS "SCardIntroduceCardTypeW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS WSTRINGZ _                       ' __in LPCWSTR szCardName
 , BYREF pguidPrimaryProvider AS GUID _                 ' __in LPCGUID pguidPrimaryProvider
 , BYREF rgguidInterfaces AS GUID _                     ' __in LPCGUID rgguidInterfaces
 , BYVAL dwInterfaceCount AS DWORD _                    ' __in DWORD dwInterfaceCount
 , BYVAL pbAtr AS BYTE PTR _                            ' __in LPCBYTE pbAtr
 , BYVAL pbAtrMask AS BYTE PTR _                        ' __in LPCBYTE pbAtrMask
 , BYVAL cbAtrLen AS DWORD _                            ' __in DWORD cbAtrLen
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardIntroduceCardType = SCardIntroduceCardTypeW
#ELSE
   MACRO SCardIntroduceCardType = SCardIntroduceCardTypeA
#ENDIF

'//
'// NOTE:    The routine SCardIntroduceCardType's parameters' order differs from
'//          the PC/SC definition.  It should be:
'//
'//              extern WINSCARDAPI LONG WINAPI
'//              SCardIntroduceCardType(
'//                  IN SCARDCONTEXT hContext,
'//                  IN LPCTSTR szCardName,
'//                  IN LPCBYTE pbAtr,
'//                  IN LPCBYTE pbAtrMask,
'//                  IN DWORD cbAtrLen,
'//                  IN LPCGUID pguidPrimaryProvider,
'//                  IN LPCGUID rgguidInterfaces,
'//                  IN DWORD dwInterfaceCount);
'//
'//          Here's a work-around MACRO:
'#define PCSCardIntroduceCardType(hContext, szCardName, pbAtr, pbAtrMask, cbAtrLen, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount) \
'          SCardIntroduceCardType(hContext, szCardName, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount, pbAtr, pbAtrMask, cbAtrLen)

DECLARE FUNCTION SCardSetCardTypeProviderNameA IMPORT "WINSCARD.DLL" ALIAS "SCardSetCardTypeProviderNameA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS ASCIIZ _                         ' __in LPCSTR szCardName
 , BYVAL dwProviderId AS DWORD _                        ' __in DWORD dwProviderId
 , BYREF szProvider AS ASCIIZ _                         ' __in LPCSTR szProvider
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardSetCardTypeProviderNameW IMPORT "WINSCARD.DLL" ALIAS "SCardSetCardTypeProviderNameW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS WSTRINGZ _                       ' __in LPCWSTR szCardName
 , BYVAL dwProviderId AS DWORD _                        ' __in DWORD dwProviderId
 , BYREF szProvider AS WSTRINGZ _                       ' __in LPCWSTR szProvider
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardSetCardTypeProviderName = SCardSetCardTypeProviderNameW
#ELSE
   MACRO SCardSetCardTypeProviderName = SCardSetCardTypeProviderNameA
#ENDIF

'//
'// NOTE:    This routine is an extention to the PC/SC specifications.
'//

DECLARE FUNCTION SCardForgetCardTypeA IMPORT "WINSCARD.DLL" ALIAS "SCardForgetCardTypeA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS ASCIIZ _                         ' __in LPCSTR szCardName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardForgetCardTypeW IMPORT "WINSCARD.DLL" ALIAS "SCardForgetCardTypeW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF szCardName AS WSTRINGZ _                       ' __in LPCWSTR szCardName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardForgetCardType = SCardForgetCardTypeW
#ELSE
   MACRO SCardForgetCardType = SCardForgetCardTypeA
#ENDIF

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Service Manager Support Routines
'//
'//      The following services are supplied to simplify the use of the Service
'//      Manager API.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardFreeMemory LIB "WinSCard.dll" ALIAS "SCardFreeMemory" _
    (BYVAL hContext AS DWORD, pvMem AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardFreeMemory IMPORT "WINSCARD.DLL" ALIAS "SCardFreeMemory" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYVAL pvMem AS DWORD _                               ' __in LPCVOID pvMem
 ) AS LONG                                              ' LONG
#ENDIF

DECLARE FUNCTION SCardAccessStartedEvent IMPORT "WINSCARD.DLL" ALIAS "SCardAccessStartedEvent" ( _
 ) AS DWORD                                             ' HANDLE

DECLARE SUB SCardReleaseStartedEvent IMPORT "WINSCARD.DLL" ALIAS "SCardReleaseStartedEvent" ()   ' void

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Reader Services
'//
'//      The following services supply means for tracking cards within readers.
'//

' // Size = 56 bytes
TYPE SCARD_READERSTATEA DWORD
   szReader       AS ASCIIZ PTR   ' LPCSTR
   pvUserData     AS DWORD        ' LPVOID
   dwCurrentState AS DWORD        ' DWORD
   dwEventState   AS DWORD        ' DWORD
   cbAtr          AS DWORD        ' DWORD
   rgbAtr(35)     AS BYTE         ' BYTE rgbAtr[36]
END TYPE

' // Size = 56 bytes
TYPE SCARD_READERSTATEW DWORD
   szReader       AS WSTRINGZ PTR   ' LPCWSTR
   pvUserData     AS DWORD          ' LPVOID
   dwCurrentState AS DWORD          ' DWORD
   dwEventState   AS DWORD          ' DWORD
   cbAtr          AS DWORD          ' DWORD
   rgbAtr(35)     AS BYTE           ' BYTE rgbAtr[36]
END TYPE

#IF %DEF(%UNICODE)
   MACRO SCARD_READERSTATE = SCARD_READERSTATEW
#ELSE
   MACRO SCARD_READERSTATE = SCARD_READERSTATEA
#ENDIF

'#define SCARD_STATE_UNAWARE     0x00000000  // The application is unaware of the
'                                            // current state, and would like to
'                                            // know.  The use of this value
'                                            // results in an immediate return
'                                            // from state transition monitoring
'                                            // services.  This is represented by
'                                            // all bits set to zero.
'#define SCARD_STATE_IGNORE      0x00000001  // The application requested that
'                                            // this reader be ignored.  No other
'                                            // bits will be set.
'#define SCARD_STATE_CHANGED     0x00000002  // This implies that there is a
'                                            // difference between the state
'                                            // believed by the application, and
'                                            // the state known by the Service
'                                            // Manager.  When this bit is set,
'                                            // the application may assume a
'                                            // significant state change has
'                                            // occurred on this reader.
'#define SCARD_STATE_UNKNOWN     0x00000004  // This implies that the given
'                                            // reader name is not recognized by
'                                            // the Service Manager.  If this bit
'                                            // is set, then SCARD_STATE_CHANGED
'                                            // and SCARD_STATE_IGNORE will also
'                                            // be set.
'#define SCARD_STATE_UNAVAILABLE 0x00000008  // This implies that the actual
'                                            // state of this reader is not
'                                            // available.  If this bit is set,
'                                            // then all the following bits are
'                                            // clear.
'#define SCARD_STATE_EMPTY       0x00000010  // This implies that there is not
'                                            // card in the reader.  If this bit
'                                            // is set, all the following bits
'                                            // will be clear.
'#define SCARD_STATE_PRESENT     0x00000020  // This implies that there is a card
'                                            // in the reader.
'#define SCARD_STATE_ATRMATCH    0x00000040  // This implies that there is a card
'                                            // in the reader with an ATR
'                                            // matching one of the target cards.
'                                            // If this bit is set,
'                                            // SCARD_STATE_PRESENT will also be
'                                            // set.  This bit is only returned
'                                            // on the SCardLocateCard() service.
'#define SCARD_STATE_EXCLUSIVE   0x00000080  // This implies that the card in the
'                                            // reader is allocated for exclusive
'                                            // use by another application.  If
'                                            // this bit is set,
'                                            // SCARD_STATE_PRESENT will also be
'                                            // set.
'#define SCARD_STATE_INUSE       0x00000100  // This implies that the card in the
'                                            // reader is in use by one or more
'                                            // other applications, but may be
'                                            // connected to in shared mode.  If
'                                            // this bit is set,
'                                            // SCARD_STATE_PRESENT will also be
'                                            // set.
'#define SCARD_STATE_MUTE        0x00000200  // This implies that the card in the
'                                            // reader is unresponsive or not
'                                            // supported by the reader or
'                                            // software.
'#define SCARD_STATE_UNPOWERED   0x00000400  // This implies that the card in the
'                                            // reader has not been powered up.

%SCARD_STATE_UNAWARE     = &H00000000???
%SCARD_STATE_IGNORE      = &H00000001???
%SCARD_STATE_CHANGED     = &H00000002???
%SCARD_STATE_UNKNOWN     = &H00000004???
%SCARD_STATE_UNAVAILABLE = &H00000008???
%SCARD_STATE_EMPTY       = &H00000010???
%SCARD_STATE_PRESENT     = &H00000020???
%SCARD_STATE_ATRMATCH    = &H00000040???
%SCARD_STATE_EXCLUSIVE   = &H00000080???
%SCARD_STATE_INUSE       = &H00000100???
%SCARD_STATE_MUTE        = &H00000200???
%SCARD_STATE_UNPOWERED   = &H00000400???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardLocateCardsA LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsA" (BYVAL hContext AS DWORD, mszCards AS ASCIIZ, _
    BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, BYVAL cReaders AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SCardLocateCardsA IMPORT "WINSCARD.DLL" ALIAS "SCardLocateCardsA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszCards AS ASCIIZ _                           ' __in    LPCSTR mszCards
 , BYREF rgReaderStates AS SCARD_READERSTATEA _         ' __inout LPSCARD_READERSTATEA rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardLocateCardsW LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsW" (BYVAL hContext AS DWORD, mszCards AS WSTRINGZ, _
    BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, BYVAL cReaders AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SCardLocateCardsW IMPORT "WINSCARD.DLL" ALIAS "SCardLocateCardsW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF mszCards AS ASCIIZ _                           ' __in    LPCSTR mszCards
 , BYREF rgReaderStates AS SCARD_READERSTATEW _         ' __inout LPSCARD_READERSTATEW rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardLocateCards = SCardLocateCardsW
#ELSE
   MACRO SCardLocateCards = SCardLocateCardsA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXP)
' // Size = 76 bytes
TYPE SCARD_ATRMASK DWORD
   cbAtr       AS DWORD   ' DWORD // Number of bytes in the ATR and the mask.
   rgbAtr(35)  AS BYTE    ' BYTE rgbAtr[36]  // Atr of card (extra alignment bytes)
   rgbMask(35) AS BYTE    ' BYTE rgbMask[36] // Mask for the Atr (extra alignment bytes)
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardLocateCardsByATRA LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsByATRA" (BYVAL hContext AS DWORD, _
    BYVAL rgAtrMasks AS SCARD_ATRMASK PTR, BYVAL cAtrs AS DWORD, _
    BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, BYVAL cReaders AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SCardLocateCardsByATRA IMPORT "WINSCARD.DLL" ALIAS "SCardLocateCardsByATRA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF rgAtrMasks AS SCARD_ATRMASK _                  ' __in    LPSCARD_ATRMASK rgAtrMasks
 , BYVAL cAtrs AS DWORD _                               ' __in    DWORD cAtrs
 , BYREF rgReaderStates AS SCARD_READERSTATEA _         ' __inout LPSCARD_READERSTATEA rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardLocateCardsByATRW LIB "WinSCard.dll" _
    ALIAS "SCardLocateCardsByATRW" (BYVAL hContext AS DWORD, _
    BYVAL rgAtrMasks AS SCARD_ATRMASK PTR, BYVAL cAtrs AS DWORD, _
    BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, BYVAL cReaders AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SCardLocateCardsByATRW IMPORT "WINSCARD.DLL" ALIAS "SCardLocateCardsByATRW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYREF rgAtrMasks AS SCARD_ATRMASK _                  ' __in    LPSCARD_ATRMASK rgAtrMasks
 , BYVAL cAtrs AS DWORD _                               ' __in    DWORD cAtrs
 , BYREF rgReaderStates AS SCARD_READERSTATEW _         ' __inout LPSCARD_READERSTATEW rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardLocateCardsByATR = SCardLocateCardsByATRW
#ELSE
   MACRO SCardLocateCardsByATR = SCardLocateCardsByATRA
#ENDIF
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardGetStatusChangeA LIB "WinSCard.dll" _
    ALIAS "SCardGetStatusChangeA" (BYVAL hContext AS DWORD, _
    BYVAL dwTimeout AS DWORD, BYVAL rgReaderStates AS SCARD_READERSTATEA PTR, _
    BYVAL cReaders AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardGetStatusChangeA IMPORT "WINSCARD.DLL" ALIAS "SCardGetStatusChangeA" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYVAL dwTimeout AS DWORD _                           ' __in    DWORD dwTimeout
 , BYREF rgReaderStates AS SCARD_READERSTATEA _         ' __inout LPSCARD_READERSTATEA rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardGetStatusChangeW LIB "WinSCard.dll" _
    ALIAS "SCardGetStatusChangeW" (BYVAL hContext AS DWORD, _
    BYVAL dwTimeout AS DWORD, BYVAL rgReaderStates AS SCARD_READERSTATEW PTR, _
    BYVAL cReaders AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardGetStatusChangeW IMPORT "WINSCARD.DLL" ALIAS "SCardGetStatusChangeW" ( _
   BYVAL hContext AS DWORD _                            ' __in    SCARDCONTEXT hContext
 , BYVAL dwTimeout AS DWORD _                           ' __in    DWORD dwTimeout
 , BYREF rgReaderStates AS SCARD_READERSTATEW _         ' __inout LPSCARD_READERSTATEW rgReaderStates
 , BYVAL cReaders AS DWORD _                            ' __in    DWORD cReaders
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardGetStatusChange = SCardGetStatusChangeW
#ELSE
   MACRO SCardGetStatusChange = SCardGetStatusChangeA
#ENDIF

DECLARE FUNCTION SCardCancel IMPORT "WINSCARD.DLL" ALIAS "SCardCancel" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 ) AS LONG                                              ' LONG

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Card/Reader Communication Services
'//
'//      The following services provide means for communication with the card.
'//

%SCARD_SHARE_EXCLUSIVE = 1 ' // This application is not willing to share this
                           ' // card with other applications.
%SCARD_SHARE_SHARED    = 2 ' // This application is willing to share this
                           ' // card with other applications.
%SCARD_SHARE_DIRECT    = 3 ' // This application demands direct control of
                           ' // the reader, so it is not available to other
                           ' // applications.

%SCARD_LEAVE_CARD      = 0 ' // Don't do anything special on close
%SCARD_RESET_CARD      = 1 ' // Reset the card on close
%SCARD_UNPOWER_CARD    = 2 ' // Power down the card on close
%SCARD_EJECT_CARD      = 3 ' // Eject the card on close

DECLARE FUNCTION SCardConnectA IMPORT "WINSCARD.DLL" ALIAS "SCardConnectA" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF szReader AS ASCIIZ _                           ' __in  LPCSTR szReader
 , BYVAL dwShareMode AS DWORD _                         ' __in  DWORD dwShareMode
 , BYVAL dwPreferredProtocols AS DWORD _                ' __in  DWORD dwPreferredProtocols
 , BYREF phCard AS DWORD _                              ' __out LPSCARDHANDLE phCard
 , BYREF pdwActiveProtocol AS DWORD _                   ' __out LPDWORD pdwActiveProtocol
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardConnectW IMPORT "WINSCARD.DLL" ALIAS "SCardConnectW" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF szReader AS WSTRINGZ _                         ' __in  LPCWSTR szReader
 , BYVAL dwShareMode AS DWORD _                         ' __in  DWORD dwShareMode
 , BYVAL dwPreferredProtocols AS DWORD _                ' __in  DWORD dwPreferredProtocols
 , BYREF phCard AS DWORD _                              ' __out LPSCARDHANDLE phCard
 , BYREF pdwActiveProtocol AS DWORD _                   ' __out LPDWORD pdwActiveProtocol
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardConnect = SCardConnectW
#ELSE
   MACRO SCardConnect = SCardConnectA
#ENDIF

DECLARE FUNCTION SCardReconnect IMPORT "WINSCARD.DLL" ALIAS "SCardReconnect" ( _
   BYVAL hCard AS DWORD _                               ' __in  SCARDHANDLE hCard
 , BYVAL dwShareMode AS DWORD _                         ' __in  DWORD dwShareMode
 , BYVAL dwPreferredProtocols AS DWORD _                ' __in  DWORD dwPreferredProtocols
 , BYVAL dwInitialization AS DWORD _                    ' __in  DWORD dwInitialization
 , BYREF pdwActiveProtocol AS DWORD _                   ' __out LPDWORD pdwActiveProtocol
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardDisconnect IMPORT "WINSCARD.DLL" ALIAS "SCardDisconnect" ( _
   BYVAL hCard AS DWORD _                               ' __in SCARDHANDLE hCard
 , BYVAL dwDisposition AS DWORD _                       ' __in DWORD dwDisposition
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardBeginTransaction IMPORT "WINSCARD.DLL" ALIAS "SCardBeginTransaction" ( _
   BYVAL hCard AS DWORD _                               ' __in SCARDHANDLE hCard
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardEndTransaction IMPORT "WINSCARD.DLL" ALIAS "SCardEndTransaction" ( _
   BYVAL hCard AS DWORD _                               ' __in SCARDHANDLE hCard
 , BYVAL dwDisposition AS DWORD _                       ' __in DWORD dwDisposition
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardCancelTransaction IMPORT "WINSCARD.DLL" ALIAS "SCardCancelTransaction" ( _
   BYVAL hCard AS DWORD _                               ' __in SCARDHANDLE hCard
 ) AS LONG                                              ' LONG

'//
'// NOTE:    This call corresponds to the PC/SC SCARDCOMM::Cancel routine,
'//          terminating a blocked SCardBeginTransaction service.
'//

DECLARE FUNCTION SCardState IMPORT "WINSCARD.DLL" ALIAS "SCardState" ( _
   BYVAL hCard AS DWORD _                               ' __in    SCARDHANDLE hCard
 , BYREF pdwState AS DWORD _                            ' __out   LPDWORD pdwState
 , BYREF pdwProtocol AS DWORD _                         ' __out   LPDWORD pdwProtocol
 , BYVAL pbAtr AS BYTE PTR _                            ' __out   LPBYTE pbAtr
 , BYREF pcbAtrLen AS DWORD _                           ' __inout LPDWORD pcbAtrLen
 ) AS LONG                                              ' LONG

'//
'// NOTE:    SCardState is an obsolete routine.  PC/SC has replaced it with
'//          SCardStatus.
'//

DECLARE FUNCTION SCardStatusA IMPORT "WINSCARD.DLL" ALIAS "SCardStatusA" ( _
   BYVAL hCard AS DWORD _                               ' __in    SCARDHANDLE hCard
 , BYREF szReaderName AS ASCIIZ _                       ' __out   LPSTR szReaderName
 , BYREF pcchReaderLen AS DWORD _                       ' __inout LPDWORD pcchReaderLen
 , BYREF pdwState AS DWORD _                            ' __out   LPDWORD pdwState
 , BYREF pdwProtocol AS DWORD _                         ' __out   LPDWORD pdwProtocol
 , BYVAL pbAtr AS BYTE PTR _                            ' __out   LPBYTE pbAtr
 , BYREF pcbAtrLen AS DWORD _                           ' __inout LPDWORD pcbAtrLen
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardStatusW IMPORT "WINSCARD.DLL" ALIAS "SCardStatusW" ( _
   BYVAL hCard AS DWORD _                               ' __in    SCARDHANDLE hCard
 , BYREF szReaderName AS WSTRINGZ _                     ' __out   LPWSTR szReaderName
 , BYREF pcchReaderLen AS DWORD _                       ' __inout LPDWORD pcchReaderLen
 , BYREF pdwState AS DWORD _                            ' __out   LPDWORD pdwState
 , BYREF pdwProtocol AS DWORD _                         ' __out   LPDWORD pdwProtocol
 , BYVAL pbAtr AS BYTE PTR _                            ' __out   LPBYTE pbAtr
 , BYREF pcbAtrLen AS DWORD _                           ' __inout LPDWORD pcbAtrLen
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardStatus = SCardStatusW
#ELSE
   MACRO SCardStatus = SCardStatusA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardTransmit LIB "WinSCard.dll" ALIAS "SCardTransmit" _
    (BYVAL hCard AS DWORD, pioSendPci AS DWORD, _
    BYVAL pbSendBuffer AS BYTE PTR, BYVAL cbSendLength AS DWORD, _
    pioRecvPci AS DWORD, BYVAL pbRecvBuffer AS BYTE PTR, _
    pcbRecvLength AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardTransmit IMPORT "WINSCARD.DLL" ALIAS "SCardTransmit" ( _
   BYVAL hCard AS DWORD _                               ' __in    SCARDHANDLE hCard
 , BYREF pioSendPci AS SCARD_IO_REQUEST _               ' __in    LPCSCARD_IO_REQUEST pioSendPci
 , BYVAL pbSendBuffer AS BYTE PTR _                     ' __in    LPCBYTE pbSendBuffer
 , BYVAL cbSendLength AS DWORD _                        ' __in    DWORD cbSendLength
 , BYREF pioRecvPci AS SCARD_IO_REQUEST _               ' __inout LPSCARD_IO_REQUEST pioRecvPci
 , BYVAL pbRecvBuffer AS BYTE PTR _                     ' __out   LPBYTE pbRecvBuffer
 , BYREF pcbRecvLength AS DWORD _                       ' __inout LPDWORD pcbRecvLength
 ) AS LONG                                              ' LONG
#ENDIF

'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Reader Control Routines
'//
'//      The following services provide for direct, low-level manipulation of the
'//      reader by the calling application allowing it control over the
'//      attributes of the communications with the card.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardControl LIB "WinSCard.dll" ALIAS "SCardControl" _
    (BYVAL hCard AS DWORD, BYVAL dwControlCode AS DWORD, _
    lpInBuffer AS ANY, BYVAL nInBufferSize AS DWORD, lpOutBuffer AS ANY, _
    BYVAL nOutBufferSize AS DWORD, lpBytesReturned AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardControl IMPORT "WINSCARD.DLL" ALIAS "SCardControl" ( _
   BYVAL hCard AS DWORD _                               ' __in  SCARDHANDLE hCard
 , BYVAL dwControlCode AS DWORD _                       ' __in  DWORD dwControlCode
 , BYVAL lpInBuffer AS DWORD _                          ' __in  LPCVOID lpInBuffer
 , BYVAL nInBufferSize AS DWORD _                       ' __in  DWORD nInBufferSize
 , BYREF lpOutBuffer AS ANY _                           ' __out LPVOID lpOutBuffer
 , BYVAL nOutBufferSize AS DWORD _                      ' __in  DWORD nOutBufferSize
 , BYREF lpBytesReturned AS DWORD _                     ' __out LPDWORD lpBytesReturned
 ) AS LONG                                              ' LONG
#ENDIF

DECLARE FUNCTION SCardGetAttrib IMPORT "WINSCARD.DLL" ALIAS "SCardGetAttrib" ( _
   BYVAL hCard AS DWORD _                               ' __in    SCARDHANDLE hCard
 , BYVAL dwAttrId AS DWORD _                            ' __in    DWORD dwAttrId
 , BYVAL pbAttr AS DWORD _                              ' __out   LPBYTE pbAttr
 , BYREF pcbAttrLen AS DWORD _                          ' __inout LPDWORD pcbAttrLen
 ) AS LONG                                              ' LONG

'//
'// NOTE:    The routine SCardGetAttrib's name differs from the PC/SC definition.
'//          It should be:
'//
'//              extern WINSCARDAPI LONG WINAPI
'//              SCardGetReaderCapabilities(
'//                  IN SCARDHANDLE hCard,
'//                  IN DWORD dwTag,
'//                  OUT LPBYTE pbAttr,
'//                  IN OUT LPDWORD pcbAttrLen);
'//
'//          Here's a work-around MACRO:
'#define SCardGetReaderCapabilities SCardGetAttrib

DECLARE FUNCTION SCardSetAttrib IMPORT "WINSCARD.DLL" ALIAS "SCardSetAttrib" ( _
   BYVAL hCard AS DWORD _                               ' __in SCARDHANDLE hCard
 , BYVAL dwAttrId AS DWORD _                            ' __in DWORD dwAttrId
 , BYVAL pbAttr AS BYTE PTR _                           ' __in LPCBYTE pbAttr
 , BYVAL cbAttrLen AS DWORD _                           ' __in DWORD cbAttrLen
 ) AS LONG                                              ' LONG

'//
'// NOTE:    The routine SCardSetAttrib's name differs from the PC/SC definition.
'//          It should be:
'//
'//              extern WINSCARDAPI LONG WINAPI
'//              SCardSetReaderCapabilities(
'//                  IN SCARDHANDLE hCard,
'//                  IN DWORD dwTag,
'//                  OUT LPBYTE pbAttr,
'//                  IN OUT LPDWORD pcbAttrLen);
'//
'//          Here's a work-around MACRO:
'#define SCardSetReaderCapabilities SCardSetAttrib


'//
'////////////////////////////////////////////////////////////////////////////////
'//
'//  Smart Card Dialog definitions
'//
'//      The following section contains structures and  exported function
'//      declarations for the Smart Card Common Dialog dialog.
'//

'// Defined constants
'// Flags
%SC_DLG_MINIMAL_UI       = &H01
%SC_DLG_NO_UI            = &H02
%SC_DLG_FORCE_UI         = &H04

%SCERR_NOCARDNAME        = &H4000
%SCERR_NOGUIDS           = &H8000

'typedef SCARDHANDLE (WINAPI *LPOCNCONNPROCA) (IN SCARDCONTEXT, IN LPSTR, IN LPSTR, IN PVOID);

'FUNCTION OCNCONNPROCA ( _
'   BYVAL DWORD, _                      ' __in SCARDCONTEXT
'   BYREF ASCIIZ, _                     ' __in LPSTR
'   BYREF ASCIIZ, _                     ' __in LPSTR
'   BYVAL DWORD _                       ' __in PVOID
'   ) AS DWORD                          ' SCANHANDLE

'typedef SCARDHANDLE (WINAPI *LPOCNCONNPROCW) (IN SCARDCONTEXT, IN LPWSTR, IN LPWSTR, IN PVOID);

'FUNCTION OCNCONNPROCW ( _
'   BYVAL DWORD, _                      ' __in SCARDCONTEXT
'   BYREF WSTRINGZ, _                   ' __in LPWSTR
'   BYREF WSTRINGZ, _                   ' __in LPWSTR
'   BYVAL DWORD _                       ' __in PVOID
'   ) AS DWORD                          ' SCANHANDLE

'typedef BOOL (WINAPI *LPOCNCHKPROC) (IN SCARDCONTEXT, IN SCARDHANDLE, IN PVOID);

'FUNCTION OCNCHKPROC ( _
'   BYVAL DWORD, _                      ' __in SCARDCONTEXT
'   BYVAL DWORD, _                      ' __in SCARDHANDLE
'   BYVAL DWORD _                       ' __in PVOID
'   ) AS LONG                           ' BOOL

'typedef void (WINAPI *LPOCNDSCPROC) (IN SCARDCONTEXT, IN SCARDHANDLE, IN PVOID);

'SUB OCNDSCPROC ( _
'   BYVAL DWORD, _                      ' __in SCARDCONTEXT
'   BYVAL DWORD _                       ' __in SCARDHANDLE
'   BYVAL DWORD _                       ' __in PVOID
'   )

'//
'// OPENCARD_SEARCH_CRITERIA: In order to specify a user-extended search,
'// lpfnCheck must not be NULL.  Moreover, the connection to be made to the
'// card before performing the callback must be indicated by either providing
'// lpfnConnect and lpfnDisconnect OR by setting dwShareMode.
'// If both the connection callbacks and dwShareMode are non-NULL, the callbacks
'// will be used.
'//

' // Size = 52 bytes
TYPE OPENCARD_SEARCH_CRITERIAA DWORD
   dwStructSize         AS DWORD        ' DWORD
   lpstrGroupNames      AS ASCIIZ PTR   ' LPSTR
   nMaxGroupNames       AS DWORD        ' DWORD
   rgguidInterfaces     AS GUID PTR     ' LPCGUID
   cguidInterfaces      AS DWORD        ' DWORD
   lpstrCardNames       AS ASCIIZ PTR   ' LPSTR
   nMaxCardNames        AS DWORD        ' DWORD
   lpfnCheck            AS DWORD        ' LPOCNCHKPROC
   lpfnConnect          AS DWORD        ' LPOCNCONNPROCA
   lpfnDisconnect       AS DWORD        ' LPOCNDSCPROC
   pvUserData           AS DWORD        ' LPVOID
   dwShareMode          AS DWORD        ' DWORD
   dwPreferredProtocols AS DWORD        ' DWORD
END TYPE

' // Size = 52 bytes
TYPE OPENCARD_SEARCH_CRITERIAW DWORD
   dwStructSize         AS DWORD          ' DWORD
   lpstrGroupNames      AS WSTRINGZ PTR   ' LPWSTR
   nMaxGroupNames       AS DWORD          ' DWORD
   rgguidInterfaces     AS GUID PTR       ' LPCGUID
   cguidInterfaces      AS DWORD          ' DWORD
   lpstrCardNames       AS WSTRINGZ PTR   ' LPWSTR
   nMaxCardNames        AS DWORD          ' DWORD
   lpfnCheck            AS DWORD          ' LPOCNCHKPROC
   lpfnConnect          AS DWORD          ' LPOCNCONNPROCW
   lpfnDisconnect       AS DWORD          ' LPOCNDSCPROC
   pvUserData           AS DWORD          ' LPVOID
   dwShareMode          AS DWORD          ' DWORD
   dwPreferredProtocols AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO OPENCARD_SEARCH_CRITERIA = OPENCARD_SEARCH_CRITERIAW
#ELSE
   MACRO OPENCARD_SEARCH_CRITERIA = OPENCARD_SEARCH_CRITERIAA
#ENDIF

'//
'// OPENCARDNAME_EX: used by SCardUIDlgSelectCard; replaces obsolete OPENCARDNAME
'//

' // Size = 72 bytes
TYPE OPENCARDNAME_EXA DWORD
   dwStructSize            AS DWORD                          ' DWORD
   hSCardContext           AS DWORD                          ' SCARDCONTEXT
   hwndOwner               AS DWORD                          ' HWND
   dwFlags                 AS DWORD                          ' DWORD
   lpstrTitle              AS ASCIIZ PTR                     ' LPCSTR
   lpstrSearchDesc         AS ASCIIZ PTR                     ' LPCSTR
   hIcon                   AS DWORD                          ' HICON
   pOpenCardSearchCriteria AS OPENCARD_SEARCH_CRITERIA PTR   ' POPENCARD_SEARCH_CRITERIAA
   lpfnConnect             AS DWORD                          ' LPOCNCONNPROCA
   pvUserData              AS DWORD                          ' LPVOID
   dwShareMode             AS DWORD                          ' DWORD
   dwPreferredProtocols    AS DWORD                          ' DWORD
   lpstrRdr                AS ASCIIZ PTR                     ' LPSTR
   nMaxRdr                 AS DWORD                          ' DWORD
   lpstrCard               AS ASCIIZ PTR                     ' LPSTR
   nMaxCard                AS DWORD                          ' DWORD
   dwActiveProtocol        AS DWORD                          ' DWORD
   hCardHandle             AS DWORD                          ' SCARDHANDLE
END TYPE

' // Size = 72 bytes
TYPE OPENCARDNAME_EXW DWORD
   dwStructSize            AS DWORD                           ' DWORD
   hSCardContext           AS DWORD                           ' SCARDCONTEXT
   hwndOwner               AS DWORD                           ' HWND
   dwFlags                 AS DWORD                           ' DWORD
   lpstrTitle              AS WSTRINGZ PTR                    ' LPCWSTR
   lpstrSearchDesc         AS WSTRINGZ PTR                    ' LPCWSTR
   hIcon                   AS DWORD                           ' HICON
   pOpenCardSearchCriteria AS OPENCARD_SEARCH_CRITERIAW PTR   ' POPENCARD_SEARCH_CRITERIAW
   lpfnConnect             AS DWORD                           ' LPOCNCONNPROCW
   pvUserData              AS DWORD                           ' LPVOID
   dwShareMode             AS DWORD                           ' DWORD
   dwPreferredProtocols    AS DWORD                           ' DWORD
   lpstrRdr                AS WSTRINGZ PTR                    ' LPWSTR
   nMaxRdr                 AS DWORD                           ' DWORD
   lpstrCard               AS WSTRINGZ PTR                    ' LPWSTR
   nMaxCard                AS DWORD                           ' DWORD
   dwActiveProtocol        AS DWORD                           ' DWORD
   hCardHandle             AS DWORD                           ' SCARDHANDLE
END TYPE

#IF %DEF(%UNICODE)
   MACRO OPENCARDNAME_EX = OPENCARDNAME_EXW
#ELSE
   MACRO OPENCARDNAME_EX = OPENCARDNAME_EXA
#ENDIF

'//
'// SCardUIDlgSelectCard replaces GetOpenCardName
'//

DECLARE FUNCTION SCardUIDlgSelectCardA IMPORT "WINSCARD.DLL" ALIAS "SCardUIDlgSelectCardA" ( _
   BYREF pDlgStruc AS OPENCARDNAME_EXA _                ' __in LPOPENCARDNAMEA_EX pDlgStruc
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardUIDlgSelectCardW IMPORT "WINSCARD.DLL" ALIAS "SCardUIDlgSelectCardW" ( _
   BYREF pDlgStruc AS OPENCARDNAME_EXW _                ' __in LPOPENCARDNAMEW_EX pDlgStruc
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardUIDlgSelectCard = SCardUIDlgSelectCardW
#ELSE
   MACRO SCardUIDlgSelectCard = SCardUIDlgSelectCardA
#ENDIF

'//
'// "Smart Card Common Dialog" definitions for backwards compatibility
'//  with the Smart Card Base Services SDK version 1.0
'//

' // Size = 92 bytes
TYPE OPENCARDNAMEA DWORD
   dwStructSize         AS DWORD        ' DWORD
   hwndOwner            AS DWORD        ' HWND
   hSCardContext        AS DWORD        ' SCARDCONTEXT
   lpstrGroupNames      AS ASCIIZ PTR   ' LPSTR
   nMaxGroupNames       AS DWORD        ' DWORD
   lpstrCardNames       AS ASCIIZ PTR   ' LPSTR
   nMaxCardNames        AS DWORD        ' DWORD
   rgguidInterfaces     AS GUID PTR     ' LPGUID
   cguidInterfaces      AS DWORD        ' DWORD
   lpstrRdr             AS ASCIIZ PTR   ' LPSTR
   nMaxRdr              AS DWORD        ' DWORD
   lpstrCard            AS ASCIIZ PTR   ' LPSTR
   nMaxCard             AS DWORD        ' DWORD
   lpstrTitle           AS ASCIIZ PTR   ' LPCSTR
   dwFlags              AS DWORD        ' DWORD
   pvUserData           AS DWORD        ' LPVOID
   dwShareMode          AS DWORD        ' DWORD
   dwPreferredProtocols AS DWORD        ' DWORD
   dwActiveProtocol     AS DWORD        ' DWORD
   lpfnConnect          AS DWORD        ' LPOCNCONNPROCA
   lpfnCheck            AS DWORD        ' LPOCNCHKPROC
   lpfnDisconnect       AS DWORD        ' LPOCNDSCPROC
   hCardHandle          AS DWORD        ' SCARDHANDLE
END TYPE

' // Size = 92 bytes
TYPE OPENCARDNAMEW DWORD
   dwStructSize         AS DWORD          ' DWORD
   hwndOwner            AS DWORD          ' HWND
   hSCardContext        AS DWORD          ' SCARDCONTEXT
   lpstrGroupNames      AS WSTRINGZ PTR   ' LPWSTR
   nMaxGroupNames       AS DWORD          ' DWORD
   lpstrCardNames       AS WSTRINGZ PTR   ' LPWSTR
   nMaxCardNames        AS DWORD          ' DWORD
   rgguidInterfaces     AS GUID PTR       ' LPGUID
   cguidInterfaces      AS DWORD          ' DWORD
   lpstrRdr             AS WSTRINGZ PTR   ' LPWSTR
   nMaxRdr              AS DWORD          ' DWORD
   lpstrCard            AS WSTRINGZ PTR   ' LPWSTR
   nMaxCard             AS DWORD          ' DWORD
   lpstrTitle           AS WSTRINGZ PTR   ' LPCWSTR
   dwFlags              AS DWORD          ' DWORD
   pvUserData           AS DWORD          ' LPVOID
   dwShareMode          AS DWORD          ' DWORD
   dwPreferredProtocols AS DWORD          ' DWORD
   dwActiveProtocol     AS DWORD          ' DWORD
   lpfnConnect          AS DWORD          ' LPOCNCONNPROCA
   lpfnCheck            AS DWORD          ' LPOCNCHKPROC
   lpfnDisconnect       AS DWORD          ' LPOCNDSCPROC
   hCardHandle          AS DWORD          ' SCARDHANDLE
END TYPE

#IF %DEF(%UNICODE)
   MACRO OPENCARDNAME = OPENCARDNAMEW
#ELSE
   MACRO OPENCARDNAME = OPENCARDNAMEA
#ENDIF

DECLARE FUNCTION GetOpenCardNameA IMPORT "WINSCARD.DLL" ALIAS "GetOpenCardNameA" ( _
   BYREF pDlgStruc AS OPENCARDNAMEA _                   ' __in LPOPENCARDNAMEA pDlgStruc
 ) AS LONG                                              ' LONG

DECLARE FUNCTION GetOpenCardNameW IMPORT "WINSCARD.DLL" ALIAS "GetOpenCardNameW" ( _
   BYREF pDlgStruc AS OPENCARDNAMEW _                   ' __in LPOPENCARDNAMEW pDlgStruc
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO GetOpenCardName = GetOpenCardNameW
#ELSE
   MACRO GetOpenCardName = GetOpenCardNameA
#ENDIF

DECLARE FUNCTION SCardDlgExtendedError IMPORT "WINSCARD.DLL" ALIAS "SCardDlgExtendedError" ( _
 ) AS LONG                                              ' LONG

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// Smartcard Caching API
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardReadCacheA LIB "WinSCard.dll" ALIAS "SCardReadCacheA" _
    (BYVAL hContext AS DWORD, CardIdentifier AS GUID, _
    BYVAL FreshnessCounter AS DWORD, LookupName AS ASCIIZ, _
    BYVAL pData AS BYTE PTR, DataLen AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardReadCacheA IMPORT "WINSCARD.DLL" ALIAS "SCardReadCacheA" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF CardIdentifier AS GUID _                       ' __in  UUID *CardIdentifier
 , BYVAL FreshnessCounter AS DWORD _                    ' __in  DWORD FreshnessCounter
 , BYREF LookupName AS ASCIIZ _                         ' __in  LPSTR LookupName
 , BYREF Data AS ANY _                                  ' __out PBYTE Data
 , BYREF DataLen AS DWORD _                             ' __out DWORD *DataLen
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SCardReadCacheW LIB "WinSCard.dll" ALIAS "SCardReadCacheW" _
    (BYVAL hContext AS DWORD, CardIdentifier AS GUID, _
    BYVAL FreshnessCounter AS DWORD, LookupName AS WSTRINGZ, _
    BYVAL pData AS BYTE PTR, DataLen AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SCardReadCacheW IMPORT "WINSCARD.DLL" ALIAS "SCardReadCacheW" ( _
   BYVAL hContext AS DWORD _                            ' __in  SCARDCONTEXT hContext
 , BYREF CardIdentifier AS GUID _                       ' __in  UUID *CardIdentifier
 , BYVAL FreshnessCounter AS DWORD _                    ' __in  DWORD FreshnessCounter
 , BYREF LookupName AS WSTRINGZ _                       ' __in  LPWSTR LookupName
 , BYREF Data AS ANY _                                  ' __out PBYTE Data
 , BYREF DataLen AS DWORD _                             ' __out DWORD *DataLen
 ) AS LONG                                              ' LONG
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SCardReadCache = SCardReadCacheW
#ELSE
   MACRO SCardReadCache = SCardReadCacheA
#ENDIF

DECLARE FUNCTION SCardWriteCacheA IMPORT "WINSCARD.DLL" ALIAS "SCardWriteCacheA" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF CardIdentifier AS GUID _                       ' __in UUID *CardIdentifier
 , BYVAL FreshnessCounter AS DWORD _                    ' __in DWORD FreshnessCounter
 , BYREF LookupName AS ASCIIZ _                         ' __in LPSTR LookupName
 , BYVAL Data AS BYTE PTR _                             ' __in PBYTE Data
 , BYVAL DataLen AS DWORD _                             ' __om DWORD DataLen
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SCardWriteCacheW IMPORT "WINSCARD.DLL" ALIAS "SCardWriteCacheW" ( _
   BYVAL hContext AS DWORD _                            ' __in SCARDCONTEXT hContext
 , BYREF CardIdentifier AS GUID _                       ' __in UUID *CardIdentifier
 , BYVAL FreshnessCounter AS DWORD _                    ' __in DWORD FreshnessCounter
 , BYREF LookupName AS WSTRINGZ _                       ' __in LPWSTR LookupName
 , BYVAL Data AS BYTE PTR _                             ' __in PBYTE Data
 , BYVAL DataLen AS DWORD _                             ' __om DWORD DataLen
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SCardWriteCache = SCardWriteCacheW
#ELSE
   MACRO SCardWriteCache = SCardWriteCacheA
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
