#ifndef CIRCLE
#define CIRCLE

#include <string>
#include "Shape.cpp"

using namespace std;

class Triangle : public Shape {
private:
	float r;

public:
	Triangle ( float _size ) : Shape ( _size ) {}

	string draw () {
		return "drew a triangle";
	}

	float area () {
		return 0.5f * size * size;
	}
};

#endif
