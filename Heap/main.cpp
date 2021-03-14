#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int *heap{nullptr};
    int heapSize{0};
    int currentHeapSize;

    Heap(int size)
    {
        heapSize = size;
        currentHeapSize = 0;
        heap = new int[size + 1];
        heap[0] = 0;
    }
    ~Heap()
    {
        delete[] heap;
    }

    void insert(int key)
    {
        int i = currentHeapSize + 1;
        if (i == 1)
        {
            heap[i] = key;
            currentHeapSize++;
            return;
        }
        heap[i] = key;
        while (i > 1 && heap[i] > heap[i / 2])
        {
            heap[i] = heap[i / 2];
            heap[i / 2] = key;
            i = i / 2;
        }
        currentHeapSize++;
    }

    void printHeap()
    {
        if (currentHeapSize == 0)
        {
            cout << "0 Heap" << endl;
            return;
        }
        for (int i = 1; i <= currentHeapSize; i++)
            cout << heap[i] << " ";
    }
};

int main()
{

    Heap h(10);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(5);
    h.insert(10);
    h.insert(12);
    h.insert(6);
    h.insert(40);
    h.insert(35);
    h.printHeap();

    return 0;
}