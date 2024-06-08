/*Subset Problem*/
#include <iostream>
#include<stack>
using namespace std;
stack<int>stck;
bool found=false;
int tar=12;
int n=6;
int a[]={3,7,5,4,12};
void print()
{
        stack<int>temp;
        while(!stck.empty())
        {
                temp.push(stck.top());
                stck.pop();
        }
        while(!temp.empty())
        {
                cout<<temp.top()<<" ";
                stck.push(temp.top());
                temp.pop();
        }
}
void solve(int curr,int ind)
{
        if(curr>tar)
        {
                return;
        }
        if(curr==tar)
        {
              found=true;
              print();
              cout<<"\n";
              return;
        }
        for(int i=ind;i<n;i++)
        {
                stck.push(a[i]);
                solve(curr+a[i],i+1);
                stck.pop();
        }
}


int main()
{
    
    solve(0,0);
    if(found==false)
    {
            cout<<"No Solution";
    }
    return 0;
}
