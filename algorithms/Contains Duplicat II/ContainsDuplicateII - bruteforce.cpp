/*Contains Duplicate II
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/
class Solution {
public:
    /*
        algorithm: brue force soluton
        1)for ith element, search same element jth, compare j-i with k
        2)iterate with all elments
        time: O(n2) space O(1)
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < 2)return false;
        for(int i = 0;i < size - 1;i++){
            for(int j = i+1;j < size;j++){
                if(nums[j] == nums[i] && abs(j-i)<= k)
                    return true;
            }
        }
        return false;
    }
};