#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "base.h" 
#include "list.h"
class shape
{
public:
	shape(int, int, int, int, int, int, int, int, string);
	~shape();
	virtual void turn() = 0;
	void drop();
	void drop(int);
	void up();
	void go_left();
	void go_right();
	void display();
	void undisplay();
	bool touch_wall();
	//left: ORI_X+INIT_X-5
	//right: ORI_X+INIT_X-5+11 
	bool touch_ground();
	//INIT_Y+ORI_Y-16	
	void add_to_list(l_list&);
	void move_into_hint();
	bool touch_list(l_list&);
protected:
	block** blocks;
	int status;
	//0, 1, 2, 3;
};


class Oshape: public shape
{
public:
	Oshape();
	void turn();
};


class LSshape: public shape
{
public:
	LSshape();
	void turn();
private:
	void turn_to0();
	void turn_to1();
	void turn_to2();
	void turn_to3();
};


class RSshape: public shape
{
public:
	RSshape();
	void turn();
private:
	void turn_to0();
	void turn_to1();
	void turn_to2();
	void turn_to3();
};


class Ishape: public shape
{
public:
	Ishape();
	void turn();
private:
	void turn_to0();
	void turn_to1();
	void turn_to2();
	void turn_to3();
};


class LLshape: public shape
{
public:
    LLshape();
    void turn();
private:
    void turn_to0();
    void turn_to1();
    void turn_to2();
    void turn_to3();
};


class RLshape: public shape
{
public:
    RLshape();
    void turn();
private:
    void turn_to0();
    void turn_to1();
    void turn_to2();
    void turn_to3();
};


class Tshape: public shape
{
public:
    Tshape();
    void turn();
private:
    void turn_to0();
    void turn_to1();
    void turn_to2();
    void turn_to3();
};

#endif
