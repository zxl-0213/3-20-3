/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    struct ListNode* cur=head;
    int count=0;
    while(cur)
    {
       cur=cur->next;
       count++;
    }
    if(k>count)
    {
        return NULL;
    }
    if(k==count)
    {
        return head;
    }
    k%=count;
    while(k)
    {
        fast=fast->next;
        k--;
    }
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}