    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int xparent = find(x);
        int yparent = find(y);
        if(xparent == yparent) return;
        if(rank[xparent]<rank[yparent]) parent[xparent]=yparent;
        else if(rank[xparent]>rank[yparent]) parent[yparent]=xparent;
        else{
            parent[xparent]=yparent;
            rank[yparent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1) return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
        parent[i]=i;
        }
        int components = n;
        for(auto&x : connections){ //x->{0,1} so x[0]=0, x[1]=1 and so on.
            int parent1 = find(x[0]);
            int parent2 = find(x[1]);
            if(parent1!=parent2){
                Union(x[0],x[1]);
                components--;
            }
        }
        return components - 1;

    }
