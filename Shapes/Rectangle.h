#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle: public Shape
{
public:
	Rectangle(int a, int b, std::string, int); // : Shape(a, b) {};
	virtual double area() override;
	virtual void Scale(int) override;
	virtual double screenarea() override;
	virtual double geoPerimeter() override;
	virtual double scrPerimeter() override;
	virtual std::vector<std::vector<char>> draw(int, int, Grid &, char, char) const override;
	friend ostream& operator <<(ostream&, const std::vector<std::vector<char>>&);
	//virtual std::string getgname()override;
};

#endif;