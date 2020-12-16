#pragma once
#include "RegularLong.h"
#include"intArr.h"
#define START 1
#define AFTER_FIRST 2
#define AFTER_SECOND 3
#define AFTER_THIRD1 4
#define AFTER_THIRD2 5
#define AFTER_THIRD3 6
#define AFTER_THIRD4 7


struct Item
{
	intArr x;
	intArr y;
	intArr ac,bd,abcd;
	intArr out;
	intArr a, b, c, d;
	int new_size;
	int line;
	Item& operator=(const Item& item);
	Item();
	~Item();
	Item(intArr& x, intArr& y);
	Item(const Item& item);
	void freeOwnership();
};

struct Node
{
	Item item;
	Node* next;

	Node(const Item& item, Node* next);
};

class Stack
{
  private:
	  Node *top;
  
  public:
	  Stack();
	  ~Stack();
	  void MakeEmpty();
	  int isEmpty();
	  void push(Item& next);
	  Item pop();
	  Item Top();

};

