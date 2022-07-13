/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

Solution 1:

//using recursion
class Solution {
public:
    vector<vector<int>> ans;
    int depth(TreeNode *root)
    {
        if(!root)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    void traverse(TreeNode *root,int l)
    {
        if(!root)
            return ;
        ans[l].push_back(root->val);
        traverse(root->left,l+1);
        traverse(root->right,l+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
      int d=depth(root);
      ans.resize(d);
      traverse(root,0);
        return ans;
    }
};



Solution 2:

//using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node;
        vector<vector<int>> answer;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> currentLevel;
            for(int i=0;i<size;i++)
            {
                node=q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            answer.push_back(currentLevel);
        }
        return answer;
        
    }
};
