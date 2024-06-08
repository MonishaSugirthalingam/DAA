/*Fractional Knapsack Problem*/
#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
typedef struct node
{
        int w,v;
        float ratio;
}item;

void init(item a[],int n)
{
        for(int i=0;i<n;i++)
        {
                a[i].ratio=(float)a[i].v/a[i].w;
                cout<<a[i].ratio<<"\n";
                for(int i=0;i<n;i++)
                {
                        int max=i;
                        for(int j=i+1;j<n;j++)
                        {
                                if(a[j].ratio>a[max].ratio)
                                {
                                        max=j;
                                }
                        }
                        item temp;
                        temp=a[i];
                        a[i]=a[max];
                        a[max]=temp;
                }
        }
}

void change(item a[],int n,int cap)
{
      float amt=0;
      for(int i=0;i<n;i++)
      {
      if(a[i].w<=cap)
      {
              amt=amt+a[i].v;
              cap=cap-a[i].w;
      }
      else
      {
              amt=amt+((float)cap/(float)a[i].w)*a[i].v;
              break;
      }
      }
      cout<<"Maximum amount is "<<amt;
}
int main()
{
    int n=5;
    int cap=60;
    item a[]={{5,30},{10,40},{15,45},{22,77},{25,90}};
    init(a,n);
    change(a,n,cap);
    return 0;
}