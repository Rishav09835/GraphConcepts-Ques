void dfsGraph(vector<int>&visited, int u, vector<vector<int>adj, vector<int>&result)
{
  if(visited[u]) return;
  visited[u]= true;
  result.push_back(u);
  for(auto & v: adj[u])
  {
    if(!visited[v])
    {
      dfsGraph(visited,v,adj,result);
      }
  }
}

