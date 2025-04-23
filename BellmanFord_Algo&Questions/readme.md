# Bellman-Ford Algorithm

The **Bellman-Ford Algorithm** is a graph algorithm used to find the **shortest paths from a single source** vertex to all other vertices in a weighted graph. It is especially useful when the graph contains **negative weight edges**.

---

## ✅ Key Features

- **Works on Directed Graphs:** Bellman-Ford is primarily designed for **directed graphs**.
- **Handles Negative Edge Weights:** Unlike Dijkstra's algorithm, Bellman-Ford works correctly even when edge weights are **negative**.
- **Detects Negative Weight Cycles:** Can detect if there's a **negative weight cycle** reachable from the source.
- **Time Complexity:** `O(V * E)` where:
  - `V` = number of vertices
  - `E` = number of edges
- **Space Complexity:** `O(V)` for the distance array.

---

## 📌 Algorithm Steps

1. Initialize the distance to all vertices as `INF`, and the source vertex distance as `0`.
2. **Relax all edges V-1 times:**
   - For each edge `(u, v)` with weight `w`, if `dist[u] + w < dist[v]`, update `dist[v] = dist[u] + w`.
3. **Check for negative weight cycles:**
   - Do one more pass over all edges to check if any distance can still be updated. If yes, a **negative cycle exists**.

---

## ⚠️ Important Notes

- **Graph Type:** Best suited for **directed graphs**. For undirected graphs with negative weights, it may falsely detect a negative cycle unless edges are handled carefully.
- **Negative Cycle Implication:** If a negative cycle exists, **shortest path is undefined** (you can keep reducing the cost by looping through the cycle).

---

## 💡 Use Cases

- **Network Routing Algorithms** (e.g., RIP protocol)
- **Currency Arbitrage Detection**
- **Shortest Paths in Graphs with Negative Weights**
- **Evaluating Reachability in Dynamic Programming Problems**

---

## 🚫 Limitations

- Slower than Dijkstra’s for graphs **without negative weights**
- Not suitable for dense graphs due to higher time complexity compared to other algorithms

---
