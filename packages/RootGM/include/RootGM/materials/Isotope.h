// $Id$

// -----------------------------------------------------------------------
// The RootGM package of the Virtual Geometry Model
// Copyright (C) 2007, Ivana Hrivnacova               
// All rights reserved. 
//           
// For the licensing terms see vgm/LICENSE.
// Contact: ivana@ipno.in2p3.fr
// -----------------------------------------------------------------------

/// \ingroup RootGM_materials
//
/// \class RootGM:: Isotope
///
/// VGM implementation for Root isotope.
///
/// \author Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_ISOTOPE_H
#define ROOT_GM_ISOTOPE_H

#include <string>

#include "VGM/materials/IIsotope.h"

namespace RootGM {

  class Isotope : public virtual VGM::IIsotope
  {
    public:
      Isotope(const std::string& name, int z, int n, double a);
      Isotope(const Isotope& rhs);
      Isotope();
      virtual ~Isotope();
      
      // operators
      Isotope& operator=(const Isotope& rhs);
    
      // methods
      virtual std::string Name() const;

      virtual int     Z() const;     
      virtual int     N() const;     
      virtual double  A() const;     
    
    private:
      std::string   fName;
      int     fZ;
      int     fN;
      double  fA; 
  };
  
}  

#endif //ROOT_GM_ISOTOPE_H
