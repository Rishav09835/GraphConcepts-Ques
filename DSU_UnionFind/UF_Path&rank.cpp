vector<int>parent;
vector<int>rank;

int find(int x){
  if(parent[x]==x) return x;
  return parent[x]=find(parent[x]);
}

void Union(int x, int y)
{
  int parentx = find(x);
  int parenty = find(y);
  if(parentx == parenty) return;
  if(rank[parentx] > rank[parenty]) parent[parenty] = parentx;
  else if(rank[parentx] < rank[parenty]) parent[parentx] = parenty;
  else {
    rank[parentx] = parenty;
    parent[parenty]++;
      }
}

int main(){
  parent.resize(n);
  rank.resize(n);
  return 0;
}
