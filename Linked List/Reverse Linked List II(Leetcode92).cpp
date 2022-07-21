/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and 
return the reversed list.*/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *node=head ,*prev=NULL,*prevLeft=NULL,*next,*lef=NULL,*newHead=head;
        int cnt=0;
        while(cnt!=right)
        {
            cnt++;
            
            if(cnt<left)
            {
                prev=node;
                node=node->next;
            }
            else if (cnt==left)
            {
                prevLeft=prev;
                lef=node;
                prev=node;
                node=node->next;
            }
            else if(cnt==right)
            {
                next=node->next;
               
                if(prevLeft)
                    prevLeft->next=node;
               
                node->next=prev;
                if(lef)
                 lef->next=next;
               
                if(left==1)
                    newHead=node;
                break;
            }
            else {
                next=node->next;
                node->next=prev;
                prev=node;
                node=next;
            }
        }
        
        return newHead;
        
    }
};
