/*Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/
//use divide and conquer to resolve this issue, like quicksort, partion the array to reach the goal
class Solution {
public:
    //partion() divide the arry to two parts, [0,p-1] >= [p] >=[p+1,n-1]
    int partion(vector<int>&nums,int start,int len,int k){
        int key = nums[start];
        int i = 0,j = len - 1;
        while(i < j){
            while(i < j && nums[start + j] <= key)--j;
            nums[start + i]= nums[start + j];
            while(i < j && nums[start + i] > key)++i;
            nums[start + j] = nums[start + i];
        }
        nums[start + i] = key;
        if((i+1) == k)return nums[start + i];
        if((i+1) > k)return partion(nums,start,i,k);
        return partion(nums,start + i+1,len - (i+1),k-(i+1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        return partion(nums,0,nums.size(),k);
    }
};
