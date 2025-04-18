    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int xparent = find(x);
        int yparent = find(y);
        if(xparent == yparent) return;
        if(rank[xparent] < rank[yparent]) parent[xparent]=yparent;
        else if(rank[xparent] > rank[yparent]) parent[yparent]=xparent;
        else {
            parent[yparent]=xparent;
            rank[xparent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //making components
        for(auto & x: edges){
            int aparent = find(x[0]);
            int bparent = find(x[1]);
            if(aparent != bparent){
                Union(aparent,bparent);
            }
        }
        //storing size of each component.
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int p = find(i);
            mp[p]++;
        }
        //finding out unreachable pair of nodes.
        long long ans = 0;
        long long remaining = n;
        for(auto& it: mp){
            int size = it.second; //component size;
            ans += size * (remaining - size);
            remaining -= size;
        }
        return ans;
  
    }
