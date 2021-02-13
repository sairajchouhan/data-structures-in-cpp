#include <iostream>
#include <queue>
#include <stack>
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
  void preOrderIter(Node *p);
  void inOrderIter(Node *p);
  void postOrderIter(Node *p);
  int height(Node *p);
  int count(Node *p);
  int countLeafs(Node *p);
  int count2ndDegreeNodes(Node *p);
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
}

void Tree::preOrderIter(Node *p)
{
  stack<Node *> st;
  while (!st.empty() || p != nullptr)
  {
    if (p != nullptr)
    {
      st.push(p);
      cout << p->data << " ";
      p = p->lchild;
    }
    else
    {
      p = st.top();
      st.pop();
      p = p->rchild;
    }
  }
}

void Tree::inOrderIter(Node *p)
{
  stack<Node *> st;
  while (!st.empty() || p != nullptr)
  {
    if (p != nullptr)
    {
      st.push(p);
      p = p->lchild;
    }
    else
    {
      p = st.top();
      st.pop();
      cout << p->data << " ";
      p = p->rchild;
    }
  }
}

void Tree::postOrderIter(Node *p)
{
  stack<long int> st;
  long long int temp{0};

  while (!st.empty() || p != nullptr)
  {
    if (p != nullptr)
    {
      st.push((long int)p);
      p = p->lchild;
    }
    else
    {
      temp = st.top();
      st.pop();
      if (temp > 0)
      {
        st.push(0 - temp);
        p = ((Node *)temp)->rchild;
      }
      else
      {
        cout << ((Node *)(0 - temp))->data << " ";
        p = nullptr;
      }
    }
  }
}

int Tree::height(Node *p)
{
  int l = 0;
  int r = 0;
  Node *root = p;

  if (root != nullptr)
  {
    l = height(root->lchild);
    r = height(root->rchild);
    if (l > r)
      return l + 1;
    else
      return r + 1;
  }
  return -1;
}

int Tree::count(Node *p)
{
  int x{0}, y = {0};
  if (p != nullptr)
  {
    x = count(p->lchild);
    y = count(p->rchild);
    return x + y + 1;
  }
  return 0;
}

int Tree::countLeafs(Node *p)
{
  int x{0}, y{0};
  if (p != nullptr)
  {
    x = countLeafs(p->lchild);
    y = countLeafs(p->rchild);
    if (x == 0 && y == 0)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int Tree::count2ndDegreeNodes(Node *p)
{
  int x{0}, y{0};
  if (p != nullptr)
  {
    x = countLeafs(p->lchild);
    y = countLeafs(p->rchild);
    if (x != 0 && y != 0)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int main()
{

  Tree t;
  t.createTree();

  cout << "PreOrder traversal using reccursion: ";
  t.preOrder(t.root);
  cout << endl;
  cout << "PreOrder traversal using iteration: ";
  t.preOrderIter(t.root);
  cout << "\n----------------------------------------------------------" << endl;

  cout << "InOrder traversal using reccursion: ";
  t.inOrder(t.root);
  cout << endl;
  cout << "InOrder traversal using iteration: ";
  t.inOrderIter(t.root);
  cout << "\n----------------------------------------------------------" << endl;

  cout << "PostOrder traversal using reccursion: ";
  t.postOrder(t.root);
  cout << endl;
  cout << "PostOrder traversal using iteration: ";
  t.postOrderIter(t.root);
  cout << "\n----------------------------------------------------------" << endl;

  cout << "Height of the tree is: " << t.height(t.root) << endl;
  cout << "Number of nodes in the tree are: " << t.count(t.root) << endl;
  cout << "Number of nodes with degree 2 are: " << t.count2ndDegreeNodes(t.root) << endl;
  cout << "Number of leaf nodes in the tree are: " << t.countLeafs(t.root) << endl;

  return 0;
}