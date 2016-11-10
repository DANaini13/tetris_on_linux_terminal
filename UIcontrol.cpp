#include "UIcontrol.h"
#include <fstream>
#include <cctype>
#include <cmath>


UIcontrol::UIcontrol():score(0), ptr(NULL), next(NULL)
{
	system("stty -echo");
	system("echo -e \"\\033[?25l\"");
	upload();
	display_background();
	display_score_board();
}


UIcontrol::~UIcontrol()
{
	system("stty echo");
	system("echo -e \"\\033[?25h\"");
	delete ptr;
	delete next;
}


void UIcontrol::upload()
{
	fstream file("level.txt");
	if(file.is_open())
	{
		level = file.get()-'0';
		file.close();
	}
	else
	{
		FILE* create_file = fopen("level.txt", "w");
		fputs("5|1|10", create_file);
		fclose(create_file);
		level = 5;
	}
}


void UIcontrol::display_background()
{
	clean();
	wall.display();
	ground.display();
	display_score_board();
}


void UIcontrol::display_score_board()
{
	go_to(INIT_X+ORI_X-11, INIT_Y+ORI_Y-5);
	cout<<"your score:";
	go_to(INIT_X+ORI_X-11, INIT_Y+ORI_Y-6);
	cout<<score;
}


void UIcontrol::init_shape()
{
	int a = rand()%7;
	switch(a)
	{
		case 0:ptr = new Oshape(); break;
		case 1:ptr = new LSshape(); break;
		case 2:ptr = new RSshape(); break;
		case 3:ptr = new Ishape(); break;
		case 4:ptr = new LLshape(); break;
		case 5:ptr = new RLshape(); break;
		case 6:ptr = new Tshape(); break; 
	}
}


void UIcontrol::display_shape()
{
	ptr->display();
}


void UIcontrol::refresh_shape_into(int n)
{
	delete ptr;
	switch(n)
	{
		case 0:ptr = new Oshape(); break;
		case 1:ptr = new LSshape(); break;
		case 2:ptr = new RSshape(); break;
		case 3:ptr = new Ishape(); break;
		case 4:ptr = new LLshape(); break;
		case 5:ptr = new RLshape(); break;
		case 6:ptr = new Tshape(); break; 
	}
	ptr->display();
}


int UIcontrol::display_next()
{
	if(next)
	{
		next->undisplay();
		delete next;
	}
	int n = rand()%7;
	switch(n)
	{
		case 0:next = new Oshape(); break;
		case 1:next = new LSshape(); break;
		case 2:next = new RSshape(); break;
		case 3:next = new Ishape(); break;
		case 4:next = new LLshape(); break;
		case 5:next = new RLshape(); break;
		case 6:next = new Tshape(); break; 
	}
	next->move_into_hint();
	next->display();
	return n;
}


void UIcontrol::turn_shape()
{
	ptr->undisplay();
	ptr->turn();
	if(ptr->touch_wall()||ptr->touch_list(list))
	{
		ptr->turn();
		ptr->turn();
		ptr->turn();
	}
	ptr->display();
}


void UIcontrol::shape_left()
{
	ptr->undisplay();
	ptr->go_left();
	if(ptr->touch_wall()||ptr->touch_list(list))
	{
		ptr->go_right();
	}
	ptr->display();
}


void UIcontrol::shape_right()
{
	ptr->undisplay();
	ptr->go_right();
	if(ptr->touch_wall()||ptr->touch_list(list))
	{
		ptr->go_left();
	}
	ptr->display();
}


bool UIcontrol::shape_down()
{
	ptr->undisplay();
	ptr->drop();
	if(ptr->touch_ground()||ptr->touch_list(list))
	{
		ptr->up();
		ptr->display();
		return true;
	}
	ptr->display();
	return false;
}


void UIcontrol::shape_up()
{
	ptr->undisplay();
	ptr->up();
	ptr->display();
}


bool UIcontrol::step(int &n)
{
	if(shape_down())
	{
		ptr->add_to_list(list);
		int score = 0;
		while(list.check())
		{
			++score;
		}
		score = pow(score, 2);
		score*=10;
		this->score+=score;
		display_score_board();
		refresh_shape_into(n);
//		refresh_shape_into(3);
		n = display_next();
		return dead();
	}
	else
	{
		return false;
	}
}


bool UIcontrol::dead()
{
	return list.get_length()>=18;
}


void UIcontrol::clean()
{
	go_to(ORI_X+INIT_X-10, ORI_Y+INIT_Y+5);
	for(int i=0; i< 30; ++i)
	{
		cout<<"                                              ";
		cout<<endl;
	}
}


void UIcontrol::output_score()
{	
	go_to(ORI_X+INIT_X-5, ORI_Y+INIT_Y);
	cout<<"your score is:"<<score<<endl;
}


interact::interact(){};


void interact::start_game()
{
	UIcontrol::init_shape();
	UIcontrol::display_shape();
	int next = UIcontrol::display_next();
	while(1)
	{
		int command = get_command();	
		switch(command)
		{
			case 0:{	
						system("sleep 0.2");
				        if(UIcontrol::step(next))
				        {
				       		goto out;	
				        }
				        command = 0;
				        break;
			       }
			case 1:UIcontrol::turn_shape();command = 0;break;
			case 2:UIcontrol::shape_left();command = 0;break;
			case 3:{ 
					if(UIcontrol::step(next))
				        {
				       		goto out;	
				        }
				       	command = 0;
					break;
			       }
			case 4:UIcontrol::shape_right();command = 0;break;
			case 5:{
				       	while(!UIcontrol::shape_down()){}
					if(UIcontrol::step(next))
				        {
				       		goto out;	
				        }	
					break;
			       }
		}
	}
	out: {}end_game();
}


int interact::get_command()
{
	if(kbhit())
	{
		char c = getchar();
		c = toupper(c);
		switch(c)
		{
			case'W':case'I': return 1;
			case'A':case'J': return 2;
			case'S':case'K': return 3;
			case'D':case'L': return 4;
			case' ': return 5;
			default: return 0;
		}
	}
	return 0;
}


void interact::end_game()
{
	UIcontrol::clean();
	UIcontrol::output_score();
}








