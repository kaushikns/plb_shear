/* This file is part of the Palabos library.
Author: Kaushik N Shankar
*/

/** \file
 * Data processors for data analysis -- header file.
 */

#ifndef SHEAR_STRESS_FUNCTIONAL_3D_H
#define SHEAR_STRESS_FUNCTIONAL_3D_H

namespace plb {

template<typename T, template<typename U> class Descriptor> 
class ShearSingleProbe3D :
    public ReductiveBoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    ShearSingleProbe3D(std::vector<Array<T,3> > const& positions_);
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual ShearSingleProbe3D<T,Descriptor>* clone() const;
    virtual void getTypeOfModification(std::vector<modif::ModifT>& modified) const {
        modified[0] = modif::nothing;
    }
    std::vector<Array<T,6> > getShearStresses() const;
private:
    std::vector<Array<T,3> > positions;
    std::vector<Array<plint,6> > shearIds;
};

}  // namespace plb

#include "shearStressFunctional3D.hh"

#endif  // SHEAR_STRESS_FUNCTIONAL_3D_H



