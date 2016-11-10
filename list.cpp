#include "list.h"


node::node(block b):block(b), next(NULL){}


void node::connect(node* n)
{
	next = n;
}


node* &node::go_next()
{
	return next;
}


list::list():head(NULL), line(0){}


list::~list()
{
	delete_all(head);
}


void list::delete_all(node* &head)
{
	if(!head)
	{
		return;
	}
	delete_all(head->go_next());
	delete head;
	head = NULL;
}


void list::insert(block b)
{
	line = b.get_height();
	node* temp = new node(b);
	temp->connect(head);
	head = temp;
}


void list::undisplay()
{
	undisplay(head);	
}


void list::undisplay(node* head)
{
	if(!head)
	{
		return;
	}
	system("sleep 0.01");
	head->undisplay();
	undisplay(head->go_next());
}


bool list::match(int n)
{
	return line==n;
}


bool list::touch(block b)
{
	return touch(head, b);
}


bool list::touch(node* head, block b)
{
	if(!head)
	{
		return false;
	}
	if(head->compare(b))
	{
		return true;
	}
	return touch(head->go_next(), b);
}


int list::get_line()
{
	return line;
}


void list::drop()
{
	drop(head);
	--line;
}


void list::drop(node* head)
{
	if(!head)
	{
		return;
	}
	system("sleep 0.003");
	head->undisplay();
	head->down();
	system("sleep 0.003");
	head->display();
	drop(head->go_next());
}


l_node::l_node():next(NULL){}


void l_node::connect(l_node* n)
{
	next = n;
}


l_node* &l_node::go_next()
{
	return next;
}


l_list::l_list():head(NULL){}


l_list::~l_list()
{
	delete_all(head);
}


void l_list::delete_all(l_node* &head)
{
	if(!head)
	{
		return;
	}
	delete_all(head->go_next());
	delete head;
	head = NULL;
}


int list::get_length()
{
	return get_length(head);
}


int list::get_length(node* head)
{
	if(!head)
	{
		return 0;
	}
	return get_length(head->go_next())+1;
}


void l_list::insert(block b)
{
	insert(head, b);	
}


void l_list::insert(l_node* &head, block b)
{
	if(!head)
	{
		head = new l_node;
		head->insert(b);
		return;
	}
	if(head->match(b.get_height()))
	{
		head->insert(b);
		return;
	}
	insert(head->go_next(), b);
}


bool l_list::touch_me(block b)
{
	return touch_me(head, b);
}


bool l_list::touch_me(l_node* head, block b)
{
	if(!head)
	{
		return false;
	}
	if(head->touch(b))
	{
		return true;
	}
	return touch_me(head->go_next(), b);
}


int l_list::get_length()
{
	return get_length(head);
}


int l_list::get_length(l_node* head)
{
	if(!head)
	{
		return 0;
	}
	return get_length(head->go_next())+1;
}


int l_list::check()
{
	int a = 0;
	check(head, a);	
	return a;
}


void l_list::check(l_node* &head, int &a)
{
	if(!head)
	{
		return;
	}
	if(head->get_length()>=10)
	{
		head->undisplay();	
		int l = head->get_line();
		l_node* temp = head->go_next();
		delete head;
		head = temp;
		++a;
		drop(l);
		return;
	}
	check(head->go_next(), a);
}


void l_list::drop(int n)
{
	drop(head, n);
}


void l_list::drop(l_node* head, int n)
{
	if(!head)
	{
		return;
	}
	if(head->get_line()>n)
	{
		head->drop();
	}
	drop(head->go_next(), n);
}














