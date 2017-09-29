' ########################################################################################
' Microsoft Windows
' Class CDictionary
' File: CDictionary.inc
' Wraps the Dictionary object to allow the use of string literals and scalar values
' instead of variants (the IDictionary interface has the variant parameters declared as
' BYREF instead of BYVAL).
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDICTIONARY_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "scrrun.inc"

CLASS CDictionary COMMON

   INSTANCE pIDictionary AS IDictionary

   ' =====================================================================================
   ' Creates an instance of the Dictionary object
   ' =====================================================================================
   CLASS METHOD Create
      pIDictionary = NEWCOM "Scripting.Dictionary"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases the instance of the Dictionary object
   ' =====================================================================================
   CLASS METHOD Destroy
      pIDictionary = NOTHING
   END METHOD
   ' =====================================================================================

   INTERFACE IDictionaryImpl : INHERIT IDispatch

   ' =====================================================================================
   ' Returns an item for a specified key in a Dictionary object.
   ' =====================================================================================
   PROPERTY GET Item (BYVAL vKey AS VARIANT) AS VARIANT
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      PROPERTY = pIDictionary.Item(vKey)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets an item for a specified key in a Dictionary object.
   ' If key is not found when changing an item, a new key is created with the specified
   ' vNewItem. If key is not found when attempting to return an existing item, a new key
   ' is created and its corresponding item is left empty.
   ' =====================================================================================
   PROPERTY SET Item (BYVAL vKey AS VARIANT, BYVAL vItem AS VARIANT)
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      pIDictionary.Item(vKey) = vItem
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a key and item pair to a Dictionary object.
   ' =====================================================================================
   METHOD Add (BYVAL vKey AS VARIANT, BYVAL vItem AS VARIANT)
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      pIDictionary.Add(vKey, vItem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of items in the Dictionary object.
   ' =====================================================================================
   PROPERTY GET Count () AS LONG
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      PROPERTY = pIDictionary.Count
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns VARIANT_TRUE (-1) if a specified key exists in the Dictionary object;
   ' VARIANT_FALSE (0) if it does not.
   ' =====================================================================================
   METHOD Exists (BYVAL vKey AS VARIANT) AS INTEGER
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      METHOD = pIDictionary.Exists(vKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns an array containing all the items in a Dictionary object.
   ' =====================================================================================
   METHOD Items () AS VARIANT
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      METHOD = pIDictionary.Items
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a key in a Dictionary object.
   ' If key is not found when changing a key, a new key is created and its associated
   ' item is left empty.
   ' =====================================================================================
   PROPERTY SET Key (BYVAL vKey AS VARIANT, BYVAL vItem AS VARIANT)
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      pIDictionary.Key(vKey) = vItem
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns an array containing all the keys in a Dictionary object.
   ' =====================================================================================
   METHOD Keys () AS VARIANT
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      METHOD = pIDictionary.Keys
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes a key, item pair from a Dictionary object.
   ' =====================================================================================
   METHOD Remove (BYVAL vKey AS VARIANT)
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      pIDictionary.Remove(vKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes all key, item pairs from a Dictionary object.
   ' =====================================================================================
   METHOD RemoveAll ()
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      pIDictionary.RemoveAll
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the comparison mode for comparing string keys in a Dictionary object.
   ' =====================================================================================
   PROPERTY GET CompareMode () AS LONG
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      PROPERTY = pIDictionary.CompareMode
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the comparison mode for comparing string keys in a Dictionary object.
   ' =====================================================================================
   PROPERTY SET CompareMode (BYVAL nCompare AS LONG)
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      pIDictionary.CompareMode = nCompare
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the standard IEnumVARIANT interface.
   ' =====================================================================================
   METHOD NewEnum_ () AS IUnknown
      IF ISNOTHING(pIDictionary) THEN METHOD OBJRESULT = %E_POINTER : EXIT METHOD
      METHOD = pIDictionary.NewEnum_
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the hash value of the specified key.
   ' =====================================================================================
   PROPERTY GET HashVal (BYVAL vKey AS VARIANT) AS VARIANT
      IF ISNOTHING(pIDictionary) THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      PROPERTY = pIDictionary.HashVal(vKey)
   END PROPERTY
   ' =====================================================================================

   END INTERFACE

END CLASS
