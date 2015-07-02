/*Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
//More voting soluton O(1)space O(n)time
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { 
            vector<int>result;
            int n1,n2,c1,c2;
            c1 = c2 = 0;
            for(int i = 0;i < nums.size();i++){
                if(n1 == nums[i])c1++;
                else if(n2 == nums[i])c2++;
                else if(c1 == 0)n1 = nums[i],c1++;
                else if(c2 == 0)n2 = nums[i],c2++;
                else c1--,c2--;
            }
            c1 = c2 = 0;
            for(int i = 0;i < nums.size();i++){
                if(n1 == nums[i])c1++;
                if(n2 == nums[i])c2++;
            }
            if(c1 > nums.size()/3)result.push_back(n1);
            if(c2 > nums.size()/3)result.push_back(n2);
            return result;
    }
};