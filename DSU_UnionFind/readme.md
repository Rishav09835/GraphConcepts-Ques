# 🔗 Disjoint Set Union (DSU) / Union-Find

## 🧠 Concept
DSU is a data structure that helps manage a collection of non-overlapping sets.  
It supports two main operations:
- **Find**: Identify the set to which an element belongs.
- **Union**: Merge two different sets into one.

---

## ✅ Applications
- Detecting cycles in graphs
- Kruskal’s algorithm for Minimum Spanning Tree
- Grouping connected components
- Dynamic connectivity problems

---

## 🚀 Optimizations
- **Path Compression**: Speeds up the `find` operation by flattening the tree.
- **Union by Rank / Size**: Keeps the trees shallow by attaching the smaller tree under the larger one.

---

## ⚡ Time Complexity
With both optimizations, each operation runs in **amortized O(α(N))** time,  
where **α(N)** is the inverse Ackermann function — which grows extremely slowly and is almost constant in practice.

### ℹ️ What does "amortized" mean?
Amortized time refers to the **average time per operation over a sequence of operations**.  
Some individual operations might be a bit costly, but most are extremely fast,  
so the **average time remains very efficient** when considered over many operations.

---
