#ifndef CIRCLE
#define CIRCLE

#include <string>
#include "Shape.cpp"

using namespace std;

class Circle : public Shape {
public:
	Circle ( float _size ) : Shape( _size ) {}

	string draw () {
		return "drew a circle";
	}

	float area () {
		return 0.0f;
	}
};

#endif
