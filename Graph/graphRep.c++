#include <bits/stdc++.h>
using namespace std;
int solve()
{

 int n,m;
 cin>>n>>m;

 int adj[n+1][m+1];

 for(int i = 0; i < m; i++){
     int u, v;
     cin>>u>>v;

     adj[u][v] = 1;
     adj[v][u] = 1;
 }


return 0;
}


int main()
{
int t=1;
while(t--)
{
solve();
}
return 0;
}