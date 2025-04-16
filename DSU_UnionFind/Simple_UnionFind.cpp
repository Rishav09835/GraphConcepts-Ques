vector<int>parent(n);
int find(int x,vector<int>&parent){
  if(parent[x]==x) return x;

  return (parent[x],parent);
}

void Union(int x, int y, vector<int>&parent){
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);
  if(x_parent!=y_parent){
    parent[x_parent]=y_parent;
  }
}
