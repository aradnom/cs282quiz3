#ifndef CIRCLE
#define CIRCLE

#include <string>
#include "Shape.cpp"

using namespace std;

class Circle : public Shape {
private:
	float r;

public:
	Circle ( float _r ) {
		r = _r;
	}

	string draw () {
		return "drew a circle";
	}

	float area () {
		return 3.14159265f * r * r;
	}
};

#endif
