/** \file ps5function.h
 */
#if !defined phy1610_ps5_ps5function_h_included
#define phy1610_ps5_ps5function_h_included

/**
   A gsl function parameter object, also supplying the function pointers for both the interval and
   derivative solvers.
 */
struct ps5function
{
   /**
      Returns \f[
                 f(x) = (\exp(1-x^2) -1) e^{\sin x}
              \f]

      \param x [in]
         Point at which to evaluate \f[ f(x) \f]

      \param params [in]
         ununsed
     */
   static double function( double x, void * params ) ;

   /**
      Returns \f[ \frac{d}{dx} \left(
                 (\exp(1-x^2) -1) e^{\sin x}
                 \right)
              \f]

      \param x [in]
         Point at which to evaluate \f[ f(x) \f]

      \param params [in]
         ununsed
     */
   static double derivative( double x, void * params ) ;

   /**
      Return both the function and the derivative.

      \param x [in]
         Evaluation point.

      \param params [in]
         ununsed

      \param y [out]
         \f[ f(x) \f]

      \param y [out]
         \f[ f'(x) \f]
     */
   static void functionAndDerivative( double x, void * params, double * y, double * dy ) ;

   /**
      Convience method to evaluate the function at this point without explicitly using function pointers.
    */
   double operator() ( const double x ) const
   {
      // gsl functions take void *, not const void *, to this needs coersion:
      return function( x, const_cast<ps5function*>(this) ) ;
   }

   /**
      For verbose output loops to show how close we are to the expected root.
    */
   static inline double expectedRoot()
   {
      // -1.0 is also a root, but we expect the positive root for bracket methods that contain x = 1.
      return 1.0 ;
   }
} ;

#endif
