#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string str) 
{
}

int main()
{
  string input = "ababaXababa";

  cout << (is_palindrome(input) ? "Yes the given string is a palindrome" : "Nope, the given string is no a palindrome") << endl;

  return 0;
}
