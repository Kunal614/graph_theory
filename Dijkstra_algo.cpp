 /*
 typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pp push_back
#define p pop

vii vect[100];
map<int,int> dist;
priority_queue<ii,vector<ii>,greater<ii>> pq;
*/
 
 while(!pq.empty())
   {
       ii k = pq.top();
       int d=k.first, u=k.second;
       pq.pop();
       if(dist[u]<d) continue;
       for(auto it=vect[u].begin();it!=vect[u].end();it++)
       {
           if(dist[it->second]>dist[u]+it->first)
           {
               dist[it->second]=dist[u]+it->first;
               pq.push({dist[it->second],it->second});
           }
       }
       
    }