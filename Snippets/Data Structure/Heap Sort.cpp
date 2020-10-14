#include <bits/stdc++.h>
using namespace std;

int left(int i)   { return 2*i;   }
int right(int i)  { return 2*i+1; }
int parent(int i) { return i/2;   }

void max_heapify(int heap[],int heap_size, int i)
{
    int l,r,largest;
    l=left(i);
    r=right(i);

    if(l<=heap_size && heap[l]>heap[i])
        largest=l;
    else
        largest=i;

    if(r<=heap_size && heap[r]>heap[largest])
        largest=r;

    if(largest!=i)
    {
        swap(heap[largest],heap[i]);
        max_heapify(heap,heap_size,largest);
    }
}

void build_max_heap(int heap[], int heap_size)
{
    int i;
    for(int i=heap_size/2;i>=1;i--)
        max_heapify(heap,heap_size,i);
}
void heap_sort(int heap[], int heap_size)
{
    for(int i=heap_size;i>1;i--)
    {
        swap(heap[1],heap[i]);
        max_heapify(heap,i-1,1);
    }
}
int main()
{
    int heap_size=9;
    int heap[]={0,7,19,10,3,12,5,17,1,2};

    build_max_heap(heap,heap_size);
    heap_sort(heap,9);
    for(int i=1;i<=9;i++)
        cout<<heap[i]<<" ";
    return 0;
}
