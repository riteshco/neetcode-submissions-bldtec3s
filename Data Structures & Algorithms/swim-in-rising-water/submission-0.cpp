class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; i++) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node)
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> positions;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                positions.push_back({grid[i][j], i, j});
            }
        }
        sort(positions.begin(), positions.end());
        DSU d(m*n);
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto& [t, r, c]: positions) {
            for(auto& [dr, dc] : directions) {
                int nr = r+dr, nc = c+dc;
                if(nr >=0 && nc >=0 && nr<m && nc<n && grid[nr][nc] <= t) {
                    d.unionSets(r*n+c, nr*n+nc);
                }
            }
            if(d.connected(0, n*m-1)) return t;
        }
        return n*m;
    }
};
