#include "Right.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
using std::ostream;


Right::Right(int b, int h, string dname = "Generic Right", int c=0) : Triangle("Right", dname, c)
{
	this->base = b;
	this->height = b;
}

void Right::Scale(int n)
{
	if ((base + n) >= 1)
	{
		this->base = base + n;
		this->height = base;

	}
}

/*int Right::area()
{
	return base* height /2;
}*/

double Right::screenarea()
{
	return height *(height +1)/2;
}

double Right::geoPerimeter()
{
	return (2 + sqrt(2))*height;
}
double Right::scrPerimeter()
{
	return (3 * (height - 1));
}

vector<vector<char>> Right::draw(int hoffset, int woffset, Grid & grid, char penChar, char fillChar) const
{
	int h = this->height + hoffset;
	int w = this->base + woffset;

	/*grid.setrow(h);//rows
	
	//columns
	for (int k = 0; k < grid.getgrid().size(); ++k)
	{
		grid.setcol(k,w);
		
	}*/
	for (int r = hoffset; r < h; ++r)
	{
		for (int c = woffset; c < w; ++c)
		{
			
			grid.insert(r, c, fillChar);
		}
	}
	for (int r = hoffset; r < h; ++r)
	{
		for (int c = woffset; c <= woffset+r-1; ++c)
		{
			
			grid.insert(r, c, penChar);
		}
	}
	return grid.getgrid();
}/*
std::string Right::getgname()
{
	return this->gname;

}*/