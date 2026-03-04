class Solution {
public:
    bool checkConditions(vector<vector<int>>&mat, int &row, int &col){
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < m; i++){
            if(mat[row][i] == 1 && i != col)return false;
        }
        for(int i = 0; i < n; i++){
            if(mat[i][col] == 1 && i != row)return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int specialPosition = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    if(checkConditions(mat, i, j))specialPosition++;
                }
            }
        }

        return specialPosition;
    }
};