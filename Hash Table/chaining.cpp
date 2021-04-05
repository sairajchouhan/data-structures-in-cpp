#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class HashTable
{
public:
    Node **ht;

    int hash(int key)
    {
        return key % 10;
    }
    HashTable()
    {
        ht = new Node *[10];
        for (int i = 0; i < 10; i++)
            ht[i] = nullptr;
    }

    void insert(int key)
    {
        int idx = hash(key);
        Node *new_node = new Node(key);

        if (ht[idx] == nullptr)
            ht[idx] = new_node;
        else
        {
            Node *p = ht[idx];
            Node *q = ht[idx];
            while (p && p->data < key)
            {
                q = p;
                p = p->next;
            }
            if (q == ht[idx])
            {
                new_node->next = ht[idx];
                ht[idx] = new_node;
            }
            else
            {
                new_node->next = q->next;
                q->next = new_node;
            }
        }
    }

    int search(int key)
    {
        int idx = hash(key);
        Node *temp = ht[idx];
        while (temp)
        {
            if (temp->data == key)
                return key;
            temp = temp->next;
        }

        return -1;
    }

    ~HashTable()
    {
        for (int i = 0; i < 10; i++)
        {
            Node *p = ht[i];
            while (ht[i])
            {
                ht[i] = ht[i]->next;
                delete p;
                p = ht[i];
            }
        }
        delete[] ht;
    }
};

int main()
{
    int arr[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    HashTable h;
    for (int i = 0; i < n; i++)
        h.insert(arr[i]);

    cout << "Successful Search" << endl;
    int key = 6;
    int value = h.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = h.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

    return 0;
}