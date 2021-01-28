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
  l.nth_node_from_start(4);
  l.nth_node_from_end(4);
  l.display_ll();

  return 0;
}