class DSU {
public:
    vector<int> parent;
    vector<int> size;
    
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return false;
        if(size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(auto& e : edges) {
            n = max(n, max(e[0], e[1]));
        }
        DSU d(n+1);
        pair<int, int> p = {-1, -1};
        for(auto& e : edges) {
            if(d.isConnected(e[0], e[1])) {
                p.first = e[0];
                p.second = e[1];
            }
            d.unionBySize(e[0], e[1]);
        }
        return {p.first, p.second};
    }
};
