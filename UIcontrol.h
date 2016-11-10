#ifndef _UICONTROL_H_
#define _UICONTROL_H_

#include "list.h"
#include "shape.h"
#include "background.h"


class UIcontrol
{
public:
	UIcontrol();	
	~UIcontrol();
	void upload();
	void display_background(); 
	void init_shape();
	void display_shape();
	void turn_shape();
	void shape_left();
	void shape_right();
	bool shape_down();
	void shape_up();
	int display_next();
	bool step(int&);
	void output_score();
	void clean();
private:
	unsigned level;
	unsigned score;
	l_list list;
	shape* ptr;
	shape* next;
	Wall wall;
	Ground ground;
	void display_score_board();
	void refresh_shape_into(int);
	bool dead();
};


class interact: public UIcontrol
{
public:
	interact();
	void start_game();
	void end_game();
private:	
	int get_command();
	//1:turn, 2:left, 3:down, 4:right, 5:land.
};

#endif
