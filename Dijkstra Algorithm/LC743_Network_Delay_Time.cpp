    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto & t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v,w});
        }
        vector<int>result(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        result[k]=0;
        pq.push({0,k}); //weight, node
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &x : adj[node]){
                int cnode = x.first;
                int d = x.second;
                if(d+dist<result[cnode]){
                    result[cnode]=d+dist;
                    pq.push({d+dist, cnode});
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX) return -1;
        }

        int mintime = 0;
        for(int i=1;i<=n;i++){
            if(result[i]>mintime) mintime = result[i];
        }
        return mintime;
    }
