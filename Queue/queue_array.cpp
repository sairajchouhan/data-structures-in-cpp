#include <iostream>
using namespace std;

class Queue
{
public:
  int size, front, rear;
  int *q;

  Queue()
  {
    front = rear = -1;
  }
  ~Queue()
  {
    delete[] q;
  }

  void enqueue(int data);
  int dequeue();
  void create_queue();
  void display();
  bool is_empty();
  bool is_full();
};

void Queue::create_queue()
{
  q = new int[size];
  if (!q)
    return;
}

bool Queue::is_empty()
{
  return front == rear;
}

bool Queue::is_full()
{
  return rear == size - 1;
}

void Queue::display()
{
  for (int i = front + 1; i <= rear; i++)
    cout << q[i] << " ";
  cout << endl;
}

void Queue::enqueue(int data)
{
  if (is_full())
    cout << "Queue is full :)" << endl;
  else
    q[++rear] = data;
}

int Queue::dequeue()
{
  if (is_empty())
  {
    cout << "Cannot delete: Empty queue :)" << endl;
    return -1;
  }
  else
    return q[++front];
}

int main()
{

  Queue Q;
  // cout << "Enter the size of the queue: ";
  // cin >> Q.size;
  Q.size = 5;
  Q.create_queue();

  Q.enqueue(2);
  Q.enqueue(4);
  Q.enqueue(6);
  Q.enqueue(8);
  Q.enqueue(10);

  Q.display();
  Q.dequeue();
  Q.display();

  return 0;
}