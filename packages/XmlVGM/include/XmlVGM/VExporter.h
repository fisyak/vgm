// $Id$
//
// Class VExporter
// --------------------
// Class for generation of geometry data files in XML,
// the XML format is independent from the geometry object model. 
// It has one abstract method for processing the volume tree
// that has to be provided by derived classes.
//
// Author: I. Hrivnacova, 19.1.2004

#ifndef XML_VGM_V_EXPORTER_H
#define XML_VGM_V_EXPORTER_H

#include <fstream>
#include <string>
#include <set>
#include <map>

#include "VGM/materials/IElement.h"
#include "VGM/materials/IMaterial.h"
#include "VGM/volumes/IFactory.h"
#include "VGM/volumes/IVolume.h"

#include "XmlVGM/Maps.h"

namespace XmlVGM {

  typedef std::vector<double> ThreeVector;

  class IWriter;
  
  class VExporter
  {
    public:
      typedef std::set <std::string, 
                        std::less<std::string> >  StringSet; 

    public:
      VExporter(const VGM::IFactory* factory,
                IWriter* writer);
      // --> protected
      // VExporter();
      // VExporter(const VExporter& right);
      virtual ~VExporter();
 
      // methods
      void GenerateXMLGeometry();
      void GenerateXMLGeometry(const std::string& volumeName);

      // set methods
      void SetFileName(const std::string& fileName);
      void SetDebug(int debug);

      // get methods
      std::string FileName() const;
      int  Debug() const;

    protected:
      VExporter();
      VExporter(const VExporter& right);

      // operators
      VExporter& operator=(const VExporter& /*right*/);

      // abstract methods
      // specific to XML definition
      //
      virtual void GenerateGeometry(VGM::IVolume* volume) = 0;

      // methods
      //
      void GeneratePositions(VGM::IVolume* volume);
      void GenerateRotations(VGM::IVolume* volume);
      void GenerateMaterials(VGM::IVolume* volume);
      void GenerateSolids(VGM::IVolume* volume);

      void ClearVolumeNames();
      
      // static data members
      static const std::string fgkUndefinedFileName; //default value of file name
                                     
      // data members
      //
      const VGM::IFactory*  fFactory; // VGM factory 
      IWriter*       fWriter;         // interface to XML writer 
      std::string    fFileName;       // output file name
      StringSet      fVolumeNames;    // set of volume names
      int            fDebug;          // debug level
      Maps           fMaps; // maps between XML elements and their names

    private:
      // methods
      //
      void ProcessPositions(VGM::IVolume* volume); 
      void ProcessRotations(VGM::IVolume* volume); 
      void ProcessMaterials(VGM::IVolume* volume); 
      void ProcessSolids(VGM::IVolume* volume); 
  };
}

// inline methods

inline void XmlVGM::VExporter::SetFileName(const std::string& fileName)
{ fFileName = fileName; }

inline void XmlVGM::VExporter::SetDebug(int debug)
{ fDebug = debug; }

inline std::string XmlVGM::VExporter::FileName() const
{ return fFileName; }

inline int XmlVGM::VExporter::Debug() const
{ return fDebug; }

#endif //XML_VGM_V_EXPORTER_H
