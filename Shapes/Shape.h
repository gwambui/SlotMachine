#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>
#include "Grid.h"
#include"Counter.h"
using std::ostream;



class Shape
{
public: 
	//friend class SlotMachine;
	virtual double area() = 0; //pure virtual function makes shape class abstract
	virtual double screenarea() = 0;
	virtual double geoPerimeter() = 0;
	virtual double scrPerimeter() = 0;
	Shape(std::string, std::string, int);
	~Shape();
	void shapeInfo();
	Shape();
	int getheight();
	int getwidth();
	virtual std::string getgname();
	virtual void Scale(int) = 0;
	std::string toString();
	friend ostream& operator<<(ostream& output, Shape& s);
	friend ostream& operator<<(ostream& output, std::vector<std::vector<char>>& grid);
	virtual std::vector<std::vector<char>> draw(int,int,Grid& g, char penChar = '*', char fillChar = ' ') const = 0;
	//void write_to_stream(char, char);
	std::string gname;

protected:
	int base;
	int height;
	std::string dname;
	
	const int id;
	//static int count;
	
}; 


#endif; //!SHAPE_H
//int Shape::count = 0;