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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //inorder traversal, optimize memory space
class Solution {
public:
    //inorder traversal
    void inorder(TreeNode* root,int& cur,int &val,int k){
        if(!root)return;
        inorder(root->left,cur,val,k);
        cur++;
        if(cur == k){
            val = root->val;
            return;
        }
        inorder(root->right,cur,val,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val,cur=0;
        inorder(root,cur,val,k);
        return val;
    }
};