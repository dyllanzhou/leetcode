/*House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police
*/
//dp(n) =  dp(n-1)
//         dp(n-2)+nums[n-1]) //dp(n-2) + nums[n-1] > dp(n-1)
class Solution {
public:
    int rob(vector<int>& nums) {  //[2,3,2,10]
        int size = nums.size();
        if(size < 1)return 0;
        if(size < 2)return nums[0];
        int s0,s1,s2;
        s0 = nums[0],s1 = nums[1] > nums[0]?nums[1]:nums[0];
        for(int i = 2;i < nums.size();++i){
            if((s0 + nums[i]) > s1){
                s2 = s0 + nums[i];
            }else{
                s2 = s1;
            }
            s0 = s1;
            s1 = s2;
        }
        return size > 2?s2:s1;
    }
};