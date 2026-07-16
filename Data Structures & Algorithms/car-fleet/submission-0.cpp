class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for(int i=0; i<position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        vector<double> stk;
        for(auto& p : pairs) {
            stk.push_back((double)(target - p.first) / p.second);
            if(stk.size() > 1) {
                if(stk.back() <= stk[stk.size()-2]) stk.pop_back();   
            }
        }
        return stk.size();
    }
};
