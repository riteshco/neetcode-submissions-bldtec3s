class Solution {
    bool find(int r, int c, int ind, vector<vector<char>>& board, string word) {
        if(ind == word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if(board[r][c] != word[ind]) return false;
        board[r][c] = '#';
        bool found = find(r+1, c, ind+1, board, word) || find(r-1, c, ind+1, board, word) || find(r, c+1, ind+1, board, word) || find(r, c-1, ind+1, board, word);
        board[r][c] = word[ind];
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(find(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
