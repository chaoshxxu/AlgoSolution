public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int r = 0;
        int c = matrix[0].length - 1;
        
        while (r < matrix.length) {
            while (c > 0 && matrix[r][c] > target) {
                --c;
            }
            if (matrix[r][c] == target) {
                return true;
            }
            ++r;
        }
        return false;        
    }
}