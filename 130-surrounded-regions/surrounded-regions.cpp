class Solution {
public:
    void dfs(vector<vector<char>>& board, int rows, int cols, int row, int col,
             vector<vector<int>>& visited) {
        
        visited[row][col] = 1;
        board[row][col] = '1';

        if (row - 1 >= 0 && !visited[row - 1][col] && board[row - 1][col] == 'O')
            dfs(board, rows, cols, row - 1, col, visited);

        if (col - 1 >= 0 && !visited[row][col - 1] && board[row][col - 1] == 'O')
            dfs(board, rows, cols, row, col - 1, visited);

        if (row + 1 < rows && !visited[row + 1][col] && board[row + 1][col] == 'O')
            dfs(board, rows, cols, row + 1, col, visited);

        if (col + 1 < cols && !visited[row][col + 1] && board[row][col + 1] == 'O')
            dfs(board, rows, cols, row, col + 1, visited);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            if (!visited[i][0] && board[i][0] == 'O')
                dfs(board, rows, cols, i, 0, visited);

            if (!visited[i][cols - 1] && board[i][cols - 1] == 'O')
                dfs(board, rows, cols, i, cols - 1, visited);
        }

        for (int i = 0; i < cols; i++) {
            if (!visited[0][i] && board[0][i] == 'O')
                dfs(board, rows, cols, 0, i, visited);

            if (!visited[rows - 1][i] && board[rows - 1][i] == 'O')
                dfs(board, rows, cols, rows - 1, i, visited);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};