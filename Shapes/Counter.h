#ifndef COUNTER_H
#define COUNTER_H




class Counter
{
private:
	int count = 0;
public:
	Counter()
	{
		this->count = 0;
	}
	int operator()()
	{
		++count;
		return count;
	}
	
	int getcount()
	{
		return count;
	}


};

#endif;