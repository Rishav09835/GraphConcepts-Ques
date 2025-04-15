bool dfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj, vector<bool>& inRecurs) {
        visited[u] = true;
        inRecurs[u] = true;
        for (int& v : adj[u]) {
            if (!visited[v]) {
                if (!dfs(v, visited, adj, inRecurs))
                    return false;
            } else if (visited[v] && inRecurs[v])
                return false;
        }
        inRecurs[u] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(numCourses);
        for (auto& x : prerequisites) {
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecurs(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, visited, adj, inRecurs))
                    return false;
            }
        }
        return true;
    }
