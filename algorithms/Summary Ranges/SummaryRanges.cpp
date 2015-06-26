/*Summary Ranges
 Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/
class Solution {
public:
    string itos(int num){
        stringstream ss;
        ss << num;
        return ss.str();
    }
    vector<string> summaryRanges(vector<int>& nums) {
            vector<string>result;
            int start = 0;
            for(int i = 0; i < nums.size();i++){
                if((i+1) == nums.size() ||(nums[i+1] - nums[i]) != 1){
                    string s(itos(nums[start]));
                    if((i-start) > 0)
                        s = s + "->" + itos(nums[i]);//0,1,2,4,5,7
                    result.push_back(s);
                    start = i+1;
                }
            }
            return result;
    }
};