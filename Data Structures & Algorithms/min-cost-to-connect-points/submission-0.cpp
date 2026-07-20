class DSU {
public:
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (size[pu] < size[pv]) swap(pu, pv);
        size[pu] += size[pv];
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        DSU d(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto& e : edges) {
            if(d.unionSets(e[1], e[2])) res += e[0];
        }
        return res;
    }
};
