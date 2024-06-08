/*Karatsuba's Faster Integer Multiplication*/
#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
int rec(int a,int b)
{
        string as=to_string(a);
        string bs=to_string(b);
        int alen=as.length();
        int blen=bs.length();
        if(alen==1 && blen==1)
        {
                return a*b;
        }
        else
        {
                int n=alen>blen?alen:blen;
                while(alen!=n)
                {
                        as="0"+as;
                        alen++;
                }
                while(blen!=n)
                {
                        bs="0"+bs;
                        blen++;
                }
                int m=ceil(n/2.0);
                int al=stoi(as.substr(0,n/2));
                int ar=stoi(as.substr(n/2,n-n/2));
                int bl=stoi(bs.substr(0,n/2));
                int br=stoi(bs.substr(n/2,n-n/2));
                
                int x1=rec(al,bl);
                int x2=rec(al+ar,bl+br);
                int x3=rec(ar,br);
                
                return (x1*pow(10,m*2)+(x2-x1-x3)*pow(10,m)+x3);
        }
}
int main()
{
    cout<<"Multiplication of Given two Numbers is "<<rec(1980,2315);
    return 0;
}