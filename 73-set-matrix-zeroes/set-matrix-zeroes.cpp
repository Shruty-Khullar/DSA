class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    //     set<int> rows;
    //     set<int> cols;
    //     int row_num = matrix.size();
    //     int col_num = matrix[0].size();

    //     for(int i=0;i<row_num;i++){
    //         for(int j=0;j<col_num;j++){
    //             if(matrix[i][j]==0){
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }

    //     for(auto itr: rows){
    //         for(int j=0;j<col_num;j++){
    //             matrix[itr][j]=0;
    //         }
    //     }

    //     for(auto itr: cols){
    //         for(int i=0;i<row_num;i++){
    //             matrix[i][itr]=0;
    //         }
    //     }
    // }

    int row_num = matrix.size();
    int col_num = matrix[0].size();
    bool firstRowZero=false;
    bool firstColZero=false;
    for(int i=0;i<row_num;i++){
        if(matrix[i][0]==0){
            firstColZero=true;
            break;
        }
    }

    for(int j=0;j<col_num;j++){
        if(matrix[0][j]==0){
            firstRowZero=true;
            break;
        }
    }

    for(int i=1;i<row_num;i++){
        for(int j=1;j<col_num;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<row_num;i++){
        for(int j=1;j<col_num;j++){
            if(matrix[i][0] == 0 ||  matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }

    if(firstColZero){
        for(int i=0;i<row_num;i++){
            matrix[i][0]=0;
        }
    }
    if(firstRowZero){
        for(int i=0;i<col_num;i++){
            matrix[0][i]=0;
        }
    }
    }

};