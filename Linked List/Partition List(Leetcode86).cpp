/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *node1=new ListNode(0),*node2=new ListNode(0);
        ListNode *head1=node1,*head2=node2;
        ListNode *node=head;
        if(!node)
            return node;
        while(node)
        {
            if(node->val<x)
            {
                node1->next=node;
                node1=node;
            }
            else
            {
                node2->next=node;
                node2=node;
            }
            node=node->next;
        }
        
        if(!head1->next)
            return head2->next;
        else
        {
            node1->next=head2->next;
            node2->next=NULL;
        }
            
        return head1->next;
           
            
        
    }
};
