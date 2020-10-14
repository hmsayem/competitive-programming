
const int MAX=100005;
int x[MAX];
int ans[MAX];
int BLOCK=500;
struct node
{
    int L,R,INDEX;

}Q[MAX];

bool cmp (node x,node y)
{
    if(x.L/BLOCK!=y.L/BLOCK)
        return x.L/BLOCK<y.L/BLOCK;
    else
        return x.R<y.R;
}
void ADD(int index){
   
}

void REMOVE(int index){
   
}
int main()
{
    int  n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&Q[i].L,&Q[i].R);
        Q[i].INDEX=i;
    }

    sort(Q,Q+q,cmp);

    int LEFT,RIGHT,START,END;

    START=END=Q[0].L;
  
    for(int i=0;i<q;i++)
    {
        while(START<Q[i].L)
        {
            if(START<=END) REMOVE(START);
            START++;
        }
        while(START>Q[i].L)
        {
            START--;
            ADD(START);
        }
        while(END<Q[i].R)
        {
            END++;
            if(END>=START) ADD(END);
        }
        while(END>Q[i].R)
        {
            REMOVE(END);
            END--;
        }   
    }
}
