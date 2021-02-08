#include <iostream>
using namespace std;

class LinkedListNode
{
public:
  int data;
  LinkedListNode *next;

  LinkedListNode(int d)
  {
    data = d;
    next = nullptr;
  }
};

class Queue
{
public:
  LinkedListNode *front, *rear;
  Queue()
  {
    front = nullptr;
    rear = nullptr;
  }
  void enqueue(int data);
  int dequeue();
  void display();
};

void Queue::enqueue(int data)
{
  LinkedListNode *new_node = new LinkedListNode(data);
  if (!new_node)
    return;
  if (front == nullptr)
  {
    front = new_node;
    rear = new_node;
  }
  else
  {
    rear->next = new_node;
    rear = rear->next;
  }
}

void Queue::display()
{
  LinkedListNode *current = front;
  while (current != nullptr)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int Queue::dequeue()
{
  int res = -1;
  if (front == nullptr)
    cout << "Empty queue :)" << endl;
  else
  {
    LinkedListNode *delete_node = front;
    front = front->next;
    res = delete_node->data;
    delete delete_node;
  }
  return res;
}

int main()
{
  Queue Q;
  Q.enqueue(1);
  Q.enqueue(11);
  Q.enqueue(111);

  Q.display();
  Q.dequeue();
  Q.display();

  return 0;
}
