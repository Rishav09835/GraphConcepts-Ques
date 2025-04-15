# 210. Course Schedule II

## 🧠 Problem Summary
You are given `numCourses` and a list of `prerequisites` where each pair `[a, b]` means:
> To take course `a`, you must first complete course `b`.

Return a valid course **ordering** to finish all courses, or return `[]` if not possible (i.e., cycle exists).

## ✅ Goal
Return any valid topological order of all courses if possible, else return `[]`.

---

## 🚀 Approaches

### 🔄 BFS (Kahn’s Algorithm - Topological Sort)
- Build graph with edges `b → a`.
- Track `indegree[]` of each node.
- Add all courses with `indegree == 0` to a queue.
- While queue not empty:
  - Pop node `u`, add to result.
  - Decrease indegree of neighbors.
  - Push neighbors with `indegree == 0` to queue.
- If all courses are processed → return result.
- Else → return `[]` (cycle exists).

### 🧭 DFS (Topological Sort + Cycle Detection)
- Build graph with edges `b → a`.
- Use `visited[]` and `inRecursion[]` to detect cycles.
- For each unvisited node:
  - Perform DFS.
  - If a node is visited **while in recursion stack** → cycle detected → return `[]`.
  - Else, push nodes into a stack (post-order).
- Return reversed post-order (topological sort).

