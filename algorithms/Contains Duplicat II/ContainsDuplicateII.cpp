/*Contains Duplicate II
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>tbl;
        int j;
        for(int i = 0;i < nums.size();i++){
            if(tbl.count(nums[i])){
                j = tbl[nums[i]];
                if(nums[j] == nums[i] && (i - j) <= k)
                    return true;
            }
            tbl[nums[i]] = i;
        }
        return false;
    }
};