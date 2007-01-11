// $Id$
/// \ingroup RootGM_materials
//
/// \class RootGM:: Element
///
/// VGM implementation for Root element.
///
/// Author: Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_ELEMENT_H
#define ROOT_GM_ELEMENT_H

#include <string>

#include "VGM/materials/IElement.h"

namespace RootGM {

  class Element : public virtual VGM::IElement
  {
    public:
      Element(const std::string& name, 
              const std::string& symbol,      
              double z, double a); 

      Element(const std::string& name, 
              const std::string& symbol,      
	      const VGM::IsotopeVector& isotopes,
              const VGM::RelAbundanceVector& relAbundances);
              
      Element(const Element& rhs);
      Element();
      virtual ~Element();
      
      // operators
      Element& operator=(const Element& rhs);
    
      // methods
      virtual std::string Name() const;
      virtual std::string Symbol() const;

      virtual double  Z() const;     
      virtual double  N() const;     
      virtual double  A() const;     

      virtual int     NofIsotopes() const;
      virtual VGM::IIsotope*  Isotope(int i) const;
      virtual double  RelAbundance(int i) const;
    
    private:
      void   CheckIndex(int iel) const;

      std::string   fName;
      std::string   fSymbol;
      double  fZ;
      double  fN;
      double  fA; 
      VGM::IsotopeVector       fIsotopes;
      VGM::RelAbundanceVector  fRelAbundances;
  };
  
}  

#endif //ROOT_GM_ELEMENT_H
