' ########################################################################################
' Microsoft Windows
' File: ObjBase.inc
' Contents: Component object model defintions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OBJBASE_INC = 1

#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"

#INCLUDE ONCE "guiddef.inc"

#IF NOT %DEF(%INITGUID)
#INCLUDE ONCE "cguid.inc"
#ENDIF

'/****** Interface Declaration ***********************************************/

'/*
' *      These are macros for declaring interfaces.  They exist so that
' *      a single definition of the interface is simulataneously a proper
' *      declaration of the interface structures (C++ abstract classes)
' *      for both C and C++.
' *
' *      DECLARE_INTERFACE(iface) is used to declare an interface that does
' *      not derive from a base interface.
' *      DECLARE_INTERFACE_(iface, baseiface) is used to declare an interface
' *      that does derive from a base interface.
' *
' *      By default if the source file has a .c extension the C version of
' *      the interface declaratations will be expanded; if it has a .cpp
' *      extension the C++ version will be expanded. if you want to force
' *      the C version expansion even though the source file has a .cpp
' *      extension, then define the macro "CINTERFACE".
' *      eg.     cl -DCINTERFACE file.cpp
' *
' *      Example Interface declaration:
' *
' *          #undef  INTERFACE
' *          #define INTERFACE   IClassFactory
' *
' *          DECLARE_INTERFACE_(IClassFactory, IUnknown)
' *          {
' *              // *** IUnknown methods ***
' *              STDMETHOD(QueryInterface) (THIS_
' *                                        REFIID riid,
' *                                        LPVOID FAR* ppvObj) PURE;
' *              STDMETHOD_(ULONG,AddRef) (THIS) PURE;
' *              STDMETHOD_(ULONG,Release) (THIS) PURE;
' *
' *              // *** IClassFactory methods ***
' *              STDMETHOD(CreateInstance) (THIS_
' *                                        LPUNKNOWN pUnkOuter,
' *                                        REFIID riid,
' *                                        LPVOID FAR* ppvObject) PURE;
' *          };
' *
' *      Example C++ expansion:
' *
' *          struct FAR IClassFactory : public IUnknown
' *          {
' *              virtual HRESULT STDMETHODCALLTYPE QueryInterface(
' *                                                  IID FAR& riid,
' *                                                  LPVOID FAR* ppvObj) = 0;
' *              virtual HRESULT STDMETHODCALLTYPE AddRef(void) = 0;
' *              virtual HRESULT STDMETHODCALLTYPE Release(void) = 0;
' *              virtual HRESULT STDMETHODCALLTYPE CreateInstance(
' *                                              LPUNKNOWN pUnkOuter,
' *                                              IID FAR& riid,
' *                                              LPVOID FAR* ppvObject) = 0;
' *          };
' *
' *          NOTE: Our documentation says '#define interface class' but we use
' *          'struct' instead of 'class' to keep a lot of 'public:' lines
' *          out of the interfaces.  The 'FAR' forces the 'this' pointers to
' *          be far, which is what we need.
' *
' *      Example C expansion:
' *
' *          typedef struct IClassFactory
' *          {
' *              const struct IClassFactoryVtbl FAR* lpVtbl;
' *          } IClassFactory;
' *
' *          typedef struct IClassFactoryVtbl IClassFactoryVtbl;
' *
' *          struct IClassFactoryVtbl
' *          {
' *              HRESULT (STDMETHODCALLTYPE * QueryInterface) (
' *                                                  IClassFactory FAR* This,
' *                                                  IID FAR* riid,
' *                                                  LPVOID FAR* ppvObj) ;
' *              HRESULT (STDMETHODCALLTYPE * AddRef) (IClassFactory FAR* This) ;
' *              HRESULT (STDMETHODCALLTYPE * Release) (IClassFactory FAR* This) ;
' *              HRESULT (STDMETHODCALLTYPE * CreateInstance) (
' *                                                  IClassFactory FAR* This,
' *                                                  LPUNKNOWN pUnkOuter,
' *                                                  IID FAR* riid,
' *                                                  LPVOID FAR* ppvObject);
' *              HRESULT (STDMETHODCALLTYPE * LockServer) (
' *                                                  IClassFactory FAR* This,
' *                                                  BOOL fLock);
' *          };
' */

'/****** Additional basic types **********************************************/

'#include <stdlib.h>

'#define LISet32(li, v) ((li).HighPart = ((LONG) (v)) < 0 ? -1 : 0, (li).LowPart = (v))
'#define ULISet32(li, v) ((li).HighPart = 0, (li).LowPart = (v))

%CLSCTX_INPROC = %CLSCTX_INPROC_SERVER OR %CLSCTX_INPROC_HANDLER

#IF %DEF(%WIN32_DCOM) ' // DCOM
%CLSCTX_ALL    = %CLSCTX_INPROC_SERVER OR %CLSCTX_INPROC_HANDLER OR %CLSCTX_LOCAL_SERVER OR %CLSCTX_REMOTE_SERVER
%CLSCTX_SERVER = %CLSCTX_INPROC_SERVER OR %CLSCTX_LOCAL_SERVER OR %CLSCTX_REMOTE_SERVER
#ELSE
%CLSCTX_ALL    = %CLSCTX_INPROC_SERVER OR %CLSCTX_INPROC_HANDLER OR %CLSCTX_LOCAL_SERVER
%CLSCTX_SERVER = %CLSCTX_INPROC_SERVER OR %CLSCTX_LOCAL_SERVER
#ENDIF   ' // DCOM

'// class registration flags; passed to CoRegisterClassObject
' REGCLS enum
%REGCLS_SINGLEUSE      = 0   ' // class object only generates one instance
%REGCLS_MULTIPLEUSE    = 1   ' // same class object genereates multiple inst.
                             ' // and local automatically goes into inproc tbl.
%REGCLS_MULTI_SEPARATE = 2   ' // multiple use, but separate control over each context.
%REGCLS_SUSPENDED      = 4   ' // register is as suspended, will be activated
                             ' // when app calls CoResumeClassObjects
%REGCLS_SURROGATE      = 8   ' // must be used when a surrogate process
                             ' // is registering a class object that will be
                             ' // loaded in the surrogate

'// interface marshaling definitions
%MARSHALINTERFACE_MIN = 500     ' // minimum number of bytes for interface marshl


'//
'// Common typedefs for paramaters used in Storage API's, gleamed from storage.h
'// Also contains Storage error codes, which should be moved into the storage
'// idl files.
'//


%CWCSTORAGENAME = 32

'/* Storage instantiation modes */
%STGM_DIRECT           = &H00000000???
%STGM_TRANSACTED       = &H00010000???
%STGM_DIRECT_SWMR      = &H00400000???
%STGM_SIMPLE           = &H08000000???

%STGM_READ             = &H00000000???
%STGM_WRITE            = &H00000001???
%STGM_READWRITE        = &H00000002???

%STGM_SHARE_DENY_NONE  = &H00000040???
%STGM_SHARE_DENY_READ  = &H00000030???
%STGM_SHARE_DENY_WRITE = &H00000020???
%STGM_SHARE_EXCLUSIVE  = &H00000010???

%STGM_PRIORITY         = &H00040000???
%STGM_DELETEONRELEASE  = &H04000000???
'#if (WINVER >= 400)
%STGM_NOSCRATCH        = &H00100000???
'#endif /* WINVER */

%STGM_CREATE           = &H00001000???
%STGM_CONVERT          = &H00020000???
%STGM_FAILIFTHERE      = &H00000000???

%STGM_NOSNAPSHOT       = &H00200000???
'#if (_WIN32_WINNT >= 0x0500)
%STGM_DIRECT_SWMR      = &H00400000???
'#endif

'/*  flags for internet asyncronous and layout docfile */
%ASYNC_MODE_COMPATIBILITY    = &H00000001???
%ASYNC_MODE_DEFAULT          = &H00000000???

%STGTY_REPEAT                = &H00000100???
%STG_TOEND                   = &HFFFFFFFF???

%STG_LAYOUT_SEQUENTIAL       = &H00000000???
%STG_LAYOUT_INTERLEAVED      = &H00000001???

%STGFMT_STORAGE              = 0
%STGFMT_NATIVE               = 1
%STGFMT_FILE                 = 3
%STGFMT_ANY                  = 4
%STGFMT_DOCFILE              = 5

'// This is a legacy define to allow old component to builds
%STGFMT_DOCUMENT             = 0

'// COM initialization flags; passed to CoInitialize.
' COINIT enum
%COINIT_APARTMENTTHREADED = &H2???
#IF %DEF(%WIN32_DCOM) ' // DCOM
'  // These constants are only valid on Windows NT 4.0
%COINIT_MULTITHREADED     = &H0???   ' // OLE calls objects on any thread.
%COINIT_DISABLE_OLE1DDE   = &H4???   ' // Don't use DDE for Ole1 support.
%COINIT_SPEED_OVER_MEMORY = &H8???   ' // Trade memory for speed.
#ENDIF   ' // DCOM


'/****** STD Object API Prototypes *****************************************/

DECLARE FUNCTION CoBuildVersion IMPORT "OLE32.DLL" ALIAS "CoBuildVersion" ( _
 ) AS DWORD                                             ' DWORD

'/* init/uninit */

DECLARE FUNCTION CoInitialize IMPORT "OLE32.DLL" ALIAS "CoInitialize" ( _
   OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE SUB CoUninitialize IMPORT "OLE32.DLL" ALIAS "CoUninitialize" ()   ' void

DECLARE FUNCTION CoGetMalloc IMPORT "OLE32.DLL" ALIAS "CoGetMalloc" ( _
   BYVAL dwMemContext AS DWORD _                        ' __in DWORD dwMemContext
 , BYREF ppMalloc AS IMalloc _                          ' __out LPMALLOC * ppMalloc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetCurrentProcess IMPORT "OLE32.DLL" ALIAS "CoGetCurrentProcess" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CoRegisterMallocSpy IMPORT "OLE32.DLL" ALIAS "CoRegisterMallocSpy" ( _
   BYVAL pMallocSpy AS IMallocSpy _                     ' __in LPMALLOCSPY pMallocSpy
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRevokeMallocSpy IMPORT "OLE32.DLL" ALIAS "CoRevokeMallocSpy" ( _
 ) AS LONG                                              ' HRESULT

' This function is obsolete. Refer to CoGetMalloc.
'WINOLEAPI  CoCreateStandardMalloc(IN DWORD memctx, OUT IMalloc FAR* FAR* ppMalloc);

'#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
DECLARE FUNCTION CoInitializeEx IMPORT "OLE32.DLL" ALIAS "CoInitializeEx" ( _
   BYVAL pvReserved AS DWORD _                          ' __in void * pvReserved
 , BYVAL dwCoInit AS DWORD _                            ' __in DWORD dwCoInit
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetCallerTID IMPORT "OLE32.DLL" ALIAS "CoGetCallerTID" ( _
   BYREF lpdwTID AS DWORD _                             ' __out LPDWORD lpdwTID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetCurrentLogicalThreadId IMPORT "OLE32.DLL" ALIAS "CoGetCurrentLogicalThreadId" ( _
   BYREF pguid AS GUID _                                ' __out GUID *pguid
 ) AS LONG                                              ' HRESULT
'#endif // DCOM

'#if (_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION CoRegisterInitializeSpy IMPORT "OLE32.DLL" ALIAS "CoRegisterInitializeSpy" ( _
   BYVAL lpInitializeSpy AS IInitializeSpy _            ' __in LPINITIALIZESPY lpInitializeSpy
 , BYVAL pUliCookie AS QUAD _                           ' __in ULARGE_INTEGER * pUliCookie
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRevokeInitializeSpy IMPORT "OLE32.DLL" ALIAS "CoRevokeInitializeSpy" ( _
   BYVAL uliCookie AS QUAD _                            ' __in ULARGE_INTEGER uliCookie
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetContextToken IMPORT "OLE32.DLL" ALIAS "CoGetContextToken" ( _
   BYREF pToken AS ANY _                                ' __out ULONG_PTR * pToken
 ) AS LONG                                              ' HRESULT

'// COM System Security Descriptors (used when the corresponding registry
'// entries are absent)
' COMSD enum
%SD_LAUNCHPERMISSIONS  = 0     ' // Machine wide launch permissions
%SD_ACCESSPERMISSIONS  = 1     ' // Machine wide acesss permissions
%SD_LAUNCHRESTRICTIONS = 2     ' // Machine wide launch limits
%SD_ACCESSRESTRICTIONS = 3     ' // Machine wide access limits

DECLARE FUNCTION CoGetSystemSecurityPermissions IMPORT "OLE32.DLL" ALIAS "CoGetSystemSecurityPermissions" ( _
   BYVAL comSDType AS LONG _                            ' COMSD comSDType
 , BYREF ppSD AS SECURITY_DESCRIPTOR _                  ' PSECURITY_DESCRIPTOR *ppSD
 ) AS LONG                                              ' HRESULT

'#endif

'// definition for Win7 new APIs
'#if (_WIN32_WINNT >= _NT_TARGET_VERSION_WIN7)

DECLARE FUNCTION CoGetApartmentType IMPORT "OLE32.DLL" ALIAS "CoGetApartmentType" ( _
   BYREF pAptType AS LONG _                             ' __out APTTYPE * pAptType
 , BYREF pAptQualifier AS LONG _                        ' __out APTTYPEQUALIFIER * pAptQualifier
 ) AS LONG                                              ' HRESULT

'#endif

'#if DBG == 1
'WINOLEAPI_(ULONG) DebugCoGetRpcFault( void );
'WINOLEAPI_(void) DebugCoSetRpcFault( ULONG );
'#endif

'#if (_WIN32_WINNT >= 0x0500)

' // Size = 60 bytes
TYPE SOleTlsDataPublic DWORD
   pvReserved0(1) AS DWORD PTR   ' void* [2]
   dwReserved0(2) AS DWORD       ' DWORD [3]
   pvReserved1(0) AS DWORD PTR   ' void* [1]
   dwReserved1(2) AS DWORD       ' DWORD [3]
   pvReserved2(3) AS DWORD PTR   ' void* [4]
   dwReserved2(0) AS DWORD       ' DWORD [1]
   pCurrentCtx    AS DWORD PTR   ' void*
END TYPE

MACRO SOleTlsData = SOleTlsDataPublic

'#endif

'/* COM+ APIs */

DECLARE FUNCTION CoGetObjectContext IMPORT "OLE32.DLL" ALIAS "CoGetObjectContext" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID ** ppv
 ) AS LONG                                              ' HRESULT

'/* register/revoke/get class objects */

DECLARE FUNCTION CoGetClassObject IMPORT "OLE32.DLL" ALIAS "CoGetClassObject" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL dwClsContext AS DWORD _                        ' __in DWORD dwClsContext
 , BYREF pServerInfo AS COSERVERINFO _                  ' __in COSERVERINFO * pServerInfo
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID * ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRegisterClassObject IMPORT "OLE32.DLL" ALIAS "CoRegisterClassObject" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwClsContext AS DWORD _                        ' __in DWORD dwClsContext
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpdwRegister AS DWORD _                        ' __out LPDWORD  lpdwRegister
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRevokeClassObject IMPORT "OLE32.DLL" ALIAS "CoRevokeClassObject" ( _
   BYVAL dwRegister AS DWORD _                          ' __in DWORD dwRegister
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoResumeClassObjects IMPORT "OLE32.DLL" ALIAS "CoResumeClassObjects" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoSuspendClassObjects IMPORT "OLE32.DLL" ALIAS "CoSuspendClassObjects" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoAddRefServerProcess IMPORT "OLE32.DLL" ALIAS "CoAddRefServerProcess" ( _
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION CoReleaseServerProcess IMPORT "OLE32.DLL" ALIAS "CoReleaseServerProcess" ( _
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION CoGetPSClsid IMPORT "OLE32.DLL" ALIAS "CoGetPSClsid" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF pclsid AS GUID _                               ' __out CLSID * pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRegisterPSClsid IMPORT "OLE32.DLL" ALIAS "CoRegisterPSClsid" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 ) AS LONG                                              ' HRESULT

'// Registering surrogate processes
DECLARE FUNCTION CoRegisterSurrogate IMPORT "OLE32.DLL" ALIAS "CoRegisterSurrogate" ( _
   BYVAL pSurrogate AS ISurrogate _                     ' __in ISurrogate * pSurrogate
 ) AS LONG                                              ' HRESULT

'/* marshaling interface pointers */

DECLARE FUNCTION CoGetMarshalSizeMax IMPORT "OLE32.DLL" ALIAS "CoGetMarshalSizeMax" ( _
   BYREF pulSize AS DWORD _                             ' __out ULONG * pulSize
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwDestContext AS DWORD _                       ' __in DWORD dwDestContext
 , BYVAL pvDestContext AS DWORD _                       ' __in LPVOID pvDestContext
 , BYVAL mshlflags AS DWORD _                           ' __in DWORD mshlflags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoMarshalInterface IMPORT "OLE32.DLL" ALIAS "CoMarshalInterface" ( _
   BYVAL pStm AS IStream _                              ' __in IStream * pStm
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwDestContext AS DWORD _                       ' __in DWORD dwDestContext
 , BYVAL pvDestContext AS DWORD _                       ' __in void * pvDestContext
 , BYVAL mshlflags AS DWORD _                           ' __in DWORD mshlflags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoUnmarshalInterface IMPORT "OLE32.DLL" ALIAS "CoUnmarshalInterface" ( _
   BYVAL pStm AS IStream _                              ' __in IStream * pStm
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void ** ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoMarshalHresult IMPORT "OLE32.DLL" ALIAS "CoMarshalHresult" ( _
   BYVAL pStm AS IStream _                              ' __in IStream * pStm
 , BYVAL hresult AS LONG _                              ' __in HRESULT hresult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoUnmarshalHresult IMPORT "OLE32.DLL" ALIAS "CoUnmarshalHresult" ( _
   BYVAL pStm AS IStream _                              ' __in LPSTREAM pStm
 , BYREF phresult AS DWORD _                            ' __out HRESULT * phresult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoReleaseMarshalData IMPORT "OLE32.DLL" ALIAS "CoReleaseMarshalData" ( _
   BYVAL pStm AS IStream _                              ' __in IStream * pStm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoDisconnectObject IMPORT "OLE32.DLL" ALIAS "CoDisconnectObject" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoLockObjectExternal IMPORT "OLE32.DLL" ALIAS "CoLockObjectExternal" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL fLock AS LONG _                                ' __in BOOL fLock
 , BYVAL fLastUnlockReleases AS LONG _                  ' __in BOOL fLastUnlockReleases
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetStandardMarshal IMPORT "OLE32.DLL" ALIAS "CoGetStandardMarshal" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL dwDestContext AS DWORD _                       ' __in DWORD dwDestContext
 , BYVAL pvDestContext AS DWORD _                       ' __in LPVOID pvDestContext
 , BYVAL mshlflags AS DWORD _                           ' __in DWORD mshlflags
 , BYREF ppMarshal AS IMarshal _                        ' __out LPMARSHAL * ppMarshal
 ) AS LONG                                              ' HRESULT


DECLARE FUNCTION CoGetStdMarshalEx IMPORT "OLE32.DLL" ALIAS "CoGetStdMarshalEx" ( _
   BYVAL pUnkOuter AS IUnknown _                        ' __in IUnknown * pUnkOuter
 , BYVAL dwSMEXFlags AS DWORD _                         ' __in DWORD dwSMEXFlags
 , BYREF ppUnkInner AS IUnknown _                       ' __out IUnknown ** ppUnkInner
 ) AS LONG                                              ' HRESULT

'/* flags for CoGetStdMarshalEx */
%SMEXF_SERVER     = &H01???       ' // server side aggregated std marshaler
%SMEXF_HANDLER    = &H02???       ' // client side (handler) agg std marshaler

DECLARE FUNCTION CoIsHandlerConnected IMPORT "OLE32.DLL" ALIAS "CoIsHandlerConnected" ( _
   BYVAL pUnk AS IUnknown _                             ' __in LPUNKNOWN pUnk
 ) AS LONG                                              ' BOOL

'// Apartment model inter-thread interface passing helpers
DECLARE FUNCTION CoMarshalInterThreadInterfaceInStream IMPORT "OLE32.DLL" ALIAS "CoMarshalInterThreadInterfaceInStream" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL pUnk AS IUnknown _                             ' __in LPUNKNOWN pUnk
 , BYREF ppStm AS IStream _                             ' __out LPSTREAM * ppStm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetInterfaceAndReleaseStream IMPORT "OLE32.DLL" ALIAS "CoGetInterfaceAndReleaseStream" ( _
   BYVAL pStm AS IStream _                              ' __in LPSTREAM pStm
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID * ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoCreateFreeThreadedMarshaler IMPORT "OLE32.DLL" ALIAS "CoCreateFreeThreadedMarshaler" ( _
   BYVAL punkOuter AS IUnknown _                        ' __in LPUNKNOWN punkOuter
 , BYREF ppunkMarshaler AS IUnknown _                   ' __out LPUNKNOWN * ppunkMarshaler
 ) AS LONG                                              ' HRESULT

'/* dll loading helpers; keeps track of ref counts and unloads all on exit */

DECLARE FUNCTION CoLoadLibrary IMPORT "OLE32.DLL" ALIAS "CoLoadLibrary" ( _
   BYREF lpszLibName AS WSTRINGZ _                      ' __in LPOLESTR lpszLibName
 , BYVAL bAutoFree AS LONG _                            ' __in BOOL bAutoFree
 ) AS DWORD                                             ' HINSTANCE

DECLARE SUB CoFreeLibrary IMPORT "OLE32.DLL" ALIAS "CoFreeLibrary" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 )                                                      ' void

DECLARE SUB CoFreeAllLibraries IMPORT "OLE32.DLL" ALIAS "CoFreeAllLibraries" ()   ' void

DECLARE SUB CoFreeUnusedLibraries IMPORT "OLE32.DLL" ALIAS "CoFreeUnusedLibraries" ()   ' void

'#if  (_WIN32_WINNT >= 0x0501)
DECLARE SUB CoFreeUnusedLibrariesEx IMPORT "OLE32.DLL" ALIAS "CoFreeUnusedLibraries" ( _
   BYVAL dwUnloadDelay AS DWORD _                       ' __in DWORD dwUnloadDelay
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 )                                                      ' void
'#endif

'#if (_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
DECLARE FUNCTION CoDisconnectContext IMPORT "OLE32.DLL" ALIAS "CoDisconnectContext" ( _
   BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 ) AS DWORD                                             ' HINSTANCE
#ENDIF

'#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM

'/* Call Security. */

DECLARE FUNCTION CoInitializeSecurity IMPORT "OLE32.DLL" ALIAS "CoInitializeSecurity" ( _
   BYREF pVoid AS SECURITY_DESCRIPTOR _                 ' __in PSECURITY_DESCRIPTOR pVoid
 , BYVAL cAuthSvc AS LONG _                             ' __in LONG cAuthSvc
 , BYREF asAuthSvc AS SOLE_AUTHENTICATION_SERVICE _     ' __in SOLE_AUTHENTICATION_SERVICE * asAuthSvc [array]
 , BYVAL pReserved1 AS DWORD _                          ' __in void * pReserved1
 , BYVAL dwAuthnLevel AS DWORD _                        ' __in DWORD dwAuthnLevel
 , BYVAL dwImpLevel AS DWORD _                          ' __in DWORD dwImpLevel
 , BYREF pAuthList AS SOLE_AUTHENTICATION_LIST _        ' __in SOLE_AUTHENTICATION_LIST * pAuthList [array]
 , BYVAL dwCapabilities AS DWORD _                      ' __in DWORD dwCapabilities
 , BYVAL pReserved3 AS DWORD _                          ' __in void * pReserved3
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetCallContext IMPORT "OLE32.DLL" ALIAS "CoGetCallContext" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppInterface AS ANY _                           ' __out void ** ppInterface
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoQueryProxyBlanket IMPORT "OLE32.DLL" ALIAS "CoQueryProxyBlanket" ( _
   BYVAL pProxy AS IUnknown _                           ' __in IUnknown * pProxy
 , BYREF pAuthnSvc AS DWORD _                           ' __out DWORD * pAuthnSvc
 , BYREF pAuthzSvc AS DWORD _                           ' __out DWORD * pAuthzSvc
 , BYREF pServerPrincName AS DWORD _                    ' __out OLECHAR ** pServerPrincName
 , BYREF pAuthnLevel AS DWORD _                         ' __out DWORD * pAuthnLevel
 , BYREF pImpLevel AS DWORD _                           ' __out DWORD * pImpLevel
 , BYREF ppAuthInfo AS DWORD _                          ' __out RPC_AUTH_IDENTITY_HANDLE * ppAuthInfo
 , BYREF pCapabilities AS DWORD _                       ' __out DWORD * pCapabilities
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoSetProxyBlanket IMPORT "OLE32.DLL" ALIAS "CoSetProxyBlanket" ( _
   BYVAL pProxy AS IUnknown _                           ' __in IUnknown * pProxy
 , BYVAL dwAuthnSvc AS DWORD _                          ' __in DWORD dwAuthnSvc
 , BYVAL dwAuthzSvc AS DWORD _                          ' __in DWORD dwAuthzSvc
 , BYVAL pServerPrincName AS DWORD _                    ' __in WCHAR * pServerPrincName [must be DWORD, not WSTRINGZ]
 , BYVAL dwAuthnLevel AS DWORD _                        ' __in DWORD dwAuthnLevel
 , BYVAL dwImpLevel AS DWORD _                          ' __in DWORD dwImpLevel
 , BYVAL pAuthInfo AS DWORD _                           ' __in RPC_AUTH_IDENTITY_HANDLE pAuthInfo
 , BYVAL dwCapabilities AS DWORD _                      ' __in DWORD dwCapabilities
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoCopyProxy IMPORT "OLE32.DLL" ALIAS "CoCopyProxy" ( _
   BYVAL pProxy AS IUnknown _                           ' __in IUnknown * pProxy
 , BYREF ppCopy AS IUnknown _                           ' __out IUnknown ** ppCopy
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoQueryClientBlanket IMPORT "OLE32.DLL" ALIAS "CoQueryClientBlanket" ( _
   BYREF pAuthnSvc AS DWORD _                           ' __out DWORD * pAuthnSvc
 , BYREF pAuthzSvc AS DWORD _                           ' __out DWORD * pAuthzSvc
 , BYREF pServerPrincName AS DWORD _                    ' __out OLECHAR ** pServerPrincName
 , BYREF pAuthnLevel AS DWORD _                         ' __out DWORD * pAuthnLevel
 , BYREF pImpLevel AS DWORD _                           ' __out DWORD * pImpLevel
 , BYREF pPrivs AS DWORD _                              ' __out RPC_AUTHZ_HANDLE * pPrivs
 , BYREF pCapabilities AS DWORD _                       ' __out DWORD * pCapabilities
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoImpersonateClient IMPORT "OLE32.DLL" ALIAS "CoImpersonateClient" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRevertToSelf IMPORT "OLE32.DLL" ALIAS "CoRevertToSelf" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoQueryAuthenticationServices IMPORT "OLE32.DLL" ALIAS "CoQueryAuthenticationServices" ( _
   BYREF pcAuthSvc AS DWORD _                           ' __in DWORD * pcAuthSvc
 , BYREF asAuthSvc AS DWORD _                           ' __out SOLE_AUTHENTICATION_SERVICE ** asAuthSvc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoSwitchCallContext IMPORT "OLE32.DLL" ALIAS "CoSwitchCallContext" ( _
   BYVAL pNewObject AS IUnknown _                       ' __in IUnknown * pNewObject
 , BYREF ppOldObject AS IUnknown _                      ' __out IUnknown ** ppOldObject
 ) AS LONG                                              ' HRESULT

%COM_RIGHTS_EXECUTE         = 1
%COM_RIGHTS_EXECUTE_LOCAL   = 2
%COM_RIGHTS_EXECUTE_REMOTE  = 4
%COM_RIGHTS_ACTIVATE_LOCAL  = 8
%COM_RIGHTS_ACTIVATE_REMOTE = 16

'#endif // DCOM

'/* helper for creating instances */

DECLARE FUNCTION CoCreateInstance IMPORT "OLE32.DLL" ALIAS "CoCreateInstance" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL pUnkOuter AS IUnknown _                        ' __in LPUNKNOWN pUnkOuter
 , BYVAL dwClsContext AS DWORD _                        ' __in DWORD dwClsContext
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID * ppv
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM

DECLARE FUNCTION CoGetInstanceFromFile IMPORT "OLE32.DLL" ALIAS "CoGetInstanceFromFile" ( _
   BYREF pServerInfo AS COSERVERINFO _                  ' __in COSERVERINFO * pServerInfo
 , BYREF pclsid AS GUID _                               ' __in CLSID * pclsid
 , BYVAL punkOuter AS IUnknown _                        ' __in IUnknown * punkOuter
 , BYVAL dwClsCtx AS DWORD _                            ' __in DWORD dwClsCtx
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYREF szName AS WSTRINGZ _                           ' __in OLECHAR * szName
 , BYVAL cmq AS DWORD _                                 ' __in ULONG cmq
 , BYREF rgmqResults AS MULTI_QI _                      ' __in MULTI_QI * rgmqResults [array]
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetInstanceFromIStorage IMPORT "OLE32.DLL" ALIAS "CoGetInstanceFromIStorage" ( _
   BYREF pServerInfo AS COSERVERINFO _                  ' __in COSERVERINFO * pServerInfo
 , BYREF pclsid AS GUID _                               ' __in CLSID * pclsid
 , BYVAL punkOuter AS IUnknown _                        ' __in IUnknown * punkOuter
 , BYVAL dwClsCtx AS DWORD _                            ' __in DWORD dwClsCtx
 , BYVAL pstg AS IStorage _                             ' __in IStorage * pstg
 , BYVAL cmq AS DWORD _                                 ' __in ULONG cmq
 , BYREF rgmqResults AS MULTI_QI _                      ' __in MULTI_QI * rgmqResults
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoCreateInstanceEx IMPORT "OLE32.DLL" ALIAS "CoCreateInstanceEx" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL punkOuter AS IUnknown _                        ' __in IUnknown * punkOuter
 , BYVAL dwClsCtx AS DWORD _                            ' __in DWORD dwClsCtx
 , BYREF pServerInfo AS COSERVERINFO _                  ' __in COSERVERINFO * pServerInfo
 , BYVAL cmq AS LONG _                                  ' __in ULONG cmq
 , BYREF pResults AS MULTI_QI _                         ' __in MULTI_QI * pResults [array]
 ) AS LONG                                              ' HRESULT

'#endif // DCOM

'/* Call related APIs */
'#if (_WIN32_WINNT >= 0x0500 ) || defined(_WIN32_DCOM) // DCOM

DECLARE FUNCTION CoGetCancelObject IMPORT "OLE32.DLL" ALIAS "CoGetCancelObject" ( _
   BYVAL dwThreadID AS DWORD _                          ' __in DWORD dwThreadID
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppUnk AS ANY _                                 ' __out void ** ppUnk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoSetCancelObject IMPORT "OLE32.DLL" ALIAS "CoSetCancelObject" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoCancelCall IMPORT "OLE32.DLL" ALIAS "CoCancelCall" ( _
   BYVAL dwThreadID AS DWORD _                          ' __in DWORD dwThreadID
 , BYVAL ulTimeout AS DWORD _                           ' __in ULONG ulTimeout
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoTestCancel IMPORT "OLE32.DLL" ALIAS "CoTestCancel" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoEnableCallCancellation IMPORT "OLE32.DLL" ALIAS "CoEnableCallCancellation" ( _
   BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoDisableCallCancellation IMPORT "OLE32.DLL" ALIAS "CoDisableCallCancellation" ( _
   BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoAllowSetForegroundWindow IMPORT "OLE32.DLL" ALIAS "CoAllowSetForegroundWindow" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DcomChannelSetHResult IMPORT "OLE32.DLL" ALIAS "DcomChannelSetHResult" ( _
   BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 , BYVAL pulReserved AS DWORD _                         ' __in ULONG* pulReserved
 , BYVAL appsHR AS LONG _                               ' __in HRESULT appsHR
 ) AS LONG                                              ' HRESULT

'#endif

'/* other helpers */

DECLARE FUNCTION StringFromCLSID IMPORT "OLE32.DLL" ALIAS "StringFromCLSID" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF ppsz AS DWORD _                                ' __out LPOLESTR * ppsz
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CLSIDFromString IMPORT "OLE32.DLL" ALIAS "CLSIDFromString" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCOLESTR lpsz
 , BYREF pclsid AS GUID _                               ' __out LPCLSID pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringFromIID IMPORT "OLE32.DLL" ALIAS "StringFromIID" ( _
   BYREF rclsid AS GUID _                               ' __in REFIID rclsid
 , BYREF lplpsz AS DWORD _                              ' __out LPOLESTR * lplpsz
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IIDFromString IMPORT "OLE32.DLL" ALIAS "IIDFromString" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCOLESTR lpsz
 , BYREF lpiid AS GUID _                                ' __out LPIID lpiid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoIsOle1Class IMPORT "OLE32.DLL" ALIAS "CoIsOle1Class" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ProgIDFromCLSID IMPORT "OLE32.DLL" ALIAS "ProgIDFromCLSID" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYREF lplpszProgID AS DWORD _                        ' __out LPOLESTR * lplpszProgID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CLSIDFromProgID IMPORT "OLE32.DLL" ALIAS "CLSIDFromProgID" ( _
   BYREF lpszProgID AS WSTRINGZ _                       ' __in LPCOLESTR lpszProgID
 , BYREF pclsid AS GUID _                               ' __out LPCLSID pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CLSIDFromProgIDEx IMPORT "OLE32.DLL" ALIAS "CLSIDFromProgIDEx" ( _
   BYREF lpszProgID AS WSTRINGZ _                       ' __in LPCOLESTR lpszProgID
 , BYREF pclsid AS GUID _                               ' __out LPCLSID pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringFromGUID2 IMPORT "OLE32.DLL" ALIAS "StringFromGUID2" ( _
   BYREF rguid AS GUID _                                ' __in REFGUID rguid
 , BYREF lpsz AS WSTRINGZ _                             ' __out LPOLESTR lpsz
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS LONG                                              ' int

DECLARE FUNCTION CoCreateGuid IMPORT "OLE32.DLL" ALIAS "CoCreateGuid" ( _
   BYREF pguid AS GUID _                                ' __out GUID * pguid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoFileTimeToDosDateTime IMPORT "OLE32.DLL" ALIAS "CoFileTimeToDosDateTime" ( _
   BYREF lpFileTime AS FILETIME _                       ' __in FILETIME * lpFileTime
 , BYREF lpDosDate AS WORD _                            ' __out LPWORD lpDosDate
 , BYREF lpDosTime AS WORD _                            ' __out LPWORD lpDosTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CoDosDateTimeToFileTime IMPORT "OLE32.DLL" ALIAS "CoDosDateTimeToFileTime" ( _
   BYVAL nDosDate AS WORD _                             ' __in WORD nDosDate
 , BYVAL nDosTime AS WORD _                             ' __in WORD nDosTime
 , BYREF lpFileTime AS FILETIME _                       ' __out FILETIME * lpFileTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CoFileTimeNow IMPORT "OLE32.DLL" ALIAS "CoFileTimeNow" ( _
   BYREF lpFileTime AS FILETIME _                       ' __out FILETIME * lpFileTime
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoRegisterMessageFilter IMPORT "OLE32.DLL" ALIAS "CoRegisterMessageFilter" ( _
   BYVAL lpMessageFilter AS IMessageFilter _            ' __in LPMESSAGEFILTER lpMessageFilter
 , BYREF lplpMessageFilter AS IMessageFilter _          ' __out LPMESSAGEFILTER * lplpMessageFilter
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
DECLARE FUNCTION CoRegisterChannelHook IMPORT "OLE32.DLL" ALIAS "CoRegisterChannelHook" ( _
   BYREF ExtensionUuid AS GUID _                        ' __in REFGUID ExtensionUuid
 , BYVAL pChannelHook AS IUnknown _                     ' __in IChannelHook *pChannelHook
 ) AS LONG                                              ' HRESULT
'#endif // DCOM


'#IF %DEF(%WIN32_DCOM)  ' // DCOM

'#if (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
'/* Synchronization API */

DECLARE FUNCTION CoWaitForMultipleHandles IMPORT "OLE32.DLL" ALIAS "CoWaitForMultipleHandles" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL cHandles AS DWORD _                            ' __in ULONG cHandles
 , BYVAL pHandles AS DWORD _                            ' __in LPHANDLE pHandles
 , BYREF lpdwindex AS  DWORD _                          ' __out LPDWORD lpdwindex
 ) AS LONG                                              ' HRESULT

'/* Flags for Synchronization API and Classes */

' enum COWAIT_FLAGS
%COWAIT_WAITALL        = 1
%COWAIT_ALERTABLE      = 2
%COWAIT_INPUTAVAILABLE = 4

'#endif // DCOM
'#ENDIF  ' // DCOM

'/* for flushing OLESCM remote binding handles */

'#if  (_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION CoInvalidateRemoteMachineBindings IMPORT "OLE32.DLL" ALIAS "CoInvalidateRemoteMachineBindings" ( _
   BYREF pszMachineName AS WSTRINGZ _                   ' __in LPOLESTR pszMachineName
 ) AS LONG                                              ' HRESULT
'#endif

'/* TreatAs APIS */

DECLARE FUNCTION CoGetTreatAsClass IMPORT "OLE32.DLL" ALIAS "CoGetTreatAsClass" ( _
   BYREF clsidOld AS GUID _                             ' __in REFCLSID clsidOld
 , BYREF pclsidNew AS GUID _                            ' __out LPCLSID pclsidNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoTreatAsClass IMPORT "OLE32.DLL" ALIAS "CoTreatAsClass" ( _
   BYREF clsidOld AS GUID _                             ' __in REFCLSID clsidOld
 , BYREF clsidNew AS GUID _                             ' __out REFCLSID clsidNew
 ) AS LONG                                              ' HRESULT


'/* the server dlls must define their DllGetClassObject and DllCanUnloadNow
' * to match these; the typedefs are located here to ensure all are changed at
' * the same time.
' */

'typedef HRESULT (STDAPICALLTYPE * LPFNGETCLASSOBJECT) (REFCLSID, REFIID, LPVOID *);

'typedef HRESULT (STDAPICALLTYPE * LPFNCANUNLOADNOW)(void);

'STDAPI  DllGetClassObject(IN REFCLSID rclsid, IN REFIID riid, OUT LPVOID FAR* ppv);
DECLARE FUNCTION DllGetClassObject (BYREF rclsid AS GUID, BYREF riid AS GUID, BYREF ppv AS ANY) AS LONG

'STDAPI  DllCanUnloadNow(void);
DECLARE FUNCTION DllCanUnloadNow () AS LONG


'/****** Default Memory Allocation ******************************************/
DECLARE FUNCTION CoTaskMemAlloc IMPORT "OLE32.DLL" ALIAS "CoTaskMemAlloc" ( _
   BYVAL cb AS DWORD _                                  ' __in ULONG cb
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION CoTaskMemRealloc IMPORT "OLE32.DLL" ALIAS "CoTaskMemRealloc" ( _
   BYVAL pv AS DWORD _                                  ' __in LPVOID pv
 , BYVAL cb AS DWORD _                                  ' __in ULONG cb
 ) AS DWORD                                             ' LPVOID

DECLARE SUB CoTaskMemFree IMPORT "OLE32.DLL" ALIAS "CoTaskMemFree" ( _
   BYVAL pv AS DWORD _                                  ' __in void * pv
 )                                                      ' void

'/****** DV APIs ***********************************************************/

'/* This function is declared in objbase.h and ole2.h */
DECLARE FUNCTION CreateDataAdviseHolder IMPORT "OLE32.DLL" ALIAS "CreateDataAdviseHolder" ( _
   BYREF ppDAHolder AS IDataAdviseHolder _              ' __out IDataAdviseHolder **ppDAHolder
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateDataCache IMPORT "OLE32.DLL" ALIAS "CreateDataCache" ( _
   BYVAL pUnkOuter AS IUnknown _                        ' __in LPUNKNOWN pUnkOuter
 , BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out LPVOID FAR *ppvObj
 ) AS LONG                                              ' HRESULT


'/****** Storage API Prototypes ********************************************/


DECLARE FUNCTION StgCreateDocFile IMPORT "OLE32.DLL" ALIAS "StgCreateDocfile" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in const WCHAR* pwcsName
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF ppstgOpen AS IStorage _                        ' __out IStorage** ppstgOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgCreateDocfileOnILockBytes IMPORT "OLE32.DLL" ALIAS "StgCreateDocfileOnILockBytes" ( _
   BYVAL plkbyt AS ILockBytes _                         ' __in ILockBytes* plkbyt
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF ppstgOpen AS IStorage _                        ' __out IStorage** ppstgOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgOpenStorage IMPORT "OLE32.DLL" ALIAS "StgOpenStorage" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in const WCHAR* pwcsName
 , BYVAL pstgPriority AS IStorage _                     ' __in IStorage* pstgPriority
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL snbExclude AS DWORD _                          ' __in SNB snbExclude
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF ppstgOpen AS IStorage _                        ' __out IStorage** ppstgOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgOpenStorageOnILockBytes IMPORT "OLE32.DLL" ALIAS "StgOpenStorageOnILockBytes" ( _
   BYVAL plkbyt AS ILockBytes _                         ' __in ILockBytes* plkbyt
 , BYVAL pStgPriority AS IStorage _                     ' __in IStorage* pStgPriority
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL snbExclude AS DWORD _                          ' __in SNB snbExclude
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF ppstgOpen AS IStorage _                        ' __out IStorage** ppstgOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgIsStorageFile IMPORT "OLE32.DLL" ALIAS "StgIsStorageFile" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in const WCHAR* pwcsName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgIsStorageILockBytes IMPORT "OLE32.DLL" ALIAS "StgIsStorageILockBytes" ( _
   BYVAL plkbyt AS ILockBytes _                         ' __in ILockBytes* plkbyt
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgSetTimes IMPORT "OLE32.DLL" ALIAS "StgSetTimes" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in WCHAR const* lpszName
 , BYREF pctime AS FILETIME _                           ' __in FILETIME const* pctime
 , BYREF patime AS FILETIME _                           ' __in FILETIME const* patime
 , BYREF pmtime AS FILETIME _                           ' __in FILETIME const* pmtime
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgOpenAsyncDocfileOnIFillLockBytes IMPORT "OLE32.DLL" ALIAS "StgOpenAsyncDocfileOnIFillLockBytes" ( _
   BYVAL ppflb AS IFillLockBytes _                      ' __in IFillLockBytes* ppflb
 , BYVAL grfmode AS DWORD _                             ' __in DWORD grfmode
 , BYVAL asyncFlags AS DWORD _                          ' __in DWORD asyncFlags
 , BYREF ppstgOpen AS IStorage _                        ' __out IStorage** ppstgOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgGetIFillLockBytesOnILockBytes IMPORT "OLE32.DLL" ALIAS "StgGetIFillLockBytesOnILockBytes" ( _
   BYVAL pilb AS ILockBytes _                           ' __in ILockBytes* pilb
 , BYREF ppflb AS IFillLockBytes _                      ' __out IFillLockBytes** ppflb
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgGetIFillLockBytesOnFile IMPORT "OLE32.DLL" ALIAS "StgGetIFillLockBytesOnFile" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in OLECHAR* pwcsName
 , BYREF ppflb AS IFillLockBytes _                      ' __out IFillLockBytes** ppflb
 ) AS LONG                                              ' HRESULT

' Note  Do not use this function. Use the IStorage::CopyTo method instead.
' CopyTo can be used to layout a docfile, thus improving performance in most scenarios.
'WINOLEAPI StgOpenLayoutDocfile(IN OLECHAR const *pwcsDfName,
'             IN  DWORD grfMode,
'             IN  DWORD reserved,
'             OUT IStorage **ppstgOpen);

'// STG initialization options for StgCreateStorageEx and StgOpenStorageEx
'#if _WIN32_WINNT == 0x500
'#define STGOPTIONS_VERSION 1
'#elif _WIN32_WINNT > 0x500
'#define STGOPTIONS_VERSION 2
'#else
'#define STGOPTIONS_VERSION 0
'#endif

#IF %WINVER = &H500
    %STGOPTIONS_VERSION = 1
#ELSEIF %WINVER > &H500
    %STGOPTIONS_VERSION = 2
#ELSE
    %STGOPTIONS_VERSION = 0
#ENDIF

'typedef struct tagSTGOPTIONS
'{
'    USHORT usVersion;            // Versions 1 and 2 supported
'    USHORT reserved;             // must be 0 for padding
'    ULONG ulSectorSize;          // docfile header sector size (512)
'#if STGOPTIONS_VERSION >= 2
'    const WCHAR *pwcsTemplateFile;  // version 2 or above
'#endif
'} STGOPTIONS;

' // Size = 8/12 bytes
TYPE STGOPTIONS
   usVersion        AS WORD    ' // Versions 1 and 2 supported
   reserved         AS WORD    ' // must be 0 for padding
   ulSectorSize     AS DWORD   ' // docfile header sector size (512)
#IF %STGOPTIONS_VERSION >= 2
   pwcsTemplateFile AS DWORD   ' // version 2 or above
#ENDIF
END TYPE

DECLARE FUNCTION StgCreateStorageEx IMPORT "OLE32.DLL" ALIAS "StgCreateStorageEx" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in const WCHAR* pwcsName
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL stgfmt AS DWORD _                              ' __in STGFMT stgfmt
 , BYVAL grfAttrs AS DWORD _                            ' __in DWORD grfAttrs
 , BYREF pStgOptions AS STGOPTIONS _                    ' __in STGOPTIONS* pStgOptions
 , BYVAL reserved2 AS DWORD _                           ' __in void* reserved2
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppObjectOpen AS ANY _                          ' __out void** ppObjectOpen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgOpenStorageEx IMPORT "OLE32.DLL" ALIAS "StgOpenStorageEx" ( _
   BYREF pwcsName AS WSTRINGZ _                         ' __in const WCHAR* pwcsName
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL stgfmt AS DWORD _                              ' __in STGFMT stgfmt
 , BYVAL grfAttrs AS DWORD _                            ' __in DWORD grfAttrs
 , BYREF pStgOptions AS STGOPTIONS _                    ' __in STGOPTIONS* pStgOptions
 , BYVAL reserved2 AS DWORD _                           ' __in void* reserved2
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppObjectOpen AS ANY _                          ' __out void** ppObjectOpen
 ) AS LONG                                              ' HRESULT

'//
'//  Moniker APIs
'//

DECLARE FUNCTION BindMoniker IMPORT "OLE32.DLL" ALIAS "BindMoniker" ( _
   BYVAL pmk AS IMoniker _                              ' __in LPMONIKER pmk
 , BYVAL grfOpt AS DWORD _                              ' __in DWORD grfOpt
 , BYREF iidResult AS GUID _                            ' __in REFIID iidResult
 , BYREF ppvResult AS ANY _                             ' __out LPVOID FAR * ppvResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInstall IMPORT "OLE32.DLL" ALIAS "CoInstall" ( _
   BYVAL pbc AS IBindCtx _                              ' __in IBindCtx * pbc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pClassSpec AS uCLSSPEC _                       ' __in uCLSSPEC * pClassSpec
 , BYVAL pQuery AS QUERYCONTEXT _                       ' __in QUERYCONTEXT * pQuery
 , BYREF pszCodeBase AS WSTRINGZ _                      ' __in LPWSTR pszCodeBase
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetObject IMPORT "OLE32.DLL" ALIAS "CoGetObject" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR pszName
 , BYREF pBindOptions AS BIND_OPTS _                    ' __in BIND_OPTS * pBindOptions
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void ** ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MkParseDisplayName IMPORT "OLE32.DLL" ALIAS "MkParseDisplayName" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYREF szUserName AS WSTRINGZ _                       ' __in LPCOLESTR szUserName
 , BYREF pchEaten AS DWORD _                            ' __out ULONG FAR * pchEaten
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MonikerRelativePathTo IMPORT "OLE32.DLL" ALIAS "MonikerRelativePathTo" ( _
   BYVAL pmkSrc AS IMoniker _                           ' __in LPMONIKER pmkSrc
 , BYVAL pmkDest AS IMoniker _                          ' __in LPMONIKER pmkDest
 , BYREF ppmkRelPath AS IMoniker _                      ' __out LPMONIKER FAR * ppmkRelPath
 , BYVAL dwReserved AS LONG _                           ' __in BOOL dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MonikerCommonPrefixWith IMPORT "OLE32.DLL" ALIAS "MonikerCommonPrefixWith" ( _
   BYVAL pmkThis AS IMoniker _                          ' __in LPMONIKER pmkThis
 , BYVAL pmkOther AS IMoniker _                         ' __in LPMONIKER pmkOther
 , BYREF ppmkCommon AS IMoniker _                       ' __out LPMONIKER FAR * ppmkCommon
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateBindCtx IMPORT "OLE32.DLL" ALIAS "CreateBindCtx" ( _
   BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF ppbc AS IBindCtx _                             ' __out LPBC FAR * ppbc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateGenericComposite IMPORT "OLE32.DLL" ALIAS "CreateGenericComposite" ( _
   BYVAL pmkFirst AS IMoniker _                         ' __in LPMONIKER pmkFirst
 , BYVAL pmkRest AS IMoniker _                          ' __in LPMONIKER pmkRest
 , BYREF ppmkComposite AS IMoniker _                    ' __out LPMONIKER FAR * ppmkComposite
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetClassFile IMPORT "OLE32.DLL" ALIAS "GetClassFile" ( _
   BYREF szFileName AS WSTRINGZ _                       ' __in LPCWSTR szFileName
 , BYREF pclsid AS GUID _                               ' __out CLSID * pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateClassMoniker IMPORT "OLE32.DLL" ALIAS "CreateClassMoniker" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF ppmk AS IMoniker _                             ' __out IMoniker ** ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateFileMoniker IMPORT "OLE32.DLL" ALIAS "CreateFileMoniker" ( _
   BYREF lpszPathName AS WSTRINGZ _                     ' __in LPCOLESTR lpszPathName
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateItemMoniker IMPORT "OLE32.DLL" ALIAS "CreateItemMoniker" ( _
   BYREF lpszDelim AS WSTRINGZ _                        ' __in LPCOLESTR lpszDelim
 , BYREF lpszItem AS WSTRINGZ _                         ' __in LPCOLESTR lpszItem
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAntiMoniker IMPORT "OLE32.DLL" ALIAS "CreateAntiMoniker" ( __
   BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreatePointerMoniker IMPORT "OLE32.DLL" ALIAS "CreatePointerMoniker" ( _
   BYVAL punk AS IUnknown _                             ' __in LPUNKNOWN punk
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateObjrefMoniker IMPORT "OLE32.DLL" ALIAS "CreateObjrefMoniker" ( _
   BYVAL pUnk AS IUnknown _                             ' __in LPUNKNOWN pUnk
 , BYREF ppMk AS IMoniker _                             ' __out LPMONIKER * ppMk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetRunningObjectTable IMPORT "OLE32.DLL" ALIAS "GetRunningObjectTable" ( _
   BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYREF pprot AS IRunningObjectTable _                 ' __out LPRUNNINGOBJECTTABLE * pprot
 ) AS LONG                                              ' HRESULT

#INCLUDE ONCE "urlmon.inc"
#INCLUDE ONCE "propidl.inc"

'//
'// Standard Progress Indicator impolementation
'//

DECLARE FUNCTION CreateStdProgressIndicator IMPORT "OLE32.DLL" ALIAS "CreateStdProgressIndicator" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF pszTitle AS WSTRINGZ _                         ' __in LPCOLESTR pszTitle
 , BYVAL pIbscCaller AS IBindStatusCallback _           ' __in IBindStatusCallback * pIbscCaller
 , BYREF ppIbsc AS IBindStatusCallback _                ' __out IBindStatusCallback ** ppIbsc
 ) AS LONG                                              ' HRESULT
