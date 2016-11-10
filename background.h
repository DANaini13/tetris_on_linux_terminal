#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include"base.h"


class Wall
{
public:
	Wall();
	~Wall();
	void display();
private:
	void build();
	block** left_wall;
	block** right_wall;
	block** hint_space;
};



class Ground
{
public:
	Ground();
	~Ground();
	void display();
private:
	void build();
	block** ground;
};


#endif
