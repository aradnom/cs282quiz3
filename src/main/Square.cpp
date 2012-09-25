#ifndef SQUARE
#define SQUARE

#include <string>
#include "Shape.cpp"

using namespace std;

class Square : public Shape {
private:
	float l, w;

public:
	Square ( float _size ) {
		l = _size;
		w = _size;
	}

	string draw () {
		return "drew a square";
	}
	
	float area () {
		return l * w;
	}
};

#endif
