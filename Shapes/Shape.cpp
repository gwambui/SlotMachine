#include "Shape.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
using std::ostream;
#include <typeinfo>
//

Shape::Shape():id(){
	
}
Shape::Shape(string gname, string dname, int c) :gname(gname), dname(dname), id(c){
	
}
Shape::~Shape()
{

}
int Shape::getheight()
{
	return this->height;
}
int Shape::getwidth()
{
	return this->base;
}

void Shape::shapeInfo()
{
	

	cout << "Shape Information" << endl << endl;
	cout << "-----------------" << endl;
	cout << "Static Type:		" << typeid(this).name()<<   endl;
	cout << "Dynamic Type:		" << typeid(*this).name()<< endl;
	cout << "Generic Name:		" << this->gname<<endl;
	cout << "Decription:		" << this->dname << endl;
	cout << "id:			" << this->id<<endl;
	cout << "B. Box width:		" << this->base<<endl;
	cout << "B. Box height:		" << this->height<<endl;
	cout << "Scr Area:		" << this->screenarea()<<endl;
	cout << "Geo Area:		" << this->area()<<endl;
	cout << "Scr Perimeter:		" << this->scrPerimeter()<<endl;
	cout << "Geo Perimeter:		" << this->geoPerimeter()<<endl;
}
std::string Shape::toString()
{
	
	string print;
	print = "Shape Information\n";
	print = print + "-----------------\n"
		+ "Static Type:		" + typeid(this).name()+'\n'
		+ "Dynamic Type:		" + typeid(*this).name()+"\n"
		+ "Generic Name:		" + this->gname + "\n"
		+ "Decription:		" + this->dname + "\n"
		+ "id:			" + std::to_string(this->id) + "\n"
		+ "B. Box width:		" + std::to_string(this->base) + "\n"
		+ "B. Box height:		" + std::to_string(this->height) + "\n"
		+ "Scr Area:		" + std::to_string((int)this->screenarea()) + "\n"
		+ "Geo Area:		" + std::to_string((int)this->area()) + "\n"
		+ "Scr Perimeter:		" + std::to_string((int)this->scrPerimeter()) + "\n"
		+ "Geo Perimeter:		" + std::to_string((int)this->geoPerimeter()) + "\n";

	
	return print;
}
ostream& operator<<(ostream& output, Shape& s)
{

	output << s.toString();
	return output;
}

ostream& operator<<(ostream& sout, const vector<vector<char>> &grid)
{


	for (vector<char> vec : grid)
	{
		for (char ch : vec)
		{
			sout << ch;
		}
		sout << '\n';
	}
	return sout;

}
std::string Shape::getgname()
{
	//cout << a.gname << endl;
	return this->dname;

}