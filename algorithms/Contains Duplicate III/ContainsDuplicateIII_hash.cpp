/*Contains Duplicate III 
Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] and nums[j] is at most t and 
the difference between i and j is at most k. 
*/
class Solution {
public:
     //hash table + key
    //|nums[i] - nums[j]| <= t     <=>    |nums[i]/t - nums[j]/t| <= 1
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 1)return false;
        map<int,long long>tbl;
        int key;
        for(int i = 0;i < nums.size();i++){
           key = nums[i]/max(1,t);
           int keys[]={key-1,key,key+1};
           for(int j = 0;j < 3;j++){
           if(tbl.count(keys[j]) && abs(nums[i] - tbl[keys[j]]) <= t)
              return true;
           }
           tbl[key] = nums[i];
           if(i >= k)
             tbl.erase(nums[i-k]/max(1,t)); 
         }
         return false;
    }
};
