class Solution {
public:
    bool isValid(vector<vector<char>>&board, int row, int col, int digit){
        char di = digit + '0';

        for(int i = 0; i < 9; i++){
            if(board[row][i] == di || board[i][col] == di) return false;
        }

        int newrow = (row / 3)*3;
        int newcol = (col / 3)*3;

        for(int i = newrow; i < newrow + 3; i++){
            for(int j = newcol; j < newcol + 3; j++){
                if(board[i][j] == di) return false;
            }
        }
        return true;
    }
    bool func(vector<vector<char>>&board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){

                    for(int k = 1; k <= 9; k++){
                        if(isValid(board, i, j, k)){
                            board[i][j] = k + '0';
                            if(func(board)){
                                return true;
                            } else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};