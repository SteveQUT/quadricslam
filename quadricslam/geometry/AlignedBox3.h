/* ----------------------------------------------------------------------------

 * QuadricSLAM Copyright 2020, ARC Centre of Excellence for Robotic Vision, Queensland University of Technology (QUT)
 * Brisbane, QLD 4000
 * All Rights Reserved
 * Authors: Lachlan Nicholson, et al. (see THANKS for the full author list)
 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 * @file AlignedBox3.h
 * @date Apr 14, 2020
 * @author Lachlan Nicholson
 * @brief an axis aligned 3D bounding box
 */

#pragma once

#include <gtsam/geometry/Pose3.h>

#include <vector>

namespace gtsam {

  /**
   * @class AlignedBox3
   * An axis aligned 3D bounding box
   */
  class GTSAM_EXPORT AlignedBox3 {

    protected:
      Vector6 xxyyzz_; ///< bounds vector 

    public:
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

      /// @name Constructors and named constructors
      /// @{

      /** Default constructor */
      AlignedBox3() { xxyyzz_.setZero();};
      
      /** Constructor from doubles */
      AlignedBox3(const double& xmin, const double& xmax, const double& ymin, const double& ymax, const double& zmin, const double& zmax);
      
      /** Constructor from vector */
      AlignedBox3(const Vector6& xxyyzz);

      /// @}
      /// @name Class methods
      /// @{

      /** Get xmin */
      double xmin() const {return xxyyzz_[0];}

      /** Get xmax */
      double xmax() const {return xxyyzz_[1];}

      /** Get ymin */
      double ymin() const {return xxyyzz_[2];}

      /** Get ymax */
      double ymax() const {return xxyyzz_[3];}

      /** Get zmin */
      double zmin() const {return xxyyzz_[4];}

      /** Get zmax */
      double zmax() const {return xxyyzz_[5];}

      /** Returns box in xxyyzz vector */
      Vector6 vector() const;

      /** Returns x,y,z lengths as a vector */
      Vector3 dimensions() const;

      /** Returns box centroid as x,y,z vector */
      Vector3 centroid() const;

      /// @}
      /// @name Testable group traits
      /// @{
        
      /** Prints the box vector with optional string */
      void print(const std::string& s = "") const;

      /** Compares two boxes */
      bool equals(const AlignedBox3& other, double tol = 1e-9) const;

      /// @}
  };

} // namespace gtsam
