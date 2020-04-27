// Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.
// 
// Notes:
// 
//     Expected solution is linear in time and constant in space.
// 
// For example,
// 
// List 1-->2-->1 is a palindrome.
// List 1-->2-->3 is not a palindrome.

 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* head) {
    ListNode *prev=NULL;
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;
    if(head->next->next==NULL) {
        if(head->val == head->next->val)
            return 1;
        else return 0;
    }
    
    ListNode *p=head;
    ListNode *q=head;
    while(q->next && q->next->next) {
        prev=p;
        p=p->next;
        q=q->next->next;
    }
    if(q->next) {
        prev=p;
        p=p->next;
        q=q->next;
    }
    prev->next=NULL;
    ListNode *last=q;
    q=NULL;
    ListNode *r=NULL;
    while(p!=NULL) {
        r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    p=head;
    while(q && p) {
        if(q->val == p->val) {
            p=p->next;
            q=q->next;
            continue;
        }
        else return 0;
    }
    return 1;
    
}
