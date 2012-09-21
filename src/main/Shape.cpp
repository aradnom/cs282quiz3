class Shape {
protected:
	int size; // Could be width/height or radius

public:
	Shape ( float _size ) {
		size = _size;
	}
	virtual void draw () = 0;
};
