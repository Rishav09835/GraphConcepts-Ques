bool isCyclic(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  vector<int>indegree(V,0);
  for(auto & edge : edges){
    int u = edge[0];
    int v = edge[1];
    indegree[v]++;
  }

  queue<int>q;
  int count = 0;
  for(int i=0;i<V;i++){
    if(indegree[i]==0){
      q.push(i);
      count++;
    }
  }

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int &v : adj[u]){
      indegree[v]--;
      if(indegree[v]==0){
        q.push(v);
        count++;
      }
    }
  }
  if(count == V) return false; //no cycle all nodes visited
  return true; //cycle exists
  
}
