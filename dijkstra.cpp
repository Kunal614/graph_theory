#include <iostream>
#include <climits>
#include <set>
using namespace std;
#define N 5
int minDist(int dist[], bool Set[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < N; v++)
   if (Set[v] == false && dist[v] <= min)
   min = dist[v], min_index = v;
   return min_index;
}
int printSol(int dist[], int n)
{
   char Ver[5] = {'S', 'T', 'X', 'Y', 'Z'};
   cout<<"Vertex Distance from Source\n";
   for (int i = 0; i < N; i++)
   cout<<" \t\t \n"<< Ver[i]<<" \t\t "<<dist[i];
   cout<<endl;
}
void dijkstra(int g[N][N], int src)
{
   int dist[N];
   bool Set[N];
   for (int i = 0; i < N; i++)
   dist[i] = INT_MAX, Set[i] = false;
   dist[src] = 0;
   for (int c = 0; c < N- 1; c++)
   {
      int u = minDist(dist, Set);
      Set[u] = true;
      for (int v = 0; v < N; v++)
      if (!Set[v] && g[u][v] && dist[u] != INT_MAX && dist[u]
         + g[u][v] < dist[v])
         dist[v] = dist[u] + g[u][v];
   }
   printSol(dist, N);
}
int main()
{
   int g[N][N] = { { 0, 10, 0, 5, 0 },
      { 0, 0, 1, 2, 0 },
      { 0, 0, 0, 0, 4 },
      { 0, 3, 9, 0, 2 },
      {7, 0, 6, 0, 0 }};
   dijkstra(g, 0);
   return 0;
}
//9875590711
