//for no cylce
#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ps push
#define po pop
using namespace std;
int main()
{
    queue <int> gq;
   int v;
    cout<<"Enter the vertex : ";
    cin>>v;
    vector <int> vi[10];
    for(int i=1;i<=v;i++)
    {
        int k;
        cout<<"Enter -1  if no adjacent element is there\n";
        cout<<"enter the element adjacent to "<<i<<" :: ";
        do
        {
        cin>>k;
        if(k!=-1)
        {
        vi[i].pb(k);
        }
        
        }while(k!=-1);
    }
    for(int i=1;i<=v;i++)
    {
             cout<< i<<" -> ";
        for(auto j=vi[i].begin();j!=vi[i].end();j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    //cout<<1<<" ";

     vector <int> vect;
     vect.pb(1);
     int p=1;
     int y=1;
    for(int i=1;i<=v;i++)
    while(y<=v)
    {
        y++;
        
        for(auto j=vi[p].begin();j!=vi[p].end();j++)
        {
            gq.ps(*j);
        }
       // cout<<gq.front()<<" ";
        //auto find(vect.begin(),vect.end(),*j)!=vect.end();
        if(find(vect.begin(),vect.end(),gq.front())==vect.end())
            { vect.pb(gq.front());
            }
        p=gq.front();
        gq.po();
        
        
    }
    cout<<endl;
    cout<<"Bfs traversal started from vertex 1 of the graph\n";
    cout<<"Bfs of the given graph is :: ";
    for(auto j=vect.begin();j!=vect.end();j++)
    {
        cout<<*j<<" ";
    }
    cout<<endl;

}

