/* You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.
The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.
Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. */
 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        vector<int> result(n+1,INT_MAX);
        result[1]=0;
        minheap.push({0,1}); //dist, node
        while(!minheap.empty()){
            int dist = minheap.top().first;
            int node = minheap.top().second;
            minheap.pop();
            for(auto &x : adj[node]){
                int curnode = x.first;
                int d = x.second;
                if(d+dist<result[curnode]){
                    parent[curnode]=node;
                    result[curnode]=d+dist;
                    minheap.push({d+dist,curnode});
                }
            }
        }
        int endNode=n;
        if(result[endNode] == INT_MAX) return {-1};
        vector<int> path;
        while(parent[endNode]!=endNode){
            path.push_back(endNode);
            endNode = parent[endNode];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
         path.insert(path.begin(), result[n]);
        return path;
        
    }
