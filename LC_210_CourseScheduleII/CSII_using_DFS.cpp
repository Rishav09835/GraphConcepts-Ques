bool dfs(int u, vector<bool>& visited, vector<bool>& inRecurs, unordered_map<int, vector<int>>& adj, stack<int>& st) {
        visited[u] = true;
        inRecurs[u] = true;
        for (int& v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, visited, inRecurs, adj, st) == false)
                    return false;
            } else if (inRecurs[v] == true)
                return false;
        }
        st.push(u);
        inRecurs[u] = false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        unordered_map<int, vector<int>> adj(numCourses);
        for (auto& x : prerequisites) {
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }
        vector<bool> inRecurs(numCourses, false);
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, inRecurs, adj, st) == false)
                    return {};
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
