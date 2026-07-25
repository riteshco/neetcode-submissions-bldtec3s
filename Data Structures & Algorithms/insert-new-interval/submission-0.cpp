class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0];
        int r = newInterval[1];
        bool done = false;
        for(auto& i: intervals) {
            if(l > i[1]) ans.push_back(i);
            else if(r < i[0]) {
                if(done) ans.push_back(i);
                else {
                    done = true;
                    ans.push_back({l, r});
                    ans.push_back(i);
                }
            }
            else {
                l = min(l, i[0]);
                r = max(r, i[1]);
            }
        }
        if(!done) ans.push_back({l, r});
        return ans;
    }
};
