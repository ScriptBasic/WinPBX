' ########################################################################################
' Microsoft Windows
' File: CGdipEffect.inc
' Contents: GDI+ Effect class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPEFFECT_INC = 1

#IF (%GDIPVER >= &H0110)

' ########################################################################################
' CGdipEffect Class
' ########################################################################################
CLASS CGdipEffect

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pEffect AS DWORD
   INSTANCE m_auxDataSize AS LONG
   INSTANCE m_auxData AS DWORD
   INSTANCE m_useAuxData AS LONG

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_auxData THEN GdipFree(m_auxData)
      IF m_pEffect THEN GdipDeleteEffect(m_pEffect)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipEffect interface.
   ' #####################################################################################
   INTERFACE IGdipEffect : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pEffect THEN GdipDeleteEffect(m_pEffect)
      m_pEffect = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      IF m_pEffect THEN METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipBlur interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipBlur : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipBlur methods ***

   ' =====================================================================================
   ' Creates a Blur object
   ' =====================================================================================
   METHOD Blur () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($BlurEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS BlurParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(BlurParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS BlurParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipSharpen interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipSharpen : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipSharpen methods ***

   ' =====================================================================================
   ' Creates a Sharpen object
   ' =====================================================================================
   METHOD Sharpen () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($SharpenEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS SharpenParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(SharpenParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS SharpenParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipRedEyeCorrection interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipRedEyeCorrection : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipRedEyeCorrection methods ***

   ' =====================================================================================
   ' Creates a RedEyeCorrection object
   ' =====================================================================================
   METHOD RedEyeCorrection () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($RedEyeCorrectionEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS RedEyeCorrectionParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(RedEyeCorrectionParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS RedEyeCorrectionParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipBrightnessContrast interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipBrightnessContrast : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipBrightnessContrast methods ***

   ' =====================================================================================
   ' Creates a BrightnessContrast object
   ' =====================================================================================
   METHOD BrightnessContrast () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($BrightnessContrastEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS BrightnessContrastParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(BrightnessContrastParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS BrightnessContrastParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipHueSaturationLightness interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipHueSaturationLightness : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipHueSaturationLightness methods ***

   ' =====================================================================================
   ' Creates a HueSaturationLightness object
   ' =====================================================================================
   METHOD HueSaturationLightness () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($HueSaturationLightnessEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS HueSaturationLightnessParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(HueSaturationLightnessParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS HueSaturationLightnessParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipLevels interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipLevels : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipLevels  methods ***

   ' =====================================================================================
   ' Creates a Levels  object
   ' =====================================================================================
   METHOD Levels () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($LevelsEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS LevelsParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(LevelsParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS LevelsParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipTint interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipTint : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipTint  methods ***

   ' =====================================================================================
   ' Creates a Tint object
   ' =====================================================================================
   METHOD Tint () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($TintEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS TintParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(TintParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS TintParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipColorBalance interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipColorBalance : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipColorBalance  methods ***

   ' =====================================================================================
   ' Creates a ColorBalance object
   ' =====================================================================================
   METHOD ColorBalance () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($ColorBalanceEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS ColorBalanceParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(ColorBalanceParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS ColorBalanceParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipColorMatrixEffect interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipColorMatrixEffect : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipColorMatrixEffect  methods ***

   ' =====================================================================================
   ' Creates a ColorMatrixEffect object
   ' =====================================================================================
   METHOD ColorMatrixEffect () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($ColorMatrixEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS ColorMatrix) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(ColorMatrix)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS ColorMatrix) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipColorLUT interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipColorLUT : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipColorLUT  methods ***

   ' =====================================================================================
   ' Creates a ColorLUT object
   ' =====================================================================================
   METHOD ColorLUT () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($ColorLUTEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS ColorLUTParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(ColorLUTParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS ColorLUTParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipColorCurve interface.
   ' Inherits from IGdipEffect.
   ' #####################################################################################
   INTERFACE IGdipColorCurve : INHERIT IAutomation

   ' *** IGdipEffect methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pEffect
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pEffect AS IGdipEffect
      pEffect = ME
      pEffect.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxDataSize () THREADSAFE AS LONG
      METHOD = m_auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' =====================================================================================
   METHOD GetAuxData () THREADSAFE AS DWORD
      METHOD = m_auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or clears a flag that specifies whether the ApplyEffect method should return a
   ' pointer to the auxiliary data that it creates.
   ' =====================================================================================
   METHOD UseAuxData (BYVAL useAuxDataFlag AS LONG) THREADSAFE AS DWORD
      m_useAuxData = useAuxDataFlag
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of the parameters currently set for this Effect. The
   ' GetParameterSize method is usually called on an object that is an instance of a
   ' descendant of the Effect class.
   ' =====================================================================================
   METHOD GetParameterSize (BYREF dwSize AS DWORD) THREADSAFE AS LONG
      METHOD = GdipGetEffectParameterSize(m_pEffect, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the auxiliary data created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set it to 0 if other method
   ' or function, such the CreateApplyEffect method of the IGdipBitmap interface, frees
   ' the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxDataSize (BYVAL auxDataSize AS LONG) THREADSAFE
      m_auxDataSize = auxDataSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to set the pointer to NULL if other
   ' method or function, such the CreateApplyEffect method of the IGdipBitmap interface,
   ' frees the memory with GdipFree.
   ' =====================================================================================
   METHOD SetAuxData (BYVAL auxData AS DWORD) THREADSAFE
      m_auxData = auxData
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to a set of lookup tables created by a previous call to the ApplyEffect method.
   ' Note: Not included in the C++ classes, but needed to retrieve the value of this flag.
   ' =====================================================================================
   METHOD GetUseAuxData () THREADSAFE AS DWORD
      METHOD = m_useAuxData
   END METHOD
   ' =====================================================================================

   ' *** IGdipColorCurve  methods ***

   ' =====================================================================================
   ' Creates a ColorCurve object
   ' =====================================================================================
   METHOD ColorCurve () THREADSAFE AS LONG
      m_hStatus = GdipCreateEffect($ColorCurveEffectGuid, m_pEffect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the parameters of this object.
   ' =====================================================================================
   METHOD SetParameters (BYREF params AS ColorCurveParams) THREADSAFE AS LONG
      LOCAL dwSize AS DWORD
      dwSize = SIZEOF(ColorCurveParams)
      m_hStatus = GdipSetEffectParameters(m_pEffect, params, dwSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the parameters of this object.
   ' =====================================================================================
   METHOD GetParameters (BYREF dwSize AS DWORD, BYREF params AS ColorCurveParams) THREADSAFE AS LONG
      m_hStatus = GdipGetEffectParameters(m_pEffect, dwSize, params)
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

#ENDIF   ' //(GDIPVER >= 0x0110)
