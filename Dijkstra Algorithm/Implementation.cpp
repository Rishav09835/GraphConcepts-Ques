    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int cnode = pq.top().second;
            pq.pop();
            for(auto & x :adj[cnode]){
                int ngbr = x.first;
                int wt = x.second;
                if(dist+wt < result[ngbr]){
                    result[ngbr]=dist+wt;
                    pq.push({dist+wt,ngbr});
                }
            }
        }
        return result;
    }
