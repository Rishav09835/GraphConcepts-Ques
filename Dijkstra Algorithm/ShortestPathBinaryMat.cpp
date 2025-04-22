class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> direct = {{1, 1},  {1, 0},  {0, 1},  {-1, -1},
                                  {0, -1}, {-1, 0}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        if (r == 0 || c == 0 || grid[0][0] != 0)
            return -1; // cannot traverse

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < r && y >= 0 && y < c;
        };
        vector<vector<int>> result(r, vector<int>(c, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;  // Current distance
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (auto& dir : direct) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1; // Cost to move to an adjacent cell

                if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + dist < result[x_][y_]) {
                    result[x_][y_] = d + dist;
                    pq.push({d + dist, {x_, y_}});
                }
            }
        }

        if (result[r - 1][c - 1] == INT_MAX) return -1;
        return result[r - 1][c - 1] + 1;  // Add 1 to the result as the last cell is also part of the path
    }
};

// we can also do this using just normal queue because weight of all the cells are same i.e. 1
