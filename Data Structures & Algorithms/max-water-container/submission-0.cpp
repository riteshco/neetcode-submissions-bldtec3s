class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int ans = 0;
        while(i < j) {
            if(heights[i] <= heights[j]) {
                ans = max(ans, heights[i] * (j - i));
                i++;
            } else {
                ans = max(ans, heights[j] * (j-i));
                j--;
            }
        }
        return ans;
    }
};
