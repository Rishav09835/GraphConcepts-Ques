bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1.adjacency list & indegree array.
        unordered_map<int,vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto & x: prerequisites){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        //2.fill the queue
        queue<int> q;
        int count=0; //to check if all courses visited or not.
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        //simple bfs
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
        return count == numCourses;
    }
