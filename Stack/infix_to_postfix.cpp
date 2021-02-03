#include <iostream>
#include <stack>
#include <string>

#define BOLDYELLOW "\033[1m\033[33m"
#define RESET "\033[0m"

using namespace std;

bool is_operand(char c)
{
  if (c == '+' || c == '-' || c == '/' || c == '*')
    return false;
  else
    return true;
}

int pre(char x)
{
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  else
    return 0;
}

bool greater_than_stack_top(char stack_top, char current)
{
  if (pre(current) > pre(stack_top))
    return true;
  else
    return false;
}

int main()
{
  cout << BOLDYELLOW << "THIS PROGRAM IMPLEMENTS INFIX TO POSTFIX CONVERSION USING ONLY '+', '-', '*' , '/'" << RESET << endl;
  stack<int> s;
  string infix = "";
  cout << "Enter the infix expression: ";
  cin >> infix;
  string postfix = "";

  for (size_t i = 0; i < infix.length(); i++)
  {
    if (is_operand(infix[i]))
      postfix += infix[i];
    else
    {
      while (!s.empty() && !greater_than_stack_top(s.top(), infix[i]))
      {
        postfix += s.top();
        s.pop();
      }
      s.push(infix[i]);
    }
  }
  while (!s.empty())
  {
    postfix += s.top();
    s.pop();
  }

  cout << postfix << endl;

  return 0;
}