/*Contains Duplicate II
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/
class Solution {
public:
    /*
        algorithm2: hash table soluton
        1)for ith element, search same element jth in hash table, compare j-i with k
        2)iterate with all elments
        time: O(n) space O(n)
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int>htbl;
        for(int i = 0;i < size;i++){
            if(htbl.count(nums[i]))
            {
                int j = htbl[nums[i]];
                if(abs(i-j) <= k)return true;
            }
            htbl[nums[i]] = i;
        }
        return false;
    }
};