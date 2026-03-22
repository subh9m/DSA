class Solution {
public:
    bool equalCheck(vector<vector<int>>&mat, vector<vector<int>>&target){
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != target[i][j])return false;
            }
        }
        return true;
    }

    void rotate90(vector<vector<int>>&mat){
        int n = mat.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(equalCheck(mat, target)){
            return true;
        }
        rotate90(mat);
        if(equalCheck(mat, target)){
            return true;
        }
        
        rotate90(mat);
        if(equalCheck(mat, target)){
            return true;
        }

        rotate90(mat);
        if(equalCheck(mat, target)){
            return true;
        }

        return false;
    }
};