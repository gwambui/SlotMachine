#include "Grid.h"



Grid::Grid()
{
	 std::vector < std::vector<char> > gr ;
	 this->grid = gr;

}
Grid::~Grid()
{
	
}
std::vector<std::vector<char>> Grid::getgrid()
{
	return this->grid;
}
void Grid::setrow(int n)
{
	this->grid.resize(n);
}
void Grid::setcol(int k, int w)
{
	this->grid[k].resize(w);
}
void Grid::insert(int i, int j, char x)
{
	this->grid[i][j] = x;
}
void Grid::clear()
{
	this->grid.clear();
}
