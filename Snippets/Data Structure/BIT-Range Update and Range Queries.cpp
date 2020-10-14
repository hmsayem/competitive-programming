#include <iostream>
using namespace std;
#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)
#define MAX 100005
int data[MAX];
long long tree1[MAX];
long long tree2[MAX];

void updateBIT(long long tree[], int n, int index, int val)
{
    while (index <= n)
    {
        tree[index] += val;
        index += index & (-index);
    }
}
void update( int n, int l, int r, int val)
{

    updateBIT(tree1, n, l, val);
    updateBIT(tree1, n, r+1, -val);
    updateBIT(tree2, n, l, (l-1)*val);
    updateBIT(tree2, n, r+1, -r*val);
}
void build_tree(int n)
{
    for (int i=1; i<=n; i++)
        update(n, i, i, data[i]);
}

long long getPoint(long long tree[], int index)
{
    long long sum = 0;

    while (index>0)
    {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

long long rangeSum(int l, int r)
{
    long long L= getPoint(tree1,l-1)*(l-1)-getPoint(tree2,l-1);
    long long R= getPoint(tree1,r)*r-getPoint(tree2,r);
    return R-L;


}
int main()
{

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    build_tree(n);

    int l = 1 , r = 5 , val = 5;
    update(n,l,r,val);

    l = 3 , r = 5 , val = 10;
    update(n,l,r,val);

    l = 2 , r = 5;
    cout << "Sum of elements from [" << l
         << "," << r << "] is ";
    cout << rangeSum(l,r) << "\n";

}
