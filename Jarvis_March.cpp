#include <iostream>
using namespace std;
struct Point
{
        int x,y;
};
int dir(Point p,Point q,Point r)
{
        int val=(r.x-p.x)*(q.y-p.y)-(q.x-p.x)*(r.y-p.y);
        if(val==0)
        {
                return 0;
        }
        
        return (val>0?1:2);
}
void ConvexHull(Point points[],int n)
{
        if(n<3)
        {
                return ;
        }
        bool intersect[n];
        for(int i=0;i<n;i++)
        {
                intersect[i]=false;
        }
        int left=0;
        for(int i=1;i<n;i++)
        {
                if(points[i].x<points[left].x)
                {
                        left=i;
                }
        }
        int prev=left,curr;
        do{
            curr=(prev+1)%n;
            for(int i=0;i<n;i++)
            {
                    if(dir(points[prev],points[curr],points[i])==2)
                    {
                            curr=i;
                    }
            }
            intersect[prev]=true;
            prev=curr;
        }while(prev!=left);
        
        for(int i=0;i<n;i++)
        {
                if(intersect[i]!=false)
                {
                        cout<<"("<<points[i].x<<","<<points[i].y<<")"<<"\n";
                }
        }
}
int main()
{
       int n;
       cout<<"Enter the Number of Lines : ";
       cin>>n;
       Point points[n];
       cout<<"Enter the Line Points\n";
       for(int i=0;i<n;i++)
       {
               cin>>points[i].x>>points[i].y;
       }
       cout<<"The points in the convex hull are\n";
       ConvexHull(points,n);
       return 0;
}