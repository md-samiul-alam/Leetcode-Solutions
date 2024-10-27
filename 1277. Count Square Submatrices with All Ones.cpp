class Solution {
public:
    bool checkMatrixOne(vector<vector<int>>& matrix, int ii, int jj, int matSize) {
        for(int i=ii; i<ii+matSize; ++i) {
            for(int j=jj; j<jj+matSize; ++j) {
                if(matrix[i][j] == 0) return false;
            }
        }
        return true;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int c=0;
        for(int matSize=1; matSize<=min(row, col); ++matSize) {
            for(int i=0; i<=row-matSize; ++i) {
                for(int j=0; j<=col-matSize; ++j) {
                    if(checkMatrixOne(matrix, i, j, matSize)) {
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
