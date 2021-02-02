#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
  string data;
  Node *next;
};

class Stack
{
private:
  Node *top;

public:
  Stack() { top = nullptr; }
  void push(string data);
  string pop();
  void display();
  bool is_empty();
  bool is_full();
  bool is_paren_balanced(string exp);
};

void Stack::push(string data)
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

string Stack::pop()
{
  string x = "";
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

bool Stack::is_empty()
{
  return top ? 0 : 1;
}

bool Stack::is_paren_balanced(string exp)
{
  for (size_t i = 0; i < exp.length(); i++)
  {
    if (exp.at(i) == '(')
      push(exp.substr(i, 1));
    else if (exp.at(i) == ')')
    {
      if (is_empty())
        return false;
      else
        pop();
    }
  }
  return is_empty();
}

int main()
{

  string exp = "";
  cout << "Enter an expression containing '(' and ')' to check if they are balanced: ";
  cin >> exp;
  Stack s;
  cout << (s.is_paren_balanced(exp) ? "The parenthesis are balanced" : "The parenthesis are not balanced") << endl;

  return 0;
}