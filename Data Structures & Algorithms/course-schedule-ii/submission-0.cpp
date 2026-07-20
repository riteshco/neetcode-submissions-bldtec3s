class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites) {
            indeg[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        int finish = 0;
        vector<int> ans;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);
            finish++;
            for(auto& nei : adj[course]) {
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }
        if(finish==numCourses) return ans;
        else return {};
    }
};
