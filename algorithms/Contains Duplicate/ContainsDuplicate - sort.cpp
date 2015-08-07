/*Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
*/
class Solution {
public:
    /*algorithm:brute force
      1)sort arary,
      2)check ajacent element
      time: O(nlogn) space O(1);
      it depends on sort algorithm
    */
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)return false;
         sort(nums.begin(),nums.end());
         for(int i = 1;i < nums.size();i++){
             if(nums[i-1] == nums[i])return true;
         }
         return false;
    }
};