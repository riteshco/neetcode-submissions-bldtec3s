class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        distance[k] = 0;
        while(!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& nei : adj[node]) {
                if(t + nei.second < distance[nei.first]){
                    distance[nei.first] = t + nei.second;
                    pq.push({t+nei.second, nei.first});
                }
            }
        }
        int time = 0;
        for(int i=1; i<=n; i++) {
            time = max(time, distance[i]);
        }
        return time==INT_MAX? -1 : time;
    }
};
