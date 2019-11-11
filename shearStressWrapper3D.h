/* This file is part of the Palabos library.
Author: Kaushik N Shankar
*/

/** \file
 * Data processors for data analysis -- header file.
 */

#ifndef SHEAR_STRESS_WRAPPER_3D_H
#define SHEAR_STRESS_WRAPPER_3D_H

#include "shearStressFunctional3D.h"
#include "shearStressFunctional3D.hh"

namespace plb {

template<typename T, template<typename U> class Descriptor>
std::vector<Array<T,6> > shearSingleProbes (
        MultiBlockLattice3D<T,Descriptor>& lattice,
        std::vector<Array<T,3> > const& positions );

}  // namespace plb

#include "shearStressWrapper3D.hh"
 
#endif  // SHEAR_STRESS_WRAPPER_3D_H



