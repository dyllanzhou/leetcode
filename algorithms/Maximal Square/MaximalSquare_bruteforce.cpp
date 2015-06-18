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
    int square(vector<vector<char>>& matrix,int i,int j,int r){
        int level;
        int flag = 1;
        for(int l = 1;l <= r;l++){
            for(int m = 0;m < l;m++){
             for(int n = 0;n < l;n++)
              if(matrix[i+m][j+n] == '0'){
                  flag = 0;
                  break;
              }
            }
            if(!flag)break;
            level = l;
        }
        return level;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m < 1)return 0;
        int n = matrix[0].size();
        int max,r,w;
        max = 0;
        for(int i = 0;(m - i) > max;i++){
            for(int j = 0;(n - j) > max;j++){
                if(matrix[i][j] == '0')continue;
                r = min(m - i, n - j);
                if(max < r){
                    w = square(matrix,i,j,r);
                    if(w > max)max = w;
                }
            }
        }
        return max*max;
    }
};