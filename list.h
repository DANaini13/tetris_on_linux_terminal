#ifndef _LIST_H_
#define _LIST_H_
#include "base.h"


class node: public block
{
public:
	node(block);
	void connect(node*);	
	node* &go_next();
private:
	node* next;
};


class list
{
public:
	list();
	~list();
	void insert(block);
	void undisplay();
	bool match(int);
	bool touch(block b);
	int get_length();
	void drop();
	int get_line();
private:
	node* head;
	void undisplay(node*);
	int line;
	bool touch(node*, block b);
	void delete_all(node* &);
	int get_length(node* head);
	void drop(node*);
};


class l_node: public list
{
public:
	l_node();
	void connect(l_node*);
	l_node* &go_next();
private:
//	list data;
	l_node* next;
};


class l_list
{
public:
	l_list();
	~l_list();
	void insert(block);
	bool touch_me(block);
	int get_length();
	int check();
	void drop(int);
private:
	l_node* head;
	void insert(l_node*&, block);
	bool touch_me(l_node*, block);
	int get_length(l_node*);
	void check(l_node* &, int &);
	void delete_all(l_node* &);
	void drop(l_node*, int);
};

#endif






