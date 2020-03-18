#include<bits/stdc++.h>
using namespace std;

class union_set{
    private:
        vector<int> rank;
        vector<int> p;
        vector<int>cycle;
    public:
       int n;
       union_set(int n){
       rank.assign(n,0);
        p.assign(n,0); 
        cycle.assign(n,0);
       }
    
      int make_set(int n)
      {
             
         
          for(int i=0;i<n;i++)
          {
             p[i]=i;
           
          }

      }
      bool isSame_set(int l , int r)
      {
            if(find_set(l)==find_set(r))
                return true;
            else
            {
                  return false;
            }
                
      }
      int find_set(int k)
      {
        
          if(k==p[k])
              return k;
           else
           {
            return p[k]=find_set(p[k]);
           }
              
      }
    void Union_set(int l , int r)
    {
           if(!isSame_set(l,r))
           {
               int x=find_set(l),y=find_set(r);
               if(rank[x]>rank[y])
                      p[y]=x;
                else
                {
                    p[x]=y;
                }
                if(rank[x]==rank[y])
                     rank[y]++;
                      
           }
    }

    bool IsCyclic(int n)
    {
    bool flag=1;
        for(int i=0;i<n;i++) 
             {
                cycle[i]=find_set(i);
             }
        for(int i=0;i<n-1;i++)
        {
            if(cycle[i]==cycle[i+1])
                 flag=0;
            else
            {
                 return false;
            }
                 
        } 
        if(flag==0)
            return true;      
    }

};
