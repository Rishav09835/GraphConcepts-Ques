    void BFS(int u, vector<bool>&visited, vector<vector<int>>&adj){
        visited[u]=true;
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto&v :adj[x]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
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
        //bfs traversal
        int provinces=0;
        vector<bool>visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(i,visited,adj);
                provinces++;
            }
        }
        return provinces;
    }
