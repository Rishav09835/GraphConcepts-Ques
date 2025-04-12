
# 547. Number of Provinces

## 🧠 Problem Summary

You are given a graph in the form of an **adjacency matrix** `isConnected` of size `n x n`:

- `isConnected[i][j] == 1` means **city `i` is directly connected to city `j`**
- `isConnected[i][j] == 0` means **no direct connection**

A **province** is defined as a group of cities that are:
- **Directly or indirectly connected**
- And **not connected to any other cities outside the group**

### 🧩 Graph Interpretation
- Treat each city as a **node** in a graph.
- A `1` in the matrix means there's an **edge** between two nodes.
- The goal is to **count the number of connected components** in this undirected graph.
