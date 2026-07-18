class Solution {
    bool isPossible(int r, int c, vector<string>& board, int n) {
        for(int i=0; i<r; i++) {
            if(board[i][c] == 'Q') return false;
        }
        int i = r-1;
        int j = c-1;
        while(i>=0 && j>=0) {
            if(board[i--][j--] == 'Q') return false;
        }
        i = r-1;
        j = c+1;
        while(i >= 0 && j < n) {
            if(board[i--][j++] == 'Q') return false;
        }
        return true;
    }
    void f(int row, vector<string>& board, int n, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int i=0; i<n; i++) {
            if(isPossible(row, i, board, n)) {
                board[row][i] = 'Q';
                f(row+1, board, n, res);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        for(int i=0; i<n; i++) {
            string tmp = "";
            for(int j=0; j<n; j++) tmp += '.';
            board.push_back(tmp);
        }
        f(0, board, n, res);
        return res;
    }
};
