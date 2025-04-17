    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);
        if (xparent == yparent)
            return;
        if (rank[xparent] < rank[yparent]) {
            parent[xparent] = yparent;
        } else if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else {
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (auto& s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for (auto& s : equations) {
            if (s[1] == '!') {
                int aparent = find(s[0] - 'a');
                int bparent = find(s[3] - 'a');
                if (aparent == bparent)
                    return false;
            }
        }
        return true;
    }
