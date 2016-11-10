#include "background.h"


Wall::Wall()
{
	left_wall = new block*[20];
	right_wall = new block*[20];
	hint_space = new block*[24];
	build();
}


Wall::~Wall()
{
	for(int i=0; i<20; ++i)
	{
		delete left_wall[i];
		delete right_wall[i];
	}
	for(int i=0; i<24; ++i)
	{
		delete hint_space[i];
	}
	delete [] left_wall;
	delete [] right_wall;
	delete [] hint_space;
	left_wall = NULL;
	right_wall = NULL;
	hint_space = NULL;
}


void Wall::build()
{
	for(int i=0; i<20; ++i)
	{
		left_wall[i] = new block(ORI_X+INIT_X-5, ORI_Y+INIT_Y+i-16, "\e[45m  \e[0m");
		right_wall[i] = new block(ORI_X+INIT_X-5+11, ORI_Y+INIT_Y+i-16, "\e[45m  \e[0m");
	}
	for(int i=0; i<7; ++i)
	{
		hint_space[i] = new block(ORI_X+INIT_X-5-7, ORI_Y+INIT_Y+i+13-16, "\e[45m  \e[0m");
	}
	for(int i=0; i<7; ++i)
	{
		hint_space[i+7] = new block(ORI_X+INIT_X-5-2, ORI_Y+INIT_Y+i+13-16, "\e[45m  \e[0m");
	}
	for(int i=0; i<5; ++i)
	{
		hint_space[i+14] = new block(ORI_X+INIT_X-5-2-i, ORI_Y+INIT_Y+19-16, "\e[45m  \e[0m");
	}
	for(int i=0; i<5; ++i)
	{
		hint_space[i+19] = new block(ORI_X+INIT_X-5-3-i, ORI_Y+INIT_Y+13-16, "\e[45m  \e[0m");
	}
}


void Wall::display()
{
	for(int i=0; i<20; ++i)
	{
		left_wall[i]->display();
		right_wall[i]->display();
	}
	for(int i=0; i<24; ++i)
	{
		hint_space[i]->display();
	}
}


Ground::Ground()
{
	ground = new block*[10];	
	build();
}


void Ground::build()
{
	for(int i=1; i<=10; ++i)
	{
		ground[i-1] = new block(INIT_X+ORI_X-5+i, INIT_Y+ORI_Y-16, "\e[45m  \e[0m");
	}
}


Ground::~Ground()
{
	for(int i=0; i<10; ++i)
	{
		delete ground[i];
	}
	delete [] ground;
	ground = NULL;
}


void Ground::display()
{
	for(int i=0; i<10; ++i)
	{
		ground[i]->display();	
	}
}









