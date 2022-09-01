/*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.*/


class Solution {
public:
    int maximum=0;
    void helper(TreeNode *root,int ma)
    {
        if(root==NULL)
            return ;
        ma=max(ma,root->val);
        if(ma<=root->val)
            maximum++;
        helper(root->left,ma);
        helper(root->right,ma);
        return ;
    }
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);
        return maximum;
        
    }
};
