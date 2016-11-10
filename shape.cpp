#include "shape.h"


shape::shape(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, string s):status(0)
{
	blocks = new block*[4];
	blocks[0] = new block(x1, y1, s);
	blocks[1] = new block(x2, y2, s);
	blocks[2] = new block(x3, y3, s);
	blocks[3] = new block(x4, y4, s);
}


shape::~shape()
{
	for(int i=0; i<4; ++i)
	{
		delete blocks[i];
	}
	delete [] blocks;
}


void shape::drop()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->down();	
	}
}


void shape::drop(int n)
{
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			blocks[j]->down();
		}
	}
}


void shape::up()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->up();	
	}
}


void shape::go_left()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->left();
	}
}


void shape::go_right()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->right();
	}
}


void shape::display()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->display();
	}
}


void shape::undisplay()
{
	for(int i=0; i<4; ++i)
	{
		blocks[i]->undisplay();
	}
}


bool shape::touch_wall()
{
	for(int i=0; i<4; ++i)
	{
		if(blocks[i]->hit_wall())
		{
			return true;
		}
	}
	return false;
}


bool shape::touch_ground()
{
	for(int i=0; i<4; ++i)
	{
		if(blocks[i]->hit_ground())
		{
			return true;
		}
	}
	return false;
}


void shape::add_to_list(l_list &list)
{
	for(int i=0; i<4; ++i)
	{
		list.insert(*blocks[i]);
	}
}


void shape::move_into_hint()
{
	for(int i=0; i<10; ++i)
	{
		go_left();		
	}
	drop();
}


bool shape::touch_list(l_list &l)
{
	for(int i=0; i<4; ++i)
	{
		if(l.touch_me(*blocks[i]))
		{
			return true;
		}
	}
	return false;
}


Oshape::Oshape():shape(INIT_X+ORI_X, INIT_Y+ORI_Y, INIT_X+ORI_X+1, INIT_Y+ORI_Y, INIT_X+ORI_X, INIT_Y+ORI_Y+1, INIT_X+ORI_X+1, INIT_Y+ORI_Y+1, "\e[46m  \e[0m"){}


void Oshape::turn(){}


LSshape::LSshape():shape(INIT_X+ORI_X+1, INIT_Y+ORI_Y, INIT_X+ORI_X, INIT_Y+ORI_Y+1, INIT_X+ORI_X+1, INIT_Y+ORI_Y+1, INIT_X+ORI_X, INIT_Y+ORI_Y+2, "\e[42m  \e[0m"){}


void LSshape::turn()
{
	switch(status)
	{
		case 0:turn_to1();break;
		case 1:turn_to2();break;
		case 2:turn_to3();break;
		case 3:turn_to0();break;
	}
}


void LSshape::turn_to0()
{
	blocks[0]->right();
	blocks[1]->left();
	blocks[2]->up();
	blocks[3]->left();
	blocks[3]->left();
	blocks[3]->up();
	status = 0;
}


void LSshape::turn_to1()
{
	blocks[0]->left();
	blocks[1]->right();
	blocks[2]->down();
	blocks[3]->right();
	blocks[3]->right();
	blocks[3]->down();
	status = 1;
}


void LSshape::turn_to2()
{
	blocks[0]->right();
	blocks[1]->left();
	blocks[2]->up();
	blocks[3]->left();
	blocks[3]->left();
	blocks[3]->up();
	status = 2;
}


void LSshape::turn_to3()
{
	blocks[0]->left();
	blocks[1]->right();
	blocks[2]->down();
	blocks[3]->right();
	blocks[3]->right();
	blocks[3]->down();
	status = 3;
}


RSshape::RSshape():shape(INIT_X+ORI_X, INIT_Y+ORI_Y, INIT_X+ORI_X, INIT_Y+ORI_Y+1, INIT_X+ORI_X+1, INIT_Y+ORI_Y+1, INIT_X+ORI_X+1, INIT_Y+ORI_Y+2, "\e[42m  \e[0m"){}


void RSshape::turn()
{
	switch(status)
	{
		case 0:turn_to1();break;
		case 1:turn_to2();break;
		case 2:turn_to3();break;
		case 3:turn_to0();break;
	}
}


void RSshape::turn_to0()
{
	blocks[0]->down();	
	blocks[1]->left();
	blocks[2]->up();
	blocks[3]->up();
	blocks[3]->up();
	blocks[3]->left();
	status = 0;
}


void RSshape::turn_to1()
{
	
	blocks[0]->up();	
	blocks[1]->right();
	blocks[2]->down();
	blocks[3]->down();
	blocks[3]->down();
	blocks[3]->right();
	status = 1;
}


void RSshape::turn_to2()
{
	blocks[0]->down();	
	blocks[1]->left();
	blocks[2]->up();
	blocks[3]->up();
	blocks[3]->up();
	blocks[3]->left();
	status = 2;
}


void RSshape::turn_to3()
{
	blocks[0]->up();	
	blocks[1]->right();
	blocks[2]->down();
	blocks[3]->down();
	blocks[3]->down();
	blocks[3]->right();
	status = 3;
}


Ishape::Ishape():shape(INIT_X+ORI_X, INIT_Y+ORI_Y, INIT_X+ORI_X, INIT_Y+ORI_Y+1, INIT_X+ORI_X, INIT_Y+ORI_Y+2, INIT_X+ORI_X, INIT_Y+ORI_Y+3, "\e[47m  \e[0m"){}


void Ishape::turn()
{
	switch(status)
	{
		case 0:turn_to1();break;
		case 1:turn_to2();break;
		case 2:turn_to3();break;
		case 3:turn_to0();break;
	}
}


void Ishape::turn_to0()
{
	blocks[1]->left();
	blocks[1]->up();
	blocks[2]->left();
	blocks[2]->up();
	blocks[2]->left();
	blocks[2]->up();
	blocks[3]->left();
	blocks[3]->up();
	blocks[3]->left();
	blocks[3]->up();
	blocks[3]->left();
	blocks[3]->up();
	status = 0;
}


void Ishape::turn_to1()
{
	blocks[1]->right();
	blocks[1]->down();
	blocks[2]->right();
	blocks[2]->down();
	blocks[2]->right();
	blocks[2]->down();
	blocks[3]->right();
	blocks[3]->down();
	blocks[3]->right();
	blocks[3]->down();
	blocks[3]->right();
	blocks[3]->down();
	status = 1;
}


void Ishape::turn_to2()
{
	blocks[1]->left();
	blocks[1]->up();
	blocks[2]->left();
	blocks[2]->up();
	blocks[2]->left();
	blocks[2]->up();
	blocks[3]->left();
	blocks[3]->up();
	blocks[3]->left();
	blocks[3]->up();
	blocks[3]->left();
	blocks[3]->up();
	status = 2;
}


void Ishape::turn_to3()
{
	blocks[1]->right();
	blocks[1]->down();
	blocks[2]->right();
	blocks[2]->down();
	blocks[2]->right();
	blocks[2]->down();
	blocks[3]->right();
	blocks[3]->down();
	blocks[3]->right();
	blocks[3]->down();
	blocks[3]->right();
	blocks[3]->down();
	status = 3;
}


LLshape::LLshape():shape(INIT_X+ORI_X,INIT_Y+ORI_Y,INIT_X+ORI_X+1,INIT_Y+ORI_Y,INIT_X+ORI_X+1,INIT_Y+ORI_Y+1,INIT_X+ORI_X+1,INIT_Y+ORI_Y+2,"\e[43m  \e[0m"){}


void LLshape::turn()
{
    switch (status)
    {
        case 0:turn_to1();break;
        case 1:turn_to2();break;
        case 2:turn_to3();break;
        case 3:turn_to0();break;
    }
}


void LLshape::turn_to0()
{
    blocks[0]->left();
    blocks[0]->left();
    blocks[1]->left();
    blocks[1]->down();
    blocks[3]->right();
    blocks[3]->up();
    status = 0;
}

void LLshape::turn_to1()
{
    blocks[0]->up();
    blocks[1]->left();
    blocks[2]->down();
    blocks[3]->down();
    blocks[3]->down();
    blocks[3]->right();
    status = 1;
}



void LLshape::turn_to2()
{
    blocks[0]->right();
    blocks[0]->up();
    blocks[1]->up();
    blocks[1]->up();
    blocks[2]->up();
    blocks[2]->left();
    blocks[3]->left();
    blocks[3]->left();
    status = 2;
}


void LLshape::turn_to3()
{
    blocks[0]->right();
    blocks[0]->down();
    blocks[0]->down();
    blocks[1]->right();
    blocks[1]->right();
    blocks[1]->down();
    blocks[2]->right();
    blocks[3]->up();
    status = 3;
}


RLshape::RLshape():shape(INIT_X+ORI_X,INIT_Y+ORI_Y,INIT_X+ORI_X+1,INIT_Y+ORI_Y,INIT_X+ORI_X,INIT_Y+ORI_Y+1,INIT_X+ORI_X,INIT_Y+ORI_Y+2,"\e[43m  \e[0m"){}


void RLshape::turn()
{
    switch (status)
    {
        case 0:turn_to1();break;
        case 1:turn_to2();break;
        case 2:turn_to3();break;
        case 3:turn_to0();break;
    }
}


void RLshape::turn_to0()
{
    blocks[0]->left();
    blocks[0]->left();
    blocks[1]->down();
    blocks[1]->left();
    blocks[2]->left();
    blocks[2]->up();
    blocks[3]->up();
    blocks[3]->up();
    status = 0;
}


void RLshape::turn_to1()
{
    blocks[0]->up();
    blocks[1]->left();
    blocks[2]->right();
    blocks[3]->right();
    blocks[3]->right();
    blocks[3]->down();
    status = 1;
}


void RLshape::turn_to2()
{
    blocks[0]->right();
    blocks[0]->up();
    blocks[1]->up();
    blocks[1]->up();
    blocks[3]->down();
    blocks[3]->left();
    status = 2;
}


void RLshape::turn_to3()
{
    blocks[0]->down();
    blocks[0]->down();
    blocks[0]->right();
    blocks[1]->down();
    blocks[1]->right();
    blocks[1]->right();
    blocks[2]->down();
    blocks[3]->left();
    status = 3;
}


Tshape::Tshape():shape(INIT_X+ORI_X+1,INIT_Y+ORI_Y,INIT_X+ORI_X,INIT_Y+ORI_Y+1,INIT_X+ORI_X+1,INIT_Y+ORI_Y+1,INIT_X+ORI_X+1,INIT_Y+ORI_Y+2,"\e[41m  \e[0m"){}


void Tshape::turn()
{
    switch (status)
    {
        case 0:turn_to1();break;
        case 1:turn_to2();break;
        case 2:turn_to3();break;
        case 3:turn_to0();break;
    }
}


void Tshape::turn_to0()
{
    blocks[0]->down();
    blocks[0]->left();
    blocks[1]->up();
    blocks[1]->left();
    blocks[3]->right();
    blocks[3]->up();
    status = 0;
}


void Tshape::turn_to1()
{
    blocks[0]->left();
    blocks[1]->right();
    blocks[2]->down();
    blocks[3]->down();
    blocks[3]->down();
    blocks[3]->right();
    status = 1;
}


void Tshape::turn_to2()
{
    blocks[0]->up();
    blocks[0]->up();
    blocks[2]->up();
    blocks[2]->left();
    blocks[3]->left();
    blocks[3]->left();
    status = 2;
}


void Tshape::turn_to3()
{
    blocks[0]->down();
    blocks[0]->right();
    blocks[0]->right();
    blocks[1]->down();
    blocks[2]->right();
    blocks[3]->up();
    status = 3;
}
