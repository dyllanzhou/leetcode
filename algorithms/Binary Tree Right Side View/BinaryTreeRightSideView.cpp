/*Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode* node;
        vector<int>path;
        if(!root)return path;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                node = q.front(),q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            path.push_back(node->val);
        }
        return path;
    }
};