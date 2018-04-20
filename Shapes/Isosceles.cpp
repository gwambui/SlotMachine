#include "Isosceles.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
using std::ostream;

Isosceles::Isosceles(int b, int h, string dname = "Generic Isosceles", int c=0) : Triangle("Isosceles", dname, c)
{
	
	if (b % 2 == 0)
	{
		this->base = b + 1;
	} else{this->base = b;}
	
	this->height = (base+1)/2;
}

void Isosceles::Scale(int n)
{
	if (base + (2*n)>= 1)
	this->base = base + (2*n);
	this->height = (base + 1)/2;
}

/*int Isosceles::area()
{
	return base* height / 2;
}
*/
double Isosceles::screenarea()
{
	return pow(height, 2);
}
double Isosceles::geoPerimeter()
{
	double x = 0.25 * pow(base, 2);
	double y = pow(height, 2);
	return (base + 2 * (sqrt(x + y)));
}
double Isosceles::scrPerimeter()
{
	return (4 * (height - 1));
}


vector<vector<char>> Isosceles::draw(int hoffset, int woffset, Grid & grid, char penChar, char fillChar) const
{
	int h = this->height + hoffset;
	int w = this->base + woffset;
	/*
	//grid.setrow(h);//rows
	

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
	for (int r = hoffset; r < h; ++r)
	{
		
		for (int c = 0; c < n ; ++c)
		{
			int f = woffset + floor(c + ((this->base - n) / 2));
			if (f < 0)  break;
			grid.insert(r, f, penChar);
			
		}
		n = n + 2;
	}
	
	return grid.getgrid();
}/*
std::string Isosceles::getgname()
{
	return this->gname;

}*/