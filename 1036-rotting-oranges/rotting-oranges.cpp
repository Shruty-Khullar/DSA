class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                } else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(row-1>=0 && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    q.push({row-1, col});
                    fresh--;
                } 
                if(col-1>=0 && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    q.push({row, col-1});
                    fresh--;
                } 
                if(row+1<rows && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    q.push({row+1, col});
                    fresh--;
                } 
                if(col+1<cols && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    q.push({row, col+1});
                    fresh--;
                } 
            }
            time++;
        }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        if(fresh!=0) return -1;
        return time-1;

    }
};