/*N Queens Problem*/
#include <iostream>
using namespace std;
int n=4;
int chess[4][4];
bool found=false;
bool issafe(int row,int col)
{
        for(int i=col;i>=0;i--)
        {
                if(chess[row][i]==1)
                {
                        return false;
                }
        }
        for(int i=row,j=col;i>=0,j>=0;i--,j--)
        {
                if(chess[i][j]==1)
                {
                        return false;
                }
        }
        for(int i=row,j=col;i<n,j>=0;i++,j--)
        {
                if(chess[i][j]==1)
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
                for(int j=0;j<n;j++)
                {
                        if(chess[i][j]==1)
                        {
                        cout<<"Q"<<" ";
                        }
                        else
                        {
                        cout<<"-"<<" ";
                        }
                       
                }
                 cout<<"\n";
        }
}
void solve(int col)
{
        if(col==n)
        {
                found=true;
                print();
                return;
        }
        for(int i=0;i<n;i++)
        {
                if(issafe(i,col))
                {
                        chess[i][col]=1;
                        solve(col+1);
                        chess[i][col]=0;
                }
        }
}
int main()
{
    solve(0);
    if(found==false)
    {
        cout<<"No solution";
    }
    return 0;
}




