class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] != node) parent[node] = findUPar(parent[node]);
        return parent[node]; 
    }

    bool unionBySize(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return false;
        if (size[pu] >= size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }

    bool isConnected(int u, int v) {
        return findUPar(u) == findUPar(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        DSU d(m*n+1);
        vector<vector<int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] != 'O') continue;
                if(r == 0 || c == 0 || r == m-1 || c == n-1) {
                    d.unionBySize(m*n, r*n+c);
                }
                for(auto& dir: directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O') {
                        d.unionBySize(r*n+c, nr*n+nc);
                    }
                }
            }
        }
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(!d.isConnected(m*n, r*n+c)) board[r][c] = 'X';
            }
        }
    }
};
