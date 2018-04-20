#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{

public:
	Triangle();
	Triangle(std::string, std::string, int); // : Shape(a, b) {};
	virtual double area() override;
	//virtual int screenarea();
	//virtual int geoPerimeter();
	//virtual int scrPerimeter();

};

#endif;