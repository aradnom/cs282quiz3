#include <memory>
#include <vector>
#include "gtest/gtest.h"

#include "Circle.cpp"
#include "Square.cpp"
#include <iostream>

const float PI = 3.14159265f;

TEST(Shapes, DrawCircle) {
  Circle c{1.0f};
  EXPECT_EQ("drew a circle", c.draw());
}

TEST(Shapes, DrawSquare) {
  Square s{1.0f};
  EXPECT_EQ("drew a square", s.draw());
}

TEST(ShapePtr, DrawSquare) {
  // change this to make the test pass
	//Shape* test = new Square( 1.0f );
	auto s = std::make_shared<Square>( 1.0f );
	//std::shared_ptr<Square> s = Square( 1.0f );
 	

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

TEST(Shapes, BunchOfCirclesArea) {
  // change these to make the tests pass.
	auto c_ptr1 = std::make_shared<Circle>( 1.0f );
	auto c_ptr2 = std::make_shared<Circle>( 1.0f );
	auto c_ptr3 = std::make_shared<Circle>( 1.0f );

  EXPECT_FLOAT_EQ(3.0f * PI, c_ptr1->area() + 
		  c_ptr2->area() + c_ptr3->area());
}

TEST(Shapes, DifferentShapes) {
  // change the assignments so that the test becomes true.
	auto sq_ptr1 = std::make_shared<Square>( 4.0 );
	auto c_ptr1 = std::make_shared<Circle>( 9.0f );
	auto c_ptr2 = std::make_shared<Circle>( 1.0f );

  EXPECT_FLOAT_EQ(4.0 * 4.0 + PI + 9.0f * 9.0f * PI,
		  sq_ptr1->area() + c_ptr1->area() + c_ptr2->area());
}

TEST(ShapeVec, AreasSumCorrectly) {
  std::vector<std::shared_ptr<Shape> > drawingBoard{};

	auto sq_ptr1 = std::make_shared<Square>( 1.0 );
	auto c_ptr1 = std::make_shared<Circle>( 1.0f );

  	drawingBoard.push_back( sq_ptr1 ); 
	drawingBoard.push_back( sq_ptr1 );
	drawingBoard.push_back( sq_ptr1 );

	drawingBoard.push_back( c_ptr1 ); 
	drawingBoard.push_back( c_ptr1 );
	drawingBoard.push_back( c_ptr1 );

  float areas = 0.0f;
  for (const auto & s : drawingBoard) {
    areas += s->area();
  }

  EXPECT_FLOAT_EQ(3.0 + 3.0 * PI, areas);
}
