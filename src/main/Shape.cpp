#ifndef SHAPE
#define SHAPE

#include <string>

using namespace std;

class Shape {
protected:
	float size; // Could be width/height or radius

public:
	Shape ( float _size ) {
		size = _size;
	}

	virtual string draw () = 0;
	virtual float area () = 0;
};

#endif
