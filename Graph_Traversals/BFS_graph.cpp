void bfs(vector<bool>&visited, int u, vector<vector<int>> adj, vector<int>&result){
  queue<int> q;
  q.push(u);
  visited[u]=true;
  result.push_back(u);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int &v: adj[u]){
      if(!visited[v]){
        visited[v]=true;
        q.push(v);
        result.push_back(v);
      }
    }
  }
}
