// Given a linked list, remove the nth node from the end of list and return its head.
// 
// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// 
// Note: If n is greater than the size of the list, remove the first node of the list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode *curr=head,*prev=NULL;
    int i=0;
    if(head->next==NULL && n==1)
        return NULL;
    while(i<n and curr) {
        i++;
        curr=curr->next;
    }
    if(curr==NULL)
        return head->next;
    prev=head;
    while(curr->next) {
        prev=prev->next;
        curr=curr->next;
    }
    curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    return head;
    
}
