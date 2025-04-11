#include <bits/stdc++.h> 
void DFS_TopoSort(vector<vector<int>>&adj,int u,vector<bool>& visited,stack<int>&st)
{
  visited[u]=true;
  for(int&v : adj[u]){
    if(!visited[v]){
      DFS_TopoSort(adj,v,visited,st);
    }
  }
  st.push(u);
}
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e)  {
    //adjacency list
  vector<vector<int>> adj(v);
  for(auto &edge : edges){
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
  }
  vector<bool>visited(v,false);
  stack<int>st;
  for(int i=0;i<v;i++){
    if(!visited[i])
    DFS_TopoSort(adj,i,visited,st);
  }
  vector<int>ans;
  while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
  }
  return ans;
  
}
