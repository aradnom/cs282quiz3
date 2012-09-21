#include "Shape.h"

class Square : public Shape {
public:
	Square ( float _size ) : Shape( _size ) {}

	void draw () {
		cout << "drew a square";
	}
};
