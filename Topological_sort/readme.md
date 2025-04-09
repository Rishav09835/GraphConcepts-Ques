# 🧭 Topological Sort

## 📌 What is Topological Sort?

Topological Sort is a way of **ordering the vertices** of a **Directed Acyclic Graph (DAG)** such that for every directed edge `u → v`, node `u` comes **before** `v` in the ordering.

---

## ✅ When is it Used?

Topological sort is useful in problems involving **dependencies**, where one task must be done before another. Common applications include:

- Course prerequisite planning
- Task scheduling
- Build systems (like Makefiles)
- Package dependency resolution

---

## 🚫 Why Not Used in Cyclic or Undirected Graphs?

### ❌ Cyclic Graphs:
Topological sorting assumes a **linear dependency order**. If there is a cycle (e.g., `A → B → C → A`), then there’s **no valid way to order** the nodes because every node depends on another in a loop. Hence, **topological sort is not defined for cyclic graphs**.

### ❌ Undirected Graphs:
Undirected graphs can have **implied cycles** (like `A — B — C — A`) and **no direction** of dependency. Topological sorting requires clear direction (`u → v`) to determine the order. Since undirected graphs **lack direction**, they **don't support dependency-based ordering**, making topological sort inapplicable.

---

## 🧠 Summary

- ✔️ Works only on **Directed Acyclic Graphs (DAGs)**
- ❌ Not applicable to **cyclic** or **undirected** graphs
- 🔄 Multiple valid topological orders may exist
- 🧩 Useful for resolving **dependencies**

---

