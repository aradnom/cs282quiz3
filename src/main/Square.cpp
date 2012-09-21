#ifndef SQUARE
#define SQUARE

#include <string>
#include "Shape.cpp"

using namespace std;

class Square : public Shape {
public:
	Square ( float _size ) : Shape( _size ) {}

	string draw () {
		return "drew a square";
	}
	
	float area () {
		return 0.0f;
	}
};

#endif
