class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> valid;
        for(auto& t: triplets) {
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) valid.push_back(t);
        }
        bool one = false;
        bool two = false;
        bool three = false;
        for(auto& v: valid) {
            if(v[0] == target[0]) one = true;
            if(v[1] == target[1]) two = true;
            if(v[2] == target[2]) three = true;
        }
        return one && two && three;
    }
};
