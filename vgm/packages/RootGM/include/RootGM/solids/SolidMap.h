// $Id$
//
// Class SolidMap
// ---------------
// The map between VGM and Root solids.
//
// Author: Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_SOLID_MAP_H
#define ROOT_GM_SOLID_MAP_H

#include <map>

#include "TGeoShape.h"

#include "VGM/solids/ISolid.h"

namespace RootGM {

  class SolidMap;

  class SolidMap
  {
    public:
      typedef std::map<VGM::ISolid*, TGeoShape*>  RootSolidMap;
      typedef RootSolidMap::const_iterator        RootSolidMapCIterator;

      typedef std::map<TGeoShape*, VGM::ISolid*>  VgmSolidMap;
      typedef VgmSolidMap::const_iterator         VgmSolidMapCIterator;

    public:
      SolidMap();
      virtual ~SolidMap();

      // static access methods
      static SolidMap* Instance(); 

      // methods
      void  AddSolid(VGM::ISolid*, TGeoShape*); 

      // get methods
      TGeoShape*    GetSolid(VGM::ISolid* iSolid) const;
      VGM::ISolid*  GetSolid(TGeoShape* solid) const;

    private:
      SolidMap(const SolidMap&);

      // static data members
      static SolidMap*  fgInstance;
  
      // data members
      RootSolidMap  fRootSolids;
      VgmSolidMap   fVgmSolids;
  };

}

#endif //ROOT_GM_SOLID_MAP_H