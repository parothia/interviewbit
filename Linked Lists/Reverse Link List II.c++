/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note: Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.
Note 2: Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode *p=NULL;
    ListNode *prev=NULL;
    ListNode *curr=A;
    ListNode *r;
    ListNode *temp;
    int count=1;
    int flag=0;
    while(count<=n) {
        if(count==m-1) {
            p=curr;
        }
        if(count==m) {
            temp=curr;
            while(count<=n) {
                r=curr->next;
                curr->next=prev;
                prev=curr;
                curr=r;
                flag=1;
                count++;
            }
        }
        if(flag)
            break;
        count++;
        curr=curr->next;
    }
    temp->next=r;
    if(p) {
        p->next=prev;
        return A;
    }
    return prev;
        
}
