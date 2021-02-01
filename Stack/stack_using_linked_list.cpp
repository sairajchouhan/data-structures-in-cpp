#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class Stack
{
private:
  Node *top;

public:
  Stack() { top = nullptr; }
  void push(int data);
  int pop();
  void display();
  int peek(int pos);
  int stack_top();
};

void Stack::push(int data)
{
  Node *temp = new Node;
  if (temp == nullptr)
    cout << "Stack overflow" << endl;
  else
  {
    temp->data = data;
    temp->next = top;
    top = temp;
  }
}

int Stack::pop()
{
  int x = -1;
  if (top == nullptr)
    cout << "Stack is empty: stack underflow" << endl;
  else
  {
    Node *temp = top;
    x = temp->data;
    top = temp->next;
    delete temp;
  }
  return x;
}

void Stack::display()
{
  Node *p = top;
  if (p == nullptr)
  {
    cout << "Empty stack :)" << endl;
    return;
  }
  else
  {
    while (top != nullptr)
    {
      cout << p->data << endl;
      p = p->next;
    }
  }
}

int Stack::peek(int pos)
{
  Node *current = top;
  if (pos < 1)
  {
    cout << "out of range" << endl;
    return -1;
  }
  int j = 1;
  while (j != pos)
  {
    ++j;
    current = current->next;
  }
  return current->data;
}

int Stack::stack_top()
{
  if (top == nullptr)
    return -1;
  else
    return top->data;
}

int main()
{

  Stack s;
  s.push(3);
  s.push(4);
  cout << "peek(2) is " << s.peek(2) << endl;
  cout << "Stack top is " << s.stack_top() << endl;
  s.display();
  return 0;
}