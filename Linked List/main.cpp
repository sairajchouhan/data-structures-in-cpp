#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
  LinkedList l;
  int arr[5] = {2, 5, 12, 6, 20};
  for (size_t i = 0; i < 5; i++)
    l.add_node(arr[i]);

  l.display_ll();
  l.reverse_ll();
  l.display_ll();

  return 0;
}