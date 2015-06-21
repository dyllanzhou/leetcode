/*Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.
Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    void comb3(vector<vector<int> >&set,vector<int>&visisted,vector<int>&result,int cnt,int cur,int k,int n){
        if(cnt == k){
            if(cur == n)set.push_back(result);
            return;
        }
        for(int i = 1;i < 10;i++){
            if((cur+i) > n)break;
            if(!result.empty() && i < result[result.size()-1])continue;
            if(visisted[i])continue;
            result.push_back(i); 
            visisted[i] = 1;
            comb3(set,visisted,result,cnt+1,cur+i,k,n);
            visisted[i] = 0;
            result.pop_back();
        }
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> >set;
        vector<int>result;
        vector<int>visisted(10,0);
        comb3(set,visisted,result,0,0,k,n);
        return set;
    }
};
