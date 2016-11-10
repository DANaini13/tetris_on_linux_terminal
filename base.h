#ifndef _BASE_H_
#define _BASE_H_

#define YELLOW 43
#define RED 31
#define GREEN 32
#define BLUE 34
#define WHITE 37
#define PURPLE 35
#define ORI_X 8
#define ORI_Y 15
#define INIT_X 5
#define INIT_Y 20

#include <cstring>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


int kbhit();
void go_to(int, int);
class block;



class location
{
public:
	location();
	location(int, int);
	location(const location&);
	int get_height();
	void up();
	void down();
	void left();
	void right();
	bool compare(const location&) const;
	void display();
	bool hit_wall();
	bool hit_ground();
protected:
	unsigned x;
	unsigned y;
};


class block: public location
{
public:
	block();
	block(const block&);
	block(int, int, string);
	void display();
	void undisplay();
private:
	string color;
};


#endif
