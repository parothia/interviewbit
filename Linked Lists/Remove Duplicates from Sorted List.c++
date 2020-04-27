/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(head->next==NULL)
        return head;
    ListNode *curr=head->next,*prev=head;
    while(curr!=NULL) {
        if(prev->val==curr->val) {
            prev->next=curr->next;
            curr->next=NULL;
            curr=prev->next;
        }
        else  {
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
