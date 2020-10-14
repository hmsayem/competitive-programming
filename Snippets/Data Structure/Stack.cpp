#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class stack
{
    int *data;
    int top;
    int capacity;

public:
    stack (int);
    void push(int);
    void pop();
    int  peek();
    bool empty();
};
stack :: stack(int SIZE)
{
    data= new int[SIZE];
    capacity=SIZE;
    top=0;
}
void stack :: push(int x)
{
    if(top==capacity)
        cout<<"Stack is full"<<endl;
    else
        data[top++]=x;

}
void stack :: pop()
{
    if(top==0)
        cout<<"Stack is empty"<<endl;
    else
        top--;
}
bool stack :: empty()
{
    if(top==0)
        return true;
    else
        return false;
}
int stack :: peek()
{
     return data[top-1];
}
int main()
{    
    stack s(3);

    s.push(1);
    s.push(2);
    s.push(3);
    
    while(!s.empty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
}
