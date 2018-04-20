#include "Rectangle.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
using std::ostream;

Rectangle::Rectangle(int a, int b, string dname = "Generic Rectangle",int c=0) : Shape("Rectangle", dname,c)
{
	this->base = a;
	this->height = b;
}


double Rectangle::area()
{
	return base* height;
}

void Rectangle::Scale(int n)
{
	if ((base + n) >= 1 && (height + n) >= 1)
	{
		this->base = base + n;
		this->height = height + n;
	}
}
double Rectangle::screenarea()
{
	return this->area();
}
double Rectangle::geoPerimeter()
{
	return 2 * (base + height);
}
double Rectangle::scrPerimeter()
{
	return (2 * (height + base) - 4);
}

vector<vector<char>> Rectangle::draw(int hoffset, int woffset, Grid & grid, char penChar, char fillChar) const
{
	int h = this->height + hoffset;
	int w = this->base + woffset;
	
/*	grid.setrow(h);//rows
	//grid.getgrid().resize(h);//rows

	//columns
	for (int k = 0; k < grid.getgrid().size(); ++k)
	{
		grid.setcol(k, w);
		//grid.getgrid()[k].resize(w);

	}*/
	for (int r = hoffset; r < h; ++r)
	{
		for (int c = woffset; c < w; ++c)
		{
			grid.insert(r, c, penChar);
			//grid.getgrid()[r][c] = penChar;
		}
	}
	return grid.getgrid();
}
/*
std::string Rectangle::getgname()
{
	return this->gname;

}*/