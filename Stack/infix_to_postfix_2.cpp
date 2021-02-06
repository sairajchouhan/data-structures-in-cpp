#include <iostream>
#include <stack>
#include <string>
#include <cctype>

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
  if (x == '(')
    return 0;
  else
    return 0;
}

string convert(string infix)
{
  stack<int> st;
  string postfix = "";
  for (size_t i = 0; i < infix.length(); i++)
  {
    if (isalnum(infix[i]))
      postfix += infix[i];
    else if (infix[i] == '(')
      st.push(infix[i]);
    else if (infix[i] == ')')
    {
      while (st.top() != '(')
      {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {
      while (!st.empty() && st.top() != '(' && pre(infix[i]) <= pre(st.top()))
      {
        postfix += st.top();
        st.pop();
      }
      st.push(infix[i]);
    }
  }
  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

int main()
{

  cout << BOLDYELLOW << "THIS PROGRAM IMPLEMENTS INFIX TO POSTFIX CONVERSION USING  '+', '-', '*' , '/' and paranthesis" << RESET << endl;

  // string infix = "A*B-(C+D)+E";
  string infix = "";
  cout << "Enter infix expression including paranthesis" << endl;
  cout << "Example: A*B-(C+D)+E" << endl;
  cin >> infix;

  cout << "The postfix expression is: ";
  cout << convert(infix) << endl;

  return 0;
}
