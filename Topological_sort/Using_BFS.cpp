vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
  vector<vector<int>> adj(v);
  for(auto &e : edges){
    int u = e[0];
    int v = e[1];
    adj[v].push_back(u);
  }

 stack<int> st;
    while(!st.empty()){
        
    }
}
