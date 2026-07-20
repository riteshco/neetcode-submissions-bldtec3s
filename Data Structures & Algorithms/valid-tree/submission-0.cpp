class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, false);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = true;
        int visited = 1;
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto& nei : adj[node]) {
                if(!vis[nei]) {
                    vis[nei] = true;
                    visited++;
                    q.push({nei, node});
                } else if(nei != parent) return false;
            }
        }

        return visited==n;
    }
};
