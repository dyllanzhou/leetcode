/*Maximal Square 
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/
class Solution {
public:
    //dp:dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size())return 0;
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int> >dp(m+1,vector<int>(n+1,0));
        int maxSize = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '0')dp[i+1][j+1] = 0;
                else{
                   dp[i+1][j+1] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1])) + 1;
                   maxSize = max(maxSize,dp[i+1][j+1]);
                }
            }
        }
        
        return maxSize*maxSize;
    }
};