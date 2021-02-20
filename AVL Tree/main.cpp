#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  int height;
  Node *lchild;
  Node *rchild;
  Node(int d)
  {
    data = d;
    lchild = rchild = nullptr;
  }
};

class AVL
{
public:
  Node *root;
  Node *insert(Node *p, int key);
  int nodeHeight(Node *p);
  int balanceFactor(Node *p);
  void inorder(Node *p);

  Node *LLRotation(Node *p);
  Node *LRRotation(Node *p);
  Node *RRRotation(Node *p);
  Node *RLRotation(Node *p);
  Node *inorderPre(Node *p);
  Node *inorderSucc(Node *p);
  Node *recDelete(Node *p, int key);

  AVL()
  {
    root = nullptr;
  }
};

Node *AVL::LLRotation(Node *p)
{
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;

  pl->height = nodeHeight(pl);
  p->height = nodeHeight(p);

  if (root == p)
    root = pl;

  return pl;
}

Node *AVL::RRRotation(Node *p)
{
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  pr->lchild = p;
  p->rchild = prl;

  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if (p == root)
    root = pr;

  return pr;
}

Node *AVL::LRRotation(Node *p)
{
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;

  plr->lchild = pl;
  plr->rchild = p;

  pl->height = nodeHeight(pl);
  p->height = nodeHeight(p);
  plr->height = nodeHeight(plr);

  if (p == root)
    root = plr;

  return plr;
}

Node *AVL::RLRotation(Node *p)
{
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;

  prl->rchild = pr;
  prl->lchild = p;

  pr->height = nodeHeight(pr);
  p->height = nodeHeight(p);
  prl->height = nodeHeight(prl);

  if (root == p)
    root = prl;

  return prl;
}

Node *AVL::insert(Node *p, int key)
{
  if (root == nullptr)
  {
    Node *new_node = new Node(key);
    new_node->height = 1;
    root = new_node;
    return new_node;
  }
  if (p == nullptr)
  {
    Node *new_node = new Node(key);
    new_node->height = 1;
    return new_node;
  }
  if (key < p->data)
    p->lchild = insert(p->lchild, key);
  else if (key > p->data)
    p->rchild = insert(p->rchild, key);

  p->height = nodeHeight(p);

  // Balance Factor and Rotation
  if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
    return LLRotation(p);
  else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
    return LRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
    return RRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
    return RLRotation(p);

  return p;
}

int AVL::nodeHeight(Node *p)
{
  int hl, hr;
  hl = (p && p->lchild) ? p->lchild->height : 0;
  hr = (p && p->rchild) ? p->rchild->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int AVL::balanceFactor(Node *p)
{
  int hl, hr;
  hl = (p && p->lchild) ? p->lchild->height : 0;
  hr = (p && p->rchild) ? p->rchild->height : 0;

  return hl - hr;
}

void AVL::inorder(Node *p)
{
  if (p)
  {
    inorder(p->lchild);
    cout << p->data << " " << flush;
    inorder(p->rchild);
  }
}

Node *AVL::recDelete(Node *p, int key)
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
    if (nodeHeight(p->lchild) > nodeHeight(p->rchild))
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

  p->height = nodeHeight(p);

  // Balance Factor and Rotation
  if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
  { // L1 Rotation
    return LLRotation(p);
  }
  else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
  { // L-1 Rotation
    return LRRotation(p);
  }
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
  { // R-1 Rotation
    return RRRotation(p);
  }
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
  { // R1 Rotation
    return RLRotation(p);
  }
  else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0)
  { // L0 Rotation
    return LLRotation(p);
  }
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0)
  { // R0 Rotation
    return RRRotation(p);
  }

  return p;
}

Node *AVL::inorderPre(Node *p)
{
  while (p && p->rchild != nullptr)
    p = p->rchild;
  return p;
}

Node *AVL::inorderSucc(Node *p)
{
  while (p && p->lchild != nullptr)
    p = p->lchild;
  return p;
}

int main()
{
  // LL Rotation
  AVL tll;
  tll.insert(tll.root, 30);
  tll.insert(tll.root, 20);
  tll.insert(tll.root, 10);

  cout << "LL Rotation: ";
  tll.inorder(tll.root);
  cout << endl;

  // RR Rotation
  AVL trr;
  trr.insert(trr.root, 10);
  trr.insert(trr.root, 20);
  trr.insert(trr.root, 30);

  cout << "RR Rotation: ";
  trr.inorder(tll.root);
  cout << endl;

  // LR Rotation
  AVL tlr;
  tlr.insert(tlr.root, 50);
  tlr.insert(tlr.root, 10);
  tlr.insert(tlr.root, 20);

  cout << "LR Rotation: ";
  tlr.inorder(tlr.root);
  cout << endl;

  // RL Rotation
  AVL trl;
  trl.insert(trl.root, 20);
  trl.insert(trl.root, 50);
  trl.insert(trl.root, 30);

  cout << "RL Rotation: ";
  trl.inorder(trl.root);
  cout << endl;

  return 0;
}