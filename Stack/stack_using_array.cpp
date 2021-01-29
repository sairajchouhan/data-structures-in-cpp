#include <iostream>
using namespace std;

class Stack
{
private:
  int top;

public:
  int data, size;
  int *arr_stack;

  Stack();
  void push(int x);
  int pop();
  int peek(int pos);
  void display();
  int stack_top();
  bool is_empty();
  bool is_full();
};

Stack::Stack()
{
  top = -1;
  arr_stack = nullptr;
}

void Stack::push(int x)
{
  if (top == size - 1)
    cout << "Stack Overflow" << endl;
  else
    arr_stack[++top] = x;
}

int Stack::pop()
{
  if (top < 0)
  {
    cout << "Stack Underflow";
    return 0;
  }
  else
  {
    int x = arr_stack[top--];
    return x;
  }
}

int Stack::peek(int pos)
{
  int index = top - pos + 1;
  int res = -1;
  if (index < 0)
    cout << "Invalid Index" << endl;
  else
    res = arr_stack[index];
  return res;
}

void Stack::display()
{
  if (top < 0)
    cout << "Stack Empty";
  else
  {
    int i{0};
    for (int i = top; i >= 0; i--)
      cout << arr_stack[i] << endl;
  }
}

int Stack::stack_top()
{
  return top < 0 ? -1 : arr_stack[top];
}

bool Stack::is_empty()
{
  return top < 0;
}

bool Stack::is_full()
{
  return (top == size - 1) ? true : false;
}

int main()
{
  cout << "-----THIS PROGRAM IMPLEMENTS STACK USING ARRAY-----" << endl;

  Stack s;
  cout << "Enter the size of the stack: ";
  cin >> s.size;
  s.arr_stack = new int[s.size];

  int arr[s.size]{0};
  cout << "Enter elements into stack: " << endl;

  for (size_t i = 0; i < s.size; i++)
    cin >> arr[i];

  for (size_t i = 0; i < s.size; i++)
    s.push(arr[i]);

  cout << "------------------" << endl;
  cout << "The stack created is" << endl;
  s.display();

  cout << "------------------" << endl;
  cout << "pop() funtion is used to pop the top most element of the stack hence " << s.pop() << " is removed" << endl;
  s.display();
  cout << "------------------" << endl;
  cout << "2nd element of the stack is " << s.peek(2) << endl;
  cout << "------------------" << endl;
  cout << "Top element of the stack is " << s.stack_top() << endl;
  cout << "------------------" << endl;
  cout << "Is Stack full ?-" << (s.is_full() ? "Yes, stack is full" : "Nah! it still has some space") << endl;
  cout << "------------------" << endl;
  cout << "Is Stack empty ?-" << (s.is_empty() ? "Yup stack is empty" : "Nope! it is not empty") << endl;

  return 0;
}