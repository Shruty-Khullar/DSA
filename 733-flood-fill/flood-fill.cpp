class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int rows = image.size();
        int cols = image[0].size();
        int src_color = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row-1>=0 && image[row-1][col]==src_color){
                    image[row-1][col]=color;
                    q.push({row-1, col});
            } 
             if(col-1>=0 && image[row][col-1]==src_color){
                    image[row][col-1]=color;
                    q.push({row, col-1});
            } 
             if(row+1<rows && image[row+1][col]==src_color){
                    image[row+1][col]=color;
                    q.push({row+1, col});
            } 
             if(col+1<cols && image[row][col+1]==src_color){
                    image[row][col+1]=color;
                    q.push({row, col+1});
            } 
        }
        return image;
    }
};