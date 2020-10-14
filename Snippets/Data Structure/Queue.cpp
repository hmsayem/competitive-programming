
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class queue{

    int *data;
    int head;
    int tail;
    int capacity;

public:
    queue (int);
    void push(int);
    void pop();
    int  front();
    bool empty();
};
queue :: queue(int SIZE)
{
    data= new int[SIZE+1];
    capacity=SIZE+1;
    head=0;
    tail=0;
}
void queue :: push(int x)
{
    if((tail+1)%capacity==head)
        cout<<"Queue is full"<<endl;
    else
        data[tail++]=x;
    tail%=capacity;
}
void queue :: pop()
{
    if(tail==head)
        cout<<"Queue is empty"<<endl;
    else
        head++;
    head%=capacity;
}
bool queue :: empty()
{
    if(tail==head)
        return true;
    else
        return false;
}
int queue :: front()
{
     return data[head];
}
int main()
{
    queue q(3);
 
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}


