/*Matrix Chain Multiplication*/
#include <iostream>
using namespace std;

int main()
{
    int r[]={13,5,89,3,34};
    int n=4;
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    dp[i][j]=0;
            }
    }
    for(int diff=2;diff<=n;diff++)
    {
            for(int i=0;i<=n-diff;i++)
            {
                    int j=i+diff-1;
                    int min=9999999;
                    for(int k=i;k<=j-1;k++)
                    {
                            int cost=dp[i][k]+dp[k+1][j]+(r[i]*r[k+1]*r[j+1]);
                            if(min>cost)
                            {
                                 min=cost;    
                            }
                    }
                    dp[i][j]=min;
                    
            }
    }
    
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    cout<<dp[i][j]<<"\t";
            }
            cout<<"\n";
    }
    return 0;
}