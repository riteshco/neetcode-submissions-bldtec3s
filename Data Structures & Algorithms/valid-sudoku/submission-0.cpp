class Solution {
public:
    bool checkRow(vector<char>& row) {
        vector<int> freq(10,0);
        for(char number: row) {
            if(number != '.') {
                freq[(int)(number - '0')]++;
                if(freq[(int)(number - '0')] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col) {
        vector<int> freq(10,0);
        for(int i=0;i<board.size();i++){
            if(board[i][col] != '.') {
                freq[(int)(board[i][col] - '0')]++;
                if(freq[(int)(board[i][col] - '0')] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkSubBox(vector<vector<char>>& board, int row, int col) {
        vector<int> freq(10, 0);
        for(int i=row; i < row+3; i++) {
            for(int j=col; j < col+3; j++) {
                if(board[i][j] != '.') {
                    freq[(int)(board[i][j]-'0')]++;
                    if(freq[(int)(board[i][j]-'0')] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto row: board) {
            if(!checkRow(row)){
                return false;
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(!checkCol(board, i)) {
                return false;
            }
        }
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                if(!checkSubBox(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};
