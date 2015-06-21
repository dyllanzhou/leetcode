/*Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/
//use min heap to mainatin k elements, iterate all ememts to end, the heap min elment is just what we want
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>heap(nums.begin(),nums.begin()+k);
        make_heap(heap.begin(), heap.end(),greater<int>());
        for(int i = k;i < nums.size();i++){
            if(heap.front() < nums[i]){
                pop_heap(heap.begin(),heap.end());
                heap.pop_back();
                heap.push_back(nums[i]);
                push_heap(heap.begin(),heap.end());
                sort_heap(heap.begin(),heap.end());
            }
        }
        return heap.front();
    }
};
