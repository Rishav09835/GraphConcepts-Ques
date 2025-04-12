void DFS(int u,vector<bool>&visited,vector<vector<int>>&adj){
        visited[u]=true;
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(v,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //dfs traversal
        int provinces=0;
        vector<bool>visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(i,visited,adj);
                provinces++;
            }
        }
        return provinces;
    }
