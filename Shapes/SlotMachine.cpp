#include "SlotMachine.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <stdio.h>  
#include <stdlib.h> 

using std::ostream;


SlotMachine::SlotMachine() 
	:display{ Grid() }, 
	mode("play"), 
	tokens(10), 
	c{ Counter() }, 
	//shape reel contains an array of three (base class)shape pointers. the pointers will point to children of shape class
	shape_reel(std::array < Shape*, 3 >{})
{
	
	welcome();
	
}

vector<vector<char>> SlotMachine::draw(Shape& a,Shape& b, Shape& c) 
{
	
	char hborder = '-';
	char vborder = '|';
	int hh = max(a.getheight(), b.getheight());
	int h =2+ max(hh, c.getheight());
	int w = 10 + a.getwidth() + b.getwidth() + c.getwidth();
	display.clear();
	display.setrow(h);//rows
	int g = this->display.getgrid().size();//returns number of on display rows
	
	//columns
	for (int k = 0; k < g; ++k)
	{
		display.setcol(k, w);
	}


	int sep1 = 3 + a.getwidth();
	int sep2 = 3 + sep1 + b.getwidth();
	

	a.draw(1, 2, display, '+', ' ');
	b.draw(1,sep1+2, display, '*', ' ');
	c.draw(1, sep2+2, display, ':', ' ');


//draw horizontal border - top and bottom
	for (int r = 0; r < h; --r)
	{
		for (int c = 0; c < w; ++c)
		{
			display.insert(r, c, hborder);
		}
		r = r + h;
	}//draw left most vertical border(1)
	for (int s = 0; s < h; ++s)
	{
		this->display.insert(s,0,  vborder);
	}
	
	//draw vertical border(2)
	for (int s = 0; s < h; ++s)
	{
		this->display.insert(s,sep1,  vborder);
	}
	
	//draw vertical border(3)
	for (int s = 0; s < h; ++s)
	{
		this->display.insert(s,sep2,  vborder);
	}

	//draw right most vertical border(4)
	for (int s = 0; s < h; ++s)
	{
		this->display.insert(s, w-1, vborder);
	}
	
	
	return display.getgrid();
}

void SlotMachine::run()
{
	std::string input;
	while (mode == "play")
	{
		if (this->tokens < 1)
		{	
			std::cout << "You have " << this->tokens << " tokens left" << endl
				<< "Press y to purchase more tokens or e to exit" << endl;
			
			char replay;
			
			cin >> replay;
			replay = tolower(replay);
			if (replay == 'y'){this->reload();}
			else if (replay == 'e') {
				this->mode = "exit";
				bye();
				exit(EXIT_SUCCESS);
			}
			else{
				std::cout << "Your input is invalid" << endl;
				
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		}
		else
		{
			std::cout << "You have " << this->tokens << " tokens left" << endl << endl
			<< "How much would you like to bet? (Enter 'q' to quit 'a' for guide)" << endl << ":";
		
			cin >> input;
			//std::getline(cin, input);
			if (input == ""){
				std::cout << "Input is empty" << endl;
			}
			else{
				if (input == "q")
				{
					//std::cout << "Thank you for playing!" << endl;
					this->mode = "exit";
					bye();
					exit(EXIT_SUCCESS);
				}
				else if (input == "a")
				{this->guide();}
				else if (this->tokens < 1)
				{
					std::cout << "You are out of tokens" << endl	
					<< "Press y to purchase more tokens or e to exit" << endl;
					cin.clear();
					char replay;
					cin >> replay;
					replay = tolower(replay);
					if (replay == 'y')
					{this->reload();}
					else if(replay == 'e'){
						this->mode = "exit";
						bye();
						exit(EXIT_SUCCESS);
					}
					else{
						std::cout << "Your input is invalid" << endl;
					}
				}
				else if (isdigit(input[0]) && (stoi(input) <= this->tokens))
				{
					this->bet = stoi(input);
					this->tokens = tokens - bet;
					this->play();
				}
				else if (isdigit(input[0]) && (stoi(input) > this->tokens))
				{
					std::cout << "Your bet is more than your tokens" << endl;
				}
				else
				{
					std::cout << "Your input is invalid" << endl;
				}
				cin.clear();
			}
		}
	}
}
void SlotMachine::play()
{

	int slot;
	int w;
	int h;
	
	for (int i = 0; i < 3; ++i)
	{
		
		w = 0;
		h = 0;
		slot = 0;
		slot = (rand() % 4)+1 ;
		
		w = (rand() % 25)+1;
		//cout << "slot draw " << slot << endl;
		//cout << "size " << w << endl;
			switch (slot)
		{
		case 1:
			// Initialize three shape pointers  with child objects to be displayed

			this->shape_reel[i] = new Rhombus(w, w, "Diamond", c());
			break;
		case 2:
			this->shape_reel[i] = new Isosceles(w, w, "Isosceles", c());
			break;
		case 3:
			this->shape_reel[i] = new Right(w, w, "RightTriangle", c());
			break;
		case 4:
			
			h = (rand() % 25) + 1;
			//cout << "hight" << h << endl;
			this->shape_reel[i] = new Rectangle(w, h, "Rectangle", c());
			break;
		}

	}
	
	cout << this->draw(*shape_reel[0], *shape_reel[1], *shape_reel[2]) << endl;;
	this->report();
	return;
}
void SlotMachine::report()
{
	
	cout << "Your draw is" << endl << endl;
	std::cout.width(10); std::cout << std::left << "Shape			Size" << endl << endl;
	std::cout.width(10); std::cout << std::left << shape_reel[0]->getgname() << "	of size, " << shape_reel[0]->getwidth() << ", " << shape_reel[0]->getheight() << endl;
	std::cout.width(10); std::cout << std::left << shape_reel[1]->getgname() << "	of size, " << shape_reel[1]->getwidth() << ", " << shape_reel[1]->getheight() << endl;
	std::cout.width(10); std::cout << std::left << shape_reel[2]->getgname() << "	of size, " << shape_reel[2]->getwidth() << ", " << shape_reel[2]->getheight() << endl << endl << endl;
		
		int test_draw = testdraw();
		switch (test_draw)
		{
		case 3:
			this->tokens = tokens + (bet * 3);
			cout << "You won the max draw(*3)!" << endl;//Your token balance is: " << this->tokens 
			break;
		case 2:
			this->tokens = tokens + (bet * 2);
			cout << "You won double your bet! "<< endl;//Your token balance is: "<< this->tokens << 
			break;
		case 1:
			this -> tokens = tokens + bet;
			cout << "You broke even! "<<endl;//Your token balance is: " << this->tokens << 
			break;
		default:
			this->tokens = tokens ;
			cout << "You lost :(.  "<<endl;//Your token balance is: " << this->tokens <<
			break;
		}
	
		return;
}
int SlotMachine::testdraw()
{
	int outcome;
	if (this->shape_reel[0]->getgname() == this->shape_reel[1]->getgname()
		& this->shape_reel[0]->getgname() == this->shape_reel[2]->getgname())
	{
		if ((shape_reel[0]->getwidth() == shape_reel[1]->getwidth() )
			& (shape_reel[0]->getwidth() == shape_reel[2]->getwidth()))
		{
			outcome = 3;
			return outcome;
		}else{
		outcome = 2;
		return outcome;}
	}
	else if (this->shape_reel[0]->getgname() == this->shape_reel[1]->getgname()
			|| this->shape_reel[0]->getgname() == this->shape_reel[2]->getgname()
			|| this->shape_reel[1]->getgname() == this->shape_reel[2]->getgname())
	{
		outcome = 1;
		return outcome;
	}
	else {
		outcome = 0;
	}

return outcome;
}
void SlotMachine::welcome()
{
	cout << R"( 
 /$$$$$$$$        /$$           /$$          
|__  $$__/       |__/          | $$          
   | $$  /$$$$$$  /$$  /$$$$$$ | $$  /$$$$$$ 
   | $$ /$$__  $$| $$ /$$__  $$| $$ /$$__  $$
   | $$| $$  \__/| $$| $$  \ $$| $$| $$$$$$$$
   | $$| $$      | $$| $$  | $$| $$| $$_____/
   | $$| $$      | $$| $$$$$$$/| $$|  $$$$$$$
   |__/|__/      |__/| $$____/ |__/ \_______/
                     | $$                    
                     | $$                    
                     |__/                    
  /$$$$$$  /$$             /$$               
 /$$__  $$| $$            | $$               
| $$  \__/| $$  /$$$$$$  /$$$$$$   /$$$$$$$  
|  $$$$$$ | $$ /$$__  $$|_  $$_/  /$$_____/  
 \____  $$| $$| $$  \ $$  | $$   |  $$$$$$   
 /$$  \ $$| $$| $$  | $$  | $$ /$$\____  $$  
|  $$$$$$/| $$|  $$$$$$/  |  $$$$//$$$$$$$/  
 \______/ |__/ \______/    \___/ |_______/   
                                                                                             
)" <<"Welcome to the Triple slots."<<endl<< endl ;
}
void SlotMachine::reload()
{
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "How many tokens would you like to purchase?" << endl;
	std::string reload;
	cin >> reload;
	//std::getline(cin, reload);
	while (!isdigit(reload[0]) || stoi(reload) < 0)
	{	
		cout << "Invalid purchase amount" << endl;
		cin.clear();
		cout << "Enter purchase amount" << endl;
		cin >> reload;
	}
	this->tokens = this->tokens + stoi(reload);
	return;
}
void SlotMachine::guide()
{
	cout << endl << "To win the game:" << endl << endl
		<< "3 times your bet: you must draw 3 identical shapes of the same size" << endl << endl
		<< "2 times your bet: you must drwaw 3 identical shapes of any size" << endl << endl
		<< "Break even: you must draw two idenical shapes" << endl << endl
		<< "No identical shapes means you lose your bet." << endl << endl
		<< "Good Luck." << endl << endl;
	return;
}
void SlotMachine::bye()
{
	std::cout << "Thank you for playing!" << endl<<endl;
	cout << R"(
 /$$$$$$$  /$$     /$$ /$$$$$$$$
| $$__  $$|  $$   /$$/| $$_____/
| $$  \ $$ \  $$ /$$/ | $$      
| $$$$$$$   \  $$$$/  | $$$$$   
| $$__  $$   \  $$/   | $$__/   
| $$  \ $$    | $$    | $$      
| $$$$$$$/    | $$    | $$$$$$$$
|_______/     |__/    |________/
)" << endl;
}