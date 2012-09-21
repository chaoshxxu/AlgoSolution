public class Solution {
    public int numDecodings(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (s.length() == 0)return 0;
        
        s = "#" + s;
        
        int[] dp = new int[s.length()];
        dp[0] = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (isValid(s.substring(i, i + 1))) {
                dp[i] += dp[i - 1];                
            }
            if (i > 1 && isValid(s.substring(i - 1, i + 1))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length() - 1];
    }
    
    private boolean isValid(String s) {
        try {
            return !s.startsWith("0") && Integer.parseInt(s) >= 1 && Integer.parseInt(s) <= 26; 
        } catch (Exception e) {
            return false;
        }
    }
}
