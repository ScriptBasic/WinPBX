' ########################################################################################
' CAfxComplex Class
' File: CAfxComplex.inc
' Contents: Class to provide support for complex numbers.
' Copyright (c) 2014 José Roca
' Portions Copyright (c) Microsoft Corporation.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXCOMPLEX_INC = 1

#IF NOT %DEF(%COMPLEX_DEFINED)
%COMPLEX_DEFINED = 1
' // Size = 16 bytes
TYPE tagComplex DWORD
   x AS DOUBLE   ' real part
   y AS DOUBLE   ' imaginary part
END TYPE
#ENDIF

' ########################################################################################
' Complex numbers
' ########################################################################################
CLASS CAfxComplex

INTERFACE IAfxComplex

   INHERIT IAutomation

   ' ========================================================================================
   ' Uses the cartesian components (x,y) to set the real and imaginary parts of the complex
   ' ========================================================================================
   METHOD Set (BYVAL x AS DOUBLE, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = x
      z.y = y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the real part of the complex number z.
   ' ========================================================================================
   METHOD GetReal (BYREF z AS tagComplex) AS DOUBLE
      METHOD = z.x
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Sets the real part of the complex number z.
   ' ========================================================================================
   METHOD SetReal (BYREF z AS tagComplex, BYVAL x AS DOUBLE)
      z.x = x
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the imaginary part of the complex number z.
   ' ========================================================================================
   METHOD GetImag (BYREF z AS tagComplex) AS DOUBLE
      METHOD = z.y
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Sets the imaginary part of the complex number z.
   ' ========================================================================================
   METHOD SetImag (BYVAL z AS tagComplex, BYVAL y AS DOUBLE)
      z.y = y
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns -1 if the two complex numbers are equal, or 0 otherwise.
   ' ========================================================================================
   METHOD Equal (BYREF z1 AS tagComplex, BYREF z2 AS tagComplex) AS LONG
      IF z1.x = z2.x AND z1.y = z2.y THEN METHOD = -1
   END METHOD
   ' ========================================================================================

   '/* Complex numbers */

   ' =====================================================================================
   ' This method uses the rectangular cartesian components (x,y) to return the complex
   ' number z = x + i y.
   ' =====================================================================================
   METHOD Rect (BYVAL x AS DOUBLE, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = x
      z.y = y
      METHOD = z
   END METHOD
   ' =====================================================================================

   '/* Complex arithmetic operators */

   ' ========================================================================================
   ' Returns the sum of the complex numbers a and b, z=a+b.
   ' ========================================================================================
   METHOD Add (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x + b.x
      z.y = a.y + b.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the difference of the complex numbers a and b, z=a-b.
   ' ========================================================================================
   METHOD Sub (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x - b.x
      z.y = a.y - b.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the product of the complex numbers a and b, z=ab.
   ' ========================================================================================
   METHOD Mul (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x * b.x - a.y * b.y
      z.y = a.x * b.y + a.y * b.x
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the sum of the complex number a and the real number x, z=a+x.
   ' ========================================================================================
   METHOD AddReal (BYREF a AS tagComplex, BYVAL x AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x + x
      z.y = a.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the difference of the complex number a and the real number x, z=a-x.
   ' ========================================================================================
   METHOD SubReal (BYREF a AS tagComplex, BYVAL x AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x - x
      z.y = a.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the product of the complex number a and the real number x, z=ax.
   ' ========================================================================================
   METHOD MulReal (BYREF a AS tagComplex, BYVAL x AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = x * a.x
      z.y = x * a.x
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the quotient of the complex number a and the real number x, z=a/x.
   ' ========================================================================================
   METHOD DivReal (BYREF a AS tagComplex, BYVAL x AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = z.x / x
      z.y = z.y / x
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' This method returns the sum of the complex number a and the imaginary number iy, z=a+iy.
   ' ========================================================================================
   METHOD AddImag (BYREF a AS tagComplex, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x
      z.y = a.y + y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the difference of the complex number a and the imaginary number iy, z=a-iy.
   ' ========================================================================================
   METHOD SubImag (BYREF a AS tagComplex, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x
      z.y = a.y - y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the product of the complex number a and the imaginary number iy, z=a*(iy).
   ' ========================================================================================
   METHOD MulImag (BYREF a AS tagComplex, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = -y * a.y
      z.y = y * a.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the quotient of the complex number a and the imaginary number iy, z=a/(iy).
   ' ========================================================================================
   METHOD DivImag (BYREF a AS tagComplex, BYVAL y AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.y / y
      z.y = -a.x / y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex conjugate of the complex number z, z^* = x - i y.
   ' ========================================================================================
   METHOD Conjugate (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = a.x
      z.y = -a.y
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the negative of the complex number z, -z = (-x) + i(-y).
   ' ========================================================================================
   METHOD Negative (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = -a.x
      z.y = -a.y
      METHOD = z
   END METHOD
   ' ========================================================================================

END INTERFACE

END CLASS
' ########################################################################################
