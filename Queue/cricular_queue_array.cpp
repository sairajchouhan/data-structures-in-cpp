#include <iostream>
using namespace std;

class CircularQueue
{
public:
  int front, rear, size;
  int *q;
  CircularQueue()
  {
    front = rear = 0;
  }

  void create_queue();
  void enqueue(int data);
  int dequeue();
  void display();

  bool is_empty();
  bool is_full();
};

void CircularQueue::create_queue()
{
  q = new int[size];
  if (!q)
    return;
}

bool CircularQueue::is_empty()
{
  return front == rear;
}

bool CircularQueue::is_full()
{
  return (rear + 1) % size == front;
}

void CircularQueue::enqueue(int data)
{

  if (is_full())
    cout << "queue is full :)" << endl;
  else
  {
    rear = (rear + 1) % size;
    q[rear] = data;
  }
}

void CircularQueue::display()
{
  int index = front;
  do
  {
    index = (index + 1) % size;
    cout << q[index] << " ";
  } while (index != rear);

  cout << endl;
}

int CircularQueue::dequeue()
{
  int x = -1;
  if (!is_empty())
  {
    front = (front + 1) % size;
    x = q[front];
  }
  return x;
}

int main()
{
  CircularQueue Q;
  cout << "Enter the size of the queue: ";
  int input{0};
  cin >> input;
  Q.size = input + 1;
  Q.create_queue();

  Q.enqueue(2);
  Q.enqueue(22);
  Q.enqueue(222);
  Q.display();
  Q.dequeue();
  Q.display();

  return 0;
}