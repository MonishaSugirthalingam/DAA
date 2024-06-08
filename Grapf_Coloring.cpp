/*Graph Coloring*/
#include <iostream>
using namespace std;
int n=5;
int adj[5][5]={{0,1,1,0,0},{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{0,1,1,1,0}};
int m=3;
int color[5];
bool issafe(int v,int c)
{
        for(int i=0;i<n;i++)
        {
                if(adj[v][i]==1 && c==color[i])
                {
                        return false;
                }
        }
        return true;
}
void print()
{
        for(int i=0;i<n;i++)
        {
                cout<<color[i]<<" ";
        }
}
bool solve(int v)
{
        if(v==n)
        {
                return true;
        }
        for(int i=1;i<=m;i++)
        {
              if(issafe(v,i))
              {
                      color[v]=i;
                      if(solve(v+1))
                      {
                              return true;
                      }
                      color[v]=0;
              }
        }
        return false;
}
int main()
{
    for(int i=1;i<=m;i++)
    {
        color[i]=0;    
    }
    if(solve(0))
    {
            print();
    }
    else
    {
            cout<<"Colors Not enough";
    }
    return 0;
}




