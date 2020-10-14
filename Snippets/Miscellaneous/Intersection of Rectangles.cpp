bool valid(int p, int q, int x1, int y1, int x2, int y2)
{
    if(p>=x5 && p<=x6 && q>=y5 && q<=y6)
        return true;
    else
        return false;
}
bool intersection(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4)
{
    x5 = max(x1, x3);
    y5 = max(y1, y3);
    x6 = min(x2, x4);
    y6 = min(y2, y4);

    if(valid(x5,y5,x1,y1,x2,y2) && valid(x5,y5,x3,y3,x4,y4) )
        return true;
    else
        return false;
}
