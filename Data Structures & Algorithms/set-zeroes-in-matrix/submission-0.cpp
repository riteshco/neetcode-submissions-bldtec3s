class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool setColZero = false;
        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 0) setColZero = true;
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>0; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(setColZero) matrix[i][0] = 0;
        }
    }
};
