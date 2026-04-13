class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,0);
        for(int i=0;i<numbers.size();i++){
            for(int j=i+1;j<numbers.size();j++){
                if(numbers[i] + numbers[j] == target) {
                    ans[0] = i+1;
                    ans[1] = j+1;
                    return ans;
                }
            }
        }
    }
};
