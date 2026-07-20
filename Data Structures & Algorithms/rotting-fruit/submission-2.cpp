class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int dRow[] = {0, 0, -1, 1};
        int dCol[] = {-1, 1, 0, 0};
        int time = 0;
        while(!q.empty()) {
            int s = q.size();
            for(int j=0; j<s; j++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int nr = r + dRow[i];
                    int nc = c + dCol[i];
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if(grid[nr][nc] == 1) {
                        fresh--;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }
        if(fresh==0) {
            if(time > 0) return --time;
            else return time;
        }
        else return -1;
    }
};
