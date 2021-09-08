class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.length() + 1][text2.length() + 1];
        
        // init
        for (int i = 0; i < text1.length() + 1; i++) {
            for (int j = 0; j < text2.length() + 1; j++) {
                dp[i][j] = 0;
            }
        }
        
        //
        for (int i = 1; i < text1.length() + 1; i++) {
            for (int j = 1; j < text2.length() + 1; j++) {
                if (text1.at(i - 1) != text2.at(j - 1))
                    // find max
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // up and left
                else 
                    dp[i][j] = dp[i - 1][j - 1] + 1; // slash
            }
        }
        
        return dp[text1.length()][text2.length()];
    }
};
