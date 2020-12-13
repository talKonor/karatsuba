#pragma once
#include "RegularLong.h"

#define START 1
#define AFTER_FIRST 2
#define AFTER_SECOND 3
#define AFTER_THIRD 4


struct ItemType
{
	vector<int> x;
	vector<int> y;
	vector<int> out;
	int line;
	ItemType();
	ItemType(vector<int>x, vector<int>y);
	ItemType(const ItemType& item);
};

struct Node
{
	ItemType item;
	Node* next;

	Node(const ItemType& item, Node* next);
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
	  void push(ItemType next);
	  ItemType pop();
	  ItemType Top();

};

