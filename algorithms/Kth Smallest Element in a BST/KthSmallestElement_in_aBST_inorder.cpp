/*Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //inorder traversal
    void inorder(TreeNode* root,vector<int>&nums){
        if(!root)return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nums;
        inorder(root,nums);
        return nums[k-1];
    }
};