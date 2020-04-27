
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::deleteDuplicates(ListNode* curr) {
   if(!curr || !curr->next)
        return curr;
        
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = curr;
    ListrNode *prev=fakeHead;
    while(curr) {
        while(curr->next && curr->val == curr->next->val)
            curr=curr->next;
        
        if(prev->next==curr) {
            prev=curr;
        }
        else prev->next=curr->next;
        curr=curr->next;
    }
    return fakeHead->next;
}
