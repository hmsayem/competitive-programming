#include<bits/stdc++.h>
using namespace std;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int grid[1005][1005];
int level [1005][1005];
int R,C;
void bfs(int x, int y)
{
    queue< pair<int , int> > q;
    level[x][y] = 0;
    q.push({x,y});

    while (!q.empty())
    {
        pair <int,int> u = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx=u.first+fx[i];
            int vy=u.second+fy[i];

            if(vx>=0 && vx<R && vy>=0 && vy<C && grid[vx][vy]!=-1 && level[vx][vy]==0)
            {
                level[vx][vy]=level[u.first][u.second]+1;
                q.push({vx,vy});
            }
        }
    }
}

int main()
{

}
