#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      
   vis[src] = 1;
   queue<pair<int, int>> q;  // queue storing (node, parent)
   q.push({src, -1});

   while (!q.empty()) {
     int node = q.front().first;
     int parent = q.front().second;
     q.pop();

     for (auto it : adj[node]) {
         if (!vis[it]) {
             vis[it] = 1;
             q.push({it, node});
         } else if (parent != it) {
             return true;  // Cycle detected
         }
     }
   }
   return false;
  }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};  // initialise all vertices as unvisited

        // check for cycle in each component of the graph
        for (int i = 0; i < V; i++) {
           if (!vis[i] && detect(i, adj, vis)) {
               return true;
           }
        }
        return false;
    }
};

int main() {
    // V = 4, E = 2 (Undirected graph)
    vector<int> adj[4] = {{1}, {0, 2}, {1, 3}, {2}}; // Correct adjacency list for undirected graph

    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";  // Cycle exists
    else
        cout << "0\n";  // No cycle
    return 0;
}
