#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *left=NULL;
    node *right=NULL;
    node *parent=NULL;
};

node *create(int item)
{
    node *new_node= new node();
    new_node->data=item;
    return new_node;
};

void add_left(node *parent_node, node *child_node)
{
    parent_node->left=child_node;
    child_node->parent=parent_node;
}
void add_right(node *parent_node, node *child_node)
{
    parent_node->right=child_node;
    child_node->parent=parent_node;
}
node *bst_minimum(node *root)
{
    node *current_node=root;
    while(current_node->left!=NULL)
    {
        current_node=current_node->left;
    }
    return current_node;
}
node *bst_insert(node *root, node *new_node)
{
    if(root==NULL)
        return new_node;

    node *parent_node=NULL,*current_node=root;

    while(current_node!=NULL)
    {
        parent_node=current_node;
        if(new_node->data<current_node->data)
            current_node=current_node->left;
        else
            current_node=current_node->right;
    }
    if(new_node->data<parent_node->data)
        add_left(parent_node,new_node);

    else
        add_right(parent_node,new_node);

    return root;
}

node *bst_transplant(node *root, node *current_node, node *new_node)
{
    if(current_node==root)
        root = new_node;
    else if(current_node==current_node->parent->left)
        add_left(current_node->parent,new_node);
    else
        add_right(current_node->parent,new_node);
    return root;
}

node *bst_delete(node *root, node *target)
{
    if(target->left==NULL)
        root=bst_transplant(root,target,target->right);
    else if(target->right==NULL)
        root=bst_transplant(root,target,target->left);
    else
    {
        node *smallest_node=bst_minimum(target->right);
        if(smallest_node->parent!=target)
        {
            root=bst_transplant(root,smallest_node,smallest_node->right);
            add_right(smallest_node,target->right);
        }
        root=bst_transplant(root,target,smallest_node);
        add_left(smallest_node,target->left);
    }
    delete(target);
    return root;
}

void pre_order(node *root)
{
    cout<<root->data<<endl;
    if(root->left!=NULL) pre_order(root->left);
    if(root->right!=NULL) pre_order(root->right);
}

int main()
{
    node *root=NULL;

    node *node1=create(20);
    node *node2=create(50);
    node *node3=create(80);
    node *node4=create(10);
    node *node5=create(35);
    node *node6=create(25);
    node *node7=create(40);
    node *node8=create(5);
    node *node9=create(75);
    node *node10=create(77);

    root=bst_insert(root,node1);
    bst_insert(root,node2);
    bst_insert(root,node3);
    bst_insert(root,node4);
    bst_insert(root,node5);
    bst_insert(root,node6);
    bst_insert(root,node7);
    bst_insert(root,node8);
    bst_insert(root,node9);
    bst_insert(root,node10);

    bst_delete(root,node2);
    pre_order(root);
}
