C/*opy List/ Deep copy of Link List
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.
Return a deep copy of the list.

Example
Given list 1 -> 2 -> 3
with random pointers going from
  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    if(!head) return NULL;
    // return head;
    int zero=head->label;
    RandomListNode *curr=head;
    unordered_map<int,RandomListNode*> umap;
    RandomListNode *newhead=new RandomListNode(0);
    RandomListNode *traverse=newhead;
    curr=head;
    while(curr) {
        RandomListNode *temp=new RandomListNode(curr->label);
        traverse->next=temp;
        traverse=traverse->next;
        umap[traverse->label]=traverse;
        curr=curr->next;
    }
    curr=head;
    traverse=newhead->next;
    while(curr) {
        if(curr->random) traverse->random=umap[curr->random->label];
        else traverse->random=0;
        traverse=traverse->next;
        curr=curr->next;
    }
    return newhead->next;
    // RandomListNode *curr=head;
    // while(curr) {
    //     cout<<curr->label<<" ";
    //     if(curr->random) cout<<curr->random->label<<" ";
    //     else cout<<0<<" ";
    //     curr=curr->next;
    // }
    // return NULL;
}
