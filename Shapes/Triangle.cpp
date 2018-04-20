#include "Triangle.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
using std::ostream;

Triangle::Triangle(string gname, string dname = "Generic Triangele", int c=0) :Shape(gname, dname, c){}



double Triangle::area()
{
	return this->base* this->height / 2;
} 