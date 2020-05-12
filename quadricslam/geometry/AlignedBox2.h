/* ----------------------------------------------------------------------------

 * QuadricSLAM Copyright 2020, ARC Centre of Excellence for Robotic Vision, Queensland University of Technology (QUT)
 * Brisbane, QLD 4000
 * All Rights Reserved
 * Authors: Lachlan Nicholson, et al. (see THANKS for the full author list)
 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 * @file AlignedBox2.h
 * @date Apr 14, 2020
 * @author Lachlan Nicholson
 * @brief an axis aligned 2D bounding box
 */

#pragma once

#include <gtsam/geometry/Pose3.h>

#include <vector>

namespace gtsam {

  /**
   * @class AlignedBox2
   * An axis aligned 2D bounding box (xmin,ymin,xmax,ymax)
   */
  class GTSAM_EXPORT AlignedBox2 {

    protected:
      Vector4 tlbr_; ///< xmin,ymin,xmax,ymax

    public:
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

      /// @name Constructors and named constructors
      /// @{

      /** Default constructor */
      AlignedBox2() : tlbr_(0,0,0,0) {};
      
      /** Constructor from bounds */
      AlignedBox2(const double& xmin, const double& ymin, const double& xmax, const double& ymax);

      /**
       * Constructor from vector
       * @param tlbr vector of xmin,ymin,xmax,ymax (Vector4)
       */
      AlignedBox2(const Vector4& tlbr);

      /// @}
      /// @name Class methods
      /// @{

      /** Get xmin */
      double xmin() const { return tlbr_[0];}

      /** Get ymin */
      double ymin() const { return tlbr_[1];}

      /** Get xmax */
      double xmax() const { return tlbr_[2];}

      /** Get ymax */
      double ymax() const { return tlbr_[3];}

      /** Returns box in xmin,ymin,xmax,ymax vector */
      Vector4 vector() const;

      /** Returns Point2(xmin, ymin) */
      Point2 minPoint() const {return Vector2(xmin(), ymin());}

      /** Returns Point2(xmax, ymax) */
      Point2 maxPoint() const {return Vector2(xmax(), ymax());}

      /** Returns equation of boxes lines */
      std::vector<Vector3> lines() const;

      /** 
       * Returns true if this contains the point 
       * Points intersecting a line are considered containing
       */
      bool contains(const Point2& point) const;

      /** 
       * Returns true if this completely contains or intersects other
       */
      bool contains(const AlignedBox2& other) const;

      /** 
       * Returns true if this completely contains other box 
       * Lines ontop of eachother are considered containing
      */
      bool completelyContains(const AlignedBox2& other) const;

      /** Returns true if this intersects other box */
      bool intersects(const AlignedBox2& other) const;

      /// @}
      /// @name Testable group traits
      /// @{
        
      /** Prints the box vector with optional string */
      void print(const std::string& s = "") const;

      /** Compares two boxes */
      bool equals(const AlignedBox2& other, double tol = 1e-9) const;

      /// @}
  };

  // Add dimensions for expressions
  template <>
  struct traits<AlignedBox2> {
    enum { dimension = 4 };
  };

  // Add vector<> typedef for python wrapper
  typedef std::vector<Vector3> Vector3Vector;


} // namespace gtsam
