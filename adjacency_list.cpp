#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack <int> gq;
   int v;
    cout<<"Enter the vertex you have : ";
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
        vi[i].push_back(k);
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
}