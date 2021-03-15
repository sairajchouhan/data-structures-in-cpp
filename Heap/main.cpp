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

    int del()
    {
        int res = {0};
        res = heap[1];
        heap[1] = heap[currentHeapSize];
        currentHeapSize--;

        int i = 1;
        while (heap[i] < heap[2 * i] || heap[i] < heap[2 * i + 1])
        {
            int leftSub = heap[i] - heap[2 * i];
            int rightSub = heap[i] - heap[2 * i + 1];
            if (leftSub < rightSub)
            {
                int temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = temp;
                i = 2 * i;
            }
            if (leftSub > rightSub)
            {
                int temp = heap[i];
                heap[i] = heap[2 * i + 1];
                heap[2 * i + 1] = temp;
                i = 2 * i + 1;
            }
        }

        return res;
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

    cout << h.del() << endl;
    cout << h.del() << endl;
    h.printHeap();
    return 0;
}