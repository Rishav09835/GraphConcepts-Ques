    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, vector<int>> adj(numCourses);
        for (auto& x : prerequisites) {
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u); // need to complete v first to do u course : v->u
            indegree[u]++;
        }
        queue<int> q;
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    count++;
                    ans.push_back(v);
                }
            }
        }
        if (count == numCourses) {
            return ans;
        }
        return {};
    }
