// Type alias for easier readability
typedef pair<int, pair<int, int>> P;

// Directions array: represents the 8 possible movements (diagonal, vertical, horizontal)
vector<vector<int>> direct = {{1, 1}, {1, 0}, {0, 1}, {-1, -1}, 
                               {0, -1}, {-1, 0}, {1, -1}, {-1, 1}};

// Function to find the shortest path in a binary matrix
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    // Get number of rows and columns in the grid
    int r = grid.size();
    int c = grid[0].size();

    // Base case: If grid is empty or the start point (0,0) is blocked, return -1 (no path)
    if (r == 0 || c == 0 || grid[0][0] != 0)
        return -1;

    // Lambda function to check if a point (x, y) is within bounds of the grid
    auto isSafe = [&](int x, int y) {
        return x >= 0 && x < r && y >= 0 && y < c;
    };

    // Queue to perform BFS; stores the current distance and coordinates
    queue<P> q;
    
    // Initialize BFS by starting at the top-left corner (0, 0) with distance 1
    q.push({1, {0, 0}});
    
    // Mark the starting point as visited
    grid[0][0] = 1;

    // BFS loop to explore the grid
    while (!q.empty()) {
        // Get the current level size (i.e., number of nodes at the current distance level)
        int N = q.size();

        // Process each node in the current level
        while (N--) {
            // Get the current distance (d) and coordinates (x, y)
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop(); // Remove the current node from the queue
            
            // If we reached the bottom-right corner, return the current distance (path length)
            if (x == r - 1 && y == c - 1)
                return d;

            // Explore all 8 possible directions from the current cell (x, y)
            for (auto& dir : direct) {
                int x_ = x + dir[0]; // Calculate the new x-coordinate
                int y_ = y + dir[1]; // Calculate the new y-coordinate
                
                // If the new position is safe and not yet visited (value = 0), add it to the queue
                if (isSafe(x_, y_) && grid[x_][y_] == 0) {
                    q.push({d +
