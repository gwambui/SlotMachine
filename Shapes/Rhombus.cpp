#include "Rhombus.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h> 
using std::ostream;

//Rectangle::Rectangle(int a, int b, string dname = "Generic Rectangle") : Shape("Rectangle", dname)
Rhombus::Rhombus(int b, int h, string dname = "Generic Rhombuse", int c=0) : Shape("Rhombus", dname, c)
{
	if (b % 2 == 0)
	{
		this->base = b + 1;
	}
	else{ this->base = b; }

	
	this->height = base;
}
void Rhombus::Scale(int n)
{
	if ((this->base + (2 * n)) >= 1)
	{
		this->base = base + (2 * n);
		this->height = base;
	}
}
double Rhombus::area()
{
	return (pow(base,2))/2;
}

double Rhombus::screenarea()
{
	double n = floor(base / 2);
	return ((2 * n)*(n + 1)) + 1;
}
double Rhombus::geoPerimeter()
{
	return (2 * sqrt(2))*base;
}
double Rhombus::scrPerimeter()
{
	return 2 * (base - 1);
}


vector<vector<char>> Rhombus::draw(int hoffset, int woffset, Grid& grid, char penChar, char fillChar) const
{
	int hh = this->height;
	int ww = this->base;
	int h = hh + hoffset;
	int w = ww + woffset;
	int j = 1 + (hh/ 2);
	int i = j + hoffset;
	/*grid.setrow(h);
	

//columns
	for (int k = 0; k < grid.getgrid().size(); ++k)
	{
		grid.setcol(k, w);
		

	}*/
	for (int r = hoffset; r < h; ++r)
	{
		for (int c = woffset; c < w; ++c)
		{
			grid.insert(r, c, fillChar);
			
		}
	}
	
	int n = 1;
	for (int r = hoffset; r < i; ++r)
	{
		
		for (int c = 0; c < n; ++c)
		{
			int f = woffset + floor(c + ((this->base - n) / 2));
			if (f < 0)  break;
			grid.insert(r, f, penChar);
			
		}
		n = n + 2;
	}
	n = this->base;
		
		for (int r = j ; r >=0; --r)
		{
		
			for (int c = n - 1; c >= 0; --c)
			{
				int f = floor(c + ((this->base - n) / 2));
			
				grid.insert(h - r, w - f - 1, penChar);
			
			}
		n = n - 2;	
		}
		
	
	
	return grid.getgrid();
}
/*
std::string Rhombus::getgname()
{
	return this->gname;

}*/
