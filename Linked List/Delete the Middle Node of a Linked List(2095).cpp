

https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/solutions/2703363/c-solution-with-slow-and-fast-pointers/

/*You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head,*fast=head,*head1=new ListNode(0),*prev=head;
        if(head->next==NULL)
            return head->next;
        head1->next=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
    
        return head1->next;
        
    }
};
