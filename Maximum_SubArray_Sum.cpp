/*Maximum Sub Array Sum*/
#include <iostream>

using namespace std;
int max(int a,int b)
{
    return (a>b?a:b);
}
int crosssum(int a[],int l,int mid,int h)
{
        int s=0;
        int left=-9999999;
        int right=-999999;
        for(int i=mid;i>=l;i--)
        {
             s=s+a[i];
             if(s>left)
             {
                     left=s;
             }
        }
        s=0;
        for(int j=mid+1;j<h;j++)
        {
                s=s+a[j];
                if(s>right)
                {
                        right=s;
                }
        }
        return (left+right);
}
int maxsum(int a[],int l,int h)
{
        if(l==h)
        {
                return a[l];
        }
        else
        {
                int mid=(l+h)/2;
                int temp=max(maxsum(a,0,mid),maxsum(a,mid+1,h));
                return max(temp,crosssum(a,l,mid,h));
        }
}
int main()
{
    int a[]={3,-1,-1,10,-3,-2,4};
    cout<<"Maximum Sum of the Given Array is "<<maxsum(a,0,7);
    return 0;
}