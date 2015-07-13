/*Unique Binary Search Trees II 
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<TreeNode*> createTree(int start,int end){
        vector<TreeNode*>results;
        if(start > end){
            results.push_back(NULL);
            return results;
        }
        vector<TreeNode*>left,right;
        for(int i = start;i <= end;i++){
            left = createTree(start,i-1);
            right = createTree(i+1,end);
            for(int k = 0;k < left.size();k++){
                for(int m = 0;m < right.size();m++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[k];
                    root->right = right[m];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
    vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*>result;
            result = createTree(1,n);
            return result;
    }
};