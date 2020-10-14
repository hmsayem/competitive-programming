int SEQ[100000];
int A[100000];
vector <int> v;

void findSeq(int i)
{
    while(i!=-1)
    {
        v.push_back(A[i]);
        i=SEQ[i];
    }

    sort(v.begin(),v.end());
}
void LIS(int n)
{
    vector <int> temp;
    vector <int> pos;

    fill(SEQ,SEQ+n,-1);

    for(int i=0;i<n;i++)
    {
        if(temp.empty() || A[i]>temp.back()){

            if(!temp.empty())
            {
                SEQ[i]=pos.back();
            }
            temp.push_back(A[i]);
            pos.push_back(i);

        }
        else
        {
            int index = lower_bound(temp.begin(),temp.end(),A[i]) - temp.begin();
            if(index!=0)
                SEQ[i]=pos[index-1];
            temp[index]=A[i];
            pos[index]=i;
        }
    }

    findSeq(pos.back());
}

int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];

    LIS(n);
    
    for(auto x : v)
        cout<<x<<endl;
}
//https://www.youtube.com/watch?v=1RpMc3fv0y4
