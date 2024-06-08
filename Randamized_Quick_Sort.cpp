/*
AIM : To implement Randamized Quick Sort
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void quicksort(int a[],int left,int right)
{
        int temp,l,r;
        if(left>=right)
        {
                return;
        }
        srand(time(NULL));
        int pivot=(rand()%(right-left+1))+left;
        temp=a[left];
        a[left]=a[pivot];
        a[pivot]=temp;
        pivot=left;
        r=right;
        l=left;
        while(l<r)
        {
             while(a[l]<=a[pivot])
             {
                     l++;
             }
             while(a[r]>a[pivot])
             {
                     r--;
             }
             if(l<r)
             {
                     temp=a[r];
                     a[r]=a[l];
                     a[l]=temp;
             }
        }
        temp=a[pivot];
        a[pivot]=a[r];
        a[r]=temp;
        
        quicksort(a,left,r-1);
        quicksort(a,r+1,right);
        
}
int main()
{
     cout<<"****************************";
     cout<<"    NAME   : MONISHA.S";
     cout<<"    REG.NO : 21BCT0414";
     cout<<"****************************";
     int n,a[50];
     cout<<"Enter the total number of values : ";
     cin>>n;
     cout<<"Enter values one by one : ";
     for(int i=0;i<n;i++)
     {
             cin>>a[i];
     }
     quicksort(a,0,n-1);
     cout<<"Sorted Array : ";
     for(int i=0;i<n;i++)
     {
             cout<<a[i]<<" ";
     }
}