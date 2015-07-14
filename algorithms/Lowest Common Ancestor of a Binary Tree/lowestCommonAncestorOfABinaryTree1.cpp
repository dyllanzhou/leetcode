/*Lowest Common Ancestor of a Binary Tree
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
//O(n2)solution
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
    int matchCount(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root)return 0;
        if(root == p || root == q)
            return 1 + matchCount(root->left,p,q) + matchCount(root->right,p,q);
        else
            return matchCount(root->left,p,q) + matchCount(root->right,p,q);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)return NULL;
            if(root == p || root == q)return root;
            int left,right;
            left = matchCount(root->left,p,q);
            if(left == 1)//another is in right tree
                return root;
            if(left == 0) //both are in right tree
                return lowestCommonAncestor(root->right,p,q);
            //left == 2
            return lowestCommonAncestor(root->left,p,q);
    }
};