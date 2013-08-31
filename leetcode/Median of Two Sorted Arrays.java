public class Solution {
    
    public double findMedianSortedArrays(int A[], int B[]) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int val1 = findWithPos(A, B, (A.length + B.length - 1) / 2);
        int val2 = findWithPos(A, B, (A.length + B.length) / 2);
        return (val1 + val2) / 2.0;
    }
    
    private int findWithPos(int A[], int B[], int pos) {
        try {
            return findInFirst(A, B, pos);
        } catch (Exception e) {
            return findInFirst(B, A, pos);
        }
    }
    
    private int findInFirst(int A[], int B[], int pos) {
        int low = 0;
        int high = A.length - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int indexOfB = pos - 1 - mid;
            if (indexOfB >= B.length || indexOfB >= 0 && B[indexOfB] > A[mid]) {
                low = mid + 1;
            } else if (indexOfB + 1 < 0 || indexOfB + 1 < B.length && B[indexOfB + 1] < A[mid]) {
                high = mid - 1;
            } else {
                return A[mid];
            }
        }
        throw new RuntimeException();
    }
}
