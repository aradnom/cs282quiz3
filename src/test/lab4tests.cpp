#include <memory>
#include <vector>
#include "gtest/gtest.h"

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
  std::shared_ptr<Shape> s = nullptr;

  EXPECT_EQ("drew a square", s->draw());
}

TEST(Shapes, BunchOfSquaresArea) {
  // change these to make the test pass
  std::shared_ptr<Shape> sq_ptr1 = nullptr;
  std::shared_ptr<Shape> sq_ptr2 = nullptr;
  std::shared_ptr<Shape> sq_ptr3 = nullptr;

  EXPECT_FLOAT_EQ(3.0f, sq_ptr1->area() + 
		  sq_ptr2->area() + sq_ptr3->area());
}

TEST(Shapes, BunchOfCirclesArea) {
  // change these to make the tests pass.
  std::shared_ptr<Shape> c_ptr1 = nullptr;
  std::shared_ptr<Shape> c_ptr2 = nullptr;
  std::shared_ptr<Shape> c_ptr3 = nullptr;

  EXPECT_FLOAT_EQ(3.0f * PI, c_ptr1->area() + 
		  c_ptr2->area() + c_ptr3->area());
}

TEST(Shapes, DifferentShapes) {
  // change the assignments so that the test becomes true.
  std::shared_ptr<Shape> sq_ptr1 = nullptr; 
  std::shared_ptr<Shape> c_ptr1 = nullptr;
  std::shared_ptr<Shape> c_ptr2 = nullptr;

  EXPECT_FLOAT_EQ(4.0 * 4.0 + PI * 9.0f * 9.0f + PI,
		  sq_ptr1->area() + c_ptr1->area() + c_ptr2->area());
}

TEST(ShapeVec, AreasSumCorrectly) {
  std::vector<std::shared_ptr<Shape> > drawingBoard{};

  // TODO Add three unit circles to the drawingBoard.
  // TODO Add three unit squares to the drawingBoard

  float areas = 0.0f;
  for (const auto & s : drawingBoard) {
    areas += s->area();
  }

  EXPECT_FLOAT_EQ(3.0 + 3.0 * PI, areas);
}
