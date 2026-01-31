class Solution {
public:
    bool row(int ele, int i, vector<vector<char>>&board){
        if(ele == '.') return true;
        int count = 0;

        for(int j = 0; j < 9; j++){
            if(board[i][j] == ele) count++;
        }

        return count <= 1;
    }

    bool col(int ele, int j, vector<vector<char>>&board){
        if(ele == '.') return true;
        int count = 0;

        for(int i = 0; i < 9; i++){
            if(board[i][j] == ele) count++;
        }

        return count <= 1;
    }

    bool mat(int ele, int row, int col, vector<vector<char>>&board){
        if(ele == '.') return true;

        int count = 0;
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == ele) count++;
            }
        }
        return count <= 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         int r = board.size();
         int c = board[0].size();
        
         for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!row(board[i][j], i, board)){
                    return false;
                }
                if(!col(board[i][j], j, board)){
                    return false;
                }

                if(!mat(board[i][j], i, j, board)){
                    return false;
                }
            }
         }

         return true;
    }
};