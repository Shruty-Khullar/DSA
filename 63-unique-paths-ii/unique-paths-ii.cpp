class Solution {
public:
    int Helper(vector<vector<int>>& obstacleGrid, int rows, int cols, int row, int col, vector<vector<int>>& dp){
        if(row<0 || col<0)
            return 0;
        if(row==0 && col==0 && obstacleGrid[row][col]!=1)
            return 1;
        if(obstacleGrid[row][col]==1)
            return dp[row][col]=0;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up = Helper(obstacleGrid, rows, cols, row-1, col, dp);
        int left = Helper(obstacleGrid, rows, cols, row, col-1, dp);
        return dp[row][col] = up + left;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = Helper(obstacleGrid, m, n,  m-1, n-1, dp);
        return ans;
    }
};