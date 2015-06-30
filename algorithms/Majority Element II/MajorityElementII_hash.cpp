/*Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
//hash soluton O(n)space O(n)time
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { //2,2,3,4,5,2
            vector<int>result;
            unordered_map<int,int>tbl;
            int thresh = nums.size()/3;
             for(int i = 0;i < nums.size();i++){
                if(!tbl.count(nums[i]))
                    tbl[nums[i]] = 1;
                else {
                    tbl[nums[i]]++;
                }
            }
            for(unordered_map<int,int>::iterator it = tbl.begin();it != tbl.end();it++){
                if(it->second > thresh)
                    result.push_back(it->first);
            }
            return result;
    }
};