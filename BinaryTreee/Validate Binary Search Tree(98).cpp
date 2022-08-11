/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */

class Solution {
public:
    bool helper(TreeNode *root,TreeNode *&previous)
    {
        if(!root)
            return true;
        bool left= helper(root->left,previous);
        if(previous&&root->val<=previous->val)
            return false;
        previous=root;
        bool right=helper(root->right,previous);
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *previous=NULL;
        return helper(root,previous);
    }
};
