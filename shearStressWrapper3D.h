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



