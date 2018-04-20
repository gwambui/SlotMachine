#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include "Shape.h"
#include <iostream>
#include "Grid.h"
#include "Counter.h"
using namespace std;
using std::ostream;
#include <array>
#include "Rectangle.h"
#include "Isosceles.h"
#include "Right.h"
#include "Rhombus.h"


class SlotMachine{

private:
	Grid display;
	std::array<Shape*, 3> shape_reel{ {} };
	Counter c;
	string mode;
	int tokens;
	int bet;
public:
	SlotMachine();
	void welcome();
	virtual std::vector<std::vector<char>> draw(Shape& a, Shape& b, Shape& c);
	//~SlotMachine();
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine& operator =(const SlotMachine&) = delete;
	void run();
	void reload();
	void guide();
	void play();
	void report();
	int testdraw();
	void bye();



};
#endif;