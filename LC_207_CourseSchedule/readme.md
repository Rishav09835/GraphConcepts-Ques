# 207. Course Schedule

## 🧠 Problem Summary
You are given `numCourses` labeled from `0` to `numCourses - 1` and a list of prerequisites.

Each prerequisite pair `[a, b]` means: to take course `a`, you must first complete course `b`.

Determine if it's possible to finish all courses — i.e., the graph must have **no cycles**.

## ✅ Goal
Return `true` if all courses can be finished (no cycles), else return `false`.

---

## 🚀 Approach

### 🔄 BFS with Cycle Detection (Kahn's Algo)
- Build a directed graph (adjacency list).
- Track indegrees of nodes.
- Push all nodes with indegree `0` to queue.
- Process queue:
  - Pop node, reduce indegree of its neighbors.
  - If neighbor's indegree becomes `0`, push to queue.
- If `count == numCourses` → return `true`, else `false`.

### 🧭 DFS with Cycle Detection
- Build a directed graph.
- Use `visited[]` and `onPath[]`:
  - If node is revisited while on the current path → cycle.
- Run DFS for each node.
- If cycle found → return `false`, else `true`.

---
