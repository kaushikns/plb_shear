/* This file is part of the Palabos library.
 *
 * Copyright (C) 2011-2017 FlowKit Sarl
 * Route d'Oron 2
 * 1010 Lausanne, Switzerland
 * E-mail contact: contact@flowkit.com
 *
 * The most recent release of Palabos can be downloaded at 
 * <http://www.palabos.org/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
    ShearSingleProbe3D(std::vector<Array<T,3> > const& positions_) : 
        positions (positions_) {}
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



