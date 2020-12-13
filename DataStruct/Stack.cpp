#include "Stack.h"

Stack::Stack()
{
    top = nullptr;
}  

Stack::~Stack()
{
    MakeEmpty();
}

void Stack::MakeEmpty()
{
    Node* temp;
    while (top!=nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
   
}

int Stack::isEmpty()
{
    return (top==nullptr);
}

void Stack::push(ItemType next)
{
    top = new Node(next, top);
}

ItemType Stack::pop()
{
    ItemType data;
    if (isEmpty()) {
        cout << "The stack is empty"<<endl;
        exit(1);
        return data;
    }
    Node* temp = top;
    top = top->next;
    data = temp->item;
    delete temp;
    return data;
}

ItemType Stack::Top() {
    return this->top->item;
}

ItemType::ItemType()
{
    this->line = START;
    
}

ItemType::ItemType(vector<int> x, vector<int> y)
{
    this->x = x;
    this->y = y;
    this->line = START;
}

ItemType::ItemType(const ItemType& item)
{
    this->line = item.line;
    this->out = item.out;
    this->x = item.x;
    this->y = item.y;
}

Node::Node(const ItemType& item, Node* next)
{
    ItemType data(item);
    this->next = next;
}

