// Given a list, rotate the list to the right by k places, where k is non-negative.
// 
// For example:
// 
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.




    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    ListNode* Solution::rotateRight(ListNode* A, int k) {
        int n=0;
        ListNode *a=A;
        while(a) {
            n++;
            a=a->next;
        }
        k=k%n;
        // cout<<" gg ";
        if(k==0)
            return A;
        // cout<<k<<" kk  ";
        ListNode *p=A,*q=A;
        while(k) {
            k--;
            q=q->next;
            // cout<<"  q  ";
            
        }
        // cout<<"  F F  ";
        while(q->next) {
            p=p->next;
            q=q->next;
        }
        ListNode *temp=p->next;
        p->next=NULL;
        q->next=A;
        return temp;
    }

