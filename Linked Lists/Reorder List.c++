// Given a singly linked list
// 
//     L: L0 → L1 → … → Ln-1 → Ln,
// 
// reorder it to:
// 
//     L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// 
// You must do this in-place without altering the nodes’ values.
// 
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *head) {
    ListNode *prev=NULL;
    ListNode *curr=head;
    ListNode *temp=NULL;
    ListNode *r=NULL;
    while(curr) {
        r=curr->next;
        curr->next=prev;
        prev=curr;
        curr=r;
    }
    return prev;
} 
 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *p=A;
    ListNode *q=A;
    ListNode *temp=NULL;
    ListNode *head2;
    while(q->next && q->next->next) {
        p=p->next;
        q=q->next->next;
    }
    head2=p->next;
    p->next=NULL;
    head2=reverse(head2);
    ListNode *head=A;
    while(head && head2) {
        temp=head2;
        head2=head2->next;
        temp->next=head->next;
        head->next=temp;
        head=head->next->next;
    }
    return A;
}
