/*Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.*/



class Solution {
public:
    vector<vector<int>> v;
    int helper(TreeNode *root,int t,vector<int> p,int u)
    {
        if(root==NULL)
        {
            return 0;
        }
        u+=root->val;
        p.push_back(root->val);
         if(root->right==NULL&&root->left==NULL&&u==t)
        {
        
            v.push_back(p);
            return 0;
        }
        else
        {
            helper(root->left,t,p,u);
            helper(root->right,t,p,u);
            return 0;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> inv;
        helper(root,targetSum,inv,0);
        return v;
        
    }
};
