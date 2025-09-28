/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head==NULL||head->next==NULL) return NULL;
    struct ListNode *fast=head;
    struct ListNode *slow=(struct ListNode*)malloc(sizeof(struct ListNode));
    slow->val=0;
    slow->next=head;
    while(n>0){
        fast=fast->next;
        n--;
    }
    if(fast==NULL){
        head=head->next;
        return head;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}
// @lc code=end

