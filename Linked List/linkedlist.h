#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

class Node
{
public:
  int data;
  Node *next;
};

class LinkedList
{
private:
  Node *head, *tail, *tracer;
  bool check_node_exists(int n);

public:
  LinkedList()
  {
    head = nullptr;
    tail = nullptr;
    tracer = head;
  }

  Node *get_head();
  void reverse_ll();
  void add_node(int data);
  void add_to_head(int data);
  void add_to_tail(int data);
  void add_to_nth_node(int data, int);
  void delete_nth_node(int n);
  int len_of_ll();
  void display_ll();
  void display_ll_rec_rev(Node *head);
  void display_ll_rec(Node *head);
  void nth_node_from_start(int n);
  void nth_node_from_end(int n);
  void delete_ll();
};

void LinkedList::reverse_ll()
{
  Node *current, *previous = nullptr, *next = nullptr;
  current = head;
  while (current != nullptr)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head = previous;
}

bool LinkedList::check_node_exists(int n)
{
  if (n < 0 || n > this->len_of_ll())
  {
    cout << BOLDRED
         << n << "th node does not exist"
         << RESET << endl;
    cout << BOLDRED
         << "The range of the Linked List is from 1 to "
         << this->len_of_ll()
         << RESET << endl;
    return false;
  }
  else
    return true;
}

Node *LinkedList::get_head()
{
  Node *head_node = head;
  return head_node;
}

void LinkedList::display_ll()
{
  tracer = head;
  if (tracer == nullptr)
    cout
        << RED << "Empty Linked List :)" << RESET << endl;

  while (tracer != nullptr)
  {
    cout << tracer->data;
    if (tracer->next != nullptr)
      cout << "\033[1m\033[32m ==> \033[0m";
    tracer = tracer->next;
  }
  cout << endl;
  tracer = head;
}

void LinkedList::display_ll_rec(Node *head)
{
  if (head == nullptr)
  {
    cout << endl;
    return;
  }
  else
  {
    cout << head->data;
    if (head->next != nullptr)
      cout << "\033[1m\033[32m ==> \033[0m";
    display_ll_rec(head->next);
  }
}

void LinkedList::display_ll_rec_rev(Node *head)
{

  if (head == nullptr)
  {
    return;
  }
  else
  {
    display_ll_rec_rev(head->next);
    if (head->next != nullptr)
      cout << "\033[1m\033[32m ==> \033[0m";
    cout << head->data;
  }
}

int LinkedList::len_of_ll()
{
  tracer = head;
  int length{0};

  while (tracer != nullptr)
  {
    ++length;
    tracer = tracer->next;
  }

  tracer = head;
  return length;
}

void LinkedList::add_to_nth_node(int data, int n = 1)
{
  if (!this->check_node_exists(n))
    return;
  tracer = head;
  int i{1};

  if (n == 1)
  {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return;
  }
  while (i < n - 1)
  {
    i++;
    tracer = tracer->next;
  }

  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = tracer->next;
  tracer->next = new_node;

  tracer = head;
}

void LinkedList::add_to_tail(int data)
{
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = nullptr;
  if (head == nullptr)
  {
    head = new_node;
    tail = new_node;
  }
  else
    tail->next = new_node;
}

void LinkedList::add_to_head(int data)
{
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = nullptr;
  if (head == nullptr)
  {
    head = new_node;
    tail = new_node;
  }
  else
  {
    new_node->next = head;
    head = new_node;
  }
}

void LinkedList::add_node(int data)
{
  Node *temp = new Node();
  temp->data = data;
  temp->next = nullptr;

  if (head == nullptr)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = tail->next;
  }
}

void LinkedList::delete_nth_node(int n = 1)
{

  if (!this->check_node_exists(n))
    return;
  tracer = head;
  int i{1};
  while (i < n - 1)
  {
    i++;
    tracer = tracer->next;
  }
  if (n == 1)
  {
    Node *delete_node = tracer;
    head = delete_node->next;
    delete delete_node;
    return;
  }
  Node *delete_node = tracer->next;
  tracer->next = tracer->next->next;
  delete delete_node;
  tracer = head;
}

void LinkedList::nth_node_from_end(int n)
{
  if (!this->check_node_exists(n))
    return;
  tracer = head;
  int i{1}, nth_from_start = this->len_of_ll() - n + 1;
  while (i < nth_from_start)
  {
    ++i;
    tracer = tracer->next;
  }

  cout << "Node at position " << n << " from end is " << tracer->data << endl;
  tracer = head;
}

void LinkedList::nth_node_from_start(int n)
{
  if (!this->check_node_exists(n))
    return;
  tracer = head;
  int i{1};
  while (i < n)
  {
    ++i;
    tracer = tracer->next;
  }

  cout << "Node at position " << n << " from start is " << tracer->data << endl;
  tracer = head;
}

void LinkedList::delete_ll()
{
  tracer = head;
  while (tracer != nullptr)
  {
    head = tracer->next;
    delete tracer;
    tracer = head;
  }
}