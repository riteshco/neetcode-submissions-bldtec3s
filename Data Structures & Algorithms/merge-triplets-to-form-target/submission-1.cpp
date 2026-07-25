class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one = false;
        bool two = false;
        bool three = false;
        for(auto& v: triplets) {
            if(v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) continue;
            if(v[0] == target[0]) one = true;
            if(v[1] == target[1]) two = true;
            if(v[2] == target[2]) three = true;
        }
        return one && two && three;
    }
};
