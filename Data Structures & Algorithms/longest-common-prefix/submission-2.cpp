class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int min_j = ans.size();
        for(int i=1;i<strs.size();i++){
            int j =0;
            while(j < strs[i].size() && j < ans.size() && strs[i][j] == ans[j]){
                j++;
            }
            min_j = min(min_j, j);
        }
        return ans.substr(0, min_j);
    }
};