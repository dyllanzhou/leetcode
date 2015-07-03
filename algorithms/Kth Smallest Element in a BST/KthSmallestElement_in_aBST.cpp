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
class Solution {
public:
    int getCount(TreeNode* root){
        if(!root)return 0;
        return 1 + getCount(root->left) + getCount(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = getCount(root->left);
        if(cnt == (k-1))return root->val;
        if(cnt < (k-1))return kthSmallest(root->right,k - cnt - 1);
        else return kthSmallest(root->left,k);
    }
};