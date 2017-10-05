//
//  Loop.hpp
//
//  Sketchup C++ Wrapper for C API
//  Copyright (C) 2016  Hidetomo (Tom) Kaneko
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef Loop_hpp
#define Loop_hpp

#include <stdio.h>
#include <vector>
//#include "SUAPI-CppWrapper/DrawingElement.hpp"
//#include "SUAPI-CppWrapper/Edge.hpp"

//#include <SketchUpAPI/geometry.h>
//#include <SketchUpAPI/model/geometry_input.h>
#include <SketchUpAPI/model/loop.h>

namespace CW {

// Forward Declarations
class LoopInput;
class Edge;
class Vertex;
class Point3D;

/**
* PointLoopClassify is used to describe where a point sits on a loop object.
*/
enum class PointLoopClassify {
	PointOutside,
  PointInside,
  PointOnVertex,
  PointOnEdge,
  PointNotOnPlane,
  PointUnknown // indicates an error
};

/**
* A face is made up of an outer loop and inner loops.
*/
class Loop {
  private:
  SULoopRef m_loop;
  
  public:
  /*
  * Creates a Loop object from the SULoopRef.
  * @param SULoopRef object that is already attached to a SUFaceRef
  */
  Loop(SULoopRef loop);
  
  /**
  * Creates an invalid Loop object.
  */
  Loop();
  
  /**
  * Tests for valid object.
  */
  bool operator!() const;

  /*
  * Returns the LoopInput object for this loop. A SULoopInputRef will be created using the values of the original SULoopRef object.
  */
  LoopInput loop_input() const;
  
  /**
  * Returns the Edges in the Loop
  */
  std::vector<Edge> edges() const;

  /**
  * Returns the Vertices in the Loop
  */
  std::vector<Vertex> vertices() const;
  
  /**
  * Returns the points representing the vertices in the Loop
  */
  std::vector<Point3D> points() const;
  
  /**
  * Determine where on the loop a point lies.  @see PointLoopClassify.
  * @param point - the Point3D object ot check.
  */
  PointLoopClassify classify_point(const Point3D& point) const;
  
  /**
  * Returns the number of edges/vertices in the loop.
  */
  size_t size() const;
  
  /**
  * Returns the SULoopRef object stored in this loop.
  */
  SULoopRef ref() const;
  
  /**
  * Returns whether a point is within a loop, given by the vector of points.
  * @param loop_points - a vector of points representing the vertices of a loop.
  * @param test_point - the point to test within the loop.
  * @return PointLoopClassify object describing the location of the point relative to the loop.
  */
  static PointLoopClassify classify_point(const std::vector<Point3D>& loop_points, const Point3D& test_point);
  
};

} /* namespace CW */
#endif /* Loop_hpp */
