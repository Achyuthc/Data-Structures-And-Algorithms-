/*Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 */

class Solution {
public:
    vector<pair<double,double>> levelSum;
    void helper(TreeNode *root,int level)
    {
        if(!root)
            return ;
        
        if(level==levelSum.size())
            levelSum.push_back({root->val,1});
        else
            levelSum[level].first+=root->val,levelSum[level].second+=1;
        
        helper(root->left,level+1);
        
        helper(root->right,level+1);
        
        return ;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        helper(root,0);
        
        for(auto item:levelSum)
            ans.push_back(item.first/item.second);
        
        return ans;
    }
};
