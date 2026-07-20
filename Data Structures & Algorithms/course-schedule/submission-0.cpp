class Solution {
    bool detectCycle(int course, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis) {
        vis[course] = true;
        pathVis[course] = true;
        for(auto& nei : adj[course]) {
            if(!pathVis[nei]) {
                if(detectCycle(nei, adj, vis, pathVis)) return true;
            } else return true;
        }
        pathVis[course] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> pathVis(numCourses);
        vector<bool> vis(numCourses);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(detectCycle(i, adj, vis, pathVis)) return false;
            }
        }
        return true;
    }
};
