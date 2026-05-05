class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        int row_num = matrix.size();
        int col_num = matrix[0].size();

        for(int i=0;i<row_num;i++){
            for(int j=0;j<col_num;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int i=0;i<row_num;i++){
            if(rows.find(i)!=rows.end())
                for(int j=0;j<col_num;j++){
                    matrix[i][j]=0;
                }
        }
        for(int j=0;j<col_num;j++){
            if(cols.find(j)!=cols.end()){
                for(int i=0;i<row_num;i++){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};