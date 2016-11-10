#include "UIcontrol.h"
#include "background.h"
#include <iostream>
#include <time.h>

int main()
{		
	srand((unsigned)time(NULL));
	interact start;
	start.start_game();
	return 0;
}
