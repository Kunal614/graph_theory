#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool arr[1000];
int dfs(int n)
{
    arr[n]=true;
    cout<<n<<endl;
    for(auto it=v[n].begin();it!=v[n].end();it++)
    {
        if(arr[*it]==false)
               dfs(*it);
           
    }
}
void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}
int main()
{
    memset(arr,false,sizeof(arr));
    
    addEdge(0, 1); 
    addEdge(0, 4); 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    addEdge(5,6);
    addEdge(7,9);
    addEdge(8,9);
  int x=0;
    for(int i=0;i<=9;i++)
    {
        if(arr[i]==false)
        {
           dfs(i);
           x++;
        }
        cout<<endl;
    }
    cout<<x<<endl;
}