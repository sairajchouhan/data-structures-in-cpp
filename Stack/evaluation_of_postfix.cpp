#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

#define BOLDYELLOW "\033[1m\033[33m"
#define RESET "\033[0m"

int evaluate_postfix(string postfix)
{
  stack<int> st;
  for (int i = 0; i < postfix.length(); i++)
  {
    if (isdigit(postfix[i]))
      st.push(postfix[i] - '0');
    else
    {
      int ro{0}, lo{0};
      ro = st.top();
      st.pop();
      lo = st.top();
      st.pop();

      switch (postfix[i])
      {
      case '+':
        st.push(lo + ro);
        break;
      case '-':
        st.push(lo - ro);
        break;
      case '*':
        st.push(lo * ro);
        break;
      case '/':
        st.push(lo / ro);
        break;
      default:
        break;
      }
    }
  }
  return st.top();
}

int main()
{
  string postfix = "";
  cout << BOLDYELLOW << "THIS PROGRAM IMPLEMENTS POSTFIX EVALUATION USING BINARY OPERATORS ONLY" << RESET << endl;
  cout << "Enter a postfix expression" << endl;
  cin >> postfix;
  cout << evaluate_postfix(postfix) << endl;

  return 0;
}