// $Id$
//
// Taken from Geant4 (G3toG4RotationMatrix) 
// ------------------------------------------
// Class description:
//
// An "extended" rotation matrix class.
// The SetRotationMatrixByCol/Row() methods enables
// to define the rotation matrix by column/row vectors.
// The result matrix may be a matrix that does not
// represent a rotation transformation (!) as
// G3 "rotation" matrices can be a composition of
// rotation and reflection.  

// --------------------------------------------

#include "RootGM/common/RotationMatrix.h"

RootGM::RotationMatrix::RotationMatrix()
{
  rxx = 1;
  ryx = 0;
  rzx = 0;
  rxy = 0;
  ryy = 1;
  rzy = 0;
  rxz = 0;
  ryz = 0;
  rzz = 1;
}

RootGM::RotationMatrix::~RotationMatrix()
{
    ;
}

void 
RootGM::RotationMatrix::SetRotationMatrixByCol(
                           const Hep3Vector& col1,
                           const Hep3Vector& col2,
                           const Hep3Vector& col3)
{
  rxx = col1.x();
  ryx = col1.y();
  rzx = col1.z();
  
  rxy = col2.x();
  ryy = col2.y();
  rzy = col2.z();
  
  rxz = col3.x();
  ryz = col3.y();
  rzz = col3.z();
  
}

void 
RootGM::RotationMatrix::SetRotationMatrixByRow(
                           const Hep3Vector& row1,
                           const Hep3Vector& row2,
                           const Hep3Vector& row3)
{
  rxx = row1.x();
  rxy = row1.y();
  rxz = row1.z();
  
  ryx = row2.x();
  ryy = row2.y();
  ryz = row2.z();
  
  rzx = row3.x();
  rzy = row3.y();
  rzz = row3.z();
  
}



