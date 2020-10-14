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

int extract_max(int heap[], int heap_size)
{
    int max_item=heap[1];
    heap[1]=heap[heap_size];
    heap_size-=1;
    max_heapify(heap,heap_size,1);
    return max_item;
}

insert_node(int heap[], int heap_size, int node)
{
    int p,i;
    heap_size+=1;
    heap[heap_size]=node;
    i=heap_size;

    while(i>1 && heap[i]>heap[parent(i)])
    {
        p=parent(i);
        swap(heap[i],heap[p]);
        i=p;
    }
}

int main()
{
    int heap_size=9;
    int heap[]={0,7,19,10,3,12,5,17,1,2};

    build_max_heap(heap,heap_size);
    
    cout<<extract_max(heap,heap_size)<<endl;
    heap_size-=1;
    insert_node(heap,heap_size,100);
    heap_size+=1;
}
