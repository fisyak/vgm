// $Id$
/// \ingroup RootGM_common
//
/// \class RootGM:: Units
///
/// Conversion from Root physical units to VGM units.
///
/// Author: Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_UNITS_H
#define ROOT_GM_UNITS_H

#include "VGM/common/Axis.h"

namespace RootGM {

  class Units
  {
    public:
      // --> protected
      // Units();  
      virtual ~Units();
  
      //
      // static get methods
      //
      
                    /// Return Root length unit in VGM units
		    ///
      static double Length(); 

                    /// Return Root angle unit in VGM units
		    ///
      static double Angle(); 

                    /// Return Root unit for the given axis in VGM units
		    ///
      static double AxisUnit(VGM::Axis axis); 

                    /// Return Root mass density unit in VGM units
		    ///
      static double MassDensity(); 

                    /// Return Root atomic weight unit in VGM units
		    ///
      static double AtomicWeight();     
      
    protected:
      Units();      
          // only static data members and methods

    private:
      // static data members  
      static const double fgkLength; 
      static const double fgkAngle;  
      static const double fgkMassDensity;
      static const double fgkAtomicWeight;
  }; 
  
}      

// inline methods

inline double RootGM::Units::Length()       { return fgkLength; }
inline double RootGM::Units::Angle()        { return fgkAngle; }
inline double RootGM::Units::MassDensity()  { return fgkMassDensity; }
inline double RootGM::Units::AtomicWeight() { return fgkAtomicWeight; }

#endif //ROOT_GM_UNITS_H
