class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();

        for(int i = 0; i < row; i++){
            int empty = col-1;
            for(int j = col-1; j >= 0; j--){

                if(boxGrid[i][j] == '*'){
                    empty = j-1;
                } else if(boxGrid[i][j] == '#'){
                    if(j != empty){
                        boxGrid[i][empty] = '#';
                        boxGrid[i][j] = '.';
                    }
                    empty--;
                }
            }
        }

        vector<vector<char>>ans(col, vector<char>(row));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans[j][row-i-1] = boxGrid[i][j];
            }
        }

        return ans;
    }
};