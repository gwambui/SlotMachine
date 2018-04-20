#ifndef GRID_H
#define GRID_H
#include <vector>



class Grid
{
private:
	std::vector<std::vector<char>> grid;
public:
	Grid();
	~Grid();
	std::vector<std::vector<char>> getgrid();
	void setrow(int);
	void setcol(int, int);
	void insert(int i, int j, char x);
	void clear();

};

#endif;