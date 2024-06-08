#include <iostream>
#include <time.h>
using namespace std;
struct Canditates
{
        int rank,interview_result;
};

int main()
{
    int n;
    cin>>n;
    struct Canditates *cand=new struct Canditates[n];
    
    for(int i=0;i<n;i++)
    {
            cin>>cand[i].rank;
    }
    
    srand(time(NULL));
    int best=-1;
    int index,no_hired=0;
    for(int i=0;i<n;i++)
    {
        do{
                index=rand()%n;
        }while(cand[index].interview_result==1);
        
        if(best==-1)
        {
                best=index;
                no_hired+=1;
        }
        else if(cand[index].rank>cand[best].rank)
        {
                best=index;
                no_hired+=1;
                
        }
    }
    cout<<"No of hired"<<"-"<<no_hired;
    cout<<"Best rank and Index "<<best<<" "<<cand[best].rank;
}