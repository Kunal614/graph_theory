 //Algorithm
 /*

     vector<int> v[1000];
    map<int,int> color;
    queue<int> pq;

    */
    pq.push(source);
    bool isBipartitie = true;
    color[source]=0;
    while(!pq.empty() && isBipartitie)
    {
        int k=pq.front();
        
        pq.pop();
        for(auto it=v[k].begin();it!=v[k].end();it++)
        {
            if(color[*it]==color[k])
               { isBipartitie=false;break;}
            else if(color[*it]==-1)
            {
                color[*it]=1-color[k];
                pq.push(*it);
            }
                
        }
    }
    isBipartitie==false?cout<<"Not bipartite":cout<<"Bipartite";
    