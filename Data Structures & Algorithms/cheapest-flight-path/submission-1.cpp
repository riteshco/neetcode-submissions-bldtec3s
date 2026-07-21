class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> cost(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        cost[src] = 0;
        while(!q.empty()) {
            int stop = q.front().first;
            int d = q.front().second.first;
            int station = q.front().second.second;
            q.pop();
            if(stop == k+1) continue; 
            for(auto& nei : adj[station]) {
                if(d + nei.second < cost[nei.first]) {
                    cost[nei.first] = d + nei.second;
                    q.push({stop+1, {d+nei.second, nei.first}});
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(cost[i] == INT_MAX) cost[i] = -1;
        }
        return cost[dst];
    }
};
