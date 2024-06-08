#include <iostream>
using namespace std;
struct Point
{
        int x,y;
};

int dir(Point p,Point q,Point r)
{
        return((r.x-p.x)*(q.x-p.x)-(r.y-p.y)*(q.y-p.y));
}
bool online(Point pi,Point pj,Point pk)
{
        int minx,maxx,miny,maxy;
        if(pi.x<=pj.x)
        {
             minx=pi.x;
             maxx=pj.x;
        }
        else
        {
                minx=pj.x;
                maxx=pi.x;
        }
        if(pi.y<=pj.y)
        {
             miny=pi.y;
             maxy=pj.y;
        }
        else
        {
                miny=pj.y;
                maxy=pi.y;
        }
        return (pk.x>=minx && pk.x<=maxx && pk.y>=miny && pk.y<=maxy);
}
bool intersect(struct Point p1,struct Point p2,struct Point p3,struct Point p4)
{
        int d1=dir(p3,p4,p1);
        int d2=dir(p3,p4,p2);
        int d3=dir(p1,p2,p3);
        int d4=dir(p1,p2,p4);
        if((d1>0 && d2<0 || d1<0 && d2>0) && (d3>0 && d4<0 || d3<0 && d4>0))
        {
                return true;
        }
        else if(d1==0 && online(p3,p4,p1))
        {
                return true;
        }
        else if(d2==0 && online(p3,p4,p2))
        {
                return true;
        }
        else if(d3==0 && online(p1,p2,p3))
        {
                return true;
        }
        else if(d4==0 && online(p1,p2,p4))
        {
                return true;
        }
        else
        {
                return false;
        }
}
int main()
{
    struct Point p1,p2,p3,p4;
    cin>>p1.x>>p1.y;
    cin>>p2.x>>p2.y;
    cin>>p3.x>>p3.y;
    cin>>p4.x>>p4.y;
    if(intersect(p1,p2,p3,p4))
    {
            cout<<"Yes Given Lines are Intersect\n";
    }
    else
    {
            cout<<"Not intersect\n";
    }
    return 0;
}
