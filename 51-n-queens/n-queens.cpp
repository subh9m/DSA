class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board) {
        int r = row;
        int c = col;

        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        while(r >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
        }

        r = row;
        c = col;

        while(r >= 0 && c < board[0].size()) {
            if(board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;

    }
    void func(int row, vector<string>&board, vector<vector<string>>&result) {
        if(row == board.size()){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size(); col++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';

                func(row + 1, board, result);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n, string(n, '.'));

        func(0, board, result);

        return result;
    }
};