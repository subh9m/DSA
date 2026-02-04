class Solution {
public:
    bool canPlace(int row, int col, vector<string>&board){
        int r = row;
        int c = col;

        while(r >= 0){
            if(board[r][c] == 'Q')return false;
            r--;
        }
        r = row;
        c = col;

        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')return false;
            r--;
            c--;
        }
        r = row;
        c = col;

        while(r >= 0 && c < board.size()){
            if(board[r][c] == 'Q')return false;
            r--;
            c++;
        }
        return true;
    }
    void func(int row, vector<vector<string>>&ans, vector<string>&board){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        //traversing each row.
        for(int col = 0; col < board.size(); col++){
            if(canPlace(row, col, board)){
                board[row][col] = 'Q';
                func(row + 1, ans, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));

        func(0, ans, board);
        return ans;
    }
};