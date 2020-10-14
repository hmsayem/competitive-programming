#include <iostream>
#include <cstdlib>
using namespace std;

struct node 
{
    int data;
    node *left=NULL;
    node *right=NULL;
};
node *create(int item)
{
    node *new_node= new node();
    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
};

void add_left(node *parent, node *child)
{
    parent->left=child;
}
void add_right(node *parent, node *child)
{
    parent->right=child;
}

void pre_order(node *root)
{
    cout<<root->data<<endl;
    if(root->left!=NULL) pre_order(root->left);
    if(root->right!=NULL) pre_order(root->right);
}

void in_order(node *root)
{
    if(root->left!=NULL) in_order(root->left);
    cout<<root->data<<endl;
    if(root->right!=NULL) in_order(root->right);
}

void post_order(node *root)
{
    if(root->left!=NULL) post_order(root->left);
    if(root->right!=NULL) post_order(root->right);
    cout<<root->data<<endl;
}

node *create_tree()
{
    node *one   =create(1);
    node *two   =create(2);
    node *three =create(3);
    node *four  =create(4);
    node *five  =create(5);

    add_left(one,two);
    add_right(one,three);
    add_left(two,four);
    add_right(two,five);

    return one;
}
int main()
{
    node *root=create_tree();
}
