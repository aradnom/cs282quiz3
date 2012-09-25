#include <memory>
#include <vector>
#include "gtest/gtest.h"

#include "Triangle.cpp"
#include "Square.cpp"
#include <iostream>

const float PI = 3.14159265f;

TEST(Shapes, DrawTriangle) {
  Triangle t{1.0f};
  EXPECT_EQ("drew a triangle", t.draw());
}

TEST(Shapes, DrawSquare) {
  Square s{1.0f};
  EXPECT_EQ("drew a square", s.draw());
}

TEST(ShapePtr, DrawSquare) {
  // change this to make the test pass
	auto s = std::make_shared<Square>( 1.0f ); 	

  EXPECT_EQ("drew a square", s->draw());
}

TEST(Shapes, BunchOfSquaresArea) {
  // change these to make the test pass
	auto sq_ptr1 = std::make_shared<Square>( 1.0f );
	auto sq_ptr2 = std::make_shared<Square>( 1.0f );
	auto sq_ptr3 = std::make_shared<Square>( 1.0f );

  EXPECT_FLOAT_EQ(3.0f, sq_ptr1->area() + 
		  sq_ptr2->area() + sq_ptr3->area());
}

TEST(Shapes, BunchOfTrianglesArea) {
  // change these to make the tests pass.
	auto t_ptr1 = std::make_shared<Triangle>( 1.0f );
	auto t_ptr2 = std::make_shared<Triangle>( 1.0f );
	auto t_ptr3 = std::make_shared<Triangle>( 1.0f );

  EXPECT_FLOAT_EQ(3.0f * 0.5f, t_ptr1->area() + 
		  t_ptr2->area() + t_ptr3->area());
}

TEST(Shapes, DifferentShapes) {
  // change the assignments so that the test becomes true.
	auto sq_ptr1 = std::make_shared<Square>( 4.0 );
	auto t_ptr1 = std::make_shared<Triangle>( 9.0f );
	auto t_ptr2 = std::make_shared<Triangle>( 1.0f );

  EXPECT_FLOAT_EQ(4.0 * 4.0 + 0.5f * 9.0f * 9.0f + 0.5f,
		  sq_ptr1->area() + t_ptr1->area() + t_ptr2->area());
}

TEST(ShapeVec, AreasSumCorrectly) {
  std::vector<std::shared_ptr<Shape> > drawingBoard{};

	auto sq_ptr1 = std::make_shared<Square>( 1.0 );
	auto t_ptr1 = std::make_shared<Triangle>( 1.0f );

  	drawingBoard.push_back( sq_ptr1 ); 
	drawingBoard.push_back( sq_ptr1 );
	drawingBoard.push_back( sq_ptr1 );

	drawingBoard.push_back( t_ptr1 ); 
	drawingBoard.push_back( t_ptr1 );
	drawingBoard.push_back( t_ptr1 );

  float areas = 0.0f;
  for (const auto & s : drawingBoard) {
    areas += s->area();
  }

  EXPECT_FLOAT_EQ(3.0f + 1.5f, areas);
}
