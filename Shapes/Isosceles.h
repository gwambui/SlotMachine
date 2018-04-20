#ifndef ISOSCELES_H
#define ISOSCELES_H
#include "Triangle.h"

class Isosceles : public Triangle
{

public:
	Isosceles(int a, int b, std::string, int); // : Shape(a, b) {};
	//virtual double area();
	virtual void Scale(int) override;
	virtual double screenarea() override;
	virtual double geoPerimeter() override;
	virtual double scrPerimeter() override;
	virtual std::vector<std::vector<char>> draw(int, int, Grid &,char, char) const override;
	friend ostream& operator <<(ostream&, const std::vector<std::vector<char>>&);
	//virtual std::string getgname()override;
};

#endif;