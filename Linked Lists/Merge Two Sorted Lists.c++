// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.
// 
// For example, given following linked lists :
// 
//   5 -> 8 -> 20 
//   4 -> 11 -> 15
// 
// The merged list should be :
// 
// 4 -> 5 -> 8 -> 11 -> 15 -> 20
// 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* h1, ListNode* h2) {
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    
    if(h1->val < h2->val) {
        h1->next=mergeTwoLists(h1->next,h2);
        return h1;
    }
    else {
        h2->next=mergeTwoLists(h1,h2->next);
        return h2;
    }
}
