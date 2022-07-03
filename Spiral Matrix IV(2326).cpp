/*You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int> (n,-1));
        
        int l=0,r=n-1,u=0,d=m-1;
        while(r>=l&&d>=u&&head)
        {
            for(int i=l;i<=r&&head;i++)
            {
               ans[u][i]=head->val;
               head=head->next;
            }  
            u++;
            for(int i=u;i<=d&&head;i++)
            {
                ans[i][r]=head->val;
                head=head->next;
            }
            r--;
            for(int i=r;i>=l&&head;i--)
            {
                ans[d][i]=head->val;
                head=head->next;
            }
            d--;
            for(int i=d;i>=u&&head;i--)
            {
                ans[i][l]=head->val;
                head=head->next;
            }
            l++;
            
            
        }
        return ans;
        
        
    }
};
