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
  Node *recInsert(Node *p, int data);
  Node *recDelete(Node *p, int key);
  int height(Node *p);
  Node *inorderPre(Node *p);
  Node *inorderSucc(Node *p);
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

Node *BinarySearchTree::recInsert(Node *p, int data)
{
  if (root == nullptr)
  {
    Node *new_node = new Node(data);
    root = new_node;
    return new_node;
  }
  if (p == nullptr)
  {
    Node *new_node = new Node(data);
    return new_node;
  }
  if (data < p->data)
    p->lchild = recInsert(p->lchild, data);
  else if (data > p->data)
    p->rchild = recInsert(p->rchild, data);

  return p;
}

Node *BinarySearchTree::recDelete(Node *p, int key)
{

  if (p == nullptr)
    return nullptr;

  if (p->lchild == nullptr && p->rchild == nullptr)
  {
    if (p == root)
    {
      root = nullptr;
    }
    delete p;
    return nullptr;
  }

  if (key < p->data)
    p->lchild = recDelete(p->lchild, key);
  else if (key > p->data)
    p->rchild = recDelete(p->rchild, key);
  else
  {
    Node *q{nullptr};
    if (height(p->lchild) > height(p->rchild))
    {
      q = inorderPre(p->lchild);
      p->data = q->data;
      p->lchild = recDelete(p->lchild, q->data);
    }
    else
    {
      q = inorderSucc(p->rchild);
      p->data = q->data;
      p->rchild = recDelete(p->rchild, q->data);
    }
  }

  return p;
}

int BinarySearchTree::height(Node *p)
{
  int x, y;
  if (p == nullptr)
  {
    return 0;
  }
  x = height(p->lchild);
  y = height(p->rchild);
  return x > y ? x + 1 : y + 1;
}

Node *BinarySearchTree::inorderPre(Node *p)
{
  while (p && p->rchild != nullptr)
  {
    p = p->rchild;
  }
  return p;
}

Node *BinarySearchTree::inorderSucc(Node *p)
{
  while (p && p->lchild != nullptr)
  {
    p = p->lchild;
  }
  return p;
}

int main()
{

  BinarySearchTree bst;

  bst.recInsert(bst.getRoot(), 5);
  bst.recInsert(bst.getRoot(), 10);

  bst.recDelete(bst.getRoot(), 5);

  bst.inorder(bst.getRoot());
  cout << endl;

  return 0;
}