
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
           if(!visited[i] && dfsCycle(adj,i,visited,-1))
            return true;
        }
        return false;
    }

    bool dfsCycle(vector<vector<int>>&adj, int u, vector<bool>&visited, int parent){
        visited[u]=true;
        for(int & v: adj[u]){
            if(v==parent) continue; //ignore edge to parent
            if(visited[v]) return true; //found cycle
            if(dfsCycle(adj,v,visited,u)) return true;
        }
        return false;
        
    }
};

