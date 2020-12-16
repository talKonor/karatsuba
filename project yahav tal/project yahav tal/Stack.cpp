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

void Stack::push(Item& next)
{
    top = new Node(next, top);

}

Item& Item::operator=(const Item& item)
{
    new_size = item.new_size;
    x = item.x;
    y = item.y;
    a = item.a;
    b = item.b;
    c = item.c;
    d = item.d;
    ac = item.ac;
    bd = item.bd;
    abcd = item.abcd;
    out = item.out;
    line=item.line;
    return *this;

}
Item Stack::pop()
{
    Item data;
    if (isEmpty()) {
        cout << "The stack is empty"<<endl;
        exit(1);
        return data;
    }
    Node* temp = top;
    top = top->next;
    temp->item.freeOwnership();
    data = temp->item;
    delete temp;
    data.freeOwnership();
    return data;
}

Item Stack::Top() {
    return this->top->item;
}

Item::Item()
{
    this->line = START;
    new_size = 0;
    
}

Item::~Item()
{
}

Item::Item(intArr& x, intArr& y)
{
    x.setOwner(false);
    y.setOwner(false);
    this->x = x;
    this->y = y;
    new_size = x.size();
    this->line = START;
}

Item::Item(const Item& item)
{
    this->line = item.line;
    this->out = item.out;
    this->x = item.x;
    this->y = item.y;
    a = item.a;
    b = item.b;
    c = item.c;
    d = item.d;
    new_size = item.new_size;
    this->ac = item.ac;
    this->bd = item.bd;
    this->abcd = item.abcd;
    this->out = item.out;
    this->freeOwnership();
}

void Item::freeOwnership()
{
    a.setOwner(false);
    b.setOwner(false);
    c.setOwner(false);
    d.setOwner(false);
    x.setOwner(false);
    y.setOwner(false);
    ac.setOwner(false);
    bd.setOwner(false);
    abcd.setOwner(false);
    out.setOwner(false);
}

Node::Node(const Item& item, Node* next)
{
    this->next = next;
    this->item = item;
}

