#include <iostream>
using namespace std;

class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;

  Node(int d)
  {
    data = d;
    lchild = rchild = nullptr;
  }
};

class BinarySearchTree
{
  Node *root;

public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  Node *getRoot();
  void insert(int data);
  void inorder(Node *p);
  Node *search(int data);
};

Node *BinarySearchTree::getRoot()
{
  return root;
}

void BinarySearchTree::insert(int data)
{
  Node *t = root;
  Node *p;
  Node *r;

  // root is empty
  if (root == nullptr)
  {
    p = new Node(data);
    root = p;
    return;
  }

  while (t != nullptr)
  {
    r = t;
    if (data < t->data)
      t = t->lchild;
    else if (data > t->data)
      t = t->rchild;
    else
      return;
  }
  p = new Node(data);
  if (data < r->data)
    r->lchild = p;
  else
    r->rchild = p;
}

void BinarySearchTree::inorder(Node *p)
{
  if (p)
  {
    inorder(p->lchild);
    cout << p->data << ", " << flush;
    inorder(p->rchild);
  }
}

Node *BinarySearchTree::search(int data)
{
  Node *t = root;
  while (t != nullptr)
  {
    if (data == t->data)
    {
      return t;
    }
    else if (data < t->data)
    {
      t = t->lchild;
    }
    else
    {
      t = t->rchild;
    }
  }
  return nullptr;
}

int main()
{

  BinarySearchTree bst;

  // Insert
  bst.insert(10);
  bst.insert(5);
  bst.insert(20);
  bst.insert(8);
  bst.insert(30);

  // Inorder traversal
  bst.inorder(bst.getRoot());
  cout << endl;

  // Search
  Node *temp = bst.search(5);
  if (temp != nullptr)
  {
    cout << temp->data << endl;
  }
  else
  {
    cout << "Element not found" << endl;
  }

  return 0;
}