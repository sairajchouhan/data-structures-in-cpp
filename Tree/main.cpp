#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  Node *lchild;
  Node *rchild;
  int data;
  Node();
  Node(int d);
};

Node::Node()
{
  lchild = rchild = nullptr;
}
Node::Node(int d)
{
  data = d;
  lchild = rchild = nullptr;
}

class Tree
{
public:
  Node *root;

  Tree() { root = nullptr; }

  void createTree();
  void preOrder(Node *p);
  void postOrder(Node *p);
  void inOrder(Node *p);
  void levelOrder(Node *p);
  void height(Node *p);
};

void Tree::createTree()
{
  Node *currnet{nullptr}, *temp{nullptr};
  queue<Node *> q;
  int x{0};
  cout << "Enter the value of root node: ";
  cin >> x;
  root = new Node(x);
  if (!root)
    return;
  q.push(root);
  while (!q.empty())
  {
    currnet = q.front();
    q.pop();
    cout << "Enter the left child of " << currnet->data << ": ";
    cin >> x;
    if (x != -1)
    {
      temp = new Node(x);
      currnet->lchild = temp;
      q.push(temp);
    }
    cout << "Enter the right child of " << currnet->data << ": ";
    cin >> x;
    if (x != -1)
    {
      temp = new Node(x);
      currnet->rchild = temp;
      q.push(temp);
    }
  }

  delete q;
}

void Tree::preOrder(Node *p)
{
  if (p)
  {
    cout << p->data << " ";
    preOrder(p->lchild);
    preOrder(p->rchild);
  }
}

void Tree::inOrder(Node *p)
{
  if (p)
  {
    inOrder(p->lchild);
    cout << p->data << " ";
    inOrder(p->rchild);
  }
}

void Tree::postOrder(Node *p)
{
  if (p)
  {
    postOrder(p->lchild);
    postOrder(p->rchild);
    cout << p->data << " ";
  }
}

void Tree::levelOrder(Node *p)
{
  queue<Node *> q;
  Node *current{nullptr};
  q.push(p);
  while (!q.empty())
  {
    current = q.front();
    cout << current->data << " ";
    q.pop();
    if (current->lchild != nullptr)
      q.push(current->lchild);
    if (current->rchild != nullptr)
      q.push(current->rchild);
  }
  delete q;
}

int main()
{

  Tree t;
  t.createTree();
  t.preOrder(t.root);
  cout << endl;
  t.inOrder(t.root);
  cout << endl;
  t.postOrder(t.root);
  cout << endl;
  t.levelOrder(t.root);

  return 0;
}