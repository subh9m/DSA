class Solution {
public:
    vector<int>delrow = {-1, 0, 1, 0};
    vector<int>delcol = {0, 1, 0, -1};

    bool isValid(int nrow, int ncol, int n, int m){
        if(nrow < 0 || nrow >= n) return false;
        if(ncol < 0 || ncol >= m) return false;
        return true;
    }

    bool isExit(int row, int col, int n, int m){
        if(row == 0 || row ==n-1) return true;
        if(col == 0 || col == m-1) return true;
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        int steps = 0;

        vector<vector<int>>visited(m, vector<int>(n, 0));

        queue<pair<int, int>>q;

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;

                if(isExit(row, col, m, n) && (row != entrance[0] || col != entrance[1])){
                    return steps;
                }

                for(int i = 0; i < 4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(isValid(nrow, ncol, m, n) && !visited[nrow][ncol] && maze[nrow][ncol] == '.'){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};