/*Count Complete Tree Nodes 
Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        int hl,hr;
        TreeNode* l,*r;
        hl = hr = 0;
        l = r = root;
        while(l){
            hl++;
            l = l->left;
        }
        while(r){
            hr++;
            r = r->right;
        }
        if(hl==hr)return (1 << hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};