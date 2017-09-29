' ########################################################################################
' CComplex Class
' File: CComplex.inc
' Contents: Class to provide support for complex numbers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' Note: Because many of the methods are based in ansi C functions found in the GNU
' Scientific Library ( http://www.gnu.org/software/gsl/  ), distributed under the terms of
' the GNU General Public License (GPL), this class is also subject to that license and,
' therefore, is only suitable to be used in open source projects.
' GNU General Public License: http://www.gnu.org/copyleft/gpl.html
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CCOMPLEX_INC = 1

#INCLUDE ONCE "math.inc"    ' C runtime header
#INCLUDE ONCE "float.inc"   ' C runtime header

#IF NOT %DEF(%SQRT_DBL_EPSILON)
%SQRT_DBL_EPSILON = 1
MACRO SQRT_DBL_EPSILON = 1.4901161193847656e-08
#ENDIF

' /* e */
#IF NOT %DEF(%M_E_DEFINED)
%M_E_DEFINED = 1
MACRO M_E = 2.71828182845904523536028747135
#ENDIF

' /* log_2 (e) */
#IF NOT %DEF(%M_LOG2E_DEFINED)
%M_LOG2E_DEFINED = 1
MACRO M_LOG2E = 1.44269504088896340735992468100
#ENDIF

' /* log_10 (e) */
#IF NOT %DEF(%M_LOG10E_DEFINED)
%M_LOG10E_DEFINED = 1
MACRO M_LOG10E = 0.43429448190325182765112891892
#ENDIF

' /* sqrt(2) */
#IF NOT %DEF(%M_SQRT2_DEFINED)
%M_SQRT2_DEFINED = 1
MACRO M_SQRT2 = 1.41421356237309504880168872421
#ENDIF

' /* sqrt(1/2) */
#IF NOT %DEF(%M_SQRT1_2_DEFINED)
%M_SQRT1_2_DEFINED = 1
MACRO M_SQRT1_2 = 0.70710678118654752440084436210
#ENDIF

' /* sqrt(3) */
#IF NOT %DEF(%M_SQRT3_DEFINED)
%M_SQRT3_DEFINED = 1
MACRO M_SQRT3 = 1.73205080756887729352744634151
#ENDIF

' /* pi */
#IF NOT %DEF(%M_PI)
%M_PI_DEFINED = 1
MACRO M_PI = 3.14159265358979323846264338328
#ENDIF

' /* pi/2 */
#IF NOT %DEF(%M_PI_2_DEFINED)
%M_PI_2_DEFINED = 1
MACRO M_PI_2 = 1.57079632679489661923132169164
#ENDIF

' /* pi/4 */
#IF NOT %DEF(%M_PI_4_DEFINED)
%M_PI_4_DEFINED = 1
MACRO M_PI_4 = 0.78539816339744830961566084582
#ENDIF

' /* sqrt(pi) */
#IF NOT %DEF(%M_SQRTPI_DEFINED)
%M_SQRTPI_DEFINED = 1
MACRO M_SQRTPI = 1.77245385090551602729816748334
#ENDIF

' /* 2/sqrt(pi) */
#IF NOT %DEF(%M_2_SQRTPI_DEFINED)
%M_2_SQRTPI_DEFINED = 1
MACRO M_2_SQRTPI = 1.12837916709551257389615890312
#ENDIF

' /* 1/pi */
#IF NOT %DEF(%M_1_PI_DEFINED)
%M_1_PI_DEFINED = 1
MACRO M_1_PI = 0.31830988618379067153776752675
#ENDIF

' /* 2/pi */
#IF NOT %DEF(%M_2_PI_DEFINED)
%M_2_PI_DEFINED = 1
MACRO M_2_PI = 0.63661977236758134307553505349
#ENDIF

' /* ln(10) */
#IF NOT %DEF(%M_LN10_DEFINED)
%M_LN10_DEFINED = 1
MACRO M_LN10 = 2.30258509299404568401799145468
#ENDIF

' /* ln(2) */
#IF NOT %DEF(%M_LN2_DEFINED)
%M_LN2_DEFINED = 1
MACRO M_LN2 = 0.69314718055994530941723212146
#ENDIF

' /* ln(pi) */
#IF NOT %DEF(%M_LNPI_DEFINED)
%M_LNPI_DEFINED = 1
MACRO M_LNPI = 1.14472988584940017414342735135
#ENDIF

' /* Euler constant */
#IF NOT %DEF(%M_EULER_DEFINED)
%M_EULER_DEFINED = 1
MACRO M_EULER = 0.57721566490153286060651209008
#ENDIF

' ########################################################################################
' Additional math functions.
' ########################################################################################

' ========================================================================================
' Computes the value of log(1+x) in a way that is accurate for small x.
' ========================================================================================
FUNCTION log1p_ (BYVAL x AS DOUBLE) AS DOUBLE
   LOCAL y, z AS DOUBLE
   y = 1 + x
   z = y - 1
   FUNCTION = log_(y) - (z-x)/y   ' /* cancels errors with IEEE arithmetic */
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the value of exp(x)-1 in a way that is accurate for small x.
' ========================================================================================
FUNCTION expm1_ (BYVAL x AS DOUBLE) AS DOUBLE
   LOCAL i, sum, term AS DOUBLE
   IF fabs_(x) < M_LN2 THEN
      ' /* Compute the taylor series S = x + (1/2!) x^2 + (1/3!) x^3 + ... */
      i = 1
      sum = x
      term = x / 1
      DO
         i += 1
         term *= x / i
         sum += term
         IF fabs_(term) <= fabs_(sum) * DBL_EPSILON THEN EXIT DO
      LOOP
      FUNCTION = sum
   ELSE
      FUNCTION = exp_(x) - 1
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the value of sqrt{x^2 + y^2 + z^2} in a way that avoids overflow.
' ========================================================================================
FUNCTION hypot3_ (BYVAL x AS DOUBLE, BYVAL y AS DOUBLE, BYVAL z AS DOUBLE) AS DOUBLE
   LOCAL xabs, yabs, zabs, w, r AS DOUBLE
   xabs = fabs_(x)
   yabs = fabs_(y)
   zabs = fabs_(z)
   w = MAX(xabs, MAX(yabs, zabs))
   IF w = 0 THEN
      FUNCTION = 0
   ELSE
      r = w * sqrt_((xabs / w) * (xabs / w) + _
                    (yabs / w) * (yabs / w) + _
                    (zabs / w) * (zabs / w))
      FUNCTION = r
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the value of arccosh(x).
' ========================================================================================
FUNCTION acosh_ (BYVAL x AS DOUBLE) AS DOUBLE
   LOCAL t AS DOUBLE
   IF x > 1.0 / SQRT_DBL_EPSILON THEN
      FUNCTION = log_(x) + M_LN2
   ELSEIF x > 2 THEN
      FUNCTION = log_(2 * x - 1 / (sqrt_(x * x - 1) + x))
   ELSEIF x > 1 THEN
      t = x - 1
      FUNCTION = log1p_(t + sqrt_(2 * t + t * t))
   ELSEIF x = 1 THEN
      FUNCTION = 0
   ELSE
      FUNCTION = 0 / 0  ' NAN
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the value of arcsinh(x).
' ========================================================================================
FUNCTION asinh_ (BYVAL x AS DOUBLE) AS DOUBLE
   LOCAL a, s, a2 AS DOUBLE
   a = fabs_(x)
   s = IIF(x < 0, -1, 1)
   IF a > 1 / SQRT_DBL_EPSILON THEN
      FUNCTION = s * (log_(a) + M_LN2)
   ELSEIF a > 2 THEN
      FUNCTION = s * log_(2 * a + 1 / (a + sqrt_(a * a + 1)))
   ELSEIF a > SQRT_DBL_EPSILON THEN
      a2 = a * a
      FUNCTION = s * log1p_(a + a2 / (1 + sqrt_(1 + a2)))
   ELSE
      FUNCTION = x
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the value of arctanh(x).
' ========================================================================================
FUNCTION atanh_ (BYVAL x AS DOUBLE) AS DOUBLE
   LOCAL a, s AS DOUBLE
   a = fabs_(x)
   s = IIF(x < 0, -1, 1)
   IF a > 1 THEN
      FUNCTION = 0 / 0   ' NAN
   ELSEIF a = 1 THEN
      FUNCTION = IIF(x < 0, HUGE_VAL, -HUGE_VAL)
   ELSEIF a => 0.5 THEN
      FUNCTION = s * 0.5 * log1p_(2 * a / (1 - a))
   ELSEIF a > DBL_EPSILON THEN
      FUNCTION = s * 0.5 * log1p_(2 * a + 2 * a * a / (1 - a))
   ELSE
      FUNCTION = x
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns +1 if x is positive infinity, -1 if x is negative infinity and 0 otherwise.
' ========================================================================================
FUNCTION isinf_ (BYVAL x AS DOUBLE) AS LONG
   IF NOT finite_(x) AND NOT isnan_(x) THEN
      FUNCTION = IIF&(x > 0, 1, -1)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether x and y are approximately equal to a relative accuracy EPSILON.
' ========================================================================================
FUNCTION fcmp_ (BYVAL x1 AS DOUBLE, BYVAL x2 AS DOUBLE, BYVAL epsilon AS DOUBLE) AS LONG

   LOCAL exponent AS LONG
   LOCAL delta, difference AS DOUBLE
   LOCAL dmax AS DOUBLE

   ' /* Find exponent of largest absolute value */
   dmax = IIF(fabs_(x1) > fabs_(x2), x1, x2)
   frexp_(dmax, exponent)

   ' /* Form a neighborhood of size  2 * delta */
   delta = ldexp_(epsilon, exponent)
   difference = x1 - x2

   IF difference > delta THEN        ' /* x1 > x2 */
      FUNCTION = 1
   ELSEIF difference < -delta THEN   ' /* x1 < x2 */
      FUNCTION = -1
   ELSE                              ' /* -delta <= difference <= delta */
      FUNCTION = 0                   ' /* x1 ~=~ x2 */
   END IF

END FUNCTION
' ========================================================================================

' ########################################################################################
' Complex numbers
' ########################################################################################
CLASS CComplex

INTERFACE IComplex

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
   ' Returns the complex number z = r exp(i theta) = r (cos(theta) + i sin(theta))
   ' from the polar representation (r, theta).
   ' =====================================================================================
   METHOD Polar (BYVAL r AS DOUBLE, BYVAL theta AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      z.x = r * cos_(theta)
      z.y = r * sin_(theta)
      METHOD = z
   END METHOD
   ' =====================================================================================

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

   '/* Properties of complex numbers */

   ' =====================================================================================
   ' Returns the argument of the complex number z, arg(z), where -pi < arg(z) <= pi.
   ' =====================================================================================
   METHOD Arg (BYREF z AS tagComplex) AS DOUBLE
      IF z.x = 0 AND z.y = 0 THEN EXIT METHOD
      METHOD = atan2_(z.y, z.x)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the magnitude of the complex number z, |z|.
   ' =====================================================================================
   METHOD Abs (BYREF z AS tagComplex) AS DOUBLE
      METHOD = hypot_(z.x, z.y)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the squared magnitude of the complex number z, |z|^2.
   ' =====================================================================================
   METHOD Abs2 (BYREF z AS tagComplex) AS DOUBLE
      METHOD = (z.x * z.x) + (z.y * z.y)
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   ' Returns the natural logarithm of the magnitude of the complex number z, log|z|.
   ' It allows an accurate evaluation of \log|z| when |z| is close to one.  The direct
   ' evaluation of log(ME.abs(z)) would lead to a loss of precision in this case.
   ' ========================================================================================
   METHOD LogAbs (BYREF z AS tagComplex) AS DOUBLE
      LOCAL xabs, yabs, dmax, u AS DOUBLE
      xabs = fabs_ (z.x)
      yabs = fabs_ (z.y)
      IF xabs => yabs THEN
         dmax = xabs
         u = yabs / xabs
      ELSE
         dmax = yabs
         u = xabs / yabs
      END IF
      ' /* Handle underflow when u is close to 0 */
      METHOD = log_(dmax) + 0.5 * log1p_(u * u)
   END METHOD
   ' ========================================================================================

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
   ' Returns the quotient of the complex numbers a and b, z=a/b.
   ' ========================================================================================
   METHOD Div (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL s AS DOUBLE, z AS tagComplex
      s = 1.0 / ME.Abs(b)
      z.x = (a.x * (s * b.x) + a.y * (s * b.y)) * s
      z.y = (a.y * (s * b.x) - a.x * (s * b.y)) * s
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
      z.y = y * a.x
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
   ' Returns the inverse, or reciprocal, of the complex number z, 1/z = (x - i y)/(x^2 + y^2).
   ' ========================================================================================
   METHOD Inverse (BYREF a AS tagComplex) AS tagComplex
      LOCAL s AS DOUBLE, z AS tagComplex
      s = 1.0 / ME.Abs(a)
      z.x = (a.x * s) * s
      z.y = -(a.y * s) * s
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

   '/* Elementary Complex Functions */

   ' ========================================================================================
   ' Returns the square root of the complex number z, sqrt z. The branch cut is the negative
   ' real axis. The result always lies in the right half of the complex plane.
   ' ========================================================================================
   METHOD Sqrt (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL x, y, w, t, ai, vi AS DOUBLE
      IF a.x = 0 AND a.y = 0 THEN EXIT METHOD
      x = fabs_ (a.x)
      y = fabs_ (a.y)
      IF x => y THEN
         t = y / x
         w = sqrt_ (x) * sqrt_ (0.5 * (1.0 + sqrt_ (1.0 + t * t)))
      ELSE
         t = x / y
         w = sqrt_ (y) * sqrt_ (0.5 * (t + sqrt_ (1.0 + t * t)))
      END IF
      IF a.x => 0 THEN
         ai = a.y
         z.x = w
         z.y = ai / (2.0 * w)
      ELSE
         ai = a.y
         vi = IIF(ai => 0, w, -w)
         z.x = ai / (2.0 * vi)
         z.y = vi
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex square root of the real number x, where x may be negative.
   ' ========================================================================================
   METHOD SqrtReal (BYVAL x AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF x => 0 THEN z.x = sqrt_(x) ELSE z.y = sqrt_(-x)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex number z raised to the complex power a, z^a. This is
   ' computed as exp(log(z)*a) using complex logarithms and complex exponentials.
   ' ========================================================================================
   METHOD Pow (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL logr, theta, rho, beta AS DOUBLE
      IF a.x = 0 AND a.y = 0 THEN
         IF b.x = 0 AND b.y = 0 THEN
            z.x = 1
         END IF
      ELSEIF b.x = 1 AND b.y = 0 THEN
         z = a
      ELSEIF b.x = -1 AND b.y = 0 THEN
         z = ME.Inverse(a)
      ELSE
         logr = ME.LogAbs (a)
         theta = ME.Arg (a)
         rho = exp_ (logr * b.x - b.y * theta)
         beta = theta * b.x + b.y * logr
         z.x = rho * cos_ (beta)
         z.y = rho * sin_ (beta)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex number z raised to the real power x, z^x.
   ' ========================================================================================
   METHOD PowReal (BYREF a AS tagComplex, BYVAL b AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL logr, theta, br, rho, beta AS DOUBLE
      IF a.x = 0 AND a.y = 0 THEN EXIT METHOD
      logr = ME.LogAbs(a)
      theta = ME.Arg(a)
      rho = exp_(logr * b)
      beta = theta * b
      z.x = rho * cos (beta)
      z.y = rho * sin (beta)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex exponential of the complex number z, exp(z).
   ' ========================================================================================
   METHOD Exp (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL rho, theta AS DOUBLE
      rho = exp_(a.x)
      theta = a.y
      z.x = rho * cos_(theta)
      z.y = rho * sin_(theta)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex natural logarithm (base e) of the complex number z, \log(z).
   ' The branch cut is the negative real axis.
   ' ========================================================================================
   METHOD Log (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = ME.Logabs(a)
      z.y = ME.Arg(a)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex base-10 logarithm of the complex number z, \log_10(z).
   ' ========================================================================================
   METHOD Log10 (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Log(a)
      METHOD = ME.MulReal(z, 1 / log_(10))
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex base-b logarithm of the complex number z, log_b(z).
   ' This quantity is computed as the ratio \log(z)/\log(b).
   ' ========================================================================================
   METHOD Log_b (BYREF a AS tagComplex, BYREF b AS tagComplex) AS tagComplex
      LOCAL z1, z2 AS tagComplex
      z1 = ME.Log(a)
      z2 = ME.Log(b)
      METHOD = ME.Div(z1, z2)
   END METHOD
   ' ========================================================================================

   '/* Complex Trigonometric Functions */

   ' ========================================================================================
   ' Returns the complex sine of the complex number
   ' z, sin(z) = (exp(iz) - exp(-iz))/(2i).
   ' ========================================================================================
   METHOD Sin (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      IF a.y = 0 THEN
         z.x = sin_(a.x)
      ELSE
         z.x = sin_(a.x) * cosh_(a.y)
         z.y = cos_(a.x) * sinh_(a.y)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex cosine of the complex number
   ' z, cos(z) = (exp(iz) + exp(-iz))/2.
   ' ========================================================================================
   METHOD Cos (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      IF a.y = 0 THEN
         z.x = cos_(a.x)
      ELSE
         z.x = cos_(a.x) * cosh_(a.y)
         z.y = sin_(a.x) * sinh_(-a.y)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex secant of the complex number z, sec(z) = 1/cos(z).
   ' ========================================================================================
   METHOD Sec (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Cos(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex cosecant of the complex number z, csc(z) = 1/sin(z).
   ' ========================================================================================
   METHOD Csc (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Sin(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex tangent of the complex number z, tan(z) = sin(z)/cos(z).
   ' ========================================================================================
   METHOD Tan (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL u, C, D, S, T AS DOUBLE
      IF fabs_ (a.y) < 1 THEN
         D = pow_(cos_(a.x), 2.0) + pow_(sinh_(a.y), 2.0)
         z.x = 0.5 * sin_(2 * a.x) / D
         z.y = 0.5 * sinh_(2 * a.y) / D
      ELSE
         u = exp_(-a.y)
         C = 2 * u / (1 - pow_(u, 2.0))
         D = 1 + pow_(cos_(a.x), 2.0) * pow_(C, 2.0)
         S = pow_(C, 2.0)
         T = 1.0 / tanh_(a.y)
         z.x = 0.5 * sin_(2 * a.x) * S / D
         z.y = T / D
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex cotangent of the complex number z, cot(z) = 1/tan(z).
   ' ========================================================================================
   METHOD Cot (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Tan(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   '/* Inverse Complex Trigonometric Functions */

   ' ========================================================================================
   ' Returns the complex arcsine of the complex number z, arcsin(z). The
   ' branch cuts are on the real axis, less than -1 and greater than 1.
   ' ========================================================================================
   METHOD ArcSin (BYREF a AS tagComplex) AS tagComplex

      LOCAL z AS tagComplex
      LOCAL x, y, r_, s, A_, B, y2, real, imag AS DOUBLE
      LOCAL A_crossover, B_crossover, D, Apx, Am1 AS DOUBLE

      IF a.y = 0 THEN
         z = ME.ArcSinReal(a.x)
      ELSE
         x = fabs_(a.x)
         y = fabs_(a.y)
         r_ = hypot_(x + 1, y)
         s = hypot_(x - 1, y)
         A_ = 0.5 * (r_ + s)
         B = x / A_
         y2 = y * y
         A_crossover = 1.5#
         B_crossover = 0.6417#
         IF B <= B_crossover THEN
            real = asin_(B)
         ELSE
            IF x <= 1 THEN
               D = 0.5 * (A_ + x) * (y2 / (r_ + x + 1) + (s + (1 - x)))
               real = atan_(x / sqrt_(D))
            ELSE
               Apx = A_ + x
               D = 0.5 * (Apx / (r_ + x + 1) + Apx / (s + (x - 1)))
               real = atan_(x / (y * sqrt_(D)))
            END IF
         END IF
         IF A_ <= A_crossover THEN
            IF x < 1 THEN
               Am1 = 0.5 * (y2 / (r_ + (x + 1)) + y2 / (s + (1 - x)))
            ELSE
               Am1 = 0.5 * (y2 / (r_ + (x + 1)) + (s + (x - 1)))
            END IF
            imag = log1p_(Am1 + sqrt_(Am1 * (A_ + 1)))
         ELSE
            imag = log_(A_ + sqrt_(A_ * A_ - 1))
         END IF
         z.x = IIF(a.x => 0, real, -real)
         z.y = IIF(a.y => 0, imag, -imag)
      END IF

      METHOD = z

   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arcsine of the real number z, arcsin(z).
   ' For z between -1 and 1, the function returns a real value in the range [-pi/2, pi/2].
   ' For z less than -1 the result has a real part of -pi/2 and a positive imaginary part.
   ' For z greater than 1 the result has a real part of pi/2 and a negative imaginary part.
   ' ========================================================================================
   METHOD ArcSinReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF fabs_(a) <= 1 THEN
         z.x = asin_(a)
      ELSE
         IF a < 0 THEN
            z.x = -M_PI_2
            z.y = acosh_(-a)
         ELSE
            z.x = M_PI_2
            z.y = -acosh_(a)
         END IF
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arccosine of the complex number z, arccos(z).
   ' The branch cuts are on the real axis, less than -1 and greater than 1.
   ' ========================================================================================
   METHOD ArcCos (BYREF a AS tagComplex) AS tagComplex

      LOCAL z AS tagComplex
      LOCAL x, y, r_, s, A_, B, y2, real, imag AS DOUBLE
      LOCAL A_crossover, B_crossover, D, Apx, Am1 AS DOUBLE
      IF a.y = 0 THEN
         z = ME.ArcCosReal(a.x)
      ELSE
         x = fabs_(a.x)
         y = fabs_(a.y)
         r_ = hypot_(x + 1, y)
         s = hypot_(x - 1, y)
         A_ = 0.5 * (r_ + s)
         B = x / A_
         y2 = y * y
         A_crossover = 1.5#
         B_crossover = 0.6417#
         IF B <= B_crossover THEN
            real = acos_(B)
         ELSE
            IF x <= 1 THEN
               D = 0.5 * (A_ + x) * (y2 / (r_ + x + 1) + (s + (1 - x)))
               real = atan_(sqrt_(D) / x)
            ELSE
               Apx = A_ + x
               D = 0.5 * (Apx / (r_ + x + 1) + Apx / (s + (x - 1)))
               real = atan_((y * sqrt_(D)) / x)
            END IF
         END IF
         IF A_ <= A_crossover THEN
            IF x < 1 THEN
               Am1 = 0.5 * (y2 / (r_ + (x + 1)) + y2 / (s + (1 - x)))
            ELSE
               Am1 = 0.5 * (y2 / (r_ + (x + 1)) + (s + (x - 1)))
            END IF
            imag = log1p_(Am1 + sqrt_(Am1 * (A_ + 1)))
         ELSE
            imag = log_ (A_ + sqrt_(A_ * A_ - 1))
         END IF
         z.x = IIF(a.x => 0, real, M_PI - real)
         z.y = IIF(a.y => 0, -imag, imag)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arccosine of the real number z, arccos(z).
   ' For z between -1 and 1, the function returns a real value in the range [0, pi].
   ' For z less than -1 the result has a real part of pi and a negative imaginary part.
   ' For z greater than 1 the result is purely imaginary and positive.
   ' ========================================================================================
   METHOD ArcCosReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF fabs_(a) <= 1.0 THEN
         z.x = acos_(a)
      ELSE
         IF a < 0 THEN
            z.x = M_PI
            z.y = -acosh_(-a)
         ELSE
            z.y = acosh_(a)
         END IF
      END IF
      FUNCTION = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arcsecant of the complex number z, arcsec(z) = arccos(1/z).
   ' ========================================================================================
   METHOD ArcSec (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Inverse(a)
      METHOD = ME.ArcCos(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arcsecant of the real number z, arcsec(z) = arccos(1/z).
   ' ========================================================================================
   METHOD ArcSecReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF a <= -1 OR a => 1 THEN
         z.x = acos_(1 / a)
      ELSE
         IF a => 0 THEN
            z.y = acosh_(1 / a)
         ELSE
            z.x = M_PI
            z.y = -acosh_(-1 / a)
         END IF
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arccosecant of the complex number z, arccsc(z) = arcsin(1/z).
   ' ========================================================================================
   METHOD ArcCsc (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Inverse(a)
      METHOD = ME.ArcSin(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arccosecant of the real number z, arccsc(z) = arcsin(1/z).
   ' ========================================================================================
   METHOD ArcCscReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF a <= -1 OR a => 1 THEN
         z.x = asin_(1 / a)
      ELSE
         IF a => 0 THEN
            z.x = M_PI_2
            z.y = -acosh_(1 / a)
         ELSE
            z.x = -M_PI_2
            z.y = acosh_(-1 / a)
         END IF
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' This method returns the complex arctangent of the complex number z, arctan(z).
   ' The branch cuts are on the imaginary axis, below -i and above i.
   ' ========================================================================================
   METHOD ArcTan (BYREF a AS tagComplex) AS tagComplex

      LOCAL z AS tagComplex
      LOCAL r_, imag, u, A_, B AS DOUBLE

      IF a.y = 0 THEN
         z.x = atan_(a.x)
      ELSE
         ' /* FIXME: This is a naive implementation which does not fully
         '    take into account cancellation errors, overflow, underflow
         '    etc.  It would benefit from the Hull et al treatment. */
         r_ = hypot_ (a.x, a.y)
         u = 2 * a.y / (1 + r_ * r_)

         ' /* FIXME: the following cross-over should be optimized but 0.1
         '    seems to work ok */
         IF fabs_ (u) < 0.1 THEN
            imag = 0.25 * (log1p_(u) - log1p_(-u))
         ELSE
            A_ = hypot_(a.x, a.y + 1)
            B = hypot_(a.x, a.y - 1)
            imag = 0.5 * log_ (A_ / B)
         END IF

         IF a.x = 0 THEN
            IF a.y > 1 THEN
               z.x = M_PI_2
               z.y = imag
            ELSEIF a.y < -1 THEN
               z.x = -M_PI_2
               z.y = imag
            ELSE
               z.y = imag
            END IF
         ELSE
            z.x = 0.5 * atan2_(2 * a.x, ((1 + r_) * (1 - r_)))
            z.y = imag
         END IF
      END IF

      METHOD = z

   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex arccotangent of the complex number z, arccot(z) = arctan(1/z).
   ' ========================================================================================
   METHOD ArcCot (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      IF a.x = 0 AND a.y = 0 THEN
         z.x = M_PI_2
      ELSE
         z = ME.Inverse(a)
         z = ME.ArcTan(z)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   '/* Complex Hyperbolic Functions */

   ' ========================================================================================
   ' Returns the complex hyperbolic sine of the complex number
   ' z, sinh(z) = (exp(z) - exp(-z))/2.
   ' ========================================================================================
   METHOD SinH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = sinh_(a.x) * cos_(a.y)
      z.y = cosh_(a.x) * sin_(a.y)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic cosine of the complex number
   ' z, cosh(z) = (exp(z) + exp(-z))/2.
   ' ========================================================================================
   METHOD CosH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z.x = cosh_(a.x) * cos_(a.y)
      z.y = sinh_(a.x) * sin_(a.y)
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic secant of the complex number z, sech(z) = 1/cosh(z).
   ' ========================================================================================
   METHOD SecH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.CosH(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic cosecant of the complex number z, csch(z) = 1/sinh(z).
   ' ========================================================================================
   METHOD CscH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.SinH(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic tangent of the complex number
   ' z, tanh(z) = sinh(z)/cosh(z).
   ' ========================================================================================
   METHOD TanH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      LOCAL D, F AS DOUBLE
      IF fabs_(a.x) < 1 THEN
         D = pow_(cos_(a.y), 2.0) + pow_(sinh_(a.x), 2.0)
         z.x = sinh_(a.x) * cosh_(a.x) / D
         z.y = 0.5 * sin_(2 * a.y) / D
      ELSE
         D = pow_(cos_(a.y), 2.0) + pow_(sinh_(a.x), 2.0)
         F = 1 + pow_(cos_(a.y) / sinh_(a.x), 2.0)
         a.x = 1.0 / (tanh_(a.x) * F)
         z.y = 0.5 * sin_(2 * a.y) / D
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic cotangent of the complex number z, coth(z) = 1/tanh(z).
   ' ========================================================================================
   METHOD CotH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.TanH(a)
      METHOD = ME.Inverse(z)
   END METHOD
   ' ========================================================================================

   '/* Inverse Complex Hyperbolic Functions */

   ' ========================================================================================
   ' Returns the complex hyperbolic arcsine of the complex number z, arcsinh(z).
   ' The branch cuts are on the imaginary axis, below -i and above i.
   ' ========================================================================================
   METHOD ArcSinH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.MulImag(a, 1)
      z = ME.ArcSin(z)
      METHOD = ME.MulImag(z, -1)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arccosine of the complex number z, arccosh(z).
   ' The branch cut is on the real axis, less than 1.
   ' ========================================================================================
   METHOD ArcCosH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.ArcCos(a)
      METHOD = ME.MulImag(z, IIF(z.y > 0, -1, 1))
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arccosine of the real number z, arccosh(z).
   ' ========================================================================================
   METHOD ArcCoshReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF a => 1 THEN
         z.x = acosh_(a)
      ELSE
         IF a => -1 THEN
            z.y = acos_(a)
         ELSE
            z.x = acosh_(-a)
            z.y = M_PI
         END IF
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arcsecant of the complex number
   ' z, arcsech(z) = arccosh(1/z).
   ' ========================================================================================
   METHOD ArcSecH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Inverse(a)
      METHOD = ME.ArcCosH(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arccosecant of the complex number
   ' z, arccsch(z) = arcsin(1/z).
   ' ========================================================================================
   METHOD ArcCscH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Inverse(a)
      METHOD = ME.ArcSinH(z)
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arctangent of the complex number z, arctanh(z).
   ' The branch cuts are on the real axis, less than -1 and greater than 1.
   ' ========================================================================================
   METHOD ArcTanH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      IF a.y = 0 THEN
         z = ME.ArcTanhReal(a.x)
      ELSE
         z = ME.MulImag(a, 1)
         z = ME.ArcTan(z)
         z = ME.MulImag(z, -1)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arctangent of the real number z, arctanh(z).
   ' ========================================================================================
   METHOD ArcTanhReal (BYVAL a AS DOUBLE) AS tagComplex
      LOCAL z AS tagComplex
      IF a > -1 AND a < 1 THEN
         z.x = atanh_(a)
      ELSE
         z.x = atanh_(1 / a)
         z.y = IIF(a < 0, M_PI_2, -M_PI_2)
      END IF
      METHOD = z
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the complex hyperbolic arccotangent of the complex number
   ' z, arccoth(z) = arctanh(1/z).
   ' ========================================================================================
   METHOD ArcCotH (BYREF a AS tagComplex) AS tagComplex
      LOCAL z AS tagComplex
      z = ME.Inverse(a)
      METHOD = ME.ArcTanH(z)
   END METHOD
   ' ========================================================================================

END INTERFACE

END CLASS
' ########################################################################################
