/* Author : Monisha.S
   DATE   : 20/03/2023
   AIM    : Implementation of Huffman Coding Algo*/
#include <iostream>
#include<queue>
using namespace std;
struct Node
{
        char letter;
        int freq;
        struct Node *left,*right;
        Node(char a,int b)
        {
                letter=a;
                freq=b;
        }
};

struct compare
{
        bool operator() (Node *l,Node *r)
        {
                return (l->freq>r->freq);
        }
};
void printcodes(struct Node *root,string s)
{
        if(root==NULL)
        {
                return;
        }
        if(root->letter!='*')
        {
                cout<<root->letter<<" "<<s<<"\n";
        }
        printcodes(root->left,s+"0");
        printcodes(root->right,s+"1");
}
void Hulf(char a[],int f[],int n)
{
     priority_queue<Node *,vector<Node*>,compare>pq;
     for(int i=0;i<n;i++)
     {
             pq.push(new Node(a[i],f[i]));
     }
     struct Node *lchild,*rchild;
     while(pq.size()!=1)
     {
        lchild=pq.top();
        pq.pop();
        rchild=pq.top();
        pq.pop();
        
        struct Node *temp=new Node('*',lchild->freq+rchild->freq);
        
        temp->left=lchild;
        temp->right=rchild;
        
        pq.push(temp);
        
     }
     
     printcodes(pq.top()," ");
}


int main()
{
    char a[]={'a','e','c','d','b','f'};
    int f[]={5,16,12,13,9,45};
    int n=6;
    Hulf(a,f,n);
    return 0;
}