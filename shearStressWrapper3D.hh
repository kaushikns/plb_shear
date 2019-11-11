/* This file is part of the Palabos library.
Author: Kaushik N Shankar
*/

/** \file
 * Utilities to help users handle data processors -- header file.
 */
#ifndef SHEAR_STRESS_WRAPPER_3D_HH
#define SHEAR_STRESS_WRAPPER_3D_HH

#include "shearStressFunctional3D.h"
#include "shearStressFunctional3D.hh"

namespace plb {

template<typename T, template<typename U> class Descriptor>
std::vector<Array<T,6> > shearSingleProbes (
        MultiBlockLattice3D<T,Descriptor>& lattice,
        std::vector<Array<T,3> > const& positions )
{
    ShearSingleProbe3D<T,Descriptor> functional(positions);;
    applyProcessingFunctional(functional, lattice.getBoundingBox(), lattice);
    return functional.getShearStresses();
}

} // namespace plb

#endif // SHEAR_STRESS_WRAPPERS_3D_HH
