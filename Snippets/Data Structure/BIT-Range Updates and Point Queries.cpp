#include <iostream>
using namespace std;

#define MAX 100005
int data[MAX];
long long tree[MAX];

void updateBIT(int n, int index, int val)
{
    while (index <= n)
    {
        tree[index] += val;
        index += index & (-index);
    }
}
void update( int n, int l, int r, int val)
{

    updateBIT(n, l, val);
    updateBIT(n, r+1, -val);
}
void build_tree(int n)
{
    for (int i=1; i<=n; i++)
        update(n, i, i, data[i]);
}

long long getPoint(int index)
{
    long long sum = 0;

    while (index>0)
    {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

int main()
{


    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];

    build_tree(n);
    int l = 3, r = 5, val = 2;

    update(n,l, r,val);

    int index = 5;
    cout << "Element at index " << index << " is " <<
         getPoint(index) << "\n";


    l = 1, r = 4, val = 4;
    update(n,l, r, val);


    index = 4;
    cout << "Element at index " << index << " is " <<
         getPoint(index) << "\n" ;

    return 0;
}
