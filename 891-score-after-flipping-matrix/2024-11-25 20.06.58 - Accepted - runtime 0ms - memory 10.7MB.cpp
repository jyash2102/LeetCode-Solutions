class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
                                  
        // Making the first column all 1's
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    grid[i][j] = 1 - grid[i][j]; // Flip the row
                }
            }
        }

        // Flip the columns where the number of 0s is greater than the number of 1s
        for (int j = 1; j < cols; j++) {  // Start from column 1 (no need to flip the first column)
            int noz = 0, noo = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] == 0) {
                    noz++;
                } else {
                    noo++;
                }
            }
            if (noz > noo) {
                for (int i = 0; i < rows; i++) {
                    grid[i][j] = 1 - grid[i][j]; // Flip the column
                }
            }
        }
        // Calculate the sum by interpreting the rows as binary numbers
         int sum=0;
        for(int i=0;i<rows;i++){
            int x=1;
            for(int j=cols-1;j>=0;j--){
                sum += grid[i][j]*x;
                x *= 2;
            } 
        }
        return sum;
    }
};
