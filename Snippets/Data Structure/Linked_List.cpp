#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node {
    int data;
    node *next;
};

node *root=NULL;
void append(int data)
{
    if(root==NULL)
    {
        root=new node();
        root->data=data;
        root->next=NULL;
    }
    else
    {
        node *current_node=root;
        while(current_node->next!=NULL)
        {
            current_node=current_node->next;
        }
        node *new_node= new node();
        current_node->next=new_node;
        new_node->data=data;
        new_node->next=NULL;
    }
}
void insert(int data, int position)
{
    if(root==NULL)
    {
        root=new node();
        root->data=data;
        root->next=NULL;
    }
    else
    {
        node * new_node=new node();
        new_node->data=data;
        if(position==1)
        {
            new_node->next=root;
            root=new_node;
        }
        else
        {
            node * current_node= root;
            for(int i=1;i<=position-2;i++)
            {
                current_node=current_node->next;
            }
            new_node->next=current_node->next;
            current_node->next=new_node;
        }
    }
}
void print()
{
    node *current_node=root;
    while(current_node!=NULL)
    {
        cout<<current_node->data<<" -> "<<" ";
        current_node=current_node->next;
    }
    cout<<"NULL"<<endl;
}
void Delete(int data)
{   
    node *current_node=root;
    node *previous_node=NULL;
    while(current_node->data!=data)
    {
        previous_node=current_node;
        current_node=current_node->next;
        if(current_node==NULL)
            return;
    }
    if(current_node==root)
    {
        node *temp=root;
        root=root->next;
        delete(temp);
    }
    else
    {
        previous_node->next=current_node->next;
        delete(current_node);
    }
}
int main()
{
    append(1);
    append(2);
    append(3);
    print();  
}


