# 📌 Dijkstra’s Algorithm

## 🧠 What is it?
Dijkstra’s Algorithm is a **greedy algorithm** used to find the **shortest path** from a **single source node** to all other nodes in a **weighted graph** with **non-negative edge weights**.

---

## 🔧 How it Works
1. Initialize distances to all nodes as ∞ (infinity), except the source node (set to 0).
2. Use a **min-priority queue** (min-heap) to pick the node with the smallest known distance.
3. For each neighbor of the current node:
   - If a shorter path is found via the current node, update its distance.
4. Repeat until all shortest distances are finalized.

---

## 🧩 Use Cases
- GPS Navigation Systems
- Network Routing Protocols
- AI pathfinding (e.g., in games)
- Google Maps, flight scheduling

---

## 📈 Time Complexity
| Implementation         | Time Complexity  |
|------------------------|------------------|
| Using Min-Heap (Binary Heap) | `O((V + E) log V)` |
| Using Simple Array            | `O(V²)`             |

Where `V` = number of vertices, `E` = number of edges.

---

## ⚠️ Limitations
- **Does NOT work** with **negative edge weights**.
- Use **Bellman-Ford Algorithm** for graphs with negative weights.

---
