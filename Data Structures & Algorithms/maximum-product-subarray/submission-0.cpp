class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> seg;
        vector<int> curr;
        int res = INT_MIN;
        for(int& num: nums) {
            res = max(res, num);
            if(num == 0) {
                if(!curr.empty()) seg.push_back(curr);
                curr.clear();
            } else {
                curr.push_back(num);
            }
        }
        if(!curr.empty()) seg.push_back(curr);\

        for(auto& sub : seg) {
            int neg = 0;
            for(int i: sub) {
                if(i < 0) neg++;
            }
            int need = (neg%2) ? neg-1 : neg;
            int cur = 1;
            int cur_neg = 0;
            for(int i=0, j = 0; i<sub.size(); i++) {
                cur *= sub[i];
                if(sub[i] < 0) cur_neg++;
                while(cur_neg > need) {
                    cur /= sub[j];
                    if(sub[j] < 0) cur_neg--;
                    j++;
                }
                if(j <= i) res = max(res, cur);
            }
        }

        return res;
    }
};
