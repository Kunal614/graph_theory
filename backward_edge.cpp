#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> v[100];
map<int , char> check_visit;
map<int,int> par;
// e = explored , v='visited' , -1='unvisited'
int x=0,y=-1;
//checking backward edge
int dfs(int n)
{
        check_visit[n]='e';
        for(auto it=v[n].begin();it!=v[n].end();it++)
        {
             
            if(check_visit[*it]==-1)
                 {
                     par[*it]=n;
                     dfs(*it);
                 }
            if(check_visit[*it]=='e' && par[n]!=*it)    //explore==explore
               x++; 

               
        }
     check_visit[n]='v';  
}
int main()
{
    int n;
    
    cout<<"Enter the vertex\n";
    cin>>n;
    cout<<"Enter the edges\n";
    int k;
    cin>>k;

    for(int i=0;i<k;i++)
    {
           cout<<"Enter the two adjacent elements\n";
           int l,m;
           cin>>l>>m;
           v[l].pb(m);
           
    }
   
    for(int i=0;i<n;i++)
       check_visit[i]=-1;

    for(int i=0;i<n;i++)
    {
        if(check_visit[i]==-1)
          { cout<<"wed"<<endl;
               dfs(i);y++;}
    }
    cout<<"Number of disconnected component is "<<y<<endl;
    cout<<"Number of backedge are "<<x<<endl;
}   