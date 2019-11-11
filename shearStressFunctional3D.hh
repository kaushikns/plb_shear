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
 * Utilities to help users handle data processors -- header file.
 */
#ifndef SHEAR_STRESS_FUNCTIONAL_3D_HH
#define SHEAR_STRESS_FUNCTIONAL_3D_HH

namespace plb {

template<typename T, template<typename U> class Descriptor>
void ShearSingleProbe3D<T,Descriptor>::process (
        Box3D domain, BlockLattice3D<T,Descriptor>& lattice )
{
    std::vector<Dot3D> cellPos(8);
    std::vector<T> weights(8);
    Array<T,6> shearStress;
    for (pluint iShear=0; iShear<positions.size(); ++iShear) {
        shearStress.resetToZero();
        Array<T,3> position(positions[iShear]);
        Dot3D referenceCellPos((plint)position[0], (plint)position[1], (plint)position[2]);
        referenceCellPos -= lattice.getLocation();
        if (contained(referenceCellPos, domain)) {
            linearInterpolationCoefficients(lattice, position, cellPos, weights);
            for (plint iCell=0; iCell<8; ++iCell) {
                Cell<T,Descriptor> const& cell = lattice.get(cellPos[iCell].x,cellPos[iCell].y,cellPos[iCell].z);
                Array<T,6> cellShear;
                cell.computeShearStress(cellShear);
                shearStress+=weights[iCell]*cellShear;
            }
        }
       this->getStatistics().gatherSum(shearIds[iShear][0], shearStress[0]);
       this->getStatistics().gatherSum(shearIds[iShear][1], shearStress[1]);
       this->getStatistics().gatherSum(shearIds[iShear][2], shearStress[2]);
       this->getStatistics().gatherSum(shearIds[iShear][3], shearStress[3]);
       this->getStatistics().gatherSum(shearIds[iShear][4], shearStress[4]);
       this->getStatistics().gatherSum(shearIds[iShear][5], shearStress[5]);
    }
}

template<typename T, template<typename U> class Descriptor>
ShearSingleProbe3D<T,Descriptor>*
    ShearSingleProbe3D<T,Descriptor>::clone() const
{
    return new ShearSingleProbe3D<T,Descriptor>(*this);
}

template<typename T, template<typename U> class Descriptor>
std::vector<Array<T,6> > ShearSingleProbe3D<T,Descriptor>::getShearStresses() const {
    std::vector<Array<T,6> > shearStresses(positions.size());
    for (pluint iShear=0; iShear<positions.size(); ++iShear) {
        shearStresses[iShear][0] = this->getStatistics().getSum(shearIds[iShear][0]);
        shearStresses[iShear][1] = this->getStatistics().getSum(shearIds[iShear][1]);
        shearStresses[iShear][2] = this->getStatistics().getSum(shearIds[iShear][2]);
        shearStresses[iShear][3] = this->getStatistics().getSum(shearIds[iShear][3]);
        shearStresses[iShear][4] = this->getStatistics().getSum(shearIds[iShear][4]);
        shearStresses[iShear][5] = this->getStatistics().getSum(shearIds[iShear][5]);
    }
    return shearStresses;
}

} // namespace plb

#endif // SHEAR_STRESS_FUNCTIONAL_3D_HH
