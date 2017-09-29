' ########################################################################################
' Microsoft Windows
' File: d3d9types.inc
' Contents: Direct3D capabilities include file
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D9TYPES_INC = 1

#IF NOT %DEF(%DIRECT3D_VERSION)
%DIRECT3D_VERSION = &H0900
#ENDIF

'// D3DCOLOR is equivalent to D3DFMT_A8R8G8B8
'typedef DWORD D3DCOLOR;

'// maps unsigned 8 bits/channel to D3DCOLOR
'#define D3DCOLOR_ARGB(a,r,g,b) \
'    ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
'#define D3DCOLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
'#define D3DCOLOR_XRGB(r,g,b)   D3DCOLOR_ARGB(0xff,r,g,b)

'#define D3DCOLOR_XYUV(y,u,v)   D3DCOLOR_ARGB(0xff,y,u,v)
'#define D3DCOLOR_AYUV(a,y,u,v) D3DCOLOR_ARGB(a,y,u,v)

'// maps floating point channels (0.f to 1.f range) to D3DCOLOR
'#define D3DCOLOR_COLORVALUE(r,g,b,a) \
'    D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))

' // Size = 4 bytes
TYPE D3DCOLOR_BGRA_STRUCT BYTE
   blue  AS BYTE
   green AS BYTE
   red   AS BYTE
   alpha AS BYTE
END TYPE

' // Size = 4 bytes
UNION D3DCOLOR_BGRA_UNION BYTE
   color AS DWORD
   D3DCOLOR_BGRA_STRUCT
END UNION

FUNCTION D3DCOLOR_ARGB (BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) AS DWORD
   LOCAL clr AS D3DCOLOR_BGRA_UNION
   clr.alpha = a
   clr.red   = r
   clr.green = g
   clr.blue  = b
   FUNCTION = clr.color
END FUNCTION

FUNCTION D3DCOLOR_RGBA (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE, BYVAL a AS BYTE) AS DWORD
   FUNCTION = D3DCOLOR_ARGB(a, r, g, b)
END FUNCTION

FUNCTION D3DCOLOR_XRGB (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) AS DWORD
   FUNCTION = D3DCOLOR_ARGB(&HFF, r, g, b)
END FUNCTION

FUNCTION D3DCOLOR_XYUV (BYVAL y AS BYTE, BYVAL u AS BYTE, BYVAL v AS BYTE) AS DWORD
   FUNCTION = D3DCOLOR_ARGB(&HFF, y, u, v)
END FUNCTION

FUNCTION D3DCOLOR_AYUV (BYVAL a AS BYTE, BYVAL y AS BYTE, BYVAL u AS BYTE, BYVAL v AS BYTE) AS DWORD
   FUNCTION = D3DCOLOR_ARGB(a, y, u, v)
END FUNCTION

FUNCTION D3DCOLOR_COLORVALUE (BYVAL r AS SINGLE, BYVAL g AS SINGLE, BYVAL b AS SINGLE, BYVAL a AS SINGLE) AS DWORD
   FUNCTION = D3DCOLOR_ARGB(CBYT(a*255), CBYT(r*255), CBYT(g*255), CBYT(b*255))
END FUNCTION

#IF NOT %DEF(%D3DVECTOR_DEFINED)
' // Size = 12 bytes
TYPE D3DVECTOR DWORD
   x AS SINGLE
   y AS SINGLE
   z AS SINGLE
END TYPE
%D3DVECTOR_DEFINED = 1
#ENDIF

#IF NOT %DEF(%D3DCOLORVALUE_DEFINED)
' // Size = 16 bytes
TYPE D3DCOLORVALUE DWORD
   r AS SINGLE
   g AS SINGLE
   b AS SINGLE
   a AS SINGLE
END TYPE
%D3DCOLORVALUE_DEFINED = 1
#ENDIF

#IF NOT %DEF(%D3DRECT_DEFINED)
' // Size = 16 bytes
TYPE D3DRECT DWORD
   x1 AS LONG
   y1 AS LONG
   x2 AS LONG
   y2 AS LONG
END TYPE
%D3DRECT_DEFINED = 1
#ENDIF

#IF NOT %DEF(%D3DMATRIX_DEFINED)
' // Size = 64 bytes
TYPE D3DMATRIX DWORD
   m11 AS SINGLE
   m12 AS SINGLE
   m13 AS SINGLE
   m14 AS SINGLE
   m21 AS SINGLE
   m22 AS SINGLE
   m23 AS SINGLE
   m24 AS SINGLE
   m31 AS SINGLE
   m32 AS SINGLE
   m33 AS SINGLE
   m34 AS SINGLE
   m41 AS SINGLE
   m42 AS SINGLE
   m43 AS SINGLE
   m44 AS SINGLE
END TYPE
%D3DMATRIX_DEFINED = 1
#ENDIF

' // Size = 24 bytes
TYPE D3DVIEWPORT9 DWORD
   X       AS DWORD
   Y       AS DWORD    ' /* Viewport Top left */
   Width   AS DWORD
   Height  AS DWORD
   MinZ    AS SINGLE   ' /* Viewport Dimensions */
   MaxZ    AS SINGLE   ' /* Min/max of clip Volume */
END TYPE

'/*
' * Values for clip fields.
' */

' // Max number of user clipping planes, supported in D3D.
%D3DMAXUSERCLIPPLANES = 32

'// These bits could be ORed together to use with D3DRS_CLIPPLANEENABLE
'//

%D3DCLIPPLANE0 = 1    ' (1 << 0)
%D3DCLIPPLANE1 = 2    ' (1 << 1)
%D3DCLIPPLANE2 = 4    ' (1 << 2)
%D3DCLIPPLANE3 = 8    ' (1 << 3)
%D3DCLIPPLANE4 = 16   ' (1 << 4)
%D3DCLIPPLANE5 = 32   ' (1 << 5)

'// The following bits are used in the ClipUnion and ClipIntersection
'// members of the D3DCLIPSTATUS9
'//

%D3DCS_LEFT        = &H00000001???
%D3DCS_RIGHT       = &H00000002???
%D3DCS_TOP         = &H00000004???
%D3DCS_BOTTOM      = &H00000008???
%D3DCS_FRONT       = &H00000010???
%D3DCS_BACK        = &H00000020???
%D3DCS_PLANE0      = &H00000040???
%D3DCS_PLANE1      = &H00000080???
%D3DCS_PLANE2      = &H00000100???
%D3DCS_PLANE3      = &H00000200???
%D3DCS_PLANE4      = &H00000400???
%D3DCS_PLANE5      = &H00000800???

%D3DCS_ALL = %D3DCS_LEFT OR %D3DCS_RIGHT OR %D3DCS_TOP OR %D3DCS_BOTTOM OR _
             %D3DCS_FRONT OR %D3DCS_BACK OR %D3DCS_PLANE0 OR %D3DCS_PLANE1 OR _
             %D3DCS_PLANE2 OR %D3DCS_PLANE3 OR %D3DCS_PLANE4 OR %D3DCS_PLANE5

' // Size = 8 bytes
TYPE D3DCLIPSTATUS9 DWORD
   ClipUnion        AS DWORD
   ClipIntersection AS DWORD
END TYPE

' // Size = 68 bytes
TYPE D3DMATERIAL9 DWORD
   Diffuse  AS D3DCOLORVALUE   ' /* Diffuse color RGBA */
   Ambient  AS D3DCOLORVALUE   ' /* Ambient color RGB */
   Specular AS D3DCOLORVALUE   ' /* Specular 'shininess' */
   Emissive AS D3DCOLORVALUE   ' /* Emissive color RGB */
   Power    AS SINGLE          ' /* Sharpness if specular highlight */
END TYPE

' enum D3DLIGHTTYPE
%D3DLIGHT_POINT       = 1???
%D3DLIGHT_SPOT        = 2???
%D3DLIGHT_DIRECTIONAL = 3???
%D3DLIGHT_FORCE_DWORD = &H7FFFFFFF??? ' (2147483647) /* force 32-bit size enum */

' // Size = 104 bytes
TYPE D3DLIGHT9 DWORD
   Type         AS DWORD             ' /* Type of light source */
   Diffuse      AS D3DCOLORVALUE     ' /* Diffuse color of light */
   Specular     AS D3DCOLORVALUE     ' /* Specular color of light */
   Ambient      AS D3DCOLORVALUE     ' /* Ambient color of light */
   Position     AS D3DVECTOR         ' /* Position in world space */
   Direction    AS D3DVECTOR         ' /* Direction in world space */
   Range        AS SINGLE            ' /* Cutoff range */
   Falloff      AS SINGLE            ' /* Falloff */
   Attenuation0 AS SINGLE            ' /* Constant attenuation */
   Attenuation1 AS SINGLE            ' /* Linear attenuation */
   Attenuation2 AS SINGLE            ' /* Quadratic attenuation */
   Theta        AS SINGLE            ' /* Inner angle of spotlight cone */
   Phi          AS SINGLE            ' /* Outer angle of spotlight cone */
END TYPE

'/*
' * Options for clearing
' */
%D3DCLEAR_TARGET      = &H00000001???  ' /* Clear target surface */
%D3DCLEAR_ZBUFFER     = &H00000002???  ' /* Clear target z buffer */
%D3DCLEAR_STENCIL     = &H00000004???  ' /* Clear stencil planes */

'/*
' * The following defines the rendering states
' */

' enum D3DSHADEMODE
%D3DSHADE_FLAT        = 1???
%D3DSHADE_GOURAUD     = 2???
%D3DSHADE_PHONG       = 3???
%D3DSHADE_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DFILLMODE
%D3DFILL_POINT        = 1???
%D3DFILL_WIREFRAME    = 2???
%D3DFILL_SOLID        = 3???
%D3DFILL_FORCE_DWORD  = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DBLEND
%D3DBLEND_ZERO            = 1???
%D3DBLEND_ONE             = 2???
%D3DBLEND_SRCCOLOR        = 3???
%D3DBLEND_INVSRCCOLOR     = 4???
%D3DBLEND_SRCALPHA        = 5???
%D3DBLEND_INVSRCALPHA     = 6???
%D3DBLEND_DESTALPHA       = 7???
%D3DBLEND_INVDESTALPHA    = 8???
%D3DBLEND_DESTCOLOR       = 9???
%D3DBLEND_INVDESTCOLOR    = 10???
%D3DBLEND_SRCALPHASAT     = 11???
%D3DBLEND_BOTHSRCALPHA    = 12???
%D3DBLEND_BOTHINVSRCALPHA = 13???
%D3DBLEND_BLENDFACTOR     = 14??? ' /* Only supported if D3DPBLENDCAPS_BLENDFACTOR is on */
%D3DBLEND_INVBLENDFACTOR  = 15??? ' /* Only supported if D3DPBLENDCAPS_BLENDFACTOR is on */
'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DBLEND_SRCCOLOR2       = 16???
%D3DBLEND_INVSRCCOLOR2    = 17???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */
%D3DBLEND_FORCE_DWORD     = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DBLENDOP
%D3DBLENDOP_ADD         = 1???
%D3DBLENDOP_SUBTRACT    = 2???
%D3DBLENDOP_REVSUBTRACT = 3???
%D3DBLENDOP_MIN         = 4???
%D3DBLENDOP_MAX         = 5???
%D3DBLENDOP_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DTEXTUREADDRESS
%D3DTADDRESS_WRAP        = 1???
%D3DTADDRESS_MIRROR      = 2???
%D3DTADDRESS_CLAMP       = 3???
%D3DTADDRESS_BORDER      = 4???
%D3DTADDRESS_MIRRORONCE  = 5???
%D3DTADDRESS_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DCULL
%D3DCULL_NONE        = 1???
%D3DCULL_CW          = 2???
%D3DCULL_CCW         = 3???
%D3DCULL_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DCMPFUNC
%D3DCMP_NEVER        = 1???
%D3DCMP_LESS         = 2???
%D3DCMP_EQUAL        = 3???
%D3DCMP_LESSEQUAL    = 4???
%D3DCMP_GREATER      = 5???
%D3DCMP_NOTEQUAL     = 6???
%D3DCMP_GREATEREQUAL = 7???
%D3DCMP_ALWAYS       = 8???
%D3DCMP_FORCE_DWORD  = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DSTENCILOP
%D3DSTENCILOP_KEEP        = 1???
%D3DSTENCILOP_ZERO        = 2???
%D3DSTENCILOP_REPLACE     = 3???
%D3DSTENCILOP_INCRSAT     = 4???
%D3DSTENCILOP_DECRSAT     = 5???
%D3DSTENCILOP_INVERT      = 6???
%D3DSTENCILOP_INCR        = 7???
%D3DSTENCILOP_DECR        = 8???
%D3DSTENCILOP_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum D3DFOGMODE
%D3DFOG_NONE        = 0???
%D3DFOG_EXP         = 1???
%D3DFOG_EXP2        = 2???
%D3DFOG_LINEAR      = 3???
%D3DFOG_FORCE_DWORD = &H7FFFFFFF???  ' (2147483647) /* force 32-bit size enum */

' enum _D3DZBUFFERTYPE
%D3DZB_FALSE        = 0???
%D3DZB_TRUE         = 1???            ' // Z buffering
%D3DZB_USEW         = 2???            ' // W buffering
%D3DZB_FORCE_DWORD  = &H7FFFFFFF???   ' (2147483647) /* force 32-bit size enum */

' // Primitives supported by draw-primitive API
' enum _D3DPRIMITIVETYPE
%D3DPT_POINTLIST     = 1???
%D3DPT_LINELIST      = 2???
%D3DPT_LINESTRIP     = 3???
%D3DPT_TRIANGLELIST  = 4???
%D3DPT_TRIANGLESTRIP = 5???
%D3DPT_TRIANGLEFAN   = 6???
%D3DPT_FORCE_DWORD   = &H7FFFFFFF???   ' (2147483647) /* force 32-bit size enum */

' enum _D3DTRANSFORMSTATETYPE
%D3DTS_VIEW        = 2???
%D3DTS_PROJECTION  = 3???
%D3DTS_TEXTURE0    = 16???
%D3DTS_TEXTURE1    = 17???
%D3DTS_TEXTURE2    = 18???
%D3DTS_TEXTURE3    = 19???
%D3DTS_TEXTURE4    = 20???
%D3DTS_TEXTURE5    = 21???
%D3DTS_TEXTURE6    = 22???
%D3DTS_TEXTURE7    = 23???
%D3DTS_FORCE_DWORD = &H7FFFFFFF???   ' (2147483647) /* force 32-bit size enum */

'#define D3DTS_WORLDMATRIX(index) (D3DTRANSFORMSTATETYPE)(index + 256)
'#define D3DTS_WORLD  D3DTS_WORLDMATRIX(0)
'#define D3DTS_WORLD1 D3DTS_WORLDMATRIX(1)
'#define D3DTS_WORLD2 D3DTS_WORLDMATRIX(2)
'#define D3DTS_WORLD3 D3DTS_WORLDMATRIX(3)

%D3DTS_WORLD  = 256???
%D3DTS_WORLD1 = 257???
%D3DTS_WORLD2 = 258???
%D3DTS_WORLD3 = 259???

' enum _D3DRENDERSTATETYPE
%D3DRS_ZENABLE                    = 7???            ' /* D3DZBUFFERTYPE (or TRUE/FALSE for legacy) */
%D3DRS_FILLMODE                   = 8???            ' /* D3DFILLMODE */
%D3DRS_SHADEMODE                  = 9???            ' /* D3DSHADEMODE */
%D3DRS_ZWRITEENABLE               = 14???           ' /* TRUE to enable z writes */
%D3DRS_ALPHATESTENABLE            = 15???           ' /* TRUE to enable alpha tests */
%D3DRS_LASTPIXEL                  = 16???           ' /* TRUE for last-pixel on lines */
%D3DRS_SRCBLEND                   = 19???           ' /* D3DBLEND */
%D3DRS_DESTBLEND                  = 20???           ' /* D3DBLEND */
%D3DRS_CULLMODE                   = 22???           ' /* D3DCULL */
%D3DRS_ZFUNC                      = 23???           ' /* D3DCMPFUNC */
%D3DRS_ALPHAREF                   = 24???           ' /* D3DFIXED */
%D3DRS_ALPHAFUNC                  = 25???           ' /* D3DCMPFUNC */
%D3DRS_DITHERENABLE               = 26???           ' /* TRUE to enable dithering */
%D3DRS_ALPHABLENDENABLE           = 27???           ' /* TRUE to enable alpha blending */
%D3DRS_FOGENABLE                  = 28???           ' /* TRUE to enable fog blending */
%D3DRS_SPECULARENABLE             = 29???           ' /* TRUE to enable specular */
%D3DRS_ZVISIBLE                   = 30???           ' /* D3DCOLOR */
%D3DRS_FOGCOLOR                   = 34???           ' /* D3DCOLOR */
%D3DRS_FOGTABLEMODE               = 35???           ' /* D3DFOGMODE */
%D3DRS_FOGSTART                   = 36???           ' /* Fog start (for both vertex and pixel fog) */
%D3DRS_FOGEND                     = 37???           ' /* Fog end      */
%D3DRS_FOGDENSITY                 = 38???           ' /* Fog density  */
%D3DRS_RANGEFOGENABLE             = 48???           ' /* Enables range-based fog */
%D3DRS_STENCILENABLE              = 52???           ' /* BOOL enable/disable stenciling */
%D3DRS_STENCILFAIL                = 53???           ' /* D3DSTENCILOP to do if stencil test fails */
%D3DRS_STENCILZFAIL               = 54???           ' /* D3DSTENCILOP to do if stencil test passes and Z test fails */
%D3DRS_STENCILPASS                = 55???           ' /* D3DSTENCILOP to do if both stencil and Z tests pass */
%D3DRS_STENCILFUNC                = 56???           ' /* D3DCMPFUNC fn.  Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true */
%D3DRS_STENCILREF                 = 57???           ' /* Reference value used in stencil test */
%D3DRS_STENCILMASK                = 58???           ' /* Mask value used in stencil test */
%D3DRS_STENCILWRITEMASK           = 59???           ' /* Write mask applied to values written to stencil buffer */
%D3DRS_TEXTUREFACTOR              = 60???           ' /* D3DCOLOR used for multi-texture blend */
%D3DRS_WRAP0                      = 128???          ' /* wrap for 1st texture coord. set */
%D3DRS_WRAP1                      = 129???          ' /* wrap for 2nd texture coord. set */
%D3DRS_WRAP2                      = 130???          ' /* wrap for 3rd texture coord. set */
%D3DRS_WRAP3                      = 131???          ' /* wrap for 4th texture coord. set */
%D3DRS_WRAP4                      = 132???          ' /* wrap for 5th texture coord. set */
%D3DRS_WRAP5                      = 133???          ' /* wrap for 6th texture coord. set */
%D3DRS_WRAP6                      = 134???          ' /* wrap for 7th texture coord. set */
%D3DRS_WRAP7                      = 135???          ' /* wrap for 8th texture coord. set */
%D3DRS_CLIPPING                   = 136???
%D3DRS_LIGHTING                   = 137???
%D3DRS_AMBIENT                    = 139???
%D3DRS_FOGVERTEXMODE              = 140???
%D3DRS_COLORVERTEX                = 141???
%D3DRS_LOCALVIEWER                = 142???
%D3DRS_NORMALIZENORMALS           = 143???
%D3DRS_DIFFUSEMATERIALSOURCE      = 145???
%D3DRS_SPECULARMATERIALSOURCE     = 146???
%D3DRS_AMBIENTMATERIALSOURCE      = 147???
%D3DRS_EMISSIVEMATERIALSOURCE     = 148???
%D3DRS_VERTEXBLEND                = 151???
%D3DRS_CLIPPLANEENABLE            = 152???
%D3DRS_POINTSIZE                  = 154???          ' /* float point size */
%D3DRS_POINTSIZE_MIN              = 155???          ' /* float point size min threshold */
%D3DRS_POINTSPRITEENABLE          = 156???          ' /* BOOL point texture coord control */
%D3DRS_POINTSCALEENABLE           = 157???          ' /* BOOL point size scale enable */
%D3DRS_POINTSCALE_A               = 158???          ' /* float point attenuation A value */
%D3DRS_POINTSCALE_B               = 159???          ' /* float point attenuation B value */
%D3DRS_POINTSCALE_C               = 160???          ' /* float point attenuation C value */
%D3DRS_MULTISAMPLE_ANTIALIAS      = 161???          ' (// BOOL - set to do FSAA with multisample buffer
%D3DRS_MULTISAMPLE_MASK           = 162???          ' // DWORD - per-sample enable/disable
%D3DRS_PATCHEDGESTYLE             = 163???          ' // Sets whether patch edges will use float style tessellation
%D3DRS_DEBUGMONITORTOKEN          = 165???          ' // DEBUG ONLY - token to debug monitor
%D3DRS_POINT_SIZE_MAX             = 166???          ' /* float point size max threshold */
%D3DRS_INDEXVERTEXBLENDENABLE     = 167???
%D3DRS_COLORWRITEENABLE           = 168???          ' // per-channel write enable
%D3DRS_TWEENFACTOR                = 170???          ' // float tween factor
%D3DRS_BLENDOP                    = 171???          ' // D3DBLENDOP setting
%D3DRS_POSITIONDEGREE             = 172???          ' // NPatch position interpolation degree. D3DDEGREE_LINEAR or D3DDEGREE_CUBIC (default)
%D3DRS_NORMALDEGREE               = 173???          ' // NPatch normal interpolation degree. D3DDEGREE_LINEAR (default) or D3DDEGREE_QUADRATIC
%D3DRS_SCISSORTESTENABLE          = 174???
%D3DRS_SLOPESCALEDEPTHBIAS        = 175???
%D3DRS_ANTIALIASEDLINEENABLE      = 176???
%D3DRS_MINTESSELLATIONLEVEL       = 178???
%D3DRS_MAXTESSELLATIONLEVEL       = 179???
%D3DRS_ADAPTIVETESS_X             = 180???
%D3DRS_ADAPTIVETESS_Y             = 181???
%D3DRS_ADAPTIVETESS_Z             = 182???
%D3DRS_ADAPTIVETESS_W             = 183???
%D3DRS_ENABLEADAPTIVETESSELLATION = 184???
%D3DRS_TWOSIDEDSTENCILMODE        = 185???          ' /* BOOL enable/disable 2 sided stenciling */
%D3DRS_CCW_STENCILFAIL            = 186???          ' /* D3DSTENCILOP to do if ccw stencil test fails */
%D3DRS_CCW_STENCILZFAIL           = 187???          ' /* D3DSTENCILOP to do if ccw stencil test passes and Z test fails */
%D3DRS_CCW_STENCILPASS            = 188???          ' /* D3DSTENCILOP to do if both ccw stencil and Z tests pass */
%D3DRS_CCW_STENCILFUNC            = 189???          ' /* D3DCMPFUNC fn.  ccw Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true */
%D3DRS_COLORWRITEENABLE1          = 190???          ' /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
%D3DRS_COLORWRITEENABLE2          = 191???          ' /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
%D3DRS_COLORWRITEENABLE3          = 192???          ' /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
%D3DRS_BLENDFACTOR                = 193???          ' /* D3DCOLOR used for a constant blend factor during alpha blending for devices that support D3DPBLENDCAPS_BLENDFACTOR */
%D3DRS_SRGBWRITEENABLE            = 194???          ' /* Enable rendertarget writes to be DE-linearized to SRGB (for formats that expose D3DUSAGE_QUERY_SRGBWRITE) */
%D3DRS_DEPTHBIAS                  = 195???
%D3DRS_WRAP8                      = 198???          ' /* Additional wrap states for vs_3_0+ attributes with D3DDECLUSAGE_TEXCOORD */
%D3DRS_WRAP9                      = 199???
%D3DRS_WRAP10                     = 200???
%D3DRS_WRAP11                     = 201???
%D3DRS_WRAP12                     = 202???
%D3DRS_WRAP13                     = 203???
%D3DRS_WRAP14                     = 204???
%D3DRS_WRAP15                     = 205???
%D3DRS_SEPARATEALPHABLENDENABLE   = 206???          ' /* TRUE to enable a separate blending function for the alpha channel */
%D3DRS_SRCBLENDALPHA              = 207???          ' /* SRC blend factor for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
%D3DRS_DESTBLENDALPHA             = 208???          ' /* DST blend factor for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
%D3DRS_BLENDOPALPHA               = 209???          ' /* Blending operation for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
%D3DRS_FORCE_DWORD                = &H7FFFFFFF???   ' (2147483647) /* force 32-bit size enum */

'// Maximum number of simultaneous render targets D3D supports
%D3D_MAX_SIMULTANEOUS_RENDERTARGETS = 4

'// Values for material source
' enum _D3DMATERIALCOLORSOURCE
%D3DMCS_MATERIAL    = 0???            ' // Color from material is used
%D3DMCS_COLOR1      = 1???            ' // Diffuse vertex color is used
%D3DMCS_COLOR2      = 2???            ' // Specular vertex color is used
%D3DMCS_FORCE_DWORD = &H7FFFFFFF???   ' // force 32-bit size enum

' // Bias to apply to the texture coordinate set to apply a wrap to.
%D3DRENDERSTATE_WRAPBIAS                = 128???

' /* Flags to construct the WRAP render states */
%D3DWRAP_U  = &H00000001???
%D3DWRAP_V  = &H00000002???
%D3DWRAP_W  = &H00000004???

' /* Flags to construct the WRAP render states for 1D thru 4D texture coordinates */
%D3DWRAPCOORD_0   = &H00000001???   ' // same as D3DWRAP_U
%D3DWRAPCOORD_1   = &H00000002???   ' // same as D3DWRAP_V
%D3DWRAPCOORD_2   = &H00000004???   ' // same as D3DWRAP_W
%D3DWRAPCOORD_3   = &H00000008???

' /* Flags to construct D3DRS_COLORWRITEENABLE */
%D3DCOLORWRITEENABLE_RED    = 1???  ' (1L<<0)
%D3DCOLORWRITEENABLE_GREEN  = 2???  ' (1L<<1)
%D3DCOLORWRITEENABLE_BLUE   = 4???  ' (1L<<2)
%D3DCOLORWRITEENABLE_ALPHA  = 8???  ' (1L<<3)

'/*
' * State enumerants for per-stage processing of fixed function pixel processing
' * Two of these affect fixed function vertex processing as well: TEXTURETRANSFORMFLAGS and TEXCOORDINDEX.
' */
%D3DTSS_COLOROP               = 1???            ' /* D3DTEXTUREOP - per-stage blending controls for color channels */
%D3DTSS_COLORARG1             = 2???            ' /* D3DTA_* (texture arg) */
%D3DTSS_COLORARG2             = 3???            ' /* D3DTA_* (texture arg) */
%D3DTSS_ALPHAOP               = 4???            ' /* D3DTEXTUREOP - per-stage blending controls for alpha channel */
%D3DTSS_ALPHAARG1             = 5???            ' /* D3DTA_* (texture arg) */
%D3DTSS_ALPHAARG2             = 6???            ' /* D3DTA_* (texture arg) */
%D3DTSS_BUMPENVMAT00          = 7???            ' /* float (bump mapping matrix) */
%D3DTSS_BUMPENVMAT01          = 8???            ' /* float (bump mapping matrix) */
%D3DTSS_BUMPENVMAT10          = 9???            ' /* float (bump mapping matrix) */
%D3DTSS_BUMPENVMAT11          = 10???           ' /* float (bump mapping matrix) */
%D3DTSS_TEXCOORDINDEX         = 11???           ' /* identifies which set of texture coordinates index this texture */
%D3DTSS_BUMPENVLSCALE         = 22???           ' /* float scale for bump map luminance */
%D3DTSS_BUMPENVLOFFSET        = 23???           ' /* float offset for bump map luminance */
%D3DTSS_TEXTURETRANSFORMFLAGS = 24???           ' /* D3DTEXTURETRANSFORMFLAGS controls texture transform */
%D3DTSS_COLORARG0             = 26???           ' /* D3DTA_* third arg for triadic ops */
%D3DTSS_ALPHAARG0             = 27???           ' /* D3DTA_* third arg for triadic ops */
%D3DTSS_RESULTARG             = 28???           ' /* D3DTA_* arg for result (CURRENT or TEMP) */
%D3DTSS_CONSTANT              = 32???           ' /* Per-stage constant D3DTA_CONSTANT */
%D3DTSS_FORCE_DWORD           = &H7FFFFFFF???   ' /* force 32-bit size enum */

'/*
' * State enumerants for per-sampler texture processing.
' */
%D3DSAMP_ADDRESSU      = 1???            ' /* D3DTEXTUREADDRESS for U coordinate */
%D3DSAMP_ADDRESSV      = 2???            ' /* D3DTEXTUREADDRESS for V coordinate */
%D3DSAMP_ADDRESSW      = 3???            ' /* D3DTEXTUREADDRESS for W coordinate */
%D3DSAMP_BORDERCOLOR   = 4???            ' /* D3DCOLOR */
%D3DSAMP_MAGFILTER     = 5???            ' /* D3DTEXTUREFILTER filter to use for magnification */
%D3DSAMP_MINFILTER     = 6???            ' /* D3DTEXTUREFILTER filter to use for minification */
%D3DSAMP_MIPFILTER     = 7???            ' /* D3DTEXTUREFILTER filter to use between mipmaps during minification */
%D3DSAMP_MIPMAPLODBIAS = 8???            ' /* float Mipmap LOD bias */
%D3DSAMP_MAXMIPLEVEL   = 9???            ' /* DWORD 0..(n-1) LOD index of largest map to use (0 == largest) */
%D3DSAMP_MAXANISOTROPY = 10???           ' /* DWORD maximum anisotropy */
%D3DSAMP_SRGBTEXTURE   = 11???           ' /* Default = 0 (which means Gamma 1.0,
                                         '     no correction required.) else correct for
                                         '     Gamma = 2.2 */
%D3DSAMP_ELEMENTINDEX  = 12???           ' /* When multi-element texture is assigned to sampler, this
                                         '      indicates which element index to use.  Default = 0.  */
%D3DSAMP_DMAPOFFSET    = 13???           ' /* Offset in vertices in the pre-sampled displacement map.
                                         '      Only valid for D3DDMAPSAMPLER sampler  */
%D3DSAMP_FORCE_DWORD   = &H7FFFFFFF???   ' /* force 32-bit size enum */

'/* Special sampler which is used in the tesselator */
%D3DDMAPSAMPLER = 256

'// Samplers used in vertex shaders
%D3DVERTEXTEXTURESAMPLER0 = %D3DDMAPSAMPLER + 1
%D3DVERTEXTEXTURESAMPLER1 = %D3DDMAPSAMPLER + 2
%D3DVERTEXTEXTURESAMPLER2 = %D3DDMAPSAMPLER + 3
%D3DVERTEXTEXTURESAMPLER3 = %D3DDMAPSAMPLER + 4

'// Values, used with D3DTSS_TEXCOORDINDEX, to specify that the vertex data(position
'// and normal in the camera space) should be taken as texture coordinates
'// Low 16 bits are used to specify texture coordinate index, to take the WRAP mode from
'//
%D3DTSS_TCI_PASSTHRU                             = &H00000000???
%D3DTSS_TCI_CAMERASPACENORMAL                    = &H00010000???
%D3DTSS_TCI_CAMERASPACEPOSITION                  = &H00020000???
%D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR          = &H00030000???
%D3DTSS_TCI_SPHEREMAP                            = &H00040000???

'/*
' * Enumerations for COLOROP and ALPHAOP texture blending operations set in
' * texture processing stage controls in D3DTSS.
' */
' enum _D3DTEXTUREOP

' // Control
%D3DTOP_DISABLE              = 1???  ' // disables stage
%D3DTOP_SELECTARG1           = 2???  ' // the default
%D3DTOP_SELECTARG2           = 3???

' // Modulate
%D3DTOP_MODULATE             = 4???  ' // multiply args together
%D3DTOP_MODULATE2X           = 5???  '  // multiply and  1 bit
%D3DTOP_MODULATE4X           = 6???  ' // multiply and  2 bits

' // Add
%D3DTOP_ADD                  =  7???  ' // add arguments together
%D3DTOP_ADDSIGNED            =  8???  ' // add with -0.5 bias
%D3DTOP_ADDSIGNED2X          =  9???  ' // as above but left  1 bit
%D3DTOP_SUBTRACT             = 10???  ' // Arg1 - Arg2, with no saturation
%D3DTOP_ADDSMOOTH            = 11???  ' // add 2 args, subtract product
                                      ' // Arg1 + Arg2 - Arg1*Arg2
                                      ' // = Arg1 + (1-Arg1)*Arg2

' // Linear alpha blend: Arg1*(Alpha) + Arg2*(1-Alpha)
%D3DTOP_BLENDDIFFUSEALPHA    = 12???  ' // iterated alpha
%D3DTOP_BLENDTEXTUREALPHA    = 13???  ' // texture alpha
%D3DTOP_BLENDFACTORALPHA     = 14???  ' // alpha from D3DRS_TEXTUREFACTOR

' // Linear alpha blend with pre-multiplied arg1 input: Arg1 + Arg2*(1-Alpha)
%D3DTOP_BLENDTEXTUREALPHAPM  = 15???  ' // texture alpha
%D3DTOP_BLENDCURRENTALPHA    = 16???  ' // by alpha of current color

' // Specular mapping
%D3DTOP_PREMODULATE               = 17???  ' // modulate with next texture before use
%D3DTOP_MODULATEALPHA_ADDCOLOR    = 18???  ' // Arg1.RGB + Arg1.A*Arg2.RGB
                                           ' // COLOROP only
%D3DTOP_MODULATECOLOR_ADDALPHA    = 19???  ' // Arg1.RGB*Arg2.RGB + Arg1.A
                                           ' // COLOROP only
%D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20???  ' // (1-Arg1.A)*Arg2.RGB + Arg1.RGB
                                           ' // COLOROP only
%D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21???  ' // (1-Arg1.RGB)*Arg2.RGB + Arg1.A
                                           ' // COLOROP only

' // Bump mapping
%D3DTOP_BUMPENVMAP           = 22???  ' // per pixel env map perturbation
%D3DTOP_BUMPENVMAPLUMINANCE  = 23???  ' // with luminance channel

' // This can do either diffuse or specular bump mapping with correct input.
' // Performs the function (Arg1.R*Arg2.R + Arg1.G*Arg2.G + Arg1.B*Arg2.B)
' // where each component has been scaled and offset to make it signed.
' // The result is replicated into all four (including alpha) channels.
' // This is a valid COLOROP only.
%D3DTOP_DOTPRODUCT3          = 24???

'    // Triadic ops
%D3DTOP_MULTIPLYADD          = 25???  ' // Arg0 + Arg1*Arg2
%D3DTOP_LERP                 = 26???  ' // (Arg0)*Arg1 + (1-Arg0)*Arg2

%D3DTOP_FORCE_DWORD = &H7FFFFFFF???

'/*
' * Values for COLORARG0,1,2, ALPHAARG0,1,2, and RESULTARG texture blending
' * operations set in texture processing stage controls in D3DRENDERSTATE.
' */
%D3DTA_SELECTMASK         = &H0000000F???  '// mask for arg selector
%D3DTA_DIFFUSE            = &H00000000???  '// select diffuse color (read only)
%D3DTA_CURRENT            = &H00000001???  '// select stage destination register (read/write)
%D3DTA_TEXTURE            = &H00000002???  '// select texture color (read only)
%D3DTA_TFACTOR            = &H00000003???  '// select D3DRS_TEXTUREFACTOR (read only)
%D3DTA_SPECULAR           = &H00000004???  '// select specular color (read only)
%D3DTA_TEMP               = &H00000005???  '// select temporary register color (read/write)
%D3DTA_CONSTANT           = &H00000006???  '// select texture stage constant
%D3DTA_COMPLEMENT         = &H00000010???  '// take 1.0 - x (read modifier)
%D3DTA_ALPHAREPLICATE     = &H00000020???  '// replicate alpha to color components (read modifier)

'//
'// Values for D3DSAMP_***FILTER texture stage states
'//
' enum _D3DTEXTUREFILTERTYPE
%D3DTEXF_NONE            = 0???  '  // filtering disabled (valid for mip filter only)
%D3DTEXF_POINT           = 1???  '  // nearest
%D3DTEXF_LINEAR          = 2???  '  // linear interpolation
%D3DTEXF_ANISOTROPIC     = 3???  '  // anisotropic
%D3DTEXF_PYRAMIDALQUAD   = 6???  '  // 4-sample tent
%D3DTEXF_GAUSSIANQUAD    = 7???  '  // 4-sample gaussian
'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DTEXF_CONVOLUTIONMONO = 8???  '  // Convolution filter for monochrome textures
'/* -- D3D9Ex only */
#ENDIF   ' // !D3D_DISABLE_9EX
%D3DTEXF_FORCE_DWORD     = &H7FFFFFFF???  ' /* force 32-bit size enum */

'/* Bits for Flags in ProcessVertices call */

%D3DPV_DONOTCOPYDATA = 1???   ' (1 << 0)

'//-------------------------------------------------------------------

'// Flexible vertex format bits
'//
%D3DFVF_RESERVED0        = &H001???
%D3DFVF_POSITION_MASK    = &H400E???
%D3DFVF_XYZ              = &H002???
%D3DFVF_XYZRHW           = &H004???
%D3DFVF_XYZB1            = &H006???
%D3DFVF_XYZB2            = &H008???
%D3DFVF_XYZB3            = &H00A???
%D3DFVF_XYZB4            = &H00C???
%D3DFVF_XYZB5            = &H00E???
%D3DFVF_XYZW             = &H4002???

%D3DFVF_NORMAL           = &H010???
%D3DFVF_PSIZE            = &H020???
%D3DFVF_DIFFUSE          = &H040???
%D3DFVF_SPECULAR         = &H080???

%D3DFVF_TEXCOUNT_MASK    = &HF00???
%D3DFVF_TEXCOUNT_SHIFT   = 8
%D3DFVF_TEX0             = &H000???
%D3DFVF_TEX1             = &H100???
%D3DFVF_TEX2             = &H200???
%D3DFVF_TEX3             = &H300???
%D3DFVF_TEX4             = &H400???
%D3DFVF_TEX5             = &H500???
%D3DFVF_TEX6             = &H600???
%D3DFVF_TEX7             = &H700???
%D3DFVF_TEX8             = &H800???

%D3DFVF_LASTBETA_UBYTE4   = &H1000???
%D3DFVF_LASTBETA_D3DCOLOR = &H8000???

%D3DFVF_RESERVED2         = &H6000???  ' // 2 reserved bits

'//---------------------------------------------------------------------
'// Vertex Shaders
'//

'// Vertex shader declaration

'// Vertex element semantics
'//
' enum _D3DDECLUSAGE
%D3DDECLUSAGE_POSITION = 0
%D3DDECLUSAGE_BLENDWEIGHT   = 1
%D3DDECLUSAGE_BLENDINDICES  = 2
%D3DDECLUSAGE_NORMAL        = 3
%D3DDECLUSAGE_PSIZE         = 4
%D3DDECLUSAGE_TEXCOORD      = 5
%D3DDECLUSAGE_TANGENT       = 6
%D3DDECLUSAGE_BINORMAL      = 7
%D3DDECLUSAGE_TESSFACTOR    = 8
%D3DDECLUSAGE_POSITIONT     = 9
%D3DDECLUSAGE_COLOR         = 10
%D3DDECLUSAGE_FOG           = 11
%D3DDECLUSAGE_DEPTH         = 12
%D3DDECLUSAGE_SAMPLE        = 13

%MAXD3DDECLUSAGE        = %D3DDECLUSAGE_SAMPLE
%MAXD3DDECLUSAGEINDEX   = 15
%MAXD3DDECLLENGTH       = 64  ' // does not include "end" marker vertex element

' enum _D3DDECLMETHOD
%D3DDECLMETHOD_DEFAULT          = 0
%D3DDECLMETHOD_PARTIALU         = 1
%D3DDECLMETHOD_PARTIALV         = 2
%D3DDECLMETHOD_CROSSUV          = 3   '  // Normal
%D3DDECLMETHOD_UV               = 4
%D3DDECLMETHOD_LOOKUP           = 4   '  // Lookup a displacement map
%D3DDECLMETHOD_LOOKUPPRESAMPLED = 6   '  // Lookup a pre-sampled displacement map

%MAXD3DDECLMETHOD = %D3DDECLMETHOD_LOOKUPPRESAMPLED

'// Declarations for _Type fields
'//
' enum _D3DDECLTYPE
%D3DDECLTYPE_FLOAT1    =  0  '  // 1D float expanded to (value, 0., 0., 1.)
%D3DDECLTYPE_FLOAT2    =  1  '  // 2D float expanded to (value, value, 0., 1.)
%D3DDECLTYPE_FLOAT3    =  2  '  // 3D float expanded to (value, value, value, 1.)
%D3DDECLTYPE_FLOAT4    =  3  '  // 4D float
%D3DDECLTYPE_D3DCOLOR  =  4  '  // 4D packed unsigned bytes mapped to 0. to 1. range
                             '  // Input is in D3DCOLOR format (ARGB) expanded to (R, G, B, A)
%D3DDECLTYPE_UBYTE4    =  5  '  // 4D unsigned byte
%D3DDECLTYPE_SHORT2    =  6  '  // 2D signed short expanded to (value, value, 0., 1.)
%D3DDECLTYPE_SHORT4    =  7  '  // 4D signed short

'// The following types are valid only with vertex shaders >= 2.0

%D3DDECLTYPE_UBYTE4N   =  8  '  // Each of 4 bytes is normalized by dividing to 255.0
%D3DDECLTYPE_SHORT2N   =  9  '  // 2D signed short normalized (v[0]/32767.0,v[1]/32767.0,0,1)
%D3DDECLTYPE_SHORT4N   = 10  '  // 4D signed short normalized (v[0]/32767.0,v[1]/32767.0,v[2]/32767.0,v[3]/32767.0)
%D3DDECLTYPE_USHORT2N  = 11  '  // 2D unsigned short normalized (v[0]/65535.0,v[1]/65535.0,0,1)
%D3DDECLTYPE_USHORT4N  = 12  '  // 4D unsigned short normalized (v[0]/65535.0,v[1]/65535.0,v[2]/65535.0,v[3]/65535.0)
%D3DDECLTYPE_UDEC3     = 13  '  // 3D unsigned 10 10 10 format expanded to (value, value, value, 1)
%D3DDECLTYPE_DEC3N     = 14  '  // 3D signed 10 10 10 format normalized and expanded to (v[0]/511.0, v[1]/511.0, v[2]/511.0, 1)
%D3DDECLTYPE_FLOAT16_2 = 15  '  // Two 16-bit floating point values, expanded to (value, value, 0, 1)
%D3DDECLTYPE_FLOAT16_4 = 16  '  // Four 16-bit floating point values
%D3DDECLTYPE_UNUSED    = 17  '  // When the type field in a decl is unused.

%MAXD3DDECLTYPE        = %D3DDECLTYPE_UNUSED

' // Size = 8 bytes
TYPE D3DVERTEXELEMENT9 BYTE
   Stream     AS WORD   ' // Stream index
   Offset     AS WORD   ' // Offset in the stream in bytes
   Type       AS BYTE   ' // Data type
   Method     AS BYTE   ' // Processing method
   Usage      AS BYTE   ' // Semantics
   UsageIndex AS BYTE   ' // Semantic index
END TYPE

'// This is used to initialize the last vertex element in a vertex declaration
'// array
'//
'#define D3DDECL_END() {0xFF,0,D3DDECLTYPE_UNUSED,0,0,0}

'// Maximum supported number of texture coordinate sets
%D3DDP_MAXTEXCOORD   = 8

'//---------------------------------------------------------------------
'// Values for IDirect3DDevice9::SetStreamSourceFreq's Setting parameter
'//---------------------------------------------------------------------
%D3DSTREAMSOURCE_INDEXEDDATA  = &H40000000???   ' (1<<30)
%D3DSTREAMSOURCE_INSTANCEDATA = &H80000000???   ' (2<<30)

'//---------------------------------------------------------------------
'//
'// The internal format of Pixel Shader (PS) & Vertex Shader (VS)
'// Instruction Tokens is defined in the Direct3D Device Driver Kit
'//
'//---------------------------------------------------------------------

'//
'// Instruction Token Bit Definitions
'//
%D3DSI_OPCODE_MASK     =  &H0000FFFF???

%D3DSI_INSTLENGTH_MASK  = &H0F000000???
%D3DSI_INSTLENGTH_SHIFT = 24

%D3DSIO_NOP          = 0???
%D3DSIO_MOV          = 1???
%D3DSIO_ADD          = 2???
%D3DSIO_SUB          = 3???
%D3DSIO_MAD          = 4???
%D3DSIO_MUL          = 5???
%D3DSIO_RCP          = 6???
%D3DSIO_RSQ          = 7???
%D3DSIO_DP3          = 8???
%D3DSIO_DP4          = 9???
%D3DSIO_MIN          = 10???
%D3DSIO_MAX          = 11???
%D3DSIO_SLT          = 12???
%D3DSIO_SGE          = 13???
%D3DSIO_EXP          = 14???
%D3DSIO_LOG          = 15???
%D3DSIO_LIT          = 16???
%D3DSIO_DST          = 17???
%D3DSIO_LRP          = 18???
%D3DSIO_FRC          = 19???
%D3DSIO_M4x4         = 20???
%D3DSIO_M4x3         = 21???
%D3DSIO_M3x4         = 22???
%D3DSIO_M3x3         = 23???
%D3DSIO_M3x2         = 24???
%D3DSIO_CALL         = 25???
%D3DSIO_CALLNZ       = 26???
%D3DSIO_LOOP         = 27???
%D3DSIO_RET          = 28???
%D3DSIO_ENDLOOP      = 29???
%D3DSIO_LABEL        = 30???
%D3DSIO_DCL          = 31???
%D3DSIO_POW          = 32???
%D3DSIO_CRS          = 33???
%D3DSIO_SGN          = 34???
%D3DSIO_ABS          = 35???
%D3DSIO_NRM          = 36???
%D3DSIO_SINCOS       = 37???
%D3DSIO_REP          = 38???
%D3DSIO_ENDREP       = 39???
%D3DSIO_IF           = 40???
%D3DSIO_IFC          = 41???
%D3DSIO_ELSE         = 42???
%D3DSIO_ENDIF        = 43???
%D3DSIO_BREAK        = 44???
%D3DSIO_BREAKC       = 45???
%D3DSIO_MOVA         = 46???
%D3DSIO_DEFB         = 47???
%D3DSIO_DEFI         = 48???

%D3DSIO_TEXCOORD     = 64???
%D3DSIO_TEXKILL      = 65???
%D3DSIO_TEX          = 66???
%D3DSIO_TEXBEM       = 67???
%D3DSIO_TEXBEML      = 68???
%D3DSIO_TEXREG2AR    = 69???
%D3DSIO_TEXREG2GB    = 70???
%D3DSIO_TEXM3x2PAD   = 71???
%D3DSIO_TEXM3x2TEX   = 72???
%D3DSIO_TEXM3x3PAD   = 73???
%D3DSIO_TEXM3x3TEX   = 74???
%D3DSIO_RESERVED0    = 75???
%D3DSIO_TEXM3x3SPEC  = 76???
%D3DSIO_TEXM3x3VSPEC = 77???
%D3DSIO_EXPP         = 78???
%D3DSIO_LOGP         = 79???
%D3DSIO_CND          = 80???
%D3DSIO_DEF          = 81???
%D3DSIO_TEXREG2RGB   = 82???
%D3DSIO_TEXDP3TEX    = 83???
%D3DSIO_TEXM3x2DEPTH = 84???
%D3DSIO_TEXDP3       = 85???
%D3DSIO_TEXM3x3      = 86???
%D3DSIO_TEXDEPTH     = 87???
%D3DSIO_CMP          = 88???
%D3DSIO_BEM          = 89???
%D3DSIO_DP2ADD       = 90???
%D3DSIO_DSX          = 91???
%D3DSIO_DSY          = 92???
%D3DSIO_TEXLDD       = 93???
%D3DSIO_SETP         = 94???
%D3DSIO_TEXLDL       = 95???
%D3DSIO_BREAKP       = 96???

%D3DSIO_PHASE        = &HFFFD???
%D3DSIO_COMMENT      = &HFFFE???
%D3DSIO_END          = &HFFFF???

%D3DSIO_FORCE_DWORD  = &H7FFFFFFF???  ' // force 32-bit size enum

'//---------------------------------------------------------------------
'// Use these constants with D3DSIO_SINCOS macro as SRC2, SRC3
'//
'#define D3DSINCOSCONST1 -1.5500992e-006f, -2.1701389e-005f,  0.0026041667f, 0.00026041668f
'#define D3DSINCOSCONST2 -0.020833334f, -0.12500000f, 1.0f, 0.50000000f

MACRO D3DSINCOSCONST1 = -1.5500992e-006!, -2.1701389e-005!,  0.0026041667!, 0.00026041668!
MACRO D3DSINCOSCONST2 = -0.020833334!, -0.12500000!, 1.0!, 0.50000000!

'//---------------------------------------------------------------------
'// Co-Issue Instruction Modifier - if set then this instruction is to be
'// issued in parallel with the previous instruction(s) for which this bit
'// is not set.
'//
%D3DSI_COISSUE          = &H40000000???

'//---------------------------------------------------------------------
'// Opcode specific controls

%D3DSP_OPCODESPECIFICCONTROL_MASK  = &H00ff0000???
%D3DSP_OPCODESPECIFICCONTROL_SHIFT = 16

'// ps_2_0 texld controls
%D3DSI_TEXLD_PROJECT = &H10000   ' (0x01 << D3DSP_OPCODESPECIFICCONTROL_SHIFT)
%D3DSI_TEXLD_BIAS    = &H20000   ' (0x02 << D3DSP_OPCODESPECIFICCONTROL_SHIFT)

'// Comparison for dynamic conditional instruction opcodes (i.e. if, breakc)
' enum _D3DSHADER_COMPARISON
%D3DSPC_RESERVED0 = 0  ' // 0 0 0
%D3DSPC_GT        = 1  ' // 0 0 1
%D3DSPC_EQ        = 2  ' // 0 1 0
%D3DSPC_GE        = 3  ' // 0 1 1
%D3DSPC_LT        = 4  ' // 1 0 0
%D3DSPC_NE        = 5  ' // 1 0 1
%D3DSPC_LE        = 6  ' // 1 1 0
%D3DSPC_RESERVED1 = 7  ' // 1 1 1

'// Comparison is part of instruction opcode token:
'#define D3DSHADER_COMPARISON_SHIFT D3DSP_OPCODESPECIFICCONTROL_SHIFT
'#define D3DSHADER_COMPARISON_MASK  (0x7<<D3DSHADER_COMPARISON_SHIFT)
%D3DSHADER_COMPARISON_SHIFT = %D3DSP_OPCODESPECIFICCONTROL_SHIFT
%D3DSHADER_COMPARISON_MASK = &H70000???

'//---------------------------------------------------------------------
'// Predication flags on instruction token
'#define D3DSHADER_INSTRUCTION_PREDICATED    (0x1 << 28)
%D3DSHADER_INSTRUCTION_PREDICATED = &H10000000???

'//---------------------------------------------------------------------
'// DCL Info Token Controls

'// For dcl info tokens requiring a semantic (usage + index)
%D3DSP_DCL_USAGE_SHIFT = 0
%D3DSP_DCL_USAGE_MASK  = &H0000000f???

%D3DSP_DCL_USAGEINDEX_SHIFT = 16
%D3DSP_DCL_USAGEINDEX_MASK  = &H000f0000???

'// DCL pixel shader sampler info token.
%D3DSP_TEXTURETYPE_SHIFT = 27
%D3DSP_TEXTURETYPE_MASK  = &H78000000???

' enum _D3DSAMPLER_TEXTURE_TYPE
' D3DSTT_UNKNOWN = 0<<D3DSP_TEXTURETYPE_SHIFT, // uninitialized value
' D3DSTT_2D      = 2<<D3DSP_TEXTURETYPE_SHIFT, // dcl_2d s# (for declaring a 2-D texture)
' D3DSTT_CUBE    = 3<<D3DSP_TEXTURETYPE_SHIFT, // dcl_cube s# (for declaring a cube texture)
' D3DSTT_VOLUME  = 4<<D3DSP_TEXTURETYPE_SHIFT, // dcl_volume s# (for declaring a volume texture)
' D3DSTT_FORCE_DWORD  = 0x7fffffff,      // force 32-bit size enum

%D3DSTT_UNKNOWN      = &H0            ' // uninitialized value
%D3DSTT_2D           = &H10000000???  ' // dcl_2d s# (for declaring a 2-D texture)
%D3DSTT_CUBE         = &H18000000???  ' // dcl_cube s# (for declaring a cube texture)
%D3DSTT_VOLUME       = &H20000000???  ' // dcl_volume s# (for declaring a volume texture)
%D3DSTT_FORCE_DWORD  = &H7FFFFFFF???  ' // force 32-bit size enum

'//---------------------------------------------------------------------
'// Parameter Token Bit Definitions
'//
%D3DSP_REGNUM_MASK       = &H000007FF???

'// destination parameter write mask
%D3DSP_WRITEMASK_0       = &H00010000??? ' // Component 0 (X;Red)
%D3DSP_WRITEMASK_1       = &H00020000??? ' // Component 1 (Y;Green)
%D3DSP_WRITEMASK_2       = &H00040000??? ' // Component 2 (Z;Blue)
%D3DSP_WRITEMASK_3       = &H00080000??? ' // Component 3 (W;Alpha)
%D3DSP_WRITEMASK_ALL     = &H000F0000??? ' // All Components

'// destination parameter modifiers
%D3DSP_DSTMOD_SHIFT      = 20
%D3DSP_DSTMOD_MASK       = &H00F00000

'// Bit masks for destination parameter modifiers
'#define    D3DSPDM_NONE                 (0<<D3DSP_DSTMOD_SHIFT) // nop
'#define    D3DSPDM_SATURATE             (1<<D3DSP_DSTMOD_SHIFT) // clamp to 0. to 1. range
'#define    D3DSPDM_PARTIALPRECISION     (2<<D3DSP_DSTMOD_SHIFT) // Partial precision hint
'#define    D3DSPDM_MSAMPCENTROID        (4<<D3DSP_DSTMOD_SHIFT) // Relevant to multisampling only:
'                                                                //      When the pixel center is not covered, sample
'                                                                //      attribute or compute gradients/LOD
'                                                                //      using multisample "centroid" location.
'                                                                //      "Centroid" is some location within the covered
'                                                                //      region of the pixel.

%D3DSPDM_NONE              = &H0???        ' // nop
%D3DSPDM_SATURATE          = &H100000???   ' // clamp to 0. to 1. range
%D3DSPDM_PARTIALPRECISION  = &H200000???   ' // Partial precision hint
%D3DSPDM_MSAMPCENTROID     = &H400000???   ' // Relevant to multisampling only:

'// destination parameter
%D3DSP_DSTSHIFT_SHIFT      = 24
%D3DSP_DSTSHIFT_MASK       = &H0F000000???

'// destination/source parameter register type
%D3DSP_REGTYPE_SHIFT       = 28
%D3DSP_REGTYPE_SHIFT2      = 8
%D3DSP_REGTYPE_MASK        = &H70000000???
%D3DSP_REGTYPE_MASK2       = &H00001800???

' enum _D3DSHADER_PARAM_REGISTER_TYPE
%D3DSPR_TEMP           =  0???  ' // Temporary Register File
%D3DSPR_INPUT          =  1???  ' // Input Register File
%D3DSPR_CONST          =  2???  ' // Constant Register File
%D3DSPR_ADDR           =  3???  ' // Address Register (VS)
%D3DSPR_TEXTURE        =  3???  ' // Texture Register File (PS)
%D3DSPR_RASTOUT        =  4???  ' // Rasterizer Register File
%D3DSPR_ATTROUT        =  5???  ' // Attribute Output Register File
%D3DSPR_TEXCRDOUT      =  6???  ' // Texture Coordinate Output Register File
%D3DSPR_OUTPUT         =  6???  ' // Output register file for VS3.0+
%D3DSPR_CONSTINT       =  7???  ' // Constant Integer Vector Register File
%D3DSPR_COLOROUT       =  8???  ' // Color Output Register File
%D3DSPR_DEPTHOUT       =  9???  ' // Depth Output Register File
%D3DSPR_SAMPLER        = 10???  ' // Sampler State Register File
%D3DSPR_CONST2         = 11???  ' // Constant Register File  2048 - 4095
%D3DSPR_CONST3         = 12???  ' // Constant Register File  4096 - 6143
%D3DSPR_CONST4         = 13???  ' // Constant Register File  6144 - 8191
%D3DSPR_CONSTBOOL      = 14???  ' // Constant Boolean register file
%D3DSPR_LOOP           = 15???  ' // Loop counter register file
%D3DSPR_TEMPFLOAT16    = 16???  ' // 16-bit float temp register file
%D3DSPR_MISCTYPE       = 17???  ' // Miscellaneous (single) registers.
%D3DSPR_LABEL          = 18???  ' // Label
%D3DSPR_PREDICATE      = 19???  ' // Predicate register
%D3DSPR_FORCE_DWORD    = &H7FFFFFFF???       '  // force 32-bit size enum

'// The miscellaneous register file (D3DSPR_MISCTYPES)
'// contains register types for which there is only ever one
'// register (i.e. the register # is not needed).
'// Rather than use up additional register types for such
'// registers, they are defined
'// as particular offsets into the misc. register file:
' enum _D3DSHADER_MISCTYPE_OFFSETS
%D3DSMO_POSITION    = 0???  ' // Input position x,y,z,rhw (PS)
%D3DSMO_FACE        = 1???  ' // Floating point primitive area (PS)

'// Register offsets in the Rasterizer Register File
'//
' enum _D3DVS_RASTOUT_OFFSETS
%D3DSRO_POSITION    = 0???
%D3DSRO_FOG         = 1???
%D3DSRO_POINT_SIZE  = 2???
%D3DSRO_FORCE_DWORD = &H7FFFFFFF???   '  // force 32-bit size enum

'// Source operand addressing modes

%D3DVS_ADDRESSMODE_SHIFT = 13
'#define D3DVS_ADDRESSMODE_MASK  (1 << D3DVS_ADDRESSMODE_SHIFT)
%D3DVS_ADDRESSMODE_MASK = &H2000???

' enum _D3DVS_ADDRESSMODE_TYPE
' D3DVS_ADDRMODE_ABSOLUTE  = (0 << D3DVS_ADDRESSMODE_SHIFT),
' D3DVS_ADDRMODE_RELATIVE  = (1 << D3DVS_ADDRESSMODE_SHIFT),
' D3DVS_ADDRMODE_FORCE_DWORD = 0x7fffffff, // force 32-bit size enum

%D3DVS_ADDRMODE_ABSOLUTE    = &H0???
%D3DVS_ADDRMODE_RELATIVE    = &H2000???
%D3DVS_ADDRMODE_FORCE_DWORD = &H7FFFFFFF???   ' // force 32-bit size enum

%D3DSHADER_ADDRESSMODE_SHIFT = 13
'#define D3DSHADER_ADDRESSMODE_MASK  (1 << D3DSHADER_ADDRESSMODE_SHIFT)
%D3DSHADER_ADDRESSMODE_MASK = &H2000???

' enum _D3DSHADER_ADDRESSMODE_TYPE
' D3DSHADER_ADDRMODE_ABSOLUTE  = (0 << D3DSHADER_ADDRESSMODE_SHIFT),
' D3DSHADER_ADDRMODE_RELATIVE  = (1 << D3DSHADER_ADDRESSMODE_SHIFT),
' D3DSHADER_ADDRMODE_FORCE_DWORD = 0x7fffffff, // force 32-bit size enum

%D3DSHADER_ADDRMODE_ABSOLUTE    = &H0???
%D3DSHADER_ADDRMODE_RELATIVE    = &H2000???
%D3DSHADER_ADDRMODE_FORCE_DWORD = &H7FFFFFFF???   ' // force 32-bit size enum

'// Source operand swizzle definitions
'//
%D3DVS_SWIZZLE_SHIFT    = 16
%D3DVS_SWIZZLE_MASK     = &H00FF0000???

'// The following bits define where to take component X from:

%D3DVS_X_X = &H0???       ' (0 << D3DVS_SWIZZLE_SHIFT)
%D3DVS_X_Y = &H10000???   ' (1 << D3DVS_SWIZZLE_SHIFT)
%D3DVS_X_Z = &H20000???   ' (2 << D3DVS_SWIZZLE_SHIFT)
%D3DVS_X_W = &H30000???   ' (3 << D3DVS_SWIZZLE_SHIFT)

'// The following bits define where to take component Y from:

%D3DVS_Y_X = &H0???       ' (0 << (D3DVS_SWIZZLE_SHIFT + 2))
%D3DVS_Y_Y = &H40000???   ' (1 << (D3DVS_SWIZZLE_SHIFT + 2))
%D3DVS_Y_Z = &H80000???   ' (2 << (D3DVS_SWIZZLE_SHIFT + 2))
%D3DVS_Y_W = &HC0000???   ' (3 << (D3DVS_SWIZZLE_SHIFT + 2))

'// The following bits define where to take component Z from:

%D3DVS_Z_X = &H0???        ' (0 << (D3DVS_SWIZZLE_SHIFT + 4))
%D3DVS_Z_Y = &H100000???   ' (1 << (D3DVS_SWIZZLE_SHIFT + 4))
%D3DVS_Z_Z = &H200000???   ' (2 << (D3DVS_SWIZZLE_SHIFT + 4))
%D3DVS_Z_W = &H300000???   ' (3 << (D3DVS_SWIZZLE_SHIFT + 4))

'// The following bits define where to take component W from:

%D3DVS_W_X = &H0???        ' (0 << (D3DVS_SWIZZLE_SHIFT + 6))
%D3DVS_W_Y = &H400000???   ' (1 << (D3DVS_SWIZZLE_SHIFT + 6))
%D3DVS_W_Z = &H800000???   ' (2 << (D3DVS_SWIZZLE_SHIFT + 6))
%D3DVS_W_W = &HC00000???   ' (3 << (D3DVS_SWIZZLE_SHIFT + 6))

'// Value when there is no swizzle (X is taken from X, Y is taken from Y,
'// Z is taken from Z, W is taken from W
'//
%D3DVS_NOSWIZZLE = %D3DVS_X_X OR %D3DVS_Y_Y OR %D3DVS_Z_Z OR %D3DVS_W_W

'// source parameter swizzle
%D3DSP_SWIZZLE_SHIFT    = 16
%D3DSP_SWIZZLE_MASK     = &H00FF0000???

'#define D3DSP_NOSWIZZLE \
'    ( (0 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
'      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
'      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
'      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )

%D3DSP_NOSWIZZLE = &H0??? OR &H40000??? OR &H200000??? OR &HC00000???

'// pixel-shader swizzle ops
'#define D3DSP_REPLICATERED \
'    ( (0 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
'      (0 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
'      (0 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
'      (0 << (D3DSP_SWIZZLE_SHIFT + 6)) )

%D3DSP_REPLICATERED = &H0???

'#define D3DSP_REPLICATEGREEN \
'    ( (1 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
'      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
'      (1 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
'      (1 << (D3DSP_SWIZZLE_SHIFT + 6)) )

%D3DSP_REPLICATEGREEN = &H10000??? OR &H40000??? OR &H100000??? OR &H400000???

'#define D3DSP_REPLICATEBLUE \
'    ( (2 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
'      (2 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
'      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
'      (2 << (D3DSP_SWIZZLE_SHIFT + 6)) )

%D3DSP_REPLICATEBLUE  = &H20000??? OR &H80000??? OR &H200000??? OR &H800000???

'#define D3DSP_REPLICATEALPHA \
'    ( (3 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
'      (3 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
'      (3 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
'      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )

%D3DSP_REPLICATEALPHA  = &H30000??? OR &HC0000??? OR &H300000??? OR &HC00000???

'// source parameter modifiers
%D3DSP_SRCMOD_SHIFT     = 24
%D3DSP_SRCMOD_MASK      = &H0F000000???

' enum _D3DSHADER_PARAM_SRCMOD_TYPE
'D3DSPSM_NONE    = 0<<D3DSP_SRCMOD_SHIFT, // nop
'D3DSPSM_NEG     = 1<<D3DSP_SRCMOD_SHIFT, // negate
'D3DSPSM_BIAS    = 2<<D3DSP_SRCMOD_SHIFT, // bias
'D3DSPSM_BIASNEG = 3<<D3DSP_SRCMOD_SHIFT, // bias and negate
'D3DSPSM_SIGN    = 4<<D3DSP_SRCMOD_SHIFT, // sign
'D3DSPSM_SIGNNEG = 5<<D3DSP_SRCMOD_SHIFT, // sign and negate
'D3DSPSM_COMP    = 6<<D3DSP_SRCMOD_SHIFT, // complement
'D3DSPSM_X2      = 7<<D3DSP_SRCMOD_SHIFT, // *2
'D3DSPSM_X2NEG   = 8<<D3DSP_SRCMOD_SHIFT, // *2 and negate
'D3DSPSM_DZ      = 9<<D3DSP_SRCMOD_SHIFT, // divide through by z component
'D3DSPSM_DW      = 10<<D3DSP_SRCMOD_SHIFT, // divide through by w component
'D3DSPSM_ABS     = 11<<D3DSP_SRCMOD_SHIFT, // abs()
'D3DSPSM_ABSNEG  = 12<<D3DSP_SRCMOD_SHIFT, // -abs()
'D3DSPSM_NOT     = 13<<D3DSP_SRCMOD_SHIFT, // for predicate register: "!p0"
'D3DSPSM_FORCE_DWORD = 0x7fffffff,        // force 32-bit size enum

%D3DSPSM_NONE        = &H0???          ' // nop
%D3DSPSM_NEG         = &H01000000???   ' // negate
%D3DSPSM_BIAS        = &H02000000???   ' // bias
%D3DSPSM_BIASNEG     = &H03000000???   ' // bias and negate
%D3DSPSM_SIGN        = &H04000000???   ' // sign
%D3DSPSM_SIGNNEG     = &H05000000???   ' // sign and negate
%D3DSPSM_COMP        = &H06000000???   ' // complement
%D3DSPSM_X2          = &H07000000???   ' // *2
%D3DSPSM_X2NEG       = &H08000000???   ' // *2 and negate
%D3DSPSM_DZ          = &H09000000???   ' // divide through by z component
%D3DSPSM_DW          = &H0A000000???   ' // divide through by w component
%D3DSPSM_ABS         = &H0B000000???   ' // abs()
%D3DSPSM_ABSNEG      = &H0C000000???   ' // -abs()
%D3DSPSM_NOT         = &H0D000000???   ' // for predicate register: "!p0"
%D3DSPSM_FORCE_DWORD = &H7FFFFFFF???   ' // force 32-bit size enum

'// pixel shader version token
'#define D3DPS_VERSION(_Major,_Minor) (0xFFFF0000|((_Major)<<8)|(_Minor))

FUNCTION D3DPS_VERSION (BYVAL Major AS DWORD, BYVAL Minor AS DWORD) AS DWORD
   SHIFT LEFT Major, 8
   FUNCTION = &HFFFF0000??? OR Major OR Minor
END FUNCTION

'// vertex shader version token
'#define D3DVS_VERSION(_Major,_Minor) (0xFFFE0000|((_Major)<<8)|(_Minor))

FUNCTION D3DVS_VERSION (BYVAL Major AS DWORD, BYVAL Minor AS DWORD) AS DWORD
   SHIFT LEFT Major, 8
   FUNCTION = &HFFFE0000??? OR Major OR Minor
END FUNCTION

'// extract major/minor from version cap
'#define D3DSHADER_VERSION_MAJOR(_Version) (((_Version)>>8)&0xFF)
'#define D3DSHADER_VERSION_MINOR(_Version) (((_Version)>>0)&0xFF)

FUNCTION D3DSHADER_VERSION_MAJOR (BYVAL Version AS DWORD) AS DWORD
   SHIFT RIGHT Version, 8
   FUNCTION = Version AND &HFF
END FUNCTION

FUNCTION D3DSHADER_VERSION_MINOR (BYVAL Version AS DWORD) AS DWORD
   FUNCTION = Version AND &HFF
END FUNCTION

'// destination/source parameter register type
'#define D3DSI_COMMENTSIZE_SHIFT     16
'#define D3DSI_COMMENTSIZE_MASK      0x7FFF0000
'#define D3DSHADER_COMMENT(_DWordSize) \
'    ((((_DWordSize)<<D3DSI_COMMENTSIZE_SHIFT)&D3DSI_COMMENTSIZE_MASK)|D3DSIO_COMMENT)

%D3DSI_COMMENTSIZE_SHIFT    = 16
%D3DSI_COMMENTSIZE_MASK     = &H7FFF0000???

'// pixel/vertex shader end token
'#define D3DPS_END()  0x0000FFFF
'#define D3DVS_END()  0x0000FFFF

%D3DPS_END = &H0000FFFF???
%D3DVS_END = &H0000FFFF???

'//---------------------------------------------------------------------

'// High order surfaces
'//
' enum D3DBASISTYPE
%D3DBASIS_BEZIER      = 0???
%D3DBASIS_BSPLINE     = 1???
%D3DBASIS_CATMULL_ROM = 2???  ' /* In D3D8 this used to be D3DBASIS_INTERPOLATE */
%D3DBASIS_FORCE_DWORD = &H7FFFFFFF???

' enum D3DDEGREETYPE
%D3DDEGREE_LINEAR      = 1???
%D3DDEGREE_QUADRATIC   = 2???
%D3DDEGREE_CUBIC       = 3???
%D3DDEGREE_QUINTIC     = 5???
%D3DDEGREE_FORCE_DWORD = &H7FFFFFFF???

' enum D3DPATCHEDGESTYLE
%D3DPATCHEDGE_DISCRETE    = 0???
%D3DPATCHEDGE_CONTINUOUS  = 1???
%D3DPATCHEDGE_FORCE_DWORD = &H7FFFFFFF???

' enum _D3DSTATEBLOCKTYPE
%D3DSBT_ALL           = 1???  ' // capture all state
%D3DSBT_PIXELSTATE    = 2???  ' // capture pixel state
%D3DSBT_VERTEXSTATE   = 3???  ' // capture vertex state
%D3DSBT_FORCE_DWORD   = &H7FFFFFFF???

'// The D3DVERTEXBLENDFLAGS type is used with D3DRS_VERTEXBLEND state.
'//
' enum _D3DVERTEXBLENDFLAGS
%D3DVBF_DISABLE  = 0???    ' // Disable vertex blending
%D3DVBF_1WEIGHTS = 1???    ' // 2 matrix blending
%D3DVBF_2WEIGHTS = 2???    ' // 3 matrix blending
%D3DVBF_3WEIGHTS = 3???    ' // 4 matrix blending
%D3DVBF_TWEENING = 255???  ' // blending using D3DRS_TWEENFACTOR
%D3DVBF_0WEIGHTS = 256???  ' // one matrix is used with weight 1.0
%D3DVBF_FORCE_DWORD = &H7FFFFFFF???  ' // force 32-bit size enum

' enum _D3DTEXTURETRANSFORMFLAGS
%D3DTTFF_DISABLE         = 0???   ' // texture coordinates are passed directly
%D3DTTFF_COUNT1          = 1???   ' // rasterizer should expect 1-D texture coords
%D3DTTFF_COUNT2          = 2???   ' // rasterizer should expect 2-D texture coords
%D3DTTFF_COUNT3          = 3???   ' // rasterizer should expect 3-D texture coords
%D3DTTFF_COUNT4          = 4???   ' // rasterizer should expect 4-D texture coords
%D3DTTFF_PROJECTED       = 256??? ' // texcoords to be divided by COUNTth element
%D3DTTFF_FORCE_DWORD     = &H7FFFFFFF???

'// Macros to set texture coordinate format bits in the FVF id

%D3DFVF_TEXTUREFORMAT2 = 0        ' // Two floating point values
%D3DFVF_TEXTUREFORMAT1 = 3        ' // One floating point value
%D3DFVF_TEXTUREFORMAT3 = 1        ' // Three floating point values
%D3DFVF_TEXTUREFORMAT4 = 2        ' // Four floating point values

'#define D3DFVF_TEXCOORDSIZE3(CoordIndex) (D3DFVF_TEXTUREFORMAT3 << (CoordIndex*2 + 16))
'#define D3DFVF_TEXCOORDSIZE2(CoordIndex) (D3DFVF_TEXTUREFORMAT2)
'#define D3DFVF_TEXCOORDSIZE4(CoordIndex) (D3DFVF_TEXTUREFORMAT4 << (CoordIndex*2 + 16))
'#define D3DFVF_TEXCOORDSIZE1(CoordIndex) (D3DFVF_TEXTUREFORMAT1 << (CoordIndex*2 + 16))

%D3DFVF_TEXCOORDSIZE1_0 = &H00030000???
%D3DFVF_TEXCOORDSIZE1_1 = &H000C0000???
%D3DFVF_TEXCOORDSIZE1_2 = &H00300000???
%D3DFVF_TEXCOORDSIZE1_3 = &H00C00000???

%D3DFVF_TEXCOORDSIZE2_0 = &H0???
%D3DFVF_TEXCOORDSIZE2_1 = &H0???
%D3DFVF_TEXCOORDSIZE2_2 = &H0???
%D3DFVF_TEXCOORDSIZE2_3 = &H0???

%D3DFVF_TEXCOORDSIZE3_0 = &H00010000???
%D3DFVF_TEXCOORDSIZE3_1 = &H00040000???
%D3DFVF_TEXCOORDSIZE3_2 = &H00100000???
%D3DFVF_TEXCOORDSIZE3_3 = &H00400000???

%D3DFVF_TEXCOORDSIZE4_0 = &H00020000???
%D3DFVF_TEXCOORDSIZE4_1 = &H00080000???
%D3DFVF_TEXCOORDSIZE4_2 = &H00200000???
%D3DFVF_TEXCOORDSIZE4_3 = &H00800000???

'//---------------------------------------------------------------------

'/* Direct3D9 Device types */
' enum D3DDEVTYPE
%D3DDEVTYPE_HAL         = 1???
%D3DDEVTYPE_REF         = 2???
%D3DDEVTYPE_SW          = 3???

%D3DDEVTYPE_NULLREF     = 4???

%D3DDEVTYPE_FORCE_DWORD  = &H7FFFFFFF???

'/* Multi-Sample buffer types */
' enum _D3DMULTISAMPLE_TYPE
%D3DMULTISAMPLE_NONE            =  0???
%D3DMULTISAMPLE_NONMASKABLE     =  1???
%D3DMULTISAMPLE_2_SAMPLES       =  2???
%D3DMULTISAMPLE_3_SAMPLES       =  3???
%D3DMULTISAMPLE_4_SAMPLES       =  4???
%D3DMULTISAMPLE_5_SAMPLES       =  5???
%D3DMULTISAMPLE_6_SAMPLES       =  6???
%D3DMULTISAMPLE_7_SAMPLES       =  7???
%D3DMULTISAMPLE_8_SAMPLES       =  8???
%D3DMULTISAMPLE_9_SAMPLES       =  9???
%D3DMULTISAMPLE_10_SAMPLES      = 10???
%D3DMULTISAMPLE_11_SAMPLES      = 11???
%D3DMULTISAMPLE_12_SAMPLES      = 12???
%D3DMULTISAMPLE_13_SAMPLES      = 13???
%D3DMULTISAMPLE_14_SAMPLES      = 14???
%D3DMULTISAMPLE_15_SAMPLES      = 15???
%D3DMULTISAMPLE_16_SAMPLES      = 16???

%D3DMULTISAMPLE_FORCE_DWORD     = &H7FFFFFFF???

'/* Formats
' * Most of these names have the following convention:
' *      A = Alpha
' *      R = Red
' *      G = Green
' *      B = Blue
' *      X = Unused Bits
' *      P = Palette
' *      L = Luminance
' *      U = dU coordinate for BumpMap
' *      V = dV coordinate for BumpMap
' *      S = Stencil
' *      D = Depth (e.g. Z or W buffer)
' *      C = Computed from other channels (typically on certain read operations)
' *
' *      Further, the order of the pieces are from MSB first; hence
' *      D3DFMT_A8L8 indicates that the high byte of this two byte
' *      format is alpha.
' *
' *      D3DFMT_D16_LOCKABLE indicates:
' *           - An integer 16-bit value.
' *           - An app-lockable surface.
' *
' *      D3DFMT_D32F_LOCKABLE indicates:
' *           - An IEEE 754 floating-point value.
' *           - An app-lockable surface.
' *
' *      All Depth/Stencil formats except D3DFMT_D16_LOCKABLE and D3DFMT_D32F_LOCKABLE indicate:
' *          - no particular bit ordering per pixel, and
' *          - are not app lockable, and
' *          - the driver is allowed to consume more than the indicated
' *            number of bits per Depth channel (but not Stencil channel).
' */
'#ifndef MAKEFOURCC
'    #define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
'                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |       \
'                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
'#endif /* defined(MAKEFOURCC) */

#IF NOT %DEF(%MAKEFOURCC_DEFINED)
%MAKEFOURCC_DEFINED = 1
FUNCTION MAKEFOURCC (BYVAL st0 AS STRING, BYVAL st1 AS STRING, BYVAL st2 AS STRING, BYVAL st3 AS STRING) AS DWORD
   LOCAL ch0 AS DWORD, ch1 AS DWORD, ch2 AS DWORD, ch3 AS DWORD
   ch0 = ASC(st0)
   ch1 = ASC(st1)
   ch2 = ASC(st2)
   ch3 = ASC(st3)
   SHIFT LEFT ch1, 8
   SHIFT LEFT ch2, 16
   SHIFT LEFT ch3, 24
   FUNCTION = ch0 OR ch1 OR ch2 OR ch3
END FUNCTION
#ENDIF

' enum _D3DFORMAT
%D3DFMT_UNKNOWN              =  0???

%D3DFMT_R8G8B8               = 20???
%D3DFMT_A8R8G8B8             = 21???
%D3DFMT_X8R8G8B8             = 22???
%D3DFMT_R5G6B5               = 23???
%D3DFMT_X1R5G5B5             = 24???
%D3DFMT_A1R5G5B5             = 25???
%D3DFMT_A4R4G4B4             = 26???
%D3DFMT_R3G3B2               = 27???
%D3DFMT_A8                   = 28???
%D3DFMT_A8R3G3B2             = 29???
%D3DFMT_X4R4G4B4             = 30???
%D3DFMT_A2B10G10R10          = 31???
%D3DFMT_A8B8G8R8             = 32???
%D3DFMT_X8B8G8R8             = 33???
%D3DFMT_G16R16               = 34???
%D3DFMT_A2R10G10B10          = 35???
%D3DFMT_A16B16G16R16         = 36???

%D3DFMT_A8P8                 = 40???
%D3DFMT_P8                   = 41???

%D3DFMT_L8                   = 50???
%D3DFMT_A8L8                 = 51???
%D3DFMT_A4L4                 = 52???

%D3DFMT_V8U8                 = 60???
%D3DFMT_L6V5U5               = 61???
%D3DFMT_X8L8V8U8             = 62???
%D3DFMT_Q8W8V8U8             = 63???
%D3DFMT_V16U16               = 64???
%D3DFMT_A2W10V10U10          = 67???

'%D3DFMT_UYVY                 = MAKEFOURCC('U', 'Y', 'V', 'Y'),
'%D3DFMT_R8G8_B8G8            = MAKEFOURCC('R', 'G', 'B', 'G'),
'%D3DFMT_YUY2                 = MAKEFOURCC('Y', 'U', 'Y', '2'),
'%D3DFMT_G8R8_G8B8            = MAKEFOURCC('G', 'R', 'G', 'B'),
'%D3DFMT_DXT1                 = MAKEFOURCC('D', 'X', 'T', '1'),
'%D3DFMT_DXT2                 = MAKEFOURCC('D', 'X', 'T', '2'),
'%D3DFMT_DXT3                 = MAKEFOURCC('D', 'X', 'T', '3'),
'%D3DFMT_DXT4                 = MAKEFOURCC('D', 'X', 'T', '4'),
'%D3DFMT_DXT5                 = MAKEFOURCC('D', 'X', 'T', '5'),

%D3DFMT_UYVY                 = &H59565955???
%D3DFMT_R8G8_B8G8            = &H47424752???
%D3DFMT_YUY2                 = &H32595559???
%D3DFMT_G8R8_G8B8            = &H42475247???
%D3DFMT_DXT1                 = &H31545844???
%D3DFMT_DXT2                 = &H32545844???
%D3DFMT_DXT3                 = &H33545844???
%D3DFMT_DXT4                 = &H34545844???
%D3DFMT_DXT5                 = &H35545844???

%D3DFMT_D16_LOCKABLE         = 70???
%D3DFMT_D32                  = 71???
%D3DFMT_D15S1                = 73???
%D3DFMT_D24S8                = 75???
%D3DFMT_D24X8                = 77???
%D3DFMT_D24X4S4              = 79???
%D3DFMT_D16                  = 80???

%D3DFMT_D32F_LOCKABLE        = 82???
%D3DFMT_D24FS8               = 83???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
   ' /* Z-Stencil formats valid for CPU access */
%D3DFMT_D32_LOCKABLE         = 84???
%D3DFMT_S8_LOCKABLE          = 85???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

%D3DFMT_L16                  = 81???

%D3DFMT_VERTEXDATA           = 100???
%D3DFMT_INDEX16              = 101???
%D3DFMT_INDEX32              = 102???

%D3DFMT_Q16W16V16U16         = 110???

'%D3DFMT_MULTI2_ARGB8         = MAKEFOURCC('M','E','T','1'),
%D3DFMT_MULTI2_ARGB8         = &H3154454D???

' // Floating point surface formats

' // s10e5 formats (16-bits per channel)
%D3DFMT_R16F                 = 111???
%D3DFMT_G16R16F              = 112???
%D3DFMT_A16B16G16R16F        = 113???

' // IEEE s23e8 formats (32-bits per channel)
%D3DFMT_R32F                 = 114???
%D3DFMT_G32R32F              = 115???
%D3DFMT_A32B32G32R32F        = 116???

%D3DFMT_CxV8U8               = 117???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
   ' // Monochrome 1 bit per pixel format
%D3DFMT_A1                   = 118???
   ' // 2.8 biased fixed point
%D3DFMT_A2B10G10R10_XR_BIAS  = 119???
   ' // Binary format indicating that the data has no inherent type
%D3DFMT_BINARYBUFFER         = 199???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */


%D3DFMT_FORCE_DWORD          = &H7FFFFFFF???

'/* Display Modes */
' // Size = 16 bytes
TYPE D3DDISPLAYMODE DWORD
   Width       AS DWORD
   Height      AS DWORD
   RefreshRate AS DWORD
   Format      AS DWORD
END TYPE

'/* Creation Parameters */
' // Size = 16 bytes
TYPE D3DDEVICE_CREATION_PARAMETERS DWORD
   AdapterOrdinal AS DWORD
   DeviceType     AS DWORD
   hFocusWindow   AS DWORD
   BehaviorFlags  AS DWORD
END TYPE

'/* SwapEffects */
%D3DSWAPEFFECT_DISCARD           = 1???
%D3DSWAPEFFECT_FLIP              = 2???
%D3DSWAPEFFECT_COPY              = 3???
%D3DSWAPEFFECT_OVERLAY           = 4???
%D3DSWAPEFFECT_FLIPEX            = 5???

%D3DSWAPEFFECT_FORCE_DWORD       = &H7FFFFFFF???

'/* Pool types */
%D3DPOOL_DEFAULT                 = 0???
%D3DPOOL_MANAGED                 = 1???
%D3DPOOL_SYSTEMMEM               = 2???
%D3DPOOL_SCRATCH                 = 3???

%D3DPOOL_FORCE_DWORD             = &H7FFFFFFF???

'/* RefreshRate pre-defines */
%D3DPRESENT_RATE_DEFAULT         = &H00000000???


'/* Resize Optional Parameters */
' // Size = 56 bytes
TYPE D3DPRESENT_PARAMETERS DWORD
   BackBufferWidth            AS DWORD
   BackBufferHeight           AS DWORD
   BackBufferFormat           AS DWORD
   BackBufferCount            AS DWORD
   MultiSampleType            AS DWORD
   MultiSampleQuality         AS DWORD
   SwapEffect                 AS DWORD
   hDeviceWindow              AS DWORD
   Windowed                   AS LONG
   EnableAutoDepthStencil     AS LONG
   AutoDepthStencilFormat     AS DWORD
   Flags                      AS DWORD
   ' /* FullScreen_RefreshRateInHz must be zero for Windowed mode */
   FullScreen_RefreshRateInHz AS DWORD
   PresentationInterval       AS DWORD
END TYPE

'// Values for D3DPRESENT_PARAMETERS.Flags

%D3DPRESENTFLAG_LOCKABLE_BACKBUFFER             = &H00000001???
%D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL            = &H00000002???
%D3DPRESENTFLAG_DEVICECLIP                      = &H00000004???
%D3DPRESENTFLAG_VIDEO                           = &H00000010???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DPRESENTFLAG_NOAUTOROTATE                    = &H00000020???
%D3DPRESENTFLAG_UNPRUNEDMODE                    = &H00000040???
%D3DPRESENTFLAG_OVERLAY_LIMITEDRGB              = &H00000080???
%D3DPRESENTFLAG_OVERLAY_YCbCr_BT709             = &H00000100???
%D3DPRESENTFLAG_OVERLAY_YCbCr_xvYCC             = &H00000200???
%D3DPRESENTFLAG_RESTRICTED_CONTENT              = &H00000400???
%D3DPRESENTFLAG_RESTRICT_SHARED_RESOURCE_DRIVER = &H00000800???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'/* Gamma Ramp: Same as DX7 */

' // Size = 15376 bytes
TYPE D3DGAMMARAMP WORD
   red  (255) AS WORD   ' WORD[256]
   green(255) AS WORD   ' WORD[256]
   blue (255) AS WORD   ' WORD[256]
END TYPE

' /* Back buffer types */
' enum D3DBACKBUFFER_TYPE
%D3DBACKBUFFER_TYPE_MONO         = 0???
%D3DBACKBUFFER_TYPE_LEFT         = 1???
%D3DBACKBUFFER_TYPE_RIGHT        = 2???

%D3DBACKBUFFER_TYPE_FORCE_DWORD  = &H7FFFFFFF???

' /* Types */
' enum _D3DRESOURCETYPE
%D3DRTYPE_SURFACE                =  1???
%D3DRTYPE_VOLUME                 =  2???
%D3DRTYPE_TEXTURE                =  3???
%D3DRTYPE_VOLUMETEXTURE          =  4???
%D3DRTYPE_CUBETEXTURE            =  5???
%D3DRTYPE_VERTEXBUFFER           =  6???
%D3DRTYPE_INDEXBUFFER            =  7???

%D3DRTYPE_FORCE_DWORD            = &H7FFFFFFF???

' /* Usages */
%D3DUSAGE_RENDERTARGET       = &H00000001???
%D3DUSAGE_DEPTHSTENCIL       = &H00000002???
%D3DUSAGE_DYNAMIC            = &H00000200???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DUSAGE_NONSECURE          = &H00800000???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'// When passed to CheckDeviceFormat, D3DUSAGE_AUTOGENMIPMAP may return
'// D3DOK_NOAUTOGEN if the device doesn't support autogeneration for that format.
'// D3DOK_NOAUTOGEN is a success code, not a failure code... the SUCCEEDED and FAILED macros
'// will return true and false respectively for this code.
%D3DUSAGE_AUTOGENMIPMAP      = &H00000400???
%D3DUSAGE_DMAP               = &H00004000???

'// The following usages are valid only for querying CheckDeviceFormat
%D3DUSAGE_QUERY_LEGACYBUMPMAP             = &H00008000???
%D3DUSAGE_QUERY_SRGBREAD                  = &H00010000???
%D3DUSAGE_QUERY_FILTER                    = &H00020000???
%D3DUSAGE_QUERY_SRGBWRITE                 = &H00040000???
%D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING  = &H00080000???
%D3DUSAGE_QUERY_VERTEXTEXTURE             = &H00100000???
%D3DUSAGE_QUERY_WRAPANDMIP                = &H00200000???

'/* Usages for Vertex/Index buffers */
%D3DUSAGE_WRITEONLY           = &H00000008???
%D3DUSAGE_SOFTWAREPROCESSING  = &H00000010???
%D3DUSAGE_DONOTCLIP           = &H00000020???
%D3DUSAGE_POINTS              = &H00000040???
%D3DUSAGE_RTPATCHES           = &H00000080???
%D3DUSAGE_NPATCHES            = &H00000100???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DUSAGE_TEXTAPI                         = &H10000000???
%D3DUSAGE_RESTRICTED_CONTENT              = &H00000800???
%D3DUSAGE_RESTRICT_SHARED_RESOURCE        = &H00002000???
%D3DUSAGE_RESTRICT_SHARED_RESOURCE_DRIVER = &H00001000???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'/* CubeMap Face identifiers */
' enum D3DCUBEMAP_FACES
%D3DCUBEMAP_FACE_POSITIVE_X     = 0???
%D3DCUBEMAP_FACE_NEGATIVE_X     = 1???
%D3DCUBEMAP_FACE_POSITIVE_Y     = 2???
%D3DCUBEMAP_FACE_NEGATIVE_Y     = 3???
%D3DCUBEMAP_FACE_POSITIVE_Z     = 4???
%D3DCUBEMAP_FACE_NEGATIVE_Z     = 5???

%D3DCUBEMAP_FACE_FORCE_DWORD    = &H7FFFFFFF???

'/* Lock flags */

%D3DLOCK_READONLY           = &H00000010???
%D3DLOCK_DISCARD            = &H00002000???
%D3DLOCK_NOOVERWRITE        = &H00001000???
%D3DLOCK_NOSYSLOCK          = &H00000800???
%D3DLOCK_DONOTWAIT          = &H00004000???

%D3DLOCK_NO_DIRTY_UPDATE    = &H00008000???

'/* Vertex Buffer Description */
' // Size = 24 bytes
TYPE D3DVERTEXBUFFER_DESC DWORD
   Format AS DWORD
   Type   AS DWORD
   Usage  AS DWORD
   Pool   AS DWORD
   Size   AS DWORD
   FVF    AS DWORD
END TYPE

'/* Index Buffer Description */
' // Size = 20 bytes
TYPE D3DINDEXBUFFER_DESC DWORD
   Format AS DWORD
   Type   AS DWORD
   Usage  AS DWORD
   Pool   AS DWORD
   Size   AS DWORD
END TYPE

'/* Surface Description */
' // Size = 32 bytes
TYPE D3DSURFACE_DESC DWORD
   Format             AS DWORD
   Type               AS DWORD
   Usage              AS DWORD
   Pool               AS DWORD
   MultiSampleType    AS DWORD
   MultiSampleQuality AS DWORD
   Width              AS DWORD
   Height             AS DWORD
END TYPE

' // Size = 28 bytes
TYPE D3DVOLUME_DESC DWORD
   Format AS DWORD
   Type   AS DWORD
   Usage  AS DWORD
   Pool   AS DWORD
   Width  AS DWORD
   Height AS DWORD
   Depth  AS DWORD
END TYPE

'/* Structure for LockRect */
' // Size = 8 bytes
TYPE D3DLOCKED_RECT DWORD
   Pitch AS LONG
   pBits AS DWORD
END TYPE

'/* Structures for LockBox */
' // Size = 24 bytes
TYPE D3DBOX DWORD
   Left   AS DWORD
   Top    AS DWORD
   Right  AS DWORD
   Bottom AS DWORD
   Front  AS DWORD
   Back   AS DWORD
END TYPE

' // Size = 12 bytes
TYPE D3DLOCKED_BOX DWORD
   RowPitch   AS LONG
   SlicePitch AS LONG
   pBits      AS DWORD
END TYPE

'/* Structures for LockRange */
' // Size = 8 bytes
TYPE D3DRANGE DWORD
   Offset AS DWORD
   Size   AS DWORD
END TYPE

'/* Structures for high order primitives */
' // Size = 28 bytes
TYPE D3DRECTPATCH_INFO DWORD
   StartVertexOffsetWidth  AS DWORD
   StartVertexOffsetHeight AS DWORD
   Width                   AS DWORD
   Height                  AS DWORD
   Stride                  AS DWORD
   Basis                   AS DWORD
   Degree                  AS DWORD
END TYPE

' // Size = 16 bytes
TYPE D3DTRIPATCH_INFO DWORD
   StartVertexOffset AS DWORD
   NumVertices       AS DWORD
   Basis             AS DWORD
   Degree            AS DWORD
END TYPE

'/* Adapter Identifier */

%MAX_DEVICE_IDENTIFIER_STRING      = 512

#IF NOT %DEF(%LARGE_INTEGER_DEFINED)
%LARGE_INTEGER_DEFINED = 1
' // Size = 8 bytes
TYPE LARGE_INTEGER_STRUCT DWORD
   LowPart  AS DWORD   ' DWORD
   HighPart AS LONG    ' LONG
END TYPE
UNION LARGE_INTEGER QWORD
   LARGE_INTEGER_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

' // Size = 1100 bytes
TYPE D3DADAPTER_IDENTIFIER9 DWORD
   Driver           AS ASCIIZ * %MAX_DEVICE_IDENTIFIER_STRING   ' char Driver[MAX_DEVICE_IDENTIFIER_STRING]
   Description      AS ASCIIZ * %MAX_DEVICE_IDENTIFIER_STRING   ' char Description[MAX_DEVICE_IDENTIFIER_STRING]
   DeviceName       AS ASCIIZ * 32                              ' char[32] /* Device name for GDI (ex. \\.\DISPLAY1) */
   DriverVersion    AS QUAD                                     ' LARGE_INTEGER /* Defined for 32 bit components */
   VendorId         AS DWORD                                    ' DWORD
   DeviceId         AS DWORD                                    ' DWORD
   SubSysId         AS DWORD                                    ' DWORD
   Revision         AS DWORD                                    ' DWORD
   DeviceIdentifier AS GUID                                     ' GUID
   WHQLLevel        AS DWORD                                    ' DWORD
END TYPE

'/* Raster Status structure returned by GetRasterStatus */
' // Size = 8 bytes
TYPE D3DRASTER_STATUS DWORD
   InVBlank AS LONG
   ScanLine AS DWORD
END TYPE


'/* Debug monitor tokens (DEBUG only)

'   Note that if D3DRS_DEBUGMONITORTOKEN is set, the call is treated as
'   passing a token to the debug monitor.  For example, if, after passing
'   D3DDMT_ENABLE/DISABLE to D3DRS_DEBUGMONITORTOKEN other token values
'   are passed in, the enabled/disabled state of the debug
'   monitor will still persist.

'   The debug monitor defaults to enabled.

'   Calling GetRenderState on D3DRS_DEBUGMONITORTOKEN is not of any use.
'*/
' enum _D3DDEBUGMONITORTOKENS
%D3DDMT_ENABLE            = 0???   ' // enable debug monitor
%D3DDMT_DISABLE           = 1???   ' // disable debug monitor
%D3DDMT_FORCE_DWORD       = &H7FFFFFFF???

'// Async feedback

' enum _D3DQUERYTYPE
%D3DQUERYTYPE_VCACHE                 = 4   ' /* D3DISSUE_END */
%D3DQUERYTYPE_RESOURCEMANAGER        = 5   ' /* D3DISSUE_END */
%D3DQUERYTYPE_VERTEXSTATS            = 6   ' /* D3DISSUE_END */
%D3DQUERYTYPE_EVENT                  = 8   ' /* D3DISSUE_END */
%D3DQUERYTYPE_OCCLUSION              = 9   ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_TIMESTAMP              = 10  ' /* D3DISSUE_END */
%D3DQUERYTYPE_TIMESTAMPDISJOINT      = 11  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_TIMESTAMPFREQ          = 12  ' /* D3DISSUE_END */
%D3DQUERYTYPE_PIPELINETIMINGS        = 13  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_INTERFACETIMINGS       = 14  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_VERTEXTIMINGS          = 15  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_PIXELTIMINGS           = 16  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_BANDWIDTHTIMINGS       = 17  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
%D3DQUERYTYPE_CACHEUTILIZATION       = 18  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DQUERYTYPE_MEMORYPRESSURE         = 19  ' /* D3DISSUE_BEGIN, D3DISSUE_END */
#ENDIF   ' // !D3D_DISABLE_9EX

'// Flags field for Issue
%D3DISSUE_END   = 1  ' (1 << 0) // Tells the runtime to issue the end of a query, changing it's state to "non-signaled".
%D3DISSUE_BEGIN = 2  ' (1 << 1) // Tells the runtime to issue the beginng of a query.

'// Flags field for GetData
%D3DGETDATA_FLUSH = 1  ' (1 << 0) // Tells the runtime to flush if the query is outstanding.


' // Size = 44 bytes
TYPE D3DRESOURCESTATS DWORD
'// Data collected since last Present()
   bThrashing            AS LONG    ' /* indicates if thrashing */
   ApproxBytesDownloaded AS DWORD   ' /* Approximate number of bytes downloaded by resource manager */
   NumEvicts             AS DWORD   ' /* number of objects evicted */
   NumVidCreates         AS DWORD   ' /* number of objects created in video memory */
   LastPri               AS DWORD   ' /* priority of last object evicted */
   NumUsed               AS DWORD   ' /* number of objects set to the device */
   NumUsedInVidMem       AS DWORD   ' /* number of objects set to the device, which are already in video memory */
'// Persistent data
   WorkingSet            AS DWORD   ' /* number of objects in video memory */
   WorkingSetBytes       AS DWORD   ' /* number of bytes in video memory */
   TotalManaged          AS DWORD   ' /* total number of managed objects */
   TotalBytes            AS DWORD   ' /* total number of bytes of managed objects */
END TYPE

%D3DRTYPECOUNT =  %D3DRTYPE_INDEXBUFFER + 1

'typedef struct _D3DDEVINFO_RESOURCEMANAGER
'{
'    D3DRESOURCESTATS    stats[D3DRTYPECOUNT];
'} D3DDEVINFO_RESOURCEMANAGER, *LPD3DDEVINFO_RESOURCEMANAGER;

' // Size = 352 bytes
TYPE D3DDEVINFO_RESOURCEMANAGER DWORD
   stats(%D3DRTYPECOUNT - 1) AS D3DRESOURCESTATS
END TYPE

' // Size = 8 bytes
TYPE D3DDEVINFO_D3DVERTEXSTATS DWORD
   NumRenderedTriangles      AS DWORD   '  /* total number of triangles that are not clipped in this frame */
   NumExtraClippingTriangles AS DWORD   '  /* Number of new triangles generated by clipping */
END TYPE

' // Size = 16 bytes
TYPE D3DDEVINFO_VCACHE DWORD
   Pattern     AS DWORD              '  /* bit pattern, return value must be FOUR_CC(‘C’, ‘A’, ‘C’, ‘H’) */
   OptMethod   AS DWORD              '  /* optimization method 0 means longest strips, 1 means vertex cache based */
   CacheSize   AS DWORD              '  /* cache size to optimize for  (only required if type is 1) */
   MagicNumber AS DWORD              '  /* used to determine when to restart strips (only required if type is 1)*/
END TYPE

' // Size = 16 bytes
TYPE D3DDEVINFO_D3D9PIPELINETIMINGS DWORD
   VertexProcessingTimePercent   AS SINGLE
   PixelProcessingTimePercent    AS SINGLE
   OtherGPUProcessingTimePercent AS SINGLE
   GPUIdleTimePercent            AS SINGLE
END TYPE

' // Size = 20 bytes
TYPE D3DDEVINFO_D3D9INTERFACETIMINGS DWORD
   WaitingForGPUToUseApplicationResourceTimePercent AS SINGLE
   WaitingForGPUToAcceptMoreCommandsTimePercent     AS SINGLE
   WaitingForGPUToStayWithinLatencyTimePercent      AS SINGLE
   WaitingForGPUExclusiveResourceTimePercent        AS SINGLE
   WaitingForGPUOtherTimePercent                    AS SINGLE
END TYPE

' // Size = 8 bytes
TYPE D3DDEVINFO_D3D9STAGETIMINGS DWORD
   MemoryProcessingPercent      AS SINGLE
   ComputationProcessingPercent AS SINGLE
END TYPE

' // Size = 20 bytes
TYPE D3DDEVINFO_D3D9BANDWIDTHTIMINGS DWORD
   MaxBandwidthUtilized                AS SINGLE
   FrontEndUploadMemoryUtilizedPercent AS SINGLE
   VertexRateUtilizedPercent           AS SINGLE
   TriangleSetupRateUtilizedPercent    AS SINGLE
   FillRateUtilizedPercent             AS SINGLE
END TYPE

' // Size = 8 bytes
TYPE D3DDEVINFO_D3D9CACHEUTILIZATION DWORD
   TextureCacheHitRate             AS SINGLE  ' // Percentage of cache hits
   PostTransformVertexCacheHitRate AS SINGLE
END TYPE

#IF NOT %DEF(%D3D_DISABLE_9EX)

' // Size = 20 bytes
TYPE D3DMEMORYPRESSURE DWORD
   BytesEvictedFromProcess     AS QUAD    ' UINT64
   SizeOfInefficientAllocation AS QUAD    ' UINT64
   LevelOfEfficiency           AS DWORD   ' DWORD
END TYPE

#ENDIF

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)

' enum D3DCOMPOSERECTSOP
%D3DCOMPOSERECTS_COPY     = 1???
%D3DCOMPOSERECTS_OR       = 2???
%D3DCOMPOSERECTS_AND      = 3???
%D3DCOMPOSERECTS_NEG      = 4???
%D3DCOMPOSERECTS_FORCE_DWORD  = &H7fffffff???  ' /* force 32-bit size enum */

' // Size = 8 bytes
TYPE D3DCOMPOSERECTDESC WORD
   X      AS WORD   ' USHORT // Top-left coordinates of a rect in the source surface
   Y      AS WORD
   Width  AS WORD   ' USHORT // Dimensions of the rect
   Height AS WORD
END TYPE

' // Size = 8 bytes
TYPE D3DCOMPOSERECTDESTINATION WORD
   SrcRectIndex AS WORD   ' USHORT // Index of D3DCOMPOSERECTDESC
   Reserved     AS WORD   ' USHORT // For alignment
   X            AS WORD   ' SHORT // Top-left coordinates of the rect in the destination surface
   Y            AS WORD
END TYPE

%D3DCOMPOSERECTS_MAXNUMRECTS  = &HFFFF
%D3DCONVOLUTIONMONO_MAXWIDTH  = 7
%D3DCONVOLUTIONMONO_MAXHEIGHT = %D3DCONVOLUTIONMONO_MAXWIDTH
%D3DFMT_A1_SURFACE_MAXWIDTH   = 8192
%D3DFMT_A1_SURFACE_MAXHEIGHT  = 2048


' // Size = 28 bytes
TYPE D3DPRESENTSTATS DWORD
   PresentCount        AS DWORD   ' UINT
   PresentRefreshCount AS DWORD   ' UINT
   SyncRefreshCount    AS DWORD   ' UINT
   SyncQPCTime         AS QUAD    ' LARGE_INTEGER
   SyncGPUTime         AS QUAD    ' LARGE_INTEGER
END TYPE

' enum D3DSCANLINEORDERING
%D3DSCANLINEORDERING_UNKNOWN     = 0
%D3DSCANLINEORDERING_PROGRESSIVE = 1
%D3DSCANLINEORDERING_INTERLACED  = 2

' // Size = 24 bytes
TYPE D3DDISPLAYMODEEX DWORD
   Size             AS DWORD   ' UINT
   Width            AS DWORD   ' UINT
   Height           AS DWORD   ' UINT
   RefreshRate      AS DWORD   ' UINT
   Format           AS DWORD   ' D3DFORMAT
   ScanLineOrdering AS DWORD   ' D3DSCANLINEORDERING
END TYPE

' // Size = 12 bytes
TYPE D3DDISPLAYMODEFILTER DWORD
   Size             AS DWORD   ' UINT
   Format           AS DWORD   ' D3DFORMAT
   ScanLineOrdering AS DWORD   ' D3DSCANLINEORDERING
END TYPE


' enum D3DDISPLAYROTATION
%D3DDISPLAYROTATION_IDENTITY = 1  ' // No rotation.
%D3DDISPLAYROTATION_90       = 2  ' // Rotated 90 degrees.
%D3DDISPLAYROTATION_180      = 3  ' // Rotated 180 degrees.
%D3DDISPLAYROTATION_270      = 4   ' // Rotated 270 degrees.

'/* For use in ID3DResource9::SetPriority calls */
%D3D9_RESOURCE_PRIORITY_MINIMUM = &H28000000???
%D3D9_RESOURCE_PRIORITY_LOW     = &H50000000???
%D3D9_RESOURCE_PRIORITY_NORMAL  = &H78000000???
%D3D9_RESOURCE_PRIORITY_HIGH    = &Ha0000000???
%D3D9_RESOURCE_PRIORITY_MAXIMUM = &Hc8000000???

%D3D_OMAC_SIZE = 16

' // Size = 16 bytes
TYPE D3D_OMAC BYTE
   Omac(%D3D_OMAC_SIZE - 1) AS BYTE   ' BYTE
END TYPE

' enum _D3DAUTHENTICATEDCHANNELTYPE
%D3DAUTHENTICATEDCHANNEL_D3D9            = 1
%D3DAUTHENTICATEDCHANNEL_DRIVER_SOFTWARE = 2
%D3DAUTHENTICATEDCHANNEL_DRIVER_HARDWARE = 3

' // Size = 24 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERY_INPUT DWORD
   QueryType      AS GUID    ' GUID
   hChannel       AS DWORD   ' HANDLE
   SequenceNumber AS DWORD   ' UINT
END TYPE

' // Size = 44 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT DWORD
   omac           AS D3D_OMAC
   QueryType      AS GUID       ' GUID
   hChannel       AS DWORD      ' HANDLE
   SequenceNumber AS DWORD      ' UINT
   ReturnCode     AS LONG       ' HRESULT
END TYPE

$D3DAUTHENTICATEDQUERY_PROTECTION = GUID$("{A84EB584-C495-48AA-B94D-8BD2D6FBCE05}")

' // Size = 4 bytes
TYPE D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS_STRUCT DWORD
   ProtectionEnabled           AS BIT * 1 IN DWORD   ' UINT
   OverlayOrFullscreenRequired AS BIT * 1
   Reserved                    AS BIT * 30
END TYPE

' // Size = 4 bytes
UNION D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS_STRUCT_UNION
   D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS_STRUCT
   Value AS DWORD
END UNION

' // Size = 4 bytes
TYPE D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS DWORD
   D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS_STRUCT_UNION
END TYPE

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYPROTECTION_OUTPUT DWORD
   Output          AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   ProtectionFlags AS D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS
END TYPE

$D3DAUTHENTICATEDQUERY_CHANNELTYPE = GUID$("{BC1B18A5-B1FB-42AB-BD94-B5828B4BF7BE}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYCHANNELTYPE_OUTPUT DWORD
   Output      AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   ChannelType AS LONG   ' D3DAUTHENTICATEDCHANNELTYPE
END TYPE

$D3DAUTHENTICATEDQUERY_DEVICEHANDLE = GUID$("{EC1C539D-8CFF-4E2A-BCC4-F5692F99F480}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYDEVICEHANDLE_OUTPUT DWORD
   Output       AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   DeviceHandle AS DWORD   ' HANDLE
END TYPE

$D3DAUTHENTICATEDQUERY_CRYPTOSESSION = GUID$("{2634499E-D018-4D74-AC17-7F724059528D}")

' // Size = 28 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYCRYPTOSESSION_INPUT DWORd
   Input             AS D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
   DXVA2DecodeHandle AS DWORD   ' HANDLE
END TYPE

' // Size = 56 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYCRYPTOSESSION_OUTPUT DWORD
   Output              AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   DXVA2DecodeHandle   AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
   DeviceHandle        AS DWORD   ' HANDLE
END TYPE

$D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESSCOUNT = GUID$("{0DB207B3-9450-46A6-82DE-1B96D44F9CF2}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESSCOUNT_OUTPUT DWORD
   Output                               AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   NumRestrictedSharedResourceProcesses AS DWORD   ' UINT
END TYPE

$D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESS = GUID$("{649BBADB-F0F4-4639-A15B-24393FC3ABAC}")

' // Size = 28 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESS_INPUT DWORD
   Input        AS D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
   ProcessIndex AS DWORD   ' UINT
END TYPE

' enum _D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
%PROCESSIDTYPE_UNKNOWN = 0
%PROCESSIDTYPE_DWM     = 1
%PROCESSIDTYPE_HANDLE  = 2

' // Size = 56 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESS_OUTPUT DWORD
   Output           AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   ProcessIndex     AS DWORD   ' UINT
   ProcessIdentifer AS LONG    ' D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
   ProcessHandle    AS DWORD   ' HANDLE
END TYPE

$D3DAUTHENTICATEDQUERY_UNRESTRICTEDPROTECTEDSHAREDRESOURCECOUNT = GUID$("{012F0BD6-E662-4474-BEFD-AA53E5143C6D}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYUNRESTRICTEDPROTECTEDSHAREDRESOURCECOUNT_OUTPUT DWORD
   Output                                  AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   NumUnrestrictedProtectedSharedResources AS DWORD   ' UINT
END TYPE

$D3DAUTHENTICATEDQUERY_OUTPUTIDCOUNT = GUID$("{2C042B5E-8C07-46D5-AABE-8F75CBAD4C31}")

' // Size = 32 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTIDCOUNT_INPUT DWORD
   Input               AS D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
   DeviceHandle        AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
END TYPE

' // Size = 56 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTIDCOUNT_OUTPUT DWORD
   Output              AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   DeviceHandle        AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
   NumOutputIDs        AS DWORD   ' UINT
END TYPE

$D3DAUTHENTICATEDQUERY_OUTPUTID = GUID$("{839DDCA3-9B4E-41E4-B053-892BD2A11EE7}")

' // Size = 36 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTID_INPUT DWORD
   Input               AS D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
   DeviceHandle        AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
   OutputIDIndex       AS DWORD   ' UINT
END TYPE

' // Size = 64 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTID_OUTPUT DWORD
   Output              AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   DeviceHandle        AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
   OutputIDIndex       AS DWORD   ' UINT
   OutputID            AS QUAD    ' UINT64
END TYPE

$D3DAUTHENTICATEDQUERY_ACCESSIBILITYATTRIBUTES = GUID$("{6214D9D2-432C-4ABB-9FCE-216EEA269E3B}")

' enum _D3DBUSTYPE
%D3DBUSTYPE_OTHER                                            = &H00000000???
%D3DBUSTYPE_PCI                                              = &H00000001???
%D3DBUSTYPE_PCIX                                             = &H00000002???
%D3DBUSTYPE_PCIEXPRESS                                       = &H00000003???
%D3DBUSTYPE_AGP                                              = &H00000004???
%D3DBUSIMPL_MODIFIER_INSIDE_OF_CHIPSET                       = &H00010000???
%D3DBUSIMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP          = &H00020000???
%D3DBUSIMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_SOCKET        = &H00030000???
%D3DBUSIMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR                = &H00040000???
%D3DBUSIMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR_INSIDE_OF_NUAE = &H00050000???
%D3DBUSIMPL_MODIFIER_NON_STANDARD                            = &H80000000???

' // Size = 56 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYINFOBUSTYPE_OUTPUT DWORD
   Output                           AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   BusType                          AS DWORD   ' D3DBUSTYPE
   bAccessibleInContiguousBlocks    AS LONG    ' BOOL
   bAccessibleInNonContiguousBlocks AS LONG    ' BOOL
END TYPE

$D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUIDCOUNT = GUID$("{B30F7066-203C-4B07-93FC-CEAAFD61241E}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUIDCOUNT_OUTPUT DWORD
   Output             AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   NumEncryptionGuids AS DWORD   ' UINT
END TYPE

$D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUID = GUID$("{F83A5958-E986-4BDA-BEB0-411F6A7A01B7}")

' // Size = 28 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUID_INPUT DWORD
   Input               AS D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
   EncryptionGuidIndex AS DWORD   ' UINT
END TYPE

' // Size = 64 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUID_OUTPUT DWORD
   Output              AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   EncryptionGuidIndex AS DWORD   ' UINT
   EncryptionGuid      AS GUID    ' GUID
END TYPE

$D3DAUTHENTICATEDQUERY_CURRENTENCRYPTIONWHENACCESSIBLE = GUID$("{EC1791C7-DAD3-4F15-9EC3-FAA93D60D4F0}")

' // Size = 60 bytes
TYPE D3DAUTHENTICATEDCHANNEL_QUERYUNCOMPRESSEDENCRYPTIONLEVEL_OUTPUT DWORD
   Output         AS D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
   EncryptionGuid AS GUID   ' GUID
END TYPE

' // Size = 40 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT DWORD
   omac           AS D3D_OMAC
   ConfigureType  AS GUID       ' GUID
   hChannel       AS DWORD      ' HANDLE
   SequenceNumber AS DWORD      ' UINT
END TYPE

' // Size = 44 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT DWORD
   omac           AS D3D_OMAC
   ConfigureType  AS GUID       ' GUID
   hChannel       AS DWORD      ' HANDLE
   SequenceNumber AS DWORD      ' UINT
   ReturnCode     AS LONG       ' HRESULT
END TYPE

$D3DAUTHENTICATEDCONFIGURE_INITIALIZE = GUID$("{06114BDB-3523-470A-8DCA-FBC2845154F0}")

' // Size = 48 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGUREINITIALIZE DWORD
   Parameters             AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
   StartSequenceQuery     AS DWORD   ' UINT
   StartSequenceConfigure AS DWORD   ' UINT
END TYPE

$D3DAUTHENTICATEDCONFIGURE_PROTECTION = GUID$("{50455658-3F47-4362-BF99-BFDFCDE9ED29}")

' // Size = 44 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGUREPROTECTION DWORD
   Parameters  AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
   Protections AS D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS
END TYPE

$D3DAUTHENTICATEDCONFIGURE_CRYPTOSESSION = GUID$("{6346CC54-2CFC-4AD4-8224-D15837DE7700}")

' // Size = 52 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGURECRYPTOSESSION DWORD
   Parameters          AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
   DXVA2DecodeHandle   AS DWORD   ' HANDLE
   CryptoSessionHandle AS DWORD   ' HANDLE
   DeviceHandle        AS DWORD   ' HANDLE
END TYPE

$D3DAUTHENTICATEDCONFIGURE_SHAREDRESOURCE = GUID$("{0772D047-1B40-48E8-9CA6-B5F510DE9F01}")

' // Size = 52 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGURESHAREDRESOURCE DWORD
   Parameters           AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
   ProcessIdentiferType AS LONG    ' D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
   ProcessHandle        AS DWORD   ' HANDLE
   AllowAccess          AS LONG    ' BOOL
END TYPE

$D3DAUTHENTICATEDCONFIGURE_ENCRYPTIONWHENACCESSIBLE = GUID$("{41FFF286-6AE0-4D43-9D55-A46E9EFD158A}")

' // Size = 56 bytes
TYPE D3DAUTHENTICATEDCHANNEL_CONFIGUREUNCOMPRESSEDENCRYPTION DWORD
   Parameters     AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
   EncryptionGuid AS GUID
END TYPE

' // Size = 12 bytes
TYPE D3DENCRYPTED_BLOCK_INFO DWORD
   NumEncryptedBytesAtBeginning AS DWORD   ' UINT
   NumBytesInSkipPattern        AS DWORD   ' UINT
   NumBytesInEncryptPattern     AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
TYPE D3DAES_CTR_IV DWORD
   IV    AS QUAD   ' UINT64 // Big-Endian IV
   Count AS QUAD   ' UINT64 // Big-Endian Block Count
END TYPE

#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */
