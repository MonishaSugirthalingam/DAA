#include <iostream>

using namespace std;
void fun(string p,int LPS[])
{
        int plen=p.length();
        int i=0,j=1;
        LPS[0]=0;
        while(j<plen)
        {
                if(p[i]==p[j])
                {
                   LPS[j]=i+1;
                   i++;
                   j++;
                }
                else
                {
                        if(i==0)
                        {
                                LPS[j]=0;
                                j++;
                        }
                        else
                        {
                                i=LPS[i-1];
                        }
                }
        }
}
int main()
{
    string s="abcddcfaaabcdd";
    string p="dd";
    int slen=s.length();
    int plen=p.length();
    int LPS[plen];
    fun(p,LPS);
    int i=0,j=0;
    while(i<slen)
    {
            if(p[j]==s[i])
            {
                    i++;j++;
            }
            if(j==plen)
            {
                    cout<<i-j<<" ";
                    j=LPS[j-1];
            }
            if(i<slen && p[j]!=s[i])
            {
                    if(j==0)
                    {
                            i++;
                    }
                    else
                    {
                            j=LPS[j-1];
                    }
            }
    }
    return 0;
}
