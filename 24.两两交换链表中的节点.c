/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL||head->next==NULL) return head;
    struct ListNode *headptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    headptr->next=head;
    struct ListNode *temp=headptr,*first,*second;
    while(temp->next!=NULL&&temp->next->next!=NULL){
        first=temp->next;
        second=temp->next->next;
        first->next=second->next;
        second->next=first;
        temp->next=second;
        temp=first;
    }
    return headptr->next;
}
// @lc code=end

