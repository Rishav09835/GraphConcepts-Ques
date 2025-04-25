    bool dfs(int node, vector<vector<int>>&adj, int destination, vector<bool>&visited){   
        if(node == destination ) return true;
        for(auto &x : adj[node]){
            if(!visited[x]){
                visited[x]=true;
                if(dfs(x, adj, destination, visited)) return true;
            }
        }
        return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        visited[source]=true;
        return dfs(source,adj,destination,visited);
        return false;
    }
