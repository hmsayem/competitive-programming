#include<bits/stdc++.h>
using namespace std;
bool visited[105][105];
char flood[105][105];
int m,n;
bool valid(int i , int j)
{
    if(i==m || j==n || i<0 || j<0 || visited[i][j]==true || flood[i][j]=='*')
        return false;
    else
        return true;

}
void floodfill(int i, int j)
{

    if(!valid(i,j))
        return;
    visited[i][j]=true;
    floodfill(i+1,j);
    floodfill(i-1,j);
    floodfill(i,j+1);
    floodfill(i,j-1);
    floodfill(i-1,j-1);
    floodfill(i-1,j+1);
    floodfill(i+1,j-1);
    floodfill(i+1,j+1);
}
int main()
{

    while(scanf("%d %d",&m,&n))
    {
        if(m==0)
            return 0;
        memset(visited,false,sizeof(visited));

        for(int i=0;i<m;i++)
            scanf("%s",flood[i]);

        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(flood[i][j]=='@' && visited[i][j]==false){
                    floodfill(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
