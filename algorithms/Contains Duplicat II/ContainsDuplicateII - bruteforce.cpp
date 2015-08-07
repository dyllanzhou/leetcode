/*Contains Duplicate II
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/
class Solution {
public:
    /*
        algorithm: brue force soluton using sort 
        1)for ith element, search same element jth, compare j-i with k
        2)iterate with all elments
        time: O(nlogn) space O(n)
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int> >pairs(nums.size());
        for(int i = 0;i < nums.size();i++)
            pairs[i] = make_pair(nums[i],i);
        sort(pairs.begin(),pairs.end());
        for(int i = 0;i < nums.size();i++){
            if(i != 0 && 
              pairs[i].first == pairs[i-1].first &&
              abs(pairs[i].second - pairs[i-1].second) <= k)
              return true;
        }
        return false;
    }
};