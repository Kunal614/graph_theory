#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define p pop
#define ps push

int main()
{ 
    queue<int> gq;
    vector<int> vertex[100];
    int v,indegree[100],long_path[100];
    int item;
    cout<<"Enter the vertex :: ";
    cin>>v;
    cout<<"Enter adjacent element if present else enter -1\n";
    for(int i=1;i<=v;i++)
    {
         int k;
        cout<<"Enter the adjacent element of "<<i<<" :: ";
         do
         {
              cin>>k;
              if(k!=-1)
              {
                  vertex[i].pb(k);
              }

         }while(k!=-1);
    }
    memset(indegree,0,sizeof(indegree));
    memset(long_path,0,sizeof(long_path));
    for(int i=1;i<=v;i++)
    {
        cout<<i<<" -- ";
        for(auto it=vertex[i].begin();it!=vertex[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=v;i++)
    {
        for(auto it=vertex[i].begin();it!=vertex[i].end();it++)
        {
            indegree[*it]++;
        }

    }
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
        {
            gq.ps(i);
        }
    }
    cout<<"Indegree order :: ";
    while(!gq.empty())
    {
        item=gq.front();
        cout<<item<<" ";
        gq.p();
       for(auto it=vertex[item].begin();it!=vertex[item].end();it++)
       {
           indegree[*it]--;
           long_path[*it]=max(long_path[*it],1+long_path[*it]);
           if(indegree[*it]==0)
           {
               gq.ps(*it);
           }
       }   
    }
    
   
    cout<<endl<<"path_traversal :: ";
    for(int i=1;i<=v;i++)
    {
        cout<<long_path[i]<<" ";
    }
    cout<<endl;
    cout<<"Longest path is :: "<<long_path[v]<<endl;;
}        