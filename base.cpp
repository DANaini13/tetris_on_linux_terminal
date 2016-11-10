#include "base.h"
#include <sstream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


void go_to(int x, int y)
{
	cout<<endl;
	y = 42-y;
	x *=2;
	string sx, sy;
	stringstream ss1, ss2;
	ss1<<x;
	ss1>>sx;
	ss2<<y;
	ss2>>sy;
	string sum = "tput cup "+sy+" "+sx;
	system(sum.c_str());
}


int kbhit()
{
  	struct termios oldt, newt;
  	int ch;
  	int oldf;
 
  	tcgetattr(STDIN_FILENO, &oldt);
  	newt = oldt;
  	newt.c_lflag &= ~(ICANON | ECHO);
  	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  	ch = getchar();
 
  	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  	fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  	if(ch != EOF)
  	{
    		ungetc(ch, stdin);
    		return 1;
  	}
 
  	return 0;
}


location::location():x(0), y(0){}


location::location(int x, int y):x(x), y(y){}


location::location(const location &l)
{
	x = l.x;
	y = l.y;
}


void location::up()
{
	++y;
}


void location::down()
{
	--y;
}


void location::left()
{
	--x;
}


void location::right()
{
	++x;
}


bool location::compare(const location &l) const
{
	return x == l.x && y == l.y;
}


bool location::hit_wall()
{
	return ORI_X+INIT_X-5==x||ORI_X+INIT_X-5+11==x;
}


bool location::hit_ground()
{
	return INIT_Y+ORI_Y-16==y;
}


void location::display()
{
	go_to(x, y);	
}


int location::get_height()
{
	return y-INIT_Y-ORI_Y+16;
}


block::block()
{
	color = "\e[41m  \e[0m";
}


block::block(const block &b):location(b)
{
	color = b.color;
}


block::block(int x, int y, string s):location(x, y)
{
	color = s;
}


void block::display()
{
	location::display();
	cout<<color;	
}


void block::undisplay()
{
	location::display();
	cout<<"\e[0m  \e[0m";
}






