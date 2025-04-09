# Graph Traversal

This folder contains key concepts and problems related to **Graph Traversal** using BFS and DFS — essential for mastering graph problems and cracking interviews.

## ✅ Traversal Techniques

- **DFS (Depth First Search)**:
  - Use **stack** (recursive or explicit).
  - Good for **connected components**, **cycle detection**, **topological sort**, etc.

- **BFS (Breadth First Search)**:
  - Use **queue**.
  - Best for **shortest path in unweighted graphs**, **level-order traversal**, etc.

## 💡 Key Concepts to Remember

- Track visited nodes using a `visited[]` array.
- For **undirected graphs**, mark edges both ways: `adj[u].push_back(v)` and `adj[v].push_back(u)`.
- For **disconnected graphs**, run BFS/DFS from all unvisited nodes.
- Be careful with **1-based vs 0-based indexing** in questions.
- **BFS is preferred** for shortest path-related problems.
- DFS is useful when **path depth**, **recursion**, or **backtracking** is involved.

## 📌 Common Interview Questions

- Number of connected components
- Cycle detection (BFS/DFS)
- Bipartite check
- Shortest path (unweighted)
- Flood fill / islands problem

