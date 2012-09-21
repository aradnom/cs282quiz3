#include "Shape.h"

class Circle : public Shape {
public:
	Circle ( float _size ) : Shape( _size ) {}

	void draw () {
		cout << "drew a circle";
	}
};
