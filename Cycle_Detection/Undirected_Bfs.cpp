
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
           if(!visited[i] && BfsCycle(adj,i,visited))
            return true;
        }
        return false;
    }

    bool BfsCycle(vector<vector<int>>&adj, int u, vector<bool>&visited){
      queue<pair<int,int>> que; //node,parent
      visited[u]=true;
      que.push({u,-1});
      while(!que.empty()){
        int x = que.front();
        int node = x.first;
        int parent = x.second;
        que.pop();
        for(int&v : adj[node]){
          if(!visited[v]){
            visited[v]=true;
            que.push({v, node});
          }
          else if(v!=parent) return true;
        }
      }
      return false;
    }
};
