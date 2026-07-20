class DSU {
public:
    vector<int> parent;
    vector<int> size;
    int comp;

    DSU(int n) {
        comp = n;
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUPar(int u) {
        if(parent[u] == u) return u;
        else return parent[u] = findUPar(parent[u]);
    }

    bool unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return false;
        comp--;
        if(size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }

    int getComponents() {
        return comp;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for(auto& edge : edges) {
            d.unionBySize(edge[0], edge[1]);
        }

        return d.getComponents();
    }
};
